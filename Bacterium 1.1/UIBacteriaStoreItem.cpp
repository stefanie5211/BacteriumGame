#include "UIBacteriaStoreItem.h"


hgeGUIBacteriaMenu::hgeGUIBacteriaMenu(int _id, hgeFont *_fnt, hgeSprite *_spCard, hgeSprite *_spLock, 
	                         HEFFECT _snd, float _x, float _y, float _delay, bool _beLock, char *_title)
{
	id       = _id;
	spCard   = _spCard;
	spLock   = _spLock;
	fnt      = _fnt;
	snd      = _snd;
	delay    = _delay;
	title    = _title;
	beLock   = _beLock;

	beLClick = false;
	
	bStatic  = false;
	bVisible = true;
	bEnabled = true;
	
	posX = _x;
	posY = -84;
	dy = 500;

	timer1 = -1.0f;
	timer2 = -1.0f;
	offset   =0.0f;

	rect.Set(_x, _y, _x+60, _y+84);
}


void hgeGUIBacteriaMenu::Render()
{
	spCard->Render(posX-offset, posY-offset);
	if(beLock)
	{
		spLock->Render(posX, posY);
	}

	if(beLClick)
	{		
		fnt->SetColor(0xFFFF8000);
	    fnt->Render(40, 90, HGETEXT_LEFT, title);
	}	
}

void hgeGUIBacteriaMenu::Update(float dt)
{	
	if(timer1 != -1.0f)
	{
		if(timer1 < delay)
		{
			timer1 += dt;
		}
		else
		{
			if(posY < rect.y1)
			{
				posY += dy* dt;
			}
			else 
			{
				offset=0.0f;
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
			if(posY > -84)
			{
				posY -= dy * dt;
			}
			else
			{
				timer2 = -1.0f;
			}
		}
	}
}

void hgeGUIBacteriaMenu::Enter()
{
	timer1  = 0.0f;
	posY  = -84;
}

void hgeGUIBacteriaMenu::Leave()
{
	timer2  = 0.0f;
}

// This method is called to test whether the control
// have finished it's Enter/Leave animation
bool hgeGUIBacteriaMenu::IsDone()
{
	if(timer2 == -1.0f)
	{
		return true;
	}
	else if(timer1 != -1.0f)
	{
		return true;
	}
	else
	{
	  return false;
	}
}

void hgeGUIBacteriaMenu::Focus(bool bFocused)
{
	if(bFocused)
	{
		beLClick = true;
		hge->Effect_Play(snd);
		soffset=0;
		doffset=4;
	}
	else
	{
		beLClick = false;
		soffset=4;
		doffset=-4;
	}
}





bool hgeGUIBacteriaMenu::MouseLButton(bool bDown)
{
	if(bDown)
	{
		offset=0;
	    gui->SetFocus(id);
		return  true;
	}
	else
	{
		offset=4;
		return false;
	}
}

bool hgeGUIBacteriaMenu::KeyClick(int key, int chr)
{
	return false;
}
