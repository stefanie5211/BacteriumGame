#include "Effect.h"

Effect *Effect::m_pInstance = 0;
Effect::Effect(void):vol(50)
{
	hge = hgeCreate(HGE_VERSION);
	sndBackGround = hge->Effect_Load("music_Bg.mp3");
	channel = hge->Effect_PlayEx(sndBackGround);	
}


Effect::~Effect(void)
{
}

Effect * Effect::GetInstance(void)
{
	if(!m_pInstance)
	{
		m_pInstance = new Effect();
	}
	return m_pInstance;
}

void Effect::Release(void)
{
	if(m_pInstance)
	{
		delete m_pInstance;
		m_pInstance =0;
	}
}