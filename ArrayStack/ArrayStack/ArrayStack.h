
// ArrayStack.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CArrayStackApp:
// �� Ŭ������ ������ ���ؼ��� ArrayStack.cpp�� �����Ͻʽÿ�.
//

class CArrayStackApp : public CWinApp
{
public:
	CArrayStackApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CArrayStackApp theApp;