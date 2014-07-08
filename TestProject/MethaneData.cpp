/*
	データクラス
	date:2014.06.23
	author:Takenori Tanaka(niigata-sl.com)
*/

#include "MethaneData.h"
using namespace System;

namespace MethaneGasConcentrationProject {
	MethaneData::MethaneData()
	{
		battery = gcnew array<int>(2);
		rssi = gcnew array<int>(2);
	}
	void MethaneData::setDateString(String^ date) {
		dateString = date;
	}
	String^ MethaneData::getDateString() {
		return dateString;
	}
	void MethaneData::setTimeString(String^ time) {
		timeString = time;
	}
	String^ MethaneData::getTimeString() {
		return timeString;
	}
	void MethaneData::setC0(float v) {
		c0 = v;
	}
	float MethaneData::getC0() {
		return c0;
	}
	void MethaneData::setC(float v) {
		c = v;
	}
	float MethaneData::getC() {
		return c;
	}
	void MethaneData::setT(float v) {
		t = v;
	}
	float MethaneData::getT() {
		return t;
	}
	void MethaneData::setBattery(int no, int val) {
		battery[no - 1] = val;
	}

	int MethaneData::getBattery(int no) {
		return battery[no - 1];
	}
	void MethaneData::setRssi(int no, int val) {
		rssi[no - 1] = val;
	}

	int MethaneData::getRssi(int no) {
		return rssi[no - 1];
	}
}