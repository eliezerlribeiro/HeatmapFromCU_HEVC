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



	private: System::Windows::Forms::NumericUpDown^ udColPosY;


	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::NumericUpDown^ udColSlice;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ edtArqMescUm;
	private: System::Windows::Forms::TextBox^ edtArqMescDois;


	private: System::Windows::Forms::Button^ btnDissolve;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label6;








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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
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
			this->udColPosY = (gcnew System::Windows::Forms::NumericUpDown());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->udColSlice = (gcnew System::Windows::Forms::NumericUpDown());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->edtArqMescUm = (gcnew System::Windows::Forms::TextBox());
			this->edtArqMescDois = (gcnew System::Windows::Forms::TextBox());
			this->btnDissolve = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
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
			this->gridHeader->Size = System::Drawing::Size(713, 158);
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
			this->udValueMin->Location = System::Drawing::Point(79, 348);
			this->udValueMin->Name = L"udValueMin";
			this->udValueMin->Size = System::Drawing::Size(76, 20);
			this->udValueMin->TabIndex = 6;
			// 
			// udValueMax
			// 
			this->udValueMax->DecimalPlaces = 2;
			this->udValueMax->Location = System::Drawing::Point(218, 350);
			this->udValueMax->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->udValueMax->Name = L"udValueMax";
			this->udValueMax->Size = System::Drawing::Size(76, 20);
			this->udValueMax->TabIndex = 7;
			this->udValueMax->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			// 
			// lblMin
			// 
			this->lblMin->AutoSize = true;
			this->lblMin->Location = System::Drawing::Point(31, 350);
			this->lblMin->Name = L"lblMin";
			this->lblMin->Size = System::Drawing::Size(42, 13);
			this->lblMin->TabIndex = 8;
			this->lblMin->Text = L"Min�mo";
			// 
			// lblMax
			// 
			this->lblMax->AutoSize = true;
			this->lblMax->Location = System::Drawing::Point(171, 350);
			this->lblMax->Name = L"lblMax";
			this->lblMax->Size = System::Drawing::Size(46, 13);
			this->lblMax->TabIndex = 9;
			this->lblMax->Text = L"M�ximo:";
			// 
			// btnFile
			// 
			this->btnFile->Location = System::Drawing::Point(421, 28);
			this->btnFile->Name = L"btnFile";
			this->btnFile->Size = System::Drawing::Size(125, 20);
			this->btnFile->TabIndex = 10;
			this->btnFile->Text = L"Selecionar arquivo ...";
			this->btnFile->UseVisualStyleBackColor = true;
			this->btnFile->Click += gcnew System::EventHandler(this, &MyForm::Button1_Click);
			// 
			// openFD
			// 
			this->openFD->RestoreDirectory = true;
			// 
			// btnCreateHeatmap
			// 
			this->btnCreateHeatmap->Location = System::Drawing::Point(387, 402);
			this->btnCreateHeatmap->Name = L"btnCreateHeatmap";
			this->btnCreateHeatmap->Size = System::Drawing::Size(57, 23);
			this->btnCreateHeatmap->TabIndex = 11;
			this->btnCreateHeatmap->Text = L"Iniciar";
			this->btnCreateHeatmap->UseVisualStyleBackColor = true;
			this->btnCreateHeatmap->Click += gcnew System::EventHandler(this, &MyForm::BtnCreateHeatmap_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(127, 31);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(114, 13);
			this->label1->TabIndex = 13;
			this->label1->Text = L"Ignorar primeiras linhas";
			// 
			// upDownIgnore
			// 
			this->upDownIgnore->Location = System::Drawing::Point(252, 24);
			this->upDownIgnore->Name = L"upDownIgnore";
			this->upDownIgnore->Size = System::Drawing::Size(49, 20);
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
			this->lblColColor->Location = System::Drawing::Point(307, 250);
			this->lblColColor->Name = L"lblColColor";
			this->lblColColor->Size = System::Drawing::Size(84, 13);
			this->lblColColor->TabIndex = 15;
			this->lblColColor->Text = L"Atributo de calor";
			// 
			// udColHeat
			// 
			this->udColHeat->Location = System::Drawing::Point(397, 248);
			this->udColHeat->Name = L"udColHeat";
			this->udColHeat->Size = System::Drawing::Size(47, 20);
			this->udColHeat->TabIndex = 14;
			this->udColHeat->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 8, 0, 0, 0 });
			// 
			// edtDelim
			// 
			this->edtDelim->Location = System::Drawing::Point(372, 28);
			this->edtDelim->Name = L"edtDelim";
			this->edtDelim->Size = System::Drawing::Size(43, 20);
			this->edtDelim->TabIndex = 16;
			this->edtDelim->Text = L",";
			// 
			// lblDelimiter
			// 
			this->lblDelimiter->AutoSize = true;
			this->lblDelimiter->Location = System::Drawing::Point(307, 31);
			this->lblDelimiter->Name = L"lblDelimiter";
			this->lblDelimiter->Size = System::Drawing::Size(59, 13);
			this->lblDelimiter->TabIndex = 17;
			this->lblDelimiter->Text = L"Delimitador";
			// 
			// pathFolderVideo
			// 
			this->pathFolderVideo->Location = System::Drawing::Point(25, 405);
			this->pathFolderVideo->Name = L"pathFolderVideo";
			this->pathFolderVideo->Size = System::Drawing::Size(353, 20);
			this->pathFolderVideo->TabIndex = 18;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 382);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(233, 13);
			this->label2->TabIndex = 19;
			this->label2->Text = L"Local da pasta a ser salvo o MAPA DE CALOR:";
			// 
			// memoLogger
			// 
			this->memoLogger->Location = System::Drawing::Point(11, 455);
			this->memoLogger->Name = L"memoLogger";
			this->memoLogger->Size = System::Drawing::Size(677, 99);
			this->memoLogger->TabIndex = 20;
			this->memoLogger->Text = L"";
			// 
			// lblCuSize
			// 
			this->lblCuSize->AutoSize = true;
			this->lblCuSize->Location = System::Drawing::Point(31, 298);
			this->lblCuSize->Name = L"lblCuSize";
			this->lblCuSize->Size = System::Drawing::Size(73, 13);
			this->lblCuSize->TabIndex = 22;
			this->lblCuSize->Text = L"Tamanho CU:";
			// 
			// udCuSize
			// 
			this->udCuSize->Location = System::Drawing::Point(110, 293);
			this->udCuSize->Name = L"udCuSize";
			this->udCuSize->Size = System::Drawing::Size(51, 20);
			this->udCuSize->TabIndex = 21;
			this->udCuSize->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 64, 0, 0, 0 });
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(171, 298);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(34, 13);
			this->label3->TabIndex = 24;
			this->label3->Text = L"Altura";
			// 
			// udHeight
			// 
			this->udHeight->Location = System::Drawing::Point(211, 296);
			this->udHeight->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->udHeight->Name = L"udHeight";
			this->udHeight->Size = System::Drawing::Size(51, 20);
			this->udHeight->TabIndex = 23;
			this->udHeight->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 720, 0, 0, 0 });
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(275, 298);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(46, 13);
			this->label4->TabIndex = 26;
			this->label4->Text = L"Largura:";
			// 
			// udWidth
			// 
			this->udWidth->Location = System::Drawing::Point(327, 298);
			this->udWidth->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->udWidth->Name = L"udWidth";
			this->udWidth->Size = System::Drawing::Size(51, 20);
			this->udWidth->TabIndex = 25;
			this->udWidth->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1280, 0, 0, 0 });
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(127, 252);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(71, 13);
			this->label5->TabIndex = 28;
			this->label5->Text = L"Posi��o X - Y";
			// 
			// udColPosX
			// 
			this->udColPosX->Location = System::Drawing::Point(201, 248);
			this->udColPosX->Name = L"udColPosX";
			this->udColPosX->Size = System::Drawing::Size(47, 20);
			this->udColPosX->TabIndex = 27;
			this->udColPosX->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			// 
			// udColPosY
			// 
			this->udColPosY->Location = System::Drawing::Point(254, 248);
			this->udColPosY->Name = L"udColPosY";
			this->udColPosY->Size = System::Drawing::Size(47, 20);
			this->udColPosY->TabIndex = 29;
			this->udColPosY->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 0 });
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(31, 251);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(30, 13);
			this->label7->TabIndex = 32;
			this->label7->Text = L"Slice";
			// 
			// udColSlice
			// 
			this->udColSlice->Location = System::Drawing::Point(67, 248);
			this->udColSlice->Name = L"udColSlice";
			this->udColSlice->Size = System::Drawing::Size(47, 20);
			this->udColSlice->TabIndex = 31;
			this->udColSlice->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 6, 0, 0, 0 });
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(496, 225);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(208, 13);
			this->label8->TabIndex = 34;
			this->label8->Text = L"Mesclar video original com mapa de calor :";
			// 
			// edtArqMescUm
			// 
			this->edtArqMescUm->Location = System::Drawing::Point(527, 249);
			this->edtArqMescUm->Name = L"edtArqMescUm";
			this->edtArqMescUm->Size = System::Drawing::Size(151, 20);
			this->edtArqMescUm->TabIndex = 33;
			// 
			// edtArqMescDois
			// 
			this->edtArqMescDois->Location = System::Drawing::Point(527, 275);
			this->edtArqMescDois->Name = L"edtArqMescDois";
			this->edtArqMescDois->Size = System::Drawing::Size(153, 20);
			this->edtArqMescDois->TabIndex = 35;
			// 
			// btnDissolve
			// 
			this->btnDissolve->Location = System::Drawing::Point(527, 301);
			this->btnDissolve->Name = L"btnDissolve";
			this->btnDissolve->Size = System::Drawing::Size(177, 23);
			this->btnDissolve->TabIndex = 36;
			this->btnDissolve->Text = L"Mesclar";
			this->btnDissolve->UseVisualStyleBackColor = true;
			this->btnDissolve->Click += gcnew System::EventHandler(this, &MyForm::Button1_Click_1);
			// 
			// button1
			// 
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->Location = System::Drawing::Point(681, 249);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(20, 20);
			this->button1->TabIndex = 37;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::Button1_Click_2);
			// 
			// button2
			// 
			this->button2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.Image")));
			this->button2->Location = System::Drawing::Point(681, 275);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(20, 20);
			this->button2->TabIndex = 38;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::Button2_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(12, 225);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(260, 13);
			this->label9->TabIndex = 39;
			this->label9->Text = L"Posicionamento dos atributos  presentes nas colunas:";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(12, 280);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(98, 13);
			this->label10->TabIndex = 40;
			this->label10->Text = L"Atributos do Frame:";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(12, 328);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(303, 13);
			this->label11->TabIndex = 41;
			this->label11->Text = L"Normaliza��o : (Definir valor minimo e maximo do atributo calor)";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(10, 439);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(88, 13);
			this->label6->TabIndex = 42;
			this->label6->Text = L"Lista de eventos:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(736, 566);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->btnDissolve);
			this->Controls->Add(this->edtArqMescDois);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->edtArqMescUm);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->udColSlice);
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
	chmMap.Width = int(udWidth->Value);
	chmMap.Height = int(udHeight->Value);
	chmMap.CUSize   = int(udCuSize->Value);		

	chmMap.SetDelim(msclr::interop::marshal_as<std::string>(edtDelim->Text));	
	chmMap.SetFileOut(strFileName);

	string strResult = chmMap.SetPath(msclr::interop::marshal_as<std::string>(pathFolderVideo->Text));

	memoLogger->AppendText(msclr::interop::marshal_as<System::String^>(strResult + "\n"));

	memoLogger->AppendText("Create HeatMap\n");

	//Create YUV HeatMap
	strFileName = msclr::interop::marshal_as<std::string>(openFD->FileName);	

	chmMap.LoadHeatMap(strFileName, int(udColHeat->Value), int(udValueMin->Value), int(udValueMax->Value), nHeader);
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

private: System::Void Button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	BlendTwoVideos videoOut;
	videoOut.Width = int(udWidth->Value);
	videoOut.Height = int(udHeight->Value);

	string strVideoUm    = msclr::interop::marshal_as<std::string>(edtArqMescUm->Text);
	string strVideoDois  = msclr::interop::marshal_as<std::string>(edtArqMescDois->Text);
	string strPathFolder = msclr::interop::marshal_as<std::string>(pathFolderVideo->Text);
	
	videoOut.StartBlend(strPathFolder, strVideoUm, strVideoDois);

}
private: System::Void Button1_Click_2(System::Object^ sender, System::EventArgs^ e) {
	openFD->Title = "Encontrar arquivo para mesclar";

	if (openFD->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		edtArqMescUm->Text = openFD->FileName;
	}
}

private: System::Void Button2_Click(System::Object^ sender, System::EventArgs^ e) {
	openFD->Title = "Encontrar arquivo para mesclar";

	if (openFD->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		edtArqMescDois->Text = openFD->FileName;
	}
}
};

}
