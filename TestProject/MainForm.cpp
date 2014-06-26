/*
メインフォーム処理クラス
date:2014.06.23
author:Takenori Tanaka(niigata-sl.com)
*/
#include "MainForm.h"

using namespace MethaneGasConcentrationProject;

[STAThreadAttribute]
int main() {
	MainForm ^fm = gcnew MainForm();
	fm->setMethaneConcentration(0.0f);
	fm->setTemperature(0.0f);
	fm->onTimer();
	fm->ShowDialog();
	return 0;
}
Chart^ MainForm::getChartControl() {
	return chart1;
}
//System::Void MainForm::readProperties() {
//}
void MainForm::setMethaneConcentration(float val) {
	labelMethane->Text = val.ToString("F1");
	labelMethane->Refresh();
}

void MainForm::setTemperature(float val) {
	labelTemp->Text = val.ToString("F1");
	labelTemp->Refresh();

}

void MainForm::onTimer() {
	MethaneData^ data = mainProc->onTimer();
	this->setMethaneConcentration(data->getC0());
	this->setTemperature(data->getT());

}
//
// タイマー処理
System::Void MainForm::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	onTimer();
	/*
	float methane = 20.05;
	float temp = 19.9;
	float corrected = 21.23;
	// 現在時間取得
	String^ datetime = Convert::ToString(DateTime::Now);
	String^ delimiter = " ";
	String^ delimiter_ymd = "_";
	// 日付と時間を分離
	array<String^>^ dt = datetime->Split(delimiter->ToCharArray());
	this->setMethaneConcentration(methane);
	this->labelMethane->Refresh();
	MethaneData^ data = gcnew MethaneData();
	data->setDateString(dt[0]);
	data->setTimeString(dt[1]);
	data->setC0(methane);
	data->setC(corrected);
	data->setT(temp);

	// データファイル処理
	String^ fn = dt[0]->Replace("/", "_");
	// 年、月、日を分離
	array<String^>^ ymd = fn->Split(delimiter_ymd->ToCharArray());
	// 日次データファイル名
	String^ dataFileName = System::IO::Directory::GetCurrentDirectory() + "\\" + "data\\" + fn + ".cvs";
	// 月次データファイル名
	String^ MonthlyDataFileName = System::IO::Directory::GetCurrentDirectory() + "\\" + "data\\" + ymd[0] + "_" + ymd[1] + ".cvs";
	// ファイル追加書き出し（ファイルがない時は新規作成される。）
	int rc = dataFile->writeFile(MonthlyDataFileName, data);
	if (rc < 0) {
		// Error
	}
	rc = dataFile->writeFile(dataFileName, data);
	if (rc < 0) {
		// Error
	}

	trendData = gcnew Generic::List<MethaneData^>();
	dataFile->readFile(dataFileName, trendData);
	trendChart->drawChart(trendData);

	//this->chart1->Series["温度"]->Points->Add()
	*/
}
