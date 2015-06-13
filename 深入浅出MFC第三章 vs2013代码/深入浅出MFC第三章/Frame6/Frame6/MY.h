#pragma once
#include "MFC.h"

class CMyWinApp :public CWinApp
{
public:
	CMyWinApp()
	{

	}
	~CMyWinApp()
	{

	}
	virtual BOOL InitInstance();
};

class CMyFrameWnd:public CFrameWnd
{
	DECLARE_DYNCREATE(CMyFrameWnd)
public:
	CMyFrameWnd();
	~CMyFrameWnd()
	{

	}
	virtual void SayHello()
	{
		std::cout << "Hello CMyFrameWnd\n";
	}
};

class CMyDoc:public CDocument
{
	DECLARE_DYNCREATE(CMyDoc)
public:
	CMyDoc()
	{

	}
	~CMyDoc()
	{

	}
	virtual void SayHello()
	{
		std::cout << "Hello CMyDoc\n";
	}
};

class CMyView:public CView
{
	DECLARE_DYNCREATE(CMyView)
public:
	CMyView()
	{

	}
	~CMyView()
	{

	}
	virtual void SayHello()
	{
		std::cout << "Hello CMyView\n";
	}
};

void PrintAllClasses();