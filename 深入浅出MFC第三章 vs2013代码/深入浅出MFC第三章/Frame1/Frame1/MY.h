#pragma once
#include "MFC.h"

class CMyWinApp:public CWinApp
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
};

class CMyFrameWnd:public CFrameWnd
{
public:
	CMyFrameWnd()
	{
		std::cout << "CMyFrameWnd Constructor \n";
	}
	~CMyFrameWnd()
	{
		std::cout << "CMyFrameWnd Destructor \n";
	}
};

