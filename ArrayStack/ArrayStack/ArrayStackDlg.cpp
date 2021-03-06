
// ArrayStackDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "ArrayStack.h"
#include "ArrayStackDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CArrayStackDlg 대화 상자



CArrayStackDlg::CArrayStackDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CArrayStackDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_nCurrentTopIndex = STACK_NULL;
}

void CArrayStackDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_POP,		m_btnPop);
	DDX_Control(pDX, IDC_BUTTON_PUSH,		m_btnPush);
	DDX_Control(pDX, IDC_EDIT_STACK_VIEW,	m_edtStackView);
	DDX_Control(pDX, IDC_EDIT_PUSH_STACK_ITEM, m_edtPushStackItem);
	DDX_Control(pDX, IDC_EDIT_POP_VIEW,		m_edtPopView);
	DDX_Control(pDX, IDC_BUTTON_SEARCH,		m_btnSearch);
	DDX_Control(pDX, IDC_EDIT_CURRENT_TOP,	m_edtCurTop);
	DDX_Control(pDX, IDC_EDIT_SEARCH_RESULT, m_edtSearchResultView);
	DDX_Control(pDX, IDC_BUTTON_POP_RESULT_CLEAR, m_btnPopResultClear);
	DDX_Control(pDX, IDC_EDIT_SEARCH_ITEM_INDEX, m_edtSearchItemIndex);
	DDX_Control(pDX, IDC_EDIT_EMPTY_SPACE,	m_edtEmptySpace);
	DDX_Control(pDX, IDC_EDIT_TOTAL_SPACE,	m_edtTotalSpace);
	DDX_Control(pDX, IDC_EDIT_USING_SPACE,	m_edtUsingSpace);
}

BEGIN_MESSAGE_MAP(CArrayStackDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_PUSH, &CArrayStackDlg::OnBnClickedButtonPush)
	ON_BN_CLICKED(IDC_BUTTON_POP, &CArrayStackDlg::OnBnClickedButtonPop)
	ON_BN_CLICKED(IDC_BUTTON_POP_RESULT_CLEAR, &CArrayStackDlg::OnBnClickedButtonPopResultClear)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, &CArrayStackDlg::OnBnClickedButtonSearch)
END_MESSAGE_MAP()


// CArrayStackDlg 메시지 처리기

BOOL CArrayStackDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	InitDlg();

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CArrayStackDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CArrayStackDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CArrayStackDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 다이얼로그 컴포터는트들의 초깃값 셋팅
void CArrayStackDlg::InitDlg()
{
	// 현재 다이얼로그는 초기 데이터가 선택 될 것이 없기에 내용 없음
}


// 스택에 데이터 적재
void CArrayStackDlg::OnBnClickedButtonPush()
{
	CString strPushStackItem = NULL;
	m_edtPushStackItem.GetWindowTextW(strPushStackItem);

	if (strPushStackItem.IsEmpty() == FALSE)
	{
		CString strPopItem = NULL;

		m_edtPushStackItem.GetWindowTextW(strPopItem);				// Edit Box에서 Text Reading.

		m_arrStack[m_nCurrentTopIndex + 1] = strPopItem;			// 데이터가 들어가는 곳은 현재 Top이 아닌 Top위로 Item을 추가하여야 하기에 TopIndex + 1 위치에 값 입력

		m_nCurrentTopIndex++;										// 데이터가 입력되었으면 Top을 증가시켜 가장 최근에 들어간 Item의 Index를 기억한다

		RefreshStackView();											// StackView 컴포넌트를 Refresh시켜 데이터가 추가된 스택을 보여준다.

		m_edtPushStackItem.SetWindowTextW(_T(""));					// 스택에 추가할 데이터가 들어갔던 컴포넌트를 비워준다.

		peek();														// 현재 CurrentTop을 컴포넌트상에 보여주는 함수.

		RefreshSpace();
	}
	else
	{
		CString strErrMsg = (_T("스택에 등록할 Item을 입력하여 주세요."));
		AfxMessageBox(strErrMsg);
	}
}

// 스택에서 데이터 꺼내오기
void CArrayStackDlg::OnBnClickedButtonPop()
{
	RefreshPopView();												// 스택에서 POP된 Item을 POP View 컴포넌트에 띄워준다.
	
	m_arrStack[m_nCurrentTopIndex] = "";							// POP된 Item을 배열에서 비워준다.

	RefreshStackView();												// POP이 실행되었기에 Stack View 컴포넌트를 Refresh 해준다.

	m_nCurrentTopIndex--;											// Top을 하나 다운시켜 가장 상단 Item을 가르키게 한다.

	peek();															// 현재 CurrentTop을 컴포넌트상에 보여주는 함수.

	RefreshSpace();
}

// 꺼내온 데이터를 보여주는 컴포넌트 클리어
void CArrayStackDlg::OnBnClickedButtonPopResultClear()
{
	m_strPopView = "";
	m_edtPopView.SetWindowTextW(m_strPopView);
}

// 입력한 인덱스를 기준으로 해당 인덱스의 데이터를 보여줌
void CArrayStackDlg::OnBnClickedButtonSearch()
{
	CString strSearchItemIndex = NULL;
	m_edtSearchItemIndex.GetWindowTextW(strSearchItemIndex);

	int nSearchItemIndex = _ttoi(strSearchItemIndex);

	m_edtSearchResultView.SetWindowTextW(m_arrStack[nSearchItemIndex]);
}

// 현재 Top이 무엇인지 컴포넌트에 입력
void CArrayStackDlg::peek()
{
	if (m_nCurrentTopIndex == STACK_NULL)
	{
		m_edtCurTop.SetWindowTextW(_T(""));
	}
	else {
		m_edtCurTop.SetWindowTextW(m_arrStack[m_nCurrentTopIndex]);
	}
}

// 스택의 현 상태를 컴포넌트에 입력
void CArrayStackDlg::RefreshStackView()
{
	m_strStackView = "";
	for (int i = 0; i <= m_nCurrentTopIndex; i++)
	{
		m_strStackView.Append(m_arrStack[i]);
		m_edtStackView.SetWindowTextW(m_strStackView);
	}
}

// 스택에서 꺼내온 데이터를 컴포넌트에 입력
void CArrayStackDlg::RefreshPopView()
{
	m_strPopView.Append(m_arrStack[m_nCurrentTopIndex]);
	m_edtPopView.SetWindowTextW(m_strPopView);
}

// 현재 Queue에 총공간, 사용중인 공간, 비어있는 공간을 컴포넌트에 입력
void CArrayStackDlg::RefreshSpace()
{

	CString strTotalSpace = NULL;
	strTotalSpace.Format(_T("%d"), STACK_MAX);
	m_edtTotalSpace.SetWindowTextW(strTotalSpace);


	CString strUsingSpace = NULL;
	int nUsingSpace = m_nCurrentTopIndex + 1;
	strUsingSpace.Format(_T("%d"), nUsingSpace);
	m_edtUsingSpace.SetWindowTextW(strUsingSpace);

	
	CString strEmptySpace = NULL;
	int nEmptySpace = STACK_MAX - nUsingSpace;
	strEmptySpace.Format(_T("%d"), nEmptySpace);
	m_edtEmptySpace.SetWindowTextW(strEmptySpace);
}
