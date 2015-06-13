// StartSoundView.cpp : implementation of the CStartSoundView class
//

#include "stdafx.h"
#include "StartSound.h"

#include "StartSoundDoc.h"
#include "StartSoundView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStartSoundView

IMPLEMENT_DYNCREATE(CStartSoundView, CView)

BEGIN_MESSAGE_MAP(CStartSoundView, CView)
	//{{AFX_MSG_MAP(CStartSoundView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStartSoundView construction/destruction

CStartSoundView::CStartSoundView()
{
	// TODO: add construction code here

}

CStartSoundView::~CStartSoundView()
{
}

BOOL CStartSoundView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CStartSoundView drawing

void CStartSoundView::OnDraw(CDC* pDC)
{
	CStartSoundDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CStartSoundView printing

BOOL CStartSoundView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CStartSoundView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CStartSoundView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CStartSoundView diagnostics

#ifdef _DEBUG
void CStartSoundView::AssertValid() const
{
	CView::AssertValid();
}

void CStartSoundView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CStartSoundDoc* CStartSoundView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStartSoundDoc)));
	return (CStartSoundDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStartSoundView message handlers
