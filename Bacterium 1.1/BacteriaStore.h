#pragma once
#include "stdafx.h"
#include "GameState.h"
#include "Store.h"
/******************************************
*1���ɹؿ���ȡ������Ա����������г�ʼ��  *
*2��Initialize������ʼ��GUI,����GUI�ؼ�   *
*3��AddBacteria������������±���         *
******************************************/
class BacteriaStore :
	public GameState
{
	typedef hgeGUIBacteriaMenu Bacteria;
	friend  class Application;

public:
	BacteriaStore(void);
	~BacteriaStore(void);

	void Initialize(void);
	void Servicelize(void);
	void AddBacteria(Bacteria*);

	GameStateConstant Frame(GameStateConstant*);
	void              Render(void);
	void              Enter(void);

private:	
	hgeGUI            *bacteriaStoreGUI;        ///����gui
	vector<Bacteria*>  vectPiece_kinds;         ///���ֿ�

	HEFFECT            snd;

	hgeFont          *fnt;


	hgeSprite       *spMouse;                //���㼺��
	HTEXTURE         texMouse;                 //���㼺��
};

