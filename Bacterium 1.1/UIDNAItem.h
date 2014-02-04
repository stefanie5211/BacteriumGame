#pragma once
#include "stdafx.h"
/****************************
*û���������ý���
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

	        void    Drafting(void);// ��ק
			void    UpdateToDisplayHelp(float);//������ʾ˵��
			void    UpdateEnterOrLeave(float);//���½����뿪Ч��

private:
	hgeSprite	*spr;
	hgeFont     *fnt;
	float		delay;
	char		*title;

	hgeRect		rect1;
	hgeRect     rect2;
	
	bool        bLBDown;

	float       initX, initY;
	float       eloffset;    ///�����뿪ʱ��λ��ƫ��
	float       dy;
	float		timer1, timer2;

	float		 timer;
	bool         mouseOver;
	bool         disPlayHelp;//��ʾ����˵��
};

