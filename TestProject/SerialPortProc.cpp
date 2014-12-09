#include <Windows.h>
#include "SerialPortProc.h"
#include "LogFile.h"

using namespace System::Text;
using namespace System::Windows::Forms;
namespace MethaneGasConcentrationProject {

	SerialPortProc::SerialPortProc(SerialPort^  argSerialPort)
	{
		this->serialPort = argSerialPort;
		status_msg = gcnew array<array<String^>^>{
			{ "0000-0000", "エラーなし" },	// 0
			{ "0001-0000", "エラーなし" },	// 1
			{ "0001-0001", "SRAM読み書きエラー" },		// 2
			{ "0001-0002", "EEPROM読み書きエラー" },	// 3
			{ "0001-0003", "バッテリー電圧低下" },		// 4
			{ "0001-0004", "" },						// 5
			{ "0002-0000", "エラーなし" },				// 6
			{ "0002-0001", "コマンドフォーマットエラー" },	// 7
			{ "0002-0002", "チェックサム不一致" },		// 8
			{ "0002-0003", "受信タイムアウト" },		// 9
			{ "0002-0004", "コマンド処理中" },			// 10
			{ "0002-0005", "中継機が親機のコマンドを受信" },	// 11
			{ "0004-0000", "エラーなし" },				// 12
			{ "0004-0001", "無線通信中" },				// 13
			{ "0004-0002", "子機記録開始プロテクト" },	// 14
			{ "0004-0003", "無線通信がキャンセルされた" },	// 15
			{ "0004-0004", "中継機間の無線通信エラー" },	// 16
			{ "0004-0005", "子機間の無線通信エラー" },	// 17
			{ "0004-0006", "子機間の無線通信エラー" },	// 18
			{ "0004-0007", "記録開始までの秒数不足で記録開始ができない" },	// 19
			{ "0004-0008", "引数が不正" },				// 20
			{ "0004-0009", "データが存在しない" },		// 21
			{ "0004-0010", "吸い上げ未完了" },			// 22
			{ "0004-0021", "チャンネル使用中" },		// 23
			{ "0004-0099", "その他のエラー" },			// 24
			{ "0005-0000", "エラーなし" },				// 25
			{ "0005-0001", "子機からの応答がなかった" },	// 26
			{ "0005-0002", "引数が不正" },				// 27
			{ "0005-0003", "子機からのデータが不正" },	// 28
			{ "0005-0004", "子機がコマンドを拒否した" },	// 29
		};
		battery = gcnew array<int>(2);
		rssi = gcnew array<int>(2);

	}

