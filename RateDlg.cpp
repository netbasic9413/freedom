//******************************************************************/
//******************************************************************/
//! All Rights Reserved. Copyright(c)   2015 (��)�ѱ��Ҹ���ġ                /
//******************************************************************/
//! File Name			: RateDlg.cpp
//! Function			: ���ͷ����
//! System Name	: Ű�� ����API �׽�Ʈ
//! Create				: , 2015/05/07
//! Update				: 
//! Comment			: 
//******************************************************************/
// RateDlg.cpp : ���� ����

#include "stdafx.h"
#include "KhOpenApiTest.h"
#include "RateDlg.h"
#include "afxdialogex.h"
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//#define  COMMISSION		0.0035	// �������� ��ü������
#define  COMMISSION1	0.0005	// ������(�ŷ���)
#define  COMMISSION2	0.0020	// ������(�ڽ���)
#define  COMMISSION3	0.0015	// ������(�ŷ��� �����Ư����)

// {��ȸ Ű,		���� Ű,	��, ��, Ÿ��,			�� ����, ����, �� ����, �� ����}
const stGRID lstFID[] = 
{
	{_T("�ſ뱸��"),	_T("917"),	-1,	0,	DT_NONE,		FALSE,	DT_CENTER,	_T(""),	_T("")},
	{_T("�����ڵ�"),	_T("9001"),	-1,	1,	DT_NONE,		FALSE,	DT_CENTER,	_T(""),	_T("")},
	{_T("�����"),	_T("302"),	-1,	2,	DT_NONE,		FALSE,	DT_LEFT,	_T(""),	_T("")},
	{_T("���簡"),	_T("10"),	-1,	3,	DT_ZERO_NUMBER,	FALSE,	DT_RIGHT,	_T(""),	_T("")},
	{_T("��������"),	_T("930"),	-1,	4,	DT_ZERO_NUMBER,	FALSE,	DT_RIGHT,	_T(""),	_T("")},
	{_T("�򰡱ݾ�"),	_T("-1"),	-1,	5,	DT_ZERO_NUMBER,	FALSE,	DT_RIGHT,	_T(""),	_T("")},
	{_T("�򰡼���"),	_T("-1"),	-1,	6,	DT_NONE		,	FALSE,	DT_RIGHT,	_T(""),	_T("")},
	{_T("���ͷ�"),	_T("-1"),	-1,	7,	DT_ZERO_NUMBER,	FALSE,	DT_RIGHT,	_T(""),	_T("")},
	{_T("���Աݾ�"),	_T("932"),	-1,	8,	DT_ZERO_NUMBER,	FALSE,	DT_RIGHT,	_T(""),	_T("")},
	{_T("���簡"),	_T("10"),	-1,	9,	DT_NONE,		FALSE,	DT_RIGHT,	_T(""),	_T("")},	//(�������� ����)
	{_T("��������"),	_T("930"),	-1,	10,	DT_NONE,		FALSE,	DT_RIGHT,	_T(""),	_T("")},	//(�������� ����)
	{_T("���Աݾ�"),	_T("932"),	-1,	11,	DT_NONE,		FALSE,	DT_RIGHT,	_T(""),	_T("")},	//(�������� ����)
	{_T("�򰡱ݾ�"),	_T("-1"),	-1,	12,	DT_NONE,		FALSE,	DT_RIGHT,	_T(""),	_T("")},	//(�������� ����)
};

