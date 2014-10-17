#include <Windows.h>
#include "MainProc.h"
#include "LogFile.h"

using namespace System;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Diagnostics;

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
#ifdef LOG
		getProcessLog();
#endif
		MethaneData^ data = gcnew MethaneData();
		data->status = -1;
		if (serialPortProc->openPort(properties->getPortNo())) {
			int i = 0;
			// エラーの時は設定カウントまでリトライする
			for (i = 0; i < properties->getErrorRetry(); i++) {
				if (abort) {	// エラーリトライタイムアウトチェック
					data->status = -1;
					break;
				}
				// 計測データ取得
				data = getData();
				if (data->status == 0) {
					// 正常終了
					break;
				}
			}
			if (data->status == -1) {
				// エラー確定
				data->errorMsg = serialPortProc->getErrorMsg();
//				LogFile::writeFile(serialPortProc->getErrorMsg() + " (retry = " + i + ")", false);
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
			//LogFile::writeFile(serialPortProc->getErrorMsg() , false);
		}
		return data;
	}
	// データの取得処理
	MethaneData^ MainProc::getData() {
		// serialPortProc->setAmmeter(0x20E0);
		// 現在時間取得
		DateTime^ now = DateTime::Now;
		DateTime^ lastWeek = now->AddDays(-6);	// 1週間前から

		MethaneData^ data = gcnew MethaneData();
		String^ dataFolder = properties->getDataFolder() + "\\"; // dataフォルダー名
		// 日次データファイル名
		String^ dailyDataFileName = dataFolder + getDailyFileNameFromDateTime(now) + ".csv";
		// 月次データファイル名
		String^ MonthlyDataFileName = dataFolder + getMonthlyFileNameFromDateTime(now) + ".csv";
		// ここでおんどとりからデータを取得する
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
#ifdef DEBUG2
		temp = now->Minute; // debug
		rc1 = true; // debug
#endif
		float ammeter = 0;
#ifndef DEBUG		
		// 温度値の取得
#ifndef DEBUG2		
		if (!abort) {	// エラーリトライタイムアウトチェック
			if (serialPortProc->startTrendData('1')) {
				if (serialPortProc->readTrendData('1')) {
					temp = serialPortProc->getTemperature();
					data->setBattery(1, serialPortProc->getBattery(1));
					data->setRssi(1, serialPortProc->getRSSI(1));
					rc1 = true;
				}
			}
		}
#endif
		if (!abort) {	// エラーリトライタイムアウトチェック
			// 電流値の取得
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
			// メタン濃度温度補正値の計算
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
			// 日付と時間を分離
			array<String^>^ dt = datetime->Split(delimiter->ToCharArray());
			// データクラスに値をセット
			data->setDateString(dt[0]);
			data->setTimeString(dt[1]);
			data->setC0(c0);
			data->setC(methane);
			data->setT(temp);
			if ((trendData->Count == 0) || (!dataFile->existsFile(dailyDataFileName))) {
				// 日次データファイルがない場合（日付が変わったか、その日最初の起動時）
				// 過去1週間のデータを読込む
				trendData = gcnew Generic::List<MethaneData^>();
				DateTime^ wk = lastWeek;
				while (wk->CompareTo(now) < 0) {
					dailyDataFileName = dataFolder + getDailyFileNameFromDateTime(wk) + ".csv";
					dataFile->readFile(dailyDataFileName, trendData);
					wk = wk->AddDays(1);
				}
				errorCount = 0;	// エラー発生回数カウントのクリア
			}
			else {
				// 先頭のデータを削除
				if (trendData->Count > 1) {
					trendData->RemoveAt(0);
				}
			}
			// ファイル追加書き出し（ファイルがない時は新規作成される。）
			dailyDataFileName = dataFolder + getDailyFileNameFromDateTime(now) + ".csv";
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
			//trendChart->drawChart(todayData); // 2014.08.13 MainForm->displayItへ
			data->todayData = todayData; // 2014.08.13 dataにtodayDataを追加。描画をMainFormへ移すため
			//this->chart1->Series["温度"]->Points->Add()
			data->status = 0;
		}
		else {
			// エラー発生
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

	// リトライ処理中に計測時間になった場合に処理中の処理を終了させるためのフラグをセットする
	void MainProc::setAbortFlag(bool val)
	{
		abort = val;
		serialPortProc->setAbortFlag(val);
	}
	void MainProc::clearErrorCount() {
		errorCount = 0;
	
	}
#ifdef LOG
	void MainProc::getProcessLog()
	{
		// 自プロセスを取得
		Process^ currentProcess = Process::GetCurrentProcess();
		// リフレッシュしないとプロセスの各種情報が最新情報に更新されない
		currentProcess->Refresh();
		LogFile::writeFile2("物理メモリ使用量:" + currentProcess->WorkingSet64, false);
		LogFile::writeFile2("仮想メモリ使用量:" + currentProcess->VirtualMemorySize64, false);

	}

#endif
}