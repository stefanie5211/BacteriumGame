#include "ParticleManager.h"


ParticleManager::ParticleManager(void)
{
}


ParticleManager::~ParticleManager(void)
{
}

ParticleManager* ParticleManager::GetInstance( void )
{
	static ParticleManager *particleManagerInstance;
	if (!particleManagerInstance)
	{
		particleManagerInstance = new ParticleManager();
	}
	return particleManagerInstance;
}

hgeParticleSystem* ParticleManager::WeaponParBall( void )
{
	parSpr = new hgeSprite((MANAGER_RESOURCES->GetMapTexture())["particles"], 64.0, 0.0, 32.0, 32.0);
	parSpr->SetHotSpot(16.0, 16.0);
	return (new hgeParticleSystem("Ball.psi", parSpr));
}

hgeParticleSystem* ParticleManager::WeaponParStar( void )
{
	parSpr = new hgeSprite((MANAGER_RESOURCES->GetMapTexture())["particles"], 0.0, 0.0, 32.0, 32.0);
	parSpr->SetHotSpot(16.0, 16.0);
	return (new hgeParticleSystem("Star.psi", parSpr));
}

hgeParticleSystem* ParticleManager::DeathParBoom( void )
{
	parSpr = new hgeSprite((MANAGER_RESOURCES->GetMapTexture())["particles"], 0.0, 0.0, 32.0, 32.0);
	parSpr->SetHotSpot(16.0, 16.0);
	return (new hgeParticleSystem("Bomb.psi", parSpr));
}