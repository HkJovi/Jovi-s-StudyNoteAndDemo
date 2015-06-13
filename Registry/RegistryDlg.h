// RegistryDlg.h : header file
//

#if !defined(AFX_REGISTRYDLG_H__E4A238D8_ADD2_4B89_BB4D_5CC33A99BCE3__INCLUDED_)
#define AFX_REGISTRYDLG_H__E4A238D8_ADD2_4B89_BB4D_5CC33A99BCE3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#include "Modify.h"
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRegistryDlg dialog

class CRegistryDlg : public CDialog
{
// Construction
public:
	LPBYTE CString_To_LPBYTE(CString str);
	CRegistryDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRegistryDlg)
	enum { IDD = IDD_REGISTRY_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRegistryDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRegistryDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void Onbtncx();
	afx_msg void Onbtnxg();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGISTRYDLG_H__E4A238D8_ADD2_4B89_BB4D_5CC33A99BCE3__INCLUDED_)
