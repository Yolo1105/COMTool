
// ATCOMMANDDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "ATCOMMAND.h"
#include "ATCOMMANDDlg.h"
#include "afxdialogex.h"
#include "SerialPortInfo.h"
#include "Openport.h"
#include "Note.h"
#include "dbt.h"
#include <fstream>
#include <vector>

#define TRACELOG
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

CATCOMMANDDlg::CATCOMMANDDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ATCOMMAND_DIALOG, pParent)
	, m_str(_T(""))
	, m_strtext(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CATCOMMANDDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_text);
	DDX_Control(pDX, IDC_CHECK1, m_loop);
	DDX_Control(pDX, IDC_LOOP, m_loopcount);
	DDX_Control(pDX, IDC_LINE1, m_line1);
	DDX_Control(pDX, IDC_LINE2, m_line2);
	DDX_Control(pDX, IDC_LINE3, m_line3);
	DDX_Control(pDX, IDC_LINE4, m_line4);
	DDX_Control(pDX, IDC_LINE5, m_line5);
	DDX_Control(pDX, IDC_LINE6, m_line6);
	DDX_Control(pDX, IDC_LINE7, m_line7);
	DDX_Control(pDX, IDC_LINE8, m_line8);
	DDX_Control(pDX, IDC_LINE9, m_line9);
	DDX_Control(pDX, IDC_LINE10, m_line10);
	DDX_Control(pDX, IDC_HISTORY, m_histroy);
	DDX_Control(pDX, IDC_STATE1, m_check1);
	DDX_Control(pDX, IDC_LINE11, m_line11);
	DDX_Control(pDX, IDC_LINE12, m_line12);
	DDX_Control(pDX, IDC_LINE13, m_line13);
	DDX_Control(pDX, IDC_LINE15, m_line14);
	DDX_Control(pDX, IDC_LINE14, m_line15);
	DDX_Control(pDX, IDC_TIME11, m_wait11);
	DDX_Control(pDX, IDC_TIME12, m_wait12);
	DDX_Control(pDX, IDC_TIME13, m_wait13);
	DDX_Control(pDX, IDC_TIME15, m_wait15);
	DDX_Control(pDX, IDC_TIME14, m_wait14);
	DDX_Control(pDX, IDC_BTAT1, m_at1);
	DDX_Control(pDX, IDC_BTAT2, m_at2);
	DDX_Control(pDX, IDC_BTAT3, m_at3);
	DDX_Control(pDX, IDC_BTAT4, m_at4);
	DDX_Control(pDX, IDC_BTAT5, m_at5);
	DDX_Control(pDX, IDC_BTAT6, m_at6);
	DDX_Control(pDX, IDC_BTAT7, m_at7);
	DDX_Control(pDX, IDC_BTAT8, m_at8);
	DDX_Control(pDX, IDC_BTAT9, m_at9);
	DDX_Control(pDX, IDC_BTAT10, m_at10);
	DDX_Control(pDX, IDC_BTAT11, m_at11);
	DDX_Control(pDX, IDC_BTAT12, m_at12);
	DDX_Control(pDX, IDC_BTAT13, m_at13);
	DDX_Control(pDX, IDC_BTAT14, m_at14);
	DDX_Control(pDX, IDC_BTAT15, m_at15);
	DDX_Control(pDX, IDC_TIME1, m_time1);
	DDX_Control(pDX, IDC_TIME2, m_time2);
	DDX_Control(pDX, IDC_TIME3, m_time3);
	DDX_Control(pDX, IDC_TIME4, m_time4);
	DDX_Control(pDX, IDC_TIME5, m_time5);
	DDX_Control(pDX, IDC_TIME6, m_time6);
	DDX_Control(pDX, IDC_TIME7, m_time7);
	DDX_Control(pDX, IDC_TIME8, m_time8);
	DDX_Control(pDX, IDC_TIME9, m_time9);
	DDX_Control(pDX, IDC_TIME10, m_time10);
	DDX_Control(pDX, IDC_CHECK14, m_checkbox);
	DDX_Control(pDX, IDC_SEND, m_send);
	DDX_Text(pDX, IDC_EDIT1, m_strtext);
	DDX_Control(pDX, IDC_STATE2, m_check2);
	DDX_Control(pDX, IDC_STATE3, m_check3);
	DDX_Control(pDX, IDC_STATE4, m_check4);
	DDX_Control(pDX, IDC_STATE5, m_check5);
	DDX_Control(pDX, IDC_STATE6, m_check6);
	DDX_Control(pDX, IDC_STATE7, m_check7);
	DDX_Control(pDX, IDC_STATE8, m_check8);
	DDX_Control(pDX, IDC_STATE9, m_check9);
	DDX_Control(pDX, IDC_STATE10, m_check10);
	DDX_Control(pDX, IDC_STATE11, m_check11);
	DDX_Control(pDX, IDC_STATE12, m_check12);
	DDX_Control(pDX, IDC_STATE13, m_check13);
	DDX_Control(pDX, IDC_STATE14, m_check14);
	DDX_Control(pDX, IDC_STATE15, m_check15);
	DDX_Control(pDX, IDC_BUTTON25, m_reset);
}

BEGIN_MESSAGE_MAP(CATCOMMANDDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SEND, &CATCOMMANDDlg::OnBnClickedSend)
	ON_BN_CLICKED(IDC_CHECK14, &CATCOMMANDDlg::LoopSend)
	ON_COMMAND(ID_SETTING_OPENPORT32781, &CATCOMMANDDlg::OpenPortBT)
	ON_COMMAND(ID_SETTING_CLOSEPORT32787, &CATCOMMANDDlg::ClosePort)
	ON_COMMAND(ID_SETTING_SAVELOG, &CATCOMMANDDlg::ClearLog)
	ON_COMMAND(ID_SETTING_IMPORTAT, &CATCOMMANDDlg::SaveLog)
	ON_COMMAND(ID_SETTING_EXIT32784, &CATCOMMANDDlg::Exit)
	ON_COMMAND(ID_SETTING_EXIT, &CATCOMMANDDlg::ImportAT)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_SETTING_EXPORTAT32782, &CATCOMMANDDlg::ExportAt)
	ON_BN_CLICKED(IDC_BTAT1, &CATCOMMANDDlg::OnBnClickedBtat1)
	ON_BN_CLICKED(IDC_BTAT2, &CATCOMMANDDlg::OnBnClickedBtat2)
	ON_BN_CLICKED(IDC_BTAT3, &CATCOMMANDDlg::OnBnClickedBtat3)
	ON_BN_CLICKED(IDC_BTAT4, &CATCOMMANDDlg::OnBnClickedBtat4)
	ON_BN_CLICKED(IDC_BTAT5, &CATCOMMANDDlg::OnBnClickedBtat5)
	ON_BN_CLICKED(IDC_BTAT6, &CATCOMMANDDlg::OnBnClickedBtat6)
	ON_BN_CLICKED(IDC_BTAT7, &CATCOMMANDDlg::OnBnClickedBtat7)
	ON_BN_CLICKED(IDC_BTAT8, &CATCOMMANDDlg::OnBnClickedBtat8)
	ON_BN_CLICKED(IDC_BTAT9, &CATCOMMANDDlg::OnBnClickedBtat9)
	ON_BN_CLICKED(IDC_BTAT10, &CATCOMMANDDlg::OnBnClickedBtat10)
	ON_BN_CLICKED(IDC_BTAT11, &CATCOMMANDDlg::OnBnClickedBtat11)
	ON_BN_CLICKED(IDC_BTAT12, &CATCOMMANDDlg::OnBnClickedBtat12)
	ON_BN_CLICKED(IDC_BTAT13, &CATCOMMANDDlg::OnBnClickedBtat13)
	ON_BN_CLICKED(IDC_BTAT14, &CATCOMMANDDlg::OnBnClickedBtat14)
	ON_BN_CLICKED(IDC_BTAT15, &CATCOMMANDDlg::OnBnClickedBtat15)
	ON_EN_CHANGE(IDC_LOOP, &CATCOMMANDDlg::OnEnChangeLoop)
	ON_WM_DEVICECHANGE()
	ON_EN_SETFOCUS(IDC_EDIT1, &CATCOMMANDDlg::OnEnSetfocusEdit1)
	ON_EN_CHANGE(IDC_EDIT1, &CATCOMMANDDlg::OnEnChangeEdit1)
	ON_COMMAND(IDR_TOOL1, &CATCOMMANDDlg::OnIdrTool1)
	ON_COMMAND(IDR_TOOL2, &CATCOMMANDDlg::OnIdrTool2)
	ON_COMMAND(IDR_TOOL3, &CATCOMMANDDlg::OnIdrTool3)
	ON_COMMAND(IDR_TOOL4, &CATCOMMANDDlg::OnIdrTool4)
	ON_COMMAND(IDR_TOOL5, &CATCOMMANDDlg::OnIdrTool5)
	ON_COMMAND(IDR_TOOL6, &CATCOMMANDDlg::OnIdrTool6)
	ON_NOTIFY_EX(TTN_NEEDTEXT, 0, OnToolNotify)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON25, &CATCOMMANDDlg::OnBnClickedButton25)
	ON_EN_CHANGE(IDC_TIME1, &CATCOMMANDDlg::OnEnChangeTime1)
	ON_EN_CHANGE(IDC_TIME2, &CATCOMMANDDlg::OnEnChangeTime2)
	ON_EN_CHANGE(IDC_TIME3, &CATCOMMANDDlg::OnEnChangeTime3)
	ON_EN_CHANGE(IDC_TIME4, &CATCOMMANDDlg::OnEnChangeTime4)
	ON_EN_CHANGE(IDC_TIME5, &CATCOMMANDDlg::OnEnChangeTime5)
	ON_EN_CHANGE(IDC_TIME6, &CATCOMMANDDlg::OnEnChangeTime6)
	ON_EN_CHANGE(IDC_TIME7, &CATCOMMANDDlg::OnEnChangeTime7)
	ON_EN_CHANGE(IDC_TIME8, &CATCOMMANDDlg::OnEnChangeTime8)
	ON_EN_CHANGE(IDC_TIME9, &CATCOMMANDDlg::OnEnChangeTime9)
	ON_EN_CHANGE(IDC_TIME10, &CATCOMMANDDlg::OnEnChangeTime10)
	ON_EN_CHANGE(IDC_TIME11, &CATCOMMANDDlg::OnEnChangeTime11)
	ON_EN_CHANGE(IDC_TIME12, &CATCOMMANDDlg::OnEnChangeTime12)
	ON_EN_CHANGE(IDC_TIME13, &CATCOMMANDDlg::OnEnChangeTime13)
	ON_EN_CHANGE(IDC_TIME15, &CATCOMMANDDlg::OnEnChangeTime15)
	ON_EN_CHANGE(IDC_TIME14, &CATCOMMANDDlg::OnEnChangeTime14)
	ON_BN_CLICKED(IDC_SELECTALL, &CATCOMMANDDlg::OnBnClickedSelectall)
END_MESSAGE_MAP()


BOOL CATCOMMANDDlg::OnToolNotify(UINT id, NMHDR* pNMHDR, LRESULT* pResult)
{
	TOOLTIPTEXT* pTTT = (TOOLTIPTEXT*)pNMHDR;
	CString str;
	UINT nID = pNMHDR->idFrom; 
	if (nID)
	{
		nID = cToolBar.CommandToIndex(nID);
		if (nID != -1)
		{
			switch (nID)
			{
			case 0:
				pTTT->lpszText = L"Open Port";
				break;
			case 1:
				pTTT->lpszText = L"Close Port";
				break;
			case 3:
				pTTT->lpszText = L"Clear Log";
				break;
			case 4:
				pTTT->lpszText = L"Save Log";
				break;
			case 6:
				pTTT->lpszText = L"Import AT";
				break;
			default:
				pTTT->lpszText = L"Export AT";
				break;

			}

			//获取工具栏文本			
			pTTT->hinst = AfxGetResourceHandle();
			return(TRUE);
		}
	}
	return(FALSE);

		return FALSE;
}

