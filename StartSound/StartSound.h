// StartSound.h : main header file for the STARTSOUND application
//

#if !defined(AFX_STARTSOUND_H__9262D6B7_073C_4190_BF7B_C61DA0633AAA__INCLUDED_)
#define AFX_STARTSOUND_H__9262D6B7_073C_4190_BF7B_C61DA0633AAA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CStartSoundApp:
// See StartSound.cpp for the implementation of this class
//

class CStartSoundApp : public CWinApp
{
public:
	CStartSoundApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStartSoundApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CStartSoundApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STARTSOUND_H__9262D6B7_073C_4190_BF7B_C61DA0633AAA__INCLUDED_)
