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
	void                    Initialize(void);//负责初始化hge和资源
	void                    Run(void);
	void                    Serialize(void);//释放

	static bool             FrameFunc(void);
	static bool             RenderFunc(void);

private:
	HGE                     *hge;
};

