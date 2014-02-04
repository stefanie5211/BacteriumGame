#include "EventManager.h"



EventManager::EventManager( void )
{
	unitsAll      = MANAGER_CHAPTER->GetUnitsAllAddress();
	unitsFriend   = MANAGER_CHAPTER->GetUnitsFriendAddress();
	unitsFoe      = MANAGER_CHAPTER->GetUnitsFoeAddress();
	unitsHuman    = MANAGER_CHAPTER->GetUnitsHumanAddress();
	gameMap = MANAGER_CHAPTER->GetGameMapAddress();
	//moveManager   = new MoveManager();
	//attackManager = new AttackManager();
	hge           = hgeCreate(HGE_VERSION);
	unitSelected  = NULL;

	rect.Set(0, BUTTON_BAR_UPPER_EDGE, 800, 600);
}


EventManager::~EventManager(void)
{
}

void EventManager::LeftClickEvent( void )
{
	if (hge->Input_GetKey() == HGEK_LBUTTON)
	{
		hge->Input_GetMousePos(&MOUSE->framStartX, &MOUSE->framStartY); //获取鼠标左键起始坐标
		if(!rect.TestPoint(MOUSE->framStartX, MOUSE->framStartY))
		{
			unitSelected = NULL; 
			multimap<UnitType, Unit*>().swap(unitsSelected); 
			//遍历判断细菌是否被鼠标左键点中
			for (vector<Unit*>::iterator iter = unitsFriend->begin(); iter != unitsFriend->end(); ++iter)
			{
				if(pow(MOUSE->framStartX-(*iter)->GetPosition().x, 2) + pow(MOUSE->framStartY-(*iter)->GetPosition().y, 2) <= pow((*iter)->GetRadius(), 2))
				{
					unitSelected = (*iter);
					unitsSelected.insert(make_pair((*iter)->GetUnitType(), *iter));
				}
			}

			for (vector<Unit*>::iterator iter = unitsFoe->begin(); iter != unitsFoe->end(); ++iter)
			{
				if(pow(MOUSE->framStartX-(*iter)->GetPosition().x, 2) + pow(MOUSE->framStartY-(*iter)->GetPosition().y, 2) <= pow((*iter)->GetRadius(), 2))
				{
					unitSelected = (*iter);
				}
			}
		}
	}
}

void EventManager::MouseFrameEvent( void )
{
	if (hge->Input_GetKeyState(HGEK_LBUTTON))
	{
		hge->Input_GetMousePos(&MOUSE->framEndX, &MOUSE->framEndY); //获取鼠标左键结束坐标
		if(MOUSE->framEndY > BUTTON_BAR_UPPER_EDGE)
		{
			MOUSE->framEndY = BUTTON_BAR_UPPER_EDGE;
		}
		if (((MOUSE->framEndX != MOUSE->framStartX) || (MOUSE->framEndY != MOUSE->framStartY)) 
			&& !hge->Input_KeyDown(HGEK_LBUTTON) && !rect.TestPoint(MOUSE->framStartX, MOUSE->framStartY))
		{
			MOUSE->lClickAndMove = true; //将鼠标左键按下后是否移动设为true
			multimap<UnitType, Unit*>().swap(unitsSelected); //清空BacControl

			//遍历判断细菌是否处于选中框体区域内                                                                                                  
			for (vector<Unit*>::iterator iter = unitsFriend->begin(); iter != unitsFriend->end(); ++iter)
			{
				if (
					(fabs((MOUSE->framStartX + MOUSE->framEndX)/2 - (*iter)->GetPosition().x) 
					<=
					(fabs((MOUSE->framStartX - MOUSE->framEndX)/2) + 16)) 
					&& 
					(fabs((MOUSE->framStartY + MOUSE->framEndY)/2 - (*iter)->GetPosition().y) 
					<= 
					(fabs((MOUSE->framStartY - MOUSE->framEndY)/2) + 16))
					)
				{
					unitsSelected.insert(make_pair((*iter)->GetUnitType(), *iter));
				}
			}
		}
		else
		{
			MOUSE->lClickAndMove = false;
		}

	}
}


