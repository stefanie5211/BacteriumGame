#pragma once
#include "Unit.h"
#include "ChapterManager.h"
#include "AttackState.h"
class PatrolState :
	public UnitState<Unit>
{
public:
	PatrolState(void);
	~PatrolState(void);

	static UnitState<Unit>* GetInstance();
	void                    Enter(Unit*);
	void                    Execute(Unit*);
	void                    Exit(Unit*);

private:
	vector<Unit*>* unitsAll; //指向所有单位的容器
	vector<Unit*>* unitsFriend;//指向友方单位的容器
	vector<Unit*>* unitsFoe;//指向敌方单位的容器
	float          bacDistance;//单位间距离
	float          minBacDistance; //最短单位距离
};

