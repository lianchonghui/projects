
// 00_02_04_MFCsystem_01.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy00_02_04_MFCsystem_01App: 
// �йش����ʵ�֣������ 00_02_04_MFCsystem_01.cpp
//

class CMy00_02_04_MFCsystem_01App : public CWinApp
{
public:
	CMy00_02_04_MFCsystem_01App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy00_02_04_MFCsystem_01App theApp;