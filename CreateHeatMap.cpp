#include <msclr\marshal_cppstd.h>

#include <thread>

#include <string>
#include <tchar.h>
#include <stdint.h>
#include <windows.h>
#include <algorithm>
#include <memory>
#include <fstream>
#include <vector>
#include <tchar.h>

#ifndef UNICODE
#define UNICODE
#define UNICODE_WAS_UNDEFINED
#endif

#ifdef UNICODE_WAS_UNDEFINED
#undef UNICODE
#endif

#include <windowsx.h>

#define LOG_MESSAGE(...) {(void)0;}

//#define LOG_MESSAGE(...) {printf(__VA_ARGS__);printf("\n");}

// RGB -> YUV
#define CLIP(X) ( (X) > 255 ? 255 : (X) < 0 ? 0 : X)
#define RGB2Y(R, G, B) CLIP(( (  66 * (R) + 129 * (G) +  25 * (B) + 128) >> 8) +  16)
#define RGB2U(R, G, B) CLIP(( ( -38 * (R) -  74 * (G) + 112 * (B) + 128) >> 8) + 128)
#define RGB2V(R, G, B) CLIP(( ( 112 * (R) -  94 * (G) -  18 * (B) + 128) >> 8) + 128)

using std::vector;
using std::string;
using std::wstring;
using std::endl;
using std::ifstream;
using std::to_string;

class CU {
	const int c_nDepth[4]	 = { 64, 16,  4, 1 };	// MAximo de cus 8x8	
	const int c_CuSize[4]	 = { 64, 32, 16, 8 };	// MAximo de cus 8x8	
	const int c_mX[4]		 = { 0,  32,  0, 32 };
	const int c_mY[4]	     = { 0,   0, 32, 32 };	

	int nCountDepth[4];

	double NormalizeToRange(double dToNormal) {
		dToNormal = (dToNormal - ValueMin) / (ValueMax - ValueMin);
		return dToNormal * 100;
	}

	COLORREF GetHeat(string param) {
		double x = atof(param.c_str());

		// Normaliza para ficar de 0 - 100
		double nNormal = NormalizeToRange(x);

		double c_FatorMult = 255 / 25;

		//Retorna fator rgb (heat)
		double dFatorRgb = c_FatorMult * (int(nNormal) % 25);
		if (dFatorRgb > 255) {
			dFatorRgb = 255;
		}
		else if (dFatorRgb < 0) {
			dFatorRgb = 0;
		} 
		
		COLORREF c;
		int spaceRgb = int(nNormal / 25);
		if (spaceRgb < 0) {
			//Caso de erro
			c = RGB(128, 128, 128);
		}else if (spaceRgb < 1) {
			c = RGB(0, int(dFatorRgb), 255);
		}else if (spaceRgb < 2) {
			c = RGB(0, 255, int(255 - dFatorRgb));
		}else if (spaceRgb < 3) {
			c = RGB(int(dFatorRgb), 255, 0);
		}else if (spaceRgb < 4) {
			c = RGB(255, int(255 - dFatorRgb), 0);
		}else if (spaceRgb == 4) {
			c = RGB(255, 0, 0);
		}else {
			//Caso de erro
			c = RGB(128, 128, 128);
		}
		return c;
	}

	void ClearCont(void) {
		for (int i = 0; i < 4; i++){
			nCountDepth[i] = 0;			
		}			
	}

public:
	int ValueMin, ValueMax;
	int Posx, Posy, Frame, Depth;
	int ColFrame, ColPosX, ColPosY, ColColor, ColDepth;
	int PosCuX, PosCuY;
	COLORREF Color;

	CU() {
		ValueMax = 100;
		ValueMin = 0;
		ColPosX  = 3;
		ColPosY  = 4;
		ColFrame = 5;
		ColDepth = 7;
		Frame	 = -1;
		Posx	 = -1;
		Posy	 = -1;

		ClearCont();
	}

	int CUSize(void) {
		return c_CuSize[Depth];
	}

