#include "PatrolState.h"


PatrolState::PatrolState(void)
{
	unitsAll    = MANAGER_CHAPTER->GetUnitsAllAddress();
	unitsFriend = MANAGER_CHAPTER->GetUnitsFriendAddress();
	unitsFoe    = MANAGER_CHAPTER->GetUnitsFoeAddress();
}

PatrolState::~PatrolState(void)
{
}

UnitState<Unit>* PatrolState::GetInstance()
{
	static UnitState<Unit>* instance ;
	if (!instance)
	{
		instance = new PatrolState();
	}
	return instance;
}

void PatrolState::Enter( Unit* )
{

}

void PatrolState::Execute( Unit* unit)
{
	Unit* attackTarget = NULL;
    minBacDistance =unit->GetAttackRange();
	for (vector<Unit*>::iterator iterB = unitsFoe->begin(); iterB != unitsFoe->end(); ++iterB)
	{
	    bacDistance = sqrt(pow((((Bacterium*)(*iterB))->GetPosition().x - unit->GetPosition().x), 2) 
			+ pow((((Bacterium*)(*iterB))->GetPosition().y - unit->GetPosition().y), 2));

		//判断攻击范围内最近的单位，并将其设为攻击目标
		if (bacDistance <= minBacDistance && ((Bacterium*)(*iterB))->GetUnitState() != DEAD)
		{
			minBacDistance = bacDistance;
			attackTarget = (Bacterium*)(*iterB);
		}
	}
	if (attackTarget != NULL )
	{
		((Bacterium*)unit)->SetAttackTarget(attackTarget);
		unit->GetFSM()->ChangeState(UNIT_STATE_ATTACK);
	}
}

void PatrolState::Exit( Unit* )
{
	
}
