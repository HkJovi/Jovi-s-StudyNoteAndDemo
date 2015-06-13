// StartSoundView.h : interface of the CStartSoundView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_STARTSOUNDVIEW_H__B83389EB_957A_4B89_82EA_C0E116D1BB5E__INCLUDED_)
#define AFX_STARTSOUNDVIEW_H__B83389EB_957A_4B89_82EA_C0E116D1BB5E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CStartSoundView : public CView
{
protected: // create from serialization only
	CStartSoundView();
	DECLARE_DYNCREATE(CStartSoundView)

// Attributes
public:
	CStartSoundDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStartSoundView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CStartSoundView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CStartSoundView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in StartSoundView.cpp
inline CStartSoundDoc* CStartSoundView::GetDocument()
   { return (CStartSoundDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STARTSOUNDVIEW_H__B83389EB_957A_4B89_82EA_C0E116D1BB5E__INCLUDED_)
