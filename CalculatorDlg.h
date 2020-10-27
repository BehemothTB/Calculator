
// CalculatorDlg.h: 头文件
//

#include "Function.h"
#include <sstream>

#pragma once


// CCalculatorDlg 对话框
class CCalculatorDlg : public CDialogEx
{
// 构造
public:
	CCalculatorDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	CWnd* pWait;
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
//	afx_msg void OnEnableWaiting();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
//	bool WaitingInit();
	afx_msg void OnClickedButtoncal();
protected:
	double min;
	double max;
	double sumxy;
	double sumy;
//	CString edit_fx;
	Function* function;
public:
	CEdit edit_fx;
	void Calculate();
//	CEdit edit_max;
//	CEdit edit_min;
protected:
	double locate;
public:
//	CStatic edit_locate;
//	CStatic edit_force;
};
