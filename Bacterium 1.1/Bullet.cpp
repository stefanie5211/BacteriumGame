#include "Bullet.h"


Bullet::Bullet(void)
{
	xCanMove = true;
	yCanMove = true;
}


Bullet::~Bullet(void)
{
}

bool Bullet::BulletMove( void )
{
	bulletMoveToTargetDistance = sqrt(pow(bulletDX - bulletX, 2) + pow(bulletDY - bulletY, 2));
	bulletMoveSpeedX = ((bulletDX - bulletX)/bulletMoveToTargetDistance)*bulletMoveSpeed;
	bulletMoveSpeedY = ((bulletDY - bulletY)/bulletMoveToTargetDistance)*bulletMoveSpeed;

	if (fabs(bulletX - bulletDX) < bulletMoveSpeed)
	{
		xCanMove = false;
	}
	else
	{
		bulletX += bulletMoveSpeedX;
	}

	if (fabs(bulletY -bulletDY) < bulletMoveSpeed)
	{
		yCanMove = false;
	}
	else
	{
		bulletY += bulletMoveSpeedY;
	}

	if (!xCanMove && !yCanMove)
	{
		return false;
	}

	bulletPar->MoveTo(bulletX, bulletY);

	return true;
}