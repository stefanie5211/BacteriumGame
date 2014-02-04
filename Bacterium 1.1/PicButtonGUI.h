#pragma once
#include "stdafx.h"

class PicButtonGUI : public hgeGUIObject
{
public:
	PicButtonGUI(int _id, HTEXTURE _tex, HEFFECT _snd, float _x, float _y, float x1,float y1, float x2, float y2);

	virtual void	Render();
	virtual void	Update(float dt);

	virtual void    Focus(bool bFocused);
	virtual void	MouseOver(bool bOver);
	virtual bool	MouseLButton(bool bDown);

private:
	hgeSprite *spr;
	HEFFECT    snd;
	float      offset;

};

