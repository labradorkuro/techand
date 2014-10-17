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
	//this->timer1->Enabled = false;
	//enableStartButton(false);
#ifdef LOG
	LogFile::writeFile2("計測開始", false);
#endif
	int error_count = 0;
	MethaneData^ data = mainProc->onTimer();
	// 画面に表示している値の更新
	BeginInvoke(gcnew DisplayItDelegate(this, &MainForm::displayIt), data);
#ifdef LOG
	LogFile::writeFile2("計測終了", false);
#endif
}

// スレッド処理内から画面を更新する
void MainForm::displayIt(MethaneData^ data) {
	if (data->status == 0) {
		this->setMethaneConcentration(data->getC());
		this->setTemperature(data->getT());
		this->setBatRssiLevel(1, data->getBattery(1), data->getRssi(1));
		this->setBatRssiLevel(2, data->getBattery(2), data->getRssi(2));
		this->setTimeLabel(data->getDateString() + " " + data->getTimeString());
		// グラフ描画
		if (data->todayData) {
#ifdef LOG
//			LogFile::writeFile2("グラフ描画開始", false);
#endif
			MethaneChart^ trendChart = gcnew MethaneChart(chart1);
			trendChart->drawChart(data->todayData);
#ifdef LOG
//			LogFile::writeFile2("グラフ描画終了", false);
#endif
		}
	}
	else if (data->status == -1) {
		if (!errorStop) {
			// エラー時（リトライ制限超過）は計測停止
			errorStop = true;
			this->timer1->Enabled = false;
			enableStartButton(true);
			LogFile::writeFile("エラーリトライ回数が制限を超えました。計測を停止します。", true);
		}
	}
	else if (data->status == -2) {
		if (!errorStop) {
			// エラー時（リトライ制限超過）は計測停止
			errorStop = true;
			this->timer1->Enabled = false;
			enableStartButton(true);
			LogFile::writeFile(data->errorMsg, true);
		}
	}

}

//
// タイマー処理
System::Void MainForm::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	if (commThread != nullptr) {
		if (commThread->IsAlive) {
			mainProc->setAbortFlag(true);
			commThread->Join();
		}
	}
	if (!errorStop) {
		// 2014.08.13 通信処理をスレッド化
		mainProc->setAbortFlag(false);
		commThread = gcnew Thread(gcnew ThreadStart(this, &MainForm::onTimer));
		commThread->IsBackground = true;	// バックグラウンド化してから起動
		commThread->Start();
	}
}


void MainForm::enableStartButton(bool enable) {
	if (enable) {
		this->buttonStop->Enabled = false;
		this->buttonStop->BackColor = Color::LightGray;
		this->buttonStart->Enabled = true;
		this->buttonStart->BackColor = Color::ForestGreen;

	}
	else {
		this->buttonStop->Enabled = true;
		this->buttonStop->BackColor = Color::Red;
		this->buttonStart->Enabled = false;
		this->buttonStart->BackColor = Color::LightGray;

	}
}

// 計測開始ボタンイベント
System::Void MainForm::buttonStart_Click(System::Object^  sender, System::EventArgs^  e) {
#ifdef LOG
	LogFile::writeFile2("計測開始ボタン押下", false);
#endif
	errorStop = false;	// エラーリトライ回数制限で停止した際にtrueになる
	mainProc->setAbortFlag(false);
	mainProc->clearErrorCount();
	int interval = mainProc->getInterval();
	this->timer1->Interval = interval;
	this->timer1->Enabled = true;
	enableStartButton(false);
	this->timer1_Tick(sender,e);
}
// 計測停止ボタンイベント
System::Void MainForm::buttonStop_Click(System::Object^  sender, System::EventArgs^  e) {
#ifdef LOG
	LogFile::writeFile2("計測停止ボタン押下", false);
#endif
	this->timer1->Enabled = false;
	this->buttonStop->Enabled = false;
	this->buttonStart->Enabled = true;
	enableStartButton(true);
}

