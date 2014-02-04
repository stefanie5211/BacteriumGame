#pragma once
#include "stdafx.h"

class hgeGUISkillButton
	    : public hgeGUIObject
{
public:
	hgeGUISkillButton(int id, hgeFont *fnt, hgeSprite *spSkill, 
		         HEFFECT snd, float x, float y, char *title = 0);

	virtual void	Render();
	virtual void	Update(float dt);
	
	virtual void	MouseOver(bool bOver);
	virtual bool	MouseLButton(bool bDown);
	        void    SetSpr(hgeSprite* _spr) { spr = _spr;}
private:
	HEFFECT		snd;

	hgeSprite   *spr;
	hgeFont     *fnt;	

	char		*title;
	float        offset;
	float		 timer;
	bool         mouseOver;
	bool         disPlayHelp;//显示技能说明
};