	void SetNewPositionXY(int nX, int nY, int nDepth) {
		int position = (nCountDepth[1] * c_nDepth[1]) + (nCountDepth[2] * c_nDepth[2]) + (nCountDepth[3] * c_nDepth[3]);

		if (position > 64) {
			LOG_MESSAGE("ERRO SetNewPositionXY : Posição > 64");
			PosCuY = nY;
			PosCuX = nX;
			return;
		}

		//Calcula o X e Y da posição atual
		int posM;		
		posM = int(floor(position / 16));
		PosCuY = c_mY[posM];
		PosCuX = c_mX[posM];

		posM = int(floor((position % 16) / 4));

		PosCuY = (c_mY[posM] / 2) + PosCuY;
		PosCuX = (c_mX[posM] / 2) + PosCuX;

		posM = (position % 16) % 4;
		PosCuY = (c_mY[posM] / 4) + PosCuY;
		PosCuX = (c_mX[posM] / 4) + PosCuX;

		PosCuX = nX + PosCuX;
		PosCuY = nY + PosCuY;

		nCountDepth[nDepth]++;	
	}

	void SetCUFromLine(vector <string> lineSplit) {
		int newPosX = 0;
		int newPosY = 0;
		
		Depth   = atoi(lineSplit[ColDepth].c_str());
		newPosX = atoi(lineSplit[ColPosX].c_str());
		newPosY = atoi(lineSplit[ColPosY].c_str());
		Frame   = atoi(lineSplit[ColFrame].c_str());
		Color   = GetHeat(lineSplit[ColColor]);

		if ((newPosX != Posx) || (newPosY != Posy)) {
			ClearCont();
		}
		
		Posx = newPosX;
		Posy = newPosY;
		SetNewPositionXY(Posx, Posy, Depth);
	}
};

class ImageCalor {	
	FILE* hOutFile;

	uint8_t* yPixels, * uPixels, * vPixels;	

	uint32_t chromaHeight;
	uint32_t chromaWidth;

public:
	int Width, Height, Frame, CUSize;

	ImageCalor() {
		CUSize    = 64;
		Frame     = -1;
		hOutFile  = 0;
	}

	void ClearImageHeatMap(void) {
		LOG_MESSAGE("Clear");
		// Pointers we are working with
		uint8_t Rc, Gc, Bc;
		uint32_t x, y, xMask = 1, yMask = 1;
		uint8_t* yPtr, * uPtr, * vPtr;
		yPtr = yPixels;
		uPtr = uPixels;
		vPtr = vPixels;

		COLORREF rgbPixels;

		for (y = 0; y < Height; y++) {
			for (x = 0; x < Width; x++) {
				rgbPixels = RGB(50, 50, 50);
				Rc = GetRValue(rgbPixels);
				Gc = GetGValue(rgbPixels);
				Bc = GetBValue(rgbPixels);

				*yPtr++ = uint8_t(RGB2Y(Rc, Gc, Bc));

				if ((y & yMask) == 0 && (x & xMask) == 0 && (y / 2) < chromaHeight && (x / 2) < chromaWidth) {
					*uPtr++ = uint8_t(RGB2U(Rc, Gc, Bc));
					*vPtr++ = uint8_t(RGB2V(Rc, Gc, Bc));
				}
			}
		}
	}

	void SetNewVideoYUV(string path) {
		LOG_MESSAGE("SetVideo path : " + path);
		
		hOutFile = fopen(path.c_str(), "wb");

		chromaHeight = Height / 2;
		chromaWidth  = Width / 2;

		int nMult      = Width * Height;
		int nMultChroma = chromaHeight * chromaWidth;
		yPixels = (uint8_t*)malloc(nMult * sizeof(uint8_t));
		uPixels = (uint8_t*)malloc(nMultChroma * sizeof(uint8_t));
		vPixels = (uint8_t*)malloc(nMultChroma * sizeof(uint8_t));

		ClearImageHeatMap();
	}

