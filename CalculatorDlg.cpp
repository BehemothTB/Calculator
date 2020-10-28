
// CalculatorDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
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
//	CWnd* pWait;
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


// CCalculatorDlg 对话框



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	min = 0.0;
	max = 0.0;
	sumxy = 0.0;
	sumy = 0.0;
	locate = 0.0;
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_EDITFX, edit_fx);
	DDX_Control(pDX, IDC_EDITFX, edit_fx);
	//  DDX_Control(pDX, IDC_MAX, edit_max);
	//  DDX_Control(pDX, IDC_MIN, edit_min);
	//  DDX_Control(pDX, IDC_ANSWERX, edit_locate);
	//  DDX_Control(pDX, IDC_ANSWERY, edit_force);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CREATE()
//	ON_STN_ENABLE(IDC_WAITING, &CCalculatorDlg::OnEnableWaiting)
ON_WM_TIMER()
ON_BN_CLICKED(IDC_BUTTONCAL, &CCalculatorDlg::OnClickedButtoncal)
END_MESSAGE_MAP()


// CCalculatorDlg 消息处理程序

BOOL CCalculatorDlg::OnInitDialog()
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

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCalculatorDlg::OnPaint()
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
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



int CCalculatorDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码

	this->SetTimer(WAITING_INITTIMER, WAITING_INITTICK, NULL);

	return 0;
}


void CCalculatorDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	if ((nIDEvent == WAITING_INITTIMER) && (pWait = this->GetDlgItem(IDC_WAITING)))
	{
		pWait->SetWindowPos(NULL, 0, 0, 0, 0, SWP_NOZORDER | SWP_NOMOVE | SWP_HIDEWINDOW);
		this->KillTimer(WAITING_INITTIMER);
	}

	CDialogEx::OnTimer(nIDEvent);
}


void CCalculatorDlg::OnClickedButtoncal()
{
	// TODO: 在此添加控件通知处理程序代码

	pWait->SetWindowPos(NULL, 0, 0, 0, 0, SWP_NOZORDER | SWP_NOMOVE | SWP_SHOWWINDOW);

	CString str_fx, str_locate, str_force;
	char* text;
	
	edit_fx.GetWindowTextW(str_fx);
	USES_CONVERSION;
	text = T2A(str_fx);
	
	if (function)
	{
		delete function;
	}
	
	sumxy = sumy = 0;
	
	function = new Function;
	function->LoadText(text);
	max = this->GetDlgItemInt(IDC_MAX, 0, 1);
	min = this->GetDlgItemInt(IDC_MIN, 0, 1);
	
	this->Calculate();

	std::stringstream ss;
	ss << locate;
	str_locate = ss.str().c_str();
	ss.str("");
	ss << sumy;
	str_force = ss.str().c_str();
	ss.str("");

	this->SetDlgItemTextW(IDC_ANSWERX, str_locate);
	this->SetDlgItemTextW(IDC_ANSWERY, str_force);

	pWait->SetWindowPos(NULL, 0, 0, 0, 0, SWP_NOZORDER | SWP_NOMOVE | SWP_HIDEWINDOW);

}


void CCalculatorDlg::Calculate()
{
	// TODO: 在此处添加实现代码.

	double x;
	double diff = (max - min) / DENOMINATOR;
	for (x = min; x <= max; x += diff)
	{
		function->x = x;
		function->LoadBackup();
		function->GetAnswer();
		sumxy += x * function->y * diff;
		sumy += function->y * diff;
	}
	locate = sumxy / sumy;
}
