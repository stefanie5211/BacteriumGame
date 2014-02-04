#pragma once
#include "stdafx.h"
#include "GameState.h"


class Option : public GameState
{
public:
	Option(void);
	~Option(void);
	GameStateConstant Frame(GameStateConstant*);
	void Render(void);
	void Enter(void);

private:
	hgeGUI           *optionGUI;

	HTEXTURE          texMouse;
	hgeSprite        *spMouse;

	hgeFont          *fnt;
	HEFFECT           snd;

	hgeFont          *fntVol;
};

