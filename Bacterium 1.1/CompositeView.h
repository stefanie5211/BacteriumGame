#pragma once
#include "stdafx.h"
#include "GameState.h"
#include "Store.h"
#include "CompositeFrame.h"
/********************************
* DNA  按钮的ID号不能随意设置， *
* 需根据合成公式                *
********************************/



class CompositeView :
	public GameState
{
public:
	CompositeView(void);
	~CompositeView(void);

	void Initialize(void);

	GameStateConstant Frame(GameStateConstant*);
	void              Render(void);
	void              Enter(void);
	void              CompositeTest(void);
	void              CompositeNewBtm(void);
	//void              Load(void);              //方便己用

private:
	hgeGUI            *compositeViewGUI;       ///该类gui

	CompositeFrame    *pLCompositeFrame;
	CompositeFrame    *pRCompositeFrame;        

	bool              leave;
	
	hgeFont           *fnt;
	hgeSprite         *spMouse;                //方便己用
	HTEXTURE          texMouse;                 //方便己用
	HEFFECT           snd;

	HTEXTURE          texPlus;
	HTEXTURE          texButtonBg;

	hgeSprite        *spPlus;
	hgeSprite        *spButtonBg;	
};

