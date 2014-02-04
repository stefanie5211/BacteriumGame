#pragma once
class Mouse
{
public:
	Mouse(void);
	~Mouse(void);

	static Mouse* GetInstance(void);

	int      key;             //�����һ�ΰ�����û�а�����ʱ������Ϊ-1;
	float    mousePosX;       //��굱ǰλ��x
	float    mousePosY;       //��굱ǰλ��x
	float    rClickX;         //�Ҽ����x����
	float    rClickY;         //�Ҽ����y����
	float    lClickX;         //��קʱ������µ�x����   
	float    lClickY;         //��ק��������µ�y����
	bool     lClickAndMove;   //���������Ƿ��ƶ�
	bool     selected;        //�����������˲��

	float    framStartX;  // ��קʱ�������Ͻǵĵ�x���� 
	float    framStartY;  // ��קʱ�������Ͻǵĵ�y���� 
	float    framEndX; // ��קʱ�������½ǵĵ�x���� 
	float    framEndY; // ��קʱ�������½ǵĵ�x���� 
};