// CRateDlg ��ȭ ����
//*******************************************************************************************************/
//! Function Name	: CRateDlg::CRateDlg(CWnd* pParent /*=NULL*/) : CDialogEx(CRateDlg::IDD, pParent)
//! Function			: ���� �ʱ� ó��
//! Param				: HANDLE hBitmap, int bits
//! Return				: void
//! Create				: , 2015/05/07
//! Comment			: 
//*******************************************************************************************************/
CRateDlg::CRateDlg(CWnd* pParent /*=NULL*/, CString strSeverType)
	: CDialogEx(CRateDlg::IDD, pParent)
{
	m_pParent			= pParent;
	m_strScrNo			= _T("9999");

	m_TotalEval			= 0;
	m_TotalPurchase		= 0;
	m_TotalProfit		= 0;
	m_TotalRate			= 0;
	m_Eval				= 0;
	m_Profit			= 0;
	m_Rate				= 0;
	m_Purchase			= 0;
	m_Comm				= 0;
	m_BuyComm			= 0;
	m_SellComm			= 0;
	m_Tax				= 0;
	m_Price				= 0;
	m_Qty				= 0;
	m_nCount			= 0;
	m_nNextRow			= 0;

	m_bNextFlag			= FALSE;
	if(strSeverType.CompareNoCase(_T("1")) == 0)// �������� ������ ���
		m_dFee = 0.0035;
	else
		m_dFee = 0.00015;	// �Ǽ��� �ŷ���������
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

//*******************************************************************/
// Function Name	: DoDataExchange
// Function			: DDX/DDV�� ���� �� �Լ� ȣ��
// Param				: CDataExchange*	pDX
// Return				: void
// Create				: , 2015/05/07
// Comment			: DDX - ��Ʈ�Ѱ� ����������̿� ������ ��ȯ�ϴ� ����
//							: DDV - ��������� ���� �� ���� ��ȿ�� üũ
//							: UapdateData()�Լ��� ���� ȣ�� �� �� ����
//*******************************************************************/
void CRateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRateDlg)
		DDX_Control(pDX, IDC_EDT_ACC,			m_EdtAcc);
		DDX_Control(pDX, IDC_GRD_RATE,			m_grdRate);
		DDX_Control(pDX, IDC_EDT_EVAL,			m_EdtTotalEval);
		DDX_Control(pDX, IDC_EDT_PURCHASE,	m_EdtTotalPurchase);
		DDX_Control(pDX, IDC_EDT_PROFIT,		m_EdtTotalProfit);
		DDX_Control(pDX, IDC_EDT_RATE,			m_EdtTotalRate);
		
	//}}AFX_DATA_MAP
}

//*******************************************************************/
// BEGIN_MESSAGE_MAP
//*******************************************************************/
BEGIN_MESSAGE_MAP(CRateDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_CLOSE()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_SEARCH, OnBtnSearch)
END_MESSAGE_MAP()

//*******************************************************************/
//! Function Name	: OnInitDialog
//! Function			: ���� �ʱ� ó��
//! Param				: void
//! Return				: BOOL
//! Create				: 2015/05/07
//! Comment			: CRateDlg �޽��� ó����
//******************************************************************/
BOOL CRateDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	InitRealAddGrid();					// �׸��� �ʱ� ó��

	CString strMsg;
	strMsg.Format(_T("������: %.2f%%, �ŷ��� ���� �ŷ���: %.2f%%, ��Ư��: %.2f%%, �ڽ��� ���� �ŷ���: %.2f%%")
		, m_dFee * 100
		, COMMISSION1 * 100
		, COMMISSION3 * 100
		, COMMISSION2 * 100
		);
	SetDlgItemText(IDC_ST_RATE_INFO, strMsg);

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CRateDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

void CRateDlg::OnClose()
{
	// ȭ�� ���� �� �θ������쿡�� �뺸(ȭ�� ���� ����)
	if (m_pParent)
	{
		int nLen = m_strScrNo.GetLength();
		char *cScrNo = new char[nLen + 1];
		memset(cScrNo, 0x00, nLen + 1);
		memcpy(cScrNo, m_strScrNo, nLen);
		m_pParent->PostMessage(UM_SCRENN_CLOSE, 0U, (LPARAM)cScrNo);
	}

	CDialogEx::OnClose();
}

HCURSOR CRateDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CRateDlg::InitRealAddGrid()
{// �׸��� �ʱ�ȭ, OpenAPI��ɰ� �������

	m_grdRate.SetEditable(false);				//cell�� ����Ʈ ���ϰ� ��.
	m_grdRate.EnableScrollBars(SB_HORZ, FALSE);

	COLORREF clr = RGB(215, 227, 241);

	// ���� ��/�� ����
	m_grdRate.SetFixedRowCount(1);

	// ��/�� ���� ����
	m_grdRate.SetRowCount(1);
	int nCount = sizeof(lstFID) / sizeof(*lstFID);		// ��üũ�� / ����ũ�� = ���Ұ���
	m_grdRate.SetColumnCount(nCount);

	// ���� ���� ����
	int i, nWidth[] = {70, 79, 80, 80, 60, 80, 80, 80, 90, 0, 0, 0, 0};
	CString strHeader[] = {"�ſ뱸��", "�����ڵ�", "�����", "���簡", "��������", "�򰡱ݾ�", "�򰡼���", "���ͷ�", "���Աݾ�", "���簡(����)", "��������(����)", "���Աݾ�(����)", "�򰡱ݾ�(����)"};

	int nCnt = sizeof(nWidth) / sizeof(*nWidth);		// ��üũ�� / ����ũ�� = ���Ұ���
	for (i = 0; i < nCnt; i++)
	{
		m_grdRate.SetColumnWidth(i, nWidth[i]);
		m_grdRate.SetItemFormat(0, i, DT_CENTER);
		m_grdRate.SetItemText(0, i, strHeader[i]);
		m_grdRate.SetItemBkColour(0, i, clr);	// ������ ���� ���� ����
	}

	// ���� ���� ����
	m_grdRate.SetRowHeight(0, 24);

	m_grdRate.Invalidate();
}

