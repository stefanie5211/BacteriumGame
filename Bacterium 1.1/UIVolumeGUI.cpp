#include "UIVolumeGUI.h"


VolumeGUI::VolumeGUI(int _id, hgeFont *_fnt, HEFFECT _snd, float _x, float _y, char *_title)
{
	float w;

	id=_id;
	fnt=_fnt;
	snd=_snd;
	title=_title;

	//color.SetHWColor(0xFFFFE060);
	//offset=0.0f;

	w=fnt->GetStringWidth(title);
	rect.Set(_x-w/2, _y, _x+w/2, _y+fnt->GetHeight());
}


void VolumeGUI::Render()
{
	fnt->SetColor(gui->GetCtrl(id)->color);
	fnt->Render(rect.x1, rect.y1, HGETEXT_LEFT, title);
}

void VolumeGUI::Update(float dt)
{

}

void VolumeGUI::MouseOver( bool bOver )
{
	if(bOver) 
		gui->SetFocus(id);
}

bool VolumeGUI::MouseLButton( bool bDown )
{
	if(!bDown)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

