#pragma once
#include "stdafx.h"
#include "BtmPiece_Kind.h"
#include "GeneSegment.h"

/******************************************
* 本类负责管理兵种库，DNA库， 及合成公式  *
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
	vector<GeneSegment*>              vectGeneSegmentsAcquired;///已获得的基因库

    BtmPiece_Kind*                    *pBtmPiece_Kind;   ///新合成的兵种
	
	HTEXTURE          texDNA;   //方便己用
    HTEXTURE          texCard;                    
	HTEXTURE          texLock;  //方便己用

	hgeSprite        *spDNA;	 //方便己用
	hgeSprite        *spCard;                 
	hgeSprite        *spLock;    //方便己用

	HGE              *hge;
};


