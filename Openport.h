#pragma once
#include "afxdialogex.h"
#include "SerialPortInfo.h"
#include "ATCOMMANDDLG.h"

// Openport 对话框

class Openport : public CDialogEx
{
	DECLARE_DYNAMIC(Openport)

public:
	Openport(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Openport();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	CUIntArray ports; 	//所有存在的串口          
	CUIntArray portse;	//可用的串口    
	CUIntArray portsu;   //已占用的串口 

	CComboBox m_sp;
	CComboBox m_bd;
	CSerialPortInfo m_cspi;
	CButton m_close;
	CButton m_open;

	virtual BOOL OnInitDialog();
	afx_msg void PortInfo();
	afx_msg void SerialPortCombo();
	afx_msg void OpenPort();
	afx_msg void ClosePort();

	void PortSetting();

	BOOL canopen = true;
	BOOL add = true;

	int totalport = 1;
	
	void portsettingthread();
	void openportthread();

	CString m_strchildport;
	CString m_strchildbd;

	vector<CString> m_vecports;
};
