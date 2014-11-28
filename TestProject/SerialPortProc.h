#pragma once

using namespace System;
using namespace System::IO::Ports;

namespace MethaneGasConcentrationProject {
	public ref class SerialPortProc
	{
	private:
		bool abortFlag = false;
		array<int>^ battery;
		array<int>^ rssi;
		float temperature = 0;
		float mA = 0;
		SerialPort^  serialPort;
		array<array<String^>^>^ status_msg;
		int errorRetry = 3;
		String^ errorMsg = "";;
		bool checkResult(array<unsigned char>^ buf, String^ exeCmd);
		int checkStatus(array<unsigned char>^ buf);
		bool SerialPortProc::checkEWCUR_Result(array<unsigned char>^ buf, Int16 len);
		bool sendCommand(array<unsigned char>^ buf, array<unsigned char>^ cmd_param, Int16 len,int device_no);
		array<unsigned char>^ setRelayInfo(unsigned char relay_no, array<unsigned char>^ cmd_param);
		void errorLog(int rc, int device_no, int error_count);
	public:
		SerialPortProc(SerialPort^  argSerialPort);
		bool openPort(String^ port);
		void closePort();
		bool setUID(unsigned char num);
		bool setRelayUID(unsigned char no);
		bool startTrendData(unsigned char no, unsigned char relay_no);
		bool readTrendData(unsigned char no, unsigned char relay_no);
		int getRSSI(int no);
		void setRSSI(int no,unsigned char v);
		int getBattery(int no);
		void setBattery(int no,unsigned char v);
		float getTemperature();
		void setTemperature(Int16 v);
		float getAmmeter();
		void setAmmeter(UInt16 v);
		void setErrorRetry(int val);
		void setAbortFlag(bool val);
		bool checkStatus();
		String^ getErrorMsg();
	};
}