	// COMポートオープン
	bool SerialPortProc::openPort(String^ port) {
		try {
			if (!serialPort->IsOpen) {
				serialPort->PortName = port;
				serialPort->Open();
				//serialPort->ReadTimeout = 5000;
				//serialPort->WriteTimeout = 5000;
			}
		}
		catch (System::Exception^ e){
			errorMsg = port + " がオープン出来ませんでした。通信ポート設定、親機との接続を確認して下さい";
			return false;
		}
		catch (InvalidOperationException^ e) {
			return false;
		}
		return true;
	}
	// COMポートクローズ
	void SerialPortProc::closePort() {
		try {
			serialPort->Close();
		}
		catch (System::Exception^ e){
			errorMsg = "通信ポートをクローズ出来ませんでした";
		}
	}
	// 子機にユニークIDを設定するコマンドを発行（EIREG)
	bool SerialPortProc::setUID(UCHAR num)
	{
		bool rc = false;
		BYTE cmd_param[] = { 'E', 'I', 'R', 'E', 'G', ':',
			'I', 'D', '=', 0x08, 0x00, 0, 0, 0, 0, 0, 0, 0, 0, 
			'N', 'A', 'M', 'E', '=', 0x08, 0x00, 'U', 'n', 'i', 't', '0', num, 0, 0,
			'N', 'U', 'M', '=', 0x01, 0x00, num,
			'C', 'H', '=', 0x01, 0x00, '0',
		};
		INT16 cs = 0;
		for (int i = 0; i < sizeof(cmd_param); i++) {
			cs += cmd_param[i];
		}
		INT16 len = sizeof(cmd_param);
		BYTE b1 = 0x00ff & cs;
		BYTE b2 = (0xff00 & cs) >> 8;
		BYTE b3 = 0x00ff & len;
		BYTE b4 = (0xff00 & len) >> 8;
		array<unsigned char>^ buf = gcnew array<unsigned char>(8192);
		buf[0] = 'T';
		buf[1] = '2';
		buf[2] = b3;
		buf[3] = b4;
		int i = 0;
		for (i = 0; i < sizeof(cmd_param); i++) {
			buf[i + 4] = cmd_param[i];
		}
		buf[4 + i++] = b1;
		buf[4 + i] = b2;
		try {
			serialPort->Write(buf, 0, buf->Length);
			serialPort->Read(buf, 0, buf->Length);
		}
		catch (IO::IOException^ e) {
			LogFile::writeFile("子機の設定時にエラーが発生しました。",true);

		}
		if (checkStatus(buf) == 25) {
			// OK
			rc = true;
		}
		else {
			LogFile::writeFile("子機の設定時にエラーが発生しました。" + status_msg[rc][0], true);

		}
		return rc;
	}
	// 中継機にユニークIDを設定するコマンドを発行（EIREG)
	bool SerialPortProc::setRelayUID(UCHAR num)
	{
		bool rc = false;
		BYTE cmd_param[] = { 'W', 'R', 'U', 'S', 'T', ':',
			'I', 'D', '=', 0x08, 0x00, 0, 0, 0, 0, 0, 0, 0, 0,
			'N', 'U', 'M', '=', 0x01, 0x00, num,
			'C', 'H', '=', 0x01, 0x00, '0',
		};
		INT16 cs = 0;
		for (int i = 0; i < sizeof(cmd_param); i++) {
			cs += cmd_param[i];
		}
		INT16 len = sizeof(cmd_param);
		BYTE b1 = 0x00ff & cs;
		BYTE b2 = (0xff00 & cs) >> 8;
		BYTE b3 = 0x00ff & len;
		BYTE b4 = (0xff00 & len) >> 8;
		array<unsigned char>^ buf = gcnew array<unsigned char>(8192);
		buf[0] = 'T';
		buf[1] = '2';
		buf[2] = b3;
		buf[3] = b4;
		int i = 0;
		for (i = 0; i < sizeof(cmd_param); i++) {
			buf[i + 4] = cmd_param[i];
		}
		buf[4 + i++] = b1;
		buf[4 + i] = b2;
		try {
			serialPort->Write(buf, 0, buf->Length);
			serialPort->Read(buf, 0, buf->Length);
		}
		catch (IO::IOException^ e) {
			LogFile::writeFile("中継機の設定時にエラーが発生しました。", true);

		}
		if (checkStatus(buf) == 6) {
			// OK
			rc = true;
		}
		else {
			LogFile::writeFile("中継機の設定時にエラーが発生しました。" + status_msg[rc][0], true);

		}
		return rc;
	}
	// 計測開始コマンド
	bool SerialPortProc::startTrendData(UCHAR no, UCHAR relay_no)
	{
		bool rtn = false;
		array<unsigned char>^ cmd_param0 = { 'E', 'W', 'C', 'U', 'R', ':', 'A', 'C', 'T', '=', 0x01, 0x00, '0',
			'C', 'H', '=', 0x01, 0x00, '0',
			'I', 'D', '=', 0x08, 0x00, 0, 0, 0, 0, 0, 0, 0, 0,
			'N', 'U', 'M', '=', 0x01, 0x00, no,
			'R', 'O', 'U', 'T', 'E', '=', 0x01, 0x00, '0',
			'F', 'O', 'R', 'M', 'A', 'T', '=', 0x01, 0x00, '5' };
		array<unsigned char>^ cmd_param = setRelayInfo(relay_no, cmd_param0);

		int device_no = no - '0';
		array<unsigned char>^ buf = gcnew array<unsigned char>(8192);
		errorMsg = "";
		rtn = sendCommand(buf, cmd_param, cmd_param->Length, device_no);
		//Sleep(2000);
		return rtn;
	}

