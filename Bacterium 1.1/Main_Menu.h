#pragma once
#include "stdafx.h"
#include "gamestate.h"


class Main_Menu :
	public GameState
{
public:
	Main_Menu(void);
	~Main_Menu(void);

	GameStateConstant Frame(GameStateConstant*);
	void              Render(void);
	void              Enter(void);

private:
	hgeGUI        *mainMenuGUI;	

	hgeFont       *fnt;
	HEFFECT        snd;	

	hgeSprite      *spMouse;  
	HTEXTURE        tex;
};

