#pragma once
#include "stdafx.h"

class CompositeFrame
{
public:
	CompositeFrame(float x1, float y1, float x2, float y2, 
		              float _x, float _y, hgeSprite* _spr);
	~CompositeFrame(void);

	void Render(void);
	hgeRect		rect;
	hgeSprite  *spr;

	int         ID;
	bool        beShaded;
	float       x, y;
	
};

