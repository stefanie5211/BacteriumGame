#include "UISkillItem.h"

hgeGUISkillButton::hgeGUISkillButton(int _id, hgeFont *_fnt, hgeSprite *_spSkill, 
		                             HEFFECT _snd, float _x, float _y, char *_title)
{
	id       =   _id;	
	fnt      =   _fnt;
	snd      =   _snd;
	title    =   _title;
	spr      =   _spSkill;
	
	bStatic     =   false;
	bVisible    =   true;
	bEnabled    =   true;

	disPlayHelp =   false;

	offset   = 4.0f;
	timer    = 0;   

	rect.Set(_x, _y, _x+60, _y+84);
}


void hgeGUISkillButton::Render(void)
{
	if(spr!= 0)
	{
		spr->SetColor(0xFAFAAa10);
		spr->RenderEx(rect.x1-offset, rect.y1-offset ,0, 0.65f);
		if(disPlayHelp)
		{
			hge->Gfx_RenderLine(480, 530, 540, 530, 0xFFFAf050);
		    hge->Gfx_RenderLine(480, 530, 480, 570, 0xFFFAf050);
		    hge->Gfx_RenderLine(480, 570, 540, 570, 0xFFFAf050);
		    hge->Gfx_RenderLine(540, 530, 540, 570, 0xFFFAf050);
		}
	}
}

void hgeGUISkillButton::Update(float dt)
{
	if(mouseOver)
	{
		if(timer < 1.0f)
		{
			timer += dt;
		}
		else
		{
			disPlayHelp = true;
		}
	}
	else
	{
		timer = 0;
		disPlayHelp = false;
	}
}

void hgeGUISkillButton::MouseOver(bool bOver)
{
	if(bOver)
	{
		mouseOver = true;
	}
	else
	{
		mouseOver = false;
	}
}

bool hgeGUISkillButton::MouseLButton(bool bDown)
{
	if(bDown)
	{	
		timer=0;
		offset=0;
		return true;
	}
	else 
	{
		hge->Effect_Play(snd);
		offset=4;
		return false;
	}
}