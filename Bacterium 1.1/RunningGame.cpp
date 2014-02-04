#include "RunningGame.h"


RunningGame::RunningGame(void)
{
	unitsAll = MANAGER_CHAPTER->GetUnitsAllAddress();
	gameMap = MANAGER_CHAPTER->GetGameMapAddress();
	eventManager = new EventManager();

	runningGameGUI = new hgeGUI();

	texMouse = hge->Texture_Load("cursor.png");
	spMouse  = new hgeSprite(texMouse, 0, 0, 32, 32); 
	runningGameGUI->SetCursor(spMouse);
	Initialize();
}


RunningGame::~RunningGame(void)
{

}

void RunningGame::Initialize(void)
{
	texSkill     = hge->Texture_Load("skill.png");
	texSkillBg   = hge->Texture_Load("ui_default_button_background.png");
	snd          = hge->Effect_Load("menu.wav");
	texButtonBar = hge->Texture_Load("color.jpg");
	texBg        = hge->Texture_Load("gameBg.jpg");

	//spBg             = new hgeSprite(texBg, 0, 0, 1920, 1200);
	spBar            = new hgeSprite(texButtonBar, 160, 480, 640, 120);
	spSkillBotton    = new hgeSprite(texSkill,   0, 0, 64, 64);	
	spSkillBottonBg  = new hgeSprite(texSkillBg, 0, 0, 64, 64);
	fnt = new hgeFont("font1.fnt");

	runningGameGUI->AddCtrl(new hgeGUISkillButton(1, fnt, spSkillBotton, snd, 405,525, "Hello, Word"));
	runningGameGUI->AddCtrl(new hgeGUISelectedButton(2, fnt, 485,525));
	runningGameGUI->AddCtrl(new hgeGUISelectedButton(3, fnt, 515,525));
	runningGameGUI->AddCtrl(new hgeGUISelectedButton(4, fnt, 545,525));
	runningGameGUI->AddCtrl(new hgeGUISelectedButton(5, fnt, 575,525));
	runningGameGUI->AddCtrl(new hgeGUISelectedButton(6, fnt, 605,525));
	runningGameGUI->AddCtrl(new hgeGUISelectedButton(7, fnt, 635,525));
}

void RunningGame::Enter(void)
{
	runningGameGUI->Enter();
}

GameStateConstant RunningGame::Frame(GameStateConstant* gameStateConstant)
{
	eventManager->LeftClickEvent();
	eventManager->MouseFrameEvent();
	eventManager->RightClickEvent();
	//eventManager->UnitAttackEvent();
	eventManager->Update();
	//eventManager->UnitMoveEvent();
	eventManager->UnitDieEvent();
	eventManager->BulletMoveEvent();
	eventManager->WinOrFail();

	float dt=hge->Timer_GetDelta();
	int id;
	static int lastid=0;

	if(hge->Input_GetKeyState(HGEK_ESCAPE)) 
	{
		runningGameGUI->Leave(); 
		*gameStateConstant = COMPOSITEVIEW;
	}
	id = runningGameGUI->Update(dt);
	
	switch(id)
	{
	case 1:
		eventManager->BuildUnits(1);
		break;
	case 2:
		eventManager->SelecteUnitType(dynamic_cast<hgeGUISelectedButton*>
			                   (runningGameGUI->GetCtrl(2))->GetUnitType());
		break;
	case 3:
		eventManager->SelecteUnitType(dynamic_cast<hgeGUISelectedButton*>
			                   (runningGameGUI->GetCtrl(3))->GetUnitType());
		break;
	case 4:
		eventManager->SelecteUnitType(dynamic_cast<hgeGUISelectedButton*>
		                       (runningGameGUI->GetCtrl(4))->GetUnitType());
		break;
	case 5:
		eventManager->SelecteUnitType(dynamic_cast<hgeGUISelectedButton*>
			(runningGameGUI->GetCtrl(5))->GetUnitType());
		break;
	case 6:
		eventManager->SelecteUnitType(dynamic_cast<hgeGUISelectedButton*>
			(runningGameGUI->GetCtrl(6))->GetUnitType());
		break;
	case 7:
		eventManager->SelecteUnitType(dynamic_cast<hgeGUISelectedButton*>
			(runningGameGUI->GetCtrl(7))->GetUnitType());
		break;
	}

	SelectGUISetting();
	return RELAX;
}

void RunningGame::Render( void )
{
	/*spBg->Render(0, 0);*/
	spBar->Render(160, 480);
	spSkillBottonBg->Render(400,520);
	MINIMAP->MiniMapRender();
	runningGameGUI->Render();
	eventManager->MouseMoveEvent();
	eventManager->MouseFrameRender();
	eventManager->MouseOverUnitEvent();
	eventManager->UnitsSelectedCircleRender();
	
	CAMERA->Render();
}

void RunningGame::SelectGUISetting(void)
{	
	if(hge->Input_KeyUp(HGEK_LBUTTON))
	{  
		multimap<UnitType, Unit*> *multUnitsSelected = eventManager->GetUnitsSelected();
		int count = multUnitsSelected->size();
		
		static int lastCount = 0;

		if(count != 0)
		{
			if(count > 6)
			{
				map<UnitType, int> mapCountOfUnitType;
				for(multimap<UnitType, Unit*>::iterator itor = multUnitsSelected->begin();
					itor != multUnitsSelected->end(); ++itor)
				{
					++mapCountOfUnitType[itor->first];
				}
				map<UnitType, int>::iterator itor = mapCountOfUnitType.begin(); 

				for(size_t ID = 2; ID < 8 ; ++ID)
				{
					if(itor != mapCountOfUnitType.end())
					{
						dynamic_cast<hgeGUISelectedButton*>(runningGameGUI->GetCtrl(ID))->
							SetNumAndUnitType(itor->first, itor->second);
						++itor;
					}
					else
					{
						dynamic_cast<hgeGUISelectedButton*>(runningGameGUI->GetCtrl(ID))->
							SetNumAndUnitType((UnitType)0, 0);
					}
				}
			}
			else
			{
				multimap<UnitType, Unit*>::iterator itor = multUnitsSelected->begin();
				for(size_t ID = 2; ID < 8 ; ++ID)
				{
					if(itor != multUnitsSelected->end())
					{
						dynamic_cast<hgeGUISelectedButton*>(runningGameGUI->GetCtrl(ID))->
							SetNumAndUnitType(itor->first, 1);
						++itor;
					}
					else
					{
						dynamic_cast<hgeGUISelectedButton*>(runningGameGUI->GetCtrl(ID))->
							SetNumAndUnitType((UnitType)0, 0);
					}
				}
			}
		}
		else if(lastCount)
		{
			for(size_t i = 2; i < 8; ++i)
			{
				dynamic_cast<hgeGUISelectedButton*>(runningGameGUI->GetCtrl(i))-> 
					SetNumAndUnitType((UnitType)0 , 0);
			}
		}

		lastCount = count;	

	}
}