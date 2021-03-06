
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

PuzzleGameView::PuzzleGameView()
{

	
}

PuzzleGameView::~PuzzleGameView()
{
}


BEGIN_MESSAGE_MAP(PuzzleGameView, CWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_FILE_NEW, &PuzzleGameView::newGameSetUp)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_FILE_SHOWPICTURE, &PuzzleGameView::OnFileShowpicture)
	ON_COMMAND(ID_FILE_SHUFFLE, &PuzzleGameView::OnFileShuffle)
	ON_COMMAND(ID_APP_EXIT, &PuzzleGameView::OnAppExit)
	
	ON_UPDATE_COMMAND_UI(ID_FILE_SHUFFLE, &PuzzleGameView::OnUpdateFileShuffle)
	ON_UPDATE_COMMAND_UI(ID_FILE_SHOWPICTURE, &PuzzleGameView::OnUpdateFileShowpicture)
END_MESSAGE_MAP()



// CChildView message handlers

BOOL PuzzleGameView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void PuzzleGameView::OnPaint() 
{
	CPaintDC dc(this); 

	if (!m_startGame.m_dialogParameters.m_indicatorToPlay)
	{
		CBitmap bmp;
		CDC MemDC;
		bmp.LoadBitmap(IDB_SCREEN_BITMAP);
		MemDC.CreateCompatibleDC(&dc);
		CBitmap *BmpPr = MemDC.SelectObject(&bmp);
		dc.BitBlt(0, 0, 862, 360, &MemDC, 0, 0, SRCCOPY);
		dc.SelectObject(BmpPr);
	}
	else
	{
		m_startGame.SetPictureForGame(dc);	
	}
}

void PuzzleGameView::ResizeWindow()
{	
	CRect rcClient, rcWindow;
	GetClientRect(&rcClient);
	GetParentFrame()->GetWindowRect(&rcWindow);

	int widthDifference = rcWindow.Width() - rcClient.Width();
	int heightDifference = rcWindow.Height() - rcClient.Height();
	
	rcWindow.right = rcWindow.left +
		m_startGame.m_setupGame.GetWidthOfPiece() * m_startGame.m_setupGame.GetNumberOfRows() + widthDifference;
	rcWindow.bottom = rcWindow.top +
		m_startGame.m_setupGame.GetHeightOfPiece() * m_startGame.m_setupGame.GetNumberOfColumns() + heightDifference;
	GetParentFrame()->MoveWindow(&rcWindow);
}

/*
newGameSetUp function opens dialog to choose other picture and set new parameters of grid
*/
void PuzzleGameView::newGameSetUp()
{
	ActivateMenu();
	Initialize();
	Invalidate();
}

/*
initialize function call functions for set the game
*/
void PuzzleGameView::Initialize()
{
	CClientDC pdc(this);
	HDC hdc;
	hdc = pdc;
	m_startGame.start();
	m_startGame.SetParametersForGame(hdc);
	ResizeWindow();
}

int PuzzleGameView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	return 0;
}

void PuzzleGameView::OnLButtonDown(UINT nFlags, CPoint point)
{	
	//if indicator TRUE, allow clicking
	if (m_startGame.m_dialogParameters.m_indicatorToPlay)
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
			Invalidate();
		}
	}
	CWnd::OnLButtonDown(nFlags, point);
}

/*
OnFileShowpicture call function to set picture for preview
DoModal() opens picture preview dialog
*/
void PuzzleGameView::OnFileShowpicture()
{
	m_preview.SetPicturePreview(m_startGame.GameImagePath().c_str(),
		m_startGame.m_setupGame.GetPictureWidth(),
		m_startGame.m_setupGame.GetPictureHeight());
	m_preview.DoModal();	
}

/*
OnFileShuffle call function to shuffle 
*/
void PuzzleGameView::OnFileShuffle()
{
	m_startGame.ShufflePieces();
	Invalidate();
}


void PuzzleGameView::OnAppExit()
{
	AfxGetMainWnd()->PostMessage(WM_CLOSE);
}

bool PuzzleGameView::ActivateMenu()
{
	if (!m_startGame.m_dialogParameters.m_indicatorToPlay)
	{
		return false;
	}
	return true;
}

void PuzzleGameView::OnUpdateFileShuffle(CCmdUI *pCmdUI)
{
	
	pCmdUI->Enable(ActivateMenu());
}


void PuzzleGameView::OnUpdateFileShowpicture(CCmdUI *pCmdUI)
{
	
	pCmdUI->Enable(ActivateMenu());
}
