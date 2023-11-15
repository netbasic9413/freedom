// AutoTradingConf.cpp : implementation file
//

//#include "pch.h"
#include "stdafx.h"
#include "KhOpenApiTest.h"
#include "AutoTradingConf.h"
#include "afxdialogex.h"
#include "shlwapi.h""


// CAutoTradingConf dialog

IMPLEMENT_DYNAMIC(CAutoTradingConf, CDialogEx)

CAutoTradingConf::CAutoTradingConf(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_AUTO_CONF_DLG, pParent)
{
	m_pParent = pParent;
}

CAutoTradingConf::~CAutoTradingConf()
{
}

void CAutoTradingConf::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK_AUTO_EXE, m_checkAutoExe);
	DDX_Control(pDX, IDC_CHECK_BUY_MACRO, m_checkBuyMacro);
	//DDX_Control(pDX, IDC_TP_START_BUY_MACRO, m_dtpickerBuyMacroStart);
	//DDX_Control(pDX, IDC_TP_END_BUY_MACRO, m_dtpickerBuyMacroEnd);
	//DDX_Control(pDX, IDC_TP_START_TIME, m_dtpickerAutoTradingStart);
	//DDX_Control(pDX, IDC_TP_END_TIME, m_dtpickerAutoTradingEnd);
	DDX_Control(pDX, IDC_COMBO_BUY_MACRO, m_comboBuyMacro);
	DDX_Control(pDX, IDC_CHECK_SEL_MACRO, m_checkSelMacro);
	DDX_Control(pDX, IDC_CHECK_EXE_OWN, m_checkExeOwnEvent);
	//DDX_Control(pDX, IDC_TP_AT_ONCE_TIME, m_dtpickerMinTime);
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
	ON_BN_CLICKED(IDC_BTN_LOAD_BUYMACRO, &CAutoTradingConf::OnBnClickedBtnLoadBuymacro)
	//ON_BN_CLICKED(IDCANCEL, &CAutoTradingConf::OnBnClickedCancel)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CAutoTradingConf message handlers


void CAutoTradingConf::OnBnClickedOk()
{
	//CString strFileName = theApp.m_sAppPath + "/data/jongcodedata.ini";
	//::WritePrivateProfileString("AUTO_TRADING_CONF", "TRADING_STRATEGY", m_strJongCode, strFileName);

	TCHAR szItem[300];
	int nSize = sizeof(szItem);
	memset(szItem, 0, nSize);

	CString strExeMacro = theApp.m_sAppPath + "/data/exe_macro.ini";
	

	//[CONF_FILE_PATH]
	if (m_strExeMacro.GetLength() <= 0)
	{
		AfxMessageBox("�ڵ��Ÿ� ������ ���� ���� �� �ּ���.");
		return;
	}
	::WritePrivateProfileString("EXE_MACRO", "file_path", (LPCSTR)m_strExeMacro, strExeMacro);


	


	//exe_macro.ini [EXE_MACRO]
	::GetPrivateProfileString("EXE_MACRO", "file_path", "0", szItem, sizeof(szItem), strExeMacro);
	CString strGetExeMacroPath = szItem;



	//��������
	//�������� (check)
	memset(szItem, 0, nSize);
	::GetPrivateProfileString("EVENT_CONF", "check_event_profit", "0", szItem, nSize, strGetExeMacroPath);
	theApp.m_nEventProfitChk = atoi(szItem);
	//����������
	memset(szItem, 0, nSize);
	::GetPrivateProfileString("EVENT_CONF", "event_profit", "0", szItem, nSize, strGetExeMacroPath);
	theApp.m_nEventProfitRate = atoi(szItem);


	//�ִ����� (check)
	memset(szItem, 0, nSize);
	::GetPrivateProfileString("EVENT_CONF", "check_event_maxprofit", "0", szItem, nSize, strGetExeMacroPath);
	theApp.m_nEventProtfitMaxChk = atoi(szItem);
	//�ִ����� (%)
	memset(szItem, 0, nSize);
	::GetPrivateProfileString("EVENT_CONF", "event_maxprofit", "0", szItem, nSize, strGetExeMacroPath);
	theApp.m_nEventProtfitMaxRate = atoi(szItem);

	//������� (check)
	memset(szItem, 0, nSize);
	::GetPrivateProfileString("EVENT_CONF", "check_event_loss", "0", szItem, nSize, strGetExeMacroPath);
	theApp.m_nEventLossChk = atoi(szItem);

	//������� 
	memset(szItem, 0, nSize);
	::GetPrivateProfileString("EVENT_CONF", "event_loss", "0", szItem, nSize, strGetExeMacroPath);
	theApp.m_nEventLossRate = atoi(szItem);

	//�����ִ���� (check)
	memset(szItem, 0, nSize);
	::GetPrivateProfileString("EVENT_CONF", "check_event_maxloss", "0", szItem, nSize, strGetExeMacroPath);
	theApp.m_nEventLossMaxChk = atoi(szItem);

	//�����ִ����
	memset(szItem, 0, nSize);
	::GetPrivateProfileString("EVENT_CONF", "event_maxloss", "0", szItem, nSize, strGetExeMacroPath);
	theApp.m_nEventLossMaxRate = atoi(szItem);



	//DestroyWindow();
	//CDialogEx::OnOK();
}




