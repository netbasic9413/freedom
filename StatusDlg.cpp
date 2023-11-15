// StatusDlg.cpp : implementation file
//

#include "stdafx.h"
#include "KhOpenApiTest.h"
#include "StatusDlg.h"
#include "afxdialogex.h"


// CStatusDlg dialog

IMPLEMENT_DYNAMIC(CStatusDlg, CDialogEx)

CStatusDlg::CStatusDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_STATUS_DLG, pParent)
{
	m_pParent = pParent;
}

CStatusDlg::~CStatusDlg()
{
}

void CStatusDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_STATUS, m_ListStatus);
}


BEGIN_MESSAGE_MAP(CStatusDlg, CDialogEx)
	
	ON_WM_CLOSE()
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CStatusDlg message handlers


void CStatusDlg::OnOK()
{

	//DestroyWindow();
	CDialogEx::OnOK();
}


void CStatusDlg::OnCancel()
{

	//DestroyWindow();
	CDialogEx::OnCancel();
}


void CStatusDlg::PostNcDestroy()
{
	//::SendMessage(AfxGetMainWnd()->m_hWnd, UM_DELETE_DLG, 0, 6);

	//delete this;
	CDialogEx::PostNcDestroy();
}


BOOL CStatusDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}






void CStatusDlg::OnClose()
{
	m_pParent->SendMessage(UM_SCRENN_CLOSE, 6U, 0L);

	CDialogEx::OnClose();
}
