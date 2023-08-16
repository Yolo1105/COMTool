// Note.cpp: 实现文件
//

#include "pch.h"
#include "ATCOMMAND.h"
#include "afxdialogex.h"
#include "Note.h"
#include "ATCOMMANDDlg.h"

// Note 对话框

IMPLEMENT_DYNAMIC(Note, CDialogEx)

Note::Note(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

Note::~Note()
{
}

void Note::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
}


BEGIN_MESSAGE_MAP(Note, CDialogEx)
	ON_BN_CLICKED(IDOK, &Note::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &Note::OnBnClickedCancel)
END_MESSAGE_MAP()


// Note 消息处理程序


void Note::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	CString tempstr;
	CATCOMMANDDlg* father = (CATCOMMANDDlg*)GetParent();
	this->m_edit.GetWindowText(ChildData);
	CWnd* pWnd = GetFocus();
	int nPortID = pWnd->GetDlgCtrlID();

	if (nPortID == 1078) {
		tempstr.Format(_T("%d"), nPortID);
		father->m_at1.SetWindowText(ChildData);
	}
	else if (nPortID == 1059) {
		tempstr.Format(_T("%d"), nPortID);
		father->m_at2.SetWindowText(ChildData);
	}
	else if (nPortID == 1065) {
		tempstr.Format(_T("%d"), nPortID);
		father->m_at3.SetWindowText(ChildData);
	}
	else if (nPortID == 1073) {
		tempstr.Format(_T("%d"), nPortID);
		father->m_at4.SetWindowText(ChildData);
	}
	else if (nPortID == 1071) {
		tempstr.Format(_T("%d"), nPortID);
		father->m_at5.SetWindowText(ChildData);
	}
	else if (nPortID == 1015) {
		tempstr.Format(_T("%d"), nPortID);
		father->m_at6.SetWindowText(ChildData);
	}
	else if (nPortID == 1019) {
		tempstr.Format(_T("%d"), nPortID);
		father->m_at7.SetWindowText(ChildData);
	}
	else if (nPortID == 1023) {
		tempstr.Format(_T("%d"), nPortID);
		father->m_at8.SetWindowText(ChildData);
	}
	else if (nPortID == 1027) {
		tempstr.Format(_T("%d"), nPortID);
		father->m_at9.SetWindowText(ChildData);
	}
	else if (nPortID == 1031) {
		tempstr.Format(_T("%d"), nPortID);
		father->m_at10.SetWindowText(ChildData);
	}
	else if (nPortID == 1035) {
		tempstr.Format(_T("%d"), nPortID);
		father->m_at11.SetWindowText(ChildData);
	}
	else if (nPortID == 1039) {
		tempstr.Format(_T("%d"), nPortID);
		father->m_at12.SetWindowText(ChildData);
	}
	else if (nPortID == 1042) {
		tempstr.Format(_T("%d"), nPortID);
		father->m_at13.SetWindowText(ChildData);
	}
	else if (nPortID == 1047) {
		tempstr.Format(_T("%d"), nPortID);
		father->m_at14.SetWindowText(ChildData);
	}
	else if (nPortID == 1049) {
		tempstr.Format(_T("%d"), nPortID);
		father->m_at15.SetWindowText(ChildData);
	}
}

void Note::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
