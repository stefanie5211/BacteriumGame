#pragma once
#include "unit.h"
class Antibody :
	public Unit
{
public:
	Antibody(void);
	~Antibody(void);
	virtual void UnitSprRender(void);

};

