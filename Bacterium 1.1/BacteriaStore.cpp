#include "BacteriaStore.h"


BacteriaStore::BacteriaStore(void)
{
	fnt = new hgeFont("font1.fnt");
	snd = hge->Effect_Load("menu.wav");

	texMouse = hge->Texture_Load("cursor.png");
	spMouse = new hgeSprite(texMouse, 0, 0, 32, 32); 
	
}


BacteriaStore::~BacteriaStore(void)
{
	for(size_t i = 0; i < vectPiece_kinds.size(); ++i)
	{
		delete vectPiece_kinds[i];
	}
}

void BacteriaStore::Initialize(void)
{
	float x = 300;
	float y = 100;	
	float delay = 0.8f;

	bacteriaStoreGUI = new hgeGUI();
	bacteriaStoreGUI->SetCursor(spMouse);
	for(vector<BtmPiece_Kind*>::iterator itor = pStore->vectBtmPiece_Kinds.begin();
		                           itor != pStore->vectBtmPiece_Kinds.end(); ++itor)
	{
		x += 75;
		bacteriaStoreGUI->AddCtrl(new hgeGUIBacteriaMenu((*itor)->ID,fnt, (*itor)->spCard,
			               (*itor)->spLock,snd, x, y, delay, (*itor)->bLock, "hehehehrhr"));
		delay -= 0.04f;
		if(x == 675)
		{
			x  =  300;
			y +=  100;
		}
	}
	

	bacteriaStoreGUI->AddCtrl(new hgeGUIMenuItem(99, fnt, snd, 500, 500, 0.1f, "Back to MainMenu"));	
}

void BacteriaStore::Servicelize(void)
{
	delete bacteriaStoreGUI;
}

void BacteriaStore::Enter(void)
{
	Initialize();
	bacteriaStoreGUI->Enter();
	
}

void BacteriaStore::AddBacteria(Bacteria* bacteria)
{
	vectPiece_kinds.push_back(bacteria);
}

GameStateConstant BacteriaStore::Frame(GameStateConstant *gameStateConstant)
{
	float dt=hge->Timer_GetDelta();
	int id;
	static int lastid=0;

	// 如果按 ESCAPE 了告诉 GUI 来完成
	if(hge->Input_GetKeyState(HGEK_ESCAPE)) { lastid=5;bacteriaStoreGUI->Leave(); }
	
	// 我们更新图形用户界面，并采取行动，如果选择了一个菜单项
	id = bacteriaStoreGUI->Update(dt);
	if(id == -1)
	{
		if(lastid == 99)
		{
	        Servicelize();
			return *gameStateConstant = MAINMENU;
		}
	}
	else if(id) 
	{ 
		lastid=id; 
		if(id == 99)
		{
			bacteriaStoreGUI->Leave();
		}
	}
	
	return RELAX;
}

void BacteriaStore::Render(void)
{	
	bacteriaStoreGUI->Render();
	hge->Gfx_RenderLine(30,  20,  250, 20,  0xFFFF8000);
	hge->Gfx_RenderLine(30,  20,  30,  580, 0xFFFF8000);
	hge->Gfx_RenderLine(250, 20,  250, 580, 0xFFFF8000);
	hge->Gfx_RenderLine(30,  580, 250, 580, 0xFFFF8000);
}
