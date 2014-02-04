#pragma once
#include "Bacterium.h"
class StarBacterium :
	public Bacterium
{
public:
	StarBacterium(void);
	StarBacterium(
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
	~StarBacterium(void);
};

