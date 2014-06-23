/*
	�f�[�^�t�@�C�������N���X
	date:2014.06.23
	author:Takenori Tanaka(niigata-sl.com)
*/
#include "DataFile.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections;
using namespace System::IO;


using namespace std;

namespace MethaneGasConcentrationProject {
	DataFile::DataFile()
	{
	}
	int DataFile::readFile(String^ fileName) {
		int rc = 0;
		try
		{
			StreamReader^ din = File::OpenText(fileName);
			try {

				String^ str;
				String^ delimStr = ",";
				array<Char>^ delimiter = delimStr->ToCharArray();
				datalist = gcnew Generic::List<MethaneData^>();
				while ((str = din->ReadLine()) != nullptr)
				{
					array<String^>^ line = str->Split(delimiter);
					if (line->Length == 5) {
						MethaneData^ md = gcnew MethaneData();
						md->setDateString(line[0]);
						md->setTimeString(line[1]);
						md->setC0(Convert::ToSingle(line[2]));
						md->setC(Convert::ToSingle(line[3]));
						md->setT(Convert::ToSingle(line[4]));
						datalist->Add(md);
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

	int DataFile::writeFile(String^ fileName, MethaneData^ data) {
		int rc = 0;
		try
		{
			StreamWriter^ dout = File::AppendText(fileName);
			try {

				String^ str = data->getDateString() + ","
					+ data->getTimeString() + ","
					+ data->getC0().ToString("F1") + ","
					+ data->getC().ToString("F1") + ","
					+ data->getT().ToString("F1");
				dout->WriteLine(str);
				dout->Flush();
			}
			finally
			{
				if (dout)
					delete (IDisposable^)dout;
			}
		}
		catch (Exception^ e)
		{
			Console::WriteLine("problem writing file '{0}'", fileName);
			rc = -2;
		}
		return rc;
	}

}
