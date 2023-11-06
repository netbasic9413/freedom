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

	// 2개이사의 서비스를 조회 시 m_mapScreen에 화면을 등록하기 전에 
	// 데이터 응답이 먼저 와서 처리가 불가능 하여 여기서 조회 처리 함.
	pCurrentPriceDlg->SendSearch();		// 조회 처리
}



BOOL CMainDlg::GetNextScreenNum(int nScreenType)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
		AfxMessageBox("더 이상 화면을 열수 없습니다.다른 화면을 닫고 실행 해 주세요~!");
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

	// 아래 함수를 호출하지 않으면 이후 조건명리스트를 불러올수가 없으니 조건 검색을 할 경우
	// 무조건 이 함수를 처음에 불러와야 한다.
	// 조건검색을 시작하려면 한번은 꼭 호출해야한다.
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