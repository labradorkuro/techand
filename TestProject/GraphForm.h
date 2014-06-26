#pragma once
#include "MainProc.h"
namespace MethaneGasConcentrationProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// GraphForm �̊T�v
	/// </summary>
	public ref class GraphForm : public System::Windows::Forms::Form
	{
	public:
		GraphForm(String^ folder)
		{
			InitializeComponent();
			//
			//TODO: �����ɃR���X�g���N�^�[ �R�[�h��ǉ����܂�
			//
			dataFolder = folder;
			startDate->Value = DateTime::Now;
			endDate->Value = DateTime::Now;
			trendChart = gcnew MethaneChart(chart1);
		}

	protected:
		/// <summary>
		/// �g�p���̃��\�[�X�����ׂăN���[���A�b�v���܂��B
		/// </summary>
		~GraphForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: List<MethaneData^>^ dataList;
	private: MethaneChart^ trendChart;
	private: String^ dataFolder;
	private: System::Windows::Forms::Panel^  panel1;
	protected:

	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::DateTimePicker^  startDate;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::DateTimePicker^  endDate;

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Panel^  panel3;

	private:
		/// <summary>
		/// �K�v�ȃf�U�C�i�[�ϐ��ł��B
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �f�U�C�i�[ �T�|�[�g�ɕK�v�ȃ��\�b�h�ł��B���̃��\�b�h�̓��e��
		/// �R�[�h �G�f�B�^�[�ŕύX���Ȃ��ł��������B
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^  title1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->startDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->endDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->startDate);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->endDate);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Padding = System::Windows::Forms::Padding(2);
			this->panel1->Size = System::Drawing::Size(1318, 52);
			this->panel1->TabIndex = 0;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Red;
			this->button2->Dock = System::Windows::Forms::DockStyle::Right;
			this->button2->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->button2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button2->Location = System::Drawing::Point(1175, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(139, 46);
			this->button2->TabIndex = 10;
			this->button2->Text = L"����";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &GraphForm::button2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Gold;
			this->button1->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->button1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button1->Location = System::Drawing::Point(660, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(139, 46);
			this->button1->TabIndex = 9;
			this->button1->Text = L"�\��";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &GraphForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label1->Location = System::Drawing::Point(14, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(82, 24);
			this->label1->TabIndex = 7;
			this->label1->Text = L"�J�n��";
			// 
			// startDate
			// 
			this->startDate->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->startDate->Location = System::Drawing::Point(100, 10);
			this->startDate->Name = L"startDate";
			this->startDate->Size = System::Drawing::Size(200, 30);
			this->startDate->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label2->Location = System::Drawing::Point(349, 12);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(82, 24);
			this->label2->TabIndex = 8;
			this->label2->Text = L"�I����";
			// 
			// endDate
			// 
			this->endDate->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->endDate->Location = System::Drawing::Point(435, 10);
			this->endDate->Name = L"endDate";
			this->endDate->Size = System::Drawing::Size(200, 30);
			this->endDate->TabIndex = 6;
			// 
			// chart1
			// 
			this->chart1->BackColor = System::Drawing::SystemColors::Control;
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			this->chart1->Dock = System::Windows::Forms::DockStyle::Fill;
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(0, 52);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Legend = L"Legend1";
			series1->Name = L"�K�X�Z�x";
			series1->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Time;
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(1318, 528);
			this->chart1->TabIndex = 3;
			this->chart1->Text = L"chart1";
			title1->Name = L"Title1";
			title1->Text = L"�K�X�Z�x";
			this->chart1->Titles->Add(title1);
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->chart1);
			this->panel3->Controls->Add(this->panel1);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel3->Location = System::Drawing::Point(0, 0);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(1318, 580);
			this->panel3->TabIndex = 2;
			// 
			// GraphForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1318, 580);
			this->Controls->Add(this->panel3);
			this->Name = L"GraphForm";
			this->Text = L"�O���t�\��";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->panel3->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 DateTime^ start = startDate->Value;
				 DateTime^ end = endDate->Value;
				 // �ߋ�1�T�Ԃ̃f�[�^��Ǎ���
				 dataList = gcnew Generic::List<MethaneData^>();
				 DataFile^ dataFile = gcnew DataFile();
				 DateTime^ wk = start;
				 while (wk->CompareTo(end) <= 0) {
					 // �����f�[�^�t�@�C����
					 String^ dailyDataFileName = dataFolder + "\\" + MainProc::getDailyFileNameFromDateTime(wk) + ".cvs";
					 dataFile->readFile(dailyDataFileName, dataList);
					 wk = wk->AddDays(1);
				 }
				 trendChart->drawChart(dataList);

	}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
}
};
}
