#include "Main_Menu.h"


Main_Menu::Main_Menu(void)
{
	mainMenuGUI = new hgeGUI();
	
	fnt = new hgeFont("font1.fnt");
	snd = hge->Effect_Load("menu.wav");
	
	mainMenuGUI->AddCtrl(new hgeGUIMenuItem(1,fnt,snd,400,220,0.0f,"Start"));
	mainMenuGUI->AddCtrl(new hgeGUIMenuItem(2,fnt,snd,400,260,0.1f,"DNAStore"));
	mainMenuGUI->AddCtrl(new hgeGUIMenuItem(3,fnt,snd,400,300,0.2f,"Options"));
	mainMenuGUI->AddCtrl(new hgeGUIMenuItem(4,fnt,snd,400,340,0.3f,"Exit"));
	
	tex = hge->Texture_Load("cursor.png");
	spMouse = new hgeSprite(tex, 0, 0, 32, 32); 
	mainMenuGUI->SetCursor(spMouse);

	mainMenuGUI->Enter();
}


Main_Menu::~Main_Menu(void)
{
}

void Main_Menu::Enter(void)
{
	mainMenuGUI->Enter();
}

GameStateConstant Main_Menu::Frame(GameStateConstant *gameStateConstant)
{
	float dt=hge->Timer_GetDelta();
	int id;
	static int lastid=0;

	// 如果按 ESCAPE 了告诉 GUI 来完成
	if(hge->Input_GetKeyState(HGEK_ESCAPE)) { lastid=5; mainMenuGUI->Leave(); }
	
	// 我们更新图形用户界面，并采取行动，如果选择了一个菜单项
	id = mainMenuGUI->Update(dt);
	if(id == -1)
	{
		switch(lastid)
		{
			case 1:
				return *gameStateConstant = START;

			case 2:
				return *gameStateConstant = BACTERIASTORE;

			case 3:
				return  *gameStateConstant = OPTION;

			case 4:
				return  *gameStateConstant = QUIT;
		}
	}
	else if(id) { lastid=id; mainMenuGUI->Leave(); }

	return RELAX;
}

void Main_Menu::Render(void)
{	
	mainMenuGUI->Render();
}