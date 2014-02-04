#pragma once
#include "stdafx.h"
#include "GameState.h"
#include "Store.h"
/******************************************
*1、由关卡读取器负责对兵种容器进行初始化  *
*2、Initialize方法初始化GUI,增添GUI控件   *
*3、AddBacteria方法负责添加新兵种         *
******************************************/
class BacteriaStore :
	public GameState
{
	typedef hgeGUIBacteriaMenu Bacteria;
	friend  class Application;

public:
	BacteriaStore(void);
	~BacteriaStore(void);

	void Initialize(void);
	void Servicelize(void);
	void AddBacteria(Bacteria*);

	GameStateConstant Frame(GameStateConstant*);
	void              Render(void);
	void              Enter(void);

private:	
	hgeGUI            *bacteriaStoreGUI;        ///该类gui
	vector<Bacteria*>  vectPiece_kinds;         ///兵种库

	HEFFECT            snd;

	hgeFont          *fnt;


	hgeSprite       *spMouse;                //方便己用
	HTEXTURE         texMouse;                 //方便己用
};

