#include "UISelected.h"


hgeGUISelectedButton::hgeGUISelectedButton(int _ID, hgeFont* _fnt, float _x, float _y)
{
	id  = _ID;
	fnt = _fnt;

	m_nNumOfSelected = 0;
	
	bStatic  = false;
    bVisible = true;
	bEnabled = true;

	offset   = 0;

	rect.Set(_x, _y, _x+32, _y+32);

}


void hgeGUISelectedButton::Render(void)
{
	if(m_nNumOfSelected)
	{
		bEnabled = true;
		fnt->SetColor(0xFFFFFFFF);
		fnt->printf(rect.x1+offset, rect.y1+offset, HGETEXT_LEFT, "%d", m_nNumOfSelected);
	}
	else
	{		
		bEnabled = true;		
	}
}

bool hgeGUISelectedButton::MouseLButton(bool bDown)
{
	if(bDown)
	{
		offset = 4;
		return true;
	}
	else
	{
		offset = 0;
		return false;
	}
}

void hgeGUISelectedButton::SetNumAndUnitType(UnitType _unitType, int num)
{
	m_nNumOfSelected = num;
	unitType         = _unitType;
}