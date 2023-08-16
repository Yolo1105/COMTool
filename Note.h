#pragma once
#include "afxdialogex.h"


// Note 对话框

class Note : public CDialogEx
{
	DECLARE_DYNAMIC(Note)

public:
	Note(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Note();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString ChildData;
	CEdit m_edit;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedCancel();
};
