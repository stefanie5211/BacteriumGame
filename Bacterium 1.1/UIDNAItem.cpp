#include "UIDNAItem.h"


hgeGUIDNAButton::hgeGUIDNAButton(int _id, hgeFont *_fnt, hgeSprite *_spr, 
	                     float _x, float _y, float _delay, char *_title)
{
	id       = _id;
	fnt      = _fnt;
	spr      = _spr;
	delay    = _delay;
	title    = _title;

	initX    = _x;
	initY    = _y;

	bStatic  = false;
	bVisible = true;
	bEnabled = true;

	bLBDown     =   false;
	disPlayHelp =   false;

	eloffset = _y+84; 

	dy = 500;

	timer  = 0.0f;   
	timer1 = -1.0f;
	timer2 = -1.0f;
	

	rect.Set(_x, _y, _x+36, _y+36);
	rect1.Set(_x, _y, _x+16, _y+16); //258, 333,274, 349 //248, 323
	rect2.Set(358, 333, 374, 349); // //348, 323
}

void hgeGUIDNAButton::Render()
{
	spr->RenderEx(rect.x1,  rect.y1-eloffset, 0, 0.6);//
}

void hgeGUIDNAButton::Update(float dt)
{	
	UpdateEnterOrLeave(dt);
	UpdateToDisplayHelp(dt);
	Drafting();	
}

void hgeGUIDNAButton::Enter()
{
	timer1  = 0.0f;
	eloffset  = rect.y1+84;
}

void hgeGUIDNAButton::Leave()
{
	timer2  = 0.0f;
}
bool hgeGUIDNAButton::IsDone()
{
	if(timer2 == -1.0f || timer1 != -1.0f)
	{
		return true;
	}
	else
	{
	  return false;
	}
}

void hgeGUIDNAButton::MouseOver(bool bOver)
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

bool hgeGUIDNAButton::MouseLButton(bool bDown)
{
	if(!bDown)
	{
		return bLBDown = false;
	}
	
	else
		return bLBDown = true;
}

bool hgeGUIDNAButton::MouseRButton(bool bDown)
{
	if(!bDown)
	{
		return false;
	}
	else
	{
		rect.Set(initX, initY, initX+16, initY+16);
		return true;
	}
}


void hgeGUIDNAButton::Drafting(void)
{
	if(bLBDown && !hge->Input_KeyUp(HGEK_LBUTTON))
	{
		float x, y;
		hge->Input_GetMousePos(&x, &y);
		rect.Set(x-18, y-18, x+18, y+18);	
	}	
}


void hgeGUIDNAButton::UpdateToDisplayHelp(float dt)
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
			
void hgeGUIDNAButton::UpdateEnterOrLeave(float dt)
{
	if(timer1 != -1.0f)
	{
		if(timer1 < delay)
		{
			timer1 += dt;
		}
		else
		{
			if(eloffset > 0)
			{
				eloffset -= dy* dt;
			}
			else 
			{
				eloffset=0.0f;
				timer1 = -1.0f;
			}
		}
	}
	else if( timer2 != -1.0f)
	{		
		if(timer2 - (1-delay) < 0)
		{
			timer2 += dt;
		}
		else 
		{			
			if(eloffset < rect.y1+84)
			{
				eloffset += dy * dt;
			}
			else
			{
				timer2 = -1.0f;
			}
		}
	}
}