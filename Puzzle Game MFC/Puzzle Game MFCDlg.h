
// Puzzle Game MFCDlg.h : header file
//

#pragma once
#include "PuzzlePictureControl.h"

// CPuzzleGameMFCDlg dialog
class CPuzzleGameMFCDlg : public CDialogEx
{
// Construction
public:
	CPuzzleGameMFCDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PUZZLEGAMEMFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedPrevious();
	afx_msg void OnBnClickedButtonNext();
	CPuzzlePictureControl m_puzzlePicture;
};
