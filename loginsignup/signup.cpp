// signup.cpp : implementation file
//

#include "pch.h"
#include "loginsignup.h"
#include "afxdialogex.h"
#include "signup.h"

#include "loginsignupDlg.h"

// signup dialog

IMPLEMENT_DYNAMIC(signup, CDialogEx)

signup::signup(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MAINDLG, pParent)
{

}

signup::~signup()
{
}

void signup::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(signup, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTONLOGIN, &signup::OnBnClickedButtonlogin)
	ON_BN_CLICKED(IDC_BUTTONSIGNUP, &signup::OnBnClickedButtonsignup)
END_MESSAGE_MAP()


// signup message handlers

void signup::OnBnClickedButtonlogin()
{
	CloginsignupDlg loginDlg;
	loginDlg.DoModal();   // mo cua so login
}


//DANG KI
void signup::OnBnClickedButtonsignup()
{
    UpdateData(TRUE); // lay du lieu tu edit box

    if (m_newUsername.IsEmpty())
    {
        AfxMessageBox(_T("Vui l�ng nh?p t�n t�i kho?n!"));
        return;
    }
    if (m_newPassword.IsEmpty())
    {
        AfxMessageBox(_T("Vui l�ng nh?p m?t kh?u!"));
        return;
    }

    // -----------------------------
    // Ki?m tra ?i?u ki?n Username
    // -----------------------------
    int lenUser = m_newUsername.GetLength();
    if (lenUser < 4 || lenUser > 20)
    {
        AfxMessageBox(_T("T�n t�i kho?n ph?i t? 4 ??n 20 k� t?."));
        return;
    }

    // Ch? cho ph�p ch? (a-z, A-Z)
    for (int i = 0; i < lenUser; i++)
    {
        if (!isalpha(m_newUsername[i]))
        {
            AfxMessageBox(_T("T�n t�i kho?n ch? ???c ch?a ch? c�i (A-Z, a-z)."));
            return;
        }
    }

    // -----------------------------
    // Ki?m tra ?i?u ki?n Password
    // -----------------------------
    if (m_newPassword.GetLength() < 8)
    {
        AfxMessageBox(_T("M?t kh?u ph?i c� �t nh?t 8 k� t?."));
        return;
    }

    // -----------------------------
    // Ki?m tra tr�ng username trong file
    // -----------------------------
    FILE* fCheck = nullptr;
    errno_t err = fopen_s(&fCheck, "E:\\accounts.txt", "r");
    if (err == 0 && fCheck != nullptr)
    {
        char u[50], p[50];
        CT2A convUser(m_newUsername);
        const char* newUser = convUser;

        while (fscanf_s(fCheck, "%49s %49s", u, (unsigned)_countof(u), p, (unsigned)_countof(p)) == 2)
        {
            if (strcmp(newUser, u) == 0)
            {
                fclose(fCheck);
                AfxMessageBox(_T("T�i kho?n ?� t?n t?i!"));
                return;
            }
        }
        fclose(fCheck);
    }

    // -----------------------------
    // Ghi th�m user m?i v�o file
    // -----------------------------
    FILE* fWrite = nullptr;
    err = fopen_s(&fWrite, "E:\\accounts.txt", "a");
    if (err != 0 || fWrite == nullptr)
    {
        AfxMessageBox(_T("Kh�ng m? ???c file ?? ghi."));
        return;
    }

    CT2A convUser(m_newUsername);
    CT2A convPass(m_newPassword);

    fprintf(fWrite, "%s %s\n", (const char*)convUser, (const char*)convPass);
    fclose(fWrite);

    AfxMessageBox(_T("??ng k� th�nh c�ng!"));
}
