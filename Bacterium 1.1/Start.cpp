#include "Start.h"


Start::Start(void)
{
	startGUI = new hgeGUI();

	fnt = new hgeFont("font1.fnt");
	snd = hge->Effect_Load("menu.wav");

	texMouse = hge->Texture_Load("cursor.png");
	spMouse = new hgeSprite(texMouse, 0, 0, 32, 32); 
	startGUI->SetCursor(spMouse);
	startGUI->AddCtrl(new hgeGUIMenuItem(1,  fnt, snd, 400, 220, 0.1f, "New Game"));
	startGUI->AddCtrl(new hgeGUIMenuItem(2,  fnt, snd, 400, 260, 0.2f, "LOAD GAME"));
	startGUI->AddCtrl(new hgeGUIMenuItem(99, fnt, snd, 600, 500, 0.1f, "Back to MainMenu"));
}


Start::~Start(void)
{
}

void Start::Enter(void)
{
	startGUI->Enter();
}


GameStateConstant Start::Frame(GameStateConstant *gameStateConstant)
{
	float dt=hge->Timer_GetDelta();
	int id;
	static int lastid=0;

	// 如果按 ESCAPE 了告诉 GUI 来完成
	if(hge->Input_GetKeyState(HGEK_ESCAPE)) { lastid=5;startGUI->Leave(); }
	
	// 我们更新图形用户界面，并采取行动，如果选择了一个菜单项
	id = startGUI->Update(dt);
	if(id == -1)
	{
		switch(lastid )
		{
		case 1:
			return *gameStateConstant = SELECTSOLDIERVIEW;
		case 2:
			return *gameStateConstant = LOADGAME;
		case 99:
			return *gameStateConstant = MAINMENU;
		}
	}
	else if(id) { lastid=id; startGUI->Leave(); }
	
	return RELAX;
}

void Start::Render(void)
{
	startGUI->Render();
}
