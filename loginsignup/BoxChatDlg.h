#pragma once
#include "afxdialogex.h"

// BoxChatDlg dialog
class CBoxChatDlg : public CDialogEx
{
    DECLARE_DYNAMIC(CBoxChatDlg)

public:
    CBoxChatDlg(CWnd* pParent = nullptr);   // standard constructor
    virtual ~CBoxChatDlg();
    CString m_username; // Luu ten nguoi dung hien tai

    // Dialog Data
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_BOXCHAT_DIALOG };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    virtual BOOL OnInitDialog();

    DECLARE_MESSAGE_MAP()
public:
    CListCtrl m_friendList; // Danh sach ban be
    CEdit m_chatDisplay;    // Man hinh hoi thoai FAKE
    afx_msg void OnLvnItemchangedFriendList(NMHDR* pNMHDR, LRESULT* pResult); // Su kien chon ban be de chat
};