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
			{ "0000-0000", "�G���[�Ȃ�" },	// 0
			{ "0001-0000", "�G���[�Ȃ�" },	// 1
			{ "0001-0001", "SRAM�ǂݏ����G���[" },		// 2
			{ "0001-0002", "EEPROM�ǂݏ����G���[" },	// 3
			{ "0001-0003", "�o�b�e���[�d���ቺ" },		// 4
			{ "0001-0004", "" },						// 5
			{ "0002-0000", "�G���[�Ȃ�" },				// 6
			{ "0002-0001", "�R�}���h�t�H�[�}�b�g�G���[" },	// 7
			{ "0002-0002", "�`�F�b�N�T���s��v" },		// 8
			{ "0002-0003", "��M�^�C���A�E�g" },		// 9
			{ "0002-0004", "�R�}���h������" },			// 10
			{ "0002-0005", "���p�@���e�@�̃R�}���h����M" },	// 11
			{ "0004-0000", "�G���[�Ȃ�" },				// 12
			{ "0004-0001", "�����ʐM��" },				// 13
			{ "0004-0002", "�q�@�L�^�J�n�v���e�N�g" },	// 14
			{ "0004-0003", "�����ʐM���L�����Z�����ꂽ" },	// 15
			{ "0004-0004", "���p�@�Ԃ̖����ʐM�G���[" },	// 16
			{ "0004-0005", "�q�@�Ԃ̖����ʐM�G���[" },	// 17
			{ "0004-0006", "�q�@�Ԃ̖����ʐM�G���[" },	// 18
			{ "0004-0007", "�L�^�J�n�܂ł̕b���s���ŋL�^�J�n���ł��Ȃ�" },	// 19
			{ "0004-0008", "�������s��" },				// 20
			{ "0004-0009", "�f�[�^�����݂��Ȃ�" },		// 21
			{ "0004-0010", "�z���グ������" },			// 22
			{ "0004-0021", "�`�����l���g�p��" },		// 23
			{ "0004-0099", "���̑��̃G���[" },			// 24
			{ "0005-0000", "�G���[�Ȃ�" },				// 25
			{ "0005-0001", "�q�@����̉������Ȃ�����" },	// 26
			{ "0005-0002", "�������s��" },				// 27
			{ "0005-0003", "�q�@����̃f�[�^���s��" },	// 28
			{ "0005-0004", "�q�@���R�}���h�����ۂ���" },	// 29
		};
		battery = gcnew array<int>(2);
		rssi = gcnew array<int>(2);

	}

	// COM�|�[�g�I�[�v��
	bool SerialPortProc::openPort(String^ port) {
		try {
			if (!serialPort->IsOpen) {
				serialPort->PortName = port;
				serialPort->Open();
				serialPort->ReadTimeout = 1000;
				serialPort->WriteTimeout = 1000;
			}
		}
		catch (System::Exception^ e){
			errorMsg = port + " ���I�[�v���o���܂���ł����B�ʐM�|�[�g�ݒ�A�e�@�Ƃ̐ڑ����m�F���ĉ�����";
			return false;
		}
		catch (InvalidOperationException^ e) {
			return false;
		}
		return true;
	}
	// COM�|�[�g�N���[�Y
	void SerialPortProc::closePort() {
		try {
			serialPort->Close();
		}
		catch (System::Exception^ e){
			errorMsg = "�ʐM�|�[�g���N���[�Y�o���܂���ł���";
		}
	}
	// �q�@�Ƀ��j�[�NID��ݒ肷��R�}���h�𔭍s�iEIREG)
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
			LogFile::writeFile("�q�@�̐ݒ莞�ɃG���[���������܂����B",true);

		}
		if (checkStatus(buf) == 25) {
			// OK
			rc = true;
		}
		else {
			LogFile::writeFile("�q�@�̐ݒ莞�ɃG���[���������܂����B" + status_msg[rc][0], true);

		}
		return rc;
	}
	// ���p�@�Ƀ��j�[�NID��ݒ肷��R�}���h�𔭍s�iEIREG)
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
			LogFile::writeFile("���p�@�̐ݒ莞�ɃG���[���������܂����B", true);

		}
		if (checkStatus(buf) == 6) {
			// OK
			rc = true;
		}
		else {
			LogFile::writeFile("���p�@�̐ݒ莞�ɃG���[���������܂����B" + status_msg[rc][0], true);

		}
		return rc;
	}
	// �v���J�n�R�}���h
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

	// �v���f�[�^�擾�R�}���h
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
			// �f�[�^�擾�`�F�b�N
			rtn = checkResult(buf, "EWCUR");
		}
		return rtn;
	}
	array<byte>^ SerialPortProc::setRelayInfo(unsigned char relay_no, array<unsigned char>^ cmd_param) {
		BYTE relay0[] = { 'R', 'E', 'L', 'A', 'Y', '=', 0x01, 0x00, 0x00 };
		BYTE relay1[] = { 'R', 'E', 'L', 'A', 'Y', '=', 0x02, 0x00, 0x00, relay_no };
		int cmd_len = cmd_param->Length;
		if (relay_no == 0) {
			// ���p�@�Ȃ�
			cmd_len += sizeof(relay0);
		}
		else {
			// ���p�@����
			cmd_len += sizeof(relay1);
		}
		array<BYTE>^ result = gcnew array<unsigned char>(cmd_len);
		for (int i = 0; i < cmd_param->Length; i++) {
			result[i] = cmd_param[i];
		}
		if (relay_no == 0) {
			// ���p�@�Ȃ�
			for (int i = 0; i < sizeof(relay0); i++) {
				result[cmd_param->Length + i] = relay0[i];
			}
		}
		else {
			// ���p�@����
			for (int i = 0; i < sizeof(relay1); i++) {
				result[cmd_param->Length + i] = relay1[i];
			}
		}
		return result;
	}
	// �R�}���h���M
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
					break;	// ����I��
				}
				else if (rc == 13) {
					// 13�͒ʐM��
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
					// �f�[�^�擾
					rtn = true;
					break;
				}
				else if (rc == -2) {
					// �s���ȃf�[�^��M
					errorLog(rc, device_no, error_count);
					break;
				}
				else if (rc == 29) {
					// �R�}���h����
					errorLog(rc, device_no, error_count);
					break;
				}
				else if ((rc == 17) || (rc == 18)) {
					// �q�@�ԒʐM�G���[
					errorLog(rc, device_no, error_count);
					break;
				}
				else {
					// �R�}���h�G���[
					errorLog(rc, device_no, error_count);
					break;
				}
			}

		}
		catch (System::TimeoutException^ e) {
			errorMsg = "COM�|�[�g�ʐM�^�C���A�E�g���������܂����B";

		}
		catch (System::Exception^ e) {
			errorMsg = "�q�@[" + device_no + "]����̃f�[�^�̎擾����I/O�G���[���������܂����B";

		}
		finally {
		}
		return rtn;
	}
	// �G���[�o��
	void SerialPortProc::errorLog(int rc, int device_no,int error_count) {
		if (rc == -2) {
			// �s���ȃf�[�^��M
			errorMsg = "�ʐM�G���[�ł��B�ڑ����m�F���ĉ�����[" + device_no + "]";
		}
		else if (rc == 29) {
			// �R�}���h����
			errorMsg = "�q�@[" + device_no + "]����̃f�[�^�̎擾���ɃR�}���h���ۃG���[���������܂����B" + status_msg[rc][0];
		}
		else if (rc == 13) {
			// �q�@�ԒʐM���Ƀ^�C���A�E�g
			errorMsg = "�q�@[" + device_no + "]����̃f�[�^�̎擾���Ƀ^�C���A�E�g���������܂����B" + status_msg[rc][0];
		}
		else if ((rc == 17) || (rc == 18)) {
			// �q�@�ԒʐM�G���[
			errorMsg = "�q�@[" + device_no + "]����̃f�[�^�̎擾���Ɏq�@�ԒʐM�G���[���������܂����B" + status_msg[rc][0];
		}
		else if (rc == 16) {
			// ���p�@�ԒʐM�G���[
			errorMsg = "�q�@[" + device_no + "]����̃f�[�^�̎擾���ɒ��p�@�Ԃ̖����ʐM�G���[���������܂����B" + status_msg[rc][0];
		}
		else {
			// �R�}���h�G���[
			errorMsg = "�q�@[" + device_no + "]����̃f�[�^�̎擾���ɃR�}���h�G���[���������܂����B" + rc;
		}
	}
	// return -1:�Ǎ��݃f�[�^�A0�ȏ�F�X�e�[�^�X�ԍ�
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
	// �擾�f�[�^�̊m�F
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
					// �q�@���猻�ݒl�Ǎ��݃R�}���hEWCUR
					rc = checkEWCUR_Result(buf, len);
				}
			}
		}
		return rc;
	}
	// �q�@���猻�ݒl�Ǎ��݃R�}���hEWCUR�̌��ʃf�[�^�m�F
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
						// �q�@No1�i���x�j
						UInt16 tl = (UInt16)buf[idx + 28];
						UInt16 tu = (UInt16)buf[idx + 29];
						tu = tu << 8;
						UInt16 temp = tl + tu;
						if (temp == 0xeeee) {
							// �Z���T�̏�A���ڑ�
							errMsg = "���x�Z���T�̏�A���ڑ� [" + temp + "]";
						}
						else if (temp == 0xF000) {
							// �Z���T�̏�A���ڑ�
							errMsg = "���x�Z���T������f�[�^ [" + temp + "]";
						}
						else {
							setTemperature(temp);
							rc = true;
						}

					}
					else if (num == 2) {
						// �q�@No2�i�d���j
						UInt16 ampl = (UInt16)buf[idx + 28];
						UInt16 ampu = (UInt16)buf[idx + 29];
						ampu = ampu << 8;
						UInt16 amp = ampl + ampu;
						if (amp == 0xf002) {
							// ����l�͈͊O
							errMsg = "mA�Z���T�͈͊O�i�I�[�o�[�j [" + amp + "]";
						}
						else if (amp == 0xf001) {
							errMsg = "mA�Z���T�͈͊O�i�A���_�[�j [" + amp + "]";
						}
						else if (amp == 0xF00F) {
							errMsg = "mA�Z���T�Z���T�̏�A���ڑ� [" + amp + "]";
						}
						else if (amp == 0xF000) {
							errMsg = "mA�Z���T������f�[�^ [" + amp + "]";
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
				errMsg = "�v���f�[�^�擾�G���[";
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
	
	// �d�g�̋���
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

	// �d�r�c��
	int SerialPortProc::getBattery(int no) {
		return battery[no - 1];
	}

	void SerialPortProc::setTemperature(INT16 v) {
		float wk = (float)v;
		wk = (wk / 10) - 100;
		temperature = wk;
	}

	// ���x�f�[�^
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
	// �G���[���g���C�񐔂̐ݒ�
	void SerialPortProc::setErrorRetry(int val) {
		errorRetry = val;
	}
	// ���f�t���O�Z�b�g
	void SerialPortProc::setAbortFlag(bool val) {
		abortFlag = val;
	}
	bool SerialPortProc::checkStatus() {
		if (abortFlag) {
			return false;	// ���f�t���O���Z�b�g���ꂽ��I���
		}
		return true;
	}
	String^ SerialPortProc::getErrorMsg() {
		return errorMsg;
	}
}