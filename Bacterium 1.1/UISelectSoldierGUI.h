#pragma once
#include "stdafx.h"
#include <math.h>
class SelectSoldierGUI : public hgeGUIObject
{
public:
	SelectSoldierGUI(int _id, HTEXTURE _tex, float _x, float _y, float x1,float y1, float x2, float y2);

	virtual void	Render();
	virtual void	Update(float dt);

	virtual bool	MouseLButton(bool bDown);
	virtual bool	MouseRButton(bool bDown);

private:
	float        initialX, initialY;
	hgeSprite    *spr;
	hgeSprite    *spr2;

	float        dertaX, dertaY, mouseX, mouseY;
	bool         bDownLastTime;
	int          Array[4][2];
	bool         bSelected;
	float        w;
};

