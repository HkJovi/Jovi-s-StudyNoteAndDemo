// StartSoundDoc.h : interface of the CStartSoundDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_STARTSOUNDDOC_H__5F508063_D7CD_48F2_AA81_4718A997A15B__INCLUDED_)
#define AFX_STARTSOUNDDOC_H__5F508063_D7CD_48F2_AA81_4718A997A15B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CStartSoundDoc : public CDocument
{
protected: // create from serialization only
	CStartSoundDoc();
	DECLARE_DYNCREATE(CStartSoundDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStartSoundDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CStartSoundDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CStartSoundDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STARTSOUNDDOC_H__5F508063_D7CD_48F2_AA81_4718A997A15B__INCLUDED_)
