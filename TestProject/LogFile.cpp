#include "LogFile.h"
#include "LogForm.h"

using namespace System::IO;
using namespace System::Windows::Forms;

namespace MethaneGasConcentrationProject {

	LogFile::LogFile()
	{
	}
	int LogFile::writeFile(String^ log, bool show) {
		int rc = 0;
		String^ fileName = System::IO::Directory::GetCurrentDirectory() + "\\log.txt";
		// ���ݎ��Ԏ擾
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
				if (dout) {
					dout->Close();
					delete (IDisposable^)dout;
				}
			}
		}
		catch (Exception^ e)
		{
			showMessage(datetime + " ���O�t�@�C���̏����݂��o���܂���ł���[" + log + "]");
			//Console::WriteLine("problem writing file '{0}'", fileName);
			rc = -1;
		}
		if (show) {
			showMessage(str);
		}
		return rc;

	}
	void LogFile::showMessage(String^ log) {
		LogForm^ lf = gcnew LogForm(log);
		lf->Show();
		//lf->ShowDialog();
	}
}