	// 計測データ取得コマンド
	bool SerialPortProc::readTrendData(UCHAR no, UCHAR relay_no)
	{
		bool rtn = false;
		array<unsigned char>^ cmd_param0 = { 'E', 'W', 'C', 'U', 'R', ':', 'A', 'C', 'T', '=', 0x01, 0x00, '1'
			, 'C', 'H', '=', 0x01, 0x00, '0',
			'I', 'D', '=', 0x08, 0x00, 0, 0, 0, 0, 0, 0, 0, 0,
			'N', 'U', 'M', '=', 0x01, 0x00, no,
			'R', 'O', 'U', 'T', 'E', '=', 0x01, 0x00, '0',
			'F', 'O', 'R', 'M', 'A', 'T', '=', 0x01, 0x00, '5' };
		array<unsigned char>^ cmd_param = setRelayInfo(relay_no, cmd_param0);

		int device_no = no - '0';
		array<unsigned char>^ buf = gcnew array<unsigned char>(8192);
		int error_count = 0;
		errorMsg = "";
		if (sendCommand(buf, cmd_param, cmd_param->Length, device_no)) {
			// データ取得チェック
			rtn = checkResult(buf, "EWCUR");
		}
		return rtn;
	}
	array<byte>^ SerialPortProc::setRelayInfo(unsigned char relay_no, array<unsigned char>^ cmd_param) {
		BYTE relay0[] = { 'R', 'E', 'L', 'A', 'Y', '=', 0x01, 0x00, 0x00 };
		BYTE relay1[] = { 'R', 'E', 'L', 'A', 'Y', '=', 0x02, 0x00, 0x00, relay_no };
		int cmd_len = cmd_param->Length;
		if (relay_no == 0) {
			// 中継機なし
			cmd_len += sizeof(relay0);
		}
		else {
			// 中継機あり
			cmd_len += sizeof(relay1);
		}
		array<BYTE>^ result = gcnew array<unsigned char>(cmd_len);
		for (int i = 0; i < cmd_param->Length; i++) {
			result[i] = cmd_param[i];
		}
		if (relay_no == 0) {
			// 中継機なし
			for (int i = 0; i < sizeof(relay0); i++) {
				result[cmd_param->Length + i] = relay0[i];
			}
		}
		else {
			// 中継機あり
			for (int i = 0; i < sizeof(relay1); i++) {
				result[cmd_param->Length + i] = relay1[i];
			}
		}
		return result;
	}
	// コマンド送信
	bool SerialPortProc::sendCommand(array<byte>^ buf, array<byte>^ cmd_param, Int16 len, int device_no) {
		bool rtn = false;
		INT16 cs = 0;
		for (int i = 0; i < len; i++) {
			cs += cmd_param[i];
		}
		BYTE b1 = 0x00ff & cs;
		BYTE b2 = (0xff00 & cs) >> 8;
		BYTE b3 = 0x00ff & len;
		BYTE b4 = (0xff00 & len) >> 8;
		int error_count = 0;
		int read_retry = 0;
		try {
			int rc = 0;
			while (true) {
				buf[0] = 'T';
				buf[1] = '2';
				buf[2] = b3;
				buf[3] = b4;
				int i = 0;
				for (i = 0; i < len; i++) {
					buf[i + 4] = cmd_param[i];
				}
				buf[4 + i++] = b1;
				buf[4 + i] = b2;
				serialPort->Write(buf, 0, buf->Length);
				serialPort->Read(buf, 0, buf->Length);
				rc = checkStatus(buf);
				if (rc == 12){
					rtn = true;
					break;	// 正常終了
				}
				else if (rc == 13) {
					// 13は通信中
					read_retry++;
					if (read_retry >= 100) {
						errorLog(rc, device_no, error_count);
						break;
					}
					else {
						Sleep(500);
						continue;
					}
				}
				else if (rc == -1) {
					// データ取得
					rtn = true;
					break;
				}
				else if (rc == -2) {
					// 不正なデータ受信
					errorLog(rc, device_no, error_count);
					break;
				}
				else if (rc == 29) {
					// コマンド拒否
					errorLog(rc, device_no, error_count);
					break;
				}
				else if ((rc == 17) || (rc == 18)) {
					// 子機間通信エラー
					errorLog(rc, device_no, error_count);
					break;
				}
				else {
					// コマンドエラー
					errorLog(rc, device_no, error_count);
					break;
				}
			}

		}
		catch (System::TimeoutException^ e) {
			errorMsg = "COMポート通信タイムアウトが発生しました。";

		}
		catch (System::Exception^ e) {
			errorMsg = "子機[" + device_no + "]からのデータの取得時にI/Oエラーが発生しました。";

		}
		finally {
		}
		return rtn;
	}
	// エラー出力
	void SerialPortProc::errorLog(int rc, int device_no,int error_count) {
		if (rc == -2) {
			// 不正なデータ受信
			errorMsg = "通信エラーです。接続を確認して下さい[" + device_no + "]";
		}
		else if (rc == 29) {
			// コマンド拒否
			errorMsg = "子機[" + device_no + "]からのデータの取得時にコマンド拒否エラーが発生しました。" + status_msg[rc][0];
		}
		else if (rc == 13) {
			// 子機間通信中にタイムアウト
			errorMsg = "子機[" + device_no + "]からのデータの取得時にタイムアウトが発生しました。" + status_msg[rc][0];
		}
		else if ((rc == 17) || (rc == 18)) {
			// 子機間通信エラー
			errorMsg = "子機[" + device_no + "]からのデータの取得時に子機間通信エラーが発生しました。" + status_msg[rc][0];
		}
		else if (rc == 16) {
			// 中継機間通信エラー
			errorMsg = "子機[" + device_no + "]からのデータの取得時に中継機間の無線通信エラーが発生しました。" + status_msg[rc][0];
		}
		else {
			// コマンドエラー
			errorMsg = "子機[" + device_no + "]からのデータの取得時にコマンドエラーが発生しました。" + rc;
		}
	}
	// return -1:読込みデータ、0以上：ステータス番号
	int SerialPortProc::checkStatus(array<BYTE>^ buf)
	{
		int rc = -1;
		if (buf[0] == 'T' && buf[1] == '2') {
			ASCIIEncoding^ en = gcnew ASCIIEncoding();
			String^ stsStr = en->GetString(buf, 10, 6);
			if (String::Compare(stsStr, "STATUS") == 0) {
				String^ cmdStr = en->GetString(buf, 19, 9);
				for (int i = 0; i < status_msg->Length; i++) {
					String^ s = status_msg[i][0];
					if (String::Compare(cmdStr, s) == 0){
						rc = i;
						break;
					}

				}
			}
		}
		else {
			rc = -2;
		}
		return rc;
	}
	// 取得データの確認
	bool SerialPortProc::checkResult(array<BYTE>^ buf, String^ exeCmd)
	{
		bool rc = false;
		if (buf[0] == 'T' && buf[1] == '2') {
			Int16 bl = (Int16)buf[2];
			Int16 bu = (Int16)buf[3];
			Int16 len = bl + (bu * 255);
			ASCIIEncoding^ en = gcnew ASCIIEncoding();
			String^ cmdStr = en->GetString(buf, 4, 5);
			if (String::Compare(cmdStr, exeCmd) == 0){
				if (String::Compare("EWCUR", exeCmd) == 0) {
					// 子機から現在値読込みコマンドEWCUR
					rc = checkEWCUR_Result(buf, len);
				}
			}
		}
		return rc;
	}
	// 子機から現在値読込みコマンドEWCURの結果データ確認
	bool SerialPortProc::checkEWCUR_Result(array<BYTE>^ buf, INT16 len){
		bool rc = false;
		int rssi = 0;
		int bat = 0;
		String^ errMsg = "";
		for (int i = 9; i < len; i++){
			if (buf[i] == 'D') {
				int idx = i;
				if (buf[idx + 1] == 'A' && buf[idx + 2] == 'T' && buf[idx + 3] == 'A' && buf[idx + 4] == '=') {
					idx = idx + 7;
					BYTE num = buf[idx];
					BYTE rssi_value = buf[idx + 1];
					setRSSI(num,rssi_value);
					BYTE bat_value = buf[idx + 4];
					setBattery(num,bat_value & 0x0f);
					if (num == 1) {
						// 子機No1（温度）
						UInt16 tl = (UInt16)buf[idx + 28];
						UInt16 tu = (UInt16)buf[idx + 29];
						tu = tu << 8;
						UInt16 temp = tl + tu;
						if (temp == 0xeeee) {
							// センサ故障、未接続
							errMsg = "温度センサ故障、未接続 [" + temp + "]";
						}
						else if (temp == 0xF000) {
							// センサ故障、未接続
							errMsg = "温度センサ未測定データ [" + temp + "]";
						}
						else {
							setTemperature(temp);
							rc = true;
						}

					}
					else if (num == 2) {
						// 子機No2（電流）
						UInt16 ampl = (UInt16)buf[idx + 28];
						UInt16 ampu = (UInt16)buf[idx + 29];
						ampu = ampu << 8;
						UInt16 amp = ampl + ampu;
						if (amp == 0xf002) {
							// 測定値範囲外
							errMsg = "mAセンサ範囲外（オーバー） [" + amp + "]";
						}
						else if (amp == 0xf001) {
							errMsg = "mAセンサ範囲外（アンダー） [" + amp + "]";
						}
						else if (amp == 0xF00F) {
							errMsg = "mAセンサセンサ故障、未接続 [" + amp + "]";
						}
						else if (amp == 0xF000) {
							errMsg = "mAセンサ未測定データ [" + amp + "]";
						}
						else {
							setAmmeter(amp);
							rc = true;
						}
					}
					break;
				}
			}
		}
		if (!rc){
			if (errMsg == "") {
				errMsg = "計測データ取得エラー";
			}
			LogFile::writeFile(errMsg, false);
		}
		return rc;
	}

