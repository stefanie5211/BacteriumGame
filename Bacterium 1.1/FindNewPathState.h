#pragma once
#include "Unit.h"
#include "ChapterManager.h"
//#include "FindPath.h"
#include "RunState.h"
class FindNewPathState :
	public UnitState<Unit>
{
public:
	FindNewPathState(void);
	~FindNewPathState(void);
	static UnitState<Unit>* GetInstance();
	void Enter(Unit* unit);
	void Execute(Unit* unit);
	void Exit(Unit* unit);
	void FindNewPath(Unit *unit);

private:
	void  GenerateSuccessors(Unit* unit, Grid *BestNode); //���ɰ˸������ӽڵ�
	void  GenerateSucc(Unit* unit, Grid *BestNode, int succDirection); //�ӽڵ㹹��
	void  PropagateDown(Grid *Old); //����ɨ����½ڵ�
	float GetHValue(Grid *startGrid, Grid *endGrid);  //��ȡhֵ
	void  InsertOpenList(Grid *newNode); //���½ڵ����open��
	void  DeleteOpenListTopGrid(void); //ɾ��open���ͷ���
	void  FilterDown(int hole);  //���½�
	void  FilterUp(int hole); //������

private:
	int           openListID[200*150 + 1]; //�ö���Ѵ��Grid�ı��,��С���ڵ�ͼ��X��ͼ�ߣ�
	Grid          *openList[200*150 + 1]; //open��,��С���ڵ�ͼ��X��ͼ��
	int           numberOfOpenListGrids; //open��ڵ�����
	int           previousID; //ǰһ���ڵ���
	list<Grid*>   closeList;	//close��
	vector<Grid*> nodeStack; //���ջ
	Grid          *startGrid, *endGrid; //��ʼ�ͽ������
	GameMap *gameMap;
};

