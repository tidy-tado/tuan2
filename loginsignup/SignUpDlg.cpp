// SignUpDlg.cpp : implementation file
//

#include "pch.h"
#include "loginsignup.h"
#include "afxdialogex.h"
#include "SignUpDlg.h"


// SignUpDlg dialog

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


// SignUpDlg message handlers

void SignUpDlg::OnBnClickedButtonOk()
{
    CString username, password;
    GetDlgItemText(IDC_EDIT_USERNAME, username);
    GetDlgItemText(IDC_EDIT_PASSWORD, password);

    // kiem tra username
    if (username.GetLength() < 4 || username.GetLength() > 20) {
        AfxMessageBox(L"Ten phai dai tu 4 den 20 ki tu");
        return;
    }
    for (int i = 0; i < username.GetLength(); i++) {
        if (!iswalpha(username[i])) { // chi cho chu cai
            AfxMessageBox(L"Ten chi duoc su dung chu cai.");
            return;
        }
    }

    // Kiem tra mat khau
    if (password.GetLength() < 8) {
        AfxMessageBox(L"Mat khau phai dai toi thieu 8 ki tu");
        return;
    }

    // PASS thi luu vao file accounts.txt
    CStdioFile file;
    if (file.Open(L"E:\\accounts.txt", CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite)) {
        file.SeekToEnd();
        file.WriteString(username + L" " + password + L"\n");
        file.Close();
        AfxMessageBox(L"Dang ki thanh cong!");
        EndDialog(IDOK);
    }
    else {
        AfxMessageBox(L"Khong the mo file accounts.txt");
    }
}



