#pragma once
#include <iostream>
typedef char* LPSTR;
typedef const char* LPCSTR;

typedef unsigned int DWORD;
typedef int BOOL;
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef int INT;
typedef unsigned int UINT;
typedef long LONG;

#define WM_COMMAND 0x0111
#define CObjectid 0xffff
#define CCmdTargetid 1
#define CWinThreadid 11
#define CWinAppid 111
#define CMyWinAppid 1111
#define CWndid 12
#define CFrameWndid 121
#define CMyFrameWndid 1211
#define CViewid 122
#define CMyViewid 1221
#define CDocumentid 13
#define CMyDocid 131

#define TRUE 1
#define FALSE 0

struct AFX_MSGMAP_ENTRY;

struct AFX_MSGMAP
{
	AFX_MSGMAP* pBaseMessageMap;
	AFX_MSGMAP_ENTRY* lpEntries;
};

#define DECLARE_MESSAGE_MAP() \
	static AFX_MSGMAP_ENTRY messageEntries[]; \
	static AFX_MSGMAP messageMap; \
	virtual AFX_MSGMAP* GetMessageMap() const;

#define BEGIN_MESSAGE_MAP(theClass,baseClass) \
	AFX_MSGMAP* theClass::GetMessageMap() const \
	{ return &theClass::messageMap; } \
	AFX_MSGMAP theClass::messageMap = { &(baseClass::messageMap),(AFX_MSGMAP_ENTRY *)&(theClass::messageEntries) };\
	AFX_MSGMAP_ENTRY theClass::messageEntries[] = \
    { 
#define END_MESSAGE_MAP() \
{ 0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0} \
    };

#include "afxmsg_.h"


class CObject
{
public:
	CObject()
	{
		std::cout << "CObject Constructor \n";
	}
	~CObject()
	{
		std::cout << "CObject Destructor \n";
	}
};


class CCmdTarget :public CObject
{
public:
	CCmdTarget()
	{
		std::cout << "CCmdTarget Constructor \n";
	}
	~CCmdTarget()
	{
		std::cout << "CCmdTarget Destructor \n";
	}
	DECLARE_MESSAGE_MAP()
};

typedef void (CCmdTarget::*AFX_PMSG)(void);

struct AFX_MSGMAP_ENTRY
{
	UINT nMessage;
	UINT nCode;
	UINT nID;
	UINT nLastID;
	UINT nSig;
	AFX_PMSG pfn;
};


class CWinThread :public CCmdTarget
{
public:
	CWinThread()
	{
		std::cout << "CWinThread Constructor \n";
	}
	~CWinThread()
	{
		std::cout << "CWinThread Destructor \n";
	}
	virtual BOOL InitInstance()
	{
		std::cout << "CWinThread::InitInstance \n";
		return TRUE;
	}
	virtual void Run()
	{
		std::cout << "CWinThread::Run \n";
	}
};


class CWnd :public CCmdTarget
{
public:
	CWnd()
	{
		std::cout << "CWnd Constructor \n";
	}
	~CWnd()
	{
		std::cout << "CWnd Destructor \n";
	}
	virtual BOOL PreCreateWindow()
	{
		std::cout << "CWnd::PreCreateWindow \n";
		return TRUE;
	}
	BOOL CreateEx()
	{
		std::cout << "CWnd::CreateEx \n";
		PreCreateWindow();
		return TRUE;
	}
	virtual BOOL Create()
	{
		std::cout << "CWnd::Create \n";
		return TRUE;
	}
	DECLARE_MESSAGE_MAP()
};

typedef void(CWnd::*AFX_PMSGW)(void);

class CView :public CWnd
{
public:
	CView()
	{
		std::cout << "CView Constructor \n";
	}
	~CView()
	{
		std::cout << "CView Destructor \n";
	}
	DECLARE_MESSAGE_MAP()
};

class CFrameWnd :public CWnd
{
public:
	CFrameWnd()
	{
		std::cout << "CFrameWnd Constructor \n";
	}
	~CFrameWnd()
	{
		std::cout << "CFrameWnd Destructor \n";
	}
	BOOL Create()
	{
		std::cout << "CFrameWnd::Create \n";
		CreateEx();
		return TRUE;
	}
	virtual BOOL PreCreateWindow()
	{
		std::cout << "CFrameWnd::PreCreateWindow \n";
		return TRUE;
	}
	DECLARE_MESSAGE_MAP()
};

class CDocument :public CCmdTarget
{
public:
	CDocument()
	{
		std::cout << "CDocument Constructor \n";
	}
	~CDocument()
	{
		std::cout << "CDocument Destructor \n";
	}
	DECLARE_MESSAGE_MAP()
};


class CWinApp :public CWinThread
{
public:
	CWinApp *m_pCurrentWinApp;
	CWnd *m_pMainWnd;
public:
	CWinApp()
	{
		m_pCurrentWinApp = this;
		std::cout << "CWinApp Constructor \n";
	}
	~CWinApp()
	{
		std::cout << "CWinApp Destructor \n";
	}
	virtual BOOL InitApplication()
	{
		std::cout << "CWinApp::InitApplication \n";
		return TRUE;
	}
	virtual BOOL InitInstance()
	{
		std::cout << "CWinApp::InitInstance \n";
		return TRUE;
	}
	virtual void Run()
	{
		std::cout << "CWinApp::Run \n";
		return CWinThread::Run();
	}
	DECLARE_MESSAGE_MAP()
};


//Global Function
CWinApp* AfxGetApp();