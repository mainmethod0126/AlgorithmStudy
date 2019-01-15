
// ArrayStackDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "ArrayStack.h"
#include "ArrayStackDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CArrayStackDlg ��ȭ ����



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


// CArrayStackDlg �޽��� ó����

BOOL CArrayStackDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	InitDlg();

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CArrayStackDlg::OnPaint()
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

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CArrayStackDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// ���̾�α� �����ʹ�Ʈ���� �ʱ갪 ����
void CArrayStackDlg::InitDlg()
{
	// ���� ���̾�α״� �ʱ� �����Ͱ� ���� �� ���� ���⿡ ���� ����
}


// ���ÿ� ������ ����
void CArrayStackDlg::OnBnClickedButtonPush()
{
	CString strPushStackItem = NULL;
	m_edtPushStackItem.GetWindowTextW(strPushStackItem);

	if (strPushStackItem.IsEmpty() == FALSE)
	{
		CString strPopItem = NULL;

		m_edtPushStackItem.GetWindowTextW(strPopItem);				// Edit Box���� Text Reading.

		m_arrStack[m_nCurrentTopIndex + 1] = strPopItem;			// �����Ͱ� ���� ���� ���� Top�� �ƴ� Top���� Item�� �߰��Ͽ��� �ϱ⿡ TopIndex + 1 ��ġ�� �� �Է�

		m_nCurrentTopIndex++;										// �����Ͱ� �ԷµǾ����� Top�� �������� ���� �ֱٿ� �� Item�� Index�� ����Ѵ�

		RefreshStackView();											// StackView ������Ʈ�� Refresh���� �����Ͱ� �߰��� ������ �����ش�.

		m_edtPushStackItem.SetWindowTextW(_T(""));					// ���ÿ� �߰��� �����Ͱ� ���� ������Ʈ�� ����ش�.

		peek();														// ���� CurrentTop�� ������Ʈ�� �����ִ� �Լ�.

		RefreshSpace();
	}
	else
	{
		CString strErrMsg = (_T("���ÿ� ����� Item�� �Է��Ͽ� �ּ���."));
		AfxMessageBox(strErrMsg);
	}
}

// ���ÿ��� ������ ��������
void CArrayStackDlg::OnBnClickedButtonPop()
{
	RefreshPopView();												// ���ÿ��� POP�� Item�� POP View ������Ʈ�� ����ش�.
	
	m_arrStack[m_nCurrentTopIndex] = "";							// POP�� Item�� �迭���� ����ش�.

	RefreshStackView();												// POP�� ����Ǿ��⿡ Stack View ������Ʈ�� Refresh ���ش�.

	m_nCurrentTopIndex--;											// Top�� �ϳ� �ٿ���� ���� ��� Item�� ����Ű�� �Ѵ�.

	peek();															// ���� CurrentTop�� ������Ʈ�� �����ִ� �Լ�.

	RefreshSpace();
}

// ������ �����͸� �����ִ� ������Ʈ Ŭ����
void CArrayStackDlg::OnBnClickedButtonPopResultClear()
{
	m_strPopView = "";
	m_edtPopView.SetWindowTextW(m_strPopView);
}

// �Է��� �ε����� �������� �ش� �ε����� �����͸� ������
void CArrayStackDlg::OnBnClickedButtonSearch()
{
	CString strSearchItemIndex = NULL;
	m_edtSearchItemIndex.GetWindowTextW(strSearchItemIndex);

	int nSearchItemIndex = _ttoi(strSearchItemIndex);

	m_edtSearchResultView.SetWindowTextW(m_arrStack[nSearchItemIndex]);
}

// ���� Top�� �������� ������Ʈ�� �Է�
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

// ������ �� ���¸� ������Ʈ�� �Է�
void CArrayStackDlg::RefreshStackView()
{
	m_strStackView = "";
	for (int i = 0; i <= m_nCurrentTopIndex; i++)
	{
		m_strStackView.Append(m_arrStack[i]);
		m_edtStackView.SetWindowTextW(m_strStackView);
	}
}

// ���ÿ��� ������ �����͸� ������Ʈ�� �Է�
void CArrayStackDlg::RefreshPopView()
{
	m_strPopView.Append(m_arrStack[m_nCurrentTopIndex]);
	m_edtPopView.SetWindowTextW(m_strPopView);
}

// ���� Queue�� �Ѱ���, ������� ����, ����ִ� ������ ������Ʈ�� �Է�
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
