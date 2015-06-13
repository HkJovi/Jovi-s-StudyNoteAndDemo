// StartSoundDoc.cpp : implementation of the CStartSoundDoc class
//

#include "stdafx.h"
#include "StartSound.h"

#include "StartSoundDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStartSoundDoc

IMPLEMENT_DYNCREATE(CStartSoundDoc, CDocument)

BEGIN_MESSAGE_MAP(CStartSoundDoc, CDocument)
	//{{AFX_MSG_MAP(CStartSoundDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStartSoundDoc construction/destruction

CStartSoundDoc::CStartSoundDoc()
{
	// TODO: add one-time construction code here

}

CStartSoundDoc::~CStartSoundDoc()
{
}

BOOL CStartSoundDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CStartSoundDoc serialization

void CStartSoundDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CStartSoundDoc diagnostics

#ifdef _DEBUG
void CStartSoundDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CStartSoundDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStartSoundDoc commands
