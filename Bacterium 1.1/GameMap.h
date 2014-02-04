#pragma once
#include "Unit.h"
#include "Grid.h"
#include "Constant.h"
class GameMap
{
public:
	GameMap(HTEXTURE &mapTex, vector<Unit*>* value);
	~GameMap(void);

	bool Passable(Unit *unit, const Position findPosition); //该点是否能走
	Unit* NextPositionPassable(Unit *unit,const Position &nextPositon);
	bool DirectionPassable(Unit *unit, int moveDirection, Grid* BestGrid); //该方向是否能走
	Grid* GetGrid(const float &x, const float &y); //屏幕坐标转换为相应格子
	void RefreshMap(void); //刷新地图
	Position* Direction(void); //返回方向
private:	
	Grid grids[100 + 1][75 + 1]; //存放地图上所有格子
	vector<Unit*> *unitsAll;
	Position direction[8]; //存放方向
	hgeSprite *mapSprite;
};

