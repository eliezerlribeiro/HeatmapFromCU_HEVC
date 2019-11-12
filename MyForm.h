#include <msclr\marshal_cppstd.h>

#include "CreateHeatMap.cpp"

#include <string>
#include <tchar.h>
#include <fstream>
#include <string.h>
#include <vector>

#pragma once

namespace HeatMapForm {
	string strFileName, strDirName, strPathFileName;
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


	private: System::Windows::Forms::Label^ lblColColor;
	private: System::Windows::Forms::NumericUpDown^ udColHeat;


	private: System::Windows::Forms::TextBox^ edtDelim;

	private: System::Windows::Forms::Label^ lblDelimiter;
	private: System::Windows::Forms::TextBox^ pathFolderVideo;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::RichTextBox^ memoLogger;









	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::NumericUpDown^ udHeight;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::NumericUpDown^ udWidth;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::NumericUpDown^ udColPosX;



	private: System::Windows::Forms::NumericUpDown^ udColPosY;


	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::NumericUpDown^ udColFrame;

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
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Adress;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Height;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Width;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PosX;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PosY;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Slice;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Depth;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::NumericUpDown^ udColDepth;












	private:
		/// <summary>
		/// Variável de designer necessária.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necessário para suporte ao Designer - não modifique 
		/// o conteúdo deste método com o editor de código.
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
			this->Depth = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->udValueMin = (gcnew System::Windows::Forms::NumericUpDown());
			this->udValueMax = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblMin = (gcnew System::Windows::Forms::Label());
			this->lblMax = (gcnew System::Windows::Forms::Label());
			this->btnFile = (gcnew System::Windows::Forms::Button());
			this->openFD = (gcnew System::Windows::Forms::OpenFileDialog());
			this->btnCreateHeatmap = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->upDownIgnore = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblColColor = (gcnew System::Windows::Forms::Label());
			this->udColHeat = (gcnew System::Windows::Forms::NumericUpDown());
			this->edtDelim = (gcnew System::Windows::Forms::TextBox());
			this->lblDelimiter = (gcnew System::Windows::Forms::Label());
			this->pathFolderVideo = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->memoLogger = (gcnew System::Windows::Forms::RichTextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->udHeight = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->udWidth = (gcnew System::Windows::Forms::NumericUpDown());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->udColPosX = (gcnew System::Windows::Forms::NumericUpDown());
			this->udColPosY = (gcnew System::Windows::Forms::NumericUpDown());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->udColFrame = (gcnew System::Windows::Forms::NumericUpDown());
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
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->udColDepth = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridHeader))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->udValueMin))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->udValueMax))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->upDownIgnore))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->udColHeat))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->udHeight))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->udWidth))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->udColPosX))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->udColPosY))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->udColFrame))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->udColDepth))->BeginInit();
			this->SuspendLayout();
			// 
			// gridHeader
			// 
			this->gridHeader->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->gridHeader->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->Adress, this->Height,
					this->Width, this->PosX, this->PosY, this->Slice, this->Depth
			});
			this->gridHeader->Location = System::Drawing::Point(9, 44);
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
			// Depth
			// 
			this->Depth->HeaderText = L"Depth";
			this->Depth->Name = L"Depth";
			// 
			// udValueMin
			// 
			this->udValueMin->DecimalPlaces = 2;
			this->udValueMin->Location = System::Drawing::Point(67, 368);
			this->udValueMin->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->udValueMin->Name = L"udValueMin";
			this->udValueMin->Size = System::Drawing::Size(76, 20);
			this->udValueMin->TabIndex = 6;
			// 
			// udValueMax
			// 
			this->udValueMax->DecimalPlaces = 2;
			this->udValueMax->Location = System::Drawing::Point(211, 368);
			this->udValueMax->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->udValueMax->Name = L"udValueMax";
			this->udValueMax->Size = System::Drawing::Size(76, 20);
			this->udValueMax->TabIndex = 7;
			this->udValueMax->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 0 });
			// 
			// lblMin
			// 
			this->lblMin->AutoSize = true;
			this->lblMin->Location = System::Drawing::Point(19, 370);
			this->lblMin->Name = L"lblMin";
			this->lblMin->Size = System::Drawing::Size(42, 13);
			this->lblMin->TabIndex = 8;
			this->lblMin->Text = L"Minímo";
			// 
			// lblMax
			// 
			this->lblMax->AutoSize = true;
			this->lblMax->Location = System::Drawing::Point(159, 370);
			this->lblMax->Name = L"lblMax";
			this->lblMax->Size = System::Drawing::Size(46, 13);
			this->lblMax->TabIndex = 9;
			this->lblMax->Text = L"Máximo:";
			// 
			// btnFile
			// 
			this->btnFile->Location = System::Drawing::Point(385, 12);
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
			this->btnCreateHeatmap->Location = System::Drawing::Point(385, 414);
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
			this->label1->Location = System::Drawing::Point(8, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(178, 13);
			this->label1->TabIndex = 13;
			this->label1->Text = L"Ignorar primeiras linhas (cabeçalhos)";
			// 
			// upDownIgnore
			// 
			this->upDownIgnore->Location = System::Drawing::Point(189, 14);
			this->upDownIgnore->Name = L"upDownIgnore";
			this->upDownIgnore->Size = System::Drawing::Size(49, 20);
			this->upDownIgnore->TabIndex = 12;
			this->upDownIgnore->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// lblColColor
			// 
			this->lblColColor->AutoSize = true;
			this->lblColColor->Location = System::Drawing::Point(172, 268);
			this->lblColColor->Name = L"lblColColor";
			this->lblColColor->Size = System::Drawing::Size(84, 13);
			this->lblColColor->TabIndex = 15;
			this->lblColColor->Text = L"Atributo de calor";
			// 
			// udColHeat
			// 
			this->udColHeat->Location = System::Drawing::Point(262, 266);
			this->udColHeat->Name = L"udColHeat";
			this->udColHeat->Size = System::Drawing::Size(47, 20);
			this->udColHeat->TabIndex = 14;
			this->udColHeat->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 7, 0, 0, 0 });
			// 
			// edtDelim
			// 
			this->edtDelim->Location = System::Drawing::Point(336, 13);
			this->edtDelim->Name = L"edtDelim";
			this->edtDelim->Size = System::Drawing::Size(43, 20);
			this->edtDelim->TabIndex = 16;
			this->edtDelim->Text = L",";
			// 
			// lblDelimiter
			// 
			this->lblDelimiter->AutoSize = true;
			this->lblDelimiter->Location = System::Drawing::Point(271, 16);
			this->lblDelimiter->Name = L"lblDelimiter";
			this->lblDelimiter->Size = System::Drawing::Size(59, 13);
			this->lblDelimiter->TabIndex = 17;
			this->lblDelimiter->Text = L"Delimitador";
			// 
			// pathFolderVideo
			// 
			this->pathFolderVideo->Location = System::Drawing::Point(23, 417);
			this->pathFolderVideo->Name = L"pathFolderVideo";
			this->pathFolderVideo->Size = System::Drawing::Size(353, 20);
			this->pathFolderVideo->TabIndex = 18;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(10, 394);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(233, 13);
			this->label2->TabIndex = 19;
			this->label2->Text = L"Local da pasta a ser salvo o MAPA DE CALOR:";
			// 
			// memoLogger
			// 
			this->memoLogger->Location = System::Drawing::Point(9, 459);
			this->memoLogger->Name = L"memoLogger";
			this->memoLogger->Size = System::Drawing::Size(713, 99);
			this->memoLogger->TabIndex = 20;
			this->memoLogger->Text = L"";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(19, 321);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(34, 13);
			this->label3->TabIndex = 24;
			this->label3->Text = L"Altura";
			// 
			// udHeight
			// 
			this->udHeight->Location = System::Drawing::Point(59, 319);
			this->udHeight->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->udHeight->Name = L"udHeight";
			this->udHeight->Size = System::Drawing::Size(51, 20);
			this->udHeight->TabIndex = 23;
			this->udHeight->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 720, 0, 0, 0 });
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(123, 321);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(46, 13);
			this->label4->TabIndex = 26;
			this->label4->Text = L"Largura:";
			// 
			// udWidth
			// 
			this->udWidth->Location = System::Drawing::Point(175, 319);
			this->udWidth->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->udWidth->Name = L"udWidth";
			this->udWidth->Size = System::Drawing::Size(51, 20);
			this->udWidth->TabIndex = 25;
			this->udWidth->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1280, 0, 0, 0 });
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(125, 242);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(58, 13);
			this->label5->TabIndex = 28;
			this->label5->Text = L"Posição: X";
			// 
			// udColPosX
			// 
			this->udColPosX->Location = System::Drawing::Point(189, 238);
			this->udColPosX->Name = L"udColPosX";
			this->udColPosX->Size = System::Drawing::Size(47, 20);
			this->udColPosX->TabIndex = 27;
			this->udColPosX->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			// 
			// udColPosY
			// 
			this->udColPosY->Location = System::Drawing::Point(262, 240);
			this->udColPosY->Name = L"udColPosY";
			this->udColPosY->Size = System::Drawing::Size(47, 20);
			this->udColPosY->TabIndex = 29;
			this->udColPosY->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 0 });
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(17, 242);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(42, 13);
			this->label7->TabIndex = 32;
			this->label7->Text = L"Quadro";
			// 
			// udColFrame
			// 
			this->udColFrame->Location = System::Drawing::Point(65, 238);
			this->udColFrame->Name = L"udColFrame";
			this->udColFrame->Size = System::Drawing::Size(47, 20);
			this->udColFrame->TabIndex = 31;
			this->udColFrame->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(494, 215);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(208, 13);
			this->label8->TabIndex = 34;
			this->label8->Text = L"Mesclar video original com mapa de calor :";
			// 
			// edtArqMescUm
			// 
			this->edtArqMescUm->Location = System::Drawing::Point(525, 239);
			this->edtArqMescUm->Name = L"edtArqMescUm";
			this->edtArqMescUm->Size = System::Drawing::Size(151, 20);
			this->edtArqMescUm->TabIndex = 33;
			// 
			// edtArqMescDois
			// 
			this->edtArqMescDois->Location = System::Drawing::Point(525, 265);
			this->edtArqMescDois->Name = L"edtArqMescDois";
			this->edtArqMescDois->Size = System::Drawing::Size(153, 20);
			this->edtArqMescDois->TabIndex = 35;
			// 
			// btnDissolve
			// 
			this->btnDissolve->Location = System::Drawing::Point(525, 291);
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
			this->button1->Location = System::Drawing::Point(679, 239);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(20, 20);
			this->button1->TabIndex = 37;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::Button1_Click_2);
			// 
			// button2
			// 
			this->button2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.Image")));
			this->button2->Location = System::Drawing::Point(679, 265);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(20, 20);
			this->button2->TabIndex = 38;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::Button2_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(10, 215);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(169, 13);
			this->label9->TabIndex = 39;
			this->label9->Text = L"Coluna representada pelo atributo:";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(10, 296);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(98, 13);
			this->label10->TabIndex = 40;
			this->label10->Text = L"Atributos do Frame:";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(10, 349);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(303, 13);
			this->label11->TabIndex = 41;
			this->label11->Text = L"Normalização : (Definir valor minimo e maximo do atributo calor)";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(8, 443);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(88, 13);
			this->label6->TabIndex = 42;
			this->label6->Text = L"Lista de eventos:";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(242, 242);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(14, 13);
			this->label12->TabIndex = 43;
			this->label12->Text = L"Y";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(12, 266);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(47, 13);
			this->label13->TabIndex = 45;
			this->label13->Text = L"Profund.";
			// 
			// udColDepth
			// 
			this->udColDepth->Location = System::Drawing::Point(65, 264);
			this->udColDepth->Name = L"udColDepth";
			this->udColDepth->Size = System::Drawing::Size(47, 20);
			this->udColDepth->TabIndex = 44;
			this->udColDepth->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 7, 0, 0, 0 });
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(736, 596);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->udColDepth);
			this->Controls->Add(this->label12);
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
			this->Controls->Add(this->udColFrame);
			this->Controls->Add(this->udColPosY);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->udColPosX);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->udWidth);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->udHeight);
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
			this->Controls->Add(this->gridHeader);
			this->Name = L"MyForm";
			this->Text = L"HeatMap";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridHeader))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->udValueMin))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->udValueMax))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->upDownIgnore))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->udColHeat))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->udHeight))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->udWidth))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->udColPosX))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->udColPosY))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->udColFrame))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->udColDepth))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion	

	private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e) {
		openFD->Title = "Load File";

		if (openFD->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			this->Text = "HeatMap - " + openFD->FileName;

			strPathFileName = msclr::interop::marshal_as<std::string>(openFD->FileName);

			ifstream FilePath(strPathFileName.c_str());
			if (FilePath.is_open()) {
				this->Text = "HeatMap - Open - " + openFD->FileName;

				string line;
				//Popula cabeçalhos
				for (int i = 0; i < upDownIgnore->Value ; i++) {
					getline(FilePath, line);
				}

				if (upDownIgnore->Value < 1) {
					getline(FilePath, line);
				}

				vector <string> lineSplit;
				string strResult = msclr::interop::marshal_as<std::string>(edtDelim->Text);				
				lineSplit = split(line, strResult);

				gridHeader->Columns->Clear();

				System::String^ strWAux;
				for (int i = 0; i < int(lineSplit.size()); i++) {
					DataGridViewColumn^ colFullName = gcnew DataGridViewColumn;
					DataGridViewCell^ celFullName = gcnew DataGridViewTextBoxCell;
					colFullName->CellTemplate = celFullName;
					gridHeader->Columns->Add(colFullName);
					
					//Cabeçalho na grid
					strWAux = msclr::interop::marshal_as<System::String^>(lineSplit[i]);
					gridHeader->Columns[i]->HeaderText = strWAux;
				}

				//Popula grid com exemplo do arquivo
				gridHeader->Rows->Clear();
				for (int j = 0; (j < 4) && FilePath.good(); j++) {
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
			strDirName = strPathFileName.substr(0, strPathFileName.size() - (strFileName.size() + 1));

			pathFolderVideo->Text = msclr::interop::marshal_as<System::String^>(strDirName);
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
		vector <string> lineSplit;
		lineSplit = split(strFileName, ".");

		int nHeader = int(upDownIgnore->Value);

		CreateHeatMap chmMap;
		chmMap.ColPosX  = int(udColPosX->Value);
		chmMap.ColPosY  = int(udColPosY->Value);
		chmMap.ColFrame = int(udColFrame->Value);
		chmMap.ColDepth = int(udColDepth->Value);
		chmMap.Width	= int(udWidth->Value);
		chmMap.Height	= int(udHeight->Value);

		chmMap.Delim    = msclr::interop::marshal_as<std::string>(edtDelim->Text);
		chmMap.FileOut  = lineSplit[0];
		chmMap.DirOut   = strDirName;

		memoLogger->AppendText("Create HeatMap\n");

		chmMap.LoadHeatMap(strPathFileName, int(udColHeat->Value), int(udValueMin->Value), int(udValueMax->Value), nHeader);
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

	private: System::Void Button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
		BlendTwoVideos videoOut;
		videoOut.Width = int(udWidth->Value);
		videoOut.Height = int(udHeight->Value);

		string strVideoUm = msclr::interop::marshal_as<std::string>(edtArqMescUm->Text);
		string strVideoDois = msclr::interop::marshal_as<std::string>(edtArqMescDois->Text);
		string strPathFolder = msclr::interop::marshal_as<std::string>(pathFolderVideo->Text);

		if (strPathFolder == "") {
			memoLogger->AppendText("Prencher caminho de saída.\n");
		}
		else if (strVideoUm == "") {
			memoLogger->AppendText("Prencher caminho do primeiro arquivo.\n");
		}
		else if (strVideoDois == "") {
			memoLogger->AppendText("Prencher caminho do segundo arquivo.\n");
		}else {
			memoLogger->AppendText("Blend Start\n");
			memoLogger->AppendText("Width : " + udWidth->Value + " Height : " + udHeight->Value + "\n");
			videoOut.StartBlend(strPathFolder, strVideoUm, strVideoDois);

			memoLogger->AppendText("Blend End\n");
		}		

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