void CAutoTradingConf::OnBnClickedBtnSaveStrategy()
{
	CString strTradingStrategy;
	((CEdit*)GetDlgItem(IDC_EDIT_TRADING_STRATEGY))->GetWindowText(strTradingStrategy);
	if (strTradingStrategy.GetLength() <= 0)
	{
		AfxMessageBox("������ �Ÿ����� ���� �Է� �� �ּ���.");
		return;
	}

	//CString strExeMacro = theApp.m_sAppPath + "/data/exe_macro.ini";
	CString strFileName = theApp.m_sAppPath + "/data/" + strTradingStrategy + ".ini";

	m_strExeMacro = strFileName;

	//[CONF_FILE_PATH]
	//::WritePrivateProfileString("CONF_FILE_PATH", "file_path", (LPCSTR)strFileName, strExeMacro);

	//���۽��ڵ��Ÿ�_�ڵ�����
	int nGetChk = m_checkAutoExe.GetCheck();
	CString str;
	str.Format(_T("%d"), nGetChk);
	::WritePrivateProfileString("AUTO_TRADING_CONF", "check_exe_auto_trading", (LPCSTR)str, strFileName);

	//���۽��ڵ��Ÿ�_��ð�_����
	((CEdit*)GetDlgItem(IDC_EDIT_AUTOTRADING_RUNTIME_START))->GetWindowText(str);
	if (str.GetLength() <= 0)
	{
		AfxMessageBox("���۽� �ڵ��Ÿ��� ��ð��� �Է� �� �ּ���.");
		return;
	}
	::WritePrivateProfileString("AUTO_TRADING_CONF", "autotrading_runtime_start", (LPCSTR)str, strFileName);


	//���۽��ڵ��Ÿ�_��ð�_��
	((CEdit*)GetDlgItem(IDC_EDIT_AUTOTRADING_RUNTIME_END))->GetWindowText(str);
	if (str.GetLength() <= 0)
	{
		AfxMessageBox("���۽� �ڵ��Ÿ��� ��ð��� �Է� �� �ּ���.");
		return;
	}
	::WritePrivateProfileString("AUTO_TRADING_CONF", "autotrading_runtime_end", (LPCSTR)str, strFileName);


	//�ڵ��ż����Ǽ���_�Ѹż����ɱݾ�
	((CEdit*)GetDlgItem(IDC_EDIT_TOTAL_POSSIBLE_BUY_AMOUNT))->GetWindowText(str);
	if (str.GetLength() <= 0)
	{
		AfxMessageBox("�� �ż����ɱݾ��� �Է� �� �ּ���.");
		return;
	}
	::WritePrivateProfileString("AUTO_BUY_COND_CONF", "total_possible_buy_amount", (LPCSTR)str, strFileName);

	//�ڵ��ż����Ǽ���_���񺰸ż��ݾ�
	((CEdit*)GetDlgItem(IDC_EDIT_TOTAL_EVENT_BUY_AMOUNT))->GetWindowText(str);
	if (str.GetLength() <= 0)
	{
		AfxMessageBox("���� �ż��ݾ� �Է� �� �ּ���.");
		return;
	}
	::WritePrivateProfileString("AUTO_BUY_COND_CONF", "total_event_buy_amount", (LPCSTR)str, strFileName);

	//�ڵ��ż����Ǽ���_�ִ�ż������
	((CEdit*)GetDlgItem(IDC_EDIT_MAX_BUY_EVENT_COUNT))->GetWindowText(str);
	if (str.GetLength() <= 0)
	{
		AfxMessageBox("�ִ� �ż�������� �Է� �� �ּ���.");
		return;
	}
	::WritePrivateProfileString("AUTO_BUY_COND_CONF", "max_buy_event_count", (LPCSTR)str, strFileName);

	//�ڵ��ż����Ǽ���_�ִ� �ż��ְ�
	((CEdit*)GetDlgItem(IDC_EDIT_BUY_HIGHEST_PRICE_PER_ONE))->GetWindowText(str);
	if (str.GetLength() <= 0)
	{
		AfxMessageBox("�ִ� �ż��ְ��� �Է� �� �ּ���.");
		return;
	}
	::WritePrivateProfileString("AUTO_BUY_COND_CONF", "buy_highest_price_per_one", (LPCSTR)str, strFileName);

	//�ڵ��ż����Ǽ���_�ִ� �ż�������
	((CEdit*)GetDlgItem(IDC_EDIT_BUY_LOWEST_PRICE_PER_ONE))->GetWindowText(str);
	if (str.GetLength() <= 0)
	{
		AfxMessageBox("�ִ� �ż��������� �Է� �� �ּ���.");
		return;
	}
	::WritePrivateProfileString("AUTO_BUY_COND_CONF", "buy_lowest_price_per_one", (LPCSTR)str, strFileName);

	//�ڵ��ż����Ǽ���_���� �ּҰŷ���
	((CEdit*)GetDlgItem(IDC_EDIT_EVENT_SMALLEST_VOLUME))->GetWindowText(str);
	if (str.GetLength() <= 0)
	{
		AfxMessageBox("���� �ּҰŷ����� �Է� �� �ּ���.");
		return;
	}
	::WritePrivateProfileString("AUTO_BUY_COND_CONF", "event_smallest_volume", (LPCSTR)str, strFileName);


	//�ڵ��ż����Ǽ���_�ż����ǽ�(üũ)
	int nGetChkBuyMacro = m_checkBuyMacro.GetCheck();
	str.Format(_T("%d"), nGetChkBuyMacro);
	::WritePrivateProfileString("AUTO_BUY_COND_CONF", "check_buy_macro", (LPCSTR)str, strFileName);

	if (nGetChkBuyMacro)
	{
		//�ڵ��ż����Ǽ���_�ż����ǽ�(���۽ð�)
		((CEdit*)GetDlgItem(IDC_EDIT_BUY_MACRO_TIME_START))->GetWindowText(str);
		if (str.GetLength() <= 0)
		{
			AfxMessageBox("�ż����ǽ� ���� �ð��� �Է� �� �ּ���.");
			return;
		}
		::WritePrivateProfileString("AUTO_BUY_COND_CONF", "buy_macro_time_start", (LPCSTR)str, strFileName);


		//�ڵ��ż����Ǽ���_�ż����ǽ�(���ð�)
		((CEdit*)GetDlgItem(IDC_EDIT_BUY_MACRO_TIME_END))->GetWindowText(str);
		if (str.GetLength() <= 0)
		{
			AfxMessageBox("�ż����ǽ� �� �ð��� �Է� �� �ּ���.");
			return;
		}
		::WritePrivateProfileString("AUTO_BUY_COND_CONF", "buy_macro_time_end", (LPCSTR)str, strFileName);
	}

	//buy_macro combo
	CString strGet;
	int nGetCurSel = m_comboBuyMacro.GetCurSel();
	if (nGetCurSel == -1)
		return;
	m_comboBuyMacro.GetLBText(nGetCurSel, strGet);
	if (strGet.GetLength() <= 0)
	{
		AfxMessageBox("�ż����ǽ��� ���� �� �ּ���.");
		return;
	}
	::WritePrivateProfileString("AUTO_BUY_COND_CONF", "buy_macro_combo", (LPCSTR)strGet, strFileName);


	/*
	//�ڵ��ż����Ǽ���_�ŵ����ǽ�(üũ)
	int nGetChkSelMacro = m_checkSelMacro.GetCheck();
	str.Format(_T("%d"), nGetChkSelMacro);
	::WritePrivateProfileString("AUTO_BUY_COND_CONF", "check_sel_macro", (LPCSTR)str, strFileName);

	//�ڵ��ż����Ǽ���_�������� ������(üũ)
	int nGetChkExeOwnEvent = m_checkExeOwnEvent.GetCheck();
	str.Format(_T("%d"), nGetChkExeOwnEvent);
	::WritePrivateProfileString("AUTO_BUY_COND_CONF", "check_exe_ownevent", (LPCSTR)str, strFileName);


	//�ڵ��ż����Ǽ���_�������� ������ (�� ���� ��˻� �ð�)
	if (nGetChkExeOwnEvent)
	{
		((CEdit*)GetDlgItem(IDC_EDIT_MIN_TIME))->GetWindowText(str);
		if (str.GetLength() <= 0)
		{
			AfxMessageBox("�������� ��� ���� �ð��� �Է� �� �ּ���.");
			return;
		}
		::WritePrivateProfileString("AUTO_BUY_COND_CONF", "exe_ownevent_min_time", (LPCSTR)str, strFileName);
	}
	*/


	//�ڵ��ż����Ǽ���_�ð��ϰ�û�꼳��(üũ)
	int nGetChkAtOnceSelTime = m_checkAtOnceSelTime.GetCheck();
	str.Format(_T("%d"), nGetChkAtOnceSelTime);
	::WritePrivateProfileString("AUTO_BUY_COND_CONF", "check_atonce_selltime", (LPCSTR)str, strFileName);


	//�ڵ��ż����Ǽ���_�ð��ϰ�û�꼳��(�ð�)
	if (nGetChkAtOnceSelTime)
	{
		((CEdit*)GetDlgItem(IDC_EDIT_AT_ONCE_TIME))->GetWindowText(str);
		if (str.GetLength() <= 0)
		{
			AfxMessageBox("�ð��ϰ�û�꼳�� �ð��� �Է� �� �ּ���.");
			return;
		}
		::WritePrivateProfileString("AUTO_BUY_COND_CONF", "atonce_selltime", (LPCSTR)str, strFileName);
	}


	//��ü������
	//��üû����_������ IDC_CHECK_PROFIT_RATIO
	int nGetChkAllSelProfitRatio = m_checkAllSelProfitRatio.GetCheck();
	str.Format(_T("%d"), nGetChkAllSelProfitRatio);
	::WritePrivateProfileString("ALL_SEL_CONF", "check_allsell_profitratio", (LPCSTR)str, strFileName);

	if (nGetChkAllSelProfitRatio)
	{
		((CEdit*)GetDlgItem(IDC_EDIT_PROFIT_RATIO))->GetWindowText(str);
		if (str.GetLength() <= 0)
		{
			AfxMessageBox("�������� �Է� �� �ּ���.");
			return;
		}
		::WritePrivateProfileString("ALL_SEL_CONF", "allsell_profitratio", (LPCSTR)str, strFileName);
	}

	//��üû����_������ IDC_CHECK_LOSS_RATIO
	int nGetChkAllSelLossRatio = m_checkAllSelLossRatio.GetCheck();
	str.Format(_T("%d"), nGetChkAllSelLossRatio);
	::WritePrivateProfileString("ALL_SEL_CONF", "check_allsell_lossratio", (LPCSTR)str, strFileName);

	if (nGetChkAllSelLossRatio)
	{
		((CEdit*)GetDlgItem(IDC_EDIT_LOSS_RATIO))->GetWindowText(str);
		if (str.GetLength() <= 0)
		{
			AfxMessageBox("�������� �Է� �� �ּ���.");
			return;
		}
		::WritePrivateProfileString("ALL_SEL_CONF", "allsel_lossratio", (LPCSTR)str, strFileName);
	}

	//��üû����_�����ݾ�
	int nGetChkAllSellProfitAmount = m_checkAllSellProfitAmount.GetCheck();
	str.Format(_T("%d"), nGetChkAllSellProfitAmount);
	::WritePrivateProfileString("ALL_SEL_CONF", "check_allsell_profitamount", (LPCSTR)str, strFileName);

	if (nGetChkAllSellProfitAmount)
	{
		((CEdit*)GetDlgItem(IDC_EDIT_PROFIT_AMOUNT))->GetWindowText(str);
		if (str.GetLength() <= 0)
		{
			AfxMessageBox("�����ݾ��� �Է� �� �ּ���.");
			return;
		}
		::WritePrivateProfileString("ALL_SEL_CONF", "allsell_profitamount", (LPCSTR)str, strFileName);
	}


	////��üû����_�����ݾ�
	int nGetChkllSellLossAmount = m_checkAllSellLossAmount.GetCheck();
	str.Format(_T("%d"), nGetChkllSellLossAmount);
	::WritePrivateProfileString("ALL_SEL_CONF", "check_allsell_lossamount", (LPCSTR)str, strFileName);

	if (nGetChkAllSellProfitAmount)
	{
		((CEdit*)GetDlgItem(IDC_EDIT_LOSS_AMOUNT))->GetWindowText(str);
		if (str.GetLength() <= 0)
		{
			AfxMessageBox("�����ݾ��� �Է� �� �ּ���.");
			return;
		}
		::WritePrivateProfileString("ALL_SEL_CONF", "allsell_lossamount", (LPCSTR)str, strFileName);
	}



	//����������
	//����û����_��������
	int nGetChkEventProfit = m_checkEventProfit.GetCheck();
	str.Format(_T("%d"), nGetChkEventProfit);
	::WritePrivateProfileString("EVENT_CONF", "check_event_profit", (LPCSTR)str, strFileName);

	if (nGetChkEventProfit)
	{
		((CEdit*)GetDlgItem(IDC_EDIT_EVENT_PROFIT_RATIO))->GetWindowText(str);
		if (str.GetLength() <= 0)
		{
			AfxMessageBox("������������ �Է� �� �ּ���.");
			return;
		}
		::WritePrivateProfileString("EVENT_CONF", "event_profit", (LPCSTR)str, strFileName);
	}




	//����û����_�������
	int nGetChkEventLoss = m_checkEventLoss.GetCheck();
	str.Format(_T("%d"), nGetChkEventLoss);
	::WritePrivateProfileString("EVENT_CONF", "check_event_loss", (LPCSTR)str, strFileName);

	if (nGetChkEventLoss)
	{
		((CEdit*)GetDlgItem(IDC_EDIT_EVENT_LOSS_RATIO))->GetWindowText(str);
		if (str.GetLength() <= 0)
		{
			AfxMessageBox("����������� �Է� �� �ּ���.");
			return;
		}
		::WritePrivateProfileString("EVENT_CONF", "event_loss", (LPCSTR)str, strFileName);
	}


	
	//����û����_�ִ�����
	int nGetChkEventMaxProfit = m_checkEventMaxProfit.GetCheck();
	str.Format(_T("%d"), nGetChkEventMaxProfit);
	::WritePrivateProfileString("EVENT_CONF", "check_event_maxprofit", (LPCSTR)str, strFileName);

	if (nGetChkEventMaxProfit)
	{
		((CEdit*)GetDlgItem(IDC_EDIT_MAX_PROFIT_RATIO))->GetWindowText(str);
		if (str.GetLength() <= 0)
		{
			AfxMessageBox("����û������ �ִ��������� �Է� �� �ּ���.");
			return;
		}
		::WritePrivateProfileString("EVENT_CONF", "event_maxprofit", (LPCSTR)str, strFileName);
	}



	//����û����_�ִ����(��)
	int nGetChkEventMaxLoss = m_checkEventMaxLoss.GetCheck();
	str.Format(_T("%d"), nGetChkEventMaxLoss);
	::WritePrivateProfileString("EVENT_CONF", "check_event_maxloss", (LPCSTR)str, strFileName);

	if (nGetChkEventMaxLoss)
	{
		((CEdit*)GetDlgItem(IDC_EDIT_MAX_LOSS_RATIO))->GetWindowText(str);
		if (str.GetLength() <= 0)
		{
			AfxMessageBox("����û������ �ִ�������� �Է� �� �ּ���.");
			return;
		}
		::WritePrivateProfileString("EVENT_CONF", "event_maxloss", (LPCSTR)str, strFileName);
	}




	//���ͷ���� �ּ������ (üũ)
	//���ͷ���� �ּ������ 



	//��ü��ż��ֹ����(üũ)
	int nGetChkCancelBuyOutStandingOrder = m_checkCancelBuyOutStandingOrder.GetCheck();
	str.Format(_T("%d"), nGetChkCancelBuyOutStandingOrder);
	::WritePrivateProfileString("ETC_CONF", "check_cancel_buy_outstandingorder", (LPCSTR)str, strFileName);

	if (nGetChkCancelBuyOutStandingOrder)
	{
		((CEdit*)GetDlgItem(IDC_EDIT_CANCEL_BUY_OUTSTANDING_ORDER))->GetWindowText(str);
		if (str.GetLength() <= 0)
		{
			AfxMessageBox("��ü�� �ż��ֹ���ҿ� ���� �ʸ� �Է� �� �ּ���.");
			return;
		}
		::WritePrivateProfileString("ETC_CONF", "cancel_buy_outstandingorder_sec", (LPCSTR)str, strFileName);
	}



	//�ż����ǽ� ������ ����, ���� ����


	//���� �ż�(�����ż� ����)
	int nGetChkFastBuy = m_checkFastBuy.GetCheck();
	str.Format(_T("%d"), nGetChkFastBuy);
	::WritePrivateProfileString("ETC_CONF", "check_fastbuy", (LPCSTR)str, strFileName);

	


	AfxMessageBox("������ �Ϸ��Ͽ����ϴ�.");
	
}	


	
	


