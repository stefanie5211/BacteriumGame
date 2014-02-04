#pragma once
#include "stdafx.h"
#include "ParticleManager.h"
#include "Constant.h"
class Bullet
{
public:
	Bullet(void);
	~Bullet(void);

	virtual       hgeParticleSystem* GetBulletPar(void)    const { return bulletPar; }
	virtual const float              GetBulletX(void)      const { return bulletX; }
	virtual const float              GetBulletY(void)      const { return bulletY; }
	virtual const float              GetBulletDX(void)      const { return bulletDX; }
	virtual const float              GetBulletDY(void)      const { return bulletDY; }

	virtual void SetBulletPar(hgeParticleSystem *newBulletSpr)   { bulletPar = newBulletSpr; }
	virtual void SetBulletX(const float &newBulletX)             { bulletX = newBulletX; }
	virtual void SetBulletY(const float &newBulletY)             { bulletY = newBulletY; }
	virtual void SetBulletDX(const float &newBulletDX)             { bulletDX = newBulletDX; }
	virtual void SetBulletDY(const float &newBulletDY)             { bulletDY = newBulletDY; }

	virtual bool BulletMove(void);

protected:
	hgeParticleSystem  *bulletPar; //子弹粒子效果
	float              bulletX; //子弹当前X坐标
	float              bulletY; //子弹当前Y坐标
	float              bulletDX; //子弹目的地X坐标
	float              bulletDY; //子弹目的地Y坐标

	float              bulletMoveSpeed; //子弹移动速度
	float              bulletMoveToTargetDistance; //子弹移动总路程(即攻击单位与被攻击单位间距离)
	float              bulletMoveSpeedX; //子弹移动速度X轴分速度
	float              bulletMoveSpeedY; //子弹移动速度Y轴分速度
	bool               xCanMove;//判断X轴是否能移动(即X坐标是否已到达目标点)
	bool               yCanMove;//判断Y轴是否能移动(即Y坐标是否已到达目标点)
};

class BallBullet : 
	public Bullet
{
public:
	BallBullet(void) 
	{ 
		bulletPar =  MANAGER_PARTICLE->WeaponParBall();
		bulletMoveSpeed = 0.1f;
	}
	~BallBullet(void);
};

class StarBullet : 
	public Bullet
{
public:
	StarBullet(void) 
	{ 
		bulletPar =  MANAGER_PARTICLE->WeaponParStar(); 
		bulletMoveSpeed = 0.1f;
	}
	~StarBullet(void);
};

