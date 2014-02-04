#pragma once
#include "stdafx.h"
#include "ResourcesManager.h"
#include "Constant.h"
class ParticleManager
{
public:
	ParticleManager(void);
	~ParticleManager(void);

	static ParticleManager* GetInstance(void);

	hgeParticleSystem*      WeaponParBall(void);
	hgeParticleSystem*      WeaponParStar(void);
	hgeParticleSystem*      DeathParBoom(void);

private:
	hgeSprite* parSpr;
};

