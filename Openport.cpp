// Openport.cpp: 实现文件
//

#include "pch.h"
#include "ATCOMMAND.h"
#include "afxdialogex.h"
#include "Openport.h"
#include "ATCOMMANDDLG.h"
#include "SerialPortInfo.h"

// Openport 对话框

IMPLEMENT_DYNAMIC(Openport, CDialogEx)

Openport::Openport(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

Openport::~Openport()
{
}

BOOL Openport::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_bd.SetWindowTextW(TEXT("9600"));

	CString ChildData;
	CATCOMMANDDlg* father = (CATCOMMANDDlg*)GetParent();

	if (father ->m_cspi.IsOpen()) {
		MessageBox(TEXT("请先关闭串口再重新连接！"));
		Openport::OnCancel();
	}

	add = true;
	PortSetting();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void Openport::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO3, m_sp);
	DDX_Control(pDX, IDC_BAUD, m_bd);
	DDX_Control(pDX, IDC_OC2, m_close);
	DDX_Control(pDX, IDC_OC, m_open);
}


BEGIN_MESSAGE_MAP(Openport, CDialogEx)
	ON_COMMAND(ID_SETTING_OPENPORT32781, &Openport::PortInfo)
	ON_CBN_SELCHANGE(IDC_COMBO3, &Openport::SerialPortCombo)
	ON_BN_CLICKED(IDC_OC, &Openport::OpenPort)
	ON_BN_CLICKED(IDC_OC2, &Openport::ClosePort)
END_MESSAGE_MAP()


// Openport 消息处理程序

void Openport::PortInfo()
{
	// TODO: 在此添加命令处理程序代码

}

void Openport::SerialPortCombo()
{
	// TODO: 在此添加控件通知处理程序代码
}


static UINT  openproc(LPVOID  lParam)
{
	Openport* pWnd = (Openport*)lParam;
	pWnd->openportthread();

	return 0;
}

void Openport::openportthread() {
	CString tempstr;
	CString uaport;
	CString ChildData;

	GetDlgItem(IDC_COMBO3)->GetWindowText(tempstr);
	CATCOMMANDDlg* father = (CATCOMMANDDlg*)GetParent();

	unsigned short naport;
	unsigned short naportnum;
	if (ports.GetSize() != portse.GetSize()) {
		PortSetting();
	}

	Openport::OnCancel();
}

static UINT  settingproc(LPVOID  lParam)
{
	Openport* pWnd = (Openport*)lParam;
	pWnd->portsettingthread();

	return 0;
}

void Openport::portsettingthread() {
	Openport::OnCancel();
}

void Openport::OpenPort()
{
	// TODO: 在此添加控件通知处理程序代码
	//AfxBeginThread(openproc, (LPVOID)this);

	//AfxBeginThread(settingproc, (LPVOID)this);
	CString uaport;
	CString ChildData;

	CATCOMMANDDlg* father = (CATCOMMANDDlg*)GetParent();

	unsigned short naport;
	unsigned short naportnum;
	if (ports.GetSize() != portse.GetSize()) {
		PortSetting();
	}

	m_sp.EnableWindow(false);
	m_bd.EnableWindow(false);

	this->m_sp.GetWindowText(ChildData);
	m_strchildport = ChildData.Mid(3); //存串口号

	this->m_bd.GetWindowText(ChildData);
	m_strchildbd = ChildData;		  //存波特率

	m_open.EnableWindow(false);

	CDialogEx::OnOK();
}



void Openport::PortSetting() {
	CATCOMMANDDlg* father = (CATCOMMANDDlg*)GetParent();
	ports.RemoveAll();
	portse.RemoveAll();
	portsu.RemoveAll();

	CString str;

	for (int i = 1; i < 256; i++)
	{
		CString sPort;
		sPort.Format(_T("\\\\.\\COM%d"), i);
		BOOL bSuccess = FALSE;
		HANDLE hPort = ::CreateFile(sPort, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, 0, 0);
		if (hPort == INVALID_HANDLE_VALUE)
		{
			DWORD dwError = GetLastError();

			if (dwError == ERROR_ACCESS_DENIED)
			{
				bSuccess = TRUE;
				portsu.Add(i);
			}
		}
		else
		{
			bSuccess = TRUE;
			portse.Add(i);
			CloseHandle(hPort);
		}
		if (bSuccess)
			ports.Add(i);
	}

	unsigned short uicounter, uisetcom;
	uicounter = ports.GetSize();

	if (add) {
		//所有存在的串口，加入combobox里
		if (uicounter > 0)
		{
			for (int i = 0; i < uicounter; i++)
			{
				uisetcom = ports.ElementAt(i);
				str.Format(_T("COM%d "), uisetcom);
				m_sp.AddString(str);
				m_vecports.push_back(str);
			}
		}
		m_sp.SetCurSel(0);
		add = false;
		totalport = ports.GetSize();
	}
}

void Openport::ClosePort()
{
	// TODO: 在此添加控件通知处理程序代码
	Openport::OnCancel();
}
