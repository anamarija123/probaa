
// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "PuzzleGame-MFC.h"
#include "PuzzleGameView.h"
#include <cmath>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
  

// CChildView

CChildView::CChildView()
{

}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_FILE_NEW, &CChildView::newGameSetUp)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}


void CChildView::OnPaint() 
{
	CPaintDC dc(this); 
	
	RECT rc;
	GetClientRect(&rc);
	indicators = 0;
	hdc = dc;
	m_startGame.SetGridAndPictureForGame(dc,&dc, rc, CWnd::m_hWnd,indicators);

	
}
void CChildView::newGameSetUp()
{
	m_startGame.start();
	indicator = true;
	Invalidate();

}
void CChildView::start()
{
	m_startGame.start();
	indicator = false;
}

int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	start();
	// TODO:  Add your specialized creation code here

	return 0;
}

void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{	
	POINT click;
	
	click.x = point.x;
	click.y = point.y;

	clickedPixelCoords.push_back(click);
	if (clickedPixelCoords.size() == 2)
	{
		
		m_startGame.m_setupGame.Swap(clickedPixelCoords);
		clickedPixelCoords.clear();
		Invalidate();
		indicators = 1;
	
	}

	//CWnd::OnLButtonDown(nFlags, point);
}