BOOL CATCOMMANDDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_Menu.LoadMenu(IDR_MENU);
	SetMenu(&m_Menu);

	// 将“关于...”菜单项添加到系统菜单中。
	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	GetDlgItem(IDC_HISTORY)->SetWindowTextW(_T("AT"));

	static UINT indicators[] =
	{
		IDS_STATUS,
		IDS_PORT,
		IDS_BAUD
	};

	m_Statusbar.Create(this);              
	m_Statusbar.SetIndicators(indicators, 3);  

	m_Statusbar.SetPaneInfo(0, IDS_STATUS, SBPS_STRETCH, 0);
	m_Statusbar.SetPaneInfo(1, IDS_PORT, SBPS_POPOUT, 320);
	m_Statusbar.SetPaneInfo(2, IDS_BAUD, SBPS_POPOUT, 320);
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, IDS_BAUD);

	m_time1.SetWindowText(_T("1000"));
	m_time2.SetWindowText(_T("1000"));
	m_time3.SetWindowText(_T("1000"));
	m_time4.SetWindowText(_T("1000"));
	m_time5.SetWindowText(_T("1000"));
	m_time6.SetWindowText(_T("1000"));
	m_time7.SetWindowText(_T("1000"));
	m_time8.SetWindowText(_T("1000"));
	m_time9.SetWindowText(_T("1000"));
	m_time10.SetWindowText(_T("1000"));
	m_wait11.SetWindowText(_T("1000"));
	m_wait12.SetWindowText(_T("1000"));
	m_wait13.SetWindowText(_T("1000"));
	m_wait14.SetWindowText(_T("1000"));
	m_wait15.SetWindowText(_T("1000"));

	line1 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_string1"));
	line2 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_string2"));
	line3 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_string3"));
	line4 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_string4"));
	line5 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_string5"));
	line6 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_string6"));
	line7 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_string7"));
	line8 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_string8"));
	line9 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_string9"));
	line10 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_string10"));
	line11 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_string11"));
	line12 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_string12"));
	line13 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_string13"));
	line14 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_string14"));
	line15 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_string15"));

	time = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_time"));
	time1 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_time1"));
	time2 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_time2"));
	time3 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_time3"));
	time4 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_time4"));
	time5 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_time5"));
	time6 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_time6"));
	time7 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_time7"));
	time8 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_time8"));
	time9 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_time9"));
	time10 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_time10"));
	time11 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_time11"));
	time12 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_time12"));
	time13 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_time13"));
	time14 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_time14"));
	time15 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_time15"));

	at1 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_at1"));
	at2 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_at2"));
	at3 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_at3"));
	at4 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_at4"));
	at5 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_at5"));
	at6 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_at6"));
	at7 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_at7"));
	at8 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_at8"));
	at9 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_at9"));
	at10 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_at10"));
	at11 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_at11"));
	at12 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_at12"));
	at13 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_at13"));
	at14 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_at14"));
	at15 = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_at15"));

	at = AfxGetApp()->GetProfileString(_T("Setting"), _T("m_at"));

	// AT Command
	if (line1 == "") {
		m_line1.SetWindowText(_T(""));
	}
	else {
		m_line1.SetWindowText(line1);
	}

	if (line2 == "") {
		m_line2.SetWindowText(_T(""));
	}
	else {
		m_line2.SetWindowText(line2);
	}

	if (line3 == "") {
		m_line3.SetWindowText(_T(""));
	}
	else {
		m_line3.SetWindowText(line3);
	}

	if (line4 == "") {
		m_line4.SetWindowText(_T(""));
	}
	else {
		m_line4.SetWindowText(line4);
	}

	if (line5 == "") {
		m_line5.SetWindowText(_T(""));
	}
	else {
		m_line5.SetWindowText(line5);
	}

	if (line6 == "") {
		m_line6.SetWindowText(_T(""));
	}
	else {
		m_line6.SetWindowText(line6);
	}

	if (line7 == "") {
		m_line7.SetWindowText(_T(""));
	}
	else {
		m_line7.SetWindowText(line7);
	}

	if (line8 == "") {
		m_line8.SetWindowText(_T(""));
	}
	else {
		m_line8.SetWindowText(line8);
	}

	if (line9 == "") {
		m_line9.SetWindowText(_T(""));
	}
	else {
		m_line9.SetWindowText(line9);
	}

	if (line10 == "") {
		m_line10.SetWindowText(_T(""));
	}
	else {
		m_line10.SetWindowText(line10);
	}

	if (line11 == "") {
		m_line11.SetWindowText(_T(""));
	}
	else {
		m_line11.SetWindowText(line11);
	}

	if (line12 == "") {
		m_line12.SetWindowText(_T(""));
	}
	else {
		m_line12.SetWindowText(line12);
	}

	if (line13 == "") {
		m_line13.SetWindowText(_T(""));
	}
	else {
		m_line13.SetWindowText(line13);
	}

	if (line14 == "") {
		m_line14.SetWindowText(_T(""));
	}
	else {
		m_line14.SetWindowText(line14);
	}

	if (line15 == "") {
		m_line15.SetWindowText(_T(""));
	}
	else {
		m_line15.SetWindowText(line15);
	}

	// Time
	if (time == "") {
		m_loopcount.SetWindowText(_T("1000"));
	}
	else {
		m_loopcount.SetWindowText(time);
	}

	if (time1 == "") {
		m_time1.SetWindowText(_T("1000"));
	}
	else {
		m_time1.SetWindowText(time1);
	}

	if (time2 == "") {
		m_time2.SetWindowText(_T("1000"));
	}
	else {
		m_time2.SetWindowText(time2);
	}

	if (time3 == "") {
		m_time3.SetWindowText(_T("1000"));
	}
	else {
		m_time3.SetWindowText(time3);
	}

	if (time4 == "") {
		m_time4.SetWindowText(_T("1000"));
	}
	else {
		m_time4.SetWindowText(time4);
	}

	if (time5 == "") {
		m_time5.SetWindowText(_T("1000"));
	}
	else {
		m_time5.SetWindowText(time5);
	}

	if (time6 == "") {
		m_time6.SetWindowText(_T("1000"));
	}
	else {
		m_time6.SetWindowText(time6);
	}

	if (time7 == "") {
		m_time7.SetWindowText(_T("1000"));
	}
	else {
		m_time7.SetWindowText(time7);
	}

	if (time8 == "") {
		m_time8.SetWindowText(_T("1000"));
	}
	else {
		m_time8.SetWindowText(time8);
	}

	if (time9 == "") {
		m_time9.SetWindowText(_T("1000"));
	}
	else {
		m_time9.SetWindowText(time9);
	}

	if (time10 == "") {
		m_time10.SetWindowText(_T("1000"));
	}
	else {
		m_time10.SetWindowText(time10);
	}

	if (time11 == "") {
		m_wait11.SetWindowText(_T("1000"));
	}
	else {
		m_wait11.SetWindowText(time11);
	}

	if (time12 == "") {
		m_wait12.SetWindowText(_T("1000"));
	}
	else {
		m_wait12.SetWindowText(time12);
	}

	if (time13 == "") {
		m_wait13.SetWindowText(_T("1000"));
	}
	else {
		m_wait13.SetWindowText(time13);
	}

	if (time14 == "") {
		m_wait14.SetWindowText(_T("1000"));
	}
	else {
		m_wait14.SetWindowText(time14);
	}

	if (time15 == "") {
		m_wait15.SetWindowText(_T("1000"));
	}
	else {
		m_wait15.SetWindowText(time15);
	}

	// AT comment
	if (at == "") {
		m_histroy.SetWindowText(_T("AT"));
	}
	else {
		m_histroy.SetWindowText(at);
	}

	if (at1 == "") {
		m_at1.SetWindowText(_T("AT1"));
	}
	else {
		m_at1.SetWindowText(at1);
	}

	if (at2 == "") {
		m_at2.SetWindowText(_T("AT2"));
	}
	else {
		m_at2.SetWindowText(at2);
	}

	if (at3 == "") {
		m_at3.SetWindowText(_T("AT3"));
	}
	else {
		m_at3.SetWindowText(at3);
	}

	if (at4 == "") {
		m_at4.SetWindowText(_T("AT4"));
	}
	else {
		m_at4.SetWindowText(at4);
	}

	if (at5 == "") {
		m_at5.SetWindowText(_T("AT5"));
	}
	else {
		m_at5.SetWindowText(at5);
	}

	if (at6 == "") {
		m_at6.SetWindowText(_T("AT6"));
	}
	else {
		m_at6.SetWindowText(at6);
	}

	if (at7 == "") {
		m_at7.SetWindowText(_T("AT7"));
	}
	else {
		m_at7.SetWindowText(at7);
	}

	if (at8 == "") {
		m_at8.SetWindowText(_T("AT8"));
	}
	else {
		m_at8.SetWindowText(at8);
	}

	if (at9 == "") {
		m_at9.SetWindowText(_T("AT9"));
	}
	else {
		m_at9.SetWindowText(at9);
	}

	if (at10 == "") {
		m_at10.SetWindowText(_T("AT10"));
	}
	else {
		m_at10.SetWindowText(at10);
	}

	if (at11 == "") {
		m_at11.SetWindowText(_T("AT11"));
	}
	else {
		m_at11.SetWindowText(at11);
	}

	if (at12 == "") {
		m_at12.SetWindowText(_T("AT12"));
	}
	else {
		m_at12.SetWindowText(at12);
	}

	if (at13 == "") {
		m_at13.SetWindowText(_T("AT13"));
	}
	else {
		m_at13.SetWindowText(at13);
	}

	if (at14 == "") {
		m_at14.SetWindowText(_T("AT14"));
	}
	else {
		m_at14.SetWindowText(at14);
	}

	if (at15 == "") {
		m_at15.SetWindowText(_T("AT15"));
	}
	else {
		m_at15.SetWindowText(at15);
	}

	if (!cToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD |
		WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS |
		CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!cToolBar.LoadToolBar(IDR_TOOLBAR1))
	{
		EndDialog(IDCANCEL);
	}
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0);

	OnLoadToolBarBitmap();

	CToolBarCtrl* pToolBar = (CToolBarCtrl*)&cToolBar.GetToolBarCtrl();
	pToolBar->EnableButton(IDR_TOOL2, false);

	CToolBarCtrl* pToolBar2 = (CToolBarCtrl*)&cToolBar.GetToolBarCtrl();
	pToolBar2->EnableButton(IDR_TOOL1, true);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CATCOMMANDDlg::OnLoadToolBarBitmap()
{
	m_IconList.Create(24, 24, TRUE | ILC_COLOR24, 6, 0);

	m_IconList.Add(LoadIcon(AfxGetResourceHandle(), MAKEINTRESOURCE(IDI_ICON6)));
	m_IconList.Add(LoadIcon(AfxGetResourceHandle(), MAKEINTRESOURCE(IDI_ICON5))); 
	m_IconList.Add(LoadIcon(AfxGetResourceHandle(), MAKEINTRESOURCE(IDI_ICON7)));
	m_IconList.Add(LoadIcon(AfxGetResourceHandle(), MAKEINTRESOURCE(IDI_ICON4)));
	m_IconList.Add(LoadIcon(AfxGetResourceHandle(), MAKEINTRESOURCE(IDI_ICON2)));
	m_IconList.Add(LoadIcon(AfxGetResourceHandle(), MAKEINTRESOURCE(IDI_ICON3)));

	cToolBar.GetToolBarCtrl().SetImageList(&m_IconList);
}

BOOL CATCOMMANDDlg::AutoFitScreen(CREATESTRUCT& cs)
{
	if (!CATCOMMANDDlg::AutoFitScreen(cs))
		return FALSE;

	cs.style = WS_OVERLAPPED | WS_CAPTION | FWS_ADDTOTITLE
		| WS_THICKFRAME | WS_MINIMIZEBOX | WS_SYSMENU;

	RECT rect;
	SystemParametersInfo(SPI_GETWORKAREA, 0, &rect, 0);


	int x1 = GetSystemMetrics(SM_CXFULLSCREEN);
	int y1 = GetSystemMetrics(SM_CYFULLSCREEN);
	int x2 = GetSystemMetrics(SM_CXSCREEN);
	int y2 = GetSystemMetrics(SM_CYSCREEN);

	cs.x = 0;
	cs.y = 0;
	cs.cx = rect.right;
	cs.cy = rect.bottom;

	return TRUE;
}

static UINT receivemessage(LPVOID  lParam);

