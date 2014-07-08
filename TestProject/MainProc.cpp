#include "MainProc.h"
using namespace System::Collections;

namespace MethaneGasConcentrationProject {

	MainProc::MainProc(Chart^ c, SerialPort^ argSerialPort)
	{
		readProperties(c);
		//onTimer();
		serialPortProc = gcnew SerialPortProc(argSerialPort);
		//serialPortProc->getUID();
		//		serialPortProc->getSettings();
	}
	
	System::Void MainProc::readProperties(Chart^ c) {
		properties = gcnew Properties();
		dataFile = gcnew DataFile();
		trendData = gcnew Generic::List<MethaneData^>();
		trendChart = gcnew MethaneChart(c);

		trendChart->drawChart(trendData);

	}
	int MainProc::reloadProperties() {
		return properties->readFile();
	}
	Properties^ MainProc::getProperties() {
		return properties;
	}
	int MainProc::getInterval() {
		return properties->getInterval();
	}
	String^ MainProc::getDailyFileNameFromDateTime(DateTime^ date) {
		String^ datetime = Convert::ToString(date);
		String^ delimiter = " ";
		String^ delimiter_ymd = "_";
		// ���t�Ǝ��Ԃ𕪗�
		array<String^>^ dt = datetime->Split(delimiter->ToCharArray());
		String^ fn = dt[0]->Replace("/", "_");
		// �����f�[�^�t�@�C����
		return fn;
	}

	String^ MainProc::getMonthlyFileNameFromDateTime(DateTime^ date) {
		String^ datetime = Convert::ToString(date);
		String^ delimiter = " ";
		String^ delimiter_ymd = "_";
		// ���t�Ǝ��Ԃ𕪗�
		array<String^>^ dt = datetime->Split(delimiter->ToCharArray());
		String^ fn = dt[0]->Replace("/", "_");
		// �N�A���A���𕪗�
		array<String^>^ ymd = fn->Split(delimiter_ymd->ToCharArray());
		// �����f�[�^�t�@�C����
		return ymd[0] + "_" + ymd[1];

	}

	// �^�C�}�[����
	MethaneData^ MainProc::onTimer() {
		// ���ݎ��Ԏ擾
		DateTime^ now = DateTime::Now;
		DateTime^ lastWeek = now->AddDays(-6);	// 1�T�ԑO����

		MethaneData^ data = gcnew MethaneData();
		// �����ł���ǂƂ肩��f�[�^���擾����
		bool rc1 = false;
		bool rc2 = false;
		float methane = 0;// now->Minute;
		float temp = 0;// now->Hour;
		float ammeter = 0;
		// ���x�l�̎擾
		if (serialPortProc->openPort(properties->getPortNo())) {
			if (serialPortProc->startTrendData('1')) {
				if (serialPortProc->readTrendData('1')) {
					temp = serialPortProc->getTemperature();
					data->setBattery(1, serialPortProc->getBattery(1));
					data->setRssi(1, serialPortProc->getRSSI(1));
					rc1 = true;
				}

			}
			// �d���l�̎擾
			if (serialPortProc->startTrendData('2')) {
				if (serialPortProc->readTrendData('2')) {
					ammeter = serialPortProc->getAmmeter();
					data->setBattery(2, serialPortProc->getBattery(2));
					data->setRssi(2, serialPortProc->getRSSI(2));
					rc2 = true;
				}

			}
			serialPortProc->closePort();
		}
		if (rc1 && rc2) {
			float rp = 10;
			float rn = -10;
			float d_c = 0;
			float c0 = 50 * (ammeter - 4) / 8;
			float d_t = temp - 20;
			if (d_t < rn) d_c = -2.3;
			else if (d_t > rp) d_c = 2.3;
			else d_c = d_t * 0.23;
			methane = c0 + d_c;

			String^ datetime = Convert::ToString(now);
			String^ delimiter = " ";
			String^ delimiter_ymd = "_";
			// ���t�Ǝ��Ԃ𕪗�
			array<String^>^ dt = datetime->Split(delimiter->ToCharArray());
			// �f�[�^�N���X�ɒl���Z�b�g
			data->setDateString(dt[0]);
			data->setTimeString(dt[1]);
			data->setC0(c0);
			data->setC(methane);
			data->setT(temp);
			String^ dataFolder = properties->getDataFolder() + "\\";
			// �����f�[�^�t�@�C����
			String^ dailyDataFileName = dataFolder + getDailyFileNameFromDateTime(now) + ".cvs";
			// �����f�[�^�t�@�C����
			String^ MonthlyDataFileName = dataFolder + getMonthlyFileNameFromDateTime(now) + ".cvs";
			if ((trendData->Count == 0) || (!dataFile->existsFile(dailyDataFileName))) {
				// �����f�[�^�t�@�C�����Ȃ��ꍇ�i���t���ς�������A���̓��ŏ��̋N�����j
				// �ߋ�1�T�Ԃ̃f�[�^��Ǎ���
				trendData = gcnew Generic::List<MethaneData^>();
				DateTime^ wk = lastWeek;
				while (wk->CompareTo(now) < 0) {
					dailyDataFileName = dataFolder + getDailyFileNameFromDateTime(wk) + ".cvs";
					dataFile->readFile(dailyDataFileName, trendData);
					wk = wk->AddDays(1);
				}

			}
			else {
				// �擪�̃f�[�^���폜
				if (trendData->Count > 1) {
					trendData->RemoveAt(0);
				}
			}
			// �t�@�C���ǉ������o���i�t�@�C�����Ȃ����͐V�K�쐬�����B�j
			dailyDataFileName = dataFolder + getDailyFileNameFromDateTime(now) + ".cvs";
			int rc = dataFile->writeFile(MonthlyDataFileName, data);
			if (rc < 0) {
				// Error
			}
			rc = dataFile->writeFile(dailyDataFileName, data);
			if (rc < 0) {
				// Error
			}

			// �O���t�\���p�ɓ����̃f�[�^�t�@�C����Ǎ���
			todayData = gcnew Generic::List<MethaneData^>();
			todayData->AddRange(trendData);
			dataFile->readFile(dailyDataFileName, todayData);
			// �O���t�`��
			trendChart->drawChart(todayData);

			//this->chart1->Series["���x"]->Points->Add()

		}
		return data;

	}
}