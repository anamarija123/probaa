#pragma once
#include "GameConfiguration.h"
#include "PuzzleDetails.h"

#include <iterator>

// CSetGameDialog dialog

class CSetGameDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CSetGameDialog)

public:
	CSetGameDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CSetGameDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

public:
	afx_msg void OnBnClickedPrevious();
	afx_msg void OnBnClickedButtonNext();
	void ShowPicture(int picture_index);

protected:
	CGameConfiguration m_gameConfiguration;
	;
public:
	int indexOfPicture = 0;
	int grid = 0;
	int gridHeight = 0;
	CStatic*  m_picture;
	wstring GetPictureForGame();
	void setPuzzleDetails(CGameConfiguration gameConfiguration);
	afx_msg void OnBnClickedButtonPrevious();
	afx_msg void OnClickedButtonNext();
	afx_msg void OnBnClickedOk();
	UINT X;
	UINT Y;
	afx_msg void OnBnClickedCancel();
};
