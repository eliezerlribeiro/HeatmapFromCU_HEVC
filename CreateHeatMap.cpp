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

#define CLIP(X) ( (X) > 255 ? 255 : (X) < 0 ? 0 : X)

// RGB -> YUV
#define RGB2Y(R, G, B) CLIP(( (  66 * (R) + 129 * (G) +  25 * (B) + 128) >> 8) +  16)
#define RGB2U(R, G, B) CLIP(( ( -38 * (R) -  74 * (G) + 112 * (B) + 128) >> 8) + 128)
#define RGB2V(R, G, B) CLIP(( ( 112 * (R) -  94 * (G) -  18 * (B) + 128) >> 8) + 128)

const uint32_t width = 1920;
const uint32_t height = 1080;
const uint16_t depth = 24;

using std::vector;
using std::string;
using std::wstring;
using std::cout;
using std::endl;
using std::ifstream;
using std::to_string;

class CU {
	double NormalizeToRange(double dToNormal) {
		if (dToNormal < 1) {
			dToNormal = dToNormal * 100;
		}
		return dToNormal;
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
		}else if (dFatorRgb < 0) {
			dFatorRgb = 0;
		}

		COLORREF c;
		int spaceRgb = int(x / 25);
		if (spaceRgb < 1) {
			c = RGB(0, int(dFatorRgb), 255);
		} else if (spaceRgb < 2) {
			c = RGB(0, 255, int(255-dFatorRgb));
		}else if (spaceRgb < 3) {
			c = RGB(int(dFatorRgb), 255, 0);
		}else if (spaceRgb < 4) {
			c = RGB(255, int(255-dFatorRgb), 0);
		}else {
			c = RGB(128, 128, 128);
		}

		return c;
	}

public:
	int Posx, Posy, Slice;
	int ColSlice, ColPosX, ColPosY, ColColor;
	COLORREF Color;

	CU() {
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
		
		if (ColColor < int(lineSplit.capacity()) ) {
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
	bool appendMode;

	uint8_t* yPixels, * uPixels, * vPixels;

	COLORREF rgbPixels;

	uint32_t lumaHeight;
	uint32_t lumaWidth;
	uint32_t chromaHeight;
	uint32_t chromaWidth;

public:
	int Widht, Heigth, Slice, CUSize;

	ImageCalor() {
		CUSize   = 64;
		Slice      = -1;
		hOutFile   = 0;
		appendMode = false;
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

		hOutFile = fopen(path.c_str(), appendMode ? "ab" : "wb");

		lumaHeight   = Heigth;
		lumaWidth    = Widht;
		chromaHeight = lumaHeight / 2;
		chromaWidth  = lumaWidth / 2;

		int nMult = Widht * Heigth;
		yPixels = (uint8_t*)malloc(nMult * sizeof(uint8_t));
		uPixels = (uint8_t*)malloc(nMult * sizeof(uint8_t));
		vPixels = (uint8_t*)malloc(nMult * sizeof(uint8_t));

		ClearImageHeatmap();
	}

	void SaveImageYUV(void) {
		LOG_MESSAGE("CreateImageYUV");
		uint8_t* yPtr, * uPtr, * vPtr;
		yPtr = yPixels;
		uPtr = uPixels;
		vPtr = vPixels;

		int nMult = lumaWidth * lumaHeight;
		fwrite(yPtr, 1, nMult, hOutFile);
		// Simply write U and V planes
		nMult = chromaWidth * chromaHeight;
		fwrite(uPtr, 1, nMult, hOutFile);
		fwrite(vPtr, 1, nMult, hOutFile);

		ClearImageHeatmap();

		LOG_MESSAGE("Done!");
	}

	void Clear() {
		HeatMapBmp.clear();
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

	bool IsSameSlice(int nSlice) {
		if (nSlice == Slice) {
			return true;
		}
		else {
			return false;
		}
	}
};

class CreateHeatMap {	
private :
	string m_strDelim;
	string m_strDirOut;
	string strFileOut;
public :	
	int Widht, Heigth, CUSize;
	int ColPosX, ColPosY, ColSlice;
	
	CreateHeatMap() {
		ColPosX = 3;
		ColPosY = 4;
		ColSlice = 5;
		Widht = 1280;
		Heigth = 720;
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
		m_strDirOut = strDirOut + "\\video";
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

	void LoadHeatMap(string PathFile, int nIndexHeat, int nRemoveLines) {		
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
		HeatImage.Widht = this->Widht;
		HeatImage.Heigth = this->Heigth;
		HeatImage.Slice = -1;
		HeatImage.CUSize = this->CUSize;
		HeatImage.FreeMemory();		
		HeatImage.SetNewVideoYUV(m_strDirOut + "\\out_" + strFileOut + ".yuv");
		
		//Inicia váriaveis locais
		bool bFirstLoop = true;
		CU lineCU;		
		lineCU.ColColor = nIndexHeat;

		while (pfFIle.good()) {
			getline(pfFIle, line);

			lineSplit = split(line, m_strDelim);
			lineCU.SetCUFromLine(lineSplit);

			if (bFirstLoop) {	
				HeatImage.Slice = lineCU.Slice;
				bFirstLoop = false;
			}
						
			//New Frame se slice for diferente
			if (HeatImage.Slice != lineCU.Slice) {
				HeatImage.SaveImageYUV();
				HeatImage.Slice = lineCU.Slice;
				HeatImage.Clear();
			}

			HeatImage.AddCU(lineCU);
		}
		HeatImage.SaveImageYUV();
		
		pfFIle.close();
		HeatImage.FreeMemory();
	}
};
