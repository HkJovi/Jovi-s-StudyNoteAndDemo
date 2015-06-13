#include "stdafx.h"
#include "MY.h"

extern CMyWinApp theApp;

CWinApp* AfxGetApp()
{
	return theApp.m_pCurrentWinApp;
}

AFX_MSGMAP* CCmdTarget::GetMessageMap() const
{
	return &CCmdTarget::messageMap;
}

AFX_MSGMAP CCmdTarget::messageMap = { NULL, &CCmdTarget::messageEntries[0] };
AFX_MSGMAP_ENTRY CCmdTarget::messageEntries[] =
{
	{ 0, 0, CCmdTargetid, 0, AfxSig_end, 0 }
};

BEGIN_MESSAGE_MAP(CWnd,CCmdTarget)
	ON_COMMAND(CWndid,0)
END_MESSAGE_MAP()

BEGIN_MESSAGE_MAP(CFrameWnd, CWnd)
	ON_COMMAND(CFrameWndid, 0)
END_MESSAGE_MAP()

BEGIN_MESSAGE_MAP(CDocument, CCmdTarget)
	ON_COMMAND(CDocumentid, 0)
END_MESSAGE_MAP()

BEGIN_MESSAGE_MAP(CView, CWnd)
	ON_COMMAND(CViewid, 0)
END_MESSAGE_MAP()

BEGIN_MESSAGE_MAP(CWinApp, CCmdTarget)
	ON_COMMAND(CWinAppid, 0)
END_MESSAGE_MAP()
