#pragma once
#include "Unit.h"
#include "ChapterManager.h"
#include "AttackState.h"
class PatrolState :
	public UnitState<Unit>
{
public:
	PatrolState(void);
	~PatrolState(void);

	static UnitState<Unit>* GetInstance();
	void                    Enter(Unit*);
	void                    Execute(Unit*);
	void                    Exit(Unit*);

private:
	vector<Unit*>* unitsAll; //ָ�����е�λ������
	vector<Unit*>* unitsFriend;//ָ���ѷ���λ������
	vector<Unit*>* unitsFoe;//ָ��з���λ������
	float          bacDistance;//��λ�����
	float          minBacDistance; //��̵�λ����
};

