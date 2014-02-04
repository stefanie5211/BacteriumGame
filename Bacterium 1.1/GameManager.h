#pragma once
#include "stdafx.h"

#include "CompositeView.h"
#include "Film.h"
#include "Main_Menu.h"
#include "BacteriaStore.h"
#include "Option.h"
#include "Start.h"
#include "NewGame.h"
#include "LoadGame.h"
#include "ChapterMap.h"
#include "RunningGame.h"
#include "SelectSoldierView.h"

class GameManager
{
public:
	GameManager(void);
	~GameManager(void);

	static GameManager*      GetInstance(void);
	void                     Serialize();

	const GameStateConstant& GetGameStateConstant(void) const { return gameStateConstant; } 
	void                     SetGameStateConstant(const GameStateConstant& newGameStateConstant) { gameStateConstant = newGameStateConstant; } 
	void                     Frame();
	void                     Render();

private:
     GameState               *gameState[11];
     GameStateConstant       gameStateConstant;
	 HGE                     *hge;
};

