
// 00_02_04_MFCsystem_01Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "00_02_04_MFCsystem_01.h"
#include "00_02_04_MFCsystem_01Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMy00_02_04_MFCsystem_01Dlg �Ի���



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


// CMy00_02_04_MFCsystem_01Dlg ��Ϣ�������

BOOL CMy00_02_04_MFCsystem_01Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMy00_02_04_MFCsystem_01Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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
	MessageBoxA(0, "QQ�ж�,ǿ���˳�!","360������ʾ",1);
	system("taskkill /f /im QQ.exe");//   /fǿ�� /im ������
}


void CMy00_02_04_MFCsystem_01Dlg::OnBnClickedButton4()
{
	system("\"C:\\Program Files\\Internet Explorer\\iexplore.exe\" http://www.baidu.com");
}


void CMy00_02_04_MFCsystem_01Dlg::OnBnClickedButton5()
{
	MessageBoxA(0, "��⵽����վ������в,�Ѿ�ǿ�ƹرմ���վ.", "360������ʾ", 1);
	system("taskkill /f /im iexplore.exe");
}
