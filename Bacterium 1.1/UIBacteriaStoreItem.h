#pragma once
#include "stdafx.h"
/***************************
*                          *
***************************/

class hgeGUIBacteriaMenu 
	    : public hgeGUIObject
{
public:
	hgeGUIBacteriaMenu(int id, hgeFont *fnt, hgeSprite *spCard, hgeSprite *spLock, HEFFECT snd, 
		                               float x, float y, float delay, bool beLock, char *title = 0);

	virtual void	Render();
	virtual void	Update(float dt);

	virtual void	Enter();
	virtual void	Leave();
	virtual bool	IsDone();
	virtual void	Focus(bool bFocused);

	virtual bool	MouseLButton(bool bDown);
	virtual bool	KeyClick(int key, int chr);

private:
	hgeSprite	*spCard;
	hgeSprite   *spLock;
	hgeFont     *fnt;
	HEFFECT		snd;
	float		delay;
	char		*title;
	bool        beLock;
	bool        beLClick;

	float       posX, posY;    
	float       dy;
	float		timer1, timer2;
	float		soffset, doffset, offset;
};

