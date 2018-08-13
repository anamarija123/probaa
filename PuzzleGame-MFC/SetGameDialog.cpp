// SetGameDialog.cpp : implementation file
//

#include "stdafx.h"
#include "PuzzleGame-MFC.h"
#include "SetGameDialog.h"
#include "afxdialogex.h"

enum initialization {
	puzzle1 = 1,
	puzzle2 = 2,
	puzzle3 = 3,
	timer = 1
} ID;
// CSetGameDialog dialog

IMPLEMENT_DYNAMIC(CSetGameDialog, CDialogEx)

CSetGameDialog::CSetGameDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CSetGameDialog::~CSetGameDialog()
{
}

void CSetGameDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PUZZLE_PICTURE, m_puzzlePicture);
}


BEGIN_MESSAGE_MAP(CSetGameDialog, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_STN_CLICKED(IDC_PUZZLE_PICTURE, &CSetGameDialog::OnStnClickedPuzzlePicture)
	ON_BN_CLICKED(IDC_BUTTON_PREVIOUS, &CSetGameDialog::OnBnClickedButtonPrevious)
	ON_BN_CLICKED(IDC_RADIO_EASY, &CSetGameDialog::OnBnClickedRadioEasy)
	ON_BN_CLICKED(IDC_RADIO_HARD, &CSetGameDialog::OnBnClickedRadioHard)
	ON_BN_CLICKED(IDC_RADIO_MEDIUM, &CSetGameDialog::OnBnClickedRadioMedium)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, &CSetGameDialog::OnClickedButtonNext)
END_MESSAGE_MAP()

BOOL CSetGameDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CPuzzleDetails first_puzzle = m_gameConfiguration.GetPuzzleDetails(ID = puzzle1);
	puzzle_details.push_back(first_puzzle);
	CPuzzleDetails second_puzzle = m_gameConfiguration.GetPuzzleDetails(ID = puzzle2);
	puzzle_details.push_back(second_puzzle);
	CPuzzleDetails third_puzzle = m_gameConfiguration.GetPuzzleDetails(ID = puzzle3);
	puzzle_details.push_back(third_puzzle);
	CTimerDetails timer_ = m_gameConfiguration.GetTimerDetails(ID = timer);

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

									// TODO: Add extra initialization here
									//	mnrsto(puzzleDetails.GetGameImagePath());

									//m_puzzlePicture.ChangePicture((LPCTSTR)puzzleDetails1.GetPreviewImagePath());

	return TRUE;  // return TRUE  unless you set the focus to a control
}
// CSetGameDialog message handlers

void CSetGameDialog::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

HCURSOR CSetGameDialog::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CSetGameDialog::OnStnClickedPuzzlePicture()
{
	// TODO: Add your control notification handler code here
	ShowPicture(indexOfPicture);
}

void CSetGameDialog::ShowPicture(int indicator)
{
	m_puzzlePicture.ChangePicture(puzzle_details[indicator].GetPreviewImagePath().c_str());

}

void CSetGameDialog::OnBnClickedButtonPrevious()
{
	// TODO: Add your control notification handler code here
	if (indexOfPicture > 0)
	{
		indexOfPicture--;
		ShowPicture(indexOfPicture);
	}
	else
	{
		return;
	}
}

void CSetGameDialog::OnBnClickedRadioEasy()
{
	// TODO: Add your control notification handler code here
	gridNumber = 3;
}


void CSetGameDialog::OnBnClickedRadioHard()
{
	// TODO: Add your control notification handler code here
	gridNumber = 7;
}


void CSetGameDialog::OnBnClickedRadioMedium()
{
	// TODO: Add your control notification handler code here
	gridNumber = 5;
}


void CSetGameDialog::OnClickedButtonNext()
{
	// TODO: Add your control notification handler code here
	//m_puzzlePicture.ChangePicture(_T(".\\smallLandscape1.bmp"));
	indexOfPicture++;
	if (indexOfPicture <= puzzle_details.size() - 1)
	{
		ShowPicture(indexOfPicture);
	}
	else
	{
		return;
	}
}
