#pragma once


// CAutoTradingConf dialog

class CAutoTradingConf : public CDialogEx
{
	DECLARE_DYNAMIC(CAutoTradingConf)

public:
	CAutoTradingConf(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CAutoTradingConf();


public:
	void LoadConfig(int nType);
	CWnd* m_pParent;
	CString		m_strScrNo;
	CString		m_strExeMacro;

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
	CButton m_checkAutoExe; //�ڵ�����
	afx_msg void OnBnClickedCheckAutoExe();
	CButton m_checkBuyMacro; //�ż����ǽ�
	afx_msg void OnBnClickedCheckBuyMacro();
	//CDateTimeCtrl m_dtpickerAutoTradingStart; //�ڵ��Ÿ� ��ð� ����
	afx_msg void OnDtnDatetimechangeTpStartTime(NMHDR* pNMHDR, LRESULT* pResult);
	//CDateTimeCtrl m_dtpickerAutoTradingEnd; //�ڵ��Ÿ� ��ð� ��

	CComboBox m_comboBuyMacro; //�ż����ǽ�
	afx_msg void OnCbnSelchangeComboBuyMacro();
	//CDateTimeCtrl m_dtpickerBuyMacroStart; //�ż����ǽ� ���۽ð�
	afx_msg void OnDtnDatetimechangeTpStartBuyMacro(NMHDR* pNMHDR, LRESULT* pResult);
	//CDateTimeCtrl m_dtpickerBuyMacroEnd; //�ż����ǽ� ���ð�
	afx_msg void OnDtnDatetimechangeTpEndBuyMacro(NMHDR* pNMHDR, LRESULT* pResult);
	
	afx_msg void OnDtnDatetimechangeTpEndTime(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnEnChangeEditTotalPossibleBuyAmount();
	

	CButton m_checkSelMacro;	//�ŵ����ǽ�
	afx_msg void OnBnClickedCheckSelMacro();
	CButton m_checkExeOwnEvent; //�������� ��� ����
	afx_msg void OnBnClickedCheckExeOwn();
	//CDateTimeCtrl m_dtpickerMinTime; //�������� ��� ���� �д��� ����
	afx_msg void OnDtnDatetimechangeTpAtOnceTime(NMHDR* pNMHDR, LRESULT* pResult);
	CButton m_checkAtOnceSelTime; //�ð��ϰ�û�� ����
	afx_msg void OnBnClickedCheckAtOnceSelTime();

	//��üû����
	CButton m_checkAllSelProfitRatio; //��üû���� - ������
	afx_msg void OnBnClickedCheckProfitRatio();
	CButton m_checkAllSelLossRatio; //��üû���� - ������
	afx_msg void OnBnClickedCheckLossRatio();
	CButton m_checkAllSellProfitAmount; //��üû���� - �����ݾ�(��)
	afx_msg void OnBnClickedCheckProfitAmount();
	afx_msg void OnBnClickedCheck8();
	CButton m_checkAllSellLossAmount; //��üû���� - �����ݾ�(��)
	afx_msg void OnBnClickedCheckLossAmount();
	CEdit m_editTradingStrategy; //�Ÿ�������
	afx_msg void OnEnChangeEditTradingStrategy();

	//����û����
	CButton m_checkEventProfit; //����û���� - ��������
	afx_msg void OnBnClickedCheckEventProfit();
	CButton m_checkEventLoss; //����û���� - �������
	afx_msg void OnBnClickedCheckEventLossRatio();
	CButton m_checkEventMaxProfit; //����û���� - �ִ�����
	afx_msg void OnBnClickedCheckEventMaxProfitRatio();
	CButton m_checkEventMaxLoss; //����û���� - �ִ����
	afx_msg void OnBnClickedCheckEventMaxLossRatio();


	CButton m_checkProfitMinEventCount; //���ͷ���� �ʼ������
	afx_msg void OnBnClickedCheckProfitMinEventCount();
	afx_msg void OnEnChangeEditProfitMinEventCount();
	CButton m_checkCancelBuyOutStandingOrder; //��ü�� �ż��ֹ����
	afx_msg void OnBnClickedCheckCancelBuyOutstandingOrder();
	CButton m_checkExeProfitLoss; //�ż����ǽ� ������ ����, ���� ����
	afx_msg void OnBnClickedCheckExeProfitLoss();
	CButton m_checkFastBuy; //���� �ż� (���� �ż� ����)
	afx_msg void OnBnClickedCheckFastBuy();
	
	
	
	afx_msg void OnBnClickedBtnLoadBuymacro();
	//afx_msg void OnBnClickedCancel();
	virtual void PostNcDestroy();
//	virtual void OnCancel();
	virtual void OnOK();

	afx_msg void OnClose();
	virtual BOOL OnInitDialog();
};
