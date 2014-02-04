#pragma once
#include "Bacterium.h"
class BallBacterium :
	public Bacterium
{
public:
	BallBacterium(void);
	BallBacterium(
		const int &initialUnitID,
		const float &initialX, 
		const float &initialY, 
		const Camp &initialCamp, 
		const HTEXTURE &initialUnitTex, 
		const HTEXTURE &initialSelectedTex,
		const HTEXTURE &initialPointTex,
		hgeParticleSystem *initialShotPar,
		hgeParticleSystem *initialDeathPar
		);
	~BallBacterium(void);
};

