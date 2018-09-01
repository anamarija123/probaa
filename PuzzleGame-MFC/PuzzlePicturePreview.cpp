// PuzzlePicturePreview.cpp : implementation file
//

#include "stdafx.h"
#include "PuzzleGame-MFC.h"
#include "PuzzlePicturePreview.h"
#include "afxdialogex.h"
#include "PuzzleGameView.h"
#include <string>
// CPuzzlePicturePreview dialog

IMPLEMENT_DYNAMIC(CPuzzlePicturePreview, CDialogEx)

CPuzzlePicturePreview::CPuzzlePicturePreview(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PICTURE_PREVIEW, pParent)
{

}

CPuzzlePicturePreview::~CPuzzlePicturePreview()
{
	DeleteBitmap();
}

void CPuzzlePicturePreview::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_BUTTON1, ShowPictureButton);
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

	CPaintDC dc(this); // device context for painting
	HBITMAP m_Bmap;
	CRect rect;
	HDC memdc;
	
	GetClientRect(&rect);

	m_Bmap = (HBITMAP)::LoadImage(NULL, m_picturePath.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	memdc = ::CreateCompatibleDC(dc.m_hDC);
	::SelectObject(memdc, m_Bmap);

	BitBlt(dc.m_hDC, 0, 0, rect.right, rect.bottom, memdc, 0, 0, SRCCOPY);
}

BOOL CPuzzlePicturePreview::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	this->SetWindowPos(NULL, 0, 0, m_widthOfPicture, m_heightOfPicture, SWP_NOMOVE | SWP_NOZORDER);
	// TODO:  Add extra initialization here


	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
			 
}


void CPuzzlePicturePreview::DeleteBitmap()
{
	DeleteObject(EntityImage);
}