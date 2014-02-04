#pragma once
#include "Unit.h"
#include "ChapterManager.h"
class AttackState :
	public UnitState<Unit>
{
public:
	AttackState(void);
	~AttackState(void);
	static UnitState<Unit>* GetInstance();
	void Enter(Unit*);
	void Execute(Unit*);
	void Exit(Unit*);
};



