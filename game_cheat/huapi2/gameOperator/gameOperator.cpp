// gameOperator.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "gameOperator.h"
#include "GameOprator.h"
#include "XmlConfig.h"
#include <boost/shared_ptr.hpp>

using namespace boost;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: ����� DLL ����� MFC DLL �Ƕ�̬���ӵģ�
//		��Ӵ� DLL �������κε���
//		MFC �ĺ������뽫 AFX_MANAGE_STATE ����ӵ�
//		�ú�������ǰ�档
//
//		����:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �˴�Ϊ��ͨ������
//		}
//
//		�˺������κ� MFC ����
//		������ÿ��������ʮ����Ҫ������ζ��
//		��������Ϊ�����еĵ�һ�����
//		���֣������������ж������������
//		������Ϊ���ǵĹ��캯���������� MFC
//		DLL ���á�
//
//		�й�������ϸ��Ϣ��
//		����� MFC ����˵�� 33 �� 58��
//

// CgameOperatorApp

BEGIN_MESSAGE_MAP(CgameOperatorApp, CWinApp)
END_MESSAGE_MAP()


// CgameOperatorApp ����

CgameOperatorApp::CgameOperatorApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CgameOperatorApp ����

CgameOperatorApp theApp;
HHOOK gHook;
shared_ptr<GameOprator> gGameOpreator;

// CgameOperatorApp ��ʼ��

BOOL CgameOperatorApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

LRESULT CALLBACK LauncherHook(int nCode,WPARAM wParam,LPARAM lParam)
{
	if (!gGameOpreator.get())
	{
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		
		gGameOpreator = shared_ptr<GameOprator>(new GameOprator());

		AfxMessageBox(_T("hook secuss"));

		XmlConfig::instance().init();
	}

	LRESULT Result=CallNextHookEx(gHook,nCode,wParam,lParam);

	return Result;
}

const LPCWSTR targetCaption = _T("����������ʰ�");

_declspec(dllexport) void WINAPI installHook()
{
	XmlConfig::instance().init();
	string test = XmlConfig::instance().getValue("game.caption");

	HWND targetHandle = FindWindow(NULL,targetCaption);
	if (!targetHandle)
	{
		AfxMessageBox(_T("can not find the game window"));
		return;
	}

	DWORD processId = ::GetWindowThreadProcessId(targetHandle, NULL);

	gHook=(HHOOK)SetWindowsHookEx(WH_KEYBOARD,(HOOKPROC)LauncherHook,
		theApp.m_hInstance,processId);

}

_declspec(dllexport) void WINAPI unInstallHook()
{
	AfxMessageBox(_T("un hook"));
	::UnhookWindowsHookEx(gHook);
}

