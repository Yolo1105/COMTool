#include "pch.h"
#include "SerialPortInfo.h"

#define TRACELOG

CSerialPortInfo::CSerialPortInfo(void)
{
    m_hComm = INVALID_HANDLE_VALUE;
}

CSerialPortInfo::~CSerialPortInfo(void)
{
    ClosePort();
}

BOOL CSerialPortInfo::OpenPort(UINT portNo, HANDLE& hComm)
{
    TCHAR szPort[50];
    _stprintf_s(szPort, _T("\\\\.\\COM%d"), portNo);

    hComm = CreateFile(szPort,		    /** 设备名,COM1,COM2等 */
        GENERIC_READ | GENERIC_WRITE,   /** 访问模式,可同时读写 */
        0,                              /** 共享模式,0表示不共享 */
        NULL,							/** 安全性设置,一般使用NULL */
        OPEN_EXISTING,					/** 该参数表示设备必须存在,否则创建失败 */
        FILE_ATTRIBUTE_NORMAL,
        0);

    if (hComm == INVALID_HANDLE_VALUE)
    {
        DWORD err = GetLastError();
        return FALSE;
    }

    return TRUE;
}

void CSerialPortInfo::ClosePort()
{
    if (m_hComm != INVALID_HANDLE_VALUE)
    {
        CloseHandle(m_hComm);
        m_hComm = INVALID_HANDLE_VALUE;
    }
}


void CSerialPortInfo::CommErrHandle(void)
{
    if (m_hComm == INVALID_HANDLE_VALUE)
    {
        return;
    }

    DWORD dwComErr = 0;
    COMSTAT comstat;

    ClearCommError(m_hComm, &dwComErr, &comstat);

    if ((dwComErr & CE_DNS) || \
        (dwComErr & CE_OOP) || \
        (dwComErr & CE_PTO))
    {
        TRACE(_T(" windows system device error \n"));
    }

    if ((dwComErr & CE_FRAME) ||
        (dwComErr & CE_RXPARITY))
    {
        TRACE(_T("Please Check Uart Property Setting !!!  \n"));
    }

    if (dwComErr & CE_IOE)
    {
        TRACE(_T("I/O err on communication with UART !!! \n"));
    }

    if (dwComErr & CE_TXFULL)
    {
        TRACE(_T("TX Buf full  \n"));
    }

    if (dwComErr & CE_RXOVER)
    {
        TRACE(_T("RX buf override \n"));
    }

    PurgeComm(m_hComm,  PURGE_TXCLEAR | PURGE_RXABORT | PURGE_TXABORT);

    return;
}

