// gameOperator.h : gameOperator DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include "HookOpreator.h"



// CgameOperatorApp
// �йش���ʵ�ֵ���Ϣ������� gameOperator.cpp
//


class CgameOperatorApp : public CWinApp
{
public:
	CgameOperatorApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
