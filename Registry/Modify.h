#if !defined(AFX_MODIFY_H__D330E2AD_E939_4C60_A89D_08AE065A2F17__INCLUDED_)
#define AFX_MODIFY_H__D330E2AD_E939_4C60_A89D_08AE065A2F17__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Modify.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CModify dialog

class CModify : public CDialog
{
// Construction
public:
	CModify(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CModify)
	enum { IDD = IDD_DIALOG1 };
	CString	m_Username;
	CString	m_Company;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CModify)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CModify)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MODIFY_H__D330E2AD_E939_4C60_A89D_08AE065A2F17__INCLUDED_)
