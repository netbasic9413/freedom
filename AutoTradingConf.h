#pragma once


// CAutoTradingConf dialog

class CAutoTradingConf : public CDialogEx
{
	DECLARE_DYNAMIC(CAutoTradingConf)

public:
	CAutoTradingConf(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CAutoTradingConf();


public:
	CWnd* m_pParent;
	CString		m_strScrNo;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AUTO_CONF_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedBtnSaveStrategy();
	afx_msg void OnBnClickedBtnOpenStrategy();
	CButton m_checkAutoExe; //자동실행
	afx_msg void OnBnClickedCheckAutoExe();
	CButton m_checkBuyMacro; //매수조건식
	afx_msg void OnBnClickedCheckBuyMacro();
	CDateTimeCtrl m_dtpickerBuyMacroStart;
	afx_msg void OnDtnDatetimechangeTpStartBuyMacro(NMHDR* pNMHDR, LRESULT* pResult);
	CDateTimeCtrl m_dtpickerBuyMacroEnd;
	afx_msg void OnDtnDatetimechangeTpEndBuyMacro(NMHDR* pNMHDR, LRESULT* pResult);
	CDateTimeCtrl m_dtpickerAutoTradingStart; //자동매매 운영시간 시작
	afx_msg void OnDtnDatetimechangeTpStartTime(NMHDR* pNMHDR, LRESULT* pResult);
	CDateTimeCtrl m_dtpickerAutoTradingEnd; //자동매매 운영시간 끝
	afx_msg void OnDtnDatetimechangeTpEndTime(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnEnChangeEditTotalPossibleBuyAmount();
	CComboBox m_comboBuyMacro; //매수조건식
	afx_msg void OnCbnSelchangeComboBuyMacro();
	CButton m_checkSelMacro;	//매도조건식
	afx_msg void OnBnClickedCheckSelMacro();
	CButton m_checkExeOwnEvent; //보유종목 대상 실행
	afx_msg void OnBnClickedCheckExeOwn();
	CDateTimeCtrl m_dtpickerMinTime;
	afx_msg void OnDtnDatetimechangeTpAtOnceTime(NMHDR* pNMHDR, LRESULT* pResult);
	CButton m_checkAllSelProfitRatio; //전체청산방식 - 익절률
	afx_msg void OnBnClickedCheckProfitRatio();
	CButton m_checkAllSelLossRatio; //전체청산방식 - 손절률
	afx_msg void OnBnClickedCheckLossRatio();
	CButton m_checkAllSellProfitAmount; //전체청산방식 - 익절금액(원)
	afx_msg void OnBnClickedCheckProfitAmount();
	afx_msg void OnBnClickedCheck8();
	CButton m_checkAllSellLossAmount; //전체청산방식 - 손절금액(원)
	afx_msg void OnBnClickedCheckLossAmount();
	CEdit m_editTradingStrategy;
	afx_msg void OnEnChangeEditTradingStrategy();
	CButton m_checkEventProfit; //종목청산방식 - 종목익절
	afx_msg void OnBnClickedCheckEventProfit();
	CButton m_checkEventLoss;
	afx_msg void OnBnClickedCheckEventLossRatio();
	CButton m_checkMaxProfit;
	afx_msg void OnBnClickedCheckMaxProfit();
	CButton m_checkEventMaxLoss;
	afx_msg void OnBnClickedCheckEventMaxLossRatio();
	CButton m_checkProfitMinEventCount;
	afx_msg void OnBnClickedCheckProfitMinEventCount();
	afx_msg void OnEnChangeEditProfitMinEventCount();
	CButton m_checkCancelBuyOutStandingOrder;
	afx_msg void OnBnClickedCheckCancelBuyOutstandingOrder();
	CButton m_checkExeProfitLoss;
	afx_msg void OnBnClickedCheckExeProfitLoss();
	CButton m_checkFastBuy;
	afx_msg void OnBnClickedCheckFastBuy();
	afx_msg void OnBnClickedCheckEventMaxProfitRatio();
	CButton m_checkEventMaxProfit;
};