BOOL CSerialPortInfo::InitPort(UINT portNo /*= 1*/, UINT baud /*= CBR_9600*/, UINT flowType, char parity /*= 'N'*/,
    UINT databits /*= 8*/, UINT stopsbits /*= 1*/, DWORD dwCommEvents /*= EV_RXCHAR*/)
{
    CSingleLock lock(&m_mutex, TRUE);

    ClosePort();

    HANDLE hComm = INVALID_HANDLE_VALUE;
    m_hComm = INVALID_HANDLE_VALUE;

    if (!OpenPort(portNo, hComm))
    {
        return FALSE;
    }

    if (!SetupComm(hComm, 131072, 131072))
    {
        ClosePort();
        return FALSE;
    }

    COMMTIMEOUTS  CommTimeouts;
    CommTimeouts.ReadIntervalTimeout = MAXDWORD;
    CommTimeouts.ReadTotalTimeoutMultiplier = 0;
    CommTimeouts.ReadTotalTimeoutConstant = 0;
    CommTimeouts.WriteTotalTimeoutMultiplier = 0;
    CommTimeouts.WriteTotalTimeoutConstant = 0;

    if (!SetCommTimeouts(hComm, &CommTimeouts))
    {
        ClosePort();
        return FALSE;
    }

    DCB  dcb;
    GetCommState(hComm, &dcb);

    char szDCBparam[50];
    sprintf_s(szDCBparam, "baud=%d parity=%c data=%d stop=%d", baud, parity, databits, stopsbits);
    DWORD dwNum = MultiByteToWideChar(CP_ACP, 0, szDCBparam, -1, NULL, 0);
    wchar_t* pwText = new wchar_t[dwNum];
    MultiByteToWideChar(CP_ACP, 0, szDCBparam, -1, pwText, dwNum);
    BuildCommDCB(pwText, &dcb);
    delete[] pwText;

    dcb.fDsrSensitivity = FALSE;
    dcb.fTXContinueOnXoff = FALSE;
    dcb.fRtsControl = RTS_CONTROL_DISABLE;
    dcb.fDtrControl = DTR_CONTROL_ENABLE;

    switch (flowType)
    {
    case 2:
    {
        dcb.fOutxCtsFlow = FALSE;
        dcb.fOutxDsrFlow = FALSE;
        dcb.fOutX = FALSE;
        dcb.fInX = FALSE;
        break;
    }
    case 0:
    {
        dcb.fOutxCtsFlow = TRUE;
        dcb.fOutxDsrFlow = FALSE;
        dcb.fRtsControl = RTS_CONTROL_HANDSHAKE;
        dcb.fOutX = FALSE;
        dcb.fInX = FALSE;
        break;
    }
    case 1:
    {
        dcb.fOutxCtsFlow = FALSE;
        dcb.fOutxDsrFlow = FALSE;
        dcb.fOutX = TRUE;
        dcb.fInX = TRUE;
        dcb.XonChar = 0x11;
        dcb.XoffChar = 0x13;
        dcb.XoffLim = 100;
        dcb.XonLim = 100;
        break;
    }
    }

    if (!SetCommState(hComm, &dcb))
    {
        ClosePort();
        return FALSE;
    }

    PurgeComm(hComm, PURGE_TXCLEAR | PURGE_RXABORT | PURGE_TXABORT);

    SetCommMask(hComm, EV_RXCHAR | EV_ERR | EV_TXEMPTY);

    //CommErrHandle();

    m_hComm = hComm;

    return TRUE;
}

BOOL CSerialPortInfo::InitPort(UINT portNo, const LPDCB& plDCB)
{
    CSingleLock lock(&m_mutex, TRUE);

    if (!OpenPort(portNo, m_hComm))
    {
        return FALSE;
    }

    if (!SetCommState(m_hComm, plDCB))
    {
        return FALSE;
    }

    PurgeComm(m_hComm, PURGE_TXCLEAR | PURGE_RXABORT | PURGE_TXABORT);

    CommErrHandle();

    return TRUE;
}

void CSerialPortInfo::UnintPort()
{
    CSingleLock lock(&m_mutex, TRUE);
    ClosePort();
}

BOOL CSerialPortInfo::ReadData(char* pBuf, int buf_len, DWORD* BytesRead)
{
    CSingleLock lock(&m_mutex, TRUE);

    if (m_hComm == INVALID_HANDLE_VALUE)
    {
        return FALSE;
    }

    BOOL   bResult = TRUE;
    UINT32 nRemainlen = buf_len;
    UINT32 nCurrentLen = 0;

    do
    {
        bResult = ReadFile(m_hComm, pBuf + nCurrentLen, nRemainlen, (LPDWORD)BytesRead, NULL);
        if ((!bResult))
        {
            DWORD dwError = GetLastError();
            TRACELOG(_T("Read fail, last error = %d\n"), dwError);

            PurgeComm(m_hComm, PURGE_TXCLEAR | PURGE_TXABORT | PURGE_RXABORT);

            DWORD dwComErr = 0;
            COMSTAT comstat;
            ClearCommError(m_hComm, &dwComErr, &comstat);

            return FALSE;
        }

        nCurrentLen += *BytesRead;
        nRemainlen -= *BytesRead;

    } while (nRemainlen > 0);

    *BytesRead = buf_len;

    return TRUE;

}

