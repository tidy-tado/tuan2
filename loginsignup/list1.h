#pragma once
#include "afxdialogex.h"


// list1 dialog

class list1 : public CDialogEx
{
	DECLARE_DYNAMIC(list1)

public:
	list1(CWnd* pParent = nullptr);   // standard constructor
	virtual ~list1();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BOXCHAT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	CListCtrl m_listCtrl;
};
