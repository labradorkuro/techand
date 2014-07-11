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
	//fm->onTimer();
	fm->ShowDialog();
	return 0;
}
Chart^ MainForm::getChartControl() {
	return chart1;
}
//System::Void MainForm::readProperties() {
//}
void MainForm::setMethaneConcentration(float val) {
	labelMethane->Text = formatValue(val);// val.ToString("F1");
	labelMethane->Refresh();
}

void MainForm::setTemperature(float val) {
	labelTemp->Text = formatValue(val);// val.ToString("##0.0");
	labelTemp->Refresh();

}
void MainForm::setBatRssiLevel(int no, int bat, int rssi) {
	if (no == 1) {
		label_temp_level->Text = "電波強度：" + rssi + "  電池残量：" + bat;
		label_temp_level->Refresh();
	}
	else if (no == 2) {
		label_ammeter_level->Text = "電波強度：" + rssi + "  電池残量：" + bat;
		label_ammeter_level->Refresh();
	}

}
void MainForm::setTimeLabel(String^ time) {
	labelTime->Text = "計測時間：" + time;
	labelTime->Refresh();

}
String^ MainForm::formatValue(float val) {
	String^ f = val.ToString("##0.0");
	while (f->Length < 5) {
		f = " " + f;
	}
	return f;
}

void MainForm::onTimer() {
	// 計測処理
	this->timer1->Enabled = false;
	MethaneData^ data = mainProc->onTimer();
	// 画面に表示している値の更新
	this->setMethaneConcentration(data->getC());
	this->setTemperature(data->getT());
	this->setBatRssiLevel(1, data->getBattery(1), data->getRssi(1));
	this->setBatRssiLevel(2, data->getBattery(2), data->getRssi(2));
	this->setTimeLabel(data->getDateString() + " " + data->getTimeString());
	if (data->status) {
		this->buttonStop->Enabled = true;
		this->buttonStart->Enabled = false;
		this->timer1->Enabled = true;
	}
	else {
		this->timer1->Enabled = false;
		this->buttonStart->Enabled = true;
		this->buttonStop->Enabled = false;
	}
}
//
// タイマー処理
System::Void MainForm::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	onTimer();
}
