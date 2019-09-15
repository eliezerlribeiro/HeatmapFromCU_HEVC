#include <msclr\marshal_cppstd.h>

#include <thread>

#include <string>
#include <stdio.h>
#include <tchar.h>
#include <stdint.h>
#include <windows.h>
#include <algorithm>
#include <memory>
#include <iostream>
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

#define LOG_MESSAGE(...) {printf(__VA_ARGS__); printf("\n");}
#define LOG_ERROR(...) {printf("ERROR: "); printf(__VA_ARGS__); printf("\n");}

// RGB -> YUV
#define CLIP(X) ( (X) > 255 ? 255 : (X) < 0 ? 0 : X)
#define RGB2Y(R, G, B) CLIP(( (  66 * (R) + 129 * (G) +  25 * (B) + 128) >> 8) +  16)
#define RGB2U(R, G, B) CLIP(( ( -38 * (R) -  74 * (G) + 112 * (B) + 128) >> 8) + 128)
#define RGB2V(R, G, B) CLIP(( ( 112 * (R) -  94 * (G) -  18 * (B) + 128) >> 8) + 128)

using std::vector;
using std::string;
using std::wstring;
using std::cout;
using std::endl;
using std::ifstream;
using std::to_string;

class CU {
	double NormalizeToRange(double dToNormal) {
		dToNormal = (dToNormal - ValueMin) / (ValueMax - ValueMin);
		return dToNormal * 100;
	}

	COLORREF ConvertColor(string param) {
		double x = atof(param.c_str());

		// Normaliza para ficar de 0 - 100
		double xNormal = NormalizeToRange(x);

		double c_FatorMult = 255 / 25;

		//Retorna fator rgb (heat)
		double dFatorRgb = c_FatorMult * (int(xNormal) % 25);
		if (dFatorRgb > 255) {
			dFatorRgb = 255;
		}
		else if (dFatorRgb < 0) {
			dFatorRgb = 0;
		}

		COLORREF c;
		int spaceRgb = int(xNormal / 25);
		if (spaceRgb < 1) {
			c = RGB(0, int(dFatorRgb), 255);
		}
		else if (spaceRgb < 2) {
			c = RGB(0, 255, int(255 - dFatorRgb));
		}
		else if (spaceRgb < 3) {
			c = RGB(int(dFatorRgb), 255, 0);
		}
		else if (spaceRgb < 4) {
			c = RGB(255, int(255 - dFatorRgb), 0);
		}
		else if (spaceRgb == 4) {
			c = RGB(255, 0, 0);
		}
		else {
			c = RGB(128, 128, 128);
		}

		return c;
	}

public:
	int ValueMin, ValueMax;
	int Posx, Posy, Slice;
	int ColSlice, ColPosX, ColPosY, ColColor;
	COLORREF Color;

	CU() {
		ValueMax = 100;
		ValueMin = 0;
		ColPosX = 3;
		ColPosY = 4;
		ColSlice = 5;
	}

	void SetCUFromLine(vector <string> lineSplit) {
		if (ColPosX < lineSplit.capacity()) {
			Posx = atoi(lineSplit[ColPosX].c_str());
		}

		if (ColPosY < lineSplit.capacity()) {
			Posy = atoi(lineSplit[ColPosY].c_str());
		}

		if (ColSlice < lineSplit.capacity()) {
			Slice = atoi(lineSplit[ColSlice].c_str());
		}

		if (ColColor < int(lineSplit.capacity())) {
			Color = ConvertColor(lineSplit[ColColor]);
		}
	}
};

class CUIndexMap {
public :
	int Posx, Posy;
};

class ImageCalor {
	vector <CUIndexMap> HeatMapBmp;

	FILE* hOutFile;

	uint8_t* yPixels, * uPixels, * vPixels;	

	uint32_t lumaHeight;
	uint32_t lumaWidth;
	uint32_t chromaHeight;
	uint32_t chromaWidth;

public:
	int Width, Height, Slice, CUSize;

