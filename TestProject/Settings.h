#pragma once
#include "Properties.h"
#include "SerialPortProc.h"

namespace MethaneGasConcentrationProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Settings �̊T�v
	/// </summary>
	public ref class Settings : public System::Windows::Forms::Form
	{
	public:
		Settings(Properties^ prop)
		{
			InitializeComponent();
			//
			//TODO: �����ɃR���X�g���N�^�[ �R�[�h��ǉ����܂�
			//
			properties = prop;
			this->intervalUpDown->Value = properties->getInterval() / 1000;
			this->folderTextBox->Text = properties->getDataFolder();
			this->portComboBox->SelectedItem = properties->getPortNo();
			this->errorRetry->Value = properties->getErrorRetry();
			this->retryLimit->Value = properties->getRetryLimit();
		}

	protected:
		/// <summary>
		/// �g�p���̃��\�[�X�����ׂăN���[���A�b�v���܂��B
		/// </summary>
		~Settings()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Properties^ properties;
	private: System::Windows::Forms::Panel^  panel5;
	protected:
	private: System::Windows::Forms::Panel^  panel6;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;
	private: System::Windows::Forms::Panel^  panel7;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	private: System::Windows::Forms::TextBox^  folderTextBox;

	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Panel^  panel8;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::NumericUpDown^  intervalUpDown;
	private: System::Windows::Forms::ComboBox^  portComboBox;
	private: System::Windows::Forms::Button^  button1;
	private: System::IO::Ports::SerialPort^  serialPort1;
	private: System::Windows::Forms::Panel^  panel9;
	private: System::Windows::Forms::TextBox^  num;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Panel^  panel10;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Panel^  panel11;
	private: System::Windows::Forms::Panel^  panel12;
	private: System::Windows::Forms::Panel^  panel13;
	private: System::Windows::Forms::NumericUpDown^  errorRetry;
	private: System::Windows::Forms::Panel^  panel14;
	private: System::Windows::Forms::NumericUpDown^  retryLimit;
	private: System::ComponentModel::IContainer^  components;




	private:
		/// <summary>
		/// �K�v�ȃf�U�C�i�[�ϐ��ł��B
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// �f�U�C�i�[ �T�|�[�g�ɕK�v�ȃ��\�b�h�ł��B���̃��\�b�h�̓��e��
		/// �R�[�h �G�f�B�^�[�ŕύX���Ȃ��ł��������B
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->folderTextBox = (gcnew System::Windows::Forms::TextBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->intervalUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->portComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->panel11 = (gcnew System::Windows::Forms::Panel());
			this->panel12 = (gcnew System::Windows::Forms::Panel());
			this->num = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel13 = (gcnew System::Windows::Forms::Panel());
			this->errorRetry = (gcnew System::Windows::Forms::NumericUpDown());
			this->panel14 = (gcnew System::Windows::Forms::Panel());
			this->retryLimit = (gcnew System::Windows::Forms::NumericUpDown());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->panel5->SuspendLayout();
			this->panel6->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel7->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			this->panel8->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->intervalUpDown))->BeginInit();
			this->panel9->SuspendLayout();
			this->panel10->SuspendLayout();
			this->panel12->SuspendLayout();
			this->panel13->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorRetry))->BeginInit();
			this->panel14->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->retryLimit))->BeginInit();
			this->SuspendLayout();
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->panel6);
			this->panel5->Controls->Add(this->tableLayoutPanel1);
			this->panel5->Location = System::Drawing::Point(12, 12);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(701, 467);
			this->panel5->TabIndex = 1;
			// 
			// panel6
			// 
			this->panel6->Controls->Add(this->button3);
			this->panel6->Controls->Add(this->button2);
			this->panel6->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel6->Location = System::Drawing::Point(0, 409);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(701, 58);
			this->panel6->TabIndex = 2;
			// 
			// button3
			// 
			this->button3->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->button3->Location = System::Drawing::Point(89, 10);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(210, 38);
			this->button3->TabIndex = 8;
			this->button3->Text = L"�ۑ�";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Settings::button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(404, 10);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(210, 38);
			this->button2->TabIndex = 9;
			this->button2->Text = L"�L�����Z��";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Settings::button2_Click);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->panel1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->panel2, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->panel3, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->panel4, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->panel7, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->flowLayoutPanel1, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->panel8, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->portComboBox, 1, 3);
			this->tableLayoutPanel1->Controls->Add(this->panel9, 0, 5);
			this->tableLayoutPanel1->Controls->Add(this->panel10, 0, 4);
			this->tableLayoutPanel1->Controls->Add(this->panel11, 0, 6);
			this->tableLayoutPanel1->Controls->Add(this->panel12, 0, 7);
			this->tableLayoutPanel1->Controls->Add(this->button1, 1, 7);
			this->tableLayoutPanel1->Controls->Add(this->panel13, 1, 4);
			this->tableLayoutPanel1->Controls->Add(this->panel14, 1, 5);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 8;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 40)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 40)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 40)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 40)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 40)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 40)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 40)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 40)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(701, 329);
			this->tableLayoutPanel1->TabIndex = 1;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(1, 1);
			this->panel1->Margin = System::Windows::Forms::Padding(0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(349, 40);
			this->panel1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label1->Location = System::Drawing::Point(84, 11);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(72, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"���ږ�";
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->label2);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(354, 4);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(343, 34);
			this->panel2->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label2->Location = System::Drawing::Point(123, 7);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(30, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"�l";
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->label3);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel3->Location = System::Drawing::Point(1, 42);
			this->panel3->Margin = System::Windows::Forms::Padding(0);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(349, 40);
			this->panel3->TabIndex = 2;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label3->Location = System::Drawing::Point(24, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(228, 20);
			this->label3->TabIndex = 1;
			this->label3->Text = L"�f�[�^�t�@�C���ۑ���t�H���_";
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->label4);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel4->Location = System::Drawing::Point(1, 83);
			this->panel4->Margin = System::Windows::Forms::Padding(0);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(349, 40);
			this->panel4->TabIndex = 3;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label4->Location = System::Drawing::Point(24, 11);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(175, 20);
			this->label4->TabIndex = 2;
			this->label4->Text = L"�f�[�^�v�����ԊԊu";
			// 
			// panel7
			// 
			this->panel7->Controls->Add(this->label5);
			this->panel7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel7->Location = System::Drawing::Point(1, 124);
			this->panel7->Margin = System::Windows::Forms::Padding(0);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(349, 40);
			this->panel7->TabIndex = 4;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label5->Location = System::Drawing::Point(24, 9);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(95, 20);
			this->label5->TabIndex = 3;
			this->label5->Text = L"�ʐM�|�[�g";
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->folderTextBox);
			this->flowLayoutPanel1->Controls->Add(this->button4);
			this->flowLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel1->Location = System::Drawing::Point(351, 42);
			this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(0);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(349, 40);
			this->flowLayoutPanel1->TabIndex = 5;
			// 
			// folderTextBox
			// 
			this->folderTextBox->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->folderTextBox->Location = System::Drawing::Point(3, 6);
			this->folderTextBox->Margin = System::Windows::Forms::Padding(3, 6, 3, 3);
			this->folderTextBox->Name = L"folderTextBox";
			this->folderTextBox->Size = System::Drawing::Size(260, 27);
			this->folderTextBox->TabIndex = 0;
			// 
			// button4
			// 
			this->button4->Dock = System::Windows::Forms::DockStyle::Right;
			this->button4->Location = System::Drawing::Point(269, 3);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(77, 30);
			this->button4->TabIndex = 1;
			this->button4->Text = L"�Q��";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Settings::button4_Click);
			// 
			// panel8
			// 
			this->panel8->Controls->Add(this->label6);
			this->panel8->Controls->Add(this->intervalUpDown);
			this->panel8->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel8->Location = System::Drawing::Point(351, 83);
			this->panel8->Margin = System::Windows::Forms::Padding(0);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(349, 40);
			this->panel8->TabIndex = 6;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label6->Location = System::Drawing::Point(265, 14);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(29, 20);
			this->label6->TabIndex = 1;
			this->label6->Text = L"�b";
			// 
			// intervalUpDown
			// 
			this->intervalUpDown->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->intervalUpDown->Location = System::Drawing::Point(3, 7);
			this->intervalUpDown->Margin = System::Windows::Forms::Padding(3, 8, 3, 3);
			this->intervalUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3600, 0, 0, 0 });
			this->intervalUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->intervalUpDown->Name = L"intervalUpDown";
			this->intervalUpDown->Size = System::Drawing::Size(256, 27);
			this->intervalUpDown->TabIndex = 2;
			this->intervalUpDown->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->intervalUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			// 
			// portComboBox
			// 
			this->portComboBox->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->portComboBox->FormattingEnabled = true;
			this->portComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
				L"COM1", L"COM2", L"COM3", L"COM4", L"COM5",
					L"COM6", L"COM7", L"COM8", L"COM9"
			});
			this->portComboBox->Location = System::Drawing::Point(354, 127);
			this->portComboBox->Name = L"portComboBox";
			this->portComboBox->Size = System::Drawing::Size(260, 28);
			this->portComboBox->TabIndex = 3;
			this->portComboBox->Text = L"�I�����Ă�������";
			// 
			// panel9
			// 
			this->panel9->Controls->Add(this->label9);
			this->panel9->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel9->Location = System::Drawing::Point(4, 209);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(343, 34);
			this->panel9->TabIndex = 9;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label9->Location = System::Drawing::Point(24, 9);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(174, 20);
			this->label9->TabIndex = 5;
			this->label9->Text = L"�G���[�m��񐔐���";
			// 
			// panel10
			// 
			this->panel10->Controls->Add(this->label8);
			this->panel10->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel10->Location = System::Drawing::Point(4, 168);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(343, 34);
			this->panel10->TabIndex = 10;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label8->Location = System::Drawing::Point(24, 9);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(148, 20);
			this->label8->TabIndex = 4;
			this->label8->Text = L"�G���[���g���C��";
			// 
			// panel11
			// 
			this->panel11->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel11->Location = System::Drawing::Point(4, 250);
			this->panel11->Name = L"panel11";
			this->panel11->Size = System::Drawing::Size(343, 34);
			this->panel11->TabIndex = 11;
			// 
			// panel12
			// 
			this->panel12->Controls->Add(this->num);
			this->panel12->Controls->Add(this->label7);
			this->panel12->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel12->Location = System::Drawing::Point(4, 291);
			this->panel12->Name = L"panel12";
			this->panel12->Size = System::Drawing::Size(343, 34);
			this->panel12->TabIndex = 12;
			// 
			// num
			// 
			this->num->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->num->Location = System::Drawing::Point(254, 4);
			this->num->Name = L"num";
			this->num->Size = System::Drawing::Size(60, 27);
			this->num->TabIndex = 6;
			this->num->Text = L"1";
			this->num->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label7
			// 
			this->label7->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label7->Location = System::Drawing::Point(126, 7);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(89, 20);
			this->label7->TabIndex = 1;
			this->label7->Text = L"�q�@�ԍ�";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->button1->Location = System::Drawing::Point(354, 291);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(343, 34);
			this->button1->TabIndex = 7;
			this->button1->Text = L"���j�[�NID�Z�b�g";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Settings::button1_Click);
			// 
			// panel13
			// 
			this->panel13->Controls->Add(this->errorRetry);
			this->panel13->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel13->Location = System::Drawing::Point(354, 168);
			this->panel13->Name = L"panel13";
			this->panel13->Size = System::Drawing::Size(343, 34);
			this->panel13->TabIndex = 13;
			// 
			// errorRetry
			// 
			this->errorRetry->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->errorRetry->Location = System::Drawing::Point(3, 7);
			this->errorRetry->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 200, 0, 0, 0 });
			this->errorRetry->Name = L"errorRetry";
			this->errorRetry->Size = System::Drawing::Size(120, 27);
			this->errorRetry->TabIndex = 4;
			this->errorRetry->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->errorRetry->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			// 
			// panel14
			// 
			this->panel14->Controls->Add(this->retryLimit);
			this->panel14->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel14->Location = System::Drawing::Point(354, 209);
			this->panel14->Name = L"panel14";
			this->panel14->Size = System::Drawing::Size(343, 34);
			this->panel14->TabIndex = 14;
			// 
			// retryLimit
			// 
			this->retryLimit->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->retryLimit->Location = System::Drawing::Point(3, 7);
			this->retryLimit->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 300, 0, 0, 0 });
			this->retryLimit->Name = L"retryLimit";
			this->retryLimit->Size = System::Drawing::Size(120, 27);
			this->retryLimit->TabIndex = 5;
			this->retryLimit->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->retryLimit->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 144, 0, 0, 0 });
			// 
			// serialPort1
			// 
			this->serialPort1->BaudRate = 38400;
			this->serialPort1->PortName = L"COM3";
			// 
			// Settings
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(731, 486);
			this->Controls->Add(this->panel5);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Settings";
			this->Text = L"����ݒ�";
			this->panel5->ResumeLayout(false);
			this->panel6->ResumeLayout(false);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel7->ResumeLayout(false);
			this->panel7->PerformLayout();
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			this->panel8->ResumeLayout(false);
			this->panel8->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->intervalUpDown))->EndInit();
			this->panel9->ResumeLayout(false);
			this->panel9->PerformLayout();
			this->panel10->ResumeLayout(false);
			this->panel10->PerformLayout();
			this->panel12->ResumeLayout(false);
			this->panel12->PerformLayout();
			this->panel13->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorRetry))->EndInit();
			this->panel14->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->retryLimit))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 bool dirty = false;
				 if (String::Compare(properties->getDataFolder(), this->folderTextBox->Text) != 0) {
					 dirty = true;
				 }
				 if (properties->getInterval() != this->intervalUpDown->Value * 1000) {
					 dirty = true;
				 }
				 if (properties->getErrorRetry() != this->errorRetry->Value) {
					 dirty = true;
				 }
				 if (properties->getRetryLimit() != this->retryLimit->Value) {
					 dirty = true;
				 }
				 if (String::Compare(properties->getPortNo(), this->portComboBox->SelectedItem->ToString())) {
					 dirty = true;
				 }
				 if (dirty) {
					 if (MessageBox::Show("�ݒ�l���ύX����Ă��܂����ۑ������ɕ��܂����H", "����ݒ�", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes){
						 this->Close();

					 }
				 }
				 else {
					 this->Close();
				 }
	}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (this->folderBrowserDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				 this->folderTextBox->Text = this->folderBrowserDialog1->SelectedPath;
			 }
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 properties->setDataFolder(this->folderTextBox->Text);
			 properties->setInterval((int)(this->intervalUpDown->Value * 1000));
			 properties->setPortNo(this->portComboBox->SelectedItem->ToString());
			 properties->setErrorRetry((int)(this->errorRetry->Value));
			 properties->setRetryLimit((int)(this->retryLimit->Value));
			 properties->writeFile();
			 this->Close();
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 SerialPortProc^ sp = gcnew SerialPortProc(this->serialPort1);
			 unsigned char n = this->num->Text->ToCharArray()[0];
			 if (sp->openPort(properties->getPortNo())) {
				 if (sp->setUID(n)) {
					 MessageBox::Show("�ݒ肳��܂���", "����ݒ�", MessageBoxButtons::OK);
				 }
				 else {
					 MessageBox::Show("�ݒ�ł��܂���ł���", "����ݒ�", MessageBoxButtons::OK);
				 }
				 sp->closePort();
			 }
			 
}

};
}
