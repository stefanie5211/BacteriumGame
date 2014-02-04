#include "UISelectSoldierGUI.h"


SelectSoldierGUI::SelectSoldierGUI(int _id, HTEXTURE _tex, float _x, float _y, float x1,float y1, float x2, float y2)
{
	id  = _id;
	spr = new hgeSprite(_tex, x1, y1, x2, y2);
	spr2= new hgeSprite(_tex, x1, y1, x2, y2);
	spr->SetZ(0.4);
	spr2->SetZ(0.4);

	w=spr->GetWidth();
	rect.Set(_x-w/2, _y, _x+w/2, _y+spr->GetHeight());

	initialX = _x-w/2; 
	initialY = _y;

	mouseX = 0;
	mouseY = 0;
	bDownLastTime = false;

	Array[0][0] = 100;
	Array[0][1] = 100;
	Array[1][0] = 250;
	Array[1][1] = 100;
	Array[2][0] = 400;
	Array[2][1] = 100;
	Array[3][0] = 550;
	Array[3][1] = 100;

	bSelected = false;
}

void SelectSoldierGUI::Render()
{
	spr->Render(initialX, initialY);
	spr2->Render(rect.x1, rect.y1);
}

void SelectSoldierGUI::Update( float dt )
{
	hge->Input_GetMousePos(&mouseX,&mouseY);
	if(!bDownLastTime){
		dertaX = mouseX - rect.x1;
		dertaY = mouseY - rect.y1;
	}
	else{
		rect.x1 = mouseX - dertaX;
		rect.y1 = mouseY - dertaY;
		rect.x2 = rect.x1 + w;
		rect.y2 = rect.y1 + spr->GetHeight();
	}

	float j = 100;
	int ii;
	for(int i=0;i<4;++i){
		if(abs(Array[i][0]-rect.x1)<10 && abs(Array[i][1]-rect.y1)<10)
			if(abs(Array[i][0]-rect.x1)<j){
				j = abs(Array[i][0]-rect.x1);
				ii = i;
			}
	}
	if(j!=100){
		bSelected = true;
		rect.x1 = Array[ii][0];
		rect.y1 = Array[ii][1];
		rect.x2 = rect.x1 + w;
		rect.y2 = rect.y1 + spr->GetHeight();
	}
}

bool SelectSoldierGUI::MouseLButton( bool bDown )
{
	if(!bDown)
	{
		spr2->SetZ(0.4);
		bDownLastTime = false;
		if(!bSelected){
		rect.x1 = initialX;
		rect.y1 = initialY;
		rect.x2 = rect.x1 + w;
		rect.y2 = rect.y1 + spr->GetHeight();
		}
		return true;
	}
	else 
	{
		bSelected = false;
		spr2->SetZ(0.5);
		bDownLastTime = true;
		return false;
	}
}

bool SelectSoldierGUI::MouseRButton( bool bDown )
{
	if(!bDown)
	{
		return true;
	}
	else 
	{
		bSelected = false;
		rect.x1 = initialX;
		rect.y1 = initialY;
		rect.x2 = rect.x1 + w;
		rect.y2 = rect.y1 + spr->GetHeight();
		return false;
	}
}
