/*
メインフォーム処理クラス
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
	/// MainForm の概要
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
			// メタン濃度計測プログラムメイン処理クラス生成
			mainProc = gcnew MainProc(chart1);
			// タイマー設定
			this->timer1->Interval = mainProc->getInterval();
			this->timer1->Enabled = true;

		}
		void setMethaneConcentration(float val);
		void setTemperature(float val);
		void onTimer();
		Chart^ getChartControl();
	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
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




	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  ファイルToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  設定ToolStripMenuItem;




	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  表示ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  TermGraphToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  機器情報ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^  終了ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;







	private: System::Windows::Forms::Button^  button1;

	private: System::Windows::Forms::Button^  button3;

	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;

	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Panel^  panel5;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel6;
	private: System::Windows::Forms::Label^  labelTemp;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  labelMethane;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label4;


	private:
		void InitComm(){
//			BYTE portInfo[256];
//			int rtn;
//			memset((void*)portInfo, 0, 256);
//			rtn = TdRTR500_GetConnectNum(portInfo, 256, 0x0500, 0);
		}
	private:  MainProc^ mainProc;
	private: GraphForm^ gf;
	private: Settings ^sf;

	private: System::ComponentModel::IContainer^  components;
			 /// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^  title1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->labelTemp = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->labelMethane = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ファイルToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->終了ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->設定ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->表示ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->TermGraphToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->機器情報ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2->SuspendLayout();
			this->panel6->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->panel3->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->panel6);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel2->Location = System::Drawing::Point(0, 70);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1305, 230);
			this->panel2->TabIndex = 6;
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::Color::White;
			this->panel6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel6->Controls->Add(this->labelTemp);
			this->panel6->Controls->Add(this->label5);
			this->panel6->Controls->Add(this->label3);
			this->panel6->Controls->Add(this->labelMethane);
			this->panel6->Controls->Add(this->label6);
			this->panel6->Controls->Add(this->label4);
			this->panel6->Location = System::Drawing::Point(111, 15);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(638, 166);
			this->panel6->TabIndex = 8;
			// 
			// labelTemp
			// 
			this->labelTemp->AutoSize = true;
			this->labelTemp->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelTemp->Location = System::Drawing::Point(365, 83);
			this->labelTemp->Name = L"labelTemp";
			this->labelTemp->Size = System::Drawing::Size(82, 60);
			this->labelTemp->TabIndex = 13;
			this->labelTemp->Text = L"   ";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label5->Location = System::Drawing::Point(502, 83);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(86, 60);
			this->label5->TabIndex = 12;
			this->label5->Text = L"℃";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label3->Location = System::Drawing::Point(16, 83);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(270, 60);
			this->label3->TabIndex = 11;
			this->label3->Text = L"温　　　度";
			// 
			// labelMethane
			// 
			this->labelMethane->AutoSize = true;
			this->labelMethane->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelMethane->Location = System::Drawing::Point(365, 22);
			this->labelMethane->Name = L"labelMethane";
			this->labelMethane->Size = System::Drawing::Size(82, 60);
			this->labelMethane->TabIndex = 10;
			this->labelMethane->Text = L"   ";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label6->Location = System::Drawing::Point(502, 22);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(86, 60);
			this->label6->TabIndex = 9;
			this->label6->Text = L"％";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label4->Location = System::Drawing::Point(16, 22);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(277, 60);
			this->label4->TabIndex = 8;
			this->label4->Text = L"メタン濃度";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label2->Location = System::Drawing::Point(261, 194);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(89, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"12345678";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label1->Location = System::Drawing::Point(107, 194);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(148, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"親機シリアル番号";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->ファイルToolStripMenuItem,
					this->設定ToolStripMenuItem, this->表示ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1305, 27);
			this->menuStrip1->TabIndex = 7;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ファイルToolStripMenuItem
			// 
			this->ファイルToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->toolStripSeparator1,
					this->終了ToolStripMenuItem
			});
			this->ファイルToolStripMenuItem->Name = L"ファイルToolStripMenuItem";
			this->ファイルToolStripMenuItem->Size = System::Drawing::Size(63, 23);
			this->ファイルToolStripMenuItem->Text = L"ファイル";
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(172, 6);
			// 
			// 終了ToolStripMenuItem
			// 
			this->終了ToolStripMenuItem->Name = L"終了ToolStripMenuItem";
			this->終了ToolStripMenuItem->Size = System::Drawing::Size(175, 24);
			this->終了ToolStripMenuItem->Text = L"終了";
			this->終了ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::終了ToolStripMenuItem_Click);
			// 
			// 設定ToolStripMenuItem
			// 
			this->設定ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripMenuItem1 });
			this->設定ToolStripMenuItem->Name = L"設定ToolStripMenuItem";
			this->設定ToolStripMenuItem->Size = System::Drawing::Size(51, 23);
			this->設定ToolStripMenuItem->Text = L"設定";
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(175, 24);
			this->toolStripMenuItem1->Text = L"動作設定";
			this->toolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItem1_Click);
			// 
			// 表示ToolStripMenuItem
			// 
			this->表示ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->TermGraphToolStripMenuItem,
					this->機器情報ToolStripMenuItem, this->toolStripSeparator2
			});
			this->表示ToolStripMenuItem->Name = L"表示ToolStripMenuItem";
			this->表示ToolStripMenuItem->Size = System::Drawing::Size(51, 23);
			this->表示ToolStripMenuItem->Text = L"表示";
			// 
			// TermGraphToolStripMenuItem
			// 
			this->TermGraphToolStripMenuItem->Name = L"TermGraphToolStripMenuItem";
			this->TermGraphToolStripMenuItem->Size = System::Drawing::Size(175, 24);
			this->TermGraphToolStripMenuItem->Text = L"期間グラフ表示";
			this->TermGraphToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::TermGraphToolStripMenuItem_Click);
			// 
			// 機器情報ToolStripMenuItem
			// 
			this->機器情報ToolStripMenuItem->Name = L"機器情報ToolStripMenuItem";
			this->機器情報ToolStripMenuItem->Size = System::Drawing::Size(175, 24);
			this->機器情報ToolStripMenuItem->Text = L"機器情報";
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(172, 6);
			// 
			// chart1
			// 
			this->chart1->BackColor = System::Drawing::SystemColors::Control;
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			this->chart1->Dock = System::Windows::Forms::DockStyle::Fill;
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(0, 0);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Legend = L"Legend1";
			series1->MarkerBorderWidth = 3;
			series1->Name = L"ガス濃度";
			series1->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::DateTime;
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series2->Legend = L"Legend1";
			series2->Name = L"温度";
			series2->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::DateTime;
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(1305, 426);
			this->chart1->TabIndex = 4;
			this->chart1->Text = L"chart1";
			title1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			title1->Name = L"Title1";
			title1->Text = L"ガス濃度";
			this->chart1->Titles->Add(title1);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Gold;
			this->button1->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->button1->Location = System::Drawing::Point(498, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(200, 62);
			this->button1->TabIndex = 0;
			this->button1->Text = L"動作設定";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Visible = false;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Gold;
			this->button3->Dock = System::Windows::Forms::DockStyle::Left;
			this->button3->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->button3->Location = System::Drawing::Point(10, 2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(200, 62);
			this->button3->TabIndex = 2;
			this->button3->Text = L"期間グラフ表示";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MainForm::button3_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::Red;
			this->button5->Dock = System::Windows::Forms::DockStyle::Right;
			this->button5->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->button5->Location = System::Drawing::Point(1091, 2);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(200, 62);
			this->button5->TabIndex = 4;
			this->button5->Text = L"終了";
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
			this->panel4->Controls->Add(this->panel1);
			this->panel4->Controls->Add(this->panel2);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel4->Location = System::Drawing::Point(0, 0);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(1305, 300);
			this->panel4->TabIndex = 10;
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Controls->Add(this->button5);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Padding = System::Windows::Forms::Padding(10, 2, 10, 2);
			this->panel1->Size = System::Drawing::Size(1305, 70);
			this->panel1->TabIndex = 7;
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
			this->Text = L"ガス濃度計測(Version 1.0)";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void グラフ表示ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 showChartDialog();
}
private: System::Void 終了ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
}
private: System::Void toolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
			 showSettingsDialog();
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
}
private: System::Void TermGraphToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 showChartDialog();
}
private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
// タイマー起動
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);

private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 showChartDialog();
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 showSettingsDialog();
}
private: System::Void showChartDialog() {
			 gf = gcnew GraphForm(mainProc->getProperties()->getDataFolder());
			 gf->ShowDialog();

}
private: System::Void showSettingsDialog() {
			 sf = gcnew Settings(mainProc->getProperties());
			 if (sf->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				 // 動作設定ファイルを再読み込み
				 //mainProc->reloadProperties();
				 // タイマー設定
				 this->timer1->Enabled = false;
				 int interval = mainProc->getInterval();
//				 this->timer1->Interval = mainProc->getInterval();
				 this->timer1->Interval = interval;
				 this->timer1->Enabled = true;
			 }

}
};
}
