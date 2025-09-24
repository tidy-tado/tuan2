// MainDlg.cpp : implementation file
//

#include "pch.h"
#include "loginsignup.h"
#include "afxdialogex.h"
#include "MainDlg.h"
#include "SignUpDlg.h"   
#include "LoginDlg.h" 

// MainDlg dialog

IMPLEMENT_DYNAMIC(MainDlg, CDialogEx)

MainDlg::MainDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MAINDIALOG, pParent)
{

}

MainDlg::~MainDlg()
{
}

void MainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MainDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SIGNUP, &MainDlg::OnBnClickedButtonSignup)
	ON_BN_CLICKED(IDC_BUTTON_LOGIN, &MainDlg::OnBnClickedButtonLogin)
END_MESSAGE_MAP()


// MainDlg message handlers

void MainDlg::OnBnClickedButtonSignup()
{
	SignUpDlg dlgSignUp;       // mo form dang ky
	dlgSignUp.DoModal();
}

void MainDlg::OnBnClickedButtonLogin()
{
	CLoginDlg dlgLogin;   // mo form login
	dlgLogin.DoModal();
}
