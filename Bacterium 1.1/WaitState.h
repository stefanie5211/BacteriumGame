#pragma once
#include "UnitState.h"
#include "ChapterManager.h"
#include "GameMap.h"
#include "MoveState.h"
#include "FindNewPathState.h"
class WaitState :
	public UnitState<Unit>
{
public:
	WaitState(void);
	~WaitState(void);
	static UnitState<Unit>* GetInstance();
	void Enter(Unit*);
	void Execute(Unit*);
	void Exit(Unit*);

private:
	GameMap *gameMap;
};

