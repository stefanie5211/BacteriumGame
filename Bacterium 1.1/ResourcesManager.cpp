#include "ResourcesManager.h"

ResourcesManager::ResourcesManager(void)
{
	hge = hgeCreate(HGE_VERSION);
	hge->Resource_AttachPack( "Resource.zip" );
	hgeRM = new hgeResourceManager( "Resource.res" );
}

ResourcesManager::~ResourcesManager(void)
{
}

ResourcesManager* ResourcesManager::GetInstance( void )
{
	static ResourcesManager *resourcesManagerInstance ;
	if(!resourcesManagerInstance)
	{	  
		resourcesManagerInstance = new ResourcesManager();
	}
	return resourcesManagerInstance;
}

bool ResourcesManager::InitResource( void )
{
	LoadingPicture();
	LoadingMusic();
	LoadingEffect();
	LoadingFont();

	return true;
}

bool ResourcesManager::LoadingPicture( void )
{
	mapTexture.insert(texture("particles", hgeRM->GetTexture("particles")));
	mapTexture.insert(texture("backgroundPic", hgeRM->GetTexture("background")));
	mapTexture.insert(texture("FriendCircle", hgeRM->GetTexture("FriendCircle")));
	mapTexture.insert(texture("FoeCircle", hgeRM->GetTexture("FoeCircle")));
	mapTexture.insert(texture("miniMap", hgeRM->GetTexture("miniMap")));
	mapTexture.insert(texture("FriendPoint", hgeRM->GetTexture("FriendPoint")));
	mapTexture.insert(texture("FoePoint", hgeRM->GetTexture("FoePoint")));

	return true;
}

bool ResourcesManager::LoadingMusic( void )
{
	mapMusic.insert(music(("backgroudMusic"), hgeRM->GetMusic("backgroundMusic")));

	return true;
}

bool ResourcesManager::LoadingEffect( void )
{
	return true;
}

bool ResourcesManager::LoadingFont( void )
{
	mapFont.insert(font("font1", hgeRM->GetFont("font1")));
	return true;
}

void ResourcesManager::Serialize()
{
	mapTexture.clear();
	mapMusic.clear();
	mapEffect.clear();
	mapFont.clear();
}