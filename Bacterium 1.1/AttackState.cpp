#include "AttackState.h"

AttackState::AttackState( void )
{
}

AttackState::~AttackState(void)
{
}

UnitState<Unit>* AttackState::GetInstance()
{
	static UnitState<Unit>* instance;
	if (!instance)
	{
		instance = new AttackState();
	}
	return instance;
}

void AttackState::Enter( Unit* bac)
{

}

void AttackState::Execute( Unit* bac)
{
	if (bac->GetInitiativeTarget())
	{
		bac->Attack(bac->GetInitiativeTarget());
	}
	else if (bac->GetAttackTarget())
	{
		bac->Attack(bac->GetAttackTarget());
	}
	else
		bac->GetFSM()->ChangeState(UNIT_STATE_PATROL);
	
}

void AttackState::Exit( Unit* bac)
{

}


