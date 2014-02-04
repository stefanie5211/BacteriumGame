#pragma once
#include "UnitState.h"
#include "ChapterManager.h"
#include "Constant.h"
#include "RunState.h"
class FollowState :
	public UnitState<Unit>
{
public:
	FollowState(void);
	~FollowState(void);
	static UnitState<Unit>* GetInstance();
	void Enter(Unit*);
	void Execute(Unit*);
	void Exit(Unit*);
};

