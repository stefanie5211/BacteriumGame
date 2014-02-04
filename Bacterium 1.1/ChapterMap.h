#pragma once
#include "stdafx.h"
#include "GameState.h"
class ChapterMap :
	public GameState
{
public:
	ChapterMap(void);
	~ChapterMap(void);

	GameStateConstant Frame(GameStateConstant*);
	void Render(void);
};

