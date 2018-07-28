// BitmapViewer.cpp : implementation file
//

#include "stdafx.h"
#include "Puzzle Game MFC.h"
#include "BitmapViewer.h"
#define BITMAPVIEWER_CLASSNAME    _T("MFCBitmapViewerCtrl")

// CBitmapViewer

IMPLEMENT_DYNAMIC(CBitmapViewer, CWnd)

CBitmapViewer::CBitmapViewer()
{
	RegisterWindowClass();
}

CBitmapViewer::~CBitmapViewer()
{
}


BEGIN_MESSAGE_MAP(CBitmapViewer, CWnd)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()



// CBitmapViewer message handlers

BOOL CBitmapViewer::RegisterWindowClass()
{
	WNDCLASS wndcls;
	HINSTANCE hInst = AfxGetInstanceHandle();

	if (!(::GetClassInfo(hInst, BITMAPVIEWER_CLASSNAME, &wndcls)))
	{
		// otherwise we need to register a new class
		wndcls.style = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;
		wndcls.lpfnWndProc = ::DefWindowProc;
		wndcls.cbClsExtra = wndcls.cbWndExtra = 0;
		wndcls.hInstance = hInst;
		wndcls.hIcon = NULL;
		wndcls.hCursor = AfxGetApp()->LoadStandardCursor(IDC_ARROW);
		wndcls.hbrBackground = (HBRUSH)(COLOR_3DFACE + 1);
		wndcls.lpszMenuName = NULL;
		wndcls.lpszClassName = BITMAPVIEWER_CLASSNAME;

		if (!AfxRegisterClass(&wndcls))
		{
			AfxThrowResourceException();
			return FALSE;
		}
	}

	return TRUE;
}


void CBitmapViewer::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CWnd::OnPaint() for painting messages
	if (m_Bitmap.GetSafeHandle() != NULL)
	{
		CPaintDC dc(this); // device context for painting

						   // Create memory DC
		CDC MemDC;
		if (!MemDC.CreateCompatibleDC(&dc))
			return;

		// Get Size of Display area
		CRect rect;
		GetClientRect(rect);

		// Get size of bitmap
		BITMAP bm;
		m_Bitmap.GetBitmap(&bm);

		// Draw the bitmap
		CBitmap* pOldBitmap = (CBitmap*)MemDC.SelectObject(&m_Bitmap);
		dc.StretchBlt(0, 0, rect.Width(), rect.Height(),
			&MemDC,
			0, 0, bm.bmWidth, bm.bmHeight,
			SRCCOPY);
		MemDC.SelectObject(pOldBitmap);
	}
}


BOOL CBitmapViewer::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default
	if (m_Bitmap.GetSafeHandle() != NULL)
	{
		return TRUE;
	}
		
	return CWnd::OnEraseBkgnd(pDC);
}


void CBitmapViewer::PreSubclassWindow()
{
	// TODO: Add your specialized code here and/or call the base class

	CWnd::PreSubclassWindow();
}
/*
BOOL CBitmapViewer::Create(CWnd* pParentWnd, const RECT& rect, UINT nID, DWORD dwStyle )
{
	return CWnd::Create(BITMAPVIEWER_CLASSNAME, _T(""), dwStyle, rect, pParentWnd, nID);
}
*/

/*=WS_VISIBLE*/
BOOL CBitmapViewer::SetBitmap(UINT nIDResource)
{
	return m_Bitmap.LoadBitmap(nIDResource);
}
