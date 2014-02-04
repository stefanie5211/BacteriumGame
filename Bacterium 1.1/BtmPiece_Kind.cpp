#include "BtmPiece_Kind.h"


BtmPiece_Kind::BtmPiece_Kind(hgeSprite *_spCard, hgeSprite *_spLock, int _ID, bool _bLock)
{
	spCard = _spCard;
	spLock = _spLock;
	ID     = _ID;
	bLock  = _bLock;
}

BtmPiece_Kind::~BtmPiece_Kind(void)
{
}

void BtmPiece_Kind::SetBlock(bool _bLock)
{
	bLock = _bLock;
}

void BtmPiece_Kind::Render(void)
{
	spCard->Render(443, 323);
}