	void SaveImageYUV(uint8_t* yPix, uint8_t* uPix, uint8_t* vPix) {
		LOG_MESSAGE("CreateImageYUV");
		uint8_t* yPtr, * uPtr, * vPtr;
		yPtr = yPix;
		uPtr = uPix;
		vPtr = vPix;

		int nMult = Width * Height;
		fwrite(yPtr, 1, nMult, hOutFile);
		// Simply write U and V planes
		nMult = chromaWidth * chromaHeight;
		fwrite(uPtr, 1, nMult, hOutFile);
		fwrite(vPtr, 1, nMult, hOutFile);

		fseek(hOutFile, 0, SEEK_END);

		LOG_MESSAGE("Done!");
	}

	void SaveImage() {
		SaveImageYUV(yPixels, uPixels, vPixels);	
	}

	void ClearSort(void) {
		ClearImageHeatMap();
		//Size por slice
		long int SizeFrame = (Width * Height);
		SizeFrame = SizeFrame + ((chromaWidth * chromaHeight) * 2);
		long int nPosVideo = ftell(hOutFile);
		int SlicePos = nPosVideo / SizeFrame;
		if (SlicePos < Frame) {
			for (int i = 0; i < (Frame - SlicePos); i++) {
				//guarda a posição dos slices faltantes
				SaveImage();
			}
		}
		else {
			//posiciona o seek no inicio do slice que será escrito
			long int NewPosSlice = Frame * SizeFrame;
			fseek(hOutFile, NewPosSlice, SEEK_SET);
		}
	}

	void ColorYUV(uint32_t Posx, uint32_t Posy, COLORREF color, int localCUSize) {
		uint8_t* yPtr, * uPtr, * vPtr;
		uint8_t Rc, Gc, Bc;
		uint32_t xMask = 1, yMask = 1;

		yPtr = yPixels;
		uPtr = uPixels;
		vPtr = vPixels;

		uint32_t nPosition;
		Rc = GetRValue(color);
		Gc = GetGValue(color);
		Bc = GetBValue(color);		

		for (uint32_t i = Posy; i < (Posy + localCUSize); i++) {
			for (uint32_t j = Posx; j < (Posx + localCUSize); j++) {
				nPosition = (i * Width) + j;
				if (!(nPosition > (Height * Width))) {
					yPtr[nPosition] = uint8_t(RGB2Y(Rc, Gc, Bc)); 
				} else {
					continue;
				}

				if ((i & yMask) == 0 && (j & xMask) == 0 && (i / 2) < chromaHeight && (j / 2) < chromaWidth) {
					nPosition = ((i / 2) * chromaWidth) + (j / 2);
					if (!(nPosition > (chromaHeight * chromaWidth))) {
						uPtr[nPosition] = uint8_t(RGB2U(Rc, Gc, Bc));
						vPtr[nPosition] = uint8_t(RGB2V(Rc, Gc, Bc));
					}
				}
			}
		}
	}

	void FreeMemory(void) {
		if (Frame != -1) {
			LOG_MESSAGE("FreeMemory");
			fclose(hOutFile);
			hOutFile = 0;
			
			/*
			free(yPixels);
			free(uPixels);
			free(vPixels);
			*/
		}
	}
};

class BlendTwoVideos {
	struct Frame {
		uint8_t* yPix;
		uint8_t* uPix;
		uint8_t* vPix;
	};

	int chromaHeight, chromaWidth;
	ImageCalor BlendImage;

	void Reposition(ifstream& file, int nSlice) {
		//Size por slice
		long int SizeFrame = (Width * Height);
		SizeFrame = SizeFrame + ((chromaWidth * chromaHeight) * 2);

		long int NewPosSlice = nSlice * SizeFrame;

		file.seekg(NewPosSlice, file.beg);
	}

