/*
プロパティファイル処理クラス
date:2014.06.23
author:Takenori Tanaka(niigata-sl.com)
*/

#pragma once

namespace MethaneGasConcentrationProject {
	public ref class Properties
	{
	private:
		int	interval = 600000;			// Timer
		System::String^ dataFolder = "data";
		System::String^ portNo = "COM1";
		System::String^ propertyFileName = "mgc.properties";
		int errorRetry = 50;			// 通信エラー時のリトライ回数
		int retryLimit = 144;	// 1日のエラー回数制限
		int relay_no = 0;			// 中継機番号 0の時は中継機なし
	public:
		int temp_corrected_value = 20;
		float concentration_factor = 2.3;
		float temp_range_upper = 10;
		float temp_range_lower = -10;
		float temp_factor = 0.23;

		Properties();
		int readFile();
		int writeFile();
		void setInterval(int val);
		int getInterval();
		void setDataFolder(System::String^ folder);
		System::String^ getDataFolder();
		void setPortNo(System::String^ port);
		System::String^ getPortNo();
		void setErrorRetry(int val);
		int getErrorRetry();
		void setRetryLimit(int val);
		int getRetryLimit();
		void setRelay_no(int no);
		int getRelay_no();
	};
}
