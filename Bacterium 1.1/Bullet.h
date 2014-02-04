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
	hgeParticleSystem  *bulletPar; //�ӵ�����Ч��
	float              bulletX; //�ӵ���ǰX����
	float              bulletY; //�ӵ���ǰY����
	float              bulletDX; //�ӵ�Ŀ�ĵ�X����
	float              bulletDY; //�ӵ�Ŀ�ĵ�Y����

	float              bulletMoveSpeed; //�ӵ��ƶ��ٶ�
	float              bulletMoveToTargetDistance; //�ӵ��ƶ���·��(��������λ�뱻������λ�����)
	float              bulletMoveSpeedX; //�ӵ��ƶ��ٶ�X����ٶ�
	float              bulletMoveSpeedY; //�ӵ��ƶ��ٶ�Y����ٶ�
	bool               xCanMove;//�ж�X���Ƿ����ƶ�(��X�����Ƿ��ѵ���Ŀ���)
	bool               yCanMove;//�ж�Y���Ƿ����ƶ�(��Y�����Ƿ��ѵ���Ŀ���)
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

