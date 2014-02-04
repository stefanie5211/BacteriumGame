#include "CompositeFrame.h"


CompositeFrame::CompositeFrame(float x1, float y1, float x2, float y2, 
		                           float _x, float _y, hgeSprite* _spr)
{
	rect.Set(x1, y1, x2, y2);

	x = _x;
	y = _y;

	spr = _spr;

	ID  = -1;
	beShaded = false;
}


CompositeFrame::~CompositeFrame(void)
{
}


void CompositeFrame::Render(void)
{
	spr->Render(x, y);
}