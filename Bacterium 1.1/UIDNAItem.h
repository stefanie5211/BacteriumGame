#pragma once
#include "stdafx.h"
/****************************
*没有重载设置焦点
************************/
class hgeGUIDNAButton:
	public hgeGUIObject
{
public:
	hgeGUIDNAButton(int id, hgeFont *fnt, hgeSprite *spr, 
		    float x, float y, float delay,char *title = 0);

	virtual void	Render();
	virtual void	Update(float dt);

	//virtual void	Reset();
	virtual void	Enter();
	virtual void	Leave();
	virtual bool	IsDone();
	//virtual void	Focus(bool bFocused);

	virtual void	MouseOver(bool bOver);
	virtual bool	MouseLButton(bool bDown);
	virtual bool    MouseRButton(bool bDown);

	        void    Drafting(void);// 拖拽
			void    UpdateToDisplayHelp(float);//更新显示说明
			void    UpdateEnterOrLeave(float);//更新进入离开效果

private:
	hgeSprite	*spr;
	hgeFont     *fnt;
	float		delay;
	char		*title;

	hgeRect		rect1;
	hgeRect     rect2;
	
	bool        bLBDown;

	float       initX, initY;
	float       eloffset;    ///进入离开时的位移偏离
	float       dy;
	float		timer1, timer2;

	float		 timer;
	bool         mouseOver;
	bool         disPlayHelp;//显示技能说明
};

