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
		readFile();
	}

	int Properties::readFile() {
		int rc = 0;

		String^ fileName = System::IO::Directory::GetCurrentDirectory() +"\\" + propertyFileName;
		try
		{
			StreamReader^ din = File::OpenText(fileName);
			try {

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
						if (prop->Length == 2) {
							if (String::Compare(prop[0], "Interval") == 0) {
								int number;
								bool result = Int32::TryParse(prop[1], number);
								if (result) {
									setInterval(number);
								}
								else {
									setInterval(600000);
								}
							}
							else if (String::Compare(prop[0], "DataFolder") == 0){
								setDataFolder(prop[1]);
							}
							else if (String::Compare(prop[0], "Port") == 0){
								setPortNo(prop[1]);
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

}
