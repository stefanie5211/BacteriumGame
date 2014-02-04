#pragma once
#include "stdafx.h"
#include "StarBacterium.h"
#include "BallBacterium.h"
#include "Constant.h"
#include "ParticleManager.h"
#include "ResourcesManager.h"
#include "PatrolState.h"
#include "GameMap.h"
class ChapterManager
{
public:
	ChapterManager(void);
	~ChapterManager(void);

	static ChapterManager*      GetInstance(void);

    void                        LoadingChapter01(void);
	void                        LoadingChapter02(void);
	void                        SelectChapterLoading(int &chapterNum);

	vector<Unit*>*              GetUnitsAllAddress(void) { return &unitsAll; } 
	vector<Unit*>*              GetUnitsFriendAddress(void) { return &unitsFriend; } 
	vector<Unit*>*              GetUnitsFoeAddress(void) { return &unitsFoe; } 
	vector<Unit*>*              GetUnitsHumanAddress(void) { return &unitsHuman; } 
	GameMap*                    GetGameMapAddress(void)  { return gameMap; }

private:
	vector<Unit*>  unitsAll;
	vector<Unit*>  unitsFriend;
	vector<Unit*>  unitsFoe;
	vector<Unit*>  unitsHuman;

	GameMap* gameMap;

	HTEXTURE       tex;
	HGE*           hge;
};
