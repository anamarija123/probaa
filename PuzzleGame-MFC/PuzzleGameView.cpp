
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
	//indicators = 0;
	hdc = dc;
	if (indicators == 0)
	{
		m_startGame.SetParametersForGame(hdc);
		m_startGame.SetPictureForGame(dc);
	}
	else
	{
		m_startGame.SetPictureForGame(dc);
	}


	
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

	long x = point.x;
	long y = point.y;

	POINT rowsAndColumns;

	int columns = m_startGame.m_setupGame.GetNumberOfColumns();
	int rows = m_startGame.m_setupGame.GetNumberOfRows();

	int pictureWidth = m_startGame.m_setupGame.GetPictureWidth();
	int pictureHeight = m_startGame.m_setupGame.GetPictureHeight();

	int indexOfClickedRow = y*columns / pictureHeight;
	int indexOfClickedColumn = x*rows / pictureWidth;
	
	rowsAndColumns.x = indexOfClickedColumn;
	rowsAndColumns.y = indexOfClickedRow;

	clickedPixelCoords.push_back(rowsAndColumns);

	if (clickedPixelCoords.size() == 2)
	{
		
		m_startGame.m_setupGame.Swap(clickedPixelCoords);
		clickedPixelCoords.clear();
		indicators = 1;
		Invalidate();
	}
	
	CWnd::OnLButtonDown(nFlags, point);
}
