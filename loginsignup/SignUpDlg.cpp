// SignUpDlg.cpp : implementation file
#include "pch.h"
#include "loginsignup.h"
#include "afxdialogex.h"
#include "SignUpDlg.h"

IMPLEMENT_DYNAMIC(SignUpDlg, CDialogEx)

SignUpDlg::SignUpDlg(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_SIGNUP_DIALOG, pParent)
{
}

SignUpDlg::~SignUpDlg()
{
}

void SignUpDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(SignUpDlg, CDialogEx)
    ON_BN_CLICKED(IDC_BUTTON_OK, &SignUpDlg::OnBnClickedButtonOk)
END_MESSAGE_MAP()

void SignUpDlg::OnBnClickedButtonOk()
{
    CString username, password;
    GetDlgItemText(IDC_EDIT_USERNAME, username);
    GetDlgItemText(IDC_EDIT_PASSWORD, password);

    if (username.GetLength() < 4 || username.GetLength() > 20) {
        AfxMessageBox(_T("Ten phai dai tu 4 den 20 ky tu"));
        return;
    }
    for (int i = 0; i < username.GetLength(); i++) {
        if (!iswalpha(username[i])) {
            AfxMessageBox(_T("Ten chi duoc su dung chu cai"));
            return;
        }
    }

    if (password.GetLength() < 8) {
        AfxMessageBox(_T("Mat khau phai dai toi thieu 8 ky tu"));
        return;
    }

    // Kiem tra tai khoan da ton tai
    bool accountExists = false;
    CStdioFile file;
    if (file.Open(_T("accounts.txt"), CFile::modeRead))
    {
        CString line;
        while (file.ReadString(line))
        {
            CString existingUsername = line.SpanExcluding(_T(" "));
            if (existingUsername == username)
            {
                accountExists = true;
                break;
            }
        }
        file.Close();
    }

    if (accountExists)
    {
        AfxMessageBox(_T("Tai khoan da ton tai"));
        return;
    }

    // Ghi tai khoan moi
    CString line = username + _T(" ") + password + _T("\n");

    if (file.Open(_T("accounts.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite))
    {
        file.SeekToEnd();
        file.WriteString(line);
        file.Close();
        AfxMessageBox(_T("Dang ky thanh cong!"));
        EndDialog(IDOK);
    }
    else
    {
        AfxMessageBox(_T("Khong the mo file accounts.txt"));
    }
}