void CAutoTradingConf::OnBnClickedBtnOpenStrategy()
{
	CString strPathName;
	char szFilter[] = "config (*.ini, *.conf) | *.ini;*.conf | All Files(*.*)|*.*||";
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, szFilter);
	if (IDOK == dlg.DoModal()) {
		strPathName = dlg.GetPathName();
	}

	if (strPathName.GetLength() <= 0)
	{
		return;
	}

	TCHAR szTmp[200];
	memset(szTmp, 0, 200);
	CString strFileName = dlg.GetFileName();
	StrCpy(szTmp, strFileName);
	PathRemoveExtension(szTmp);
	char szItem[80];
	int nSize = sizeof(szItem);
	memset(szItem, 0, nSize);
	SetDlgItemText(IDC_EDIT_TRADING_STRATEGY, szTmp);


	//���۽� �ڵ��Ÿ�
	::GetPrivateProfileString("AUTO_TRADING_CONF", "check_exe_auto_trading", "0", szItem, nSize, strPathName);
	m_checkAutoExe.SetCheck(atoi(szItem));
	//start time
	memset(szItem, 0, nSize);
	::GetPrivateProfileString("AUTO_TRADING_CONF", "autotrading_runtime_start", "", szItem, nSize, strPathName);
	SetDlgItemText(IDC_EDIT_AUTOTRADING_RUNTIME_START, LPCTSTR(szItem));
	//end time
	memset(szItem, 0, nSize);
	::GetPrivateProfileString("AUTO_TRADING_CONF", "autotrading_runtime_end", "", szItem, nSize, strPathName);
	SetDlgItemText(IDC_EDIT_AUTOTRADING_RUNTIME_END, LPCTSTR(szItem));

	//�ڵ��ż� ���� ����
	//�� �ż����ɱݾ�
	memset(szItem, 0, nSize);
	::GetPrivateProfileString("AUTO_BUY_COND_CONF", "total_possible_buy_amount", "", szItem, nSize, strPathName);
	SetDlgItemText(IDC_EDIT_TOTAL_POSSIBLE_BUY_AMOUNT, LPCTSTR(szItem));
	//���� �ż��ݾ�
	memset(szItem, 0, nSize);
	::GetPrivateProfileString("AUTO_BUY_COND_CONF", "total_event_buy_amount", "", szItem, nSize, strPathName);
	SetDlgItemText(IDC_EDIT_TOTAL_EVENT_BUY_AMOUNT, LPCTSTR(szItem));
	//�ִ� �ż������
	memset(szItem, 0, nSize);
	::GetPrivateProfileString("AUTO_BUY_COND_CONF", "max_buy_event_count", "", szItem, nSize, strPathName);
	SetDlgItemText(IDC_EDIT_MAX_BUY_EVENT_COUNT, LPCTSTR(szItem));
	//�ִ� �ż� �ְ�
	memset(szItem, 0, nSize);
	::GetPrivateProfileString("AUTO_BUY_COND_CONF", "buy_highest_price_per_one", "", szItem, nSize, strPathName);
	SetDlgItemText(IDC_EDIT_BUY_HIGHEST_PRICE_PER_ONE, LPCTSTR(szItem));
	//�ִ� �ż� ������
	memset(szItem, 0, nSize);
	::GetPrivateProfileString("AUTO_BUY_COND_CONF", "buy_lowest_price_per_one", "", szItem, nSize, strPathName);
	SetDlgItemText(IDC_EDIT_BUY_LOWEST_PRICE_PER_ONE, LPCTSTR(szItem));
	//���� �ּ� �ŷ���
	memset(szItem, 0, nSize);
	::GetPrivateProfileString("AUTO_BUY_COND_CONF", "event_smallest_volume", "", szItem, nSize, strPathName);
	SetDlgItemText(IDC_EDIT_EVENT_SMALLEST_VOLUME, LPCTSTR(szItem));
	//�ż����ǽ� (check)
	memset(szItem, 0, nSize);
	::GetPrivateProfileString("AUTO_BUY_COND_CONF", "check_buy_macro", "0", szItem, nSize, strPathName);
	m_checkBuyMacro.SetCheck(atoi(szItem));
	//�ż����ǽ� (�ð�)
	//start
	memset(szItem, 0, nSize);
	::GetPrivateProfileString("AUTO_BUY_COND_CONF", "buy_macro_time_start", "", szItem, nSize, strPathName);
	SetDlgItemText(IDC_EDIT_BUY_MACRO_TIME_START, LPCTSTR(szItem));
	//end
	memset(szItem, 0, nSize);
	::GetPrivateProfileString("AUTO_BUY_COND_CONF", "buy_macro_time_end", "", szItem, nSize, strPathName);
	SetDlgItemText(IDC_EDIT_BUY_MACRO_TIME_END, LPCTSTR(szItem));

	//m_comboBuyMacro
	memset(szItem, 0, nSize);
	::GetPrivateProfileString("AUTO_BUY_COND_CONF", "buy_macro_combo", "", szItem, nSize, strPathName);
	m_comboBuyMacro.AddString(szItem);
	m_comboBuyMacro.SetCurSel(0);
	//SetDlgItemText(IDC_EDIT_BUY_MACRO_TIME_END, LPCTSTR(szItem));

	/*
	//�ŵ����ǽ� (check)
	memset(szItem, 0, nSize);
	::GetPrivateProfileString("AUTO_BUY_COND_CONF", "check_sel_macro", "0", szItem, nSize, strPathName);
	m_checkAutoExe.SetCheck(atoi(szItem));

	//�������� ��� ���� 
	memset(szItem, 0, nSize);
	::GetPrivateProfileString("AUTO_BUY_COND_CONF", "check_exe_ownevent", "0", szItem, nSize, strPathName);
	m_checkAutoExe.SetCheck(atoi(szItem));
	*/
	
	//�������� ��� ���� (�ð�)
	/*
	memset(szItem, 0, nSize);
	::GetPrivateProfileString("AUTO_BUY_COND_CONF", "buy_macro_time_start", "", szItem, nSize, strPathName);
	SetDlgItemText(IDC_EDIT_MIN_TIME, LPCTSTR(szItem));
	*/
	


	//�ð��ϰ�û�� ���� (check)
	memset(szItem, 0, nSize);
	::GetPrivateProfileString("AUTO_BUY_COND_CONF", "check_atonce_selltime", "0", szItem, nSize, strPathName);
	m_checkAtOnceSelTime.SetCheck(atoi(szItem));

	//�ð��ϰ�û�� ���� (�ð�)
	memset(szItem, 0, nSize);
	::GetPrivateProfileString("AUTO_BUY_COND_CONF", "atonce_selltime", "0", szItem, nSize, strPathName);
	SetDlgItemText(IDC_EDIT_AT_ONCE_TIME, LPCTSTR(szItem));

	

	//��üû����
	//������ (check)
	memset(szItem, 0, nSize);
	::GetPrivateProfileString("ALL_SEL_CONF", "check_allsell_profitratio", "0", szItem, nSize, strPathName);
	m_checkAllSelProfitRatio.SetCheck(atoi(szItem));
	//������ (%)
	memset(szItem, 0, nSize);
	::GetPrivateProfileString("ALL_SEL_CONF", "allsell_profitratio", "0", szItem, nSize, strPathName);
	SetDlgItemText(IDC_EDIT_PROFIT_RATIO, LPCTSTR(szItem));
	//������ (check)
	memset(szItem, 0, nSize);
	::GetPrivateProfileString("ALL_SEL_CONF", "check_allsell_lossratio", "0", szItem, nSize, strPathName);
	m_checkAllSelLossRatio.SetCheck(atoi(szItem));
	//������ (%)
	memset(szItem, 0, nSize);
	::GetPrivateProfileString("ALL_SEL_CONF", "allsel_lossratio", "0", szItem, nSize, strPathName);
	SetDlgItemText(IDC_EDIT_LOSS_RATIO, LPCTSTR(szItem));
	//�����ݾ�(check)
	memset(szItem, 0, nSize);
	BOOL bCheck = FALSE;
	::GetPrivateProfileString("ALL_SEL_CONF", "check_allsell_profitamount", "0", szItem, nSize, strPathName);
	bCheck = atoi(szItem);
	m_checkAllSellProfitAmount.SetCheck(bCheck);
	//�����ݾ�
	if (bCheck)
	{
		memset(szItem, 0, nSize);
		::GetPrivateProfileString("ALL_SEL_CONF", "allsell_profitamount", "0", szItem, nSize, strPathName);
		SetDlgItemText(IDC_EDIT_PROFIT_AMOUNT, LPCTSTR(szItem));
	}

	//�����ݾ�(check)
	bCheck = FALSE;
	memset(szItem, 0, nSize);
	::GetPrivateProfileString("ALL_SEL_CONF", "check_allsell_lossamount", "0", szItem, nSize, strPathName);
	bCheck = atoi(szItem);
	m_checkAllSellLossAmount.SetCheck(atoi(szItem));
	//�����ݾ�
	if (bCheck)
	{
		memset(szItem, 0, nSize);
		::GetPrivateProfileString("ALL_SEL_CONF", "allsell_lossamount", "0", szItem, nSize, strPathName);
		SetDlgItemText(IDC_EDIT_LOSS_AMOUNT, LPCTSTR(szItem));
	}

	//����û����
	//�������� (check)
	memset(szItem, 0, nSize);
	::GetPrivateProfileString("EVENT_CONF", "check_event_profit", "0", szItem, nSize, strPathName);
	m_checkEventProfit.SetCheck(atoi(szItem));
	//��������
	memset(szItem, 0, nSize);
	::GetPrivateProfileString("EVENT_CONF", "event_profit", "0", szItem, nSize, strPathName);
	SetDlgItemText(IDC_EDIT_EVENT_PROFIT_RATIO, LPCTSTR(szItem));
	//������� (check)
	memset(szItem, 0, nSize);
	::GetPrivateProfileString("EVENT_CONF", "check_event_loss", "0", szItem, nSize, strPathName);
	m_checkEventLoss.SetCheck(atoi(szItem));
	//�������
	memset(szItem, 0, nSize);
	::GetPrivateProfileString("EVENT_CONF", "event_loss", "0", szItem, nSize, strPathName);
	SetDlgItemText(IDC_EDIT_EVENT_LOSS_RATIO, LPCTSTR(szItem));
	//�ִ����� (check)
	memset(szItem, 0, nSize);
	::GetPrivateProfileString("EVENT_CONF", "check_event_maxprofit", "0", szItem, nSize, strPathName);
	m_checkEventMaxProfit.SetCheck(atoi(szItem));
	//�ִ�����
	memset(szItem, 0, nSize);
	::GetPrivateProfileString("EVENT_CONF", "event_maxprofit", "0", szItem, nSize, strPathName);
	SetDlgItemText(IDC_EDIT_MAX_PROFIT_RATIO, LPCTSTR(szItem));

	//�ִ���� (check)
	memset(szItem, 0, nSize);
	::GetPrivateProfileString("EVENT_CONF", "check_event_maxloss", "0", szItem, nSize, strPathName);
	m_checkEventMaxLoss.SetCheck(atoi(szItem));
	//�ִ����
	memset(szItem, 0, nSize);
	::GetPrivateProfileString("EVENT_CONF", "event_maxloss", "0", szItem, nSize, strPathName);
	SetDlgItemText(IDC_EDIT_MAX_LOSS_RATIO, LPCTSTR(szItem));


	//ETC_CONF
	//��ü�� �ż��ֹ����
	memset(szItem, 0, nSize);
	::GetPrivateProfileString("ETC_CONF", "check_cancel_buy_outstandingorder", "0", szItem, nSize, strPathName);
	m_checkCancelBuyOutStandingOrder.SetCheck(atoi(szItem));

	//��ü�� �ż��ֹ���� (��)
	memset(szItem, 0, nSize);
	::GetPrivateProfileString("ETC_CONF", "cancel_buy_outstandingorder_sec", "0", szItem, nSize, strPathName);
	SetDlgItemText(IDC_EDIT_CANCEL_BUY_OUTSTANDING_ORDER, LPCTSTR(szItem));

	//���� �ż�(���� �ż� ����)
	memset(szItem, 0, nSize);
	::GetPrivateProfileString("ETC_CONF", "check_fastbuy", "0", szItem, nSize, strPathName);
	m_checkFastBuy.SetCheck(atoi(szItem));

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


