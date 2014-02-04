#include "Unit.h"

Unit::Unit(void)
{
	m_pStateMachine = new StateMachine<Unit>(this);
}

Unit::~Unit(void)
{
}

void Unit::UnitSelectedSprRender( void )
{
	unitSelectedSpr->Render(position.x, position.y);

}

void Unit::UnitMiniMapSprRender( void )
{
	unitMiniMapSpr->Render(MINIMAP->GetMiniMapX()+(position.x/5),MINIMAP->GetMiniMapY()+(position.y/5));
}

void Unit::TakingDamage( const int &enemyDamage )
{
	hp -= enemyDamage;
	if (hp <= 0)
	{
		unitState = DEAD;
		//deathPar->FireAt(position.x, position.y);
		//deathPar->info.nEmission=10;
	}
}

void Unit::Update()
{
	m_pStateMachine->Update();
}

void Unit::Move( void )
{
	if (nextPosition.x > position.x && nextPosition.x != -1)	
		position.x += speed;
	else if(nextPosition.x < position.x && nextPosition.x != -1)
		position.x -= speed;

	if (nextPosition.y > position.y && nextPosition.y != -1)
		position.y += speed;
	else if(nextPosition.y < position.y && nextPosition.y != -1)
		position.y -= speed;
}

void Unit::UnitSprRender( void )
{
	unitSpr->Render(position.x, position.y);
	float dt=hge->Timer_GetDelta();
	if (!bulletsVec.empty())
	{
		for (vector<Bullet*>::iterator iter = bulletsVec.begin(); iter != bulletsVec.end(); ++iter)
		{
			(*iter)->GetBulletPar()->Update(dt);			
			(*iter)->GetBulletPar()->FireAt(position.x, position.y);
			(*iter)->GetBulletPar()->Render();

		}
	}
}

void Unit::Attack( Unit* attackTarget )
{
	if ((sqrt(pow((position.x - attackTarget->GetPosition().x), 2) 
		+ pow((position.y - attackTarget->GetPosition().y), 2))) < attackRange)
	{
		//shotPar->FireAt(position.x, position.y);
		//shotPar->info.nEmission=100;
		//shotPar->MoveTo(attackTarget->GetPosition().x, attackTarget->GetPosition().y);
		//attackTarget->TakingDamage(damage);
		if (counter < attackSpeed)
		{
			++counter;
		}
		else
		{
			Bullet *bullet = new BallBullet();
			bullet->SetBulletX(position.x);
			bullet->SetBulletY(position.y);
			bullet->SetBulletDX(attackTarget->GetPosition().x);
			bullet->SetBulletDY(attackTarget->GetPosition().y);
			
			bulletsVec.push_back(bullet);
			counter = 0;
		}
	}
	else
	{
		counter = 0;
	}
}
