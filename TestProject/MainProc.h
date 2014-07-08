/*
���C�������N���X
date:2014.06.23
author:Takenori Tanaka(niigata-sl.com)
*/
#include "Properties.h"
#include "DataFile.h"
#include "MethaneChart.h"
#include "SerialPortProc.h"
#pragma once

using namespace System::Collections;

namespace MethaneGasConcentrationProject {
	public ref class MainProc
	{
	public:
		MainProc(Chart^ c, SerialPort^ ArgSerialPort);
		MethaneData^ onTimer();
		int getInterval();
		static String^ getDailyFileNameFromDateTime(DateTime^ dt);
		static String^ getMonthlyFileNameFromDateTime(DateTime^ dt);
		Properties^ getProperties();
		int reloadProperties();
	private:
		SerialPortProc^ serialPortProc;
		Chart^ chart;
		Properties^ properties;
		DataFile^ dataFile;
		MethaneChart^ trendChart;
		List<MethaneData^>^ todayData;
		List<MethaneData^>^ trendData;
		System::Void readProperties(Chart^ c);
	};
}
