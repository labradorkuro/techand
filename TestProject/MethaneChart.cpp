/*
グラフ描画処理クラス
date:2014.06.23
author:Takenori Tanaka(niigata-sl.com)
*/

#include "MethaneChart.h"
#include "MethaneData.h"

using namespace System;
using namespace System::Windows::Forms::DataVisualization::Charting;
using namespace System::Data;
using namespace System::Collections::Generic;
using namespace System::Drawing;

namespace MethaneGasConcentrationProject {

	MethaneChart::MethaneChart(Chart^ chart)
	{
		methaneChart = chart;
		init();
	}
	void MethaneChart::init() {
		methaneChart->Series->Clear();
		methaneChart->Titles->Clear();
		methaneChart->ChartAreas->Clear();
		methaneChart->ChartAreas->Add("MethaneChart");
		Title^ t = methaneChart->Titles->Add("メタン濃度と温度");
		Font^ font = t->Font;
		t->Font = gcnew Font(font->Name, 14);
	}
	//
	// 渡されたデータをグラフデータとして描画する
	// data:データファイルから読込んだデータを格納したリスト
	void MethaneChart::drawChart(List<MethaneData^>^ data) {
		methaneChart->Series->Clear();
		DataSet^ ds = getDataSet(data);

		methaneChart->DataSource = ds;
		for (int i = 1; i < ds->Tables[0]->Columns->Count; i++) {
			String^ columnName = ds->Tables[0]->Columns[i]->ColumnName;
			methaneChart->Series->Add(columnName);
			methaneChart->Series[columnName]->ChartType = SeriesChartType::Line;
			if (String::Compare(columnName, "メタン濃度(%)") == 0) {
				methaneChart->Series[columnName]->Color = Color::Orange;
			}
			else if (String::Compare(columnName, "温度(℃)") == 0) {
				methaneChart->Series[columnName]->Color = Color::Blue;
			}
			else {
				methaneChart->Series[columnName]->Color = Color::Green;
			}
			methaneChart->Series[columnName]->XValueMember = ds->Tables[0]->Columns[0]->ColumnName;
			methaneChart->Series[columnName]->YValueMembers = columnName;
			methaneChart->Series[columnName]->BorderWidth = 3;
		
		}
		
		methaneChart->ChartAreas["MethaneChart"]->AxisX->Title = "日付時刻";
		methaneChart->ChartAreas["MethaneChart"]->AxisY->Title = "濃度/温度";
		methaneChart->DataBind();
	}

	//
	// 渡されたデータをグラフデータとして表示するためのDataSetにして返す
	// data:データファイルから読込んだデータを格納したリスト
	DataSet^ MethaneChart::getDataSet(List<MethaneData^>^ data) {
		DataSet^ ds = gcnew DataSet();
		DataTable^ dt = gcnew DataTable();
		DataRow^ dtRow;
		String^ name = "";
		Single^ v = 0.0f;
		dt->Columns->Add("タイムスタンプ", name->GetType());
		dt->Columns->Add("メタン濃度(%)", v->GetType());
		dt->Columns->Add("温度(℃)", v->GetType());
		ds->Tables->Add(dt);
		for (int i = 0; i < data->Count; i++) {
			MethaneData^ md = data[i];
			dtRow = ds->Tables[0]->NewRow();
			dtRow[0] = md->getDateString() + " " + md->getTimeString();
			dtRow[1] = md->getC();
			dtRow[2] = md->getT();
			ds->Tables[0]->Rows->Add(dtRow);

		}
		return ds;
	}

}