#pragma once
template <class entity_type>
class UnitState
{
public:
    /*UnitState(void);*/
	/*~UnitState(void);*/

	virtual void Enter(entity_type*)=0;
	virtual void Execute(entity_type*)=0;
	virtual void Exit(entity_type*)=0;
};

