#pragma once
#include <Windows.h>
//#include <TdRTR500CommLib.h>

#include "GraphForm.h"
#include "Settings.h"

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
		}
		int dataFileRead();
		void setMethaneConcentration(float val);
		void setTemperature(float val);
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
	private: System::Windows::Forms::Label^  label6;

	private: System::Windows::Forms::Label^  label4;

	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  ファイルToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  設定ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ヘルプToolStripMenuItem;


	private: System::Windows::Forms::ToolStripMenuItem^  期間データファイル作成ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  表示ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  TermGraphToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  機器情報ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^  終了ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
	private: System::Windows::Forms::Panel^  panel1;
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
	private: System::Windows::Forms::ToolStripMenuItem^  エラー履歴表示ToolStripMenuItem;

	private:
		void InitComm(){
//			BYTE portInfo[256];
//			int rtn;
//			memset((void*)portInfo, 0, 256);
//			rtn = TdRTR500_GetConnectNum(portInfo, 256, 0x0500, 0);
		}
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
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
			this->ファイルToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->期間データファイル作成ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->終了ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->設定ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->表示ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->TermGraphToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->機器情報ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->エラー履歴表示ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ヘルプToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->panel2->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->flowLayoutPanel1->SuspendLayout();
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
			this->panel2->Location = System::Drawing::Point(12, 114);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(565, 230);
			this->panel2->TabIndex = 6;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label2->Location = System::Drawing::Point(427, 184);
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
			this->labelTemp->Location = System::Drawing::Point(301, 83);
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
			this->label1->Location = System::Drawing::Point(273, 184);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(148, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"親機シリアル番号";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label5->Location = System::Drawing::Point(430, 83);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(86, 60);
			this->label5->TabIndex = 6;
			this->label5->Text = L"℃";
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
			this->label3->Text = L"温　　　度";
			// 
			// labelMethane
			// 
			this->labelMethane->AutoSize = true;
			this->labelMethane->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelMethane->Location = System::Drawing::Point(301, 22);
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
			this->label6->Location = System::Drawing::Point(430, 22);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(86, 60);
			this->label6->TabIndex = 3;
			this->label6->Text = L"％";
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
			this->label4->Text = L"メタン濃度";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->ファイルToolStripMenuItem,
					this->設定ToolStripMenuItem, this->表示ToolStripMenuItem, this->ヘルプToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(590, 27);
			this->menuStrip1->TabIndex = 7;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ファイルToolStripMenuItem
			// 
			this->ファイルToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->期間データファイル作成ToolStripMenuItem,
					this->toolStripSeparator1, this->終了ToolStripMenuItem
			});
			this->ファイルToolStripMenuItem->Name = L"ファイルToolStripMenuItem";
			this->ファイルToolStripMenuItem->Size = System::Drawing::Size(63, 23);
			this->ファイルToolStripMenuItem->Text = L"ファイル";
			// 
			// 期間データファイル作成ToolStripMenuItem
			// 
			this->期間データファイル作成ToolStripMenuItem->Name = L"期間データファイル作成ToolStripMenuItem";
			this->期間データファイル作成ToolStripMenuItem->Size = System::Drawing::Size(214, 24);
			this->期間データファイル作成ToolStripMenuItem->Text = L"期間データファイル作成";
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(211, 6);
			// 
			// 終了ToolStripMenuItem
			// 
			this->終了ToolStripMenuItem->Name = L"終了ToolStripMenuItem";
			this->終了ToolStripMenuItem->Size = System::Drawing::Size(214, 24);
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
			this->toolStripMenuItem1->Size = System::Drawing::Size(138, 24);
			this->toolStripMenuItem1->Text = L"動作設定";
			this->toolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItem1_Click);
			// 
			// 表示ToolStripMenuItem
			// 
			this->表示ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->TermGraphToolStripMenuItem,
					this->機器情報ToolStripMenuItem, this->toolStripSeparator2, this->エラー履歴表示ToolStripMenuItem
			});
			this->表示ToolStripMenuItem->Name = L"表示ToolStripMenuItem";
			this->表示ToolStripMenuItem->Size = System::Drawing::Size(51, 23);
			this->表示ToolStripMenuItem->Text = L"表示";
			// 
			// TermGraphToolStripMenuItem
			// 
			this->TermGraphToolStripMenuItem->Name = L"TermGraphToolStripMenuItem";
			this->TermGraphToolStripMenuItem->Size = System::Drawing::Size(171, 24);
			this->TermGraphToolStripMenuItem->Text = L"期間グラフ表示";
			this->TermGraphToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::TermGraphToolStripMenuItem_Click);
			// 
			// 機器情報ToolStripMenuItem
			// 
			this->機器情報ToolStripMenuItem->Name = L"機器情報ToolStripMenuItem";
			this->機器情報ToolStripMenuItem->Size = System::Drawing::Size(171, 24);
			this->機器情報ToolStripMenuItem->Text = L"機器情報";
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(168, 6);
			// 
			// エラー履歴表示ToolStripMenuItem
			// 
			this->エラー履歴表示ToolStripMenuItem->Name = L"エラー履歴表示ToolStripMenuItem";
			this->エラー履歴表示ToolStripMenuItem->Size = System::Drawing::Size(171, 24);
			this->エラー履歴表示ToolStripMenuItem->Text = L"エラー履歴表示";
			// 
			// ヘルプToolStripMenuItem
			// 
			this->ヘルプToolStripMenuItem->Name = L"ヘルプToolStripMenuItem";
			this->ヘルプToolStripMenuItem->Size = System::Drawing::Size(56, 23);
			this->ヘルプToolStripMenuItem->Text = L"ヘルプ";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->chart1);
			this->panel1->Location = System::Drawing::Point(12, 350);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(565, 291);
			this->panel1->TabIndex = 8;
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
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series2->Legend = L"Legend1";
			series2->Name = L"ガス濃度";
			series2->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Time;
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(565, 291);
			this->chart1->TabIndex = 4;
			this->chart1->Text = L"chart1";
			title2->Name = L"Title1";
			title2->Text = L"ガス濃度";
			this->chart1->Titles->Add(title2);
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->button1);
			this->flowLayoutPanel1->Controls->Add(this->button2);
			this->flowLayoutPanel1->Controls->Add(this->button3);
			this->flowLayoutPanel1->Controls->Add(this->button4);
			this->flowLayoutPanel1->Controls->Add(this->button5);
			this->flowLayoutPanel1->Location = System::Drawing::Point(12, 43);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(564, 52);
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
			this->button1->Text = L"動作設定";
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
			this->button3->Text = L"期間グラフ表示";
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
			this->button5->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->button5->Location = System::Drawing::Point(327, 3);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(120, 48);
			this->button5->TabIndex = 4;
			this->button5->Text = L"終了";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MainForm::button5_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(590, 653);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainForm";
			this->Text = L"ガス濃度計測";
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->flowLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void グラフ表示ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void 終了ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
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
};
}
