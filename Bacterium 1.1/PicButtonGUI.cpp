#include "PicButtonGUI.h"


PicButtonGUI::PicButtonGUI(int _id, HTEXTURE _tex, HEFFECT _snd, float _x, float _y, float x1,float y1, float x2, float y2)
{
	id  = _id;
	snd = _snd;
	spr = new hgeSprite(_tex, x1, y1, x2, y2);

	float w;
	w=spr->GetWidth();
	rect.Set(_x-w/2, _y, _x+w/2, _y+spr->GetHeight());

	offset       = 0.0f;

}

void PicButtonGUI::Render()
{
	spr->Render(rect.x1+offset, rect.y1+offset);
}

void PicButtonGUI::Update( float dt )
{

}

void PicButtonGUI::Focus(bool bFocused)
{
	if(bFocused)
		hge->Effect_Play(snd);

}

void PicButtonGUI::MouseOver(bool bOver)
{
	if(bOver) gui->SetFocus(id);
}

bool PicButtonGUI::MouseLButton(bool bDown)
{
	if(!bDown)
	{
		offset = 0.0f;
		return true;
	}
	else 
	{
		offset = 2.0f;
		return false;
	}
}







