
// Ex1-MFCApplication1Dlg.h: 头文件
//

#pragma once


// CEx1MFCApplication1Dlg 对话框
class CEx1MFCApplication1Dlg : public CDialog
{
// 构造
public:
	CEx1MFCApplication1Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EX1MFCAPPLICATION1_DIALOG };
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
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeMfceditbrowse1();
	afx_msg void OnBnClickedButton1();
	TCHAR* StringToChar(CString& str);
	CString ExecuteCmd(CString str);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnEnChangeEdit2();
};
