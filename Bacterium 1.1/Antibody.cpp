#include "Antibody.h"


Antibody::Antibody(void)
{
	hge = hgeCreate(HGE_VERSION);
	unitType = ANTIBODY;
}


Antibody::~Antibody(void)
{
}

void Antibody::UnitSprRender( void )
{
	if (unitState != DEAD)
	{
		unitSpr->Render(position.x, position.y);
	}
}
