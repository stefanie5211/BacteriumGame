#include "RunState.h"


RunState::RunState(void)
{
	gameMap = MANAGER_CHAPTER->GetGameMapAddress();
}


RunState::~RunState(void)
{
}

UnitState<Unit>* RunState::GetInstance()
{
	static UnitState<Unit>* instance;
	if (!instance)
	{
		instance = new RunState();
	}
	return instance;
}

void RunState::Enter( Unit* unit)
{

}

void RunState::Execute( Unit* unit)
{

	if (unit->RouteList().empty())
	{
		if (unit->GetFollowUnit())
		{
			unit->GetFSM()->ChangeState(UNIT_STATE_FOLLOW);
		}
		else
		{
			unit->GetFSM()->ChangeState(UNIT_STATE_PATROL);
		}
	}
	else
	{
		//把路径容器下移步赋给NextPosition
		Unit *nextUnit;
		unit->SetNextPosition(unit->RouteList().back()) ;
		unit->RouteList().pop_back();
		//判断下一个格子有没单位挡路，如果有将它赋给nextUnit
		if ((nextUnit = gameMap->NextPositionPassable(unit, unit->GetNextPosition())) != NULL)
		{
			//如果该单位状态为静止，直接寻路
			if (nextUnit->GetFSM()->CurrentState() == UNIT_STATE_PATROL)
			{
				unit->GetFSM()->SetCurrentState(UNIT_STATE_FINDNEWPATH);
			} 
			//如果该单位状态为移动，判断优先级，你高则让它状态设为等待 你寻路
			else if (nextUnit->GetFSM()->CurrentState() == UNIT_STATE_MOVE && unit->GetPriorNum() >= nextUnit->GetPriorNum())
			{
				nextUnit->GetFSM()->SetCurrentState(UNIT_STATE_WAIT);
				unit->GetFSM()->SetCurrentState(UNIT_STATE_FINDNEWPATH);
			}
			else
			{
				unit->GetFSM()->SetCurrentState(UNIT_STATE_WAIT);
			}
		}
		else
		{
			unit->GetFSM()->SetCurrentState(UNIT_STATE_MOVE);
		}
	}
}

void RunState::Exit( Unit* )
{

}
