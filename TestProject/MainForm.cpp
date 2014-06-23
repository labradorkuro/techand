/*
メインフォーム処理クラス
date:2014.06.23
author:Takenori Tanaka(niigata-sl.com)
*/
#include "MainForm.h"

using namespace MethaneGasConcentrationProject;

[STAThreadAttribute]
int main() {
	MainForm ^fm = gcnew MainForm();
	fm->dataFileRead();
	fm->setMethaneConcentration(55.45f);
	fm->setTemperature(19.89f);
	fm->ShowDialog();
	return 0;
}
System::Void MainForm::readProperties() {
	properties = gcnew Properties();
}
int MainForm::dataFileRead() {
	return 0;
}
void MainForm::setMethaneConcentration(float val) {
	labelMethane->Text = val.ToString("F1");
}

void MainForm::setTemperature(float val) {
	labelTemp->Text = val.ToString("F1");

}
