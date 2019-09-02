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
	int address, Slice, Depth;
	int SizeNxN;
	int IndexOfColor;
	COLORREF m_Color;

	COLORREF ConvertColor(string param) {
		double x = atof(param.c_str());
		if (x < 1) {
			x = x * 100;
		}

		double c_FatorMult = 255 / 25;

		double dFatorRgb = c_FatorMult * (int(x) % 25);
		if (dFatorRgb > 255) {
			dFatorRgb = 255;
		}else if (dFatorRgb < 0) {
			dFatorRgb = 0;
		}

		int spaceRgb = x / 25;

		COLORREF c;
		if (spaceRgb < 1) {
			c = RGB(0, int(dFatorRgb), 255);
		} else if (spaceRgb < 2) {
			c = RGB(0, 255, int(255-dFatorRgb));
		}else if (spaceRgb < 3) {
			c = RGB(int(dFatorRgb), 255, 0);
		}else {
			c = RGB(255, int(255-dFatorRgb), 0);
		}

		return c;
	}

public:
	int Posx, Posy, Widht, Heigth;
	CU() {
		IndexOfColor = 1;
	}

	COLORREF GetColor() {
		return m_Color;
	}

	int GetSlice() {
		return Slice;
	}
	int GetWidht() {
		return Widht;
	}

	int GetHeigth() {
		return Heigth;
	}

	void SetIndexColor(int nIndex) {
		IndexOfColor = nIndex;
	}

	void SetCUFromLine(vector <string> lineSplit) {
		if (7 < lineSplit.capacity()) {
			address = atoi(lineSplit[0].c_str());
			Heigth = atoi(lineSplit[1].c_str());
			Widht = atoi(lineSplit[2].c_str());
			Posx = atoi(lineSplit[3].c_str());
			Posy = atoi(lineSplit[4].c_str());
			Slice = atoi(lineSplit[5].c_str());
			Depth = atoi(lineSplit[7].c_str());
		}
		
		if (IndexOfColor < int(lineSplit.capacity()) ) {
			m_Color = ConvertColor(lineSplit[IndexOfColor]);
		}else{
			m_Color = RGB(255, 0, 0);
		}
	}
};

class CUIndexMap {
public :
	int Posx, Posy;
};

class ImageCalor {
	int Widht, Heigth, Slice;
	int m_CUSize;
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
	ImageCalor() {
		m_CUSize   = 64;
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

	void SetNewVideoYUV(CU lineCU, string path) {
		cout << "SetVideo path: " << path << endl;

		Slice = lineCU.GetSlice();
		Widht = lineCU.GetWidht();
		Heigth = lineCU.GetHeigth();

		hOutFile = fopen(path.c_str(), appendMode ? "ab" : "wb");

		lumaHeight = Heigth;
		lumaWidth = Widht;
		chromaHeight = lumaHeight / 2;
		chromaWidth = lumaWidth / 2;

		int nMult = Widht * Heigth;
		yPixels = (uint8_t*)malloc(nMult * sizeof(uint8_t));
		uPixels = (uint8_t*)malloc(nMult * sizeof(uint8_t));
		vPixels = (uint8_t*)malloc(nMult * sizeof(uint8_t));

		ClearImageHeatmap();
	}

	void SetCuSize(int CUSize) {
		m_CUSize = CUSize;
	}

	void SetSlice(CU lineCU) {
		Slice = lineCU.GetSlice();
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
		if (HeatMapBmp.capacity() > 0) {
			for (int nIndex = 0; nIndex < int(HeatMapBmp.size()); nIndex++) {
				if ((HeatMapBmp[nIndex].Posx == lineCU.Posx) && (HeatMapBmp[nIndex].Posy == lineCU.Posy)) {
					bFound = true;
				}
			}
		}

		if (!bFound) {
			ColorYUV(lineCU.Posx, lineCU.Posy, lineCU.GetColor());
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

		for (uint32_t i = Posy; i < (Posy + m_CUSize); i++) {
			for (uint32_t j = Posx; j < (Posx + m_CUSize); j++) {
				nPosition = (i * lumaWidth) + j;
				if (nPosition > (lumaHeight * lumaWidth)) {
					cout << "ERRO LUMA " << nPosition << " Posy " << Posy << " Posx " << Posx << " H " << lumaHeight << " W " << lumaWidth << endl;
				}
				else {
					yPtr[nPosition] = uint8_t(RGB2Y(Rc, Gc, Bc));
				}

				if ((i & yMask) == 0 && (j & xMask) == 0 && (i / 2) < chromaHeight && (j / 2) < chromaWidth) {
					nPosition = ((i / 2) * chromaWidth) + (j / 2);
					if (nPosition > (chromaHeight * chromaWidth)) {
						cout << "ERRO CROMA" << nPosition << " H " << chromaHeight << " W " << chromaWidth << endl;
					}
					else {
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
	int    m_CUSize;
public :
	CreateHeatMap() {
		strFileOut   = "64";
		m_strDelim   = ",";
		m_strDirOut  = "c:\\temp";
		m_CUSize     = 64;
	}

	void SetFileOut(string strOut) {
		strFileOut = strOut;
	}

	void SetDelim(string delim) {
		m_strDelim = delim;
	}

	void SetCuSize(int CUSize) {
		m_CUSize = CUSize;
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

		//Popula matriz
		bool bNewBmp = false;
		bool bFirstLoop = true;
		CU lineCU;
		ImageCalor HeatImage;
		int nBmpCount = 0, nCountLineCU = 0;

		HeatImage.FreeMemory();
		lineCU.SetIndexColor(nIndexHeat);
		HeatImage.SetCuSize(m_CUSize);
		while (pfFIle.good()) {
			getline(pfFIle, line);

			lineSplit = split(line, m_strDelim);
			lineCU.SetCUFromLine(lineSplit);

			if (bFirstLoop) {
				string nameArq = "\\out_" + strFileOut + ".yuv";
				cout << nameArq << endl;
				HeatImage.SetNewVideoYUV(lineCU, m_strDirOut + nameArq);				
				bFirstLoop = false;
			}
			
			bNewBmp = HeatImage.IsSameSlice(lineCU.GetSlice());
			nCountLineCU++;
			if (!bNewBmp) {				
				string aux = "New Bmp " + to_string(nBmpCount) + " countLine " + to_string(nCountLineCU) + "\n";
				cout << aux << endl;
				HeatImage.SaveImageYUV();
				HeatImage.SetSlice(lineCU);
				HeatImage.Clear();
				nCountLineCU = 0;
				nBmpCount += 1;
			}
			HeatImage.AddCU(lineCU);
		}
		HeatImage.SaveImageYUV();
		
		pfFIle.close();
	}
};
