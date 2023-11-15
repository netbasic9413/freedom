#pragma once


// CStatusDlg dialog

class CStatusDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CStatusDlg)

public:
	CStatusDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CStatusDlg();


public:
	CString		m_strScrNo;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STATUS_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_ListStatus;
	//afx_msg void OnLbnSelchangeListStatus();
	virtual void OnOK();
	virtual void OnCancel();
	virtual void PostNcDestroy();
	virtual BOOL OnInitDialog();
};
