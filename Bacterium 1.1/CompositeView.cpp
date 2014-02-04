#include "CompositeView.h"


CompositeView::CompositeView(void):leave(false)
{
	compositeViewGUI = new hgeGUI();
	fnt = new hgeFont("font1.fnt");
	snd = hge->Effect_Load("menu.wav");

	texMouse = hge->Texture_Load("cursor.png");
	spMouse  = new hgeSprite(texMouse, 0, 0, 32, 32); 
	compositeViewGUI->SetCursor(spMouse);

	texPlus     = hge->Texture_Load("+++.png");
	
	texButtonBg = hge->Texture_Load("ui_default_button_background.png");

	spPlus      = new hgeSprite(texPlus,     0, 0, 32, 32);
	spButtonBg  = new hgeSprite(texButtonBg, 0, 0, 64, 64);

	pLCompositeFrame = new 	CompositeFrame(258, 333, 274, 349, 245, 320, spButtonBg); 
	pRCompositeFrame = new	CompositeFrame(358, 333, 374, 349, 345, 320, spButtonBg); 

	

	Initialize();
	compositeViewGUI->Enter();
}


CompositeView::~CompositeView(void)
{
}


void CompositeView::Initialize(void)
{
	float x = 200;
	float y = 100;	
	float delay = 0.8f;

	//compositeViewGUI->AddCtrl(new UICompositeFrame(1, spButtonBg, 245, 320));///过期代码 可以删除
	//compositeViewGUI->AddCtrl(new UICompositeFrame(2, spButtonBg, 345, 320));
	compositeViewGUI->AddCtrl(new UICompositeFrame(3, spButtonBg, 445, 320));

	for(vector<GeneSegment*>::iterator itor = pStore->vectGeneSegments.begin();
		                         itor != pStore->vectGeneSegments.end(); ++itor)
	{
		x += 45;
		compositeViewGUI->AddCtrl(new hgeGUIDNAButton((*itor)->ID, fnt, 
			                        (*itor)->spr, x, y, delay, "hehe"));
		delay -= 0.04f;
		if(x == 425)
		{
			x  =  200;
			y +=  60;
		}
	}
	compositeViewGUI->AddCtrl(new hgeGUIMenuItem(97, fnt, snd, 410, 328, 0.1f, "="));
	compositeViewGUI->AddCtrl(new hgeGUIMenuItem(98, fnt, snd, 100, 500, 0.1f, "continue"));
	compositeViewGUI->AddCtrl(new hgeGUIMenuItem(99, fnt, snd, 650, 500, 0.1f, "Back to MainMenu"));
	compositeViewGUI->SetFocus(98);
}

GameStateConstant CompositeView::Frame(GameStateConstant* gameStateConstant)
{
	float dt=hge->Timer_GetDelta();
	int id;
	static int lastid=0;

	id = compositeViewGUI->Update(dt);
	
	if(id ==97)	
	{
		CompositeNewBtm();
	}	
	else if(id == -1)
	{
		if(lastid == 99)
		{			
			lastid = 0;
			return *gameStateConstant = MAINMENU;
		}		
	}
	else if(id) 
	{ 
		lastid = id; 
		if(id == 99)
		{
			leave = true;
			compositeViewGUI->Leave();
		}
	}
	if(!leave)
	{
		CompositeTest();
	}
	return RELAX;
}

void CompositeView::Render(void)
{	
	spPlus->Render(300, 328);	

	pLCompositeFrame->Render();
	pRCompositeFrame->Render();

	compositeViewGUI->Render();

	if(pStore->pBtmPiece_Kind!=0)
	{
		(*pStore->pBtmPiece_Kind)->Render();
	}
}

void CompositeView::Enter(void)
{
	compositeViewGUI->Enter();
	leave = false;
}

void CompositeView::CompositeTest(void)
{
	if(hge->Input_KeyUp(HGEK_LBUTTON))
	{
		int ID = compositeViewGUI->GetFocus();
		if(pLCompositeFrame->rect.Intersect(
			&compositeViewGUI->GetCtrl(ID)->rect))
		{
			compositeViewGUI->GetCtrl(ID)->rect.Set(248, 323, 312, 387);
			pLCompositeFrame->ID = ID;
			pLCompositeFrame->beShaded = true;
		}
		else if(pRCompositeFrame->rect.Intersect(
			&compositeViewGUI->GetCtrl(ID)->rect))
		{
			compositeViewGUI->GetCtrl(ID)->rect.Set(348, 323, 412, 387);
			pRCompositeFrame->ID = ID;
			pRCompositeFrame->beShaded = true;			
		}
	}
}


void CompositeView::CompositeNewBtm(void)
{
	if(pLCompositeFrame->beShaded && pRCompositeFrame->beShaded)
	{		
		for(vector<pair<pair<int, int>, int>>::iterator 
			itor = pStore->vectformulas.begin();
			itor != pStore->vectformulas.end(); 
	       	++itor)
		{
			if((pLCompositeFrame->ID == itor->first.first &&
				pRCompositeFrame->ID == itor->first.second)||
			   (pLCompositeFrame->ID == itor->first.second &&
				pRCompositeFrame->ID == itor->first.first))
			{				
				for(vector<BtmPiece_Kind*>::iterator 
					pos = pStore->vectBtmPiece_Kinds.begin();
					pos != pStore->vectBtmPiece_Kinds.end(); 
				    ++pos)
				{
					if((*pos)->ID == itor->second)
					{
						pStore->pBtmPiece_Kind = &(*pos);
						(*pos)->bLock = false;
						break;
					}
				}
				break;			   
			}
		}
	}
}