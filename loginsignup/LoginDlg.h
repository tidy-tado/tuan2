
// loginsignupDlg.h : header file
//

#pragma once


// CloginsignupDlg dialog
class CLoginDlg : public CDialogEx
{
// Construction
public:
	CLoginDlg(CWnd* pParent = nullptr);	// standard constructor
	CString m_username;
	CString m_password;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LOGINSIGNUP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
};
