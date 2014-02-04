#include "Store.h"

Store *Store::m_pInstance = 0;

Store::Store(void): pBtmPiece_Kind(0)
{
	hge     = hgeCreate(HGE_VERSION);  

	texDNA  = hge->Texture_Load("Spell_Frost_ChillingArmor.png");
	texCard = hge->Texture_Load("1.jpg");   
	texLock = hge->Texture_Load("locked.png");

	spDNA  = new hgeSprite(texDNA,     0, 0, 64, 64);
	spCard   = new hgeSprite(texCard,  0, 0, 60, 84);
	spLock = new hgeSprite(texLock,    0, 0, 60, 60);	

	BtmPiece_KindStoreInit();
	GeneSegmentsStoreInit();
	FormulasInit();
}


Store::~Store(void)
{
}

Store *Store::GetInstance(void)
{
	if(!m_pInstance)
	{
		m_pInstance = new Store();
	}
	return m_pInstance;
}

void Store::Release(void)
{
	if(m_pInstance)
	{
		delete m_pInstance;
		m_pInstance = 0;
	}
}
void Store::GeneSegmentsStoreInit(void)
{
	int   ID = 10;

	for(size_t j = 0; j < 4; ++j)
	{
		for(size_t i = 0; i < 5; ++i)
		{
			
			vectGeneSegments.push_back(new GeneSegment(spDNA , ID++));
		}
	}
}

void Store::BtmPiece_KindStoreInit(void)
{
	int   ID = 10;

	for(size_t j = 0; j < 4; ++j)
	{
		for(size_t i = 0; i < 5; ++i)
		{
		
			vectBtmPiece_Kinds.push_back(new BtmPiece_Kind(spCard, spLock, ID++, true));
		}
	}
}

void Store::FormulasInit(void)
{
	int IDBtmPiece_Kind = 10;
	int IDGeneSegment   = 10;

	pair<int, int> pairGeneSegment;

	for(size_t i = 0; i < 15; ++i)
	{
		pairGeneSegment = make_pair(IDGeneSegment++,IDGeneSegment++);
		vectformulas.push_back(make_pair(pairGeneSegment, IDBtmPiece_Kind));
		IDBtmPiece_Kind++;
	}
}

void AddNewBtmPiece_Kind(BtmPiece_Kind* _BtmPiece_Kind)
{

}

void AddNewGeneSegments(GeneSegment* pGeneSegment)
{

}