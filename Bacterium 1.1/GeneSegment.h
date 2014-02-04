#pragma once
#include "stdafx.h"

class GeneSegment
{
public:
	GeneSegment(hgeSprite* _spr, int _ID);
	~GeneSegment(void);

	hgeSprite *spr;
	int        ID;
};

