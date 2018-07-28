// DialogPuzzleGame.cpp : implementation file
//

#include "stdafx.h"
#include "Puzzle Game MFC.h"
#include "DialogPuzzleGame.h"
#include "Puzzle Game MFCDlg.h"
#include "afxdialogex.h"


// CDialogPuzzleGame dialog

IMPLEMENT_DYNAMIC(CDialogPuzzleGame, CDialogEx)

CDialogPuzzleGame::CDialogPuzzleGame(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_GAME_PLAY, pParent)
{

}

CDialogPuzzleGame::~CDialogPuzzleGame()
{
}

void CDialogPuzzleGame::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CUSTOM1, m_Viewer);
}


BEGIN_MESSAGE_MAP(CDialogPuzzleGame, CDialogEx)
END_MESSAGE_MAP()

BOOL CDialogPuzzleGame::OnInitDialog()
{

	m_Viewer.Create(_T("MFCBitmapViewerCtrl"), _T(""), WS_VISIBLE, CRect(0, 0, 100, 100), this, 1);
	m_Viewer.SetBitmap(IDB_BITMAP1);

/*
	HBITMAP l_Bmp_h;
	l_Bmp_h = ::LoadBitmap(AfxGetResourceHandle(), MAKEINTRESOURCE(IDB_BITMAP1));
	m_Viewer.SetBitmap((UINT)l_Bmp_h);
*/
	//
	/*
	RECT rc;
	GetWindowRect(&rc);

	CRect rect;
	CWnd *pWnd = GetDlgItem(IDC_STATIC_PICTURE_CONTROL);
	pWnd->GetWindowRect(&rect);
	ScreenToClient(&rect);

	picture_control.ChangePicture(L".\\bigLandscape1.bmp");
	*/
	return true;
}

// CDialogPuzzleGame message handlers


void CDialogPuzzleGame::OnBnSetfocusStaticPuzzlePlay()
{
	// TODO: Add your control notification handler code here
}


void CDialogPuzzleGame::OnStnClickedPictureControl2()
{
	// TODO: Add your control notification handler code here
}