void EventManager::RightClickEvent( void )
{
	bool beInitiativeAttack = false;
	if (hge->Input_GetKey() == HGEK_RBUTTON && !unitsSelected.empty()) 
	{
		hge->Input_GetMousePos(&MOUSE->rClickX, &MOUSE->rClickY); //获取鼠标右键坐标
		for (vector<Unit*>::iterator iterA = unitsAll->begin(); iterA != unitsAll->end(); ++iterA)
		{
			if ((*iterA)->GetCamp()==FOE)
			{
				if ((sqrt(pow(MOUSE->rClickX - (*iterA)->GetPosition().x, 2) + pow(MOUSE->rClickY - (*iterA)->GetPosition().y, 2))) <= (*iterA)->GetRadius())
				{
					for(multimap<UnitType, Unit*>::iterator iterB = unitsSelected.begin(); iterB != unitsSelected.end(); ++iterB)
					{
						beInitiativeAttack = true;
						//attackManager->InitiativeAttack((Bacterium*)(iterB->second),(Bacterium*)(*iterA));
						iterB->second->SetInitiativeTarget((Bacterium*)(*iterA));
						iterB->second->SetFollowUnit((Bacterium*)(*iterA));
						iterB->second->GetFSM()->SetCurrentState(UNIT_STATE_FOLLOW);
					}
				}
			}
		}
		if (beInitiativeAttack == false)
		{
			for(multimap<UnitType, Unit*>::iterator iter = unitsSelected.begin(); iter != unitsSelected.end(); ++iter)
			{
				((Bacterium*)(iter->second))->SetAttackTarget(NULL);
				((Bacterium*)(iter->second))->SetInitiativeTarget(NULL);
				((Bacterium*)(iter->second))->SetDestinationPositionX(MOUSE->rClickX); 
				((Bacterium*)(iter->second))->SetDestinationPositionY(MOUSE->rClickY);//设置细菌移动目的地
				(iter->second)->GetFSM()->SetCurrentState(UNIT_STATE_FINDNEWPATH); //将细菌状态设置为移动
			}
		}
	}
}

void EventManager::MouseFrameRender( void )
{
	if (MOUSE->lClickAndMove)
	{
		hge->Gfx_RenderLine(MOUSE->framStartX, MOUSE->framStartY, MOUSE->framEndX, MOUSE->framStartY, 0xFF7CFC00, 0.5f);
		hge->Gfx_RenderLine(MOUSE->framEndX, MOUSE->framStartY, MOUSE->framEndX, MOUSE->framEndY, 0xFF7CFC00, 0.5f);
		hge->Gfx_RenderLine(MOUSE->framEndX, MOUSE->framEndY, MOUSE->framStartX, MOUSE->framEndY, 0xFF7CFC00, 0.5f);
		hge->Gfx_RenderLine(MOUSE->framStartX, MOUSE->framEndY, MOUSE->framStartX, MOUSE->framStartY, 0xFF7CFC00, 0.5f);
		MOUSE->lClickAndMove = false;
	}
}

void EventManager::UnitDieEvent( void )
{
	for (vector<Unit*>::iterator iterAll = unitsAll->begin(); iterAll != unitsAll->end(); )
	{
		if ((*iterAll)->GetUnitState() == DEAD)
		{
			int tempUnitID = (*iterAll)->GetUnitID();
			switch((*iterAll)->	GetCamp())
			{
			case FRIEND:
				for (vector<Unit*>::iterator iterFriend = unitsFriend->begin(); iterFriend != unitsFriend->end(); ++iterFriend)
				{
					if ((*iterFriend)->GetUnitID() == tempUnitID)
					{
						unitsFriend->erase(iterFriend);
						break;
					}
				}
				break;
			case FOE:
				for (vector<Unit*>::iterator iterFoe = unitsFoe->begin(); iterFoe != unitsFoe->end(); ++iterFoe)
				{
					if ((*iterFoe)->GetUnitID() == tempUnitID)
					{
						unitsFoe->erase(iterFoe);
						break;
					}
				}
				break;
			case HUMAN:
				break;
			}
			delete *iterAll;
			iterAll = unitsAll->erase(iterAll);
		}
		else
		{
			++iterAll;
		}
	}
}

GameStateConstant EventManager::WinOrFail( void )
{	
	return RUNNINGGAME;
}

void EventManager::UnitsSelectedCircleRender( void )
{
	if (unitSelected != NULL)
	{
		unitSelected->UnitSelectedSprRender();
	}

	for(multimap<UnitType, Unit*>::iterator iter = unitsSelected.begin(); iter != unitsSelected.end(); ++iter)
	{
		(iter->second)->UnitSelectedSprRender();
	}
}

