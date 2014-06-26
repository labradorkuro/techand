#include "LogFile.h"
#include "LogForm.h"

using namespace System::IO;
using namespace System::Windows::Forms;

namespace MethaneGasConcentrationProject {

	LogFile::LogFile()
	{
	}
	int LogFile::writeFile(String^ log) {
		int rc = 0;
		String^ fileName = System::IO::Directory::GetCurrentDirectory() + "\\log.txt";
		// 現在時間取得
		DateTime^ now = DateTime::Now;
		String^ datetime = Convert::ToString(now);
		String^ str = datetime + " " + log;

		try
		{
			StreamWriter^ dout = File::AppendText(fileName);
			try {

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
			showMessage(datetime + " ログファイルの書込みが出来ませんでした");
			Console::WriteLine("problem writing file '{0}'", fileName);
			rc = -2;
		}
		showMessage(str);
		return rc;

	}
	void LogFile::showMessage(String^ log) {
		LogForm^ lf = gcnew LogForm(log);
		lf->ShowDialog();
	}
}