#pragma once

#define SCREEN_HEIGHT 600
#define SCREEN_WIDTH 800

#define MINIMAP_HEIGHT 120
#define MINIMAP_WIDTH 160

#define BUTTON_BAR_UPPER_EDGE 480
#define BUTTON_BAR_LEFT_EDGE  160

#define STRAIGHT_G 1.0f //移动直着走G值
#define DIAGONAL_G 1.4f //移动斜这走G值

#define CAMERAMOVESPEED 3
#define GRID_LENGTH 8 //格子长度
#define MAX_WAIT_TIME 100 //碰撞检测时最长等待时间
#define CAMERA Camera::GetInstance()
#define MINIMAP MiniMap::GetInstance()
#define MOUSE Mouse::GetInstance() 
#define MANAGER_RESOURCES ResourcesManager::GetInstance() 
#define MANAGER_PARTICLE ParticleManager::GetInstance() 
#define MANAGER_CHAPTER ChapterManager::GetInstance()
#define UNIT_STATE_PATROL PatrolState::GetInstance() 
#define UNIT_STATE_ATTACK AttackState::GetInstance()
#define UNIT_STATE_RUN RunState::GetInstance()
#define UNIT_STATE_MOVE MoveState::GetInstance()
#define UNIT_STATE_WAIT WaitState::GetInstance()
#define UNIT_STATE_FOLLOW FollowState::GetInstance()
#define UNIT_STATE_FINDNEWPATH FindNewPathState::GetInstance()
enum GameStateConstant {MAINMENU, START, BACTERIASTORE, OPTION, NEWGAME, LOADGAME, FILM, CHAPTERMAP, SELECTSOLDIERVIEW, COMPOSITEVIEW, RUNNINGGAME, QUIT, RELAX};//各种游戏进程状态
enum Camp { FRIEND, FOE, HUMAN };//单位阵营
enum State { DEAD, ATTACKING, RUN, FINDNEWPATH, STILLNESS, MOVING, WAITING,FOLLOWING, CIRCULARMOTION,  STRAIGHTMOVING, DIRECTMOVE };//单位状态
enum GridDirection{ UPPERLEFT, LEFT, LOWERLEFT, LOWER, LOWERRIGHT, RIGHT, UPPERRIGHT, UPPER};//格子方向
enum GridState{ FREE, INOPENLIST, INCLOSELIST }; //格子状态
enum UnitType { CELL, STARBACTERIUM, BALLBACTERIUM, ANTIBODY };//单位类型

struct Position
{
	float x;
	float y;
};

