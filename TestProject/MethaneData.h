/*
	データクラス
	date:2014.06.23
	author:Takenori Tanaka(niigata-sl.com)
*/
using namespace System;
using namespace System::Collections::Generic;

#pragma once
namespace MethaneGasConcentrationProject {
	ref class MethaneData
	{
	private:
		System::String^ dateString;
		System::String^ timeString;
		float c0 = 0;	// メタン濃度
		float c = 0;	// メタン濃度温度補正値
		float t = 0;	// ガス温度
		array<int>^ battery;	// 電池残量
		array<int>^ rssi;		// 電波強度
	public:
		int status = 0;	// 計測結果
		String^ errorMsg = "";	// エラー時メッセージが入る 

		MethaneData();
		void setDateString(String^ date);
		String^ getDateString();
		void setTimeString(String^ time);
		String^ getTimeString();
		void setC0(float v);
		float getC0();
		void setC(float v);
		float getC();
		void setT(float v);
		float getT();
		void setBattery(int no, int val);
		int getBattery(int no);
		void setRssi(int no, int val);
		int getRssi(int no);
		List<MethaneData^>^ todayData; // 2014.08.13 追加

	};
	
}
