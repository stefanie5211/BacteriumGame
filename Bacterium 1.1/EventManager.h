#pragma once
#include "stdafx.h"
#include "Mouse.h"
#include "Bacterium.h"
#include "Unit.h"
#include "Constant.h"
#include "ChapterManager.h"
#include "Camera.h"
#include "FindNewPathState.h"

class EventManager
{
public:
	EventManager(void);
	~EventManager(void);

	void              LeftClickEvent(void);
	void              RightClickEvent(void);
	void              MouseFrameEvent(void);
	void              MouseFrameRender(void);
	void              MouseMoveEvent(void);
	void              MouseOverUnitEvent(void); 
	void              UnitDieEvent(void);
	//void              UnitAttackEvent(void);
	void              SelecteUnitType(UnitType);    ///括选兵种后，在GUI界面单击某种兵，对该兵种进行选择
	void              UnitsSelectedCircleRender(void);

	void              BuildUnits(int id);
	void              BulletMoveEvent(void);
	GameStateConstant WinOrFail(void);

	multimap<UnitType, Unit*>* GetUnitsSelected(void){ return &unitsSelected;}
	void              Update();
private:
	vector<Unit*>    *unitsAll; //指向所有单位的容器
	vector<Unit*>    *unitsFriend;
	vector<Unit*>    *unitsFoe;
	vector<Unit*>    *unitsHuman;

	multimap<UnitType, Unit*>  unitsSelected; //存放被选中的多个单位
	Unit*                      unitSelected; //存放被选中的一个单位

	HGE*             hge;
	hgeRect          rect;

	GameMap *gameMap;
};