BOOL CATCOMMANDDlg::OnDeviceChange(UINT nEventType, DWORD dwData)
{
	DEV_BROADCAST_DEVICEINTERFACE* pHdr = (DEV_BROADCAST_DEVICEINTERFACE*)dwData;

	PDEV_BROADCAST_DEVICEINTERFACE pDevInf;
	pDevInf = (PDEV_BROADCAST_DEVICEINTERFACE)pHdr;

	int count = 0;
	CString end;
	end = "\r\n";

	switch (nEventType)
	{
	case DBT_DEVICEREMOVECOMPLETE:				//设备移除事件
		if (pDevInf != NULL)
		{
			TRACELOG("DBT_DEVICEREMOVECOMPLETE");
			m_text.SetSel(-1);
			m_text.ReplaceSel(_T("设备移除! \r\n"));
			m_cspi.UnintPort();

			m_bostatus = false;
			normal = false;

			m_strWord = "";
			m_strTempstr = m_Statusbar.GetPaneText(1);

			if (m_strTempstr != "UNKNOWN PORT") {
				m_strWord += TEXT("COM");
				m_strWord += m_strPort;
				m_strWord += "CLOSE";
				m_Statusbar.SetPaneText(1, m_strWord);
			}

			if (((CButton*)GetDlgItem(IDC_CHECK14))->GetCheck() == 1 && check == false) {
				m_checkbox.EnableWindow(false);
				check = true;
			}

			if (((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck() == 1 && check2 == false) {
				m_loop.EnableWindow(false);
				check2 = true;
			}

			CToolBarCtrl* pToolBar = (CToolBarCtrl*)&cToolBar.GetToolBarCtrl();
			pToolBar->EnableButton(IDR_TOOL1, true);
			CToolBarCtrl* pToolBar2 = (CToolBarCtrl*)&cToolBar.GetToolBarCtrl();
			pToolBar2->EnableButton(IDR_TOOL2, false);

			return true;
		}
		break;

	case DBT_DEVICEARRIVAL:						//设备插入事件
		if (pDevInf != NULL)
		{
			TRACELOG("DBT_DEVICEARRIVAL");
			m_text.SetSel(-1);
			m_text.ReplaceSel(_T("设备插入! \r\n"));

			if (check) {
				m_checkbox.EnableWindow(true);
				check == false;
			}
			if (check2) {
				m_loop.EnableWindow(true);
				check2 = false;
			}

			ports.RemoveAll();
			portse.RemoveAll();
			portsu.RemoveAll();

			CString str;
			str = "";
			Openport op;

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

			if (uicounter > 0)
			{
				for (int i = 0; i < uicounter; i++)
				{
					uisetcom = ports.ElementAt(i);
					str.Format(_T("COM%d "), uisetcom);

					for (size_t i = 0; i < op.m_vecports.size(); ++i) 
					{
						if (op.m_vecports[i] == str) {
							found = true;
							break; 
						}
					}
					if (!found) 
					{
						m_cspi.InitPort(_ttoi(str.Mid(3)), 9600);
						m_Statusbar.SetPaneText(1, str + TEXT("OPENED"));
						if (!m_bOpenthread) {
							AfxBeginThread(receivemessage, (LPVOID)this);
							m_bOpenthread = true;
						}
					}
				}
			}

			if (((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck() == 1) 
			{
				m_text.SetSel(-1);
				m_text.ReplaceSel(TEXT("\r\n"));
				OnBnClickedSend();
			}

			if (((CButton*)GetDlgItem(IDC_CHECK14))->GetCheck() == 1) 
			{
				LoopSend();
			}
			CToolBarCtrl* pToolBar = (CToolBarCtrl*)&cToolBar.GetToolBarCtrl();
			pToolBar->EnableButton(IDR_TOOL1, false);
			CToolBarCtrl* pToolBar2 = (CToolBarCtrl*)&cToolBar.GetToolBarCtrl();
			pToolBar2->EnableButton(IDR_TOOL2, true);
		}
		break;

	default:
		break;
	}
	return TRUE;
}

void CATCOMMANDDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CATCOMMANDDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CATCOMMANDDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

static UINT  sendproc(LPVOID  lParam)
{
	CATCOMMANDDlg* pWnd = (CATCOMMANDDlg*)lParam;
	pWnd->SendThread();

	return 0;
}

void CATCOMMANDDlg::SendThread()
{
    GetDlgItem(IDC_HISTORY)->GetWindowText(m_strTempstr);
    BOOL add = true;

    for (size_t i = 0; i < m_vecHistory.size(); i++) 
	{
        if (m_vecHistory[i] == m_strTempstr) {
            add = false;
            break;
        }
    }

    if (add) 
	{
        m_vecHistory.push_back(m_strTempstr);
        m_histroy.AddString(m_strTempstr);
    }

    int state = ((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck();

    if (state == 0) 
	{
		Send();
    }

    else if (state == 1) 
	{
		DelaySend();
    }
}


void CATCOMMANDDlg::OnBnClickedSend()
{
	// TODO: 在此添加控件通知处理程序代码
	CWinThread* MyThread = AfxBeginThread(sendproc, (LPVOID)this);
}

void CATCOMMANDDlg::Send()
{
	m_boissend = true;
	GetDlgItem(IDC_HISTORY)->GetWindowText(m_strLinetext);

	if (!m_cspi.IsOpen()) 
	{
		MessageBox(TEXT("发送失败，串口未连接或已经拔出！"), TEXT("Warning"));
		return;
	}

	if (m_strLinetext == "") 
	{
		return;
	}

	GetDlgItem(IDC_HISTORY)->GetWindowText(m_strTempstr); 
	m_strTempstr += _T("\r\n");

	DWORD len = m_strTempstr.GetLength();
	BOOL test = m_cspi.WriteData((unsigned char*)CStringA(m_strTempstr.GetBuffer()).GetBuffer(), len);
	if (!test) 
	{
		return;
	}
	m_str1 = "";

	m_tmTime = CTime::GetCurrentTime();
	m_str2 = m_tmTime.Format("[%Y-%m-%d  %X]");
	m_str1 += "\r\n";
	m_str1 += m_str2;
	m_str1 += " ->";
	m_str1 += "\r\n";
	m_str1 += m_strTempstr;

	m_text.SetSel(-1);
	m_text.ReplaceSel(m_str1);
}

void CATCOMMANDDlg::DelaySend()
{ 
	if (!m_cspi.IsOpen())
	{
		CButton* pBtn = (CButton*)GetDlgItem(IDC_CHECK1);
		pBtn->SetCheck(0);
		MessageBox(TEXT("发送失败，串口未连接或已经拔出！"), TEXT("Warning"));
		return;
	}

	m_at1.EnableWindow(false);
	m_at2.EnableWindow(false);
	m_at3.EnableWindow(false);
	m_at4.EnableWindow(false);
	m_at5.EnableWindow(false);
	m_at6.EnableWindow(false);
	m_at7.EnableWindow(false);
	m_at8.EnableWindow(false);
	m_at9.EnableWindow(false);
	m_at10.EnableWindow(false);
	m_at11.EnableWindow(false);
	m_at12.EnableWindow(false);
	m_at13.EnableWindow(false);
	m_at14.EnableWindow(false);
	m_at15.EnableWindow(false);
	m_checkbox.EnableWindow(false);
	m_send.EnableWindow(false);
	m_loopcount.EnableWindow(false);
	m_histroy.EnableWindow(false);
	m_reset.EnableWindow(false);

	int sleeptime = 0;
	GetDlgItem(IDC_HISTORY)->GetWindowText(m_strLinetext);

	if (m_strLinetext == "") 
	{
		return;
	}

	int state = ((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck();

	GetDlgItem(IDC_LOOP)->GetWindowText(m_strTime);
	if (m_strTime != "") { 
		sleeptime = _ttoi(m_strTime); 
	}

	if (sleeptime == 0) {
		Send();
		CButton* pBtn = (CButton*)GetDlgItem(IDC_CHECK1);
		pBtn->SetCheck(0);
		return;
	} 

	while (state == 1) 
	{
		state = ((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck();

		CString m_strTempstr = TEXT("");
		m_str1 = "";
		GetDlgItem(IDC_HISTORY)->GetWindowText(m_strTempstr);
		m_strTempstr += _T("\r\n");

		DWORD len = m_strTempstr.GetLength();
		BOOL test = m_cspi.WriteData((unsigned char*)CStringA(m_strTempstr.GetBuffer()).GetBuffer(), len);
		if (!test) 
		{
			return;
		}
		m_str1 = "";
		m_boissend = true;

		m_tmTime = CTime::GetCurrentTime();
		m_str2 = m_tmTime.Format("[%Y-%m-%d  %X]");
		m_str1 += "\r\n";
		m_str1 += m_str2;
		m_str1 += " ->";
		m_str1 += "\r\n";
		m_str1 += m_strTempstr;

		m_text.SetSel(-1);
		m_text.ReplaceSel(m_str1);

		Sleep(sleeptime);
	}

	m_at1.EnableWindow(true);
	m_at2.EnableWindow(true);
	m_at3.EnableWindow(true);
	m_at4.EnableWindow(true);
	m_at5.EnableWindow(true);
	m_at6.EnableWindow(true);
	m_at7.EnableWindow(true);
	m_at8.EnableWindow(true);
	m_at9.EnableWindow(true);
	m_at10.EnableWindow(true);
	m_at11.EnableWindow(true);
	m_at12.EnableWindow(true);
	m_at13.EnableWindow(true);
	m_at14.EnableWindow(true);
	m_at15.EnableWindow(true);

	m_checkbox.EnableWindow(true);
	m_send.EnableWindow(true);
	m_loopcount.EnableWindow(true);
	m_histroy.EnableWindow(true);
	m_reset.EnableWindow(true);
}

static UINT  myproc1(LPVOID  lParam)
{
	CATCOMMANDDlg* pWnd = (CATCOMMANDDlg*)lParam;
	pWnd->ThreadSend1();

	return 0;
}

static UINT  myproc2(LPVOID  lParam)
{
	CATCOMMANDDlg* pWnd = (CATCOMMANDDlg*)lParam;
	pWnd->ThreadSend2();

	return 0;
}

static UINT  myproc3(LPVOID  lParam)
{
	CATCOMMANDDlg* pWnd = (CATCOMMANDDlg*)lParam;
	pWnd->ThreadSend3();

	return 0;
}

static UINT  myproc4(LPVOID  lParam)
{
	CATCOMMANDDlg* pWnd = (CATCOMMANDDlg*)lParam;
	pWnd->ThreadSend4();

	return 0;
}


static UINT  myproc5(LPVOID  lParam)
{
	CATCOMMANDDlg* pWnd = (CATCOMMANDDlg*)lParam;
	pWnd->ThreadSend5();

	return 0;
}

static UINT  myproc6(LPVOID  lParam)
{
	CATCOMMANDDlg* pWnd = (CATCOMMANDDlg*)lParam;
	pWnd->ThreadSend6();

	return 0;
}

static UINT  myproc7(LPVOID  lParam)
{
	CATCOMMANDDlg* pWnd = (CATCOMMANDDlg*)lParam;
	pWnd->ThreadSend7();

	return 0;
}

static UINT  myproc8(LPVOID  lParam)
{
	CATCOMMANDDlg* pWnd = (CATCOMMANDDlg*)lParam;
	pWnd->ThreadSend8();

	return 0;
}


static UINT  myproc9(LPVOID  lParam)
{
	CATCOMMANDDlg* pWnd = (CATCOMMANDDlg*)lParam;
	pWnd->ThreadSend9();

	return 0;
}

static UINT  myproc10(LPVOID  lParam)
{
	CATCOMMANDDlg* pWnd = (CATCOMMANDDlg*)lParam;
	pWnd->ThreadSend10();

	return 0;
}

static UINT  myproc11(LPVOID  lParam)
{
	CATCOMMANDDlg* pWnd = (CATCOMMANDDlg*)lParam;
	pWnd->ThreadSend11();

	return 0;
}

static UINT  myproc12(LPVOID  lParam)
{
	CATCOMMANDDlg* pWnd = (CATCOMMANDDlg*)lParam;
	pWnd->ThreadSend12();

	return 0;
}

static UINT  myproc13(LPVOID  lParam)
{
	CATCOMMANDDlg* pWnd = (CATCOMMANDDlg*)lParam;
	pWnd->ThreadSend13();

	return 0;
}

static UINT  myproc14(LPVOID  lParam)
{
	CATCOMMANDDlg* pWnd = (CATCOMMANDDlg*)lParam;
	pWnd->ThreadSend14();

	return 0;
}

static UINT  myproc15(LPVOID  lParam)
{
	CATCOMMANDDlg* pWnd = (CATCOMMANDDlg*)lParam;
	pWnd->ThreadSend15();

	return 0;
}

void CATCOMMANDDlg::ThreadSend1()
{
	// 主要处理函数在这里写  
	GetDlgItem(IDC_LINE1)->GetWindowText(m_strTempstr);
	m_strTempstr += _T("\r\n");
	DWORD len = m_strTempstr.GetLength();

	BOOL test = m_cspi.WriteData((unsigned char*)CStringA(m_strTempstr.GetBuffer()).GetBuffer(), len);
	if (!test) 
	{
		return;
	}
	m_str1 = "";
	m_boissend = true;

	m_tmTime = CTime::GetCurrentTime();
	m_str2 = m_tmTime.Format("[%Y-%m-%d  %X]");
	m_str1 += "\r\n";
	m_str1 += m_str2;
	m_str1 += " ->";
	m_str1 += "\r\n";
	m_str1 += m_strTempstr;

	m_text.SetSel(-1);
	m_text.ReplaceSel(m_str1);

	GetDlgItem(IDC_TIME1)->GetWindowText(m_strTime);
	int sleeptime = _ttoi(m_strTime);
	Sleep(sleeptime);

	
}

void CATCOMMANDDlg::ThreadSend2()
{
	// 主要处理函数在这里写  
	GetDlgItem(IDC_LINE2)->GetWindowText(m_strTempstr);
	m_strTempstr += _T("\r\n");
	DWORD len = m_strTempstr.GetLength();
	BOOL test = m_cspi.WriteData((unsigned char*)CStringA(m_strTempstr.GetBuffer()).GetBuffer(), len);
	if (!test) 
	{
		return;
	}
	m_str1 = "";
	m_boissend = true;

	m_tmTime = CTime::GetCurrentTime();
	m_str2 = m_tmTime.Format("[%Y-%m-%d  %X]");
	m_str1 += "\r\n";
	m_str1 += m_str2;
	m_str1 += " ->";
	m_str1 += "\r\n";
	m_str1 += m_strTempstr;

	m_text.SetSel(-1);
	m_text.ReplaceSel(m_str1);

	GetDlgItem(IDC_TIME2)->GetWindowText(m_strTime);
	int sleeptime = _ttoi(m_strTime);
	Sleep(sleeptime);

	
}

void CATCOMMANDDlg::ThreadSend3()
{
	// 主要处理函数在这里写  
	GetDlgItem(IDC_LINE3)->GetWindowText(m_strTempstr);
	m_strTempstr += _T("\r\n");
	DWORD len = m_strTempstr.GetLength();
	BOOL test = m_cspi.WriteData((unsigned char*)CStringA(m_strTempstr.GetBuffer()).GetBuffer(), len);
	if (!test) 
	{
		return;
	}
	m_str1 = "";
	m_boissend = true;

	m_tmTime = CTime::GetCurrentTime();
	m_str2 = m_tmTime.Format("[%Y-%m-%d  %X]");
	m_str1 += "\r\n";
	m_str1 += m_str2;
	m_str1 += " ->";
	m_str1 += "\r\n";
	m_str1 += m_strTempstr;

	m_text.SetSel(-1);
	m_text.ReplaceSel(m_str1);

	GetDlgItem(IDC_TIME3)->GetWindowText(m_strTime);
	int sleeptime = _ttoi(m_strTime);
	Sleep(sleeptime);

	
}

void CATCOMMANDDlg::ThreadSend4()
{
	// 主要处理函数在这里写  
	GetDlgItem(IDC_LINE4)->GetWindowText(m_strTempstr);
	m_strTempstr += _T("\r\n");
	DWORD len = m_strTempstr.GetLength();
	BOOL test = m_cspi.WriteData((unsigned char*)CStringA(m_strTempstr.GetBuffer()).GetBuffer(), len);
	if (!test) 
	{
		return;
	}
	m_str1 = "";
	m_boissend = true;

	m_tmTime = CTime::GetCurrentTime();
	m_str2 = m_tmTime.Format("[%Y-%m-%d  %X]");
	m_str1 += "\r\n";
	m_str1 += m_str2;
	m_str1 += " ->";
	m_str1 += "\r\n";
	m_str1 += m_strTempstr;

	m_text.SetSel(-1);
	m_text.ReplaceSel(m_str1);

	GetDlgItem(IDC_TIME4)->GetWindowText(m_strTime);
	int sleeptime = _ttoi(m_strTime);
	Sleep(sleeptime);

	
}

void CATCOMMANDDlg::ThreadSend5()
{
	// 主要处理函数在这里写  
	GetDlgItem(IDC_LINE5)->GetWindowText(m_strTempstr);
	m_strTempstr += _T("\r\n");
	DWORD len = m_strTempstr.GetLength();
	BOOL test = m_cspi.WriteData((unsigned char*)CStringA(m_strTempstr.GetBuffer()).GetBuffer(), len);
	if (!test) 
	{
		return;
	}
	m_str1 = "";
	m_boissend = true;

	m_tmTime = CTime::GetCurrentTime();
	m_str2 = m_tmTime.Format("[%Y-%m-%d  %X]");
	m_str1 += "\r\n";
	m_str1 += m_str2;
	m_str1 += " ->";
	m_str1 += "\r\n";
	m_str1 += m_strTempstr;

	m_text.SetSel(-1);
	m_text.ReplaceSel(m_str1);

	GetDlgItem(IDC_TIME5)->GetWindowText(m_strTime);
	int sleeptime = _ttoi(m_strTime);
	Sleep(sleeptime);

	
}

void CATCOMMANDDlg::ThreadSend6()
{
	// 主要处理函数在这里写  
	GetDlgItem(IDC_LINE6)->GetWindowText(m_strTempstr);
	m_strTempstr += _T("\r\n");
	DWORD len = m_strTempstr.GetLength();
	BOOL test = m_cspi.WriteData((unsigned char*)CStringA(m_strTempstr.GetBuffer()).GetBuffer(), len);
	if (!test) 
	{
		return;
	}
	m_str1 = "";
	m_boissend = true;

	m_tmTime = CTime::GetCurrentTime();
	m_str2 = m_tmTime.Format("[%Y-%m-%d  %X]");
	m_str1 += "\r\n";
	m_str1 += m_str2;
	m_str1 += " ->";
	m_str1 += "\r\n";
	m_str1 += m_strTempstr;

	m_text.SetSel(-1);
	m_text.ReplaceSel(m_str1);

	GetDlgItem(IDC_TIME6)->GetWindowText(m_strTime);
	int sleeptime = _ttoi(m_strTime);
	Sleep(sleeptime);

	
}

void CATCOMMANDDlg::ThreadSend7()
{
	// 主要处理函数在这里写  
	GetDlgItem(IDC_LINE7)->GetWindowText(m_strTempstr);
	m_strTempstr += _T("\r\n");
	DWORD len = m_strTempstr.GetLength();
	BOOL test = m_cspi.WriteData((unsigned char*)CStringA(m_strTempstr.GetBuffer()).GetBuffer(), len);
	if (!test) 
	{
		return;
	}
	m_str1 = "";
	m_boissend = true;

	m_tmTime = CTime::GetCurrentTime();
	m_str2 = m_tmTime.Format("[%Y-%m-%d  %X]");
	m_str1 += "\r\n";
	m_str1 += m_str2;
	m_str1 += " ->";
	m_str1 += "\r\n";
	m_str1 += m_strTempstr;

	m_text.SetSel(-1);
	m_text.ReplaceSel(m_str1);

	GetDlgItem(IDC_TIME7)->GetWindowText(m_strTime);
	int sleeptime = _ttoi(m_strTime);
	Sleep(sleeptime);

	
}

void CATCOMMANDDlg::ThreadSend8()
{
	// 主要处理函数在这里写  
	GetDlgItem(IDC_LINE8)->GetWindowText(m_strTempstr);
	m_strTempstr += _T("\r\n");
	DWORD len = m_strTempstr.GetLength();
	BOOL test = m_cspi.WriteData((unsigned char*)CStringA(m_strTempstr.GetBuffer()).GetBuffer(), len);
	if (!test) 
	{
		return;
	}
	m_str1 = "";
	m_boissend = true;

	m_tmTime = CTime::GetCurrentTime();
	m_str2 = m_tmTime.Format("[%Y-%m-%d  %X]");
	m_str1 += "\r\n";
	m_str1 += m_str2;
	m_str1 += " ->";
	m_str1 += "\r\n";
	m_str1 += m_strTempstr;

	m_text.SetSel(-1);
	m_text.ReplaceSel(m_str1);

	GetDlgItem(IDC_TIME8)->GetWindowText(m_strTime);
	int sleeptime = _ttoi(m_strTime);
	Sleep(sleeptime);

	
}

void CATCOMMANDDlg::ThreadSend9()
{
	// 主要处理函数在这里写  
	GetDlgItem(IDC_LINE9)->GetWindowText(m_strTempstr);
	m_strTempstr += _T("\r\n");
	DWORD len = m_strTempstr.GetLength();
	BOOL test = m_cspi.WriteData((unsigned char*)CStringA(m_strTempstr.GetBuffer()).GetBuffer(), len);
	if (!test)
	{
		return;
	}
	m_str1 = "";
	m_boissend = true;

	m_tmTime = CTime::GetCurrentTime();
	m_str2 = m_tmTime.Format("[%Y-%m-%d  %X]");
	m_str1 += "\r\n";
	m_str1 += m_str2;
	m_str1 += " ->";
	m_str1 += "\r\n";
	m_str1 += m_strTempstr;

	m_text.SetSel(-1);
	m_text.ReplaceSel(m_str1);

	GetDlgItem(IDC_TIME9)->GetWindowText(m_strTime);
	int sleeptime = _ttoi(m_strTime);
	Sleep(sleeptime);

	
}

void CATCOMMANDDlg::ThreadSend10()
{
	// 主要处理函数在这里写  
	GetDlgItem(IDC_LINE10)->GetWindowText(m_strTempstr);
	m_strTempstr += _T("\r\n");
	DWORD len = m_strTempstr.GetLength();
	BOOL test = m_cspi.WriteData((unsigned char*)CStringA(m_strTempstr.GetBuffer()).GetBuffer(), len);
	if (!test) 
	{
		return;
	}
	m_str1 = "";
	m_boissend = true;

	m_tmTime = CTime::GetCurrentTime();
	m_str2 = m_tmTime.Format("[%Y-%m-%d  %X]");
	m_str1 += "\r\n";
	m_str1 += m_str2;
	m_str1 += " ->";
	m_str1 += "\r\n";
	m_str1 += m_strTempstr;

	m_text.SetSel(-1);
	m_text.ReplaceSel(m_str1);

	GetDlgItem(IDC_TIME10)->GetWindowText(m_strTime);
	int sleeptime = _ttoi(m_strTime);
	Sleep(sleeptime);

	
}

void CATCOMMANDDlg::ThreadSend11()
{
	// 主要处理函数在这里写  
	GetDlgItem(IDC_LINE11)->GetWindowText(m_strTempstr);
	m_strTempstr += _T("\r\n");
	DWORD len = m_strTempstr.GetLength();
	BOOL test = m_cspi.WriteData((unsigned char*)CStringA(m_strTempstr.GetBuffer()).GetBuffer(), len);
	if (!test) 
	{
		return;
	}
	m_str1 = "";
	m_boissend = true;

	m_tmTime = CTime::GetCurrentTime();
	m_str2 = m_tmTime.Format("[%Y-%m-%d  %X]");
	m_str1 += "\r\n";
	m_str1 += m_str2;
	m_str1 += " ->";
	m_str1 += "\r\n";
	m_str1 += m_strTempstr;

	m_text.SetSel(-1);
	m_text.ReplaceSel(m_str1);

	GetDlgItem(IDC_TIME11)->GetWindowText(m_strTime);
	int sleeptime = _ttoi(m_strTime);
	Sleep(sleeptime);

	
}

void CATCOMMANDDlg::ThreadSend12()
{
	// 主要处理函数在这里写  
	GetDlgItem(IDC_LINE12)->GetWindowText(m_strTempstr);
	m_strTempstr += _T("\r\n");
	DWORD len = m_strTempstr.GetLength();
	BOOL test = m_cspi.WriteData((unsigned char*)CStringA(m_strTempstr.GetBuffer()).GetBuffer(), len);
	if (!test) 
	{
		return;
	}
	m_str1 = "";
	m_boissend = true;

	m_tmTime = CTime::GetCurrentTime();
	m_str2 = m_tmTime.Format("[%Y-%m-%d  %X]");
	m_str1 += "\r\n";
	m_str1 += m_str2;
	m_str1 += " ->";
	m_str1 += "\r\n";
	m_str1 += m_strTempstr;

	m_text.SetSel(-1);
	m_text.ReplaceSel(m_str1);

	GetDlgItem(IDC_TIME12)->GetWindowText(m_strTime);
	int sleeptime = _ttoi(m_strTime);
	Sleep(sleeptime);

	
}

void CATCOMMANDDlg::ThreadSend13()
{
	// 主要处理函数在这里写  
	GetDlgItem(IDC_LINE13)->GetWindowText(m_strTempstr);
	m_strTempstr += _T("\r\n");
	DWORD len = m_strTempstr.GetLength();
	BOOL test = m_cspi.WriteData((unsigned char*)CStringA(m_strTempstr.GetBuffer()).GetBuffer(), len);
	if (!test)
	{
		return;
	}
	m_str1 = "";
	m_boissend = true; 

	m_tmTime = CTime::GetCurrentTime();
	m_str2 = m_tmTime.Format("[%Y-%m-%d  %X]");
	m_str1 += "\r\n";
	m_str1 += m_str2;
	m_str1 += " ->";
	m_str1 += "\r\n";
	m_str1 += m_strTempstr;

	m_text.SetSel(-1);
	m_text.ReplaceSel(m_str1);

	GetDlgItem(IDC_TIME13)->GetWindowText(m_strTime);
	int sleeptime = _ttoi(m_strTime);
	Sleep(sleeptime);

	
}

void CATCOMMANDDlg::ThreadSend14()
{
	// 主要处理函数在这里写  
	GetDlgItem(IDC_LINE14)->GetWindowText(m_strTempstr);
	m_strTempstr += _T("\r\n");
	DWORD len = m_strTempstr.GetLength();
	BOOL test = m_cspi.WriteData((unsigned char*)CStringA(m_strTempstr.GetBuffer()).GetBuffer(), len);
	if (!test) 
	{
		return;
	}
	m_str1 = "";
	m_boissend = true;

	m_tmTime = CTime::GetCurrentTime();
	m_str2 = m_tmTime.Format("[%Y-%m-%d  %X]");
	m_str1 += "\r\n";
	m_str1 += m_str2;
	m_str1 += " ->";
	m_str1 += "\r\n";
	m_str1 += m_strTempstr;

	m_text.SetSel(-1);
	m_text.ReplaceSel(m_str1);

	GetDlgItem(IDC_TIME14)->GetWindowText(m_strTime);
	int sleeptime = _ttoi(m_strTime);
	Sleep(sleeptime);

	
}

void CATCOMMANDDlg::ThreadSend15()
{
	// 主要处理函数在这里写  
	GetDlgItem(IDC_LINE15)->GetWindowText(m_strTempstr);
	m_strTempstr += _T("\r\n");
	DWORD len = m_strTempstr.GetLength();
	BOOL test = m_cspi.WriteData((unsigned char*)CStringA(m_strTempstr.GetBuffer()).GetBuffer(), len);
	if (!test) 
	{
		return;
	}
	m_str1 = "";
	m_boissend = true;

	m_tmTime = CTime::GetCurrentTime();
	m_str2 = m_tmTime.Format("[%Y-%m-%d  %X]");
	m_str1 += "\r\n";
	m_str1 += m_str2;
	m_str1 += " ->";
	m_str1 += "\r\n";
	m_str1 += m_strTempstr;

	m_text.SetSel(-1);
	m_text.ReplaceSel(m_str1);

	GetDlgItem(IDC_TIME15)->GetWindowText(m_strTime);
	int sleeptime = _ttoi(m_strTime);
	Sleep(sleeptime);
}


static UINT loopproc(LPVOID  lParam)
{
	CATCOMMANDDlg* pWnd = (CATCOMMANDDlg*)lParam;
	pWnd->LoopThread();

	return 0;
}

void CATCOMMANDDlg::LoopThread() {
	m_send.EnableWindow(false);
	m_send.EnableWindow(false);
	m_reset.EnableWindow(false);

	m_line1.EnableWindow(false);
	m_line2.EnableWindow(false);
	m_line3.EnableWindow(false);
	m_line4.EnableWindow(false);
	m_line5.EnableWindow(false);
	m_line6.EnableWindow(false);
	m_line7.EnableWindow(false);
	m_line8.EnableWindow(false);
	m_line9.EnableWindow(false);
	m_line10.EnableWindow(false);
	m_line11.EnableWindow(false);
	m_line12.EnableWindow(false);
	m_line13.EnableWindow(false);
	m_line14.EnableWindow(false);
	m_line15.EnableWindow(false);

	m_time1.EnableWindow(false);
	m_time2.EnableWindow(false);
	m_time3.EnableWindow(false);
	m_time4.EnableWindow(false);
	m_time5.EnableWindow(false);
	m_time6.EnableWindow(false);
	m_time7.EnableWindow(false);
	m_time8.EnableWindow(false);
	m_time9.EnableWindow(false);
	m_time10.EnableWindow(false);
	m_wait11.EnableWindow(false);
	m_wait12.EnableWindow(false);
	m_wait13.EnableWindow(false);
	m_wait14.EnableWindow(false);
	m_wait15.EnableWindow(false);


	m_check1.EnableWindow(false);
	m_check2.EnableWindow(false);
	m_check3.EnableWindow(false);
	m_check4.EnableWindow(false);
	m_check5.EnableWindow(false);
	m_check6.EnableWindow(false);
	m_check7.EnableWindow(false);
	m_check8.EnableWindow(false);
	m_check9.EnableWindow(false);
	m_check10.EnableWindow(false);
	m_check11.EnableWindow(false);
	m_check12.EnableWindow(false);
	m_check13.EnableWindow(false);
	m_check14.EnableWindow(false);
	m_check15.EnableWindow(false);

	m_at1.EnableWindow(false);
	m_at2.EnableWindow(false);
	m_at3.EnableWindow(false);
	m_at4.EnableWindow(false);
	m_at5.EnableWindow(false);
	m_at6.EnableWindow(false);
	m_at7.EnableWindow(false);
	m_at8.EnableWindow(false);
	m_at9.EnableWindow(false);
	m_at10.EnableWindow(false);
	m_at11.EnableWindow(false);
	m_at12.EnableWindow(false);
	m_at13.EnableWindow(false);
	m_at14.EnableWindow(false);
	m_at15.EnableWindow(false);

	m_reset.EnableWindow(false);

	DWORD LINE[] = { IDC_LINE1 ,IDC_LINE2, IDC_LINE3, IDC_LINE4, IDC_LINE5,
		IDC_LINE6, IDC_LINE7, IDC_LINE8, IDC_LINE9, IDC_LINE10, IDC_LINE11,
		IDC_LINE12, IDC_LINE13, IDC_LINE14, IDC_LINE15 };
	DWORD STATE[] = { IDC_STATE1 ,IDC_STATE2, IDC_STATE3, IDC_STATE4, IDC_STATE5,
	IDC_STATE6, IDC_STATE7, IDC_STATE8, IDC_STATE9, IDC_STATE10, IDC_STATE11,
	IDC_STATE12, IDC_STATE13, IDC_STATE14, IDC_STATE15 };
	DWORD TIME[] = { IDC_TIME1 ,IDC_TIME2, IDC_TIME3, IDC_TIME4, IDC_TIME5,
	IDC_TIME6, IDC_TIME7, IDC_TIME8, IDC_TIME9, IDC_TIME10, IDC_TIME11,
	IDC_TIME12, IDC_TIME13, IDC_TIME14, IDC_TIME15 };

	int state = ((CButton*)GetDlgItem(IDC_CHECK14))->GetCheck();

	while (state == 1) 
	{
		state = ((CButton*)GetDlgItem(IDC_CHECK14))->GetCheck();
		if (normal)
		{
			for (size_t i = 0; i < 15; i++)
			{
				state = ((CButton*)GetDlgItem(IDC_CHECK14))->GetCheck();
				if (state == 0) {
					break;
				}
				currentline = i;

				GetDlgItem(LINE[i])->GetWindowText(m_strLinetext);

				if (((CButton*)GetDlgItem(STATE[i]))->GetCheck() == 1 && m_strLinetext != "")
				{
					m_strLinetext += _T("\r\n");
					DWORD len = m_strLinetext.GetLength();

					BOOL test = m_cspi.WriteData((unsigned char*)CStringA(m_strLinetext.GetBuffer()).GetBuffer(), len);
					if (!test)
					{
						return;
					}

					m_boissend = true;

					CString m_str1, m_str2;
					DWORD len2 = m_cspi.GetBytesInCOM();

					m_tmTime = CTime::GetCurrentTime();
					m_str2 = m_tmTime.Format("[%Y-%m-%d  %X]");
					m_str1 += "\r\n";
					m_str1 += m_str2;
					m_str1 += " ->";
					m_str1 += "\r\n";
					m_str1 += m_strLinetext;

					m_text.SetSel(-1);
					m_text.ReplaceSel(m_str1);

					GetDlgItem(TIME[i])->GetWindowText(m_strTime);
					int sleeptime = _ttoi(m_strTime);
					Sleep(sleeptime);
				}
				else {
					break;
				}
			}
		}
		else 
		{
			for (size_t i = currentline; i < 15; i++)
			{
				state = ((CButton*)GetDlgItem(IDC_CHECK14))->GetCheck();
				if (state == 0) {
					break;
				}
				currentline = i;

				GetDlgItem(LINE[i])->GetWindowText(m_strLinetext);

				if (((CButton*)GetDlgItem(STATE[i]))->GetCheck() == 1 && m_strLinetext != "")
				{
					m_strLinetext += _T("\r\n");
					DWORD len = m_strLinetext.GetLength();

					BOOL test = m_cspi.WriteData((unsigned char*)CStringA(m_strLinetext.GetBuffer()).GetBuffer(), len);
					if (!test)
					{
						return;
					}

					m_boissend = true;

					CString m_str1, m_str2;
					DWORD len2 = m_cspi.GetBytesInCOM();

					m_tmTime = CTime::GetCurrentTime();
					m_str2 = m_tmTime.Format("[%Y-%m-%d  %X]");
					m_str1 += "\r\n";
					m_str1 += m_str2;
					m_str1 += " ->";
					m_str1 += "\r\n";
					m_str1 += m_strLinetext;

					m_text.SetSel(-1);
					m_text.ReplaceSel(m_str1);

					GetDlgItem(TIME[i])->GetWindowText(m_strTime);
					int sleeptime = _ttoi(m_strTime);
					Sleep(sleeptime);
				}

				if (i == 15)
				{
					normal = true;
					currentline = 0;
				}
			}
		}
		normal = true;
	}

	m_send.EnableWindow(true);
	m_reset.EnableWindow(true);

	m_line1.EnableWindow(true);
	m_line2.EnableWindow(true);
	m_line3.EnableWindow(true);
	m_line4.EnableWindow(true);
	m_line5.EnableWindow(true);
	m_line6.EnableWindow(true);
	m_line7.EnableWindow(true);
	m_line8.EnableWindow(true);
	m_line9.EnableWindow(true);
	m_line10.EnableWindow(true);
	m_line11.EnableWindow(true);
	m_line12.EnableWindow(true);
	m_line13.EnableWindow(true);
	m_line14.EnableWindow(true);
	m_line15.EnableWindow(true);

	m_time1.EnableWindow(true);
	m_time2.EnableWindow(true);
	m_time3.EnableWindow(true);
	m_time4.EnableWindow(true);
	m_time5.EnableWindow(true);
	m_time6.EnableWindow(true);
	m_time7.EnableWindow(true);
	m_time8.EnableWindow(true);
	m_time9.EnableWindow(true);
	m_time10.EnableWindow(true);
	m_wait11.EnableWindow(true);
	m_wait12.EnableWindow(true);
	m_wait13.EnableWindow(true);
	m_wait14.EnableWindow(true);
	m_wait15.EnableWindow(true);


	m_check1.EnableWindow(true);
	m_check2.EnableWindow(true);
	m_check3.EnableWindow(true);
	m_check4.EnableWindow(true);
	m_check5.EnableWindow(true);
	m_check6.EnableWindow(true);
	m_check7.EnableWindow(true);
	m_check8.EnableWindow(true);
	m_check9.EnableWindow(true);
	m_check10.EnableWindow(true);
	m_check11.EnableWindow(true);
	m_check12.EnableWindow(true);
	m_check13.EnableWindow(true);
	m_check14.EnableWindow(true);
	m_check15.EnableWindow(true);

	m_at1.EnableWindow(true);
	m_at2.EnableWindow(true);
	m_at3.EnableWindow(true);
	m_at4.EnableWindow(true);
	m_at5.EnableWindow(true);
	m_at6.EnableWindow(true);
	m_at7.EnableWindow(true);
	m_at8.EnableWindow(true);
	m_at9.EnableWindow(true);
	m_at10.EnableWindow(true);
	m_at11.EnableWindow(true);
	m_at12.EnableWindow(true);
	m_at13.EnableWindow(true);
	m_at14.EnableWindow(true);
	m_at15.EnableWindow(true);

	m_reset.EnableWindow(true);
}

void CATCOMMANDDlg::LoopSend()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strTempstr = m_Statusbar.GetPaneText(1);
	CButton* pBtn = (CButton*)GetDlgItem(IDC_CHECK14);
	int state = ((CButton*)GetDlgItem(IDC_CHECK14))->GetCheck();

	DWORD STATE[] = { IDC_STATE1 ,IDC_STATE2, IDC_STATE3, IDC_STATE4, IDC_STATE5,
	IDC_STATE6, IDC_STATE7, IDC_STATE8, IDC_STATE9, IDC_STATE10, IDC_STATE11,
	IDC_STATE12, IDC_STATE13, IDC_STATE14, IDC_STATE15 };

	if (!m_cspi.IsOpen()) 
	{
		MessageBox(TEXT("发送失败，串口未连接或已经拔出！"), TEXT("Warning"));
		pBtn->SetCheck(0);
		return;
	}

	else 
	{
		if (state == 1)
		{
			for (size_t i = 0; i < 15; ++i) {
				if (((CButton*)GetDlgItem(STATE[i]))->GetCheck() == 1) {
					AfxBeginThread(loopproc, (LPVOID)this);
					return;
				}
			}			
			
			CButton* pBtn = (CButton*)GetDlgItem(IDC_CHECK14);
			pBtn->SetCheck(0);
		}
	}
}

static UINT receivemessage(LPVOID  lParam)
{
	CATCOMMANDDlg* pWnd = (CATCOMMANDDlg*)lParam;
	pWnd->ReceiveThread();
	return 0;
}

void CATCOMMANDDlg::ReceiveThread() {
	//接收数据
	CString line, line2;

	while ((m_cspi.IsOpen()))
	{
		CString output;
		m_str = " <-";
		DWORD len2 = m_cspi.GetBytesInCOM();
		if (len2)
		{
				m_cspi.ReadData(buf2, len2, &len2);
				for (size_t i = 0; i < len2; i++)
				{
					CString test;
					test = buf2[i];

					if (test == "+") {
						numdbg += 1;
					}

					if (m_boissend == true) {
						numdbg = 0;
						receive = false;
						m_boissend = false;
					}

					if (test == "\n" && line != "")
					{
						m_text.SetSel(-1);
						m_text.ReplaceSel(test + "\r\n");
						line = "";
						continue;
					}

					else if (test == "\r" && receive == false)
					{
						m_tmTime = CTime::GetCurrentTime();
						m_str2 = m_tmTime.Format("[%Y-%m-%d  %X]");

						if (line != "")
						{
							m_text.SetSel(-1);
							m_text.ReplaceSel(m_str2 + m_str + "\r\n" + line);
							if (numdbg != 0) {
								receive = true;
							}
						}

					}
					else if (test == "\r" && receive == true)
					{
						if (line != "")
						{
							m_text.SetSel(-1);
							m_text.ReplaceSel(line);
						}
					}
					else
					{
						line += test;
					}
				}
		}
		else
		{
			Sleep(1);
			//AutoSave();
		} 
	}
	
	m_bOpenthread = false;

	return;
}


void CATCOMMANDDlg::OpenPortBT()
{
	// TODO: 在此添加命令处理程序代码
	Openport op;

	if (IDOK == op.DoModal())
	{
        if (m_cspi.InitPort(_ttoi(op.m_strchildport), _ttoi(op.m_strchildbd)))
        {
			m_strPort = op.m_strchildport;
			m_Statusbar.SetPaneText(1, TEXT("COM") + op.m_strchildport + TEXT("OPENED"));
			m_Statusbar.SetPaneText(2, op.m_strchildbd + TEXT(" bps"));
			CToolBarCtrl* pToolBar = (CToolBarCtrl*)&cToolBar.GetToolBarCtrl();
			pToolBar->EnableButton(IDR_TOOL1, false);
			CToolBarCtrl* pToolBar2 = (CToolBarCtrl*)&cToolBar.GetToolBarCtrl();
			pToolBar2->EnableButton(IDR_TOOL2, true);
            if (!m_bOpenthread) 
			{
				AfxBeginThread(receivemessage, (LPVOID)this);
                m_bOpenthread = true;
            }

        }
		else {
			MessageBox(_T("当前串口号无法打开！请检查后重新打开！"), _T("Warning"));
			OpenPortBT();
		}
	}
}	

void CATCOMMANDDlg::ClosePort()
{
	// TODO: 在此添加命令处理程序代码

	if ((m_cspi.IsOpen())) 
	{
		m_cspi.UnintPort();
		m_Statusbar.SetPaneText(1, TEXT("UNKNOWN PORT"));
	}
	else 
	{
		MessageBox(_T("串口未链接！"));
	}
	count = 0;

	CToolBarCtrl* pToolBar = (CToolBarCtrl*)&cToolBar.GetToolBarCtrl();
	pToolBar->EnableButton(IDR_TOOL2, false);
	CToolBarCtrl* pToolBar2 = (CToolBarCtrl*)&cToolBar.GetToolBarCtrl();
	pToolBar2->EnableButton(IDR_TOOL1, true);
}
 
void CATCOMMANDDlg::ClearLog()
{
	// TODO: 在此添加命令处理程序代码
	m_text.SetWindowTextW(TEXT(""));
}

void CATCOMMANDDlg::SaveLog()
{
	// TODO: 在此添加命令处理程序代码
	CString FileName;
	CString test;
	test = _T("DataLog_");
	m_tmTime = CTime::GetCurrentTime();
	m_str2 = m_tmTime.Format("%m%d_%Hh%Mm");
	test += m_str2;
	test += _T(".txt");

	CFileDialog dlgFile(FALSE, _T("*.txt"), test, OFN_HIDEREADONLY, _T("Describe File(*.txt)|*.txt|All Files(*.*)|*.*||"), NULL);
	if (IDOK == dlgFile.DoModal())
	{
		FileName = dlgFile.GetPathName();
	}
	else {
		return;
	}

	CStdioFile FileWrite;
	if (!FileWrite.Open(FileName, CFile::modeWrite | CFile::modeCreate | CFile::typeText))
	{
		MessageBox(_T("打开文件失败!"), TEXT("Warning"));
		return;
	}
	
	CString line;
	CString ch;

	GetDlgItem(IDC_EDIT1)->GetWindowText(m_strTempstr);
	for (size_t i = 0; i < m_strTempstr.GetLength(); ++i) {
		ch = m_strTempstr[i];
		if(ch == "\n") {
			continue;
		}
		else {
			line += ch;
		}
		if (ch == TEXT("\r")) {
			FileWrite.WriteString(line);
			line = "";
		}
	}

	FileWrite.Close(); 
}

void CATCOMMANDDlg::Exit()
{
	// TODO: 在此添加命令处理程序代码
	if (MessageBox(TEXT("确定要退出吗？"), TEXT("Warning"), MB_YESNO | MB_DEFBUTTON2) == IDYES)
	{
		CATCOMMANDDlg::OnCancel();
	}
}

static UINT myproc_1(LPVOID  lParam)
{
	CATCOMMANDDlg* pWnd = (CATCOMMANDDlg*)lParam;
	pWnd->Receive();

	return 0;
}

void CATCOMMANDDlg::Receive()
{
	// 主要处理函数在这里写  

	DWORD LINE[] = { IDC_LINE1 ,IDC_LINE2, IDC_LINE3, IDC_LINE4, IDC_LINE5,
	IDC_LINE6, IDC_LINE7, IDC_LINE8, IDC_LINE9, IDC_LINE10, IDC_LINE11,
	IDC_LINE12, IDC_LINE13, IDC_LINE14, IDC_LINE15 };

	DWORD TIME[] = { IDC_TIME1 ,IDC_TIME2, IDC_TIME3, IDC_TIME4, IDC_TIME5,
	IDC_TIME6, IDC_TIME7, IDC_TIME8, IDC_TIME9, IDC_TIME10, IDC_TIME11,
	IDC_TIME12, IDC_TIME13, IDC_TIME14, IDC_TIME15 };

	DWORD AT[] = { IDC_BTAT1 ,IDC_BTAT2, IDC_BTAT3, IDC_BTAT4, IDC_BTAT5,
	IDC_BTAT6, IDC_BTAT7, IDC_BTAT8, IDC_BTAT9, IDC_BTAT10, IDC_BTAT11,
	IDC_BTAT12, IDC_BTAT13, IDC_BTAT14, IDC_BTAT15 };

	CString filepath;
	CFileDialog TmpDlg(TRUE, _T("*.ini"), TEXT("AT_Command"), OFN_HIDEREADONLY, _T("Describe File(*.ini)|*.ini|All Files(*.*)|*.*||"), NULL);

	if (IDOK == TmpDlg.DoModal())
	{
		filepath = TmpDlg.GetPathName();
	}
	else {
		return;
	}

	for (size_t i = 0; i < 15; ++i)
	{
		CString str;
		CString attext, delay, atbt;
		CString buf1,buf2,buf3;
		str.Format(_T("%d"), i + 1);
		GetDlgItem(LINE[i])->GetWindowText(attext);
		GetDlgItem(TIME[i])->GetWindowText(delay);
		GetDlgItem(AT[i])->GetWindowText(atbt);

		GetPrivateProfileString(str, _T("AT Command"), CString("NULL"), buf1.GetBuffer(MAX_PATH), MAX_PATH, filepath);
		GetPrivateProfileString(str, _T("Delay(ms)"), CString("NULL"), buf2.GetBuffer(MAX_PATH), MAX_PATH, filepath);
		GetPrivateProfileString(str, _T("AT Notation"), CString("NULL"), buf3.GetBuffer(MAX_PATH), MAX_PATH, filepath);

		if (i == 0)
		{
			m_line1.SetWindowTextW(buf1);
			m_time1.SetWindowTextW(buf2);
			m_at1.SetWindowTextW(buf3);
		}
		else if (i == 1) 
		{
			m_line2.SetWindowTextW(buf1);
			m_time2.SetWindowTextW(buf2);
			m_at2.SetWindowTextW(buf3);
		}
		else if (i == 2) 
		{
			m_line3.SetWindowTextW(buf1);
			m_time3.SetWindowTextW(buf2);
			m_at3.SetWindowTextW(buf3);
		}
		else if (i == 3)
		{
			m_line4.SetWindowTextW(buf1);
			m_time4.SetWindowTextW(buf2);
			m_at4.SetWindowTextW(buf3);
		}
		else if (i == 4) 
		{
			m_line5.SetWindowTextW(buf1);
			m_time5.SetWindowTextW(buf2);
			m_at5.SetWindowTextW(buf3);
		}
		else if (i == 5) 
		{
			m_line6.SetWindowTextW(buf1);
			m_time6.SetWindowTextW(buf2);
			m_at6.SetWindowTextW(buf3);
		}
		else if (i == 6) 
		{
			m_line7.SetWindowTextW(buf1);
			m_time7.SetWindowTextW(buf2);
			m_at7.SetWindowTextW(buf3);
		}
		else if (i == 7) 
		{
			m_line8.SetWindowTextW(buf1);
			m_time8.SetWindowTextW(buf2);
			m_at8.SetWindowTextW(buf3);
		}
		else if (i == 8) 
		{
			m_line9.SetWindowTextW(buf1);
			m_time9.SetWindowTextW(buf2);
			m_at9.SetWindowTextW(buf3);
		}
		else if (i == 9) 
		{
			m_line10.SetWindowTextW(buf1);
			m_time10.SetWindowTextW(buf2);
			m_at10.SetWindowTextW(buf3);
		}
		else if (i == 10) 
		{
			m_line11.SetWindowTextW(buf1);
			m_wait11.SetWindowTextW(buf2);
			m_at11.SetWindowTextW(buf3);
		}
		else if (i == 11) 
		{
			m_line12.SetWindowTextW(buf1);
			m_wait12.SetWindowTextW(buf2);
			m_at12.SetWindowTextW(buf3);
		}
		else if (i == 12) 
		{
			m_line13.SetWindowTextW(buf1);
			m_wait13.SetWindowTextW(buf2);
			m_at13.SetWindowTextW(buf3);
		}
		else if (i == 13) 
		{
			m_line14.SetWindowTextW(buf1);
			m_wait14.SetWindowTextW(buf2);
			m_at14.SetWindowTextW(buf3);
		}
		else if (i == 14) 
		{
			m_line15.SetWindowTextW(buf1);
			m_wait15.SetWindowTextW(buf2);
			m_at15.SetWindowTextW(buf3);
		}
	}
}

void CATCOMMANDDlg::ImportAT()
{
	// TODO: 在此添加命令处理程序代码
	AfxBeginThread(myproc_1, (LPVOID)this);
}


void CATCOMMANDDlg::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDialogEx::OnLButtonDblClk(nFlags, point);
}

void CATCOMMANDDlg::ExportAt()
{
	// TODO: 在此添加命令处理程序代码

	DWORD LINE[] = { IDC_LINE1 ,IDC_LINE2, IDC_LINE3, IDC_LINE4, IDC_LINE5,
	IDC_LINE6, IDC_LINE7, IDC_LINE8, IDC_LINE9, IDC_LINE10, IDC_LINE11,
	IDC_LINE12, IDC_LINE13, IDC_LINE14, IDC_LINE15 };

	DWORD TIME[] = { IDC_TIME1 ,IDC_TIME2, IDC_TIME3, IDC_TIME4, IDC_TIME5,
	IDC_TIME6, IDC_TIME7, IDC_TIME8, IDC_TIME9, IDC_TIME10, IDC_TIME11,
	IDC_TIME12, IDC_TIME13, IDC_TIME14, IDC_TIME15 };

	DWORD AT[] = { IDC_BTAT1 ,IDC_BTAT2, IDC_BTAT3, IDC_BTAT4, IDC_BTAT5,
	IDC_BTAT6, IDC_BTAT7, IDC_BTAT8, IDC_BTAT9, IDC_BTAT10, IDC_BTAT11,
	IDC_BTAT12, IDC_BTAT13, IDC_BTAT14, IDC_BTAT15 };

	CString FileName;

	CFileDialog dlgFile(FALSE, _T("*.ini"), _T("AT_Command"), OFN_HIDEREADONLY, _T("Describe File(*.ini)|*.ini|All Files(*.*)|*.*||"), NULL);
	if (IDOK == dlgFile.DoModal())
	{
		FileName = dlgFile.GetPathName();
	}
	else {
		return;
	}

	for (size_t i = 0; i < 15; ++i)
	{
		CString str;
		CString attext, delay, atbt;
		str.Format(_T("%d"), i + 1);
		GetDlgItem(LINE[i])->GetWindowText(attext);
		GetDlgItem(TIME[i])->GetWindowText(delay);
		GetDlgItem(AT[i])->GetWindowText(atbt);
		WritePrivateProfileStringW(str, _T("AT Command"), attext, FileName);
		WritePrivateProfileStringW(str, _T("Delay(ms)"), delay, FileName);
		WritePrivateProfileStringW(str, _T("AT Notation"), atbt, FileName);
	}
}

void CATCOMMANDDlg::OnBnClickedBtat1()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_LINE1)->GetWindowText(m_strLinetext);

	if (!m_cspi.IsOpen()) 
	{
		MessageBox(TEXT("发送失败，串口未连接或已经拔出！"), TEXT("Warning"));
		return;
	}
	if (m_strLinetext == "") 
	{
		return;
	}
	AfxBeginThread(myproc1, (LPVOID)this);
}


void CATCOMMANDDlg::OnBnClickedBtat2()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_LINE2)->GetWindowText(m_strLinetext);

	if (!m_cspi.IsOpen()) 
	{
		MessageBox(TEXT("发送失败，串口未连接或已经拔出！"), TEXT("Warning"));
		return;
	}

	if (m_strLinetext == "") 
	{
		return;
	}
	AfxBeginThread(myproc2, (LPVOID)this);
}


void CATCOMMANDDlg::OnBnClickedBtat3()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_LINE3)->GetWindowText(m_strLinetext);

	if (!m_cspi.IsOpen()) 
	{
		MessageBox(TEXT("发送失败，串口未连接或已经拔出！"), TEXT("Warning"));
		return;
	}

	if (m_strLinetext == "") 
	{
		return;
	}
	AfxBeginThread(myproc3, (LPVOID)this);
}


void CATCOMMANDDlg::OnBnClickedBtat4()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_LINE4)->GetWindowText(m_strLinetext);

	if (!m_cspi.IsOpen()) 
	{
		MessageBox(TEXT("发送失败，串口未连接或已经拔出！"), TEXT("Warning"));
		return;
	}

	if (m_strLinetext == "") 
	{
		return;
	}
	AfxBeginThread(myproc4, (LPVOID)this);
}


