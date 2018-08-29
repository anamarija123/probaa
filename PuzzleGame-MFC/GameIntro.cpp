#include "stdafx.h"
#include "GameIntro.h"

void CGameIntro::start()
{
	
	SetParametarsLoadedFromIniFile();
	SetParametarsLoadedFromDialog();
}
CGameIntro::CGameIntro()
{
}


CGameIntro::~CGameIntro()
{
}

void CGameIntro::SetParametarsLoadedFromIniFile()
{
	//m_gameConfiguration.GetGridDetails();
	m_gameConfiguration.GetPuzzleDetails(1);
	m_gameConfiguration.GetPuzzleDetails(2);
	m_gameConfiguration.GetPuzzleDetails(3);
}


void CGameIntro::SetParametarsLoadedFromDialog()
{	
	m_gameConfiguration.GetGridDetails();
	m_dialogParameters.setPuzzleDetails(m_gameConfiguration);
	x = m_gameConfiguration.gridDetailsCollection[0].GetXSize();
	y = m_gameConfiguration.gridDetailsCollection[0].GetYSize();
	m_dialogParameters.Y = y;
	m_dialogParameters.X = x;
	
	m_dialogParameters.DoModal();
	
	
	x = m_dialogParameters.X;
	y = m_dialogParameters.Y;
	m_gameConfiguration.SetGridDetails(x, y);	
}

void CGameIntro::SetParametersForGame(HDC hDC)
{
	imagePath = m_dialogParameters.GetPictureForGame();
	//m_preview.SetPicturePreview(imagePath);
	bool pictureOpened = m_setupGame.LoadBitmapPicture(hDC,imagePath.c_str());
	if (pictureOpened == true)
	{
		m_setupGame.initializeParameters(x, y, imagePath);
	}
	
	ShufflePieces();
}

void CGameIntro::ShufflePieces()
{
	m_setupGame.Shuffle();
}

void CGameIntro::SetPictureForGame(HDC hDC)
{
	m_setupGame.DrawPieces(hDC);
}