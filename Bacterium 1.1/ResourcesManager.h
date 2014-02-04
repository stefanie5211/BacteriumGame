#pragma once
#include "stdafx.h"

typedef map<string, HTEXTURE>::value_type texture;
typedef map<string, HMUSIC>::value_type music;
typedef map<string, HEFFECT>::value_type effect;
typedef map<string, hgeFont*>::value_type font;

class ResourcesManager
{
public:
	ResourcesManager(void);
	~ResourcesManager(void);

	static ResourcesManager*         GetInstance(void);
	void                             Serialize(void);

	bool                             InitResource(void);
	bool                             LoadingPicture(void);
	bool                             LoadingMusic(void);
	bool                             LoadingEffect(void);
	bool                             LoadingFont(void);

	map<string, HTEXTURE>&           GetMapTexture(void) { return mapTexture; }
	map<string, HMUSIC>&             GetMapMusic(void) { return mapMusic; };
	map<string, HEFFECT>&            GetMapEffect(void) { return mapEffect; };
	map<string, hgeFont*>&           GetMapFont(void) { return mapFont; };

private:
	hgeResourceManager               *hgeRM;
	map<string, HTEXTURE>            mapTexture;
	map<string, HMUSIC>              mapMusic;
	map<string, HEFFECT>             mapEffect;
	map<string, hgeFont*>            mapFont;

	HGE*                             hge;
};

