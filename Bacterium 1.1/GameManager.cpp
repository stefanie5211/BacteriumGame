#include "GameManager.h"

GameManager::GameManager(void)
{
	gameState[MAINMENU] = new Main_Menu();
	gameState[START] = new Start();;
	gameState[BACTERIASTORE] = new BacteriaStore();
	gameState[OPTION] = new Option();
	gameState[NEWGAME] = new NewGame();
	gameState[LOADGAME] = new LoadGame();
	gameState[FILM] = new Film();
	gameState[CHAPTERMAP] = new ChapterMap();
	gameState[SELECTSOLDIERVIEW] = new SelectSoldierView();
	gameState[COMPOSITEVIEW] = new CompositeView();
	gameState[RUNNINGGAME] = new RunningGame();

	gameStateConstant = MAINMENU;
	hge = hgeCreate(HGE_VERSION);
}

GameManager::~GameManager(void)
{
}

void GameManager::Serialize()
{

}

void GameManager::Frame()
{
	if(gameState[gameStateConstant]->Frame(&gameStateConstant) - 12)
	{
		gameState[gameStateConstant]->Enter();
	}
}

void GameManager::Render()
{
	hge->Gfx_BeginScene();

	hge->Gfx_Clear(0);

	(ResourcesManager::GetInstance()->GetMapFont())["font1"]->printf(5, 5, HGETEXT_LEFT, "dt:%.3f\nFPS:%d (constant)", hge->Timer_GetDelta(), hge->Timer_GetFPS());

	gameState[gameStateConstant]->Render();

	hge->Gfx_EndScene();
}

GameManager* GameManager::GetInstance( void )
{
    static GameManager *gameManagerInstance;
	if(!gameManagerInstance)
	{	  
		gameManagerInstance = new GameManager();
	}
	return gameManagerInstance;
}

