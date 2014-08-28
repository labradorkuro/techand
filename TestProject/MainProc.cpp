#include <Windows.h>
#include "MainProc.h"
#include "LogFile.h"

using namespace System;
using namespace System::Collections;
using namespace System::Windows::Forms;

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
		MethaneData^ data = gcnew MethaneData();
		data->status = -1;
		if (serialPortProc->openPort(properties->getPortNo())) {
			int i = 0;
			// �G���[�̎��͐ݒ�J�E���g�܂Ń��g���C����
			for (i = 0; i < properties->getErrorRetry(); i++) {
				if (abort) {	// �G���[���g���C�^�C���A�E�g�`�F�b�N
					data->status = -1;
					break;
				}
				// �v���f�[�^�擾
				data = getData();
				if (data->status == 0) {
					// ����I��
					break;
				}
			}
			if (data->status == -1) {
				// �G���[�m��
				LogFile::writeFile(serialPortProc->getErrorMsg() + " (retry = " + i + ")", false);
				errorCount++;
				if (errorCount >= properties->getRetryLimit()) {
					data->status = -1;
				}
				else {
					data->status = 1;
				}
			}
			serialPortProc->closePort();
		}
		else {
			data->status = -2;
			data->errorMsg = serialPortProc->getErrorMsg();
			LogFile::writeFile(serialPortProc->getErrorMsg() , false);
		}
		return data;
	}
	// �f�[�^�̎擾����
	MethaneData^ MainProc::getData() {
		// serialPortProc->setAmmeter(0x20E0);
		// ���ݎ��Ԏ擾
		DateTime^ now = DateTime::Now;
		DateTime^ lastWeek = now->AddDays(-6);	// 1�T�ԑO����

		MethaneData^ data = gcnew MethaneData();
		String^ dataFolder = properties->getDataFolder() + "\\"; // data�t�H���_�[��
		// �����f�[�^�t�@�C����
		String^ dailyDataFileName = dataFolder + getDailyFileNameFromDateTime(now) + ".csv";
		// �����f�[�^�t�@�C����
		String^ MonthlyDataFileName = dataFolder + getMonthlyFileNameFromDateTime(now) + ".csv";
		// �����ł���ǂƂ肩��f�[�^���擾����
		bool rc1 = false;
		bool rc2 = false;
		float methane = 0;
		float temp = 0;
#ifdef DEBUG
		methane = now->Second; // debug
		temp = now->Minute; // debug
		rc1 = true; // debug
		rc2 = true; // debug
#endif
		float ammeter = 0;
#ifndef DEBUG		
		// ���x�l�̎擾
		if (!abort) {	// �G���[���g���C�^�C���A�E�g�`�F�b�N
			if (serialPortProc->startTrendData('1')) {
				if (serialPortProc->readTrendData('1')) {
					temp = serialPortProc->getTemperature();
					data->setBattery(1, serialPortProc->getBattery(1));
					data->setRssi(1, serialPortProc->getRSSI(1));
					rc1 = true;
				}
			}
		}
		if (!abort) {	// �G���[���g���C�^�C���A�E�g�`�F�b�N
			// �d���l�̎擾
			if (serialPortProc->startTrendData('2')) {
				if (serialPortProc->readTrendData('2')) {
					ammeter = serialPortProc->getAmmeter();
					data->setBattery(2, serialPortProc->getBattery(2));
					data->setRssi(2, serialPortProc->getRSSI(2));
					rc2 = true;
				}
			}

		}

#endif
		if (rc1 && rc2) {
			// ���^���Z�x���x�␳�l�̌v�Z
			float rp = properties->temp_range_upper;
			float rn = properties->temp_range_lower;
			float d_c = 0;
			float c0 = 50 * (ammeter - 4) / 8;
			float d_t = temp - properties->temp_corrected_value;
			if (d_t < rn) d_c = -(properties->concentration_factor);
			else if (d_t > rp) d_c = properties->concentration_factor;
			else d_c = d_t * properties->temp_factor;
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
			if ((trendData->Count == 0) || (!dataFile->existsFile(dailyDataFileName))) {
				// �����f�[�^�t�@�C�����Ȃ��ꍇ�i���t���ς�������A���̓��ŏ��̋N�����j
				// �ߋ�1�T�Ԃ̃f�[�^��Ǎ���
				trendData = gcnew Generic::List<MethaneData^>();
				DateTime^ wk = lastWeek;
				while (wk->CompareTo(now) < 0) {
					dailyDataFileName = dataFolder + getDailyFileNameFromDateTime(wk) + ".csv";
					dataFile->readFile(dailyDataFileName, trendData);
					wk = wk->AddDays(1);
				}
				errorCount = 0;	// �G���[�����񐔃J�E���g�̃N���A
			}
			else {
				// �擪�̃f�[�^���폜
				if (trendData->Count > 1) {
					trendData->RemoveAt(0);
				}
			}
			// �t�@�C���ǉ������o���i�t�@�C�����Ȃ����͐V�K�쐬�����B�j
			dailyDataFileName = dataFolder + getDailyFileNameFromDateTime(now) + ".csv";
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
			//trendChart->drawChart(todayData); // 2014.08.13 MainForm->displayIt��
			data->todayData = todayData; // 2014.08.13 data��todayData��ǉ��B�`���MainForm�ֈڂ�����
			//this->chart1->Series["���x"]->Points->Add()
			data->status = 0;
		}
		else {
			// �G���[����
			if (!dataFile->existsFile(dailyDataFileName)) {
				dataFile->createFile(dailyDataFileName);
				errorCount = 0;
			}
			data->status = -1;
		}
#ifdef DEBUG
		data->status = 0;
#endif		
		return data;

	}

	// ���g���C�������Ɍv�����ԂɂȂ����ꍇ�ɏ������̏������I�������邽�߂̃t���O���Z�b�g����
	void MainProc::setAbortFlag(bool val)
	{
		abort = val;
		serialPortProc->setAbortFlag(val);
	}
	void MainProc::clearErrorCount() {
		errorCount = 0;

	}
}