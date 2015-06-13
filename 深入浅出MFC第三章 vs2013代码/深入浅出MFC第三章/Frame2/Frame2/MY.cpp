#include "stdafx.h"
#include "MY.h"

CMyWinApp theApp;

int _tmain(int argc, _TCHAR* argv[])
{
	CWinApp * pApp = AfxGetApp();
	pApp->InitApplication();
	pApp->InitInstance();
	pApp->Run();
	system("pause");
	return 0;
}