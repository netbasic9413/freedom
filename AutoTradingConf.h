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
};
