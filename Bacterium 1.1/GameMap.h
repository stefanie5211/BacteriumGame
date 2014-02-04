#pragma once
#include "Unit.h"
#include "Grid.h"
#include "Constant.h"
class GameMap
{
public:
	GameMap(HTEXTURE &mapTex, vector<Unit*>* value);
	~GameMap(void);

	bool Passable(Unit *unit, const Position findPosition); //�õ��Ƿ�����
	Unit* NextPositionPassable(Unit *unit,const Position &nextPositon);
	bool DirectionPassable(Unit *unit, int moveDirection, Grid* BestGrid); //�÷����Ƿ�����
	Grid* GetGrid(const float &x, const float &y); //��Ļ����ת��Ϊ��Ӧ����
	void RefreshMap(void); //ˢ�µ�ͼ
	Position* Direction(void); //���ط���
private:	
	Grid grids[100 + 1][75 + 1]; //��ŵ�ͼ�����и���
	vector<Unit*> *unitsAll;
	Position direction[8]; //��ŷ���
	hgeSprite *mapSprite;
};

