#include "MiniMap.h"


MiniMap::MiniMap(void)
{
	miniMapX = 0; 
	miniMapY = SCREEN_HEIGHT - MINIMAP_HEIGHT;
	miniMapSpr = new hgeSprite((MANAGER_RESOURCES->GetMapTexture())["miniMap"],0,0,MINIMAP_WIDTH,MINIMAP_HEIGHT);
}

MiniMap::~MiniMap(void)
{
}

MiniMap* MiniMap::GetInstance( void )
{
	static MiniMap* miniMapInstance;
	if (!miniMapInstance)
	{
		miniMapInstance = new MiniMap();
	}
	return miniMapInstance;
}

void MiniMap::MiniMapRender( void )
{
	miniMapSpr->Render(miniMapX,miniMapY); 
}
