#pragma once
#include "stdafx.h"
#include "ResourcesManager.h"
#include "Constant.h"
class MiniMap
{
public:
	MiniMap(void);
	~MiniMap(void);
	static MiniMap*    GetInstance(void);
	void               MiniMapRender(void);

	virtual const float& GetMiniMapX(void)             const { return miniMapX; }
	virtual const float& GetMiniMapY(void)             const { return miniMapY; }

	virtual void       SetMiniMapX(const float &newMiniMapX)   { miniMapX = newMiniMapX; }
	virtual void       SetMiniMapY(const float &newMiniMapY)   { miniMapY = newMiniMapY; }

private:
	float         miniMapX, miniMapY;             //小地图在屏幕上绘制的坐标
    hgeSprite*    miniMapSpr;    //小地图精灵
};

