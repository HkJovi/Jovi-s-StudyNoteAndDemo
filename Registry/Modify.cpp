// Modify.cpp : implementation file
//

#include "stdafx.h"
#include "Registry.h"
#include "Modify.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CModify dialog


CModify::CModify(CWnd* pParent /*=NULL*/)
	: CDialog(CModify::IDD, pParent)
{
	//{{AFX_DATA_INIT(CModify)
	m_Username = _T("");
	m_Company = _T("");
	//}}AFX_DATA_INIT
}


void CModify::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CModify)
	DDX_Text(pDX, IDC_COMPANY,  m_Company);
	DDX_Text(pDX, IDC_USERNAME, m_Username);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CModify, CDialog)
	//{{AFX_MSG_MAP(CModify)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CModify message handlers
