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
	
END_MESSAGE_MAP()


// CStatusDlg message handlers


void CStatusDlg::OnOK()
{

	DestroyWindow();
	//CDialogEx::OnOK();
}


void CStatusDlg::OnCancel()
{

	DestroyWindow();
	//CDialogEx::OnCancel();
}


void CStatusDlg::PostNcDestroy()
{
	
	delete this;
	CDialogEx::PostNcDestroy();
}


BOOL CStatusDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
