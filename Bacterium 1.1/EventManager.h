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
	void              SelecteUnitType(UnitType);    ///��ѡ���ֺ���GUI���浥��ĳ�ֱ����Ըñ��ֽ���ѡ��
	void              UnitsSelectedCircleRender(void);

	void              BuildUnits(int id);
	void              BulletMoveEvent(void);
	GameStateConstant WinOrFail(void);

	multimap<UnitType, Unit*>* GetUnitsSelected(void){ return &unitsSelected;}
	void              Update();
private:
	vector<Unit*>    *unitsAll; //ָ�����е�λ������
	vector<Unit*>    *unitsFriend;
	vector<Unit*>    *unitsFoe;
	vector<Unit*>    *unitsHuman;

	multimap<UnitType, Unit*>  unitsSelected; //��ű�ѡ�еĶ����λ
	Unit*                      unitSelected; //��ű�ѡ�е�һ����λ

	HGE*             hge;
	hgeRect          rect;

	GameMap *gameMap;
};

