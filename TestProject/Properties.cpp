/*
プロパティファイル処理クラス
date:2014.06.23
author:Takenori Tanaka(niigata-sl.com)
*/

#include "Properties.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections;
using namespace System::IO;


using namespace std;


namespace MethaneGasConcentrationProject {
	Properties::Properties()
	{
		int rc = readFile();
		if (rc == -1) {
			// File Not Found
			setDataFolder(System::IO::Directory::GetCurrentDirectory() + "\\" + "data");
		}
	}

	int Properties::readFile() {
		int rc = 0;

		String^ fileName = System::IO::Directory::GetCurrentDirectory() +"\\" + propertyFileName;
		try
		{
			StreamReader^ din = File::OpenText(fileName);
			try {
				int number;

				String^ str;
				String^ delimStr = ",";
				array<Char>^ delimiter = delimStr->ToCharArray();
				String^ delimStrProp = ":";
				array<Char>^ delimiterProp = delimStrProp->ToCharArray();
				while ((str = din->ReadLine()) != nullptr)
				{
					array<String^>^ properties = str->Split(delimiter);
					for (int i = 0; i < properties->Length; i++) {
						array<String^>^ prop = properties[i]->Split(delimiterProp);
						if (prop->Length >= 2) {
							if (String::Compare(prop[0], "Interval") == 0) {
								bool result = Int32::TryParse(prop[1], number);
								if (result) {
									setInterval(number);
								}
								else {
									setInterval(600000);
								}
							}
							else if (String::Compare(prop[0], "DataFolder") == 0){
								String^ f = prop[1];
								for (int j = 2; j < prop->Length; j++) {
									f += ":" + prop[j];
								}
								setDataFolder(f);
							}
							else if (String::Compare(prop[0], "Port") == 0){
								setPortNo(prop[1]);
							}
							else if (String::Compare(prop[0], "ErrorRetry") == 0){
								bool result = Int32::TryParse(prop[1], number);
								if (result) {
									setErrorRetry(number);
								}
								else {
									setErrorRetry(3);
								}
							}
							else if (String::Compare(prop[0], "RetryLimit") == 0){
								bool result = Int32::TryParse(prop[1], number);
								if (result) {
									setRetryLimit(number);
								}
								else {
									setRetryLimit(3);
								}
							}
							else if (String::Compare(prop[0], "RelayNo") == 0){
								bool result = Int32::TryParse(prop[1], number);
								if (result) {
									setRelay_no(number);
								}
								else {
									setRelay_no(0);
								}
							}
						}
					}
				}
			}
			finally
			{
				if (din)
					delete (IDisposable^)din;
			}
		}
		catch (Exception^ e)
		{
			if (dynamic_cast<FileNotFoundException^>(e)) {
				Console::WriteLine("file '{0}' not found", fileName);
				rc = -1;
			}
			else {
				Console::WriteLine("problem reading file '{0}'", fileName);
				rc = -2;
			}
		}
		return rc;
	}
	int Properties::writeFile() {
		int rc = 0;
		String^ fileName = System::IO::Directory::GetCurrentDirectory() + "\\" + propertyFileName;
		try
		{
			String^ line = "Interval:" + getInterval() + ",DataFolder:" + getDataFolder() + ",Port:" + getPortNo()
				+ ",ErrorRetry:" + getErrorRetry() + ",RetryLimit:" + getRetryLimit() + ",RelayNo:" + getRelay_no();
			try {
				File::WriteAllText(fileName, line);
			}
			finally
			{
			}
		}
		catch (Exception^ e)
		{
			Console::WriteLine("problem writing file '{0}'", fileName);
			rc = -2;
		}
		return rc;
	}

	void Properties::setInterval(int val) {
		interval = val;
	}
	int Properties::getInterval() {
		return interval;
	}
	void Properties::setDataFolder(System::String^ folder) {
		dataFolder = folder;
	}
	System::String^ Properties::getDataFolder() {
		return dataFolder;
	}
	void Properties::setPortNo(System::String^ port) {
		portNo = port;
	}
	System::String^ Properties::getPortNo() {
		return portNo;
	}
	void Properties::setErrorRetry(int val) {
		errorRetry = val;
	}
	int Properties::getErrorRetry() {
		return errorRetry;
	}
	void Properties::setRetryLimit(int val) {
		retryLimit = val;
	}
	int Properties::getRetryLimit() {
		return retryLimit;
	}
	void Properties::setRelay_no(int val) {
		relay_no = val;
	}
	int Properties::getRelay_no() {
		return relay_no;
	}

}
