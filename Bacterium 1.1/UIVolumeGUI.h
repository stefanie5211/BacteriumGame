#pragma once
#include "stdafx.h"
class VolumeGUI : public hgeGUIObject
{
public:
	VolumeGUI(int _id, hgeFont *_fnt, HEFFECT _snd, float _x, float _y, char *_title);

	virtual void	Render();
	virtual void    Update(float dt);
	virtual void	MouseOver(bool bOver);
	virtual bool	MouseLButton(bool bDown);

private:
	hgeFont		*fnt;
	HEFFECT		snd;
	char		*title;

	hgeColor	color;
	float		offset;
};


