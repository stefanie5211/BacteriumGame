#include "WaitState.h"


WaitState::WaitState(void)
{
	gameMap = MANAGER_CHAPTER->GetGameMapAddress();
}


WaitState::~WaitState(void)
{
}

UnitState<Unit>* WaitState::GetInstance()
{
	static UnitState<Unit>* instance;
	if (!instance)
	{
		instance = new WaitState();
	}
	return instance;
}

void WaitState::Enter( Unit* unit)
{
	
}

void WaitState::Execute( Unit* unit)
{
	Unit *nextUnit;
	//一直判断下一步的单位是否离开，如果是把状态设为移动
	if ((nextUnit = gameMap->NextPositionPassable(((Bacterium*)unit), ((Bacterium*)unit)->GetNextPosition())) == NULL)
	{
		unit->GetFSM()->ChangeState(UNIT_STATE_MOVE);
	}
	else
	{
		((Bacterium*)unit)->SetWaitTime(((Bacterium*)unit)->GetWaitTime()+1);
	}
	//如果等待超时，直接寻找新路径
	if (((Bacterium*)unit)->GetWaitTime() > MAX_WAIT_TIME)
	{
		unit->GetFSM()->ChangeState(UNIT_STATE_FINDNEWPATH);
	}
}

void WaitState::Exit( Unit* unit)
{

}
