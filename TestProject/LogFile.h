/*
���O�t�@�C�������N���X
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
		static int writeFile(String^ log, bool show);
#ifdef LOG
		static int writeFile2(String^ log, bool show);
#endif
		static void showMessage(String^ log);
	private:
	};
}
