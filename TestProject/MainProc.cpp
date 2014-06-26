#include "MainProc.h"
using namespace System::Collections;

namespace MethaneGasConcentrationProject {

	MainProc::MainProc(Chart^ c)
	{
		readProperties(c);
		//onTimer();
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

		// �����ł���ǂƂ肩��f�[�^���擾����
		float methane = now->Minute;
		float temp = now->Hour;
		float corrected = 21.23;


		String^ datetime = Convert::ToString(now);
		String^ delimiter = " ";
		String^ delimiter_ymd = "_";
		// ���t�Ǝ��Ԃ𕪗�
		array<String^>^ dt = datetime->Split(delimiter->ToCharArray());
		// �f�[�^�N���X�ɒl���Z�b�g
		MethaneData^ data = gcnew MethaneData();
		data->setDateString(dt[0]);
		data->setTimeString(dt[1]);
		data->setC0(methane);
		data->setC(corrected);
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
		return data;
	}
}