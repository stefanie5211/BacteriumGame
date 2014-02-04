#include "GameMap.h"


GameMap::GameMap(HTEXTURE &mapTex, vector<Unit*>* value)
{
	direction[0].x = -GRID_LENGTH;
	direction[0].y = -GRID_LENGTH;
	direction[1].x = -GRID_LENGTH;
	direction[1].y = 0;
	direction[2].x = -GRID_LENGTH;
	direction[2].y = GRID_LENGTH;
	direction[3].x = 0;
	direction[3].y = GRID_LENGTH;
	direction[4].x = GRID_LENGTH;
	direction[4].y = GRID_LENGTH;
	direction[5].x = GRID_LENGTH;
	direction[5].y = 0;
	direction[6].x = GRID_LENGTH;
	direction[6].y = -GRID_LENGTH;
	direction[7].x = 0;
	direction[7].y = -GRID_LENGTH;

	for (int i = 1; i < 101; ++i)
	{
		for (int j = 1; j < 76; ++j)
		{
			grids[i][j].mapX = i;
			grids[i][j].mapY = j;
			grids[i][j].postion.x = (i - 1)*8.0f;
			grids[i][j].postion.y = (j - 1)*8.0f;
		}
	}

	unitsAll = value;
	mapSprite = new hgeSprite(mapTex, 0.0, 0.0, 1280.0, 800.0);
}


GameMap::~GameMap(void)
{
}

void GameMap::RefreshMap( void )
{
	for (int i = 1; i < 101; ++i)
	{
		for (int j = 1; j < 76; ++j)
		{
			grids[i][j].gValue = 0;
			grids[i][j].hValue = 0;
			grids[i][j].fValue = 0;
			grids[i][j].state = FREE;
			grids[i][j].parent = NULL;
			for (int k = 0; k < 8; ++k)
			{
				grids[i][j].children[k] = NULL;
			}
		}
	}
}

bool GameMap::Passable( Unit* unit, const Position findPosition)
{
	for (vector<Unit*>::iterator iter = unitsAll->begin(); iter != unitsAll->end(); ++iter)
	{
		if ((*iter) == unit)
		{
			continue;
		}
		if (sqrt(pow(findPosition.x - (*iter)->GetPosition().x, 2) + pow(findPosition.y - (*iter)->GetPosition().y, 2)) 
			<= (unit->GetRadius() + (*iter)->GetRadius()) ||  (findPosition.x + unit->GetRadius() > 800) ||  (findPosition.x - unit->GetRadius() < 0)
			||  (findPosition.y + unit->GetRadius() > 600) ||  (findPosition.y + unit->GetRadius() < 0))
		{
			return false;
		}
	}
	return true; 
}

bool GameMap::DirectionPassable( Unit *unit, int moveDirection, Grid* BestGrid )
{
	Position tempPosition; 
	tempPosition.x = (BestGrid->postion.x) + direction[moveDirection].x + unit->GetRadius();
	tempPosition.y = (BestGrid->postion.y) + direction[moveDirection].y + unit->GetRadius();
	return Passable(unit, tempPosition);
}

Grid* GameMap::GetGrid( const float &x, const float &y )
{
	return &(grids[(int)(x/8) + 1][(int)(y/8) + 1]);
}

Position* GameMap::Direction( void )
{
	return direction;
}


Unit* GameMap::NextPositionPassable( Unit *unit,const Position &nextPositon )
{
	for (vector<Unit*>::iterator iter = unitsAll->begin(); iter != unitsAll->end(); ++iter)
	{
		if ((*iter) == unit)
		{
			continue;
		}

		if (sqrt(pow(nextPositon.x - (*iter)->GetPosition().x, 2) + pow(nextPositon.y - (*iter)->GetPosition().y, 2)) <= (unit->GetRadius() + (*iter)->GetRadius()))
		{
			return (*iter);
		}
	}
	return NULL; 
}
