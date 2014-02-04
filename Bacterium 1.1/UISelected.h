#pragma once
#include "stdafx.h"
#include "hgegui.h"
#include "Constant.h"

class hgeGUISelectedButton :
	public hgeGUIObject
{
public:
	hgeGUISelectedButton(int, hgeFont*, float, float);

	void     Render(void);
	bool	 MouseLButton(bool bDown);

	void     SetNumAndUnitType(UnitType, int num);

	UnitType GetUnitType(void){ return unitType; }
	

private:
	hgeFont     *fnt;
	int          m_nNumOfSelected;
	UnitType     unitType;
	float        offset;
};

