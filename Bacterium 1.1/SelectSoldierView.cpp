#include "SelectSoldierView.h"


SelectSoldierView::SelectSoldierView(void)
{
	//hge              = hgeCreate(HGE_VERSION);

	texMouse         = hge->Texture_Load("cursor.png");
	spMouse          = new hgeSprite(texMouse, 0, 0, 32, 32);	

	fnt              = new hgeFont("font1.fnt");
	snd              = hge->Effect_Load("menu.wav");

	beSelectFrame    = hge->Texture_Load("");
	//spbeSelectFrame  = new hgeSprite(beSelectFrame);

	SelectedFrame    = hge->Texture_Load("");
	//spSelectedFrame  = new hgeSprite(SelectedFrame);

	selectSoldierGUI = new hgeGUI();
	selectSoldierGUI->AddCtrl(new hgeGUIMenuItem(99,fnt,snd,600,500, 0,"Back To Menu"));
	selectSoldierGUI->AddCtrl(new hgeGUIMenuItem(98,fnt,snd,300,500, 0, "OK"));
	selectSoldierGUI->AddCtrl(new SelectSoldierGUI(1,hge->Texture_Load("cake1.jpg"),150,350,0,0,100,100));
	selectSoldierGUI->AddCtrl(new SelectSoldierGUI(2,hge->Texture_Load("cake2.jpg"),250,350,0,0,100,100));
	selectSoldierGUI->SetCursor(spMouse);
	backGround       = hge->Texture_Load("sv.jpg");
	spBackGround     = new hgeSprite(backGround, 0, 0, 800, 600);
}


SelectSoldierView::~SelectSoldierView(void)
{
}

void SelectSoldierView::Enter(void)
{

}

GameStateConstant SelectSoldierView::Frame( GameStateConstant *gsc)
{
	float dt=hge->Timer_GetDelta();
	int id = selectSoldierGUI->Update(dt);
	switch(id)
	{
	case 99:
		*gsc = MAINMENU;
		break;
	case 98:
		*gsc = LOADGAME;
		break;
	default:
		*gsc = SELECTSOLDIERVIEW;
		break;
	}

	return *gsc;
}

void SelectSoldierView::Render( void )
{
	spBackGround->Render(0,0);
	//spbeSelectFrame->Render(200,400);
	//spSelectedFrame->Render(200,100);
	selectSoldierGUI->Render();
}
