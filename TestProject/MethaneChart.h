/*
グラフ描画処理クラス
date:2014.06.23
author:Takenori Tanaka(niigata-sl.com)
*/

#include "MethaneData.h"

#pragma once
using namespace System::Windows::Forms::DataVisualization::Charting;
using namespace System::Data;
using namespace System::Collections::Generic;

namespace MethaneGasConcentrationProject {
	ref class MethaneChart
	{
	public:
		MethaneChart(Chart^ chart);
		void drawChart(List<MethaneData^>^ data);
			
	private:
		Chart^ methaneChart;
		void init();
		DataSet^ getDataSet(List<MethaneData^>^ data);

	};
}