void CRateDlg::OnReceiveTrDataKhopenapictrl(LPCTSTR sScrNo, LPCTSTR sRQName, LPCTSTR sTrcode, LPCTSTR sRecordName, LPCTSTR sPrevNext, long nDataLength, LPCTSTR sErrorCode, LPCTSTR sMessage, LPCTSTR sSplmMsg)
{// ��ȸ��û ���� �̺�Ʈ

	CString strPrevNext(sPrevNext);
	CString strRQName(sRQName);
	if (strRQName == _T("���¼��ͷ�"))			// ���¼��ͷ�
	{
		m_bNextFlag = FALSE;
		CString strData;
		int nFieldCnt = sizeof(lstFID) / sizeof(*lstFID);		// ��üũ�� / ����ũ�� = ���Ұ���

		strRQName = _T("���¼��ͷ�");
		int i, j, nCnt = theApp.m_khOpenApi.GetRepeatCnt(sTrcode, strRQName);	//������ �Ǽ�
		m_nCount += (nCnt+1);	//������ �Ǽ��� �׸��� ��� �߰�
		m_grdRate.SetRowCount(m_nCount);

		for (i = 0; i < nCnt; i++)
		{
			CString strCode;

			for (j = 0; j < nFieldCnt; j++)
			{
				strData = theApp.m_khOpenApi.GetCommData(sTrcode, strRQName, i, lstFID[j].strKey);
				strData.Trim();

				if (j == 0) //�ſ뱸��
				{
					if (strData == _T("00"))
					{
						strData = _T("����");
					} 
					else if (strData == _T("03"))
					{
						strData = _T("����");
					}
					else if (strData == _T("99"))
					{
						strData = _T("������");
					}
				}
				else if (j == 1)	//�����
				{
					strCode = strData;
				}

				m_grdRate.SetItemFormat(i + 1 + m_nNextRow, lstFID[j].nCol, lstFID[j].nAlign);
				if (strData != _T(""))
				{
					m_grdRate.SetItemText(i + 1 + m_nNextRow, j, theApp.ConvDataFormat(lstFID[j].nDataType, strData, lstFID[j].strBeforeData, lstFID[j].strAfterData));
				}
			}

			int nRow(0);
			nRow = i + 1 + m_nNextRow;

			//���� ���ͷ� ���
			SetRate(nRow, strCode);

			CString strIndex;
			strIndex.Format(_T("%d"), nRow);

			//������ Ű������ �ؼ� �ο찪�� �����Ѵ�.
			m_mapJongCode.SetAt(strCode, strIndex);
		}

		//�� ���ͷ� ���
		SetTotalRate();

		if (strPrevNext == _T("2"))	//������ȸ
		{
			m_bNextFlag = TRUE;	//������ȸ����
			m_nCount = m_nCount - 1;	//�׸��� ���Row��/�� ����.
			m_nNextRow = m_nCount;	//������ȸ�� ������ Row���� ����.
			
			CString strAccNo;
			m_EdtAcc.GetWindowText(strAccNo);	//�Է��� ���¹�ȣ.

			//������ȸ�� �Ѵ�.
			theApp.m_khOpenApi.SetInputValue(_T("���¹�ȣ"), strAccNo);
			theApp.m_khOpenApi.CommRqData(_T("���¼��ͷ�"), _T("OPT10085"), 2, m_strScrNo);
		}

		//������ȸ�� �ƴҶ��� �ǽð� ����� �Ѵ�.
		if (!m_bNextFlag)
		{
			CString strRQName = _T("��������"), strCodeList, strCode;
			long  nCodeCount(0);

			for (int nRow = 1; nRow < m_nCount; nRow++)
			{
				nCodeCount++;
				strCode = m_grdRate.GetItemText(nRow, 1);
				strCode.Trim();
				strCodeList += strCode + _T(";");
			}

			long lRet = theApp.m_khOpenApi.CommKwRqData(strCodeList, 0, nCodeCount, 0, strRQName, m_strScrNo);
			if (!lRet)
			{
				return;
			}
		}

		m_grdRate.Invalidate();
	}
}

