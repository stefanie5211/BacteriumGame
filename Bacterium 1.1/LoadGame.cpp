#include "LoadGame.h"


LoadGame::LoadGame(void)
{
}


LoadGame::~LoadGame(void)
{
}

GameStateConstant LoadGame::Frame(GameStateConstant* gameStateConstant)
{
	ifstream saveFileIn("save.txt");
	chapterNum = saveFileIn.get() - '0';
	MANAGER_CHAPTER->SelectChapterLoading(chapterNum);

	return *gameStateConstant = RUNNINGGAME;
}

void LoadGame::Render( void )
{

}