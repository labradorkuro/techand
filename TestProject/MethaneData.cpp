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

}