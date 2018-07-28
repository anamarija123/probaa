#pragma once
#include "Puzzle Game MFCDlg.h"
#include "BitmapViewer.h"
// CDialogPuzzleGame dialog

class CDialogPuzzleGame : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogPuzzleGame)

public:
	CDialogPuzzleGame(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDialogPuzzleGame();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_GAME_PLAY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CStatic PuzzlePictureControlGame;
	
protected:
	BOOL CDialogPuzzleGame::OnInitDialog();
public:
	afx_msg void OnBnSetfocusStaticPuzzlePlay();
	afx_msg void OnStnClickedPictureControl2();
	CStatic kontrola;

	CPuzzlePictureControl picture_control;
	CBitmapViewer m_Viewer;
};
