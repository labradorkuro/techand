/*
プロパティファイル処理クラス
date:2014.06.23
author:Takenori Tanaka(niigata-sl.com)
*/

#pragma once

namespace MethaneGasConcentrationProject {
	public ref class Properties
	{
	private:
		int	interval = 600000;			// Timer
		System::String^ dataFolder = "data";
		System::String^ portNo = "COM1";
		System::String^ propertyFileName = "mgc.properties";
	public:
		Properties();
		int readFile();
		int writeFile();
		void setInterval(int val);
		int getInterval();
		void setDataFolder(System::String^ folder);
		System::String^ getDataFolder();
		void setPortNo(System::String^ port);
		System::String^ getPortNo();
	};
}
