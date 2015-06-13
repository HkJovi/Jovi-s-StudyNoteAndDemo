#pragma once
#include "MFC.h"

class CMyFrameWnd :public CFrameWnd
{
public:
	CMyFrameWnd()
	{
		Create();
		std::cout << "CMyFrameWnd Constructor \n";
	}
	~CMyFrameWnd()
	{
		std::cout << "CMyFrameWnd Destructor \n";
	}
	DECLARE_MESSAGE_MAP()
};


class CMyWinApp :public CWinApp
{
public:
	CMyWinApp()
	{
		std::cout << "CMyWinApp Constructor \n";
	}
	~CMyWinApp()
	{
		std::cout << "CMyWinApp Destructor \n";
	}
	virtual BOOL InitInstance()
	{
		std::cout << "CMyWinApp::InitInstance \n";
		m_pMainWnd = new CMyFrameWnd;
		return TRUE;
	}
	DECLARE_MESSAGE_MAP()
};

class CMyView :public CView
{
public:
	CMyView()
	{

	}
	~CMyView()
	{

	}

	DECLARE_MESSAGE_MAP()
};

class CMyDoc: public CDocument
{
public:
	CMyDoc()
	{

	}
	~CMyDoc()
	{

	}
	DECLARE_MESSAGE_MAP()
};

