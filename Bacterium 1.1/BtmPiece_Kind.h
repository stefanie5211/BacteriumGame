#pragma once
#include "stdafx.h"

class BtmPiece_Kind
{
public:
	BtmPiece_Kind(hgeSprite *_spCard, hgeSprite *_spLock, int _ID, bool _bLock);
	~BtmPiece_Kind();

	void Render(void);
	void SetBlock(bool _bLock);
	
	hgeSprite *spCard;
	hgeSprite *spLock;
	int        ID;
	bool       bLock;

};