	void LoadFrame(ifstream& inOriginal, uint8_t* pLuma, uint8_t* pCr, uint8_t* pCb) {
		LOG_MESSAGE("Load Frame: ");
		// Pointers we are working with
		uint32_t xMask = 1, yMask = 1;
		uint8_t* yPtr, * uPtr, * vPtr;
		yPtr = pLuma;
		uPtr = pCr;
		vPtr = pCb;
		int mult = Height * Width;
		inOriginal.read((char*)yPtr, mult);

		mult = chromaHeight * chromaWidth;
		inOriginal.read((char*)uPtr, mult);
		inOriginal.read((char*)vPtr, mult);
	}

	void BlendFrarmes(ifstream& inHeatMap, ifstream& inOriginal, Frame sfHeatMap, Frame sfOriginal) {
		#define ChannelBlend_Normal(A,B)     ((uint8_t)(A))
		#define ChannelBlend_Lighten(A,B)    ((uint8_t)((B > A) ? B:A))
		#define ChannelBlend_Darken(A,B)     ((uint8_t)((B > A) ? A:B))
		#define ChannelBlend_Multiply(A,B)   ((uint8_t)((A * B) / 255))
		#define ChannelBlend_Average(A,B)    ((uint8_t)((A + B) / 2))
		#define ChannelBlend_Add(A,B)        ((uint8_t)(min(255, (A + B))))
		#define ChannelBlend_Subtract(A,B)   ((uint8_t)((A + B < 255) ? 0:(A + B - 255)))
		#define ChannelBlend_Difference(A,B) ((uint8_t)(abs(A - B)))
		#define ChannelBlend_Negation(A,B)   ((uint8_t)(255 - abs(255 - A - B)))
		#define ChannelBlend_Screen(A,B)     ((uint8_t)(255 - (((255 - A) * (255 - B)) >> 8)))
		#define ChannelBlend_Exclusion(A,B)  ((uint8_t)(A + B - 2 * A * B / 255))
		#define ChannelBlend_Overlay(A,B)    ((uint8_t)((B < 128) ? (2 * A * B / 255):(255 - 2 * (255 - A) * (255 - B) / 255)))
		#define ChannelBlend_SoftLight(A,B)  ((uint8_t)((B < 128)?(2*((A>>1)+64))*((float)B/255):(255-(2*(255-((A>>1)+64))*(float)(255-B)/255))))
		#define ChannelBlend_HardLight(A,B)  (ChannelBlend_Overlay(B,A))
		#define ChannelBlend_ColorDodge(A,B) ((uint8_t)((B == 255) ? B:min(255, ((A << 8 ) / (255 - B)))))
		#define ChannelBlend_ColorBurn(A,B)  ((uint8_t)((B == 0) ? B:max(0, (255 - ((255 - A) << 8 ) / B))))
		#define ChannelBlend_LinearDodge(A,B)(ChannelBlend_Add(A,B))
		#define ChannelBlend_LinearBurn(A,B) (ChannelBlend_Subtract(A,B))
		#define ChannelBlend_LinearLight(A,B)((uint8_t)(B < 128)?ChannelBlend_LinearBurn(A,(2 * B)):ChannelBlend_LinearDodge(A,(2 * (B - 128))))
		#define ChannelBlend_VividLight(A,B) ((uint8_t)(B < 128)?ChannelBlend_ColorBurn(A,(2 * B)):ChannelBlend_ColorDodge(A,(2 * (B - 128))))
		#define ChannelBlend_PinLight(A,B)   ((uint8_t)(B < 128)?ChannelBlend_Darken(A,(2 * B)):ChannelBlend_Lighten(A,(2 * (B - 128))))
		#define ChannelBlend_HardMix(A,B)    ((uint8_t)((ChannelBlend_VividLight(A,B) < 128) ? 0:255))
		#define ChannelBlend_Reflect(A,B)    ((uint8_t)((B == 255) ? B:min(255, (A * A / (255 - B)))))
		#define ChannelBlend_Glow(A,B)       (ChannelBlend_Reflect(B,A))
		#define ChannelBlend_Phoenix(A,B)    ((uint8_t)(min(A,B) - max(A,B) + 255))
		#define ChannelBlend_Alpha(A,B,O)    ((uint8_t)(O * A + (1 - O) * B))
		#define ChannelBlend_AlphaF(A,B,F,O) (ChannelBlend_Alpha(F(A,B),A,O))

		LoadFrame(inOriginal, sfOriginal.yPix, sfOriginal.uPix, sfOriginal.vPix);
		LoadFrame(inHeatMap, sfHeatMap.yPix, sfHeatMap.uPix, sfHeatMap.vPix);

		LOG_MESSAGE("Blend  Frame: ");
		// Pointers we are working with	
		uint32_t x, y, xMask = 1, yMask = 1;
		uint8_t* yPtr, * uPtr, * vPtr;
		yPtr = sfOriginal.yPix;
		uPtr = sfOriginal.uPix;
		vPtr = sfOriginal.vPix;

		uint8_t* yPtrHeat, * uPtrHeat, * vPtrHeat;
		yPtrHeat = sfHeatMap.yPix;
		uPtrHeat = sfHeatMap.uPix;
		vPtrHeat = sfHeatMap.vPix;

		uint8_t aux;
		for (y = 0; y < Height; y++) {
			for (x = 0; x < Width; x++) {
				*yPtrHeat++ = ChannelBlend_AlphaF(*yPtr, *yPtrHeat, ChannelBlend_HardLight, 0.5F);
				yPtr++;
				if ((y & yMask) == 0 && (x & xMask) == 0 && (y / 2) < chromaHeight && (x / 2) < chromaWidth) {
					aux = ChannelBlend_AlphaF(*uPtr, *uPtrHeat, ChannelBlend_HardLight, 0.5F);
					*uPtrHeat++ = aux;
					aux = ChannelBlend_AlphaF(*vPtr, *vPtrHeat, ChannelBlend_HardLight, 0.5F);
					*vPtrHeat++ = aux;
					uPtr++;
					vPtr++;
				}
			}
		}

		BlendImage.SaveImageYUV(sfHeatMap.yPix, sfHeatMap.uPix, sfHeatMap.vPix);
	}

public :
	int Height, Width, CUSize;

