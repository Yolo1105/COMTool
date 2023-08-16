#ifndef SERIALPORT_H_
#define SERIALPORT_H_

#include <Windows.h>


class CSerialPortInfo
{
public:
    CSerialPortInfo(void);
    ~CSerialPortInfo(void);

public:

    BOOL InitPort(UINT  portNo = 1, UINT  baud = 921600, UINT flowType = 2, char  parity = 'N', UINT  databits = 8,
        UINT  stopsbits = 1, DWORD dwCommEvents = EV_RXCHAR);

    BOOL InitPort(UINT  portNo, const LPDCB& plDCB);

    void UnintPort();

    BOOL WriteData(unsigned char* pData, unsigned int length);

    BOOL ReadData(char* pBuf, int buf_len, DWORD* BytesRead);

    BOOL ClearUartRxBuffer();

    int GetBytesInCOM();

    BOOL IsOpen();

private:
    BOOL OpenPort(UINT  portNo, HANDLE& hComm);

    void ClosePort();

    void CommErrHandle(void);

public:
    HANDLE  m_hComm;

    CMutex m_mutex;
};

#endif //SERIALPORT_H_