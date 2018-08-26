
// ChildView.h : interface of the CChildView class
//



#include "GameIntro.h"
#include "GameSetUp.h"
// CChildView window

class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	BOOL indicator;

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void newGameSetUp();
	CSetGameDialog m_setUpDialog;
	CGameIntro m_startGame;
	std::vector<POINT>clickedPixelCoords;
	void start();
	HDC hdc;
	int indicators = 0;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

