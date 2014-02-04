#pragma once
#include "Unit.h"
#include "ChapterManager.h"
#include "RunState.h"
#include "FollowState.h"
class MoveState :
	public UnitState<Unit>
{
public:
	MoveState(void);
	~MoveState(void);
	static UnitState<Unit>* GetInstance();
	void Enter(Unit* unit);
	void Execute(Unit* unit);
	void Exit(Unit* unit);
};

