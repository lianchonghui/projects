
// 00_02_04_MFCsystem_01Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "00_02_04_MFCsystem_01.h"
#include "00_02_04_MFCsystem_01Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMy00_02_04_MFCsystem_01Dlg 对话框



CMy00_02_04_MFCsystem_01Dlg::CMy00_02_04_MFCsystem_01Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY00_02_04_MFCSYSTEM_01_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy00_02_04_MFCsystem_01Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy00_02_04_MFCsystem_01Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMy00_02_04_MFCsystem_01Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMy00_02_04_MFCsystem_01Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMy00_02_04_MFCsystem_01Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMy00_02_04_MFCsystem_01Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMy00_02_04_MFCsystem_01Dlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CMy00_02_04_MFCsystem_01Dlg 消息处理程序

BOOL CMy00_02_04_MFCsystem_01Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMy00_02_04_MFCsystem_01Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMy00_02_04_MFCsystem_01Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMy00_02_04_MFCsystem_01Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy00_02_04_MFCsystem_01Dlg::OnBnClickedButton1()
{
	#include<stdlib.h>
	system("calc");
}


void CMy00_02_04_MFCsystem_01Dlg::OnBnClickedButton2()
{
//#include<stdio.h>
	system("\"C:\\Program Files (x86)\\Tencent\\QQ\\Bin\\QQScLauncher.exe\"");
}


void CMy00_02_04_MFCsystem_01Dlg::OnBnClickedButton3()
{
//#include<Windows.h>
	MessageBoxA(0, "QQ中毒,强制退出!","360友情提示",1);
	system("taskkill /f /im QQ.exe");//   /f强制 /im 进程名
}


void CMy00_02_04_MFCsystem_01Dlg::OnBnClickedButton4()
{
	system("\"C:\\Program Files\\Internet Explorer\\iexplore.exe\" http://www.baidu.com");
}


void CMy00_02_04_MFCsystem_01Dlg::OnBnClickedButton5()
{
	MessageBoxA(0, "检测到此网站存在威胁,已经强制关闭此网站.", "360友情提示", 1);
	system("taskkill /f /im iexplore.exe");
}
