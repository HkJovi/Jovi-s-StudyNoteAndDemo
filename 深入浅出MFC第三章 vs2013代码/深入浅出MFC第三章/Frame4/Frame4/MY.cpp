#include "stdafx.h"
#include "MY.h"

CMyWinApp theApp;

BOOL CMyWinApp::InitInstance()
{
	m_pMainWnd = new CMyFrameWnd;
	return TRUE;
}

CMyFrameWnd::CMyFrameWnd()
{
	Create();
}

void PrintAllClasses()
{
	CRuntimeClass* pClass;
	for (pClass = CRuntimeClass::pFirstClass; pClass != NULL; pClass = pClass->m_pNextClass)
	{
		std::cout << pClass->m_lpszClassName << "\n";
		std::cout << pClass->m_nObjectSize << "\n";
		std::cout << pClass->m_wSchema << "\n";
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	CWinApp *pApp = AfxGetApp();
	pApp->InitApplication();
	pApp->InitInstance();
	pApp->Run();
	CMyDoc *pMydoc = new CMyDoc;
	PrintAllClasses();
	std::cout << pMydoc->IsKindOf(RUNTIME_CLASS(CWinApp)) << std::endl;
	std::cout << pMydoc->IsKindOf(RUNTIME_CLASS(CCmdTarget)) << std::endl;
	system("pause");
	return 0;
}
