#include "Bacterium.h"


Bacterium::Bacterium(void)
{
	m_pStateMachine = new StateMachine<Unit>(this);
	//GetFSM()->SetCurrentState();
	hge = hgeCreate(HGE_VERSION);
	//unitType = BACTERIUM;
}


Bacterium::~Bacterium(void)
{
}



//void Bacterium::DirectMove( float gx,float gy )
//{
//	float xSpeed,ySpeed;
//	xSpeed = ((gx-position.x))/(sqrt(pow((gx-position.x), 2)+pow((gy-position.y), 2)))/10;
//	ySpeed = ((gy-position.y))/(sqrt(pow((gx-position.x), 2)+pow((gy-position.y), 2)))/10;
//	destinationPositon.x=gx;
//	destinationPositon.y=gy;
//	if (gx > position.x)
//	{	
//		position.x += xSpeed;
//		if (position.x >= gx)
//		{
//			gx = -1;
//		}
//	}
//	else
//	{
//		position.x += xSpeed;
//		if (position.x <= gx)
//		{
//			gx = -1;
//		}
//	}
//
//	if (gy > position.y)
//	{
//		position.y += ySpeed;
//		if (position.y >= gy)
//		{
//			gy = -1;
//		}
//	} 
//	else
//	{
//		position.y += ySpeed;
//		if (position.y <= gy)
//		{
//			gy = -1;
//		}
//	}
//
//	if (gx == -1 && gy == -1)
//	{
//		unitState = STILLNESS;
//		//runAway = false;
//	}
//}

//void Bacterium::BeAttack()
//{
//
//}
