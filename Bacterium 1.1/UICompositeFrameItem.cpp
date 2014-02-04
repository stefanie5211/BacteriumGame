#include "UICompositeFrameItem.h"


UICompositeFrame::UICompositeFrame(int _id,  hgeSprite *_spr, float _x, float _y)
{
	id  = _id;
	spr = _spr;

	rect.Set(_x, _y, _x+64, _y+64);
}

void UICompositeFrame::Render(void)
{
	spr->Render(rect.x1, rect.y1);
}


