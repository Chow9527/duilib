#pragma once
#include "stdafx.h"

class UIThread : public nbase::FrameworkThread
{
public:
	UIThread() : nbase::FrameworkThread("MainThread") {}
	virtual ~UIThread() {}
private:
	/**
	* �麯������ʼ�����߳�
	* @return void	�޷���ֵ
	*/
	virtual void Init() override;

	/**
	* �麯�������߳��˳�ʱ����һЩ������
	* @return void	�޷���ֵ
	*/
	virtual void Cleanup() override;
};

