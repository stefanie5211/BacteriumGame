#include "FollowState.h"


FollowState::FollowState(void)
{
}


FollowState::~FollowState(void)
{
}

UnitState<Unit>* FollowState::GetInstance()
{
	static UnitState<Unit>* instance;
	if (!instance)
	{
		instance = new FollowState();
	}
	return instance;
}

void FollowState::Enter( Unit* unit)
{

}

void FollowState::Execute( Unit* unit )
{
	Position followUnitPosition = unit->GetFollowUnit()->GetPosition();
	Position unitPosition = unit->GetPosition();
	const float pi = 3.14f;
	if (sqrt(pow(followUnitPosition.x - unitPosition.x, 2) + pow(followUnitPosition.y - unitPosition.y, 2)) > unit->GetMaxDistanceToFollowUnit()||(unit->GetInitiativeTarget()&&(sqrt(pow(followUnitPosition.x - unitPosition.x, 2) + pow(followUnitPosition.y - unitPosition.y, 2)) > unit->GetAttackRange())))
	{
		if (followUnitPosition.x > unitPosition.x)
		{
			float tanX = (followUnitPosition.y - unitPosition.y)/(followUnitPosition.x - unitPosition.x);
			if (tanX <= tan((-67.5)*pi/180))
			{
				unit->SetNextPositionX(unitPosition.x);
				unit->SetNextPositionY(unitPosition.y - GRID_LENGTH);
			}
			else if(tanX > tan((-67.5)*pi/180) && tanX <= tan((-22.5)*pi/180))
			{
				unit->SetNextPositionX(unitPosition.x + GRID_LENGTH);
				unit->SetNextPositionY(unitPosition.y - GRID_LENGTH);
			}
			else if(tanX > tan((-22.5)*pi/180) && tanX <= tan((22.5)*pi/180))
			{
				unit->SetNextPositionX(unitPosition.x + GRID_LENGTH);
				unit->SetNextPositionY(unitPosition.y);
			}
			else if(tanX > tan((22.5)*pi/180) && tanX <= tan((67.5)*pi/180))
			{
				unit->SetNextPositionX(unitPosition.x + GRID_LENGTH);
				unit->SetNextPositionY(unitPosition.y + GRID_LENGTH);
			}
			else 
			{
				unit->SetNextPositionX(unitPosition.x);
				unit->SetNextPositionY(unitPosition.y + GRID_LENGTH);
			}
		}
		else if (followUnitPosition.x < unitPosition.x)
		{
			float tanX = (followUnitPosition.y - unitPosition.y)/(followUnitPosition.x - unitPosition.x);
			if (tanX <= tan((-67.5)*pi/180))
			{
				unit->SetNextPositionX(unitPosition.x);
				unit->SetNextPositionY(unitPosition.y + GRID_LENGTH);
			}
			else if(tanX > tan((-67.5)*pi/180) && tanX <= tan((-22.5)*pi/180))
			{
				unit->SetNextPositionX(unitPosition.x - GRID_LENGTH);
				unit->SetNextPositionY(unitPosition.y + GRID_LENGTH);
			}
			else if(tanX > tan((-22.5)*pi/180) && tanX <= tan((22.5)*pi/180))
			{
				unit->SetNextPositionX(unitPosition.x - GRID_LENGTH);
				unit->SetNextPositionY(unitPosition.y);
			}
			else if(tanX > tan((22.5)*pi/180) && tanX <= tan((67.5)*pi/180))
			{
				unit->SetNextPositionX(unitPosition.x - GRID_LENGTH);
				unit->SetNextPositionY(unitPosition.y - GRID_LENGTH);
			}
			else 
			{
				unit->SetNextPositionX(unitPosition.x);
				unit->SetNextPositionY(unitPosition.y - GRID_LENGTH);
			}
		}
		else
		{
			if (followUnitPosition.y > unitPosition.y)
			{
				unit->SetNextPositionX(unitPosition.x);
				unit->SetNextPositionY(unitPosition.y + GRID_LENGTH);
			}
			else
			{
				unit->SetNextPositionX(unitPosition.x);
				unit->SetNextPositionY(unitPosition.y - GRID_LENGTH);
			}
		}
		unit->RouteList().push_back(unit->GetNextPosition());
		unit->SetDestinationPosition(followUnitPosition);
		unit->GetFSM()->ChangeState(UNIT_STATE_RUN);
	}
}

void FollowState::Exit( Unit* unit)
{

}
