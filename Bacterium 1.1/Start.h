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
	HTEXTURE          texMouse;                 //���㼺��
	hgeFont          *fnt;
	hgeSprite        *spMouse;                //���㼺��
	
};

