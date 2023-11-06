#pragma once


#include "KHOpenAPICtrl.h"
#include "GridCtrl\GridCtrl.h"


// CMainDlg dialog

class CMainDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMainDlg)

public:
	CMainDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CMainDlg();


public:
	BOOL GetNextScreenNum(int nScreenType);
	CMapStringToString m_mapScreenNum;
	CMapStringToPtr m_mapScreen;
	int m_nScrN0;
	long		m_nRet;

// Dialog Data
	enum { IDD = IDD_MAIN_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	//CKhopenapictrl1 m_ctrlOpenAPI;
	CKHOpenAPI	m_khOpenApi;
	afx_msg void OnBnClickedBtnCurrentprice();
	afx_msg void OnBnClickedBtnLogin();
	afx_msg void OnBnClickedBtnCon();
	afx_msg void OnBnClickedBtnCurrentprice2();
};