void CAutoTradingConf::OnBnClickedBtnLoadBuymacro()
{
	int i = 0;
	CString strCondition, strConditionName, strIndex;

	long lRet = theApp.m_khOpenApi.GetConditionLoad();

	if (lRet > 0)
	{
		CString strConditionNameList = theApp.m_khOpenApi.GetConditionNameList();


		if (strConditionNameList.GetLength() > 0)
		{
			m_comboBuyMacro.ResetContent();
		}

		while (AfxExtractSubString(strCondition, strConditionNameList, i++, _T(';')))
		{
			if (strCondition.IsEmpty())
				continue;

			AfxExtractSubString(strIndex, strCondition, 0, _T('^'));// ������ȣ
			AfxExtractSubString(strConditionName, strCondition, 1, _T('^'));// ���ǽ� �̸�


			m_comboBuyMacro.AddString(strCondition);
		}

		m_comboBuyMacro.SetCurSel(0);

	}

	
}

/*

void CAutoTradingConf::OnBnClickedCancel()
{

	//DestroyWindow();

	CDialogEx::OnCancel();
}

*/


void CAutoTradingConf::PostNcDestroy()
{
	
	//delete this;
	//CDialogEx::PostNcDestroy();
}


//void CAutoTradingConf::OnCancel()
//{
//	
//	//DestroyWindow();
//	CDialogEx::OnCancel();
//}


void CAutoTradingConf::OnOK()
{
	
	//DestroyWindow();
	CDialogEx::OnOK();
}



void CAutoTradingConf::OnClose()
{
	//m_pParent->PostMessage(UM_SCRENN_CLOSE, 5U, 0L);
	//::AfxGetMainWnd()->PostMessageA(UM_SCRENN_CLOSE, 5U, 0L);
	m_pParent->SendMessage(UM_SCRENN_CLOSE, 5U, 0L);

	CDialogEx::OnClose();
}
