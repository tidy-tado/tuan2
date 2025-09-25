// list1.cpp : implementation file
//

#include "pch.h"
#include "loginsignup.h"
#include "afxdialogex.h"
#include "list1.h"


// list1 dialog

IMPLEMENT_DYNAMIC(list1, CDialogEx)

list1::list1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BOXCHAT, pParent)
{

}

list1::~list1()
{
}

void list1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FRIEND_LIST, m_listCtrl);
}


BEGIN_MESSAGE_MAP(list1, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_FRIEND_LIST, &list1::OnLvnItemchangedList1)
END_MESSAGE_MAP()


// list1 message handlers

void list1::OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}