void CRateDlg::OnReceiveMsgKhopenapictrl(LPCTSTR sScrNo, LPCTSTR sRQName, LPCTSTR sTrCode, LPCTSTR sMsg)
{// �ֹ��̳� ���°��� ��ȸ ���� �޽��� ���� �̺�Ʈ
}

void CRateDlg::OnReceiveRealDataKhopenapictrl(LPCTSTR sJongmokCode, LPCTSTR sRealType, LPCTSTR sRealData)
{// �ǽð� �ü������� ���� �̺�Ʈ

	CString strIndex, strData;
	if (!m_mapJongCode.Lookup(sJongmokCode, strIndex))
	{
		return;
	}

	CString strCode;

	int i, nFieldCnt = sizeof(lstFID) / sizeof(*lstFID);		// ��üũ�� / ����ũ�� = ���Ұ���
	for (i = 0; i < nFieldCnt; i++)
	{
		if (atoi(lstFID[i].strRealKey) < 0)
		{
			continue;
		}

		//�ǽð� �����͸� �׸� �°� �����´�.
		strData = theApp.m_khOpenApi.GetCommRealData(sJongmokCode, atoi(lstFID[i].strRealKey));	strData.Trim();

		//�׸� �´� �����Ͱ� �������� �׸��忡 ǥ���Ѵ�.
		if (strData != _T(""))
		{
			m_grdRate.SetItemText(_ttoi(strIndex), i, theApp.ConvDataFormat(lstFID[i].nDataType, strData, lstFID[i].strBeforeData, lstFID[i].strAfterData));
		}
	}

	//���� ���ͷ� ���
	strCode = sJongmokCode;
	SetRate(_ttoi(strIndex), strCode);

	//�� ���ͷ� ���
	SetTotalRate();

	m_grdRate.Invalidate();
}

void CRateDlg::OnReceiveChejanData(LPCTSTR sGubun, LONG nItemCnt, LPCTSTR sFidList)
{// �ǽð� �ֹ�,�ܰ��뺸 ���� �̺�Ʈ

	CString strGuBun(sGubun), strAccNo, strAcc;

	strAccNo	= theApp.m_khOpenApi.GetChejanData(9201);	// ü��� ������ ���¹�ȣ
	m_EdtAcc.GetWindowText(strAcc);									// ���� ���¹�ȣ

	//���� ���ͷ� ��ȸ�� ���¹�ȣ�� �ִ� ü��� ���� ���� �� �ְ� ó��.
	if (strAccNo == strAcc)
	{
		if (strGuBun == _T("4"))
		{
			OnBtnSearch(); //���������� ����ȸ�Ѵ�.
		}
	}
}

void CRateDlg::OnBtnSearch()
{// ���� ���ͷ� ��ȸ��û

	CString strAccNo;
	m_EdtAcc.GetWindowText(strAccNo);	//�Է��� ���¹�ȣ.
	if(strAccNo.IsEmpty())
	{
		AfxMessageBox(_T("���ͷ� ��ȸ�� ���¹�ȣ 10�ڸ��� �Է����ּ���."));
		return;
	}
	
	m_grdRate.SetRowCount(1);		// ��/�� ���� ����
	m_nCount = 0;
	m_nNextRow = 0;

	//���ͷ���� ��ȸ
	theApp.m_khOpenApi.SetInputValue(_T("���¹�ȣ"), strAccNo);
	long lRet = theApp.m_khOpenApi.CommRqData(_T("���¼��ͷ�"), _T("OPT10085"), 0, m_strScrNo);

	if (!theApp.IsError(lRet))
	{
	}
}

