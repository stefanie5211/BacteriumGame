#pragma once
#include "stdafx.h"
#include "UImenuitem.h"
#include "ResourcesManager.h"
#include "Constant.h"
#include "UIBacteriaStoreItem.h"
#include "UIDNAItem.h"
#include "UICompositeFrameItem.h"
#include "UISkillItem.h"
#include "PicButtonGUI.h"
#include "Effect.h"
#include "UIVolumeGUI.h"
#include "UISelectSoldierGUI.h"

class GameState
{	
public:
	GameState(void);
	virtual ~GameState(void);

	virtual GameStateConstant Frame(GameStateConstant*) = 0;
	virtual                   void Render(void)         = 0;
	virtual                   void Enter(void) {}       ;

protected:
    HGE        *hge;
};