BOOL CSerialPortInfo::WriteData(unsigned char* pData, unsigned int length)
{
    CSingleLock lock(&m_mutex, TRUE);
    if (m_hComm == INVALID_HANDLE_VALUE)
    {
        return FALSE;
    }

    BOOL   bResult = TRUE;
    DWORD  BytesToSend = 0;

    bResult = WriteFile(m_hComm, pData, length, &BytesToSend, NULL);

    if (!bResult || length != BytesToSend)
    {
        DWORD dwError = GetLastError();
        TRACELOG(_T("Write fail, last error = %d\n"), dwError);

        PurgeComm(m_hComm, PURGE_TXCLEAR | PURGE_TXABORT | PURGE_RXABORT);

        DWORD dwComErr = 0;
        COMSTAT comstat;
        ClearCommError(m_hComm, &dwComErr, &comstat);

        return FALSE;
    }

    return TRUE;
}

BOOL CSerialPortInfo::ClearUartRxBuffer()
{
    CSingleLock lock(&m_mutex, TRUE);
    if (m_hComm == INVALID_HANDLE_VALUE)
    {
        return FALSE;
    }

    BOOL   bResult = TRUE;
    DWORD  BytesToSend = 0;


    BOOL bRet = PurgeComm(m_hComm, PURGE_RXCLEAR | PURGE_RXABORT);

    return bRet;
}


int CSerialPortInfo::GetBytesInCOM()
{
    CSingleLock lock(&m_mutex, TRUE);
    if (m_hComm == INVALID_HANDLE_VALUE)
    {
        return FALSE;
    }

    UINT    BytesInQue = 0;
    DWORD   dwComErr = 0;
    COMSTAT comstat;

    memset(&comstat, 0, sizeof(COMSTAT));
    if (ClearCommError(m_hComm, &dwComErr, &comstat))
    {
        if (dwComErr & CE_RXOVER)
        {
            TRACELOG(_T("Error:Receive Queue overflow !!!"));
        }

        if (dwComErr & CE_OVERRUN)
        {
            TRACELOG(_T("Error:Receive Overrun Error !!!"));
        }

        if (dwComErr & CE_RXPARITY)
        {
            TRACELOG(_T("Error:Receive Parity Error !!!"));
        }

        if (dwComErr & CE_FRAME)
        {
            TRACELOG(_T("Error:Receive Framing error !!!"));
        }

        if (dwComErr & CE_BREAK)
        {
            TRACELOG(_T("Error:Break Detected !!!"));
        }

        if (dwComErr & CE_TXFULL)
        {
            TRACELOG(_T("Error:Break Detected !!!"));
        }

        if (dwComErr & CE_PTO)
        {
            TRACELOG(_T("Error:LPTx Timeout !!!"));
        }

        if (dwComErr & CE_IOE)
        {
            TRACELOG(_T("Error: LPTx I/O Error !!!"));
        }

        if (dwComErr & CE_DNS)
        {
            TRACELOG(_T("Error:LPTx Device not selected !!!"));
        }

        if (dwComErr & CE_OOP)
        {
            TRACELOG(_T("Error:LPTx Out-Of-Paper !!!"));
        }

        if (dwComErr & CE_MODE)
        {
            TRACELOG(_T("Error:Requested mode unsupported !!!"));
        }

        if (dwComErr & (CE_RXPARITY | CE_FRAME | CE_BREAK | CE_PTO | CE_IOE | CE_DNS | CE_OOP | CE_MODE))
        {
            BytesInQue = -1;
        }
        else
        {
            BytesInQue = comstat.cbInQue;
        }

    }
    else
    {
        TRACELOG(_T("Unkown error, last error = %d !!!"), GetLastError());
        BytesInQue = -1;
    }

    return BytesInQue;
}

BOOL CSerialPortInfo::IsOpen()
{
    CSingleLock lock(&m_mutex, TRUE);

    return m_hComm != INVALID_HANDLE_VALUE;
}
