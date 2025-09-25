// BoxChatDlg.cpp : implementation file
#include "pch.h"
#include "loginsignup.h"
#include "BoxChatDlg.h"
#include "afxdialogex.h"

IMPLEMENT_DYNAMIC(CBoxChatDlg, CDialogEx)

CBoxChatDlg::CBoxChatDlg(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_BOXCHAT, pParent)
    , m_username(_T(""))
{
}

CBoxChatDlg::~CBoxChatDlg()
{
}

void CBoxChatDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_FRIEND_LIST, m_friendList);
    DDX_Control(pDX, IDC_CHAT_DISPLAY, m_chatDisplay);
}

BEGIN_MESSAGE_MAP(CBoxChatDlg, CDialogEx)
    ON_NOTIFY(LVN_ITEMCHANGED, IDC_FRIEND_LIST, &CBoxChatDlg::OnLvnItemchangedFriendList)
END_MESSAGE_MAP()

BOOL CBoxChatDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // Cau hinh CListCtrl
    m_friendList.InsertColumn(0, _T("Friends"), LVCFMT_LEFT, 150);

    // Them danh sach ban be mau
    m_friendList.InsertItem(0, _T("User1"));
    m_friendList.InsertItem(1, _T("User2"));
    m_friendList.InsertItem(2, _T("User3"));
    m_friendList.SetExtendedStyle(m_friendList.GetExtendedStyle() | LVS_EX_FULLROWSELECT);

    // Thong bao chao mung=))))
    CString welcome;
    welcome.Format(_T("Hi %s! let chatting with somebody."), m_username.IsEmpty() ? _T("Guest") : m_username);
    m_chatDisplay.SetWindowText(welcome);


    return TRUE;
}

void CBoxChatDlg::OnLvnItemchangedFriendList(NMHDR* pNMHDR, LRESULT* pResult)
{
    LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
    if (pNMLV->uNewState & LVIS_SELECTED)
    {
        int selectedItem = pNMLV->iItem;
        CString friendName = m_friendList.GetItemText(selectedItem, 0);
        CString chatContent;

        // Hoi thoai FAKE
        if (friendName == _T("User1"))
        {
            chatContent = _T("User1: What's up, long time no see my boy!\r\n")
                + m_username + _T(": hi, u good buddies?\r\n")
                + _T("User1: yah, im good, what about u?\r\n");
        }
        else if (friendName == _T("User2"))
        {
            chatContent = _T("User2: Hey, what are u doing homie?\r\n")
                + m_username + _T(": Just cook my code homie!\r\n")
                + _T("User2: Cool, keep doing this shit!\r\n");
        }
        else if (friendName == _T("User3"))
        {
            chatContent = _T("User3: What's new?\r\n")
                + m_username + _T(": Nothing!\r\n")
                + _T("User3: Haha, let get out, touch a grass with me?\r\n");
        }
        else
        {
            chatContent.Format(_T("In chatting with %s\r\n"), friendName);
        }

        m_chatDisplay.SetWindowText(chatContent);
    }
    *pResult = 0;
}