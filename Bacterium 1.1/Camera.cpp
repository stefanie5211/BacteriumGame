#include "Camera.h"


Camera::Camera(void)
{
	MainMapPosition.x=-240;
	MainMapPosition.y=-100;
	unitsAll = MANAGER_CHAPTER->GetUnitsAllAddress();
}


Camera::~Camera(void)
{

}

void Camera::Render( )
{
	for (vector<Unit*>::iterator iterA = unitsAll->begin(); iterA != unitsAll->end(); ++iterA)
	{
		(*iterA)->GetUnitSpr()->Render(Change((*iterA)->GetPosition()).x,Change((*iterA)->GetPosition()).y);
		float dt=hge->Timer_GetDelta();
		if (!(*iterA)->GetBulletsVec().empty())
		{
			for (vector<Bullet*>::iterator iter = (*iterA)->GetBulletsVec().begin(); iter != (*iterA)->GetBulletsVec().end(); ++iter)
			{
				(*iter)->GetBulletPar()->Update(dt);			
				(*iter)->GetBulletPar()->FireAt(Change((*iterA)->GetPosition()).x, Change((*iterA)->GetPosition()).y);
				(*iter)->GetBulletPar()->Render();

			}
		}
		(*iterA)->UnitMiniMapSprRender();
	}
}

Camera* Camera::GetInstance()
{
	static Camera *cameraInstance; 
	if ( !cameraInstance )
		cameraInstance = new Camera();
	return cameraInstance;
}

Position Camera::Change( Position pos )
{
	Position cameraPos;
	cameraPos.x = pos.x + MainMapPosition.x;
	cameraPos.y = pos.y + MainMapPosition.y;
	return cameraPos ;
}

