
// ArrayStackDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"

#define STACK_MAX 20	// 스택의 최대 크기 정의
#define STACK_NULL -1	// 스택의 초기 Top 정의

// CArrayStackDlg 대화 상자
class CArrayStackDlg : public CDialogEx
{
// 생성입니다.
public:
	CArrayStackDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ARRAYSTACK_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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
	// 컴포넌트 멤버변수 //
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
