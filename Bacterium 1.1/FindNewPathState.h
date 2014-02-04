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
	void  GenerateSuccessors(Unit* unit, Grid *BestNode); //生成八个方向子节点
	void  GenerateSucc(Unit* unit, Grid *BestNode, int succDirection); //子节点构造
	void  PropagateDown(Grid *Old); //重新扫描更新节点
	float GetHValue(Grid *startGrid, Grid *endGrid);  //获取h值
	void  InsertOpenList(Grid *newNode); //将新节点插入open表
	void  DeleteOpenListTopGrid(void); //删除open表的头结点
	void  FilterDown(int hole);  //向下降
	void  FilterUp(int hole); //向上升

private:
	int           openListID[200*150 + 1]; //用二叉堆存放Grid的编号,大小等于地图宽X地图高，
	Grid          *openList[200*150 + 1]; //open表,大小等于地图宽X地图高
	int           numberOfOpenListGrids; //open表节点数量
	int           previousID; //前一个节点编号
	list<Grid*>   closeList;	//close表
	vector<Grid*> nodeStack; //结点栈
	Grid          *startGrid, *endGrid; //开始和结束结点
	GameMap *gameMap;
};