	void StartBlend(string pathOut, string arqOrig, string arqHeat) {				
		chromaHeight = Height / 2;
		chromaWidth = Width / 2;

		//Define variaveis básicas		
		BlendImage.Width = Width;
		BlendImage.Height = Height;
		BlendImage.FreeMemory();
		BlendImage.SetNewVideoYUV(pathOut + "\\out_dissolved.yuv");

		std::ifstream inHeatMap;
		std::ifstream inOriginal;
		
		inHeatMap.open(arqHeat,  std::ios::binary | std::ios::in);
		inOriginal.open(arqOrig, std::ios::binary | std::ios::in);

		Frame sfHeatMap, sfOriginal;
		int nMult = Height * Width;
		sfHeatMap.yPix = (uint8_t*)malloc(nMult * sizeof(uint8_t));
		sfOriginal.yPix = (uint8_t*)malloc(nMult * sizeof(uint8_t));

		nMult = chromaHeight * chromaWidth;
		sfHeatMap.uPix = (uint8_t*)malloc(nMult * sizeof(uint8_t));
		sfHeatMap.vPix = (uint8_t*)malloc(nMult * sizeof(uint8_t));

		sfOriginal.uPix = (uint8_t*)malloc(nMult * sizeof(uint8_t));
		sfOriginal.vPix = (uint8_t*)malloc(nMult * sizeof(uint8_t));


		if (inHeatMap.is_open() && inOriginal.is_open()) {	
			while (inHeatMap.good() && inOriginal.good()) {
				BlendFrarmes(inHeatMap, inOriginal, sfHeatMap, sfOriginal);
			}
		}

		//Liberar memoria
		free(sfHeatMap.yPix);
		free(sfHeatMap.uPix);
		free(sfHeatMap.vPix);

		free(sfOriginal.yPix);
		free(sfOriginal.uPix);
		free(sfOriginal.vPix);

		inHeatMap.close();
		inOriginal.close();
	}
};