	ImageCalor() {
		CUSize   = 64;
		Slice      = -1;
		hOutFile   = 0;
	}

	void ClearImageHeatmap(void) {
		cout << "Clear: " << endl;
		// Pointers we are working with
		uint8_t Rc, Gc, Bc;
		uint32_t x, y, xMask = 1, yMask = 1;
		uint8_t* yPtr, * uPtr, * vPtr;
		yPtr = yPixels;
		uPtr = uPixels;
		vPtr = vPixels;

		COLORREF rgbPixels;

		for (y = 0; y < lumaHeight; y++) {
			for (x = 0; x < lumaWidth; x++) {
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
		cout << "SetVideo path: " << path << endl;

		hOutFile = fopen(path.c_str(), "wb");

		lumaHeight   = Height;
		lumaWidth    = Width;
		chromaHeight = lumaHeight / 2;
		chromaWidth  = lumaWidth / 2;

		int nMult      = Width * Height;
		int nMultChroma = chromaHeight * chromaWidth;
		yPixels = (uint8_t*)malloc(nMult * sizeof(uint8_t));
		uPixels = (uint8_t*)malloc(nMultChroma * sizeof(uint8_t));
		vPixels = (uint8_t*)malloc(nMultChroma * sizeof(uint8_t));

		ClearImageHeatmap();
	}

	void SaveImageYUV(uint8_t* yPix, uint8_t* uPix, uint8_t* vPix) {
		LOG_MESSAGE("CreateImageYUV");
		uint8_t* yPtr, * uPtr, * vPtr;
		yPtr = yPix;
		uPtr = uPix;
		vPtr = vPix;

		int nMult = lumaWidth * lumaHeight;
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

	void ClearSort(int localSlice) {
		ClearImageHeatmap();

		//Size por slice
		long int SizeSlice = (lumaWidth * lumaHeight);
		SizeSlice = SizeSlice + ((chromaWidth * chromaHeight) * 2);

		long int nPosVideo = ftell(hOutFile);

		int SlicePos = nPosVideo / SizeSlice;

		if (SlicePos < localSlice) {
			for (int i = 0; i < (localSlice - SlicePos); i++) {
				//guarda a posição dos slices faltantes
				SaveImage();
			}
		}
		else {
			//posiciona o seek no inicio do slice que será escrito
			long int NewPosSlice = localSlice * SizeSlice;
			fseek(hOutFile, NewPosSlice, SEEK_SET);
		}
	}

	void Clear() {
		HeatMapBmp.clear();
		ClearSort(Slice);
	}

	void AddCU(CU lineCU) {
		bool bFound = false;
		for (int nIndex = 0; nIndex < int(HeatMapBmp.size()); nIndex++) {
			if ((HeatMapBmp[nIndex].Posx == lineCU.Posx) && (HeatMapBmp[nIndex].Posy == lineCU.Posy)) {
				bFound = true;
			}
		}

		if (!bFound) {
			ColorYUV(lineCU.Posx, lineCU.Posy, lineCU.Color);
			CUIndexMap cuMap;
			cuMap.Posx = lineCU.Posx;
			cuMap.Posy = lineCU.Posy;
			HeatMapBmp.push_back(cuMap);
		}
	}

	void ColorYUV(uint32_t Posx, uint32_t Posy, COLORREF color) {
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

		for (uint32_t i = Posy; i < (Posy + CUSize); i++) {
			for (uint32_t j = Posx; j < (Posx + CUSize); j++) {
				nPosition = (i * lumaWidth) + j;
				if (!(nPosition > (lumaHeight * lumaWidth))) {
					yPtr[nPosition] = uint8_t(RGB2Y(Rc, Gc, Bc)); 
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
		if (Slice != -1) {
			cout << "FreeMemory" << endl;
			fclose(hOutFile);
			hOutFile = 0;

			free(yPixels);
			free(uPixels);
			free(vPixels);
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
		long int SizeSlice = (Width * Height);
		SizeSlice = SizeSlice + ((chromaWidth * chromaHeight) * 2);

		long int NewPosSlice = nSlice * SizeSlice;

		file.seekg(NewPosSlice, file.beg);
	}

	void LoadFrame(ifstream& inOriginal, uint8_t* pLuma, uint8_t* pCr, uint8_t* pCb) {
		cout << "Load Frame: " << endl;
		// Pointers we are working with
		uint32_t x, y, xMask = 1, yMask = 1;
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

		cout << "Blend  Frame: " << endl;
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


		COLORREF rgbColor, rgbHeat;
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
				
		//Define variaveis básicas		
		BlendImage.Width = this->Width;
		BlendImage.Height = this->Height;
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
private :
	string m_strDelim;
	string m_strDirOut;
	string strFileOut;
public :	
	int Width, Height, CUSize;
	int ColPosX, ColPosY, ColSlice;
	
	CreateHeatMap() {
		ColPosX = 3;
		ColPosY = 4;
		ColSlice = 5;
		Width = 1280;
		Height = 720;
		strFileOut   = "64";
		m_strDelim   = ",";
		m_strDirOut  = "c:\\temp";
		CUSize     = 64;
	}

	void SetFileOut(string strOut) {
		strFileOut = strOut;
	}

	void SetDelim(string delim) {
		m_strDelim = delim;
	}

	void SetCuSize(int LocalCUSize) {
		CUSize = LocalCUSize;
	}

	string SetPath(string strDirOut) {
		m_strDirOut = strDirOut;
		return CreateFolder(m_strDirOut);
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

	string CreateFolder(string folderVideo) {		
		wstring strPathVideo;
		StringToWString(strPathVideo, folderVideo);

		LPCWSTR wide_string;
		wide_string = strPathVideo.c_str();

		if (CreateDirectory(wide_string, NULL)) {		
			return "Create";
		}else if (ERROR_ALREADY_EXISTS == GetLastError()) {
			return "ALREADY_EXISTS";
		}else if (ERROR_PATH_NOT_FOUND == GetLastError()) {
			return "ERROR: ERROR_PATH_NOT_FOUND";
		}else {
			return "ERROR: Failed to create directory";
		}
	}

	static int StringToWString(std::wstring& ws, const std::string& s) {
		std::wstring wsTmp(s.begin(), s.end());
		ws = wsTmp;
		return 0;
	}

	void LoadHeatMap(string PathFile, int nIndexHeat, int nValueMin, int nValueMax, int nRemoveLines) {		
		ifstream pfFIle(PathFile.c_str());
		if (!pfFIle.is_open()) {
			cout << "ERROR: File Open" << '\n';
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
		HeatImage.Slice = -1;
		HeatImage.CUSize = this->CUSize;
		HeatImage.FreeMemory();		
		HeatImage.SetNewVideoYUV(m_strDirOut + "\\out_" + strFileOut + ".yuv");
		
		//Inicia váriaveis locais
		bool bFirstLoop = true;
		CU lineCU;		
		lineCU.ColColor = nIndexHeat;
		lineCU.ValueMin = nValueMin;
		lineCU.ValueMax = nValueMax;

		while (pfFIle.good()) {
			getline(pfFIle, line);

			lineSplit = split(line, m_strDelim);
			lineCU.SetCUFromLine(lineSplit);

			if (bFirstLoop) {	
				HeatImage.Slice = lineCU.Slice;
				HeatImage.Clear();
				bFirstLoop = false;
			}
						
			//New Frame se slice for diferente
			if (HeatImage.Slice != lineCU.Slice) {
				HeatImage.SaveImage();
				HeatImage.Slice = lineCU.Slice;
				HeatImage.Clear();
			}

			HeatImage.AddCU(lineCU);
		}
		HeatImage.SaveImage();
		
		pfFIle.close();
		//HeatImage.FreeMemory();
	}
};