void EventManager::MouseOverUnitEvent( void )
{
	for (vector<Unit*>::iterator iter = unitsAll->begin(); iter != unitsAll->end(); ++iter)
	{
		hge->Input_GetMousePos(&MOUSE->mousePosX, &MOUSE->mousePosY);
		if (sqrt(pow(MOUSE->mousePosX - (*iter)->GetPosition().x, 2) + pow(MOUSE->mousePosY - (*iter)->GetPosition().y, 2)) <= (*iter)->GetRadius())
		{
			(*iter)->UnitSelectedSprRender();
		}
	}
}

void EventManager::BuildUnits(int id)
{
	Unit* ballBac = new BallBacterium(5,200,300,FRIEND,(MANAGER_RESOURCES->GetMapTexture())["particles"], 
		                              (MANAGER_RESOURCES->GetMapTexture())["FriendCircle"],(MANAGER_RESOURCES->GetMapTexture())["FriendPoint"], 
		                               MANAGER_PARTICLE->WeaponParBall(), MANAGER_PARTICLE->DeathParBoom());

	unitsAll->push_back(ballBac);
	unitsFriend->push_back(ballBac);
}

void EventManager::SelecteUnitType(UnitType unitType)
{
	typedef multimap<UnitType, Unit*>::iterator authors_itor;

	multimap<UnitType, Unit*> multTemp;
	pair<authors_itor, authors_itor> pos =  unitsSelected.equal_range(unitType);

	while(pos.first != pos.second)
	{
		multTemp.insert(make_pair(pos.first->first, pos.first->second));
		++pos.first;
	}

	multimap<UnitType, Unit*>().swap(unitsSelected); 
	unitsSelected.swap(multTemp);
}

void EventManager::BulletMoveEvent( void )
{
	for (vector<Unit*>::iterator iterUnitAll = unitsAll->begin(); iterUnitAll != unitsAll->end(); ++iterUnitAll)
	{
		for(vector<Bullet*>::iterator iterBulletsVec = ((Bacterium*)(*iterUnitAll))->BulletsVec().begin(); iterBulletsVec != ((Bacterium*)(*iterUnitAll))->BulletsVec().end(); )
		{
			if ((*iterBulletsVec)->BulletMove() == false)
			{
				(*iterBulletsVec)->GetBulletPar()->Stop();
				delete *iterBulletsVec;
				iterBulletsVec = ((Bacterium*)(*iterUnitAll))->BulletsVec().erase(iterBulletsVec);
			}
			else
			{
				++iterBulletsVec;
			}
		}
	}
}

void EventManager::Update()
{
	for (vector<Unit*>::iterator iterAll = unitsAll->begin(); 
		iterAll != unitsAll->end(); ++iterAll)
	{
		(*iterAll)->Update();
	}
}

void EventManager::MouseMoveEvent( void )
{
	hge->Input_GetMousePos(&MOUSE->mousePosX, &MOUSE->mousePosY);
	if (MOUSE->mousePosX == HGE_SCREENWIDTH && CAMERA->GetMainMapPosition().x < 480 - CAMERAMOVESPEED)
	{
		CAMERA->SetMainMapPosition(CAMERA->GetMainMapPosition().x + CAMERAMOVESPEED,CAMERA->GetMainMapPosition().y);
	}
	else if (MOUSE->mousePosX == 0 && CAMERA->GetMainMapPosition().x > CAMERAMOVESPEED)
	{
		CAMERA->SetMainMapPosition(CAMERA->GetMainMapPosition().x - CAMERAMOVESPEED,CAMERA->GetMainMapPosition().y);
	}
	if (MOUSE->mousePosY == 0 && CAMERA->GetMainMapPosition().y > CAMERAMOVESPEED)
	{
		CAMERA->SetMainMapPosition(CAMERA->GetMainMapPosition().x, CAMERA->GetMainMapPosition().y -CAMERAMOVESPEED);
	}
	else if (MOUSE->mousePosY == HGE_SCREENHEIGHT && CAMERA->GetMainMapPosition().y < 200 - CAMERAMOVESPEED)
	{
		CAMERA->SetMainMapPosition(CAMERA->GetMainMapPosition().x ,CAMERA->GetMainMapPosition().y +CAMERAMOVESPEED);
	}
}
