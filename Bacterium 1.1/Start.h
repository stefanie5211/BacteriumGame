#pragma once
#include "gamestate.h"


class Start :
	public GameState
{
public:
	Start(void);
	~Start(void);

	GameStateConstant Frame(GameStateConstant*);
	void              Render(void);
	void              Enter(void);

private:
	hgeGUI           *startGUI;
	HEFFECT           snd;
	HTEXTURE          texMouse;                 //方便己用
	hgeFont          *fnt;
	hgeSprite        *spMouse;                //方便己用
	
};

