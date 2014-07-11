/*
	�f�[�^�N���X
	date:2014.06.23
	author:Takenori Tanaka(niigata-sl.com)
*/
using namespace System;
#pragma once
namespace MethaneGasConcentrationProject {
	ref class MethaneData
	{
	private:
		System::String^ dateString;
		System::String^ timeString;
		float c0 = 0;	// ���^���Z�x
		float c = 0;	// ���^���Z�x���x�␳�l
		float t = 0;	// �K�X���x
		array<int>^ battery;	// �d�r�c��
		array<int>^ rssi;		// �d�g���x
	public:
		bool status = false;	// �v������

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
	};
	
}