void CRateDlg::SetRate(int nRow, CString strCode)
{// ���� ���ͷ� ���

	//�ֽ� ���� ���� ���ͷ� ����̶� �ֽĿ� ������ ���ͷ��� �ٸ��� ������ �˷��帳�ϴ�.
	//���簡
	CString strData, strTmp;
	strData = m_grdRate.GetItemText(nRow, 9);
	strTmp = strData.Left(1);
	if (strTmp == _T("-") || strTmp == _T("+"))
	{
		strData = strData.Mid(1);
	}
	double nPrice = _ttof(strData);

	//����
	double nQty = _ttof(m_grdRate.GetItemText(nRow, 10));

	//���Աݾ�
	double nPurchase = _ttof(m_grdRate.GetItemText(nRow, 11));

	int nCount(0);
	nCount = m_grdRate.GetRowCount();

	//�ż������ ������ = ���Աݾ� * ��ü������(0.015%) (10���̸� ����)
	m_BuyComm = nPurchase * m_dFee;
	m_BuyComm = floor(m_BuyComm / 10) * 10;	//(10���̸� ����)

	//�ŵ������ ������ = ���簡 * ���� * ��ü������(0.015%) (10���̸� ����)
	m_SellComm = nPrice * nQty * m_dFee;
	m_SellComm = floor(m_SellComm / 10) * 10;	//(10���̸� ����)

	//������
	long lMarketType = theApp.m_khOpenApi.GetMarketType(strCode);
	if (lMarketType == 0) //�ŷ���
	{// ������(�ŷ���) = ���簡 * ���� * 0.15%(�����Ư����) + ���簡 * ���� * 0.05%(�ŷ���)
		m_Tax = nPrice * nQty * COMMISSION1;
		m_Tax = floor(m_Tax);
		
		double dTax = nPrice * nQty * COMMISSION3;
		dTax = floor(dTax);
		m_Tax = m_Tax + dTax;		
	} 
	else if (lMarketType == 10)//�ڽ���
	{
		//������(�ڽ���) = ���簡 * ���� * 0.3%(���̸� ����)
		m_Tax = floor(nPrice * nQty * COMMISSION2);
	}

	CString strTemp;

	//���� �򰡱ݾ� = (���簡 * ����) - �ż������ ������ - �ŵ������ ������ - ������ �����
	m_Eval = (nPrice * nQty) - m_BuyComm - m_SellComm - m_Tax;
	strTemp.Format(_T("%0.lf"), m_Eval);
	m_grdRate.SetItemText(nRow, 5,  theApp.ConvDataFormat(lstFID[5].nDataType, strTemp, lstFID[5].strBeforeData, lstFID[5].strAfterData));
	m_grdRate.SetItemText(nRow, 12,  theApp.ConvDataFormat(lstFID[12].nDataType, strTemp, lstFID[12].strBeforeData, lstFID[12].strAfterData));

	//���� �򰡼��� = �򰡱ݾ� - ���Աݾ�
	m_Profit = m_Eval - nPurchase;
	strTemp.Format(_T("%0.lf"), m_Profit);
	m_grdRate.SetItemText(nRow, 6,  theApp.ConvDataFormat(lstFID[6].nDataType, strTemp, lstFID[6].strBeforeData, lstFID[6].strAfterData));

	//���� ���ͷ� = �򰡼��� / ���Աݾ� * 100
	if (nPurchase == 0)
	{
		m_Rate = 0;
	}
	else
	{
		m_Rate = m_Profit / nPurchase * 100;
	}
	strTemp.Format(_T("%0.2lf %%"), m_Rate);
	m_grdRate.SetItemText(nRow, 7,  theApp.ConvDataFormat(lstFID[7].nDataType, strTemp, lstFID[7].strBeforeData, lstFID[7].strAfterData));
}

void CRateDlg::SetTotalRate()
{// ��ü ���ͷ� ���
	int nCnt = m_grdRate.GetRowCount();	//�׸��� Row ���� ���ϱ�
	double dTotalEval(0), dTotalPurchase(0), dTotalProfit, dTotalRate(0);
	CString strTotalEval, strTotalPurchase, strTotalProfit, strTotalRate;

	for (int i = 1; i < nCnt; i++)
	{
		dTotalEval += _ttof(m_grdRate.GetItemText(i, 12));			// �� �򰡱ݾ�
		dTotalPurchase += _ttof(m_grdRate.GetItemText(i, 11));	// �� ���Աݾ�
	}
	
	strTotalEval.Format(_T("%0.lf"), dTotalEval);
	strTotalEval = theApp.ConvDataFormat(DT_ZERO_NUMBER, strTotalEval);
	m_EdtTotalEval.SetWindowText(strTotalEval);

	strTotalPurchase.Format(_T("%0.lf"), dTotalPurchase);
	strTotalPurchase = theApp.ConvDataFormat(DT_ZERO_NUMBER, strTotalPurchase);
	m_EdtTotalPurchase.SetWindowText(strTotalPurchase);


	// �� �򰡼���
	dTotalProfit = dTotalEval - dTotalPurchase;
	strTotalProfit.Format(_T("%0.lf"), dTotalProfit);
	strTotalProfit = theApp.ConvDataFormat(DT_ZERO_NUMBER, strTotalProfit);
	m_EdtTotalProfit.SetWindowText(strTotalProfit);

	// �� ���ͷ�
	dTotalRate = dTotalProfit / dTotalPurchase * 100;
	strTotalRate.Format(_T("%0.2lf"), dTotalRate);
	strTotalRate = theApp.ConvDataFormat(DT_NONE, strTotalRate, _T(""), _T("%"));
	m_EdtTotalRate.SetWindowText(strTotalRate);
}