#include "Mouse.h"

Mouse::Mouse(void)
{
	lClickAndMove = false;
}


Mouse::~Mouse(void)
{
}

Mouse* Mouse::GetInstance( void )
{
	static Mouse *mouseInstance ;
	if(!mouseInstance)
	{	  
		mouseInstance = new Mouse();
	}
	return mouseInstance;
}