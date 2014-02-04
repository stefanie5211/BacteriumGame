#pragma once
#include "stdafx.h"
#include "EventManager.h"
#include "Unit.h"
#include "Bacterium.h"
#include "GameState.h"
#include "ChapterManager.h"
#include "UISelected.h"
#include "Camera.h"
#include "GameMap.h"
class RunningGame :
	public GameState
{
public:
	RunningGame(void);
	~RunningGame(void);

	GameStateConstant Frame(GameStateConstant*);
	void              Render(void);
	void              Enter(void);
	void              Initialize(void);     //方便初始化，可删除

	void              SelectGUISetting(void);

private:
	hgeGUI            *runningGameGUI;

    EventManager      *eventManager;
	vector<Unit*>     *unitsAll;
	GameMap* gameMap;

	////////////////////////////一下仅为使用方便
	HTEXTURE      texSkill;
	HTEXTURE      texSkillBg;	
	HTEXTURE      texMouse;
	HTEXTURE      texBg;

	HEFFECT       snd;
	HEFFECT       texButtonBar;

	hgeSprite    *spMouse;
	hgeSprite    *spBar;
	hgeSprite    *spSkillBotton;	
	hgeSprite    *spSkillBottonBg;
	hgeSprite    *spBg;
	hgeFont      *fnt;

};

