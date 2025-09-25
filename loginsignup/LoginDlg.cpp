// LoginDlg.cpp : implementation file
#include "pch.h"
#include "framework.h"
#include "loginsignup.h"
#include "LoginDlg.h"
#include "afxdialogex.h"
#include "BoxChatDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAboutDlg dialog used for App About
class CAboutDlg : public CDialogEx
{
public:
    CAboutDlg();

#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_ABOUTBOX };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);

protected:
    DECLARE_MESSAGE_MAP()
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

// CLoginDlg dialog
CLoginDlg::CLoginDlg(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_LOGIN_DIALOG, pParent)
    , m_loginSuccess(FALSE)
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_USERNAME, m_username);
    DDX_Text(pDX, IDC_PASSWORD, m_password);
}

BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
    ON_WM_SYSCOMMAND()
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDCANCEL, &CLoginDlg::OnBnClickedCancel)
    ON_BN_CLICKED(IDOK, &CLoginDlg::OnBnClickedOk)
END_MESSAGE_MAP()

BOOL CLoginDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

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

    SetIcon(m_hIcon, TRUE);
    SetIcon(m_hIcon, FALSE);

    return TRUE;
}

void CLoginDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLoginDlg::OnPaint()
{
    if (IsIconic())
    {
        CPaintDC dc(this);
        SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
        int cxIcon = GetSystemMetrics(SM_CXICON);
        int cyIcon = GetSystemMetrics(SM_CYICON);
        CRect rect;
        GetClientRect(&rect);
        int x = (rect.Width() - cxIcon + 1) / 2;
        int y = (rect.Height() - cyIcon + 1) / 2;
        dc.DrawIcon(x, y, m_hIcon);
    }
    else
    {
        CDialogEx::OnPaint();
    }
}

HCURSOR CLoginDlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}

void CLoginDlg::OnBnClickedCancel()
{
    CDialogEx::OnCancel();
}

void CLoginDlg::OnBnClickedOk()
{
    UpdateData(TRUE);
    char UsernameFromFile[20] = { 0 }; // Khoi tao mang bang 0
    char PasswordFromFile[20] = { 0 }; // Khoi tao mang bang 0
    bool ValidLogin = false;

    if (m_username.IsEmpty())
    {
        AfxMessageBox(_T("Vui long nhap tai khoan"));
        return;
    }
    if (m_password.IsEmpty())
    {
        AfxMessageBox(_T("Vui long nhap mat khau"));
        return;
    }

    try {
        FILE* fCheck = nullptr;
        errno_t err = fopen_s(&fCheck, "accounts.txt", "r");
        if (err != 0 || fCheck == nullptr) {
            AfxMessageBox(_T("Khong mo duoc file accounts.txt"));
            return;
        }

        CT2A convUser(m_username);
        CT2A convPass(m_password);
        const char* usernameInput = convUser;
        const char* passwordInput = convPass;

        while (fscanf_s(fCheck, "%19s %19s",
            UsernameFromFile, (unsigned)_countof(UsernameFromFile),
            PasswordFromFile, (unsigned)_countof(PasswordFromFile)) == 2)
        {
            if (strcmp(usernameInput, UsernameFromFile) == 0 &&
                strcmp(passwordInput, PasswordFromFile) == 0)
            {
                ValidLogin = true;
                break;
            }
        }

        fclose(fCheck);

        if (ValidLogin)
        {
            m_loginSuccess = TRUE;
            AfxMessageBox(_T("Dang nhap thanh cong!"));
            CDialogEx::OnOK();
        }
        else
        {
            AfxMessageBox(_T("Thong tin dang nhap khong chinh xac."));
        }
    }
    catch (...)
    {
        AfxMessageBox(_T("Dang nhap khong thanh cong"));
    }
}