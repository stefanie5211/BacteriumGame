#include "Option.h"


Option::Option()
{
	texMouse         = hge->Texture_Load("cursor.png");
	spMouse          = new hgeSprite(texMouse, 0, 0, 32, 32);	

	fnt              = new hgeFont("font1.fnt");
	snd              = hge->Effect_Load("menu.wav");

	optionGUI        = new hgeGUI();
	optionGUI->AddCtrl(new hgeGUIMenuItem(99,fnt,snd,600,500, 0,"Back To Menu"));
	optionGUI->AddCtrl(new hgeGUIMenuItem(97,fnt,snd,300,100, 0, "-"));
	optionGUI->AddCtrl(new hgeGUIMenuItem(98,fnt,snd,550,100, 0,"+"));
	for(int i=1; i<=30; ++i){
		optionGUI->AddCtrl(new VolumeGUI(i,fnt,snd,350+i*5,100,"|"));
		optionGUI->GetCtrl(i)->SetColor(0xFFFFE060);
	}
	optionGUI->SetCursor(spMouse);
	fntVol           = new hgeFont("font1.fnt");
	fntVol->SetColor(0xFFFFE060);
	//vol              = 50;
}


Option::~Option(void)
{
}

void Option::Enter(void)
{
	optionGUI->Enter();
}
GameStateConstant Option::Frame(GameStateConstant* gameStateConstant)
{
	float dt=hge->Timer_GetDelta();
	int id = optionGUI->Update(dt);
	
	if(id>0&&id<=30)
	{
		pEffect->vol = id*100/30;
	}
	switch(id)
	{
	case 99:
		return *gameStateConstant = MAINMENU;
	case 97:
		pEffect->vol -= 100/30;
		break;
	case 98:
		pEffect->vol += 100/30;
		break;
	}

	hge->Channel_SetVolume(pEffect->channel, pEffect->vol);
	return RELAX;
}

void Option::Render( void )
{
	fntVol->Render(150, 100, 0, "Volume");

	for(int i=1;i<=30;++i){
		if(i <= pEffect->vol*30/100)
		    optionGUI->GetCtrl(i)->SetColor(0xFFFFFFFF);
	    else
			optionGUI->GetCtrl(i)->SetColor(0xFFFFE060);
	}
	optionGUI->Render();
}
