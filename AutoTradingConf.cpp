// AutoTradingConf.cpp : implementation file
//

//#include "pch.h"
#include "stdafx.h"
#include "KhOpenApiTest.h"
#include "AutoTradingConf.h"
#include "afxdialogex.h"


// CAutoTradingConf dialog

IMPLEMENT_DYNAMIC(CAutoTradingConf, CDialogEx)

CAutoTradingConf::CAutoTradingConf(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_AUTO_CONF_DLG, pParent)
{

}

CAutoTradingConf::~CAutoTradingConf()
{
}

void CAutoTradingConf::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAutoTradingConf, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAutoTradingConf::OnBnClickedOk)
END_MESSAGE_MAP()


// CAutoTradingConf message handlers


void CAutoTradingConf::OnBnClickedOk()
{
	//CString strFileName = theApp.m_sAppPath + "/data/jongcodedata.ini";
	//::WritePrivateProfileString("AUTO_TRADING_CONF", "TRADING_STRATEGY", m_strJongCode, strFileName);



	CDialogEx::OnOK();
}
