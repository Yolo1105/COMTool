
// ATCOMMANDDlg.h: 头文件
//

#pragma once
#include "SerialPortInfo.h"
#include "Test.h"
#include <vector>

using namespace std;

// CATCOMMANDDlg 对话框
class CATCOMMANDDlg : public CDialogEx
{
// 构造
public:
	CATCOMMANDDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ATCOMMAND_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg BOOL OnDeviceChange(UINT nEventType, DWORD dwData); 
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point); 
	DECLARE_MESSAGE_MAP()

public:


	CSerialPortInfo m_cspi;

	CStatusBar	m_Statusbar;
	CRect m_DlgRect;

	vector<CString> m_vecHistory;
	CMenu m_Menu;

	CUIntArray ports; 	        
	CUIntArray portse;	 
	CUIntArray portsu;   

	CString m_str, m_str1, m_str2;
	CString m_strWord;
	CString m_strTempstr; 
	CString m_strLinetext;
	CString m_strStatus;
	CString m_strTime;

	CTime m_tmTime;

	CWinThread* MyThread;

	BOOL m_bostatus = true;
	BOOL restart = false;
	BOOL connect = true;
	BOOL check = false;
	BOOL check2 = false;

	int count = 0;

	char* buf = new char[1024]();
	char* buf2 = new char[1024]();

	BOOL click = false;
	BOOL found = false;

	int totalport = 0;
	int currentline = 0;

	BOOL normal = true;
	BOOL m_boissend = false;
	BOOL m_bOpenthread = false;
	CString	m_strCmd;
	int		m_nSleep;
	CString m_strPort;

	BOOL threadend = false;
	BOOL threadstart = false;

	BOOL receive = false;
	int numdbg = 0;

	// CATCOMMANDDlg 对话框
	BOOL AutoFitScreen(CREATESTRUCT& cs);
	void OnBnClickedSend();
	void Send();
	void DelaySend();
	void Receive(); 

	CString* pByte;
	CEdit m_text;
	CEdit* m_ptrtext = &m_text;
	CButton m_loop;
	CEdit m_loopcount;
	CButton m_checkbox;
	CButton m_send;
	CToolBar cToolBar;

	Test m_line1; 
	Test m_line2;
	Test m_line3;
	Test m_line4;
	Test m_line5;
	Test m_line6;
	Test m_line7;
	Test m_line8;
	Test m_line9;
	Test m_line10;
	Test m_line11;
	Test m_line12;
	Test m_line13;
	Test m_line14;
	Test m_line15;

	CEdit m_time1;
	CEdit m_time2;
	CEdit m_time3;
	CEdit m_time4;
	CEdit m_time5;
	CEdit m_time6;
	CEdit m_time7;
	CEdit m_time8;
	CEdit m_time9;
	CEdit m_time10;
	CEdit m_wait11;
	CEdit m_wait12;
	CEdit m_wait13;
	CEdit m_wait14;
	CEdit m_wait15;

	CButton m_send1;
	CButton m_send2;
	CButton m_send3;
	CButton m_send4;
	CButton m_send5;
	CButton m_send6;
	CButton m_send7;
	CButton m_send8;
	CButton m_send9;
	CButton m_send10;
	CButton m_send11;
	CButton m_send12;
	CButton m_send13;
	CButton m_send14;
	CButton m_send15;

	CComboBox m_histroy;
	CButton m_check1;
	CEdit m_sp;
	CEdit m_bd;

	CButton m_at1;
	CButton m_at2;
	CButton m_at3;
	CButton m_at4;
	CButton m_at5;
	CButton m_at6;
	CButton m_at7;
	CButton m_at8;
	CButton m_at9;
	CButton m_at10;
	CButton m_at11;
	CButton m_at12;
	CButton m_at13;
	CButton m_at14;
	CButton m_at15;

	void LoopSend();
	void OpenPortBT();
	void ClosePort();
	void ClearLog();
	void SaveLog();
	void Exit();

	void ImportAT();
	void ExportAt();

	void ThreadSend1();
	void ThreadSend2();
	void ThreadSend3();
	void ThreadSend4();
	void ThreadSend5();
	void ThreadSend6();
	void ThreadSend7();
	void ThreadSend8();
	void ThreadSend9();
	void ThreadSend10();
	void ThreadSend11();
	void ThreadSend12();
	void ThreadSend13();
	void ThreadSend14();
	void ThreadSend15();

	void OnBnClickedBtat1();
	void OnBnClickedBtat2();
	void OnBnClickedBtat3();
	void OnBnClickedBtat4();
	void OnBnClickedBtat5();
	void OnBnClickedBtat6();
	void OnBnClickedBtat7();
	void OnBnClickedBtat8();
	void OnBnClickedBtat9();
	void OnBnClickedBtat10();
	void OnBnClickedBtat11();
	void OnBnClickedBtat12();
	void OnBnClickedBtat13();
	void OnBnClickedBtat14();
	void OnBnClickedBtat15();

	void LoopThread();
	void SendThread();
	void ReceiveThread();
	afx_msg void OnEnChangeLoop();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnEnSetfocusEdit1();
	afx_msg void OnEnChangeEdit1();
	CString m_strtext;

	void AutoSave();
	CButton m_check2;
	CButton m_check3;
	CButton m_check4;
	CButton m_check5;
	CButton m_check6;
	CButton m_check7;
	CButton m_check8;
	CButton m_check9;
	CButton m_check10;
	CButton m_check11;
	CButton m_check12;
	CButton m_check13;
	CButton m_check14;
	CButton m_check15;
	afx_msg void OnIdrTool1();
	afx_msg void OnIdrTool2();
	afx_msg void OnIdrTool3();
	afx_msg void OnIdrTool4();
	afx_msg void OnIdrTool5();
	afx_msg void OnIdrTool6();

	CString line1;
	CString line2;
	CString line3;
	CString line4;
	CString line5;
	CString line6;
	CString line7;
	CString line8;
	CString line9;
	CString line10;
	CString line11;
	CString line12;
	CString line13;
	CString line14;
	CString line15;

	CString time;
	CString time1;
	CString time2;
	CString time3;
	CString time4;
	CString time5;
	CString time6;
	CString time7;
	CString time8;
	CString time9;
	CString time10;
	CString time11;
	CString time12;
	CString time13;
	CString time14;
	CString time15;

	CString at;
	CString at1;
	CString at2;
	CString at3;
	CString at4;
	CString at5;
	CString at6;
	CString at7;
	CString at8;
	CString at9;
	CString at10;
	CString at11;
	CString at12;
	CString at13;
	CString at14;
	CString at15;

	CImageList m_IconList;
	void OnLoadToolBarBitmap();

	BOOL OnToolNotify(UINT id, NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClose();
	afx_msg void OnBnClickedButton25();
	afx_msg void OnEnChangeTime1();
	afx_msg void OnEnChangeTime2();
	afx_msg void OnEnChangeTime3();
	afx_msg void OnEnChangeTime4();
	afx_msg void OnEnChangeTime5();
	afx_msg void OnEnChangeTime6();
	afx_msg void OnEnChangeTime7();
	afx_msg void OnEnChangeTime8();
	afx_msg void OnEnChangeTime9();
	afx_msg void OnEnChangeTime10();
	afx_msg void OnEnChangeTime11();
	afx_msg void OnEnChangeTime12();
	afx_msg void OnEnChangeTime13();
	afx_msg void OnEnChangeTime15();
	afx_msg void OnEnChangeTime14();
	CButton m_reset;
	afx_msg void OnBnClickedSelectall();
};
