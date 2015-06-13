#pragma once
#include <iostream>


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


class CCmdTarget:public CObject
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


class CWinThread:public CCmdTarget
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
};


class CWinApp:public CWinThread
{
public:
	CWinApp *m_pCurrentWinApp;
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
};

class CWnd:public CCmdTarget
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

class CFrameWnd:public CWnd
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
};

class CDocument:public CCmdTarget
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


//Global Function
CWinApp* AfxGetApp();