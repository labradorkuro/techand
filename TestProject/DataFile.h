/*
データファイル処理クラス
date:2014.06.23
author:Takenori Tanaka(niigata-sl.com)
*/

#include "MethaneData.h"
using namespace System::Collections::Generic;

#pragma once
namespace MethaneGasConcentrationProject {
	ref class DataFile
	{
	private:
		List<MethaneData^>^ datalist;

	public:
		DataFile();
		int readFile(String^ fileName, List<MethaneData^>^ datalist);
		int writeFile(String^ fileName, MethaneData^ data);
		int createFile(String^ fileName);
		bool existsFile(String^ fileName);
	};
}

