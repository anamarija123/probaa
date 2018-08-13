#pragma once
#include "PuzzlePictureControl.h"
#include "GameConfiguration.h"
#include "PuzzleDetails.h"
#include <vector>
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
	void ShowPicture(int indicator);

protected:
	CPuzzlePictureControl m_puzzlePicture;
	CGameConfiguration m_gameConfiguration;
public:
	std::vector<CPuzzleDetails> puzzle_details;
	int indexOfPicture = 0;
	int grid = 0;
	int gridNumber = 0;
	//std::list<CPuzzleDetails>::iterator it;

	afx_msg void OnStnClickedPuzzlePicture();
	afx_msg void OnBnClickedButtonPrevious();
	afx_msg void OnBnClickedRadioEasy();
	afx_msg void OnBnClickedRadioHard();
	afx_msg void OnBnClickedRadioMedium();
	afx_msg void OnClickedButtonNext();
};
