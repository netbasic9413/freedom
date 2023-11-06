// MainDlg.cpp : implementation file
//

#include "stdafx.h"
#include "KhOpenApiTest.h"
#include "MainDlg.h"
#include "CurrentPriceDlg.h"
#include "afxdialogex.h"
#include "RealAddDlg.h"
#include "RateDlg.h"

// CMainDlg dialog

IMPLEMENT_DYNAMIC(CMainDlg, CDialogEx)

CMainDlg::CMainDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMainDlg::IDD, pParent)
{

}

CMainDlg::~CMainDlg()
{
}

void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_KHOPENAPICTRL1, theApp.m_khOpenApi);
	//DDX_Control(pDX, IDC_KHOPENAPICTRL1, m_ctrlOpenAPI);
}


BEGIN_MESSAGE_MAP(CMainDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_CURRENTPRICE, &CMainDlg::OnBnClickedBtnCurrentprice)
	ON_BN_CLICKED(IDC_BTN_LOGIN, &CMainDlg::OnBnClickedBtnLogin)
	ON_BN_CLICKED(IDC_BTN_CON, &CMainDlg::OnBnClickedBtnCon)
	ON_BN_CLICKED(IDC_BTN_CURRENTPRICE2, &CMainDlg::OnBnClickedBtnCurrentprice2)
END_MESSAGE_MAP()


// CMainDlg message handlers


void CMainDlg::OnBnClickedBtnCurrentprice()
{
	if (!GetNextScreenNum(0))
	{
		return;
	}

	CCurrentPriceDlg *pCurrentPriceDlg = new CCurrentPriceDlg(this);
	pCurrentPriceDlg->m_strScrNo.Format("%04d", m_nScrN0);
	pCurrentPriceDlg->Create(IDD_CURRENTPRICE_DLG);

	m_mapScreen.SetAt(pCurrentPriceDlg->m_strScrNo, pCurrentPriceDlg);

	// 2���̻��� ���񽺸� ��ȸ �� m_mapScreen�� ȭ���� ����ϱ� ���� 
	// ������ ������ ���� �ͼ� ó���� �Ұ��� �Ͽ� ���⼭ ��ȸ ó�� ��.
	pCurrentPriceDlg->SendSearch();		// ��ȸ ó��
}



BOOL CMainDlg::GetNextScreenNum(int nScreenType)
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	static int nRepeat = 0;
	m_nScrN0++;
	if (m_nScrN0 > 9999)
	{
		nRepeat++;
		m_nScrN0 = 1;
	}

	if (nRepeat > 1)
	{
		nRepeat = 0;
		AfxMessageBox("�� �̻� ȭ���� ���� �����ϴ�.�ٸ� ȭ���� �ݰ� ���� �� �ּ���~!");
		return FALSE;
	}

	CString strKey, strTemp;
	strKey.Format("%04d", m_nScrN0);
	if (m_mapScreenNum.Lookup(strKey, strTemp))
	{
		return GetNextScreenNum(nScreenType);
	}

	nRepeat = 0;
	strTemp.Format("%d", nScreenType);
	m_mapScreenNum.SetAt(strKey, strTemp);
	return TRUE;
}



void CMainDlg::OnBnClickedBtnLogin()
{
	theApp.m_khOpenApi.CommConnect();
}


void CMainDlg::OnBnClickedBtnCon()
{
	if (!GetNextScreenNum(3))
	{
		return;
	}

	// �Ʒ� �Լ��� ȣ������ ������ ���� ���Ǹ���Ʈ�� �ҷ��ü��� ������ ���� �˻��� �� ���
	// ������ �� �Լ��� ó���� �ҷ��;� �Ѵ�.
	// ���ǰ˻��� �����Ϸ��� �ѹ��� �� ȣ���ؾ��Ѵ�.
	m_nRet = theApp.m_khOpenApi.GetConditionLoad();

	if (m_nRet > 0)
	{
		CRealAddDlg* pRealAddDlg = new CRealAddDlg(this);
		pRealAddDlg->m_strScrNo.Format(_T("%04d"), m_nScrN0);
		pRealAddDlg->Create(IDD_CON_SET);

		m_mapScreen.SetAt(pRealAddDlg->m_strScrNo, pRealAddDlg);
	}
}


void CMainDlg::OnBnClickedBtnCurrentprice2()
{
	CString strTemp;
	((CEdit*)GetDlgItem(IDC_EDT_JONGCODE2))->GetWindowText(strTemp);
	if (strTemp.GetLength() != 6)
		return;

	CString strRe = theApp.m_khOpenApi.GetMasterStockState(strTemp);
	AfxMessageBox(strRe);

}