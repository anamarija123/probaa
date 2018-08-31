
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
	m_startGame.m_setupGame.Delete();
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_FILE_NEW, &CChildView::newGameSetUp)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_FILE_SHOWPICTURE, &CChildView::OnFileShowpicture)
	ON_COMMAND(ID_FILE_SHUFFLE, &CChildView::OnFileShuffle)
	ON_COMMAND(ID_APP_EXIT, &CChildView::OnAppExit)
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
	
	switch (indicator)
	{
	case INDICATOR_TO_SET_GAME:
		m_startGame.SetParametersForGame(hdc);
		m_startGame.SetPictureForGame(dc);
		GetParentFrame()->MoveWindow(0, 0, m_startGame.m_setupGame.GetPictureWidth(),
			m_startGame.m_setupGame.GetPictureHeight());
		break;
	case INDICATOR_TO_SWAP:
		m_startGame.SetPictureForGame(dc);
		break;
	case INDICATOR_TO_SHUFFLE:
		m_startGame.SetPictureForGame(dc);
		break;
	}
}

/*
newGameSetUp function opens dialog to choose other picture and set new parameters of grid
*/
void CChildView::newGameSetUp()
{
	m_startGame.start();
	indicator = INDICATOR_TO_SET_GAME;
	Invalidate();
}

/*
start function call function to initialize
*/
void CChildView::start()
{
	m_startGame.start();
}

int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	start();

	return 0;
}

void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{	

	long x = point.x;
	long y = point.y;

	POINT clickedPixelOfPicture;

	int columns = m_startGame.m_setupGame.GetNumberOfColumns();
	int rows = m_startGame.m_setupGame.GetNumberOfRows();

	int pictureWidth = m_startGame.m_setupGame.GetPictureWidth();
	int pictureHeight = m_startGame.m_setupGame.GetPictureHeight();

	int indexOfClickedRow = y*columns / pictureHeight;
	int indexOfClickedColumn = x*rows / pictureWidth;
	
	clickedPixelOfPicture.x = indexOfClickedColumn;
	clickedPixelOfPicture.y = indexOfClickedRow;

	clickedPixelCoords.push_back(clickedPixelOfPicture);

	//if clickedPixelCoords contains two user clicks
	if (clickedPixelCoords.size() == 2)
	{	
		m_startGame.m_setupGame.Swap(clickedPixelCoords);
		clickedPixelCoords.clear();
		indicator = INDICATOR_TO_SWAP;
		Invalidate();
	}
	
	CWnd::OnLButtonDown(nFlags, point);
}

/*
OnFileShowpicture call function to set picture for preview
DoModal() opens picture preview dialog
*/
void CChildView::OnFileShowpicture()
{
	m_preview.SetPicturePreview(m_startGame.GameImagePath(),
		m_startGame.m_setupGame.GetPictureWidth(),
		m_startGame.m_setupGame.GetPictureHeight());
	m_preview.DoModal();	
}

/*
OnFileShuffle call function to shuffle 
*/
void CChildView::OnFileShuffle()
{
	m_startGame.ShufflePieces();
	indicator = INDICATOR_TO_SHUFFLE;
	Invalidate();
}


void CChildView::OnAppExit()
{
	m_startGame.m_setupGame.Delete();
	PostQuitMessage(0);
}
