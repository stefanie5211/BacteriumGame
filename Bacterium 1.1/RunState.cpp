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
		//��·���������Ʋ�����NextPosition
		Unit *nextUnit;
		unit->SetNextPosition(unit->RouteList().back()) ;
		unit->RouteList().pop_back();
		//�ж���һ��������û��λ��·������н�������nextUnit
		if ((nextUnit = gameMap->NextPositionPassable(unit, unit->GetNextPosition())) != NULL)
		{
			//����õ�λ״̬Ϊ��ֹ��ֱ��Ѱ·
			if (nextUnit->GetFSM()->CurrentState() == UNIT_STATE_PATROL)
			{
				unit->GetFSM()->SetCurrentState(UNIT_STATE_FINDNEWPATH);
			} 
			//����õ�λ״̬Ϊ�ƶ����ж����ȼ������������״̬��Ϊ�ȴ� ��Ѱ·
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
