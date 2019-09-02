#include <msclr\marshal_cppstd.h>

#include "CreateHeatMap.cpp"

#include <string>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

#pragma once

namespace HeatMapForm {
	using namespace std;

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;	

	/// <summary>
	/// Sumário para MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Adicione o código do construtor aqui
			//
		}

	protected:
		/// <summary>
		/// Limpar os recursos que estão sendo usados.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ gridHeader;
	protected:

	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Adress;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ High;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Width;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PosX;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PosY;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Slice;




	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown2;
	private: System::Windows::Forms::Label^ lblMin;
	private: System::Windows::Forms::Label^ lblMax;
	private: System::Windows::Forms::Button^ btnFile;

	private: System::Windows::Forms::OpenFileDialog^ openFD;
	private: System::Windows::Forms::Button^ btnCreateHeatmap;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::NumericUpDown^ upDownIgnore;

	private: System::Windows::Forms::CheckBox^ cbHasHeader;
	private: System::Windows::Forms::Label^ lblColColor;
	private: System::Windows::Forms::NumericUpDown^ upDownCol;
	private: System::Windows::Forms::TextBox^ edtDelim;

	private: System::Windows::Forms::Label^ lblDelimiter;
	private: System::Windows::Forms::TextBox^ pathFolderVideo;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::RichTextBox^ memoLogger;
	private: System::Windows::Forms::Label^ lblCuSize;
	private: System::Windows::Forms::NumericUpDown^ upCuSize;





	private:
		/// <summary>
		/// Variável de designer necessária.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necessário para suporte ao Designer - não modifique 
		/// o conteúdo deste método com o editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->gridHeader = (gcnew System::Windows::Forms::DataGridView());
			this->Adress = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->High = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Width = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PosX = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PosY = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Slice = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblMin = (gcnew System::Windows::Forms::Label());
			this->lblMax = (gcnew System::Windows::Forms::Label());
			this->btnFile = (gcnew System::Windows::Forms::Button());
			this->openFD = (gcnew System::Windows::Forms::OpenFileDialog());
			this->btnCreateHeatmap = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->upDownIgnore = (gcnew System::Windows::Forms::NumericUpDown());
			this->cbHasHeader = (gcnew System::Windows::Forms::CheckBox());
			this->lblColColor = (gcnew System::Windows::Forms::Label());
			this->upDownCol = (gcnew System::Windows::Forms::NumericUpDown());
			this->edtDelim = (gcnew System::Windows::Forms::TextBox());
			this->lblDelimiter = (gcnew System::Windows::Forms::Label());
			this->pathFolderVideo = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->memoLogger = (gcnew System::Windows::Forms::RichTextBox());
			this->lblCuSize = (gcnew System::Windows::Forms::Label());
			this->upCuSize = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridHeader))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->upDownIgnore))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->upDownCol))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->upCuSize))->BeginInit();
			this->SuspendLayout();
			// 
			// gridHeader
			// 
			this->gridHeader->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->gridHeader->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->Adress, this->High,
					this->Width, this->PosX, this->PosY, this->Slice
			});
			this->gridHeader->Location = System::Drawing::Point(11, 84);
			this->gridHeader->Name = L"gridHeader";
			this->gridHeader->Size = System::Drawing::Size(677, 195);
			this->gridHeader->TabIndex = 0;
			this->gridHeader->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::GridHeader_CellClick);
			// 
			// Adress
			// 
			this->Adress->HeaderText = L"Adress";
			this->Adress->Name = L"Adress";
			// 
			// High
			// 
			this->High->HeaderText = L"High";
			this->High->Name = L"High";
			// 
			// Width
			// 
			this->Width->HeaderText = L"Width";
			this->Width->Name = L"Width";
			// 
			// PosX
			// 
			this->PosX->HeaderText = L"PosX";
			this->PosX->Name = L"PosX";
			// 
			// PosY
			// 
			this->PosY->HeaderText = L"PosY";
			this->PosY->Name = L"PosY";
			// 
			// Slice
			// 
			this->Slice->HeaderText = L"Slice";
			this->Slice->Name = L"Slice";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->DecimalPlaces = 2;
			this->numericUpDown1->Location = System::Drawing::Point(101, 300);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(76, 20);
			this->numericUpDown1->TabIndex = 6;
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->DecimalPlaces = 2;
			this->numericUpDown2->Location = System::Drawing::Point(101, 326);
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(76, 20);
			this->numericUpDown2->TabIndex = 7;
			// 
			// lblMin
			// 
			this->lblMin->AutoSize = true;
			this->lblMin->Location = System::Drawing::Point(13, 305);
			this->lblMin->Name = L"lblMin";
			this->lblMin->Size = System::Drawing::Size(82, 13);
			this->lblMin->TabIndex = 8;
			this->lblMin->Text = L"Minimo Possivel";
			// 
			// lblMax
			// 
			this->lblMax->AutoSize = true;
			this->lblMax->Location = System::Drawing::Point(10, 328);
			this->lblMax->Name = L"lblMax";
			this->lblMax->Size = System::Drawing::Size(85, 13);
			this->lblMax->TabIndex = 9;
			this->lblMax->Text = L"Maximo Possivel";
			// 
			// btnFile
			// 
			this->btnFile->Location = System::Drawing::Point(229, 58);
			this->btnFile->Name = L"btnFile";
			this->btnFile->Size = System::Drawing::Size(75, 20);
			this->btnFile->TabIndex = 10;
			this->btnFile->Text = L"Arquivo";
			this->btnFile->UseVisualStyleBackColor = true;
			this->btnFile->Click += gcnew System::EventHandler(this, &MyForm::Button1_Click);
			// 
			// openFD
			// 
			this->openFD->RestoreDirectory = true;
			// 
			// btnCreateHeatmap
			// 
			this->btnCreateHeatmap->Location = System::Drawing::Point(554, 327);
			this->btnCreateHeatmap->Name = L"btnCreateHeatmap";
			this->btnCreateHeatmap->Size = System::Drawing::Size(123, 23);
			this->btnCreateHeatmap->TabIndex = 11;
			this->btnCreateHeatmap->Text = L"GerarHeatMap";
			this->btnCreateHeatmap->UseVisualStyleBackColor = true;
			this->btnCreateHeatmap->Click += gcnew System::EventHandler(this, &MyForm::BtnCreateHeatmap_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(10, 59);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(114, 13);
			this->label1->TabIndex = 13;
			this->label1->Text = L"Ignorar primeiras linhas";
			// 
			// upDownIgnore
			// 
			this->upDownIgnore->DecimalPlaces = 2;
			this->upDownIgnore->Location = System::Drawing::Point(134, 58);
			this->upDownIgnore->Name = L"upDownIgnore";
			this->upDownIgnore->Size = System::Drawing::Size(76, 20);
			this->upDownIgnore->TabIndex = 12;
			// 
			// cbHasHeader
			// 
			this->cbHasHeader->AutoSize = true;
			this->cbHasHeader->Checked = true;
			this->cbHasHeader->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cbHasHeader->Location = System::Drawing::Point(13, 28);
			this->cbHasHeader->Name = L"cbHasHeader";
			this->cbHasHeader->Size = System::Drawing::Size(101, 17);
			this->cbHasHeader->TabIndex = 1;
			this->cbHasHeader->Text = L"Tem Cabeçalho";
			this->cbHasHeader->UseVisualStyleBackColor = true;
			// 
			// lblColColor
			// 
			this->lblColColor->AutoSize = true;
			this->lblColColor->Location = System::Drawing::Point(225, 330);
			this->lblColColor->Name = L"lblColColor";
			this->lblColColor->Size = System::Drawing::Size(87, 13);
			this->lblColColor->TabIndex = 15;
			this->lblColColor->Text = L"Coluna HeatMap";
			// 
			// upDownCol
			// 
			this->upDownCol->Location = System::Drawing::Point(318, 328);
			this->upDownCol->Name = L"upDownCol";
			this->upDownCol->Size = System::Drawing::Size(76, 20);
			this->upDownCol->TabIndex = 14;
			// 
			// edtDelim
			// 
			this->edtDelim->Location = System::Drawing::Point(318, 298);
			this->edtDelim->Name = L"edtDelim";
			this->edtDelim->Size = System::Drawing::Size(76, 20);
			this->edtDelim->TabIndex = 16;
			this->edtDelim->Text = L",";
			// 
			// lblDelimiter
			// 
			this->lblDelimiter->AutoSize = true;
			this->lblDelimiter->Location = System::Drawing::Point(253, 302);
			this->lblDelimiter->Name = L"lblDelimiter";
			this->lblDelimiter->Size = System::Drawing::Size(59, 13);
			this->lblDelimiter->TabIndex = 17;
			this->lblDelimiter->Text = L"Delimitador";
			// 
			// pathFolderVideo
			// 
			this->pathFolderVideo->Location = System::Drawing::Point(486, 295);
			this->pathFolderVideo->Name = L"pathFolderVideo";
			this->pathFolderVideo->Size = System::Drawing::Size(191, 20);
			this->pathFolderVideo->TabIndex = 18;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(423, 298);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(57, 13);
			this->label2->TabIndex = 19;
			this->label2->Text = L"Save File :";
			// 
			// memoLogger
			// 
			this->memoLogger->Location = System::Drawing::Point(11, 370);
			this->memoLogger->Name = L"memoLogger";
			this->memoLogger->Size = System::Drawing::Size(677, 154);
			this->memoLogger->TabIndex = 20;
			this->memoLogger->Text = L"";
			// 
			// lblCuSize
			// 
			this->lblCuSize->AutoSize = true;
			this->lblCuSize->Location = System::Drawing::Point(437, 334);
			this->lblCuSize->Name = L"lblCuSize";
			this->lblCuSize->Size = System::Drawing::Size(43, 13);
			this->lblCuSize->TabIndex = 22;
			this->lblCuSize->Text = L"CU size";
			// 
			// upCuSize
			// 
			this->upCuSize->Location = System::Drawing::Point(486, 330);
			this->upCuSize->Name = L"upCuSize";
			this->upCuSize->Size = System::Drawing::Size(51, 20);
			this->upCuSize->TabIndex = 21;
			this->upCuSize->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 64, 0, 0, 0 });
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(691, 526);
			this->Controls->Add(this->lblCuSize);
			this->Controls->Add(this->upCuSize);
			this->Controls->Add(this->memoLogger);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->pathFolderVideo);
			this->Controls->Add(this->lblDelimiter);
			this->Controls->Add(this->edtDelim);
			this->Controls->Add(this->lblColColor);
			this->Controls->Add(this->upDownCol);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->upDownIgnore);
			this->Controls->Add(this->btnCreateHeatmap);
			this->Controls->Add(this->btnFile);
			this->Controls->Add(this->lblMax);
			this->Controls->Add(this->lblMin);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->cbHasHeader);
			this->Controls->Add(this->gridHeader);
			this->Name = L"MyForm";
			this->Text = L"HeatMap";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridHeader))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->upDownIgnore))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->upDownCol))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->upCuSize))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion	
	
