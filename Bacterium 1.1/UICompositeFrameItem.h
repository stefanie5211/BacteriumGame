#pragma once
#include "hgegui.h"
class UICompositeFrame:
	public hgeGUIObject
{
public:
	UICompositeFrame(int id,  hgeSprite *spr, float x, float y);
	virtual void	Render();

private:
	hgeSprite	   *spr;
};

