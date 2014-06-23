/*
データファイル処理クラス
date:2014.06.23
author:Takenori Tanaka(niigata-sl.com)
*/

#include "MethaneData.h"

#pragma once
namespace MethaneGasConcentrationProject {
	ref class DataFile
	{
	private:
		System::Collections::Generic::List<MethaneData^>^ datalist;

	public:
		DataFile();
		int readFile(String^ fileName);
		int writeFile(String^ fileName, MethaneData^ data);

	};
}