private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e) {				
	openFD->Title = "Load File";
	if (openFD->ShowDialog() == System::Windows::Forms::DialogResult::OK){	
		this->Text = "HeatMap - " + openFD->FileName;
		
		string strFileName;		

		strFileName = msclr::interop::marshal_as<std::string>(openFD->FileName);

		ifstream FilePath(strFileName.c_str());
		if (FilePath.is_open()) {
			this->Text = "HeatMap - Open - " + openFD->FileName;

			string line;
			vector <string> lineSplit;

			//Popula cabeçalhos
			for (int i = 0; i < upDownIgnore->Value; i++) {
				getline(FilePath, line);
			}
			string strResult = msclr::interop::marshal_as<std::string>(edtDelim->Text);
			getline(FilePath, line);
			lineSplit = split(line, strResult);

			gridHeader->Columns->Clear();

			System::String^ strWAux;
			for (int i=0; i < int(lineSplit.size()); i++) {
				DataGridViewColumn^ colFullName = gcnew DataGridViewColumn;
				DataGridViewCell^ celFullName = gcnew DataGridViewTextBoxCell;
				colFullName->CellTemplate = celFullName;
				gridHeader->Columns->Add(colFullName);

				if (cbHasHeader->Checked) {
					strWAux = msclr::interop::marshal_as<System::String^>(lineSplit[i]);
					gridHeader->Columns[i]->HeaderText = strWAux;
				}
			}				

			//Popula grid com exemplo do arquivo
			gridHeader->Rows->Clear();
			for (int j = 0; (j < 4) && FilePath.good() ; j++) {
				getline(FilePath, line);
				lineSplit = split(line, ",");
				gridHeader->Rows->Add();
				for (int i = 0; i < int(lineSplit.size()); i++) {
					strWAux = msclr::interop::marshal_as<System::String^>(lineSplit[i]);
					gridHeader->Rows[j]->Cells[i]->Value = strWAux;
				}
			}
		}

		strFileName = msclr::interop::marshal_as<std::string>(openFD->SafeFileName);
		string strPath = msclr::interop::marshal_as<std::string>(openFD->FileName);

		string strDir = strPath.substr(0, strPath.size() - (strFileName.size() + 2));

		pathFolderVideo->Text = msclr::interop::marshal_as<System::String^>(strDir);
	}
}		 	

