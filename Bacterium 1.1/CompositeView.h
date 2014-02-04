#pragma once
#include "stdafx.h"
#include "GameState.h"
#include "Store.h"
#include "CompositeFrame.h"
/********************************
* DNA  ��ť��ID�Ų����������ã� *
* ����ݺϳɹ�ʽ                *
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
	//void              Load(void);              //���㼺��

private:
	hgeGUI            *compositeViewGUI;       ///����gui

	CompositeFrame    *pLCompositeFrame;
	CompositeFrame    *pRCompositeFrame;        

	bool              leave;
	
	hgeFont           *fnt;
	hgeSprite         *spMouse;                //���㼺��
	HTEXTURE          texMouse;                 //���㼺��
	HEFFECT           snd;

	HTEXTURE          texPlus;
	HTEXTURE          texButtonBg;

	hgeSprite        *spPlus;
	hgeSprite        *spButtonBg;	
};

