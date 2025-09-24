#pragma once
#include "afxdialogex.h"


// SignUpDlg dialog

class SignUpDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SignUpDlg)

public:
	SignUpDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~SignUpDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SIGNUP_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonOk();
};