	void SerialPortProc::setRSSI(int no, BYTE v) {
		if (120 < v) {
			rssi[no -1] = 5;
		}
		else if ((100 < v) && (v <= 120)) {
			rssi[no - 1] = 4;
		}
		else if ((80 < v) && (v <= 100)) {
			rssi[no - 1] = 3;
		}
		else if ((60 < v) && (v <= 80)) {
			rssi[no - 1] = 2;
		}
		else if ((0 < v) && (v <= 60)) {
			rssi[no - 1] = 1;
		}
		else {
			rssi[no - 1] = 0;
		}

	}
	
	// 電波の強さ
	int SerialPortProc::getRSSI(int no) {
		return rssi[no - 1];
	}

	void SerialPortProc::setBattery(int no,BYTE v) {
		if (2 >= v) {
			battery[no - 1] = 5;
		}
		else if (v == 3) {
			battery[no - 1] = 4;
		}
		else if ((v == 4) || (v == 5)) {
			battery[no - 1] = 3;
		}
		else if ((v == 6) || (v == 7)) {
			battery[no - 1] = 2;
		}
		else if ((v == 8) || (v == 9)) {
			battery[no - 1] = 1;
		}
		else if ((v >= 10) && (v <= 15)) {
			battery[no - 1] = 0;
		}
	}

	// 電池残量
	int SerialPortProc::getBattery(int no) {
		return battery[no - 1];
	}

	void SerialPortProc::setTemperature(INT16 v) {
		float wk = (float)v;
		wk = (wk / 10) - 100;
		temperature = wk;
	}

	// 温度データ
	float SerialPortProc::getTemperature() {
		return temperature;
	}

	void SerialPortProc::setAmmeter(UInt16 v) {
		mA = (float)v / 100;
		return;
	}

	float SerialPortProc::getAmmeter() {
		return mA;
	}
	// エラーリトライ回数の設定
	void SerialPortProc::setErrorRetry(int val) {
		errorRetry = val;
	}
	// 中断フラグセット
	void SerialPortProc::setAbortFlag(bool val) {
		abortFlag = val;
	}
	bool SerialPortProc::checkStatus() {
		if (abortFlag) {
			return false;	// 中断フラグがセットされたら終わる
		}
		return true;
	}
	String^ SerialPortProc::getErrorMsg() {
		return errorMsg;
	}
}