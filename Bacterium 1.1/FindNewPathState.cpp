#include "FindNewPathState.h"


FindNewPathState::FindNewPathState(void)
{
	gameMap = MANAGER_CHAPTER->GetGameMapAddress();
}


FindNewPathState::~FindNewPathState(void)
{
}

UnitState<Unit>* FindNewPathState::GetInstance()
{
	static UnitState<Unit>* instance;
	if (!instance)
	{
		instance = new FindNewPathState();
	}
	return instance;
}

void FindNewPathState::Enter( Unit* unit )
{
	
}

void FindNewPathState::Execute( Unit* unit )
{
	FindNewPath(unit);
}

void FindNewPathState::Exit( Unit* unit )
{

}
void FindNewPathState::FindNewPath( Unit* unit )
{  
	startGrid = gameMap->GetGrid(unit->GetPosition().x - unit->GetRadius(), unit->GetPosition().y - unit->GetRadius()); //unit当前左上角格子
	endGrid = gameMap->GetGrid(((Bacterium*)unit)->GetDestinationPosition().x - unit->GetRadius(), ((Bacterium*)unit)->GetDestinationPosition().y - unit->GetRadius()); //目的地格子
	gameMap->RefreshMap(); // 刷新地图
	((Bacterium*)unit)->RouteList().clear(); //清空路径
	//清空两个表
	numberOfOpenListGrids = 0;
	previousID = 1;
	closeList.clear();

	//定义头结点并放入Open表
	Grid *headGrid, *bestGrid; //头结点，最优结点
	headGrid = startGrid;
	headGrid->hValue = GetHValue(startGrid, endGrid);
	headGrid->fValue = headGrid->gValue + headGrid->hValue;
	headGrid->openList_ID = previousID;
	InsertOpenList(headGrid);

	while(numberOfOpenListGrids > 0)
	{
		//从Open表中取得一个估价值最好的节点并删除
		bestGrid = openList[openListID[1]];
		DeleteOpenListTopGrid();

		//如果close表里结点超过最大值，就取当前离目标点最近结点做为终点
		if (closeList.size() > 120)
		{
			endGrid = closeList.front();
			bestGrid = closeList.front();
		}

		//如果该节点是目标节点就退出
		if (bestGrid->mapX == endGrid->mapX && bestGrid->mapY == endGrid->mapY)
		{
			//求得路径PATH
			while (bestGrid->mapX != startGrid->mapX || bestGrid->mapY != startGrid->mapY)
			{	
				Position tempPosition;
				tempPosition.x = bestGrid->postion.x + unit->GetRadius();
				tempPosition.y = bestGrid->postion.y + unit->GetRadius();
				((Bacterium*)unit)->RouteList().push_back(tempPosition);
				bestGrid = bestGrid->parent;
			}
			//把该单位状态设置为RUN 
			unit->GetFSM()->SetCurrentState(UNIT_STATE_RUN);
			((Bacterium*)unit)->SetWaitTime(0) ;
			break;
		}

		//否则生成八个方向的子节点
		GenerateSuccessors(unit ,bestGrid);
		//将检查过的结点放入close表,并让close表始终保持第一个结点为离终点最近的点
		if (!closeList.empty() && bestGrid->hValue < (*closeList.begin())->hValue)
			closeList.push_front(bestGrid);
		else
			closeList.push_back(bestGrid);
		//把最优结点的状态设为在close表里
		bestGrid->state = INCLOSELIST; 
	}
}

void FindNewPathState::GenerateSuccessors(Unit* unit, Grid *bestGrid)
{
	//依次生成八个方向的子节点
	// 左上
	if (gameMap->DirectionPassable(unit, UPPERLEFT, bestGrid))
		GenerateSucc(unit, bestGrid, UPPERLEFT);
	// 上
	if (gameMap->DirectionPassable(unit, UPPER, bestGrid))
		GenerateSucc(unit, bestGrid, UPPER);
	// 右上
	if (gameMap->DirectionPassable(unit, UPPERRIGHT, bestGrid))
		GenerateSucc(unit, bestGrid, UPPERRIGHT);
	// 右
	if (gameMap->DirectionPassable(unit, RIGHT, bestGrid))
		GenerateSucc(unit, bestGrid, RIGHT);
	// 右下
	if (gameMap->DirectionPassable(unit, LOWERRIGHT, bestGrid))
		GenerateSucc(unit, bestGrid, LOWERRIGHT);
	// 下
	if (gameMap->DirectionPassable(unit, LOWER, bestGrid))
		GenerateSucc(unit, bestGrid, LOWER);
	// 左下
	if (gameMap->DirectionPassable(unit, LOWERLEFT, bestGrid))
		GenerateSucc(unit, bestGrid, LOWERLEFT);
	// 左
	if (gameMap->DirectionPassable(unit, LEFT, bestGrid))
		GenerateSucc(unit, bestGrid, LEFT);
}        

void FindNewPathState::GenerateSucc( Unit* unit, Grid *bestGrid, int succDirection )
{
	Grid *oldGrid = gameMap->GetGrid(bestGrid->postion.x + gameMap->Direction()[succDirection].x, bestGrid->postion.y + gameMap->Direction()[succDirection].y);
	Grid *succGrid;
	float succGValue;
	int i;

	//计算节点的G值,直着走+1.0，斜着走+1.4
	if (succDirection == UPPER || succDirection == RIGHT || succDirection == LOWER || succDirection == LEFT)
		succGValue = bestGrid->gValue + STRAIGHT_G;
	else
		succGValue = bestGrid->gValue + DIAGONAL_G;

	//判断子节点是否在open表中
	if (oldGrid->state == INOPENLIST)
	{
		//搜索最优结点children数组中空的元素，把该节点放进去
		for(i = 0; i < 8; ++i)
		{
			if( bestGrid->children[i] == NULL )
				break;
		}
		bestGrid->children[i] = oldGrid;

		//比较Open表中的估价值和当前的估价值（只要比较g值就可以了）
		if ( succGValue < oldGrid->gValue )
		{
			//当前的估价值小就更新Open表中的估价值
			oldGrid->parent = bestGrid;
			oldGrid->gValue = succGValue;
			oldGrid->fValue = oldGrid->gValue + oldGrid->hValue;
			//更新open表，向上升和向下降都试一下
			FilterUp(oldGrid->openListID_ID);
			FilterDown(oldGrid->openListID_ID);
		}
	}
	//判断节点是否在close表中
	else if (oldGrid->state == INCLOSELIST)
	{
		//搜索最优结点children数组中空的元素，把该节点放进去
		for(i = 0; i < 8; ++i)
		{
			if( bestGrid->children[i] == NULL )
				break;
		}
		bestGrid->children[i] = oldGrid;

		//比较Closed表中的估价值和当前的估价值（只要比较g值就可以了）
		if ( succGValue < oldGrid->gValue )
		{
			//当前的估价值小就更新Closed表中的估价值
			oldGrid->parent = bestGrid;
			oldGrid->gValue = succGValue;
			oldGrid->fValue = oldGrid->gValue + oldGrid->hValue;
			//再依次更新oldGrid的所有子节点的估价值（优化点，不重新把结点放入open，而是直接更新）
			PropagateDown(oldGrid);
		}
	}
	//结点不在Open表中也不在Close表中
	else
	{
		succGrid = oldGrid;
		succGrid->parent = bestGrid;
		succGrid->gValue = succGValue;
		succGrid->hValue = GetHValue(succGrid, endGrid);
		succGrid->fValue = succGrid->gValue + succGrid->hValue;
		//再插入Open表中（优化点,不排序open表，而是采用二叉堆），并把它的状态设为在open表中
		InsertOpenList(succGrid);
		succGrid->state = INOPENLIST;
		//搜索最优结点children数组中空的元素，把该节点放进去
		for(i = 0; i < 8; ++i)
		{
			if ( bestGrid->children[i] == NULL )
				break;
		}
		bestGrid->children[i] = succGrid;
	}
}

void FindNewPathState::PropagateDown( Grid *oldGrid )
{
	Grid *Child, *Father;
	float tempGValue;

	for(int i = 0; i < 8; ++i)
	{
		if ((Child = oldGrid->children[i]) == NULL)  
			break;

		tempGValue = oldGrid->gValue ;
		//判断方向并求G值
		if (Child->postion.x == oldGrid->postion.x || Child->postion.y == oldGrid->postion.y)
			tempGValue += STRAIGHT_G;
		else
			tempGValue += DIAGONAL_G;

		if (tempGValue < Child->gValue)
		{
			Child->gValue = tempGValue;
			Child->fValue = Child->gValue + Child->hValue;
			Child->parent = oldGrid;     
			nodeStack.push_back(Child);           
		} 
	}

	while (!nodeStack.empty())
	{
		Father = nodeStack.back(); //容器最后一个元素赋给father
		nodeStack.pop_back(); //移除容器最后一个元素
		for(int i = 0; i < 8; ++i)
		{
			if ((Child = Father->children[i])==NULL)      
				break;

			tempGValue = Father->gValue ;
			//判断方向并求G值
			if (Child->postion.x == Father->postion.x || Child->postion.y == Father->postion.y)
				tempGValue += STRAIGHT_G;
			else
				tempGValue += DIAGONAL_G;

			if (tempGValue < Child->gValue) 
			{                        
				Child->gValue = tempGValue;
				Child->fValue = Child->gValue + Child->hValue;
				Child->parent = Father;
				nodeStack.push_back(Child);   
			}
		}
	}
}

