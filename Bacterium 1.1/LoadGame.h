#pragma once
#include "stdafx.h"
#include "GameState.h"
#include "ChapterManager.h"
class LoadGame :
	public GameState
{
public:
	LoadGame(void);
	~LoadGame(void);

	GameStateConstant Frame(GameStateConstant*);
	void              Render(void);

private:
	int chapterNum;
};

