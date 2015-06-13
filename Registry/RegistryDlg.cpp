// RegistryDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Registry.h"
#include "RegistryDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRegistryDlg dialog

CRegistryDlg::CRegistryDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRegistryDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRegistryDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRegistryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRegistryDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRegistryDlg, CDialog)
	//{{AFX_MSG_MAP(CRegistryDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_btncx, Onbtncx)
	ON_BN_CLICKED(IDC_btnxg, Onbtnxg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRegistryDlg message handlers

BOOL CRegistryDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CRegistryDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CRegistryDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CRegistryDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CRegistryDlg::Onbtncx() 
{
	// TODO: Add your control notification handler code here
	HKEY hKEY; 
	LPCTSTR data_set="Software\\Microsoft\\Ms Setup (ACME)\\User Info\\";
	long ret0 =::RegOpenKeyEx(HKEY_CURRENT_USER,data_set,0,KEY_READ,&hKEY);
	if (ret0!=ERROR_SUCCESS)
	{
		MessageBox("错误！无法打开键值");
		return;
	}
	//查询用户
	LPBYTE username_Get=new byte[40];
	DWORD type_1=REG_SZ;
	DWORD cbData_1 = 40;
	long ret1=::RegQueryValueEx(hKEY,"DefName",NULL,
		&type_1, //键值类型
		username_Get, //保存查询数据
		&cbData_1); //预设的数据长度
	if (ret1!=ERROR_SUCCESS)
	{
		MessageBox("错误！无法打开键值");
		return;
	}
	//查询公司
	LPBYTE Company_Get=new byte[40];
	DWORD type_2=REG_SZ;
	DWORD cbData_2 = 40;
	long ret2=::RegQueryValueEx(hKEY,"DefCompany",NULL,
		&type_2, //键值类型
		Company_Get, //保存查询数据
		&cbData_2); //预设的数据长度
	if (ret2!=ERROR_SUCCESS)
	{
		MessageBox("错误！无法打开键值");
		return;
	}
	CString str_username=CString(username_Get);
	CString str_company=CString(Company_Get);
	delete[] username_Get;
	delete[] Company_Get;
	::RegCloseKey(hKEY);
	CString value="用户名："+str_username+",公司名："+str_company;
	AfxMessageBox(value,MB_OK|MB_ICONINFORMATION);
}

void CRegistryDlg::Onbtnxg() 
{
	// TODO: Add your control notification handler code here
	CModify modify;	
	if(modify.DoModal()==IDOK)
	{
		CString str_username = modify.m_Username;
		CString str_company=modify.m_Company;
		//和获取一样得到HKEY
		HKEY hKEY;
		LPCTSTR data_set="Software\\Microsoft\\Ms Setup (ACME)\\User Info\\";
		long ret0=::RegOpenKeyEx(HKEY_CURRENT_USER,data_set,NULL,KEY_WRITE,&hKEY); //获取写入权限
		if (ret0!=ERROR_SUCCESS)
		{
			MessageBox("错误！无法打开键值");
		    return;
		}
		//修改用户名
		LPBYTE username_Set=CString_To_LPBYTE(str_username);
		DWORD type_1=REG_SZ;
		DWORD cbData_1=str_username.GetLength()+1;
		long ret1=::RegSetValueEx(hKEY,"DefName",NULL,type_1,username_Set,cbData_1);
		if (ret1!=ERROR_SUCCESS)
		{
			MessageBox("错误！修改用户名失败");
			return;
		}
		//修改公司
		LPBYTE company_Set=CString_To_LPBYTE(str_company);
		DWORD type_2=REG_SZ;
		DWORD cbData_2=str_company.GetLength()+1;
		long ret2=::RegSetValueEx(hKEY,"DefCompany",NULL,type_2,company_Set,cbData_2);
		if (ret2!=ERROR_SUCCESS)
		{
			MessageBox("错误！修改公司失败");
			return;
		}
	    AfxMessageBox("修改成功！",MB_OK|MB_ICONINFORMATION);
	}
}

LPBYTE CRegistryDlg::CString_To_LPBYTE(CString str)
{
	LPBYTE lpb=new byte[str.GetLength()+1];
	for(int i=0;i<str.GetLength();i++)
	{
		lpb[i]=str[i];
		lpb[str.GetLength()]=0;
	}
	return lpb;
}