class CreateHeatMap {	
public :	
	int Width, Height;
	int ColPosX, ColPosY, ColFrame, ColDepth;
	string Delim, DirOut, FileOut;

	CreateHeatMap() {
		ColPosX	 = 3;
		ColPosY  = 4;
		ColFrame = 5;
		ColDepth = 7;
		Width    = 1280;
		Height	 = 720;
		FileOut  = "64";
		Delim	 = ",";
		DirOut	 = "c:\\temp";
	}	

	vector<string> split(const string& str, const string& delim) {
		vector<string> tokens;
		size_t prev = 0, pos = 0;
		do {
			pos = str.find(delim, prev);
			if (pos == string::npos) pos = str.length();
			string token = str.substr(prev, pos - prev);
			if (!token.empty()) tokens.push_back(token);
			prev = pos + delim.length();
		} while (pos < str.length() && prev < str.length());
		return tokens;
	}

	static int StringToWString(std::wstring& ws, const std::string& s) {
		std::wstring wsTmp(s.begin(), s.end());
		ws = wsTmp;
		return 0;
	}

	void LoadHeatMap(string PathFile, int nIndexHeat, int nValueMin, int nValueMax, int nRemoveLines) {		
		ifstream pfFIle(PathFile.c_str());
		if (!pfFIle.is_open()) {
			LOG_MESSAGE("ERROR: File Open");
		}

		string line;
		vector <string> lineSplit;

		//DELETA CABEÇALHOS
		for (int i = 0; i < nRemoveLines; i++) {
			getline(pfFIle, line);
		}

		//Define variaveis básicas
		ImageCalor HeatImage;
		HeatImage.Width = this->Width;
		HeatImage.Height = this->Height;
		HeatImage.Frame = -1;
		HeatImage.FreeMemory();		
		HeatImage.SetNewVideoYUV(DirOut + "\\out_" + FileOut + ".yuv");
		
		//Inicia váriaveis locais
		bool bFirstLoop = true;
		CU lineCU;		
		lineCU.ColColor = nIndexHeat;	
		lineCU.ColFrame = ColFrame;
		lineCU.ColPosX  = ColPosX;
		lineCU.ColPosY  = ColPosY;
		lineCU.ColDepth = ColDepth;
		
		lineCU.ValueMin = nValueMin;
		lineCU.ValueMax = nValueMax;

		//ultima coluna
		int nMaxCol = nIndexHeat;
		if (ColFrame > nMaxCol) {
			nMaxCol = ColFrame;
		}
		if (ColPosX > nMaxCol) {
			nMaxCol = ColPosX;
		}
		if (ColPosY > nMaxCol) {
			nMaxCol = ColPosY;
		}
		if (ColDepth > nMaxCol) {
			nMaxCol = ColDepth;
		}

		while (pfFIle.good()) {
			getline(pfFIle, line);

			lineSplit = split(line, Delim);
			
			//Controle de acesso a posição
			if (nMaxCol < lineSplit.size()){
				lineCU.SetCUFromLine(lineSplit);
			}

			//Se for primeira passagem
			if (bFirstLoop) {	
				HeatImage.Frame = lineCU.Frame;
				HeatImage.ClearSort();
				bFirstLoop = false;
			}
						
			//Novo quadro se quadro atual for diferente do anterior
			if (HeatImage.Frame != lineCU.Frame) {
				HeatImage.SaveImage();
				HeatImage.Frame = lineCU.Frame;
				HeatImage.ClearSort();
			}

			HeatImage.ColorYUV(lineCU.PosCuX, lineCU.PosCuY, lineCU.Color, lineCU.CUSize());
		}
		HeatImage.SaveImage();
		
		pfFIle.close();
		HeatImage.FreeMemory();
	}
};
