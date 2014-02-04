#pragma once
#include "stdafx.h"
#include "GameManager.h"
#include "ResourcesManager.h"
class GameApplication
{
public:
	GameApplication(void);
	~GameApplication(void);

	static GameApplication* GetInstance(void);
	void                    Initialize(void);//�����ʼ��hge����Դ
	void                    Run(void);
	void                    Serialize(void);//�ͷ�

	static bool             FrameFunc(void);
	static bool             RenderFunc(void);

private:
	HGE                     *hge;
};

