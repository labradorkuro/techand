/*
ログファイル処理クラス
date:2014.06.23
author:Takenori Tanaka(niigata-sl.com)
*/
using namespace System;
#pragma once
namespace MethaneGasConcentrationProject {
	ref class LogFile
	{
	public:
		LogFile();
		static int writeFile(String^ log);
	private:
		static void showMessage(String^ log);
	};
}
