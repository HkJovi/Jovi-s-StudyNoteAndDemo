#pragma once
#include <iostream>
#include <stdio.h>
#include <string.h>
#define BOOL int
#define TRUE 1
#define FALSE 0
#define LPCSTR LPSTR
typedef char* LPSTR;
#define UINT int
#define PASCAL _stdcall
#define TRACE1 printf

class CObject;

struct CRuntimeClass
{
	//Attributes
	LPCSTR m_lpszClassName;
	int m_nObjectSize;
	UINT m_wSchema;
	CObject *(PASCAL *m_pfnCreateObject)();
	CRuntimeClass *m_pBaseClass;

	CObject* CreateObject();
	static CRuntimeClass* PASCAL Load();

	static CRuntimeClass* pFirstClass;
	CRuntimeClass* m_pNextClass;
};

struct AFX_CLASSINIT
{
	AFX_CLASSINIT(CRuntimeClass* pNewClass);
};

#define RUNTIME_CLASS(class_name) \
	(&class_name::class##class_name)

#define DECLARE_DYNAMIC(class_name) \
public: \
	static CRuntimeClass class##class_name; \
	virtual CRuntimeClass *GetRuntimeClass() const;

#define DECLARE_DYNCREATE(class_name) \
	DECLARE_DYNAMIC(class_name) \
	static CObject* PASCAL CreateObject();

#define _IMPLEMENT_RUNTIMECLASS(class_name,base_class_name,wSchema,pfnNew) \
	static char lpsz##class_name[] = #class_name; \
	CRuntimeClass class_name::class##class_name = { \
	lpsz##class_name,sizeof(class_name),wSchema,pfnNew, \
	RUNTIME_CLASS(base_class_name),NULL }; \
	static AFX_CLASSINIT _init_##class_name(&class_name::class##class_name); \
	CRuntimeClass* class_name::GetRuntimeClass() const \
	{ return &class_name::class##class_name;} \

#define IMPLEMENT_DYNAMIC(class_name,base_class_name) \
	_IMPLEMENT_RUNTIMECLASS(class_name,base_class_name,0xFFFF,NULL)

#define IMPLEMENT_DYNCREATE(class_name,base_class_name) \
	CObject* PASCAL class_name::CreateObject() \
	{ return new class_name ;} \
	_IMPLEMENT_RUNTIMECLASS(class_name,base_class_name,0xFFFF,class_name::CreateObject)

class CObject
{
public:
	CObject()
	{

	}
	~CObject()
	{

	}
	virtual CRuntimeClass* GetRuntimeClass() const;
	BOOL IsKindOf(const CRuntimeClass* pClass) const;
	virtual void SayHello()
	{
		std::cout << "Hello CObject\n";
	}
public:
	static CRuntimeClass classCObject;
};

class CCmdTarget :public CObject
{
	DECLARE_DYNAMIC(CCmdTarget)
public:
	CCmdTarget()
	{

	}
	~CCmdTarget()
	{

	}
};

class CWinThread : public CCmdTarget
{
	DECLARE_DYNAMIC(CWinThread)
public:
	CWinThread()
	{

	}
	~CWinThread()
	{

	}
	virtual BOOL InitInstance()
	{
		return TRUE;
	}
	virtual int Run()
	{
		return 1;
	}
};

class CWnd;

class CWinApp:public CWinThread
{
	DECLARE_DYNAMIC(CWinApp)
public:
	CWinApp* m_pCurrentWinApp;
	CWnd* m_pMainWnd;
public:
	CWinApp()
	{
		m_pCurrentWinApp = this;
	}
	~CWinApp()
	{

	}
	virtual BOOL InitApplication()
	{
		return TRUE;
	}
	virtual BOOL InitInstance()
	{
		return TRUE;
	}
	virtual int Run()
	{
		return CWinThread::Run();
	}
};

class CDocument:public CCmdTarget
{
	DECLARE_DYNAMIC(CDocument)
public:
	CDocument()
	{

	}
	~CDocument()
	{

	}
};

class CWnd:public CCmdTarget
{
	DECLARE_DYNCREATE(CWnd);
public:
	CWnd()
	{

	}
	~CWnd()
	{

	}
	virtual BOOL Create();
	BOOL CreateEx();
	virtual BOOL PreCreateWindow();
	virtual void SayHello()
	{
		std::cout << "Hello CWnd\n";
	}
};

class CFrameWnd :public CWnd
{
	DECLARE_DYNCREATE(CFrameWnd)
public:
	CFrameWnd()
	{

	}
	~CFrameWnd()
	{

	}
	BOOL Create();
	virtual BOOL PreCreateWindow();
	virtual void SayHello()
	{
		std::cout << "Hello CFrameWnd\n";
	}
};

class CView :public CWnd
{
	DECLARE_DYNAMIC(CView)
public:
	CView()
	{

	}
	~CView()
	{

	}
};

CWinApp *AfxGetApp();