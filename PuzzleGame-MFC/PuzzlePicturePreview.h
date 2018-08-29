#pragma once
#include <string>
#include "GameSetUp.h"
// CPuzzlePicturePreview dialog

class CPuzzlePicturePreview : public CDialogEx
{
	DECLARE_DYNAMIC(CPuzzlePicturePreview)

public:
	CPuzzlePicturePreview(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CPuzzlePicturePreview();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	
	std::wstring m_picturePath;
	CStatic*  m_picture;
	DECLARE_MESSAGE_MAP()
public:
	void ShowPicture();
	void SetPicturePreview(std::wstring pictureInfo);
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	CGameSetUp m_pictureInfo;
};
