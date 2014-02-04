#pragma once
#include "stdafx.h"
#include "GameState.h"
class Film :
	public GameState
{
public:
	Film(void);
	~Film(void);

	GameStateConstant Frame(GameStateConstant*);
	void              Render(void);
};