void CATCOMMANDDlg::OnBnClickedBtat5()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_LINE5)->GetWindowText(m_strLinetext);
	
	if (!m_cspi.IsOpen()) 
	{
		MessageBox(TEXT("发送失败，串口未连接或已经拔出！"), TEXT("Warning"));
		return;
	}

	if (m_strLinetext == "") 
	{
		return;
	}
	AfxBeginThread(myproc5, (LPVOID)this);
}


void CATCOMMANDDlg::OnBnClickedBtat6()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_LINE6)->GetWindowText(m_strLinetext);
	
	if (!m_cspi.IsOpen()) 
	{
		MessageBox(TEXT("发送失败，串口未连接或已经拔出！"), TEXT("Warning"));
		return;
	}

	if (m_strLinetext == "") 
	{
		return;
	}
	AfxBeginThread(myproc6, (LPVOID)this);
}

void CATCOMMANDDlg::OnBnClickedBtat7()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_LINE7)->GetWindowText(m_strLinetext);
	
	if (!m_cspi.IsOpen()) 
	{
		MessageBox(TEXT("发送失败，串口未连接或已经拔出！"), TEXT("Warning"));
		return;
	}

	if (m_strLinetext == "") 
	{
		return;
	}
	AfxBeginThread(myproc7, (LPVOID)this);
}


