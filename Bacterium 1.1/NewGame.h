#pragma once
#include "stdafx.h"
#include "GameState.h"
class NewGame :
	public GameState
{
public:
	NewGame(void);
	~NewGame(void);

	GameStateConstant Frame(GameStateConstant*);
	void              Render(void);
};

