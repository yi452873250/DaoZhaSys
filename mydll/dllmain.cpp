// dllmain.cpp : ���� DLL Ӧ�ó������ڵ㡣
#include "stdafx.h"
static DWORD WINAPI AutoClick(LPVOID lpParam)
{
	HWND fd = FindWindow(L"CentralManagementSystem5.2", L"�ۺϼ���������");
	if (fd == NULL)
	{
		MessageBox(fd, L"��ʧ��", NULL, NULL);
		return 0;
	}
	else
	{
		SetForegroundWindow(fd);
		HWND fdchild1 = FindWindowEx(fd, NULL, NULL, L"��ƵѲ��");
		HWND fdchild2 = FindWindowEx(fdchild1, NULL, L"AfxWnd90", L"PlayViewWnd");
		HWND fdchild3 = FindWindowEx(fdchild2, NULL, L"AfxWnd90", L"PlayViewToolbar");
		//EnumChildWindows(fdchild3, FindChilds, NULL);
		HWND fdchild = FindWindowEx(fdchild3, NULL, L"Button", NULL);
		HWND fdchildnext = GetWindow(fdchild, GW_HWNDNEXT);
		HWND fdchildnext1 = GetWindow(fdchildnext, GW_HWNDNEXT);
		if (fdchildnext1 == NULL)
		{
			MessageBox(fd, L"��ȡ�Ӱ�ťʧ��", NULL, NULL);
			return 0;
		}
		else
		{
			Sleep(1000);
			while (1)
			{
				
				SendMessage(fdchildnext1, WM_LBUTTONDOWN, NULL, NULL); 
				Sleep(100);
				SendMessage(fdchildnext1, WM_LBUTTONUP, NULL, NULL);
				Sleep(60000);
			}
		}
	}
	return 0;
}
void clickbutton()
{
	CreateThread(0, 0, AutoClick, NULL, 0, 0);
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		clickbutton();
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