void CATCOMMANDDlg::OnBnClickedBtat8()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_LINE8)->GetWindowText(m_strLinetext);
	
	if (!m_cspi.IsOpen()) 
	{
		MessageBox(TEXT("发送失败，串口未连接或已经拔出！"), TEXT("Warning"));
		return;
	}

	if (m_strLinetext == "") 
	{
		return;
	}
	AfxBeginThread(myproc8, (LPVOID)this);
}


void CATCOMMANDDlg::OnBnClickedBtat9()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_LINE9)->GetWindowText(m_strLinetext);
	
	if (!m_cspi.IsOpen()) 
	{
		MessageBox(TEXT("发送失败，串口未连接或已经拔出！"), TEXT("Warning"));
		return;
	}

	if (m_strLinetext == "") 
	{
		return;
	}
	AfxBeginThread(myproc9, (LPVOID)this);
}


void CATCOMMANDDlg::OnBnClickedBtat10()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_LINE10)->GetWindowText(m_strLinetext);
	
	if (!m_cspi.IsOpen()) 
	{
		MessageBox(TEXT("发送失败，串口未连接或已经拔出！"), TEXT("Warning"));
		return;
	}

	if (m_strLinetext == "") 
	{
		return;
	}
	AfxBeginThread(myproc10, (LPVOID)this);
}


