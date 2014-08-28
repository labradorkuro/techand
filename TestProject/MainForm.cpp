/*
���C���t�H�[�������N���X
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
		label_temp_level->Text = "�d�g���x�F" + rssi + "  �d�r�c�ʁF" + bat;
		label_temp_level->Refresh();
	}
	else if (no == 2) {
		label_ammeter_level->Text = "�d�g���x�F" + rssi + "  �d�r�c�ʁF" + bat;
		label_ammeter_level->Refresh();
	}

}
void MainForm::setTimeLabel(String^ time) {
	labelTime->Text = "�v�����ԁF" + time;
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
	// �v������
	//this->timer1->Enabled = false;
	//enableStartButton(false);
	LogFile::writeFile("�v���J�n", false);
	int error_count = 0;
	MethaneData^ data = mainProc->onTimer();
	// ��ʂɕ\�����Ă���l�̍X�V
	BeginInvoke(gcnew DisplayItDelegate(this, &MainForm::displayIt), data);
	LogFile::writeFile("�v���I��", false);
}

// �X���b�h�����������ʂ��X�V����
void MainForm::displayIt(MethaneData^ data) {
	if (data->status == 0) {
		this->setMethaneConcentration(data->getC());
		this->setTemperature(data->getT());
		this->setBatRssiLevel(1, data->getBattery(1), data->getRssi(1));
		this->setBatRssiLevel(2, data->getBattery(2), data->getRssi(2));
		this->setTimeLabel(data->getDateString() + " " + data->getTimeString());
		// �O���t�`��
		if (data->todayData) {
			MethaneChart^ trendChart = gcnew MethaneChart(chart1);
			trendChart->drawChart(data->todayData);
		}
	}
	else if (data->status == -1) {
		if (!errorStop) {
			// �G���[���i���g���C�������߁j�͌v����~
			errorStop = true;
			this->timer1->Enabled = false;
			enableStartButton(true);
			LogFile::writeFile("�G���[���g���C�񐔂������𒴂��܂����B�v�����~���܂��B", true);
		}
	}
	else if (data->status == -2) {
		if (!errorStop) {
			// �G���[���i���g���C�������߁j�͌v����~
			errorStop = true;
			this->timer1->Enabled = false;
			enableStartButton(true);
			LogFile::writeFile(data->errorMsg, true);
		}
	}

}

//
// �^�C�}�[����
System::Void MainForm::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	if (commThread != nullptr) {
		if (commThread->IsAlive) {
			mainProc->setAbortFlag(true);
			commThread->Join();
		}
	}
	if (!errorStop) {
		// 2014.08.13 �ʐM�������X���b�h��
		mainProc->setAbortFlag(false);
		commThread = gcnew Thread(gcnew ThreadStart(this, &MainForm::onTimer));
		commThread->IsBackground = true;	// �o�b�N�O���E���h�����Ă���N��
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

// �v���J�n�{�^���C�x���g
System::Void MainForm::buttonStart_Click(System::Object^  sender, System::EventArgs^  e) {
	errorStop = false;	// �G���[���g���C�񐔐����Œ�~�����ۂ�true�ɂȂ�
	mainProc->setAbortFlag(false);
	mainProc->clearErrorCount();
	int interval = mainProc->getInterval();
	this->timer1->Interval = interval;
	this->timer1->Enabled = true;
	enableStartButton(false);
	this->timer1_Tick(sender,e);
}
// �v����~�{�^���C�x���g
System::Void MainForm::buttonStop_Click(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Enabled = false;
	this->buttonStop->Enabled = false;
	this->buttonStart->Enabled = true;
	enableStartButton(true);
}

