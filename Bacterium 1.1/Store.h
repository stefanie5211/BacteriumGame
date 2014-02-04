#pragma once
#include "stdafx.h"
#include "BtmPiece_Kind.h"
#include "GeneSegment.h"

/******************************************
* ���ฺ�������ֿ⣬DNA�⣬ ���ϳɹ�ʽ  *
******************************************/

#define pStore Store::GetInstance() 

class Store
{
	friend class BacteriaStore;
	friend class CompositeView;
	
public:	
	~Store(void);

	static Store *GetInstance(void);
	static void   Release(void);

	void BtmPiece_KindStoreInit(void);
	void GeneSegmentsStoreInit(void);
	void FormulasInit(void);

	void AddNewBtmPiece_Kind(BtmPiece_Kind*);
	void AddNewGeneSegments(GeneSegment*);

private:
	Store(void);

	static Store     *m_pInstance;

	vector<pair<pair<int, int>, int>> vectformulas;
	vector<BtmPiece_Kind*>            vectBtmPiece_Kinds;
	vector<GeneSegment*>              vectGeneSegments;
	vector<GeneSegment*>              vectGeneSegmentsAcquired;///�ѻ�õĻ����

    BtmPiece_Kind*                    *pBtmPiece_Kind;   ///�ºϳɵı���
	
	HTEXTURE          texDNA;   //���㼺��
    HTEXTURE          texCard;                    
	HTEXTURE          texLock;  //���㼺��

	hgeSprite        *spDNA;	 //���㼺��
	hgeSprite        *spCard;                 
	hgeSprite        *spLock;    //���㼺��

	HGE              *hge;
};


