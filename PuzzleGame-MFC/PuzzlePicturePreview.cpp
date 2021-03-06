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
	: CDialogEx(IDD_PICTURE_PREVIEW, pParent), m_widthOfPicture(0),m_heightOfPicture(0)
{

}

CPuzzlePicturePreview::~CPuzzlePicturePreview()
{
}

void CPuzzlePicturePreview::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPuzzlePicturePreview, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP() 


// CPuzzlePicturePreview message handlers

void CPuzzlePicturePreview::SetPicturePreview(tstring pictureInfo, int width, int height)
{
	m_widthOfPicture = width;
	m_heightOfPicture = height;
	m_picturePath = pictureInfo;
}

void CPuzzlePicturePreview::OnPaint()
{

	CPaintDC dc(this); // device context for painting

	CImage img;
	CBitmap bitmap;
	CDC mdcPicture;
	img.Load(m_picturePath.c_str());
	bitmap.Attach(img.Detach());
	mdcPicture.CreateCompatibleDC(&dc);
	CBitmap * bmpPrevious = mdcPicture.SelectObject(&bitmap);
	dc.BitBlt(0, 0, m_widthOfPicture, m_heightOfPicture, &mdcPicture, 0, 0, SRCCOPY);
	dc.SelectObject(bmpPrevious);
}

BOOL CPuzzlePicturePreview::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	this->SetWindowPos(NULL, 0, 0, m_widthOfPicture, m_heightOfPicture, SWP_NOMOVE | SWP_NOZORDER);

	return TRUE;  			 
}

