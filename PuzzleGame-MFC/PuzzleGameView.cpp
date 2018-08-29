
// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "PuzzleGame-MFC.h"
#include "PuzzleGameView.h"
#include <cmath>
#ifdef _DEBUG
#define new DEBUG_NEW
#define INDICATOR_TO_SET_GAME 0
#define INDICATOR_TO_SWAP 1
#define INDICATOR_TO_SHUFFLE 2
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
	ON_COMMAND(ID_FILE_SHOWPICTURE, &CChildView::OnFileShowpicture)
	ON_COMMAND(ID_FILE_SHUFFLE, &CChildView::OnFileShuffle)
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
	hdc = dc;

	switch (indicators)
	{
	case INDICATOR_TO_SET_GAME:
		m_startGame.SetParametersForGame(hdc);
		m_startGame.SetPictureForGame(dc);
		break;
	case INDICATOR_TO_SWAP:
		m_startGame.SetPictureForGame(dc);
		break;
	case INDICATOR_TO_SHUFFLE:
		m_startGame.SetPictureForGame(dc);
		break;
	}
}

void CChildView::newGameSetUp()
{
	m_startGame.start();
	indicators = INDICATOR_TO_SET_GAME;
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
		indicators = INDICATOR_TO_SWAP;
		Invalidate();
	}
	
	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnFileShowpicture()
{

	m_preview.SetPicturePreview(m_startGame.imagePath);
	m_preview.DoModal();
	
}


void CChildView::OnFileShuffle()
{
	m_startGame.ShufflePieces();
	indicators = INDICATOR_TO_SHUFFLE;
	Invalidate();
}
