// PuzzlePicturePreview.cpp : implementation file
//

#include "stdafx.h"
#include "PuzzleGame-MFC.h"
#include "PuzzlePicturePreview.h"
#include "afxdialogex.h"
#include "PuzzleGameView.h"

// CPuzzlePicturePreview dialog

IMPLEMENT_DYNAMIC(CPuzzlePicturePreview, CDialogEx)

CPuzzlePicturePreview::CPuzzlePicturePreview(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

CPuzzlePicturePreview::~CPuzzlePicturePreview()
{
	DeleteBitmap();
}

void CPuzzlePicturePreview::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, ShowPictureButton);
}


BEGIN_MESSAGE_MAP(CPuzzlePicturePreview, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CPuzzlePicturePreview message handlers

void CPuzzlePicturePreview::SetPicturePreview(std::wstring pictureInfo, int width, int height)
{
	m_widthOfPicture = width;
	m_heightOfPicture = height;
	m_picturePath = pictureInfo;
}

void CPuzzlePicturePreview::OnPaint()
{


}

BOOL CPuzzlePicturePreview::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	ShowPicture();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE

				 
}

/*
ShowPicture function show whole picture 
*/
void CPuzzlePicturePreview::ShowPicture()
{
	CRect rc;

	CButton* pBtn = (CButton*)GetDlgItem(IDC_BUTTON1);
	pBtn->ModifyStyle(0, BS_BITMAP);

	pBtn->GetWindowRect(rc);
	pBtn->SetWindowPos(NULL, rc.left, rc.top, m_widthOfPicture, m_heightOfPicture, SWP_NOSENDCHANGING | SWP_NOACTIVATE | SWP_NOZORDER | SWP_NOMOVE);

	HBITMAP EntityImage = (HBITMAP)LoadImage(
		NULL,
		m_picturePath.c_str(),
		IMAGE_BITMAP,
		0, 0, 
		LR_LOADFROMFILE
	);

	pBtn->SetBitmap(EntityImage);
	
}

void CPuzzlePicturePreview::DeleteBitmap()
{
	DeleteObject(EntityImage);
}