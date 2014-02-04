#include "MoveState.h"


MoveState::MoveState(void)
{

}


MoveState::~MoveState(void)
{
}

UnitState<Unit>* MoveState::GetInstance()
{
	static UnitState<Unit>* instance;
	if (!instance)
	{
		instance = new MoveState();
	}
	return instance;
}

void MoveState::Enter( Unit* unit )
{

}

void MoveState::Execute( Unit* unit )
{
	if (((Bacterium*)unit)->GetNextPosition().x == -1 && ((Bacterium*)unit)->GetNextPosition().y == -1)
	{
		unit->GetFSM()->ChangeState(UNIT_STATE_RUN);
		((Bacterium*)unit)->SetWaitTime(0);
	}

	((Bacterium*)unit)->Move();
	if (((unit)->GetInitiativeTarget()!=NULL&&(sqrt(pow(((unit)->GetFollowUnit()->GetPosition().x-unit->GetPosition().x),2)+ pow(((unit)->GetFollowUnit()->GetPosition().y-unit->GetPosition().y),2)))<=((unit)->GetAttackRange())))	
	{
		(unit)->RouteList().clear();
		unit->GetFSM()->ChangeState(UNIT_STATE_FOLLOW);
	}

	//浮点数精度有限，所以判断的时候取范围值（即加0.2只加了0.199999）
	if (abs(((Bacterium*)unit)->GetNextPosition().x - unit->GetPosition().x) <= 0.001)
	{
		unit->SetPositionX(((Bacterium*)unit)->GetNextPosition().x);
		((Bacterium*)unit)->SetNextPositionX(-1);
	}
	if (abs(((Bacterium*)unit)->GetNextPosition().y - unit->GetPosition().y) <= 0.001)
	{
		unit->SetPositionY(((Bacterium*)unit)->GetNextPosition().y);
		((Bacterium*)unit)->SetNextPositionY(-1);
	}
}

void MoveState::Exit( Unit* unit )
{

}
