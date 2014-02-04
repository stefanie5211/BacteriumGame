#pragma once
#include "stdafx.h"
#include "Constant.h"
#include "MiniMap.h"
#include "Bullet.h"
#include "UnitState.h"
#include "StateMachine.h"

class Unit
{
public:
	Unit(void);
	~Unit(void);

	virtual const Position&  GetPosition(void)  const { return position; } 
	virtual const State&     GetUnitState(void) const { return unitState; }  
	virtual const Camp&      GetCamp(void)      const { return camp; } 
	virtual const float&     GetRadius(void)    const { return radius; }
	virtual const UnitType&  GetUnitType(void)  const { return unitType; }
	virtual const int&       GetUnitID(void)    const { return unitID; }

	virtual const Position&  GetDestinationPosition(void)     const { return destinationPositon; }
	virtual const float&     GetSpeed(void)                   const { return speed; }
	virtual const int&       GetDamage(void)                  const { return damage; }
	virtual       float&     GetAttackRange(void)                   { return attackRange; }
	virtual const float&     GetWatchRange(void)              const { return watchRange; }
	virtual       Unit*      GetAttackTarget(void)            const { return attackTarget; }
	virtual const int&       GetPriorNum(void)                const { return priorNum; }  
	virtual const Position&  GetNextPosition(void)            const { return nextPosition; }
	virtual const int&       GetWaitTime(void)                const { return waitTime; }
	virtual const Unit*      GetFollowUnit(void)              const { return followUnit; }
	virtual const float&     GetMaxDistanceToFollowUnit(void) const { return maxDistanceToFollowUnit;}
	virtual       Position   GetLastTarget()                  const { return lastTarget; }	
	virtual const bool       GetFollow()                      const { return follow; }	
	virtual const Position   GetInitialPos()                  const { return initialPos; }	
	virtual       Unit*      GetInitiativeTarget()            const { return initiativeTarget; }

	virtual void SetPosition(const Position &newPosition) { position = newPosition; }
	virtual void SetUnitState(const State &newUnitState)  { unitState = newUnitState; } 
	virtual void SetPositionX(const float &newX)          { position.x = newX; }
	virtual void SetPositionY(const float &newY)          { position.y = newY; }
	virtual void SetCamp(const Camp &newCamp)             { camp = newCamp; }
	virtual void SetRadius(const float &newRadius)        { radius = newRadius; }
	virtual void SetUnitID(const int &newUnitID)          { unitID = newUnitID; }

	virtual void SetDestinationPosition(const Position &newDestinationPosition)  { destinationPositon = newDestinationPosition; }
	virtual void SetDestinationPositionX(const float &newDestinationPositionX)   { destinationPositon.x = newDestinationPositionX; }
	virtual void SetDestinationPositionY(const float &newDestinationPositionY)   { destinationPositon.y = newDestinationPositionY; }
	virtual void SetSpeed(const float &newSpeed)                                 { speed = newSpeed; }
	virtual void SetDamage(const int &newDamage)                                 { damage = newDamage; }
	virtual void SetAttackRange(const float &newAttackRange)                     { attackRange = newAttackRange; }
	virtual void SetWatchRange(const float &newWatchRange)                       { watchRange = newWatchRange; }
	virtual void SetAttackTarget(Unit *newAttackTarget)                          { attackTarget = newAttackTarget; }
	virtual void SetPriorNum(const int &newPriorNum)                             { priorNum = newPriorNum; }
	virtual void SetNextPosition(const Position &newNextPosition)                { nextPosition = newNextPosition; }
	virtual void SetNextPositionX(const float &newX)                             { nextPosition.x = newX; }
	virtual void SetNextPositionY(const float &newY)                             { nextPosition.y = newY; }
	virtual void SetWaitTime(const int &newWaitTime)                             { waitTime = newWaitTime; }
    virtual void SetFollowUnit(Unit *newfollowUnit)                              { followUnit = newfollowUnit; }
	virtual void SetMaxDistanceToFollowUnit(float &newMaxDistanceToFollowUnit)   { maxDistanceToFollowUnit = newMaxDistanceToFollowUnit; }
	virtual void SetLastTarget(Position val)                                     { lastTarget = val; }
	virtual void SetFollow(bool val)                                             { follow = val; }
	virtual void SetInitialPos(Position val)                                     { initialPos = val; }
	virtual void SetInitiativeTarget(Unit* val)                                  { initiativeTarget = val; }
	virtual vector<Bullet*> GetBulletsVec() const                                { return bulletsVec; }
	virtual void SetBulletsVec(vector<Bullet*> val)                              { bulletsVec = val; }
	virtual hgeSprite * GetUnitSpr() const                                          { return unitSpr; }
	virtual void SetUnitSpr(hgeSprite * val)                                        { unitSpr = val; }
	virtual void              UnitSprRender(void); //������Ⱦ
	virtual void              UnitSelectedSprRender(void);
	virtual void              UnitMiniMapSprRender(void);
	virtual void              TakingDamage(const int &enemyDamage);
	virtual void              Update();
	virtual vector<Position>& RouteList(void) { return routeList; }
	virtual vector<Bullet*>&  BulletsVec(void){ return bulletsVec; }
	virtual void              Move(void);
	virtual void              Attack(Unit* attackTarget);
	StateMachine<Unit>*       GetFSM() const { return m_pStateMachine; }

protected:
	hgeParticleSystem*  shotPar; //�������Ч��
	hgeParticleSystem*  deathPar; //��������Ч��
	Position            destinationPositon; //Ŀ�ĵ�����
	float               speed; //�ƶ��ٶ�
	int                 damage; //������
	float               attackRange; //������Χ
	float               watchRange; //���ӷ�Χ
	Unit                *attackTarget; //����Ŀ��
	int                 priorNum; //���ȼ�
	Position            nextPosition; //��һ������
	int                 waitTime; //��ײ�Ⱥ�ʱ��
	Unit                *followUnit;//�������
	float               maxDistanceToFollowUnit;//����浥λ�����ֵ�������
	vector<Position>    routeList; //����ƶ�·��
	Position            lastTarget;//��󿴵����������λ��
	bool                follow;//�Ƿ����
	Position            initialPos;//������ʱ�ĳ�ʼλ��  ��������һ�ξ���û��׷��Ŀ����Զ��ص���ʼλ��
	Unit*               initiativeTarget;//��������Ŀ��
	int                 attackSpeed; //�����ٶ�
	int                 counter; //������
	vector<Bullet*>     bulletsVec; //����ӵ�������
	
	float               maxRunAfterDistance;//׷����˵����Χ

	hgeSprite           *unitSpr; //��λ������	
	
	hgeSprite           *unitSelectedSpr;//ѡ��λ����
	hgeSprite           *unitMiniMapSpr; //С��ͼ����
	Position            position; //��ǰ���ĵ���
	int                 unitID; //��λID
	int                 hp;  //��λѪ��
	float               radius;  //��λ�뾶
	Camp                camp; //��Ӫ
	State               unitState; //��ǰ��λ״̬
	UnitType            unitType;
	HGE*                hge;
	StateMachine<Unit>* m_pStateMachine;
};

