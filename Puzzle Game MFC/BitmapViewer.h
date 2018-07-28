#pragma once


// CBitmapViewer

class CBitmapViewer : public CWnd
{
	DECLARE_DYNAMIC(CBitmapViewer)

public:
	CBitmapViewer();
	virtual ~CBitmapViewer();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	virtual void PreSubclassWindow();

public:
	BOOL SetBitmap(UINT nIDResource);
	BOOL RegisterWindowClass();
	//BOOL Create(CWnd* pParentWnd, const RECT& rect, UINT nID, DWORD dwStyle /*=WS_VISIBLE*/);
protected:
	CBitmap m_Bitmap;
};


