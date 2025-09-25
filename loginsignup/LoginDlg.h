#pragma once
#include "afxdialogex.h"

// CLoginDlg dialog
class CLoginDlg : public CDialogEx
{
public:
    CLoginDlg(CWnd* pParent = nullptr);
    CString m_username;
    CString m_password;
    BOOL m_loginSuccess; // Bien theo doi trang thai dang nhap

#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_LOGIN_DIALOG };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);

protected:
    HICON m_hIcon;
    virtual BOOL OnInitDialog();
    afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();
    DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedCancel();
    afx_msg void OnBnClickedOk();
};