void CATCOMMANDDlg::OnBnClickedBtat11()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_LINE11)->GetWindowText(m_strLinetext);
	
	if (!m_cspi.IsOpen()) 
	{
		MessageBox(TEXT("发送失败，串口未连接或已经拔出！"), TEXT("Warning"));
		return;
	}

	if (m_strLinetext == "") 
	{
		return;
	}
	AfxBeginThread(myproc11, (LPVOID)this);
}


void CATCOMMANDDlg::OnBnClickedBtat12()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_LINE12)->GetWindowText(m_strLinetext);
	
	if (!m_cspi.IsOpen()) 
	{
		MessageBox(TEXT("发送失败，串口未连接或已经拔出！"), TEXT("Warning"));
		return;
	}

	if (m_strLinetext == "") 
	{
		return;
	}
	AfxBeginThread(myproc12, (LPVOID)this);
}


void CATCOMMANDDlg::OnBnClickedBtat13()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_LINE13)->GetWindowText(m_strLinetext);
	
	if (!m_cspi.IsOpen()) 
	{
		MessageBox(TEXT("发送失败，串口未连接或已经拔出！"), TEXT("Warning"));
		return;
	}

	if (m_strLinetext == "") 
	{
		return;
	}
	AfxBeginThread(myproc13, (LPVOID)this);
}


