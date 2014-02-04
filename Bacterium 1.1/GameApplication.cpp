#include "GameApplication.h"

GameApplication::GameApplication(void)
{
}


GameApplication::~GameApplication(void)
{
}

void GameApplication::Initialize( void )
{
	hge = hgeCreate(HGE_VERSION);

	hge->System_SetState(HGE_SHOWSPLASH,false);
	hge->System_SetState(HGE_LOGFILE, "Bacteria v1.1 Beta.log");
	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);
	hge->System_SetState(HGE_RENDERFUNC, RenderFunc);
	hge->System_SetState(HGE_TITLE, "Bacterium");
	hge->System_SetState(HGE_WINDOWED, true);
	hge->System_SetState(HGE_SCREENWIDTH, 800);
	hge->System_SetState(HGE_SCREENHEIGHT, 600);
	hge->System_SetState(HGE_SCREENBPP, 32);
	hge->System_SetState(HGE_HIDEMOUSE,true);

	if(hge->System_Initiate())
	{
		if(!ResourcesManager::GetInstance()->InitResource())
		{
			hge->System_Shutdown();
			hge->Release();
		}
	}
}

GameApplication* GameApplication::GetInstance( void )
{
	static GameApplication  *gameAppInstance;
	if(!gameAppInstance)
	{	  
		gameAppInstance = new GameApplication();
	}
	return gameAppInstance;
}

void GameApplication::Run( void )
{
	hge->System_Start();
}

void GameApplication::Serialize( void )
{
	GameManager::GetInstance()->Serialize();
	ResourcesManager::GetInstance()->Serialize();
}

bool GameApplication::FrameFunc( void )
{
    GameManager::GetInstance()->Frame();
	return false;
}

bool GameApplication::RenderFunc( void )
{
	GameManager::GetInstance()->Render();
	return false;
}

