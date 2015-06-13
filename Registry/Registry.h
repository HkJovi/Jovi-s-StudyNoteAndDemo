// Registry.h : main header file for the REGISTRY application
//

#if !defined(AFX_REGISTRY_H__426B03C5_CA7F_4A41_A301_21D156A41E9B__INCLUDED_)
#define AFX_REGISTRY_H__426B03C5_CA7F_4A41_A301_21D156A41E9B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRegistryApp:
// See Registry.cpp for the implementation of this class
//

class CRegistryApp : public CWinApp
{
public:
	CRegistryApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRegistryApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRegistryApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGISTRY_H__426B03C5_CA7F_4A41_A301_21D156A41E9B__INCLUDED_)
