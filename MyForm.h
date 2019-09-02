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
	/// Sum�rio para MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Adicione o c�digo do construtor aqui
			//
		}

	protected:
		/// <summary>
		/// Limpar os recursos que est�o sendo usados.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ gridHeader;
	private: System::Windows::Forms::NumericUpDown^ udValueMin;
	protected:

	protected:











	private: System::Windows::Forms::NumericUpDown^ udValueMax;

	private: System::Windows::Forms::Label^ lblMin;
	private: System::Windows::Forms::Label^ lblMax;
	private: System::Windows::Forms::Button^ btnFile;

	private: System::Windows::Forms::OpenFileDialog^ openFD;
	private: System::Windows::Forms::Button^ btnCreateHeatmap;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::NumericUpDown^ upDownIgnore;

	private: System::Windows::Forms::CheckBox^ cbHasHeader;
	private: System::Windows::Forms::Label^ lblColColor;
	private: System::Windows::Forms::NumericUpDown^ udColHeat;


	private: System::Windows::Forms::TextBox^ edtDelim;

	private: System::Windows::Forms::Label^ lblDelimiter;
	private: System::Windows::Forms::TextBox^ pathFolderVideo;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::RichTextBox^ memoLogger;
	private: System::Windows::Forms::Label^ lblCuSize;
	private: System::Windows::Forms::NumericUpDown^ udCuSize;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Adress;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Height;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Width;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PosX;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PosY;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Slice;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::NumericUpDown^ udHeight;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::NumericUpDown^ udWidth;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::NumericUpDown^ udColPosX;


	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::NumericUpDown^ udColPosY;


	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::NumericUpDown^ udColSlice;







	private:
		/// <summary>
		/// Vari�vel de designer necess�ria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necess�rio para suporte ao Designer - n�o modifique 
		/// o conte�do deste m�todo com o editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->gridHeader = (gcnew System::Windows::Forms::DataGridView());
			this->Adress = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Height = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Width = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PosX = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PosY = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Slice = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->udValueMin = (gcnew System::Windows::Forms::NumericUpDown());
			this->udValueMax = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblMin = (gcnew System::Windows::Forms::Label());
			this->lblMax = (gcnew System::Windows::Forms::Label());
			this->btnFile = (gcnew System::Windows::Forms::Button());
			this->openFD = (gcnew System::Windows::Forms::OpenFileDialog());
			this->btnCreateHeatmap = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->upDownIgnore = (gcnew System::Windows::Forms::NumericUpDown());
			this->cbHasHeader = (gcnew System::Windows::Forms::CheckBox());
			this->lblColColor = (gcnew System::Windows::Forms::Label());
			this->udColHeat = (gcnew System::Windows::Forms::NumericUpDown());
			this->edtDelim = (gcnew System::Windows::Forms::TextBox());
			this->lblDelimiter = (gcnew System::Windows::Forms::Label());
			this->pathFolderVideo = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->memoLogger = (gcnew System::Windows::Forms::RichTextBox());
			this->lblCuSize = (gcnew System::Windows::Forms::Label());
			this->udCuSize = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->udHeight = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->udWidth = (gcnew System::Windows::Forms::NumericUpDown());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->udColPosX = (gcnew System::Windows::Forms::NumericUpDown());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->udColPosY = (gcnew System::Windows::Forms::NumericUpDown());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->udColSlice = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridHeader))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->udValueMin))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->udValueMax))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->upDownIgnore))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->udColHeat))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->udCuSize))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->udHeight))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->udWidth))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->udColPosX))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->udColPosY))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->udColSlice))->BeginInit();
			this->SuspendLayout();
			// 
			// gridHeader
			// 
			this->gridHeader->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->gridHeader->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->Adress, this->Height,
					this->Width, this->PosX, this->PosY, this->Slice
			});
			this->gridHeader->Location = System::Drawing::Point(11, 54);
			this->gridHeader->Name = L"gridHeader";
			this->gridHeader->Size = System::Drawing::Size(677, 225);
			this->gridHeader->TabIndex = 0;
			this->gridHeader->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::GridHeader_CellClick);
			// 
			// Adress
			// 
			this->Adress->HeaderText = L"Adress";
			this->Adress->Name = L"Adress";
			// 
			// Height
			// 
			this->Height->HeaderText = L"Height";
			this->Height->Name = L"Height";
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
			// udValueMin
			// 
			this->udValueMin->DecimalPlaces = 2;
			this->udValueMin->Location = System::Drawing::Point(140, 295);
			this->udValueMin->Name = L"udValueMin";
			this->udValueMin->Size = System::Drawing::Size(76, 20);
			this->udValueMin->TabIndex = 6;
			// 
			// udValueMax
			// 
			this->udValueMax->DecimalPlaces = 2;
			this->udValueMax->Location = System::Drawing::Point(140, 321);
			this->udValueMax->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->udValueMax->Name = L"udValueMax";
			this->udValueMax->Size = System::Drawing::Size(76, 20);
			this->udValueMax->TabIndex = 7;
			this->udValueMax->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			// 
			// lblMin
			// 
			this->lblMin->AutoSize = true;
			this->lblMin->Location = System::Drawing::Point(83, 297);
			this->lblMin->Name = L"lblMin";
			this->lblMin->Size = System::Drawing::Size(51, 13);
			this->lblMin->TabIndex = 8;
			this->lblMin->Text = L"Valor Min";
			// 
			// lblMax
			// 
			this->lblMax->AutoSize = true;
			this->lblMax->Location = System::Drawing::Point(75, 323);
			this->lblMax->Name = L"lblMax";
			this->lblMax->Size = System::Drawing::Size(54, 13);
			this->lblMax->TabIndex = 9;
			this->lblMax->Text = L"Valor Max";
			// 
			// btnFile
			// 
			this->btnFile->Location = System::Drawing::Point(361, 28);
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
			this->btnCreateHeatmap->Location = System::Drawing::Point(478, 374);
			this->btnCreateHeatmap->Name = L"btnCreateHeatmap";
			this->btnCreateHeatmap->Size = System::Drawing::Size(119, 23);
			this->btnCreateHeatmap->TabIndex = 11;
			this->btnCreateHeatmap->Text = L"GerarHeatMap";
			this->btnCreateHeatmap->UseVisualStyleBackColor = true;
			this->btnCreateHeatmap->Click += gcnew System::EventHandler(this, &MyForm::BtnCreateHeatmap_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(142, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(114, 13);
			this->label1->TabIndex = 13;
			this->label1->Text = L"Ignorar primeiras linhas";
			// 
			// upDownIgnore
			// 
			this->upDownIgnore->Location = System::Drawing::Point(266, 28);
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
			this->cbHasHeader->Text = L"Tem Cabe�alho";
			this->cbHasHeader->UseVisualStyleBackColor = true;
			// 
			// lblColColor
			// 
			this->lblColColor->AutoSize = true;
			this->lblColColor->Location = System::Drawing::Point(475, 324);
			this->lblColColor->Name = L"lblColColor";
			this->lblColColor->Size = System::Drawing::Size(69, 13);
			this->lblColColor->TabIndex = 15;
			this->lblColColor->Text = L"Col HeatMap";
			// 
			// udColHeat
			// 
			this->udColHeat->Location = System::Drawing::Point(550, 320);
			this->udColHeat->Name = L"udColHeat";
			this->udColHeat->Size = System::Drawing::Size(47, 20);
			this->udColHeat->TabIndex = 14;
			this->udColHeat->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 8, 0, 0, 0 });
			// 
			// edtDelim
			// 
			this->edtDelim->Location = System::Drawing::Point(140, 347);
			this->edtDelim->Name = L"edtDelim";
			this->edtDelim->Size = System::Drawing::Size(76, 20);
			this->edtDelim->TabIndex = 16;
			this->edtDelim->Text = L",";
			// 
			// lblDelimiter
			// 
			this->lblDelimiter->AutoSize = true;
			this->lblDelimiter->Location = System::Drawing::Point(75, 351);
			this->lblDelimiter->Name = L"lblDelimiter";
			this->lblDelimiter->Size = System::Drawing::Size(59, 13);
			this->lblDelimiter->TabIndex = 17;
			this->lblDelimiter->Text = L"Delimitador";
			// 
			// pathFolderVideo
			// 
			this->pathFolderVideo->Location = System::Drawing::Point(140, 377);
			this->pathFolderVideo->Name = L"pathFolderVideo";
			this->pathFolderVideo->Size = System::Drawing::Size(321, 20);
			this->pathFolderVideo->TabIndex = 18;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(77, 380);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(57, 13);
			this->label2->TabIndex = 19;
			this->label2->Text = L"Save File :";
			// 
			// memoLogger
			// 
			this->memoLogger->Location = System::Drawing::Point(11, 413);
			this->memoLogger->Name = L"memoLogger";
			this->memoLogger->Size = System::Drawing::Size(677, 128);
			this->memoLogger->TabIndex = 20;
			this->memoLogger->Text = L"";
			// 
			// lblCuSize
			// 
			this->lblCuSize->AutoSize = true;
			this->lblCuSize->Location = System::Drawing::Point(238, 298);
			this->lblCuSize->Name = L"lblCuSize";
			this->lblCuSize->Size = System::Drawing::Size(43, 13);
			this->lblCuSize->TabIndex = 22;
			this->lblCuSize->Text = L"CU size";
			// 
			// udCuSize
			// 
			this->udCuSize->Location = System::Drawing::Point(287, 294);
			this->udCuSize->Name = L"udCuSize";
			this->udCuSize->Size = System::Drawing::Size(51, 20);
			this->udCuSize->TabIndex = 21;
			this->udCuSize->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 64, 0, 0, 0 });
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(243, 325);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(38, 13);
			this->label3->TabIndex = 24;
			this->label3->Text = L"Height";
			// 
			// udHeight
			// 
			this->udHeight->Location = System::Drawing::Point(287, 323);
			this->udHeight->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->udHeight->Name = L"udHeight";
			this->udHeight->Size = System::Drawing::Size(51, 20);
			this->udHeight->TabIndex = 23;
			this->udHeight->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 720, 0, 0, 0 });
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(251, 353);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(35, 13);
			this->label4->TabIndex = 26;
			this->label4->Text = L"Width";
			// 
			// udWidth
			// 
			this->udWidth->Location = System::Drawing::Point(287, 351);
			this->udWidth->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->udWidth->Name = L"udWidth";
			this->udWidth->Size = System::Drawing::Size(51, 20);
			this->udWidth->TabIndex = 25;
			this->udWidth->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1280, 0, 0, 0 });
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(358, 298);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(50, 13);
			this->label5->TabIndex = 28;
			this->label5->Text = L"Col PosX";
			// 
			// udColPosX
			// 
			this->udColPosX->Location = System::Drawing::Point(414, 294);
			this->udColPosX->Name = L"udColPosX";
			this->udColPosX->Size = System::Drawing::Size(47, 20);
			this->udColPosX->TabIndex = 27;
			this->udColPosX->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(358, 324);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(50, 13);
			this->label6->TabIndex = 30;
			this->label6->Text = L"Col PosY";
			// 
			// udColPosY
			// 
			this->udColPosY->Location = System::Drawing::Point(414, 320);
			this->udColPosY->Name = L"udColPosY";
			this->udColPosY->Size = System::Drawing::Size(47, 20);
			this->udColPosY->TabIndex = 29;
			this->udColPosY->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 0 });
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(496, 298);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(48, 13);
			this->label7->TabIndex = 32;
			this->label7->Text = L"Col Slice";
			// 
			// udColSlice
			// 
			this->udColSlice->Location = System::Drawing::Point(550, 296);
			this->udColSlice->Name = L"udColSlice";
			this->udColSlice->Size = System::Drawing::Size(47, 20);
			this->udColSlice->TabIndex = 31;
			this->udColSlice->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 6, 0, 0, 0 });
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(701, 566);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->udColSlice);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->udColPosY);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->udColPosX);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->udWidth);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->udHeight);
			this->Controls->Add(this->lblCuSize);
			this->Controls->Add(this->udCuSize);
			this->Controls->Add(this->memoLogger);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->pathFolderVideo);
			this->Controls->Add(this->lblDelimiter);
			this->Controls->Add(this->edtDelim);
			this->Controls->Add(this->lblColColor);
			this->Controls->Add(this->udColHeat);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->upDownIgnore);
			this->Controls->Add(this->btnCreateHeatmap);
			this->Controls->Add(this->btnFile);
			this->Controls->Add(this->lblMax);
			this->Controls->Add(this->lblMin);
			this->Controls->Add(this->udValueMax);
			this->Controls->Add(this->udValueMin);
			this->Controls->Add(this->cbHasHeader);
			this->Controls->Add(this->gridHeader);
			this->Name = L"MyForm";
			this->Text = L"HeatMap";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridHeader))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->udValueMin))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->udValueMax))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->upDownIgnore))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->udColHeat))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->udCuSize))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->udHeight))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->udWidth))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->udColPosX))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->udColPosY))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->udColSlice))->EndInit();
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

			//Popula cabe�alhos
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
	udColHeat->Value = e->ColumnIndex;
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
	chmMap.ColPosX  = int(udColPosX->Value);
	chmMap.ColPosY  = int(udColPosY->Value);
	chmMap.ColSlice = int(udColSlice->Value);
	chmMap.Widht    = int(udWidth->Value);
	chmMap.Heigth   = int(udHeight->Value); 
	chmMap.CUSize   = int(udCuSize->Value);

	chmMap.SetDelim(msclr::interop::marshal_as<std::string>(edtDelim->Text));	
	chmMap.SetFileOut(strFileName);

	string strResult = chmMap.SetPath(msclr::interop::marshal_as<std::string>(pathFolderVideo->Text));

	memoLogger->AppendText(msclr::interop::marshal_as<System::String^>(strResult + "\n"));

	memoLogger->AppendText("Create HeatMap\n");

	//Create YUV HeatMap
	strFileName = msclr::interop::marshal_as<std::string>(openFD->FileName);
	chmMap.LoadHeatMap(strFileName, int(udColHeat->Value), nHeader);
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
