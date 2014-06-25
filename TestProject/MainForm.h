/*
���C���t�H�[�������N���X
date:2014.06.23
author:Takenori Tanaka(niigata-sl.com)
*/

#pragma once
#include <Windows.h>
//#include <TdRTR500CommLib.h>
#include "GraphForm.h"
#include "Settings.h"
#include "Properties.h"
#include "DataFile.h"
#include "MethaneChart.h"
#include "MainProc.h"

namespace MethaneGasConcentrationProject {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	
	/// <summary>
	/// MainForm �̊T�v
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: �����ɃR���X�g���N�^�[ �R�[�h��ǉ����܂�
			//

			// ���^���Z�x�v���v���O�������C�������N���X����
			mainProc = gcnew MainProc(chart1);
			// �^�C�}�[�ݒ�
			this->timer1->Interval = mainProc->getInterval();
			this->timer1->Enabled = true;
		}
		void setMethaneConcentration(float val);
		void setTemperature(float val);
		Chart^ getChartControl();
	protected:
		/// <summary>
		/// �g�p���̃��\�[�X�����ׂăN���[���A�b�v���܂��B
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:







	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  label6;

	private: System::Windows::Forms::Label^  label4;

	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  �t�@�C��ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �ݒ�ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �w���vToolStripMenuItem;


	private: System::Windows::Forms::ToolStripMenuItem^  ���ԃf�[�^�t�@�C���쐬ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  �\��ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  TermGraphToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  �@����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^  �I��ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  labelTemp;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  labelMethane;

	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;

	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Panel^  panel5;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::ToolStripMenuItem^  �G���[����\��ToolStripMenuItem;

	private:
		void InitComm(){
//			BYTE portInfo[256];
//			int rtn;
//			memset((void*)portInfo, 0, 256);
//			rtn = TdRTR500_GetConnectNum(portInfo, 256, 0x0500, 0);
		}
	private:  MainProc^ mainProc;
	private: System::ComponentModel::IContainer^  components;
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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^  title2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->labelTemp = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->labelMethane = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->�t�@�C��ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���ԃf�[�^�t�@�C���쐬ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->�I��ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�ݒ�ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�\��ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->TermGraphToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�@����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->�G���[����\��ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�w���vToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel2->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->flowLayoutPanel1->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->labelTemp);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->labelMethane);
			this->panel2->Controls->Add(this->label6);
			this->panel2->Controls->Add(this->label4);
			this->panel2->Location = System::Drawing::Point(21, 58);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(839, 230);
			this->panel2->TabIndex = 6;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label2->Location = System::Drawing::Point(177, 172);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(89, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"12345678";
			// 
			// labelTemp
			// 
			this->labelTemp->AutoSize = true;
			this->labelTemp->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelTemp->Location = System::Drawing::Point(366, 83);
			this->labelTemp->Name = L"labelTemp";
			this->labelTemp->Size = System::Drawing::Size(131, 60);
			this->labelTemp->TabIndex = 7;
			this->labelTemp->Text = L"18.6";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label1->Location = System::Drawing::Point(23, 172);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(148, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"�e�@�V���A���ԍ�";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label5->Location = System::Drawing::Point(503, 83);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(86, 60);
			this->label5->TabIndex = 6;
			this->label5->Text = L"��";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label3->Location = System::Drawing::Point(17, 83);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(270, 60);
			this->label3->TabIndex = 5;
			this->label3->Text = L"���@�@�@�x";
			// 
			// labelMethane
			// 
			this->labelMethane->AutoSize = true;
			this->labelMethane->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelMethane->Location = System::Drawing::Point(366, 22);
			this->labelMethane->Name = L"labelMethane";
			this->labelMethane->Size = System::Drawing::Size(131, 60);
			this->labelMethane->TabIndex = 4;
			this->labelMethane->Text = L"45.5";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label6->Location = System::Drawing::Point(503, 22);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(86, 60);
			this->label6->TabIndex = 3;
			this->label6->Text = L"��";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label4->Location = System::Drawing::Point(17, 22);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(277, 60);
			this->label4->TabIndex = 1;
			this->label4->Text = L"���^���Z�x";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->�t�@�C��ToolStripMenuItem,
					this->�ݒ�ToolStripMenuItem, this->�\��ToolStripMenuItem, this->�w���vToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1305, 27);
			this->menuStrip1->TabIndex = 7;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// �t�@�C��ToolStripMenuItem
			// 
			this->�t�@�C��ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->���ԃf�[�^�t�@�C���쐬ToolStripMenuItem,
					this->toolStripSeparator1, this->�I��ToolStripMenuItem
			});
			this->�t�@�C��ToolStripMenuItem->Name = L"�t�@�C��ToolStripMenuItem";
			this->�t�@�C��ToolStripMenuItem->Size = System::Drawing::Size(63, 23);
			this->�t�@�C��ToolStripMenuItem->Text = L"�t�@�C��";
			// 
			// ���ԃf�[�^�t�@�C���쐬ToolStripMenuItem
			// 
			this->���ԃf�[�^�t�@�C���쐬ToolStripMenuItem->Name = L"���ԃf�[�^�t�@�C���쐬ToolStripMenuItem";
			this->���ԃf�[�^�t�@�C���쐬ToolStripMenuItem->Size = System::Drawing::Size(214, 24);
			this->���ԃf�[�^�t�@�C���쐬ToolStripMenuItem->Text = L"���ԃf�[�^�t�@�C���쐬";
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(211, 6);
			// 
			// �I��ToolStripMenuItem
			// 
			this->�I��ToolStripMenuItem->Name = L"�I��ToolStripMenuItem";
			this->�I��ToolStripMenuItem->Size = System::Drawing::Size(214, 24);
			this->�I��ToolStripMenuItem->Text = L"�I��";
			this->�I��ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::�I��ToolStripMenuItem_Click);
			// 
			// �ݒ�ToolStripMenuItem
			// 
			this->�ݒ�ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripMenuItem1 });
			this->�ݒ�ToolStripMenuItem->Name = L"�ݒ�ToolStripMenuItem";
			this->�ݒ�ToolStripMenuItem->Size = System::Drawing::Size(51, 23);
			this->�ݒ�ToolStripMenuItem->Text = L"�ݒ�";
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(138, 24);
			this->toolStripMenuItem1->Text = L"����ݒ�";
			this->toolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItem1_Click);
			// 
			// �\��ToolStripMenuItem
			// 
			this->�\��ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->TermGraphToolStripMenuItem,
					this->�@����ToolStripMenuItem, this->toolStripSeparator2, this->�G���[����\��ToolStripMenuItem
			});
			this->�\��ToolStripMenuItem->Name = L"�\��ToolStripMenuItem";
			this->�\��ToolStripMenuItem->Size = System::Drawing::Size(51, 23);
			this->�\��ToolStripMenuItem->Text = L"�\��";
			// 
			// TermGraphToolStripMenuItem
			// 
			this->TermGraphToolStripMenuItem->Name = L"TermGraphToolStripMenuItem";
			this->TermGraphToolStripMenuItem->Size = System::Drawing::Size(171, 24);
			this->TermGraphToolStripMenuItem->Text = L"���ԃO���t�\��";
			this->TermGraphToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::TermGraphToolStripMenuItem_Click);
			// 
			// �@����ToolStripMenuItem
			// 
			this->�@����ToolStripMenuItem->Name = L"�@����ToolStripMenuItem";
			this->�@����ToolStripMenuItem->Size = System::Drawing::Size(171, 24);
			this->�@����ToolStripMenuItem->Text = L"�@����";
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(168, 6);
			// 
			// �G���[����\��ToolStripMenuItem
			// 
			this->�G���[����\��ToolStripMenuItem->Name = L"�G���[����\��ToolStripMenuItem";
			this->�G���[����\��ToolStripMenuItem->Size = System::Drawing::Size(171, 24);
			this->�G���[����\��ToolStripMenuItem->Text = L"�G���[����\��";
			// 
			// �w���vToolStripMenuItem
			// 
			this->�w���vToolStripMenuItem->Name = L"�w���vToolStripMenuItem";
			this->�w���vToolStripMenuItem->Size = System::Drawing::Size(56, 23);
			this->�w���vToolStripMenuItem->Text = L"�w���v";
			// 
			// chart1
			// 
			chartArea2->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea2);
			this->chart1->Dock = System::Windows::Forms::DockStyle::Fill;
			legend2->Name = L"Legend1";
			this->chart1->Legends->Add(legend2);
			this->chart1->Location = System::Drawing::Point(0, 0);
			this->chart1->Name = L"chart1";
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series3->Legend = L"Legend1";
			series3->MarkerBorderWidth = 3;
			series3->Name = L"�K�X�Z�x";
			series3->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::DateTime;
			series4->ChartArea = L"ChartArea1";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series4->Legend = L"Legend1";
			series4->Name = L"���x";
			series4->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::DateTime;
			this->chart1->Series->Add(series3);
			this->chart1->Series->Add(series4);
			this->chart1->Size = System::Drawing::Size(1305, 426);
			this->chart1->TabIndex = 4;
			this->chart1->Text = L"chart1";
			title2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			title2->Name = L"Title1";
			title2->Text = L"�K�X�Z�x";
			this->chart1->Titles->Add(title2);
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->button1);
			this->flowLayoutPanel1->Controls->Add(this->button2);
			this->flowLayoutPanel1->Controls->Add(this->button3);
			this->flowLayoutPanel1->Controls->Add(this->button4);
			this->flowLayoutPanel1->Controls->Add(this->button5);
			this->flowLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->flowLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(1305, 52);
			this->flowLayoutPanel1->TabIndex = 9;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Gold;
			this->button1->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->button1->Location = System::Drawing::Point(3, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(120, 48);
			this->button1->TabIndex = 0;
			this->button1->Text = L"����ݒ�";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(129, 3);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(10, 48);
			this->button2->TabIndex = 1;
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Gold;
			this->button3->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->button3->Location = System::Drawing::Point(145, 3);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(160, 48);
			this->button3->TabIndex = 2;
			this->button3->Text = L"���ԃO���t�\��";
			this->button3->UseVisualStyleBackColor = false;
			// 
			// button4
			// 
			this->button4->Enabled = false;
			this->button4->Location = System::Drawing::Point(311, 3);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(10, 48);
			this->button4->TabIndex = 5;
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::Red;
			this->button5->Dock = System::Windows::Forms::DockStyle::Right;
			this->button5->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->button5->Location = System::Drawing::Point(327, 3);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(120, 48);
			this->button5->TabIndex = 4;
			this->button5->Text = L"�I��";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MainForm::button5_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MainForm::timer1_Tick);
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->panel5);
			this->panel3->Controls->Add(this->panel4);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel3->Location = System::Drawing::Point(0, 27);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(1305, 726);
			this->panel3->TabIndex = 10;
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->chart1);
			this->panel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel5->Location = System::Drawing::Point(0, 300);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(1305, 426);
			this->panel5->TabIndex = 11;
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->flowLayoutPanel1);
			this->panel4->Controls->Add(this->panel2);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel4->Location = System::Drawing::Point(0, 0);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(1305, 300);
			this->panel4->TabIndex = 10;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1305, 753);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainForm";
			this->Text = L"�K�X�Z�x�v��";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->flowLayoutPanel1->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void �O���t�\��ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void �I��ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
}
private: System::Void toolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
			 Settings ^sf = gcnew Settings();
			 sf->Show();
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
}
private: System::Void TermGraphToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 GraphForm^ gf = gcnew GraphForm();
			 gf->Show();
}
private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
// �^�C�}�[�N��
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);
};
}
