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
	//һֱ�ж���һ���ĵ�λ�Ƿ��뿪������ǰ�״̬��Ϊ�ƶ�
	if ((nextUnit = gameMap->NextPositionPassable(((Bacterium*)unit), ((Bacterium*)unit)->GetNextPosition())) == NULL)
	{
		unit->GetFSM()->ChangeState(UNIT_STATE_MOVE);
	}
	else
	{
		((Bacterium*)unit)->SetWaitTime(((Bacterium*)unit)->GetWaitTime()+1);
	}
	//����ȴ���ʱ��ֱ��Ѱ����·��
	if (((Bacterium*)unit)->GetWaitTime() > MAX_WAIT_TIME)
	{
		unit->GetFSM()->ChangeState(UNIT_STATE_FINDNEWPATH);
	}
}

void WaitState::Exit( Unit* unit)
{

}
