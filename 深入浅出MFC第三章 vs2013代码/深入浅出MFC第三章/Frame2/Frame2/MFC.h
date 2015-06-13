#pragma once
#include <iostream>
#include <typeinfo.h>
#define TRUE 1
#define FALSE 0
#define BOOL int

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
};

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
};


//Global Function
CWinApp* AfxGetApp();