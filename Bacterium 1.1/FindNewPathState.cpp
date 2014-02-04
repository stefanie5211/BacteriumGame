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
	startGrid = gameMap->GetGrid(unit->GetPosition().x - unit->GetRadius(), unit->GetPosition().y - unit->GetRadius()); //unit��ǰ���ϽǸ���
	endGrid = gameMap->GetGrid(((Bacterium*)unit)->GetDestinationPosition().x - unit->GetRadius(), ((Bacterium*)unit)->GetDestinationPosition().y - unit->GetRadius()); //Ŀ�ĵظ���
	gameMap->RefreshMap(); // ˢ�µ�ͼ
	((Bacterium*)unit)->RouteList().clear(); //���·��
	//���������
	numberOfOpenListGrids = 0;
	previousID = 1;
	closeList.clear();

	//����ͷ��㲢����Open��
	Grid *headGrid, *bestGrid; //ͷ��㣬���Ž��
	headGrid = startGrid;
	headGrid->hValue = GetHValue(startGrid, endGrid);
	headGrid->fValue = headGrid->gValue + headGrid->hValue;
	headGrid->openList_ID = previousID;
	InsertOpenList(headGrid);

	while(numberOfOpenListGrids > 0)
	{
		//��Open����ȡ��һ������ֵ��õĽڵ㲢ɾ��
		bestGrid = openList[openListID[1]];
		DeleteOpenListTopGrid();

		//���close�����㳬�����ֵ����ȡ��ǰ��Ŀ�����������Ϊ�յ�
		if (closeList.size() > 120)
		{
			endGrid = closeList.front();
			bestGrid = closeList.front();
		}

		//����ýڵ���Ŀ��ڵ���˳�
		if (bestGrid->mapX == endGrid->mapX && bestGrid->mapY == endGrid->mapY)
		{
			//���·��PATH
			while (bestGrid->mapX != startGrid->mapX || bestGrid->mapY != startGrid->mapY)
			{	
				Position tempPosition;
				tempPosition.x = bestGrid->postion.x + unit->GetRadius();
				tempPosition.y = bestGrid->postion.y + unit->GetRadius();
				((Bacterium*)unit)->RouteList().push_back(tempPosition);
				bestGrid = bestGrid->parent;
			}
			//�Ѹõ�λ״̬����ΪRUN 
			unit->GetFSM()->SetCurrentState(UNIT_STATE_RUN);
			((Bacterium*)unit)->SetWaitTime(0) ;
			break;
		}

		//�������ɰ˸�������ӽڵ�
		GenerateSuccessors(unit ,bestGrid);
		//�������Ľ�����close��,����close��ʼ�ձ��ֵ�һ�����Ϊ���յ�����ĵ�
		if (!closeList.empty() && bestGrid->hValue < (*closeList.begin())->hValue)
			closeList.push_front(bestGrid);
		else
			closeList.push_back(bestGrid);
		//�����Ž���״̬��Ϊ��close����
		bestGrid->state = INCLOSELIST; 
	}
}

void FindNewPathState::GenerateSuccessors(Unit* unit, Grid *bestGrid)
{
	//�������ɰ˸�������ӽڵ�
	// ����
	if (gameMap->DirectionPassable(unit, UPPERLEFT, bestGrid))
		GenerateSucc(unit, bestGrid, UPPERLEFT);
	// ��
	if (gameMap->DirectionPassable(unit, UPPER, bestGrid))
		GenerateSucc(unit, bestGrid, UPPER);
	// ����
	if (gameMap->DirectionPassable(unit, UPPERRIGHT, bestGrid))
		GenerateSucc(unit, bestGrid, UPPERRIGHT);
	// ��
	if (gameMap->DirectionPassable(unit, RIGHT, bestGrid))
		GenerateSucc(unit, bestGrid, RIGHT);
	// ����
	if (gameMap->DirectionPassable(unit, LOWERRIGHT, bestGrid))
		GenerateSucc(unit, bestGrid, LOWERRIGHT);
	// ��
	if (gameMap->DirectionPassable(unit, LOWER, bestGrid))
		GenerateSucc(unit, bestGrid, LOWER);
	// ����
	if (gameMap->DirectionPassable(unit, LOWERLEFT, bestGrid))
		GenerateSucc(unit, bestGrid, LOWERLEFT);
	// ��
	if (gameMap->DirectionPassable(unit, LEFT, bestGrid))
		GenerateSucc(unit, bestGrid, LEFT);
}        

void FindNewPathState::GenerateSucc( Unit* unit, Grid *bestGrid, int succDirection )
{
	Grid *oldGrid = gameMap->GetGrid(bestGrid->postion.x + gameMap->Direction()[succDirection].x, bestGrid->postion.y + gameMap->Direction()[succDirection].y);
	Grid *succGrid;
	float succGValue;
	int i;

	//����ڵ��Gֵ,ֱ����+1.0��б����+1.4
	if (succDirection == UPPER || succDirection == RIGHT || succDirection == LOWER || succDirection == LEFT)
		succGValue = bestGrid->gValue + STRAIGHT_G;
	else
		succGValue = bestGrid->gValue + DIAGONAL_G;

	//�ж��ӽڵ��Ƿ���open����
	if (oldGrid->state == INOPENLIST)
	{
		//�������Ž��children�����пյ�Ԫ�أ��Ѹýڵ�Ž�ȥ
		for(i = 0; i < 8; ++i)
		{
			if( bestGrid->children[i] == NULL )
				break;
		}
		bestGrid->children[i] = oldGrid;

		//�Ƚ�Open���еĹ���ֵ�͵�ǰ�Ĺ���ֵ��ֻҪ�Ƚ�gֵ�Ϳ����ˣ�
		if ( succGValue < oldGrid->gValue )
		{
			//��ǰ�Ĺ���ֵС�͸���Open���еĹ���ֵ
			oldGrid->parent = bestGrid;
			oldGrid->gValue = succGValue;
			oldGrid->fValue = oldGrid->gValue + oldGrid->hValue;
			//����open�������������½�����һ��
			FilterUp(oldGrid->openListID_ID);
			FilterDown(oldGrid->openListID_ID);
		}
	}
	//�жϽڵ��Ƿ���close����
	else if (oldGrid->state == INCLOSELIST)
	{
		//�������Ž��children�����пյ�Ԫ�أ��Ѹýڵ�Ž�ȥ
		for(i = 0; i < 8; ++i)
		{
			if( bestGrid->children[i] == NULL )
				break;
		}
		bestGrid->children[i] = oldGrid;

		//�Ƚ�Closed���еĹ���ֵ�͵�ǰ�Ĺ���ֵ��ֻҪ�Ƚ�gֵ�Ϳ����ˣ�
		if ( succGValue < oldGrid->gValue )
		{
			//��ǰ�Ĺ���ֵС�͸���Closed���еĹ���ֵ
			oldGrid->parent = bestGrid;
			oldGrid->gValue = succGValue;
			oldGrid->fValue = oldGrid->gValue + oldGrid->hValue;
			//�����θ���oldGrid�������ӽڵ�Ĺ���ֵ���Ż��㣬�����°ѽ�����open������ֱ�Ӹ��£�
			PropagateDown(oldGrid);
		}
	}
	//��㲻��Open����Ҳ����Close����
	else
	{
		succGrid = oldGrid;
		succGrid->parent = bestGrid;
		succGrid->gValue = succGValue;
		succGrid->hValue = GetHValue(succGrid, endGrid);
		succGrid->fValue = succGrid->gValue + succGrid->hValue;
		//�ٲ���Open���У��Ż���,������open�����ǲ��ö���ѣ�����������״̬��Ϊ��open����
		InsertOpenList(succGrid);
		succGrid->state = INOPENLIST;
		//�������Ž��children�����пյ�Ԫ�أ��Ѹýڵ�Ž�ȥ
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
		//�жϷ�����Gֵ
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
		Father = nodeStack.back(); //�������һ��Ԫ�ظ���father
		nodeStack.pop_back(); //�Ƴ��������һ��Ԫ��
		for(int i = 0; i < 8; ++i)
		{
			if ((Child = Father->children[i])==NULL)      
				break;

			tempGValue = Father->gValue ;
			//�жϷ�����Gֵ
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

//�ü�Ȩ�����hֵ�������10��6�Ǹ����ǵó��ľ���ֵ��������
float FindNewPathState::GetHValue(Grid *startGrid, Grid *endGrid)
{
	if (abs(endGrid->postion.x - startGrid->postion.x) > abs(endGrid->postion.y - startGrid->postion.y)) 
		return 10*abs(endGrid->postion.x - startGrid->postion.x)+6*abs(endGrid->postion.y - startGrid->postion.y); 
	else 
		return 10*abs(endGrid->postion.y - startGrid->postion.y)+6*abs(endGrid->postion.x - startGrid->postion.x);
}

void FindNewPathState::InsertOpenList( Grid *newNode )
{
	newNode->openList_ID = ++previousID; //�½ڵ�open�����ID����ǰһ�ڵ��ID+1
	++numberOfOpenListGrids; //�ڵ�����+1
	newNode->openListID_ID = numberOfOpenListGrids; //�½ڵ�openID�����ID���ڵ�ǰ�ڵ���
	openListID[newNode->openListID_ID] = newNode->openList_ID; 
	openList[newNode->openList_ID] = newNode; 
	FilterUp(newNode->openListID_ID); //���½ڵ�������
}

void FindNewPathState::DeleteOpenListTopGrid( void )
{
	openListID[1] = openListID[numberOfOpenListGrids]; //�����һ���ڵ��Ƶ�����
	openList[openListID[1]]->openListID_ID = 1; //�Ѹýڵ���openListID�����λ�ø�Ϊ1
	--numberOfOpenListGrids;
	FilterDown(1); //�ö��˽ڵ����½�
}

void FindNewPathState::FilterDown( int hole )
{
	int tempHole = hole, tempOpenList_ID, tempOpenListID_ID;;

	while (1)
	{
		hole = tempHole;
		if ((2*hole+1) <= numberOfOpenListGrids) //�жϵ�ǰ�ڵ��Ƿ�ӵ�������ӽڵ�
		{
			//ѡ�������ӽڵ���F��͵��Ǹ�
			if (openList[openListID[hole]]->fValue >= openList[openListID[2*hole]]->fValue) 
				tempHole = 2*hole;
			if (openList[openListID[tempHole]]->fValue >= openList[openListID[2*hole+1]]->fValue)
				tempHole = 2*hole + 1;
		}
		else if((2*hole) <= numberOfOpenListGrids)//�жϵ�ǰ�ڵ��Ƿ�ӵ��һ���ڵ�
		{
			if (openList[openListID[hole]]->fValue >= openList[openListID[2*hole]]->fValue)
				tempHole = 2*hole;
		}


		//�����ڵ�
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

	//��Ԫ��û�е��ﶥ���ǣ�ִ�����´���
	while(hole != 1)
	{
		//����ֽڵ��Ƿ�С�ڸ��ڵ��Fֵ��Ϊtrue�򽻻�
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