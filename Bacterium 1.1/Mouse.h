#pragma once
class Mouse
{
public:
	Mouse(void);
	~Mouse(void);

	static Mouse* GetInstance(void);

	int      key;             //鼠标上一次按键，没有按键的时候被设置为-1;
	float    mousePosX;       //鼠标当前位置x
	float    mousePosY;       //鼠标当前位置x
	float    rClickX;         //右键点击x坐标
	float    rClickY;         //右键点击y坐标
	float    lClickX;         //拖拽时左键按下的x坐标   
	float    lClickY;         //拖拽是左键按下的y坐标
	bool     lClickAndMove;   //左键点击后是否移动
	bool     selected;        //鼠标左键弹起的瞬间

	float    framStartX;  // 拖拽时矩形左上角的点x坐标 
	float    framStartY;  // 拖拽时矩形左上角的点y坐标 
	float    framEndX; // 拖拽时矩形右下角的点x坐标 
	float    framEndY; // 拖拽时矩形右下角的点x坐标 
};

