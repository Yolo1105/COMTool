#include "pch.h"
#include "Test.h"
#include "Note.h"
BEGIN_MESSAGE_MAP(Test, CEdit)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()


void Test::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Note note;
	note.DoModal();

	CEdit::OnLButtonDblClk(nFlags, point);
}
