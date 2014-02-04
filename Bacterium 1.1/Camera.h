#pragma once
#include "stdafx.h"
#include "Constant.h"
#include "ChapterManager.h"
#include "Unit.h"
class Camera
{
public:
	Camera(void);
	~Camera(void);
private:
	Position          MainMapPosition;
	vector<Unit*>     *unitsAll;
	HGE               *hge;
public:
	void Render();
	Position GetMainMapPosition() const { return MainMapPosition; }
	void SetMainMapPosition(Position val) { MainMapPosition = val; }
	void SetMainMapPosition(float x , float y){ MainMapPosition.x = x; MainMapPosition.y = y; }
	static Camera* GetInstance();
	Position Change(Position pos);
};