//用加权求和求h值，这里的10和6是高手们得出的经验值，不解释
float FindNewPathState::GetHValue(Grid *startGrid, Grid *endGrid)
{
	if (abs(endGrid->postion.x - startGrid->postion.x) > abs(endGrid->postion.y - startGrid->postion.y)) 
		return 10*abs(endGrid->postion.x - startGrid->postion.x)+6*abs(endGrid->postion.y - startGrid->postion.y); 
	else 
		return 10*abs(endGrid->postion.y - startGrid->postion.y)+6*abs(endGrid->postion.x - startGrid->postion.x);
}

void FindNewPathState::InsertOpenList( Grid *newNode )
{
	newNode->openList_ID = ++previousID; //新节点open表里的ID等于前一节点的ID+1
	++numberOfOpenListGrids; //节点数量+1
	newNode->openListID_ID = numberOfOpenListGrids; //新节点openID表里的ID等于当前节点数
	openListID[newNode->openListID_ID] = newNode->openList_ID; 
	openList[newNode->openList_ID] = newNode; 
	FilterUp(newNode->openListID_ID); //让新节点向上升
}

void FindNewPathState::DeleteOpenListTopGrid( void )
{
	openListID[1] = openListID[numberOfOpenListGrids]; //把最后一个节点移到顶端
	openList[openListID[1]]->openListID_ID = 1; //把该节点在openListID表里的位置改为1
	--numberOfOpenListGrids;
	FilterDown(1); //让顶端节点向下降
}

void FindNewPathState::FilterDown( int hole )
{
	int tempHole = hole, tempOpenList_ID, tempOpenListID_ID;;

	while (1)
	{
		hole = tempHole;
		if ((2*hole+1) <= numberOfOpenListGrids) //判断当前节点是否拥有两个子节点
		{
			//选择两个子节点中F最低的那个
			if (openList[openListID[hole]]->fValue >= openList[openListID[2*hole]]->fValue) 
				tempHole = 2*hole;
			if (openList[openListID[tempHole]]->fValue >= openList[openListID[2*hole+1]]->fValue)
				tempHole = 2*hole + 1;
		}
		else if((2*hole) <= numberOfOpenListGrids)//判断当前节点是否拥有一个节点
		{
			if (openList[openListID[hole]]->fValue >= openList[openListID[2*hole]]->fValue)
				tempHole = 2*hole;
		}


		//交换节点
		if (hole != tempHole)
		{
			tempOpenList_ID = openListID[hole];
			tempOpenListID_ID = openList[openListID[hole]]->openListID_ID;

			openListID[hole] = openListID[tempHole];
			openList[openListID[hole]]->openListID_ID = openList[openListID[tempHole]]->openListID_ID;

			openListID[tempHole] = tempOpenList_ID;
			openList[openListID[tempHole]]->openListID_ID = tempOpenListID_ID;
		}
		else
			break;
	}
}

void FindNewPathState::FilterUp( int hole )
{
	int tempOpenList_ID, tempOpenListID_ID;

	//当元素没有到达顶部是，执行以下代码
	while(hole != 1)
	{
		//检查字节点是否小于父节点的F值，为true则交换
		if (openList[openListID[hole]]->fValue <= openList[openListID[hole/2]]->fValue)
		{
			tempOpenList_ID = openListID[hole/2];
			tempOpenListID_ID = openList[openListID[hole/2]]->openListID_ID;

			openListID[hole/2] = openListID[hole];
			openList[openListID[hole/2]]->openListID_ID = openList[openListID[hole]]->openListID_ID;

			openListID[hole] = tempOpenList_ID;
			openList[openListID[hole]]->openListID_ID = tempOpenListID_ID;
			hole = hole/2;
		}
		else
			break;
	}
}