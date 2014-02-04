#include "stdafx.h"
#include "GameApplication.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	GameApplication::GetInstance()->Initialize();
	GameApplication::GetInstance()->Run();
	GameApplication::GetInstance()->Serialize();
	return 0;
}