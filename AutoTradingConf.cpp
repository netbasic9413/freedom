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
	DDX_Control(pDX, IDC_CHECK_AUTO_EXE, m_checkAutoExe);
	DDX_Control(pDX, IDC_CHECK_BUY_MACRO, m_checkBuyMacro);
	DDX_Control(pDX, IDC_TP_START_BUY_MACRO, m_dtpickerBuyMacroStart);
	DDX_Control(pDX, IDC_TP_END_BUY_MACRO, m_dtpickerBuyMacroEnd);
	//DDX_Control(pDX, IDC_TP_START_TIME, m_dtpickerAutoTradingStart);
	//DDX_Control(pDX, IDC_TP_END_TIME, m_dtpickerAutoTradingEnd);
	DDX_Control(pDX, IDC_COMBO_BUY_MACRO, m_comboBuyMacro);
	DDX_Control(pDX, IDC_CHECK_SEL_MACRO, m_checkSelMacro);
	DDX_Control(pDX, IDC_CHECK_EXE_OWN, m_checkExeOwnEvent);
	DDX_Control(pDX, IDC_TP_AT_ONCE_TIME, m_dtpickerMinTime);
	DDX_Control(pDX, IDC_CHECK_PROFIT_RATIO, m_checkAllSelProfitRatio);
	DDX_Control(pDX, IDC_CHECK_LOSS_RATIO, m_checkAllSelLossRatio);
	DDX_Control(pDX, IDC_CHECK_PROFIT_AMOUNT, m_checkAllSellProfitAmount);
	DDX_Control(pDX, IDC_CHECK_LOSS_AMOUNT, m_checkAllSellLossAmount);
	DDX_Control(pDX, IDC_EDIT_TRADING_STRATEGY, m_editTradingStrategy);
	DDX_Control(pDX, IDC_CHECK_EVENT_PROFIT, m_checkEventProfit);
	DDX_Control(pDX, IDC_CHECK_EVENT_LOSS_RATIO, m_checkEventLoss);
	//DDX_Control(pDX, IDC_CHECK_MAX_PROFIT, m_checkMaxProfit);
	DDX_Control(pDX, IDC_CHECK_EVENT_MAX_LOSS_RATIO, m_checkEventMaxLoss);
	DDX_Control(pDX, IDC_CHECK_PROFIT_MIN_EVENT_COUNT, m_checkProfitMinEventCount);
	DDX_Control(pDX, IDC_CHECK_CANCEL_BUY_OUTSTANDING_ORDER, m_checkCancelBuyOutStandingOrder);
	DDX_Control(pDX, IDC_CHECK_EXE_PROFIT_LOSS, m_checkExeProfitLoss);
	DDX_Control(pDX, IDC_CHECK_FAST_BUY, m_checkFastBuy);
	DDX_Control(pDX, IDC_CHECK_EVENT_MAX_PROFIT_RATIO, m_checkEventMaxProfit);
	DDX_Control(pDX, IDC_CHECK_AT_ONCE_SEL_TIME, m_checkAtOnceSelTime);
}


BEGIN_MESSAGE_MAP(CAutoTradingConf, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAutoTradingConf::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BTN_SAVE_STRATEGY, &CAutoTradingConf::OnBnClickedBtnSaveStrategy)
	ON_BN_CLICKED(IDC_BTN_OPEN_STRATEGY, &CAutoTradingConf::OnBnClickedBtnOpenStrategy)
	ON_BN_CLICKED(IDC_CHECK_AUTO_EXE, &CAutoTradingConf::OnBnClickedCheckAutoExe)
	ON_BN_CLICKED(IDC_CHECK_BUY_MACRO, &CAutoTradingConf::OnBnClickedCheckBuyMacro)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_TP_START_BUY_MACRO, &CAutoTradingConf::OnDtnDatetimechangeTpStartBuyMacro)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_TP_END_BUY_MACRO, &CAutoTradingConf::OnDtnDatetimechangeTpEndBuyMacro)
	//ON_NOTIFY(DTN_DATETIMECHANGE, IDC_TP_START_TIME, &CAutoTradingConf::OnDtnDatetimechangeTpStartTime)
	//ON_NOTIFY(DTN_DATETIMECHANGE, IDC_TP_END_TIME, &CAutoTradingConf::OnDtnDatetimechangeTpEndTime)
	ON_EN_CHANGE(IDC_EDIT_TOTAL_POSSIBLE_BUY_AMOUNT, &CAutoTradingConf::OnEnChangeEditTotalPossibleBuyAmount)
	ON_CBN_SELCHANGE(IDC_COMBO_BUY_MACRO, &CAutoTradingConf::OnCbnSelchangeComboBuyMacro)
	ON_BN_CLICKED(IDC_CHECK_SEL_MACRO, &CAutoTradingConf::OnBnClickedCheckSelMacro)
	ON_BN_CLICKED(IDC_CHECK_EXE_OWN, &CAutoTradingConf::OnBnClickedCheckExeOwn)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_TP_AT_ONCE_TIME, &CAutoTradingConf::OnDtnDatetimechangeTpAtOnceTime)
	ON_BN_CLICKED(IDC_CHECK_PROFIT_RATIO, &CAutoTradingConf::OnBnClickedCheckProfitRatio)
	ON_BN_CLICKED(IDC_CHECK_LOSS_RATIO, &CAutoTradingConf::OnBnClickedCheckLossRatio)
	ON_BN_CLICKED(IDC_CHECK_PROFIT_AMOUNT, &CAutoTradingConf::OnBnClickedCheckProfitAmount)
	ON_BN_CLICKED(IDC_CHECK8, &CAutoTradingConf::OnBnClickedCheck8)
	ON_BN_CLICKED(IDC_CHECK_LOSS_AMOUNT, &CAutoTradingConf::OnBnClickedCheckLossAmount)
	ON_EN_CHANGE(IDC_EDIT_TRADING_STRATEGY, &CAutoTradingConf::OnEnChangeEditTradingStrategy)
	ON_BN_CLICKED(IDC_CHECK_EVENT_PROFIT, &CAutoTradingConf::OnBnClickedCheckEventProfit)
	ON_BN_CLICKED(IDC_CHECK_EVENT_LOSS_RATIO, &CAutoTradingConf::OnBnClickedCheckEventLossRatio)
	ON_BN_CLICKED(IDC_CHECK_EVENT_MAX_LOSS_RATIO, &CAutoTradingConf::OnBnClickedCheckEventMaxLossRatio)
	ON_BN_CLICKED(IDC_CHECK_PROFIT_MIN_EVENT_COUNT, &CAutoTradingConf::OnBnClickedCheckProfitMinEventCount)
	ON_EN_CHANGE(IDC_EDIT_PROFIT_MIN_EVENT_COUNT, &CAutoTradingConf::OnEnChangeEditProfitMinEventCount)
	ON_BN_CLICKED(IDC_CHECK_CANCEL_BUY_OUTSTANDING_ORDER, &CAutoTradingConf::OnBnClickedCheckCancelBuyOutstandingOrder)
	ON_BN_CLICKED(IDC_CHECK_EXE_PROFIT_LOSS, &CAutoTradingConf::OnBnClickedCheckExeProfitLoss)
	ON_BN_CLICKED(IDC_CHECK_FAST_BUY, &CAutoTradingConf::OnBnClickedCheckFastBuy)
	ON_BN_CLICKED(IDC_CHECK_EVENT_MAX_PROFIT_RATIO, &CAutoTradingConf::OnBnClickedCheckEventMaxProfitRatio)
	ON_BN_CLICKED(IDC_CHECK_AT_ONCE_SEL_TIME, &CAutoTradingConf::OnBnClickedCheckAtOnceSelTime)
END_MESSAGE_MAP()


// CAutoTradingConf message handlers


void CAutoTradingConf::OnBnClickedOk()
{
	//CString strFileName = theApp.m_sAppPath + "/data/jongcodedata.ini";
	//::WritePrivateProfileString("AUTO_TRADING_CONF", "TRADING_STRATEGY", m_strJongCode, strFileName);



	CDialogEx::OnOK();
}




void CAutoTradingConf::OnBnClickedBtnSaveStrategy()
{
	CString strTradingStrategy;
	((CEdit*)GetDlgItem(IDC_EDIT_TRADING_STRATEGY))->GetWindowText(strTradingStrategy);
	if (strTradingStrategy.GetLength() <= 0)
	{
		AfxMessageBox("저장할 매매전략 명을 입력 해 주세요.");
		return;
	}

	CString strFileName = theApp.m_sAppPath + "/data/"+ strTradingStrategy + ".ini";

	//시작시자동매매_자동실행
	int nGetChk = m_checkAutoExe.GetCheck();
	CString str;
	str.Format(_T("%d"), nGetChk);
	::WritePrivateProfileString("AUTO_TRADING_CONF", "check_exe_auto_trading", (LPCSTR)str, strFileName);
	
	//시작시자동매매_운영시간_시작
	((CEdit*)GetDlgItem(IDC_EDIT_AUTOTRADING_RUNTIME_START))->GetWindowText(str);
	if (str.GetLength() <= 0)
	{
		AfxMessageBox("시작시 자동매매의 운영시간을 입력 해 주세요.");
		return;
	}
	::WritePrivateProfileString("AUTO_TRADING_CONF", "autotrading_runtime_start", (LPCSTR)str, strFileName);


	//시작시자동매매_운영시간_끝
	((CEdit*)GetDlgItem(IDC_EDIT_AUTOTRADING_RUNTIME_END))->GetWindowText(str);
	if (str.GetLength() <= 0)
	{
		AfxMessageBox("시작시 자동매매의 운영시간을 입력 해 주세요.");
		return;
	}
	::WritePrivateProfileString("AUTO_TRADING_CONF", "autotrading_runtime_end", (LPCSTR)str, strFileName);


	//자동매수조건설정_총매수가능금액
	((CEdit*)GetDlgItem(IDC_EDIT_TOTAL_POSSIBLE_BUY_AMOUNT))->GetWindowText(str);
	if (str.GetLength() <= 0)
	{
		AfxMessageBox("총 매수가능금액을 입력 해 주세요.");
		return;
	}
	::WritePrivateProfileString("AUTO_BUY_COND_CONF", "total_possible_buy_amount", (LPCSTR)str, strFileName);

	//자동매수조건설정_종목별매수금액
	((CEdit*)GetDlgItem(IDC_EDIT_TOTAL_EVENT_BUY_AMOUNT))->GetWindowText(str);
	if (str.GetLength() <= 0)
	{
		AfxMessageBox("종목별 매수금액 입력 해 주세요.");
		return;
	}
	::WritePrivateProfileString("AUTO_BUY_COND_CONF", "total_event_buy_amount", (LPCSTR)str, strFileName);

	//자동매수조건설정_최대매수종목수
	((CEdit*)GetDlgItem(IDC_EDIT_MAX_BUY_EVENT_COUNT))->GetWindowText(str);
	if (str.GetLength() <= 0)
	{
		AfxMessageBox("최대 매수종목수를 입력 해 주세요.");
		return;
	}
	::WritePrivateProfileString("AUTO_BUY_COND_CONF", "max_buy_event_count", (LPCSTR)str, strFileName);

	//자동매수조건설정_주당 매수최고가
	((CEdit*)GetDlgItem(IDC_EDIT_BUY_HIGHEST_PRICE_PER_ONE))->GetWindowText(str);
	if (str.GetLength() <= 0)
	{
		AfxMessageBox("주당 매수최고가를 입력 해 주세요.");
		return;
	}
	::WritePrivateProfileString("AUTO_BUY_COND_CONF", "buy_highest_price_per_one", (LPCSTR)str, strFileName);

	//자동매수조건설정_주당 매수최저가
	((CEdit*)GetDlgItem(IDC_EDIT_BUY_LOWEST_PRICE_PER_ONE))->GetWindowText(str);
	if (str.GetLength() <= 0)
	{
		AfxMessageBox("주당 매수최저가를 입력 해 주세요.");
		return;
	}
	::WritePrivateProfileString("AUTO_BUY_COND_CONF", "buy_lowest_price_per_one", (LPCSTR)str, strFileName);

	//자동매수조건설정_종목 최소거래량
	((CEdit*)GetDlgItem(IDC_EDIT_EVENT_SMALLEST_VOLUME))->GetWindowText(str);
	if (str.GetLength() <= 0)
	{
		AfxMessageBox("종목 최소거래량을 입력 해 주세요.");
		return;
	}
	::WritePrivateProfileString("AUTO_BUY_COND_CONF", "event_smallest_volume", (LPCSTR)str, strFileName);


	//자동매수조건설정_매수조건식(체크)
	int nGetChkBuyMacro = m_checkBuyMacro.GetCheck();
	str.Format(_T("%d"), nGetChkBuyMacro);
	::WritePrivateProfileString("AUTO_BUY_COND_CONF", "check_buy_macro", (LPCSTR)str, strFileName);


	//자동매수조건설정_매수조건식(시작시간)
	((CEdit*)GetDlgItem(IDC_EDIT_BUY_MACRO_TIME_START))->GetWindowText(str);
	if (str.GetLength() <= 0)
	{
		AfxMessageBox("매수조건식 시작 시간을 입력 해 주세요.");
		return;
	}
	::WritePrivateProfileString("AUTO_BUY_COND_CONF", "buy_macro_time_start", (LPCSTR)str, strFileName);


	//자동매수조건설정_매수조건식(끝시간)
	((CEdit*)GetDlgItem(IDC_EDIT_BUY_MACRO_TIME_END))->GetWindowText(str);
	if (str.GetLength() <= 0)
	{
		AfxMessageBox("매수조건식 끝 시간을 입력 해 주세요.");
		return;
	}
	::WritePrivateProfileString("AUTO_BUY_COND_CONF", "buy_macro_time_end", (LPCSTR)str, strFileName);



	AfxMessageBox("저장을 완료하였습니다.");
	
}	


	
	


void CAutoTradingConf::OnBnClickedBtnOpenStrategy()
{
	// TODO: Add your control notification handler code here
}


void CAutoTradingConf::OnBnClickedCheckAutoExe()
{
	// TODO: Add your control notification handler code here
}


void CAutoTradingConf::OnBnClickedCheckBuyMacro()
{
	// TODO: Add your control notification handler code here
}


void CAutoTradingConf::OnDtnDatetimechangeTpStartBuyMacro(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void CAutoTradingConf::OnDtnDatetimechangeTpEndBuyMacro(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void CAutoTradingConf::OnDtnDatetimechangeTpStartTime(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void CAutoTradingConf::OnDtnDatetimechangeTpEndTime(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void CAutoTradingConf::OnEnChangeEditTotalPossibleBuyAmount()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CAutoTradingConf::OnCbnSelchangeComboBuyMacro()
{
	// TODO: Add your control notification handler code here
}


void CAutoTradingConf::OnBnClickedCheckSelMacro()
{
	// TODO: Add your control notification handler code here
}


void CAutoTradingConf::OnBnClickedCheckExeOwn()
{
	// TODO: Add your control notification handler code here
}


void CAutoTradingConf::OnDtnDatetimechangeTpAtOnceTime(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void CAutoTradingConf::OnBnClickedCheckProfitRatio()
{
	// TODO: Add your control notification handler code here
}


void CAutoTradingConf::OnBnClickedCheckLossRatio()
{
	// TODO: Add your control notification handler code here
}


void CAutoTradingConf::OnBnClickedCheckProfitAmount()
{
	// TODO: Add your control notification handler code here
}


void CAutoTradingConf::OnBnClickedCheck8()
{
	// TODO: Add your control notification handler code here
}


void CAutoTradingConf::OnBnClickedCheckLossAmount()
{
	// TODO: Add your control notification handler code here
}


void CAutoTradingConf::OnEnChangeEditTradingStrategy()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CAutoTradingConf::OnBnClickedCheckEventProfit()
{
	// TODO: Add your control notification handler code here
}


void CAutoTradingConf::OnBnClickedCheckEventLossRatio()
{
	// TODO: Add your control notification handler code here
}



void CAutoTradingConf::OnBnClickedCheckEventMaxLossRatio()
{
	// TODO: Add your control notification handler code here
}


void CAutoTradingConf::OnBnClickedCheckProfitMinEventCount()
{
	// TODO: Add your control notification handler code here
}


void CAutoTradingConf::OnEnChangeEditProfitMinEventCount()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CAutoTradingConf::OnBnClickedCheckCancelBuyOutstandingOrder()
{
	// TODO: Add your control notification handler code here
}


void CAutoTradingConf::OnBnClickedCheckExeProfitLoss()
{
	// TODO: Add your control notification handler code here
}


void CAutoTradingConf::OnBnClickedCheckFastBuy()
{
	// TODO: Add your control notification handler code here
}



void CAutoTradingConf::OnBnClickedCheckEventMaxProfitRatio()
{
	// TODO: Add your control notification handler code here
}


void CAutoTradingConf::OnBnClickedCheckAtOnceSelTime()
{
	// TODO: Add your control notification handler code here
}
