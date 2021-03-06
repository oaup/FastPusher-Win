// FastPusherWinDlg.cpp: 实现文件

#include "stdafx.h"
#include "FastPusherWin.h"
#include "FastPusherWinDlg.h"
#include "afxdialogex.h"
//#include <avdevice.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CFastPusherWinDlg::CFastPusherWinDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FASTPUSHERWIN_DIALOG, pParent)
	, m_pIGrabDesktopDevice(nullptr)
	, m_pICameraDevice(nullptr)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

BEGIN_MESSAGE_MAP(CFastPusherWinDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnBnClickedButton2)
END_MESSAGE_MAP()


// CFastPusherWinDlg 消息处理程序

BOOL CFastPusherWinDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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
	m_pIGrabDesktopDevice = new CJwGrabDesktopDevice;
	m_pICameraDevice = new CJwCameraDevice;

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CFastPusherWinDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CFastPusherWinDlg::OnPaint()
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
HCURSOR CFastPusherWinDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CFastPusherWinDlg::OnDestroy()
{
	if (nullptr != m_pIGrabDesktopDevice)
	{
		delete m_pIGrabDesktopDevice;
		m_pIGrabDesktopDevice = nullptr;
	}
	if (nullptr != m_pICameraDevice)
	{
		delete m_pICameraDevice;
		m_pICameraDevice = nullptr;
	}
	__super::OnDestroy();
}

void CFastPusherWinDlg::OnBnClickedButton1()
{
	m_pIGrabDesktopDevice->Open();
}

void CFastPusherWinDlg::OnBnClickedButton2()
{
	m_pICameraDevice->Open();
}