void CATCOMMANDDlg::OnBnClickedBtat15()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_LINE14)->GetWindowText(m_strLinetext);
	
	if (!m_cspi.IsOpen()) 
	{
		MessageBox(TEXT("发送失败，串口未连接或已经拔出！"), TEXT("Warning"));
		return;
	}

	if (m_strLinetext == "") 
	{
		return;
	}
	AfxBeginThread(myproc14, (LPVOID)this);
}


void CATCOMMANDDlg::OnBnClickedBtat14()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_LINE15)->GetWindowText(m_strLinetext);
	
	if (!m_cspi.IsOpen()) 
	{
		MessageBox(TEXT("发送失败，串口未连接或已经拔出！"), TEXT("Warning"));
		return;
	}

	if (m_strLinetext == "") 
	{
		return;
	}
	AfxBeginThread(myproc15, (LPVOID)this);
}

void CATCOMMANDDlg::OnEnChangeLoop()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	GetDlgItem(IDC_LOOP)->GetWindowText(m_str);//获取编辑框内容

	if (m_str.SpanIncluding(_T("0123456789.")) != m_str) 
	{
		m_loopcount.SetWindowText(_T(""));
	}
}


BOOL CATCOMMANDDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN && GetDlgItem(IDC_HISTORY) == GetFocus()->GetParent())
	{
		OnBnClickedSend();
	}

	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN && pMsg->hwnd == GetDlgItem(IDC_LINE1)->GetSafeHwnd())
	{
		OnBnClickedBtat1();
	}

	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN && pMsg->hwnd == GetDlgItem(IDC_LINE2)->GetSafeHwnd())
	{
		OnBnClickedBtat2();
	}

	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN && pMsg->hwnd == GetDlgItem(IDC_LINE3)->GetSafeHwnd())
	{
		OnBnClickedBtat3();
	}

	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN && pMsg->hwnd == GetDlgItem(IDC_LINE4)->GetSafeHwnd())
	{
		OnBnClickedBtat4();
	}

	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN && pMsg->hwnd == GetDlgItem(IDC_LINE5)->GetSafeHwnd())
	{
		OnBnClickedBtat5();
	}

	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN && pMsg->hwnd == GetDlgItem(IDC_LINE6)->GetSafeHwnd())
	{
		OnBnClickedBtat6();
	}

	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN && pMsg->hwnd == GetDlgItem(IDC_LINE7)->GetSafeHwnd())
	{
		OnBnClickedBtat7();
	}

	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN && pMsg->hwnd == GetDlgItem(IDC_LINE8)->GetSafeHwnd())
	{
		OnBnClickedBtat8();
	}

	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN && pMsg->hwnd == GetDlgItem(IDC_LINE9)->GetSafeHwnd())
	{
		OnBnClickedBtat9();
	}

	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN && pMsg->hwnd == GetDlgItem(IDC_LINE10)->GetSafeHwnd())
	{
		OnBnClickedBtat10();
	}

	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN && pMsg->hwnd == GetDlgItem(IDC_LINE11)->GetSafeHwnd())
	{
		OnBnClickedBtat11();
	}

	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN && pMsg->hwnd == GetDlgItem(IDC_LINE12)->GetSafeHwnd())
	{
		OnBnClickedBtat12();
	}

	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN && pMsg->hwnd == GetDlgItem(IDC_LINE13)->GetSafeHwnd())
	{
		OnBnClickedBtat13();
	}

	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN && pMsg->hwnd == GetDlgItem(IDC_LINE14)->GetSafeHwnd())
	{
		OnBnClickedBtat14();
	}

	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN && pMsg->hwnd == GetDlgItem(IDC_LINE15)->GetSafeHwnd())
	{
		OnBnClickedBtat15();
	}

	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
	{
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
	
}


void CATCOMMANDDlg::OnEnSetfocusEdit1()
{
	// TODO: 在此添加控件通知处理程序代码
	// 隐藏鼠标
	//::HideCaret(GetDlgItem(IDC_EDIT1)->GetSafeHwnd()); 
}


void CATCOMMANDDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。


	// TODO:  在此添加控件通知处理程序代码
	//int nLen = m_ptrtext->GetWindowTextLength();
	//m_ptrtext->SetSel(nLen, nLen);
	
	m_text.SetFocus();
	m_text.GetWindowText(m_strtext);
	int nLength = m_strtext.GetLength();
	m_text.SetSel(nLength, nLength, FALSE);
}

void CATCOMMANDDlg::AutoSave()
{
	// TODO: 在此添加命令处理程序代码
	CString FileName;
	CString test;
	test = _T("DataLog_");
	m_tmTime = CTime::GetCurrentTime();
	m_str2 = m_tmTime.Format("%m%d_%Hh%Mm");
	test += m_str2;
	test += _T(".txt");

	CFileDialog dlgFile(FALSE, _T("*.txt"), test, OFN_HIDEREADONLY, _T("Describe File(*.txt)|*.txt|All Files(*.*)|*.*||"), NULL);

	CStdioFile FileWrite;
	FileName = dlgFile.GetPathName();
	if (!FileWrite.Open(FileName, CFile::modeWrite | CFile::modeCreate | CFile::typeText))
	{
		MessageBox(_T("打开文件失败!"), TEXT("Warning"));
		return;
	}

	CString line;
	CString ch;

	GetDlgItem(IDC_EDIT1)->GetWindowText(m_strTempstr);
	for (size_t i = 0; i < m_strTempstr.GetLength(); ++i) {
		ch = m_strTempstr[i];
		if(ch == "\n") {
			continue;
		}
		else {
			line += ch;
		}
		if (ch == TEXT("\r")) {
			FileWrite.WriteString(line);
			line = "";
		}
	}

	FileWrite.Close();
}

void CATCOMMANDDlg::OnIdrTool1()
{
	// TODO: 在此添加命令处理程序代码
	OpenPortBT();
}


void CATCOMMANDDlg::OnIdrTool2()
{
	// TODO: 在此添加命令处理程序代码
	if ((m_cspi.IsOpen()))
	{
		m_cspi.UnintPort();
		m_Statusbar.SetPaneText(1, TEXT("UNKNOWN PORT"));
	}
	else
	{
		MessageBox(_T("串口未链接！"));
	}
	count = 0;

	CToolBarCtrl* pToolBar = (CToolBarCtrl*)&cToolBar.GetToolBarCtrl();
	pToolBar->EnableButton(IDR_TOOL2, false);

	CToolBarCtrl* pToolBar2 = (CToolBarCtrl*)&cToolBar.GetToolBarCtrl();
	pToolBar2->EnableButton(IDR_TOOL1, true);
}


void CATCOMMANDDlg::OnIdrTool3()
{
	// TODO: 在此添加命令处理程序代码
		// TODO: 在此添加命令处理程序代码
	m_text.SetWindowTextW(TEXT(""));
}

void CATCOMMANDDlg::OnIdrTool4()
{
	// TODO: 在此添加命令处理程序代码
	SaveLog();
}


void CATCOMMANDDlg::OnIdrTool5()
{
	// TODO: 在此添加命令处理程序代码
	AfxBeginThread(myproc_1, (LPVOID)this);
}


void CATCOMMANDDlg::OnIdrTool6()
{
	// TODO: 在此添加命令处理程序代码
	ExportAt();
}

void CATCOMMANDDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	GetDlgItem(IDC_LINE1)->GetWindowText(line1);
	GetDlgItem(IDC_LINE2)->GetWindowText(line2);
	GetDlgItem(IDC_LINE3)->GetWindowText(line3);
	GetDlgItem(IDC_LINE4)->GetWindowText(line4);
	GetDlgItem(IDC_LINE5)->GetWindowText(line5);
	GetDlgItem(IDC_LINE6)->GetWindowText(line6);
	GetDlgItem(IDC_LINE7)->GetWindowText(line7);
	GetDlgItem(IDC_LINE8)->GetWindowText(line8);
	GetDlgItem(IDC_LINE9)->GetWindowText(line9);
	GetDlgItem(IDC_LINE10)->GetWindowText(line10);
	GetDlgItem(IDC_LINE11)->GetWindowText(line11);
	GetDlgItem(IDC_LINE12)->GetWindowText(line12);
	GetDlgItem(IDC_LINE13)->GetWindowText(line13);
	GetDlgItem(IDC_LINE14)->GetWindowText(line14);
	GetDlgItem(IDC_LINE15)->GetWindowText(line15);

	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_string1"), line1);
	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_string2"), line2);
	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_string3"), line3);
	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_string4"), line4);
	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_string5"), line5);
	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_string6"), line6);
	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_string7"), line7);
	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_string8"), line8);
	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_string9"), line9);
	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_string10"), line10);
	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_string11"), line11);
	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_string12"), line12);
	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_string13"), line13);
	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_string14"), line14);
	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_string15"), line15);

	GetDlgItem(IDC_LOOP)->GetWindowText(time);
	GetDlgItem(IDC_TIME1)->GetWindowText(time1);
	GetDlgItem(IDC_TIME2)->GetWindowText(time2);
	GetDlgItem(IDC_TIME3)->GetWindowText(time3);
	GetDlgItem(IDC_TIME4)->GetWindowText(time4);
	GetDlgItem(IDC_TIME5)->GetWindowText(time5);
	GetDlgItem(IDC_TIME6)->GetWindowText(time6);
	GetDlgItem(IDC_TIME7)->GetWindowText(time7);
	GetDlgItem(IDC_TIME8)->GetWindowText(time8);
	GetDlgItem(IDC_TIME9)->GetWindowText(time9);
	GetDlgItem(IDC_TIME10)->GetWindowText(time10);
	GetDlgItem(IDC_TIME11)->GetWindowText(time11);
	GetDlgItem(IDC_TIME12)->GetWindowText(time12);
	GetDlgItem(IDC_TIME13)->GetWindowText(time13);
	GetDlgItem(IDC_TIME14)->GetWindowText(time14);
	GetDlgItem(IDC_TIME15)->GetWindowText(time15);

	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_time"), time);
	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_time1"), time1);
	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_time2"), time2);
	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_time3"), time3);
	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_time4"), time4);
	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_time5"), time5);
	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_time6"), time6);
	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_time7"), time7);
	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_time8"), time8);
	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_time9"), time9);
	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_time10"), time10);
	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_time11"), time11);
	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_time12"), time12);
	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_time13"), time13);
	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_time14"), time14);
	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_time15"), time15);

	GetDlgItem(IDC_HISTORY)->GetWindowText(at);
	GetDlgItem(IDC_BTAT1)->GetWindowText(at1);
	GetDlgItem(IDC_BTAT2)->GetWindowText(at2);
	GetDlgItem(IDC_BTAT3)->GetWindowText(at3);
	GetDlgItem(IDC_BTAT4)->GetWindowText(at4);
	GetDlgItem(IDC_BTAT5)->GetWindowText(at5);
	GetDlgItem(IDC_BTAT6)->GetWindowText(at6);
	GetDlgItem(IDC_BTAT7)->GetWindowText(at7);
	GetDlgItem(IDC_BTAT8)->GetWindowText(at8);
	GetDlgItem(IDC_BTAT9)->GetWindowText(at9);
	GetDlgItem(IDC_BTAT10)->GetWindowText(at10);
	GetDlgItem(IDC_BTAT11)->GetWindowText(at11);
	GetDlgItem(IDC_BTAT12)->GetWindowText(at12);
	GetDlgItem(IDC_BTAT13)->GetWindowText(at13);
	GetDlgItem(IDC_BTAT14)->GetWindowText(at14);
	GetDlgItem(IDC_BTAT15)->GetWindowText(at15);

	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_at"), at);
	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_at1"), at1);
	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_at2"), at2);
	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_at3"), at3);
	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_at4"), at4);
	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_at5"), at5);
	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_at6"), at6);
	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_at7"), at7);
	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_at8"), at8);
	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_at9"), at9);
	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_at10"), at10);
	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_at11"), at11);
	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_at12"), at12);
	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_at13"), at13);
	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_at14"), at14);
	AfxGetApp()->WriteProfileString(_T("Setting"), _T("m_at15"), at15);

	AutoSave();
	CDialogEx::OnClose();
}


void CATCOMMANDDlg::OnBnClickedButton25()
{
	// TODO: 在此添加控件通知处理程序代码
	m_time1.SetWindowText(_T("1000"));
	m_time2.SetWindowText(_T("1000"));
	m_time3.SetWindowText(_T("1000"));
	m_time4.SetWindowText(_T("1000"));
	m_time5.SetWindowText(_T("1000"));
	m_time6.SetWindowText(_T("1000"));
	m_time7.SetWindowText(_T("1000"));
	m_time8.SetWindowText(_T("1000"));
	m_time9.SetWindowText(_T("1000"));
	m_time10.SetWindowText(_T("1000"));
	m_wait11.SetWindowText(_T("1000"));
	m_wait12.SetWindowText(_T("1000"));
	m_wait13.SetWindowText(_T("1000"));
	m_wait14.SetWindowText(_T("1000"));
	m_wait15.SetWindowText(_T("1000"));

	m_line1.SetWindowText(_T("")); 
	m_line2.SetWindowText(_T("")); 
	m_line3.SetWindowText(_T(""));  
	m_line4.SetWindowText(_T("")); 
	m_line5.SetWindowText(_T("")); 
	m_line6.SetWindowText(_T("")); 
	m_line7.SetWindowText(_T("")); 
	m_line8.SetWindowText(_T("")); 
	m_line9.SetWindowText(_T("")); 
	m_line10.SetWindowText(_T("")); 
	m_line11.SetWindowText(_T("")); 
	m_line12.SetWindowText(_T("")); 
	m_line13.SetWindowText(_T("")); 
	m_line14.SetWindowText(_T("")); 
	m_line15.SetWindowText(_T(""));

	m_at1.SetWindowText(_T("AT1"));
	m_at2.SetWindowText(_T("AT2"));
	m_at3.SetWindowText(_T("AT3"));
	m_at4.SetWindowText(_T("AT4"));
	m_at5.SetWindowText(_T("AT5"));
	m_at6.SetWindowText(_T("AT6"));
	m_at7.SetWindowText(_T("AT7"));
	m_at8.SetWindowText(_T("AT8"));
	m_at9.SetWindowText(_T("AT9"));
	m_at10.SetWindowText(_T("AT10"));
	m_at11.SetWindowText(_T("AT11"));
	m_at12.SetWindowText(_T("AT12"));
	m_at13.SetWindowText(_T("AT13"));
	m_at14.SetWindowText(_T("AT14"));
	m_at15.SetWindowText(_T("AT15"));

	DWORD LINE[] = { IDC_LINE1 ,IDC_LINE2, IDC_LINE3, IDC_LINE4, IDC_LINE5,
	IDC_LINE6, IDC_LINE7, IDC_LINE8, IDC_LINE9, IDC_LINE10, IDC_LINE11,
	IDC_LINE12, IDC_LINE13, IDC_LINE14, IDC_LINE15 };

	DWORD STATE[] = { IDC_STATE1 ,IDC_STATE2, IDC_STATE3, IDC_STATE4, IDC_STATE5,
	IDC_STATE6, IDC_STATE7, IDC_STATE8, IDC_STATE9, IDC_STATE10, IDC_STATE11,
	IDC_STATE12, IDC_STATE13, IDC_STATE14, IDC_STATE15 };

	((CButton*)GetDlgItem(IDC_SELECTALL))->SetCheck(0);
	for (size_t i = 0; i < 15; ++i)
	{
		GetDlgItem(LINE[i])->GetWindowText(m_strTempstr);
		CButton* pBtn = (CButton*)GetDlgItem(STATE[i]);
		pBtn->SetCheck(0);
	}
}


void CATCOMMANDDlg::OnEnChangeTime1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	GetDlgItem(IDC_TIME1)->GetWindowText(m_str);

	if (m_str.SpanIncluding(_T("0123456789.")) != m_str)
	{
		 m_time1.SetWindowText(_T(""));
	}
}


void CATCOMMANDDlg::OnEnChangeTime2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	GetDlgItem(IDC_TIME2)->GetWindowText(m_str);//获取编辑框内容

	if (m_str.SpanIncluding(_T("0123456789.")) != m_str)
	{
		m_time2.SetWindowText(_T(""));
	}
}


void CATCOMMANDDlg::OnEnChangeTime3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	GetDlgItem(IDC_TIME3)->GetWindowText(m_str);//获取编辑框内容

	if (m_str.SpanIncluding(_T("0123456789.")) != m_str)
	{
		m_time3.SetWindowText(_T(""));
	}
}


void CATCOMMANDDlg::OnEnChangeTime4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	GetDlgItem(IDC_TIME4)->GetWindowText(m_str);//获取编辑框内容

	if (m_str.SpanIncluding(_T("0123456789.")) != m_str)
	{
		m_time4.SetWindowText(_T(""));
	}
}


void CATCOMMANDDlg::OnEnChangeTime5()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	GetDlgItem(IDC_TIME5)->GetWindowText(m_str);//获取编辑框内容

	if (m_str.SpanIncluding(_T("0123456789.")) != m_str)
	{
		m_time5.SetWindowText(_T(""));
	}
}


void CATCOMMANDDlg::OnEnChangeTime6()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	GetDlgItem(IDC_TIME6)->GetWindowText(m_str);//获取编辑框内容

	if (m_str.SpanIncluding(_T("0123456789.")) != m_str)
	{
		m_time6.SetWindowText(_T(""));
	}
}


void CATCOMMANDDlg::OnEnChangeTime7()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	GetDlgItem(IDC_TIME7)->GetWindowText(m_str);//获取编辑框内容

	if (m_str.SpanIncluding(_T("0123456789.")) != m_str)
	{
		m_time7.SetWindowText(_T(""));
	}
}


void CATCOMMANDDlg::OnEnChangeTime8()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	GetDlgItem(IDC_TIME8)->GetWindowText(m_str);//获取编辑框内容

	if (m_str.SpanIncluding(_T("0123456789.")) != m_str)
	{
		m_time8.SetWindowText(_T(""));
	}
}


void CATCOMMANDDlg::OnEnChangeTime9()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	GetDlgItem(IDC_TIME9)->GetWindowText(m_str);//获取编辑框内容

	if (m_str.SpanIncluding(_T("0123456789.")) != m_str)
	{
		m_time9.SetWindowText(_T(""));
	}
}


void CATCOMMANDDlg::OnEnChangeTime10()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	GetDlgItem(IDC_TIME10)->GetWindowText(m_str);//获取编辑框内容

	if (m_str.SpanIncluding(_T("0123456789.")) != m_str)
	{
		m_time10.SetWindowText(_T(""));
	}
}


void CATCOMMANDDlg::OnEnChangeTime11()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	GetDlgItem(IDC_TIME11)->GetWindowText(m_str);//获取编辑框内容

	if (m_str.SpanIncluding(_T("0123456789.")) != m_str)
	{
		m_wait11.SetWindowText(_T(""));
	}
}


void CATCOMMANDDlg::OnEnChangeTime12()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	GetDlgItem(IDC_TIME12)->GetWindowText(m_str);//获取编辑框内容

	if (m_str.SpanIncluding(_T("0123456789.")) != m_str)
	{
		m_wait12.SetWindowText(_T(""));
	}
}


void CATCOMMANDDlg::OnEnChangeTime13()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	GetDlgItem(IDC_TIME13)->GetWindowText(m_str);//获取编辑框内容

	if (m_str.SpanIncluding(_T("0123456789.")) != m_str)
	{
		m_wait13.SetWindowText(_T(""));
	}
}


void CATCOMMANDDlg::OnEnChangeTime14()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	GetDlgItem(IDC_TIME14)->GetWindowText(m_str);//获取编辑框内容

	if (m_str.SpanIncluding(_T("0123456789.")) != m_str)
	{
		m_wait14.SetWindowText(_T(""));
	}
}


void CATCOMMANDDlg::OnEnChangeTime15()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	GetDlgItem(IDC_TIME15)->GetWindowText(m_str);//获取编辑框内容

	if (m_str.SpanIncluding(_T("0123456789.")) != m_str)
	{
		m_wait15.SetWindowText(_T(""));
	}
}



void CATCOMMANDDlg::OnBnClickedSelectall()
{
	// TODO: 在此添加控件通知处理程序代码
	DWORD LINE[] = { IDC_LINE1 ,IDC_LINE2, IDC_LINE3, IDC_LINE4, IDC_LINE5,
	IDC_LINE6, IDC_LINE7, IDC_LINE8, IDC_LINE9, IDC_LINE10, IDC_LINE11,
	IDC_LINE12, IDC_LINE13, IDC_LINE14, IDC_LINE15 };

	DWORD STATE[] = { IDC_STATE1 ,IDC_STATE2, IDC_STATE3, IDC_STATE4, IDC_STATE5,
	IDC_STATE6, IDC_STATE7, IDC_STATE8, IDC_STATE9, IDC_STATE10, IDC_STATE11,
	IDC_STATE12, IDC_STATE13, IDC_STATE14, IDC_STATE15 };

	int state = ((CButton*)GetDlgItem(IDC_SELECTALL))->GetCheck();
	if (state == 1) {
		for (size_t i = 0; i < 15; ++i)
		{
			GetDlgItem(LINE[i])->GetWindowText(m_strTempstr);
			if (m_strTempstr != "")
			{
				CButton* pBtn = (CButton*)GetDlgItem(STATE[i]);
				pBtn->SetCheck(1);
			}
		}
	}
	else {
		for (size_t i = 0; i < 15; ++i)
		{
			GetDlgItem(LINE[i])->GetWindowText(m_strTempstr);
			CButton* pBtn = (CButton*)GetDlgItem(STATE[i]);
			pBtn->SetCheck(0);
		}
	}
}
