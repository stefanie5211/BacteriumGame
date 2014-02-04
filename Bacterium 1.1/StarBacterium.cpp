#include "StarBacterium.h"


StarBacterium::StarBacterium(void)
{
}

StarBacterium::StarBacterium( 
	const int &initialUnitID,
	const float &initialX, 
	const float &initialY, 
	const Camp &initialCamp, 
	const HTEXTURE &initialUnitTex,
	const HTEXTURE &initialSelectedTex, 
	const HTEXTURE &initialPointTex,
	hgeParticleSystem *initialShotPar, 
	hgeParticleSystem *initialDeathPar
	)
{
	unitID = initialUnitID;
	unitType = STARBACTERIUM;
	position.x = initialX;
	position.y = initialY;
	camp = initialCamp;
	speed = 0.2f;
	damage = 5; 
	hp = 20000; 
	attackRange = 100.0f;
	radius = 16.0f;
	priorNum = 1;
	shotPar = initialShotPar;
	deathPar = initialDeathPar;
	counter = 0;
	attackTarget = NULL;
	initiativeTarget = NULL;
	followUnit = NULL;
	attackSpeed=500;
	maxDistanceToFollowUnit = 160.0f;
	unitSpr =  new hgeSprite(initialUnitTex, 32.0, 32.0, 32.0, 32.0);
	unitSpr->SetHotSpot(16.0f, 16.0f);
	unitSpr->SetBlendMode(BLEND_COLORMUL | BLEND_ALPHAADD | BLEND_ZWRITE);
	unitSelectedSpr = new hgeSprite(initialSelectedTex, 0, 0, 47.0, 47.0);
	unitSelectedSpr->SetHotSpot(23.5f, 23.5f);
	unitSelectedSpr->SetBlendMode(BLEND_COLORMUL | BLEND_ALPHAADD | BLEND_ZWRITE);
	unitMiniMapSpr = new hgeSprite(initialPointTex, 0, 0, 4, 4);
	unitMiniMapSpr->SetHotSpot(2.0f, 2.0f);
	unitMiniMapSpr->SetBlendMode(BLEND_COLORMUL | BLEND_ALPHAADD | BLEND_ZWRITE);
	for(int i=0;i<4;i++)
	{			
		unitSpr->SetZ(0.5f, i);

		if (camp == FRIEND)
		{
			unitSpr->SetColor(0xFFFF0000, i);
		}
		else if (camp == FOE)
		{
			unitSpr->SetColor(0xFF0000E3, i);
		}
		else
		{
			unitSpr->SetColor(0xFFF9F900, i);
		}
	}
}


StarBacterium::~StarBacterium(void)
{
}
