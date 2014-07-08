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
		// 日付と時間を分離
		array<String^>^ dt = datetime->Split(delimiter->ToCharArray());
		String^ fn = dt[0]->Replace("/", "_");
		// 日次データファイル名
		return fn;
	}

	String^ MainProc::getMonthlyFileNameFromDateTime(DateTime^ date) {
		String^ datetime = Convert::ToString(date);
		String^ delimiter = " ";
		String^ delimiter_ymd = "_";
		// 日付と時間を分離
		array<String^>^ dt = datetime->Split(delimiter->ToCharArray());
		String^ fn = dt[0]->Replace("/", "_");
		// 年、月、日を分離
		array<String^>^ ymd = fn->Split(delimiter_ymd->ToCharArray());
		// 月次データファイル名
		return ymd[0] + "_" + ymd[1];

	}

	// タイマー処理
	MethaneData^ MainProc::onTimer() {
		// 現在時間取得
		DateTime^ now = DateTime::Now;
		DateTime^ lastWeek = now->AddDays(-6);	// 1週間前から

		MethaneData^ data = gcnew MethaneData();
		// ここでおんどとりからデータを取得する
		bool rc1 = false;
		bool rc2 = false;
		float methane = 0;// now->Minute;
		float temp = 0;// now->Hour;
		float ammeter = 0;
		// 温度値の取得
		if (serialPortProc->openPort(properties->getPortNo())) {
			if (serialPortProc->startTrendData('1')) {
				if (serialPortProc->readTrendData('1')) {
					temp = serialPortProc->getTemperature();
					data->setBattery(1, serialPortProc->getBattery(1));
					data->setRssi(1, serialPortProc->getRSSI(1));
					rc1 = true;
				}

			}
			// 電流値の取得
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
			// 日付と時間を分離
			array<String^>^ dt = datetime->Split(delimiter->ToCharArray());
			// データクラスに値をセット
			data->setDateString(dt[0]);
			data->setTimeString(dt[1]);
			data->setC0(c0);
			data->setC(methane);
			data->setT(temp);
			String^ dataFolder = properties->getDataFolder() + "\\";
			// 日次データファイル名
			String^ dailyDataFileName = dataFolder + getDailyFileNameFromDateTime(now) + ".cvs";
			// 月次データファイル名
			String^ MonthlyDataFileName = dataFolder + getMonthlyFileNameFromDateTime(now) + ".cvs";
			if ((trendData->Count == 0) || (!dataFile->existsFile(dailyDataFileName))) {
				// 日次データファイルがない場合（日付が変わったか、その日最初の起動時）
				// 過去1週間のデータを読込む
				trendData = gcnew Generic::List<MethaneData^>();
				DateTime^ wk = lastWeek;
				while (wk->CompareTo(now) < 0) {
					dailyDataFileName = dataFolder + getDailyFileNameFromDateTime(wk) + ".cvs";
					dataFile->readFile(dailyDataFileName, trendData);
					wk = wk->AddDays(1);
				}

			}
			else {
				// 先頭のデータを削除
				if (trendData->Count > 1) {
					trendData->RemoveAt(0);
				}
			}
			// ファイル追加書き出し（ファイルがない時は新規作成される。）
			dailyDataFileName = dataFolder + getDailyFileNameFromDateTime(now) + ".cvs";
			int rc = dataFile->writeFile(MonthlyDataFileName, data);
			if (rc < 0) {
				// Error
			}
			rc = dataFile->writeFile(dailyDataFileName, data);
			if (rc < 0) {
				// Error
			}

			// グラフ表示用に当日のデータファイルを読込む
			todayData = gcnew Generic::List<MethaneData^>();
			todayData->AddRange(trendData);
			dataFile->readFile(dailyDataFileName, todayData);
			// グラフ描画
			trendChart->drawChart(todayData);

			//this->chart1->Series["温度"]->Points->Add()

		}
		return data;

	}
}