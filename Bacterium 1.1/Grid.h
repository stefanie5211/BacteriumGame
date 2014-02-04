#pragma once
#include "Unit.h"
class Grid
{
public:
	Grid(void);
	~Grid(void);
	int mapX, mapY; //格子在grids数组里面的坐标
	int openList_ID; //open表里的ID
	int openListID_ID; //open表里的ID
	Grid* parent; //父节点
	Grid* children[8]; //子节点
	Position postion;  //格子左上角坐标
	float hValue; 
	float gValue;
	float fValue;
	int state; //当前状态（在open表里或close表里或都不在）
	bool passable; //地图上该点是否有障碍物
};

