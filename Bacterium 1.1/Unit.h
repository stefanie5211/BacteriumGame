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
	virtual void              UnitSprRender(void); //精灵渲染
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
	hgeParticleSystem*  shotPar; //射击粒子效果
	hgeParticleSystem*  deathPar; //死亡粒子效果
	Position            destinationPositon; //目的地坐标
	float               speed; //移动速度
	int                 damage; //攻击力
	float               attackRange; //攻击范围
	float               watchRange; //监视范围
	Unit                *attackTarget; //攻击目标
	int                 priorNum; //优先级
	Position            nextPosition; //下一步坐标
	int                 waitTime; //碰撞等候时间
	Unit                *followUnit;//跟随对象
	float               maxDistanceToFollowUnit;//与跟随单位允许保持的最大距离
	vector<Position>    routeList; //存放移动路径
	Position            lastTarget;//最后看到攻击对象的位置
	bool                follow;//是否跟随
	Position            initialPos;//被攻击时的初始位置  被攻击后一段距离没有追上目标就自动回到初始位置
	Unit*               initiativeTarget;//主动攻击目标
	int                 attackSpeed; //攻击速度
	int                 counter; //计数器
	vector<Bullet*>     bulletsVec; //存放子弹的容器
	
	float               maxRunAfterDistance;//追随敌人的最大范围

	hgeSprite           *unitSpr; //单位纹理精灵	
	
	hgeSprite           *unitSelectedSpr;//选择单位精灵
	hgeSprite           *unitMiniMapSpr; //小地图精灵
	Position            position; //当前中心点坐
	int                 unitID; //单位ID
	int                 hp;  //单位血量
	float               radius;  //单位半径
	Camp                camp; //阵营
	State               unitState; //当前单位状态
	UnitType            unitType;
	HGE*                hge;
	StateMachine<Unit>* m_pStateMachine;
};

