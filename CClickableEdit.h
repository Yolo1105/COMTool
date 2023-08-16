#pragma once
#include <afxwin.h>
class CClickableEdit :
    public CEdit
{
public:
    DECLARE_MESSAGE_MAP()
        afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
    afx_msg void test();
};

