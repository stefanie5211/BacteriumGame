#pragma once
#include "Unit.h"
class Grid
{
public:
	Grid(void);
	~Grid(void);
	int mapX, mapY; //������grids�������������
	int openList_ID; //open�����ID
	int openListID_ID; //open�����ID
	Grid* parent; //���ڵ�
	Grid* children[8]; //�ӽڵ�
	Position postion;  //�������Ͻ�����
	float hValue; 
	float gValue;
	float fValue;
	int state; //��ǰ״̬����open�����close����򶼲��ڣ�
	bool passable; //��ͼ�ϸõ��Ƿ����ϰ���
};

