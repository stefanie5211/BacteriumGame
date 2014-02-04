#include "ChapterManager.h"


ChapterManager::ChapterManager(void)
{
	hge = hgeCreate(HGE_VERSION);
}


ChapterManager::~ChapterManager(void)
{
}

ChapterManager* ChapterManager::GetInstance( void )
{
	static ChapterManager *chapterManagerInstance;
	if(!chapterManagerInstance)
	{	  
		chapterManagerInstance = new ChapterManager();
	}
	return chapterManagerInstance;
}

void ChapterManager::LoadingChapter01( void )
{
	Unit* ballBac1 = new BallBacterium(1,100,200,FRIEND,(MANAGER_RESOURCES->GetMapTexture())["particles"], (MANAGER_RESOURCES->GetMapTexture())["FriendCircle"],(MANAGER_RESOURCES->GetMapTexture())["FriendPoint"], MANAGER_PARTICLE->WeaponParBall(), MANAGER_PARTICLE->DeathParBoom());
	Unit* ballBac2 = new BallBacterium(2,100,300,FRIEND,(MANAGER_RESOURCES->GetMapTexture())["particles"], (MANAGER_RESOURCES->GetMapTexture())["FriendCircle"],(MANAGER_RESOURCES->GetMapTexture())["FriendPoint"], MANAGER_PARTICLE->WeaponParBall(), MANAGER_PARTICLE->DeathParBoom());
	Unit* starBac1 = new StarBacterium(3,400,400,FOE,   (MANAGER_RESOURCES->GetMapTexture())["particles"], (MANAGER_RESOURCES->GetMapTexture())["FoeCircle"],(MANAGER_RESOURCES->GetMapTexture())["FoePoint"], MANAGER_PARTICLE->WeaponParBall(), MANAGER_PARTICLE->DeathParBoom());
	Unit* starBac2 = new StarBacterium(4,300,400,FOE,   (MANAGER_RESOURCES->GetMapTexture())["particles"], (MANAGER_RESOURCES->GetMapTexture())["FoeCircle"],(MANAGER_RESOURCES->GetMapTexture())["FoePoint"], MANAGER_PARTICLE->WeaponParBall(), MANAGER_PARTICLE->DeathParBoom());

	Unit* starBac3 = new StarBacterium(5,200,200,FRIEND, (MANAGER_RESOURCES->GetMapTexture())["particles"], (MANAGER_RESOURCES->GetMapTexture())["FoeCircle"],(MANAGER_RESOURCES->GetMapTexture())["FoePoint"], MANAGER_PARTICLE->WeaponParBall(), MANAGER_PARTICLE->DeathParBoom());
	Unit* starBac4 = new StarBacterium(6,200,300,FRIEND, (MANAGER_RESOURCES->GetMapTexture())["particles"], (MANAGER_RESOURCES->GetMapTexture())["FoeCircle"],(MANAGER_RESOURCES->GetMapTexture())["FoePoint"], MANAGER_PARTICLE->WeaponParBall(), MANAGER_PARTICLE->DeathParBoom());

	unitsAll.push_back(ballBac1);
	unitsFriend.push_back(ballBac1);
	unitsAll.push_back(ballBac2);
	unitsFriend.push_back(ballBac2);
	unitsAll.push_back(starBac3);
	unitsFriend.push_back(starBac3);
	unitsAll.push_back(starBac4);
	unitsFriend.push_back(starBac4);

	unitsAll.push_back(starBac1);
	unitsFoe.push_back(starBac1);
	unitsAll.push_back(starBac2);
	unitsFoe.push_back(starBac2);

	ballBac1->GetFSM()->SetCurrentState(UNIT_STATE_PATROL);
	ballBac2->GetFSM()->SetCurrentState(UNIT_STATE_PATROL);
	starBac1->GetFSM()->SetCurrentState(UNIT_STATE_PATROL);
	starBac2->GetFSM()->SetCurrentState(UNIT_STATE_PATROL);
	starBac3->GetFSM()->SetCurrentState(UNIT_STATE_PATROL);
	starBac4->GetFSM()->SetCurrentState(UNIT_STATE_PATROL);
	((Bacterium*)ballBac1)->SetFollowUnit(ballBac2);
	ballBac1->SetUnitState(FOLLOWING);

	gameMap = new GameMap((MANAGER_RESOURCES->GetMapTexture())["background"], &unitsAll);
}

void ChapterManager::LoadingChapter02( void )
{

}

void ChapterManager::SelectChapterLoading( int &chapterNum )
{
	switch (chapterNum)
	{
	case 1:
		LoadingChapter01();
	case 2:
		LoadingChapter02();
	}
}
