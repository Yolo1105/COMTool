#include "pch.h"
#include "Test.h"
#include "Note.h"
BEGIN_MESSAGE_MAP(Test, CEdit)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()


void Test::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Note note;
	note.DoModal();

	CEdit::OnLButtonDblClk(nFlags, point);
}