private: System::Void BtnCreateHeatmap_Click(System::Object^ sender, System::EventArgs^ e) {
	memoLogger->AppendText("Begin\n");

	RunHeatMap();

	memoLogger->AppendText("End\n");
}

private: System::Void GridHeader_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	upDownCol->Value = e->ColumnIndex;
}
		 
void RunHeatMap() {
	string strFileName = msclr::interop::marshal_as<std::string>(openFD->SafeFileName);
	vector <string> lineSplit;
	lineSplit = split(strFileName, ".");
	strFileName = lineSplit[0];

	int nHeader = int(upDownIgnore->Value);
	if (cbHasHeader->Checked)
		nHeader++;

	CreateHeatMap chmMap;
	string strResult = msclr::interop::marshal_as<std::string>(edtDelim->Text);
	chmMap.SetDelim(strResult);
	chmMap.SetCuSize(int(upCuSize->Value));
	chmMap.SetFileOut(strFileName);

	string strFolder = msclr::interop::marshal_as<std::string>(pathFolderVideo->Text);
	strResult = chmMap.SetPath(strFolder);
	memoLogger->AppendText(msclr::interop::marshal_as<System::String^>(strResult + "\n"));

	memoLogger->AppendText("Create HeatMap\n");

	strFileName = msclr::interop::marshal_as<std::string>(openFD->FileName);
	chmMap.LoadHeatMap(strFileName, int(upDownCol->Value), nHeader);
}

vector<string> split(const string& str, const string& delim){
	vector<string> tokens;
	size_t prev = 0, pos = 0;
	do{
		pos = str.find(delim, prev);
		if (pos == string::npos) pos = str.length();
		string token = str.substr(prev, pos - prev);
		if (!token.empty()) tokens.push_back(token);
		prev = pos + delim.length();
	} while (pos < str.length() && prev < str.length());
	return tokens;
}

};

}
