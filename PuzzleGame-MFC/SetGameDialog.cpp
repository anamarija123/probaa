// SetGameDialog.cpp : implementation file
//

#include "stdafx.h"
#include "PuzzleGame-MFC.h"
#include "SetGameDialog.h"
#include "afxdialogex.h"


// CSetGameDialog dialog

IMPLEMENT_DYNAMIC(CSetGameDialog, CDialogEx)

CSetGameDialog::CSetGameDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SELECT_PUZZLE, pParent)
	, X(0)
	, Y(0)
	, m_indicatorToPlay(false)
	, hEntityImage(nullptr)
	
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CSetGameDialog::~CSetGameDialog()
{
	DeleteBitmap();
}

void CSetGameDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT1, X);
	DDV_MinMaxUInt(pDX, X, 3, 10);
	DDX_Text(pDX, IDC_EDIT2, Y);
	DDV_MinMaxUInt(pDX, Y, 3, 10);
}


BEGIN_MESSAGE_MAP(CSetGameDialog, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_PREVIOUS, &CSetGameDialog::OnBnClickedButtonPrevious)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, &CSetGameDialog::OnClickedButtonNext)
	ON_BN_CLICKED(IDOK, &CSetGameDialog::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CSetGameDialog::OnBnClickedCancel)
END_MESSAGE_MAP()

BOOL CSetGameDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	
	SetIcon(m_hIcon, TRUE);			
	SetIcon(m_hIcon, FALSE);		
	
	GetDlgItem(IDC_BUTTON_PREVIOUS)->EnableWindow(FALSE);
	m_indexOfPicture = 0;
	ShowPicture(m_indexOfPicture);
	
	return TRUE;  
}
// CSetGameDialog message handlers

void CSetGameDialog::OnPaint()
{

	
	CDialogEx::OnPaint();
	
	
}

HCURSOR CSetGameDialog::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

/*
setPuzzleDetails setting details about loaded ini file
@param gameConfiguration contains info loaded from ini
*/
void CSetGameDialog::setPuzzleDetails(CGameConfiguration gameConfiguration)
{
	m_gameConfiguration = gameConfiguration;
	m_numberOfPictures = m_gameConfiguration.puzzleDetailsCollection.size() - 1;
}

/*
ShowPicture show little picture on dialog
@param picture_index index of picture to display
*/


void CSetGameDialog::ShowPicture(int picture_index)
{
	CStatic*  m_picture;
	m_picture = (CStatic*)GetDlgItem(IDC_PUZZLE_PICTURE);
	m_picture->ModifyStyle(0, SS_BITMAP);
	hEntityImage = (HBITMAP)LoadImage(
		NULL,
		m_gameConfiguration.puzzleDetailsCollection[picture_index].GetPreviewImagePath().c_str(), 
		IMAGE_BITMAP, 
		160, 140,
		LR_LOADFROMFILE);

	if (hEntityImage)
	{
		//SetBitmap returns a handle to previous bitmap
		HBITMAP oldbmp = m_picture->SetBitmap(hEntityImage);
		if (oldbmp)
			DeleteObject(oldbmp);
	}
}

void CSetGameDialog::OnBnClickedButtonPrevious()
{
	if (m_indexOfPicture > 0)
	{
		GetDlgItem(IDC_BUTTON_NEXT)->EnableWindow(TRUE);
		m_indexOfPicture--;
		ShowPicture(m_indexOfPicture);
	}
	
	if (m_indexOfPicture == 0)
	{
		GetDlgItem(IDC_BUTTON_PREVIOUS)->EnableWindow(FALSE);
	}
}



void CSetGameDialog::OnClickedButtonNext()
{
	m_indexOfPicture ++;
	if (m_indexOfPicture < m_numberOfPictures)
	{
		GetDlgItem(IDC_BUTTON_PREVIOUS)->EnableWindow(TRUE);
		ShowPicture(m_indexOfPicture);		
	}
	if (m_indexOfPicture == m_numberOfPictures)
	{
		ShowPicture(m_indexOfPicture);
		GetDlgItem(IDC_BUTTON_NEXT)->EnableWindow(FALSE);
	}
}


void CSetGameDialog::OnBnClickedOk()
{
	m_indicatorToPlay = true;//START GAME
	DeleteBitmap();
	UpdateData();
	CDialogEx::OnOK();
}


void CSetGameDialog::OnBnClickedCancel()
{
	m_indicatorToPlay = false;
	DeleteBitmap();
	UpdateData();
	CDialogEx::OnCancel();
}
/*
GetPictureForGame returns chosen picture for game
*/
tstring CSetGameDialog::GetPictureForGame()
{
	return m_gameConfiguration.puzzleDetailsCollection[m_indexOfPicture].GetGameImagePath().c_str();
}

void CSetGameDialog::DeleteBitmap()
{
	DeleteObject(hEntityImage);
}