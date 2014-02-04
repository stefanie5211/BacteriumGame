#pragma once
#include "UnitState.h"
#include "ChapterManager.h"
#include "FollowState.h"
#include "GameMap.h"
#include "MoveState.h"
#include "FindNewPathState.h"
#include "WaitState.h"
class RunState :
	public UnitState<Unit>
{
public:
	RunState(void);
	~RunState(void);
	static UnitState<Unit>* GetInstance();
	void Enter(Unit*);
	void Execute(Unit*);
	void Exit(Unit*);

private:
	GameMap *gameMap;
};

