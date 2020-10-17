#include "stdafx.h"
#include "UIThread.h"
#include "MianForm.h"


enum ThreadId
{
	kThreadUI
};



void UIThread::Init()
{
	nbase::ThreadManager::RegisterThread(kThreadUI);

	// ��ȡ��Դ·������ʼ��ȫ�ֲ���
	std::wstring theme_dir = nbase::win32::GetCurrentModuleDirectory();
	ui::GlobalManager::Startup(theme_dir + L"themes\\" , ui::CreateControlCallback(), false, L"", L"");
	// ����һ��Ĭ�ϴ�����Ӱ�ľ��д���
	MianForm* window = new MianForm();
	window->Create(NULL, MianForm::kClassName.c_str(), WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX, 0);
	window->CenterWindow();
	window->ShowWindow();
}

void UIThread::Cleanup()
{
	ui::GlobalManager::Shutdown();
	SetThreadWasQuitProperly(true);
	nbase::ThreadManager::UnregisterThread();
}