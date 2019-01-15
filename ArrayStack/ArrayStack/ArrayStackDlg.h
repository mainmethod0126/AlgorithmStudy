
// ArrayStackDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"

#define STACK_MAX 20	// ������ �ִ� ũ�� ����
#define STACK_NULL -1	// ������ �ʱ� Top ����

// CArrayStackDlg ��ȭ ����
class CArrayStackDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CArrayStackDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ARRAYSTACK_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

	afx_msg void OnBnClickedButtonPush();
	afx_msg void OnBnClickedButtonPop();
	afx_msg void OnBnClickedButtonPopResultClear();
	afx_msg void OnBnClickedButtonSearch();

	DECLARE_MESSAGE_MAP()

protected:

public:

	////////////////////////////////////////
	// ������Ʈ ������� //
	CButton m_btnPop;
	CButton m_btnPush;
	CButton m_btnSearch;
	CButton m_btnPopResultClear;

	CEdit m_edtStackView;
	CEdit m_edtPopView;
	CEdit m_edtPushStackItem;
	CEdit m_edtCurTop;
	CEdit m_edtSearchItemValue;
	CEdit m_edtSearchResultView;
	CEdit m_edtSearchItemIndex;
	CEdit m_edtEmptySpace;
	CEdit m_edtTotalSpace;
	CEdit m_edtUsingSpace;
	////////////////////////////////////////


	CString m_arrStack[STACK_MAX];

	CString m_strStackView;
	CString m_strPopView;

	int m_nTopNextIndex;
	int m_nCurrentTopIndex;

	void InitDlg();
	void RefreshStackView();
	void RefreshPopView();
	void peek();
	void RefreshSpace();
	
};
