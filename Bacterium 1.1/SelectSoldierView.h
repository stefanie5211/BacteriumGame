#pragma once
#include "stdafx.h"
#include "GameState.h"

class SelectSoldierView : public GameState
{
public:
	SelectSoldierView(void);
	~SelectSoldierView(void);
	GameStateConstant Frame(GameStateConstant*);
	void Render(void);
	void Enter(void);
private:
	hgeGUI            *selectSoldierGUI;

	HTEXTURE          texMouse;
	hgeSprite        *spMouse;

	hgeFont          *fnt;
	HEFFECT           snd;

	HTEXTURE        backGround;
	hgeSprite      *spBackGround;

	HTEXTURE        beSelectFrame;//备选框
	hgeSprite      *spbeSelectFrame;

	HTEXTURE        SelectedFrame;
	hgeSprite      *spSelectedFrame;//已选框体

};

