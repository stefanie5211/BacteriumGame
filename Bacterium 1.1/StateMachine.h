#pragma once
template <class entity_type>
class StateMachine
{

private:
	entity_type*            m_pOwner;
	UnitState<entity_type>* m_pCurrentState;
	UnitState<entity_type>* m_pPreviousState;
	UnitState<entity_type>* m_pGlobalState;
	
public:
	StateMachine(entity_type* m_pOwner):m_pOwner(m_pOwner),
		                                m_pCurrentState(NULL),
										m_pPreviousState(NULL),
										m_pGlobalState(NULL){}
	~StateMachine(void);

	UnitState<entity_type>* CurrentState()   const {return m_pCurrentState;}
	UnitState<entity_type>* GlobalState()    const {return m_pGlobalState;}
	UnitState<entity_type>* PreviousState()  const {return m_pPreviousState;}

	void SetCurrentState(UnitState<entity_type>* s)  {m_pCurrentState = s;}
	void SetGlobalState(UnitState<entity_type>* s)   {m_pGlobalState = s;}
	void SetPreviousState(UnitState<entity_type>* s) {m_pPreviousState = s;} 

	void Update() const
	{
		if (m_pGlobalState)
			m_pGlobalState->Execute(m_pOwner);
		if (m_pCurrentState)
			m_pCurrentState->Execute(m_pOwner);
	}

	void ChangeState(UnitState<entity_type>* pNewState)
	{
		m_pPreviousState = m_pCurrentState;
		m_pCurrentState->Exit(m_pOwner);
		m_pCurrentState = pNewState;
		m_pCurrentState->Enter(m_pOwner);
	}

	void ReverToPreviousState()
	{
		ChangeState(m_pPreviousState);
	}
};

