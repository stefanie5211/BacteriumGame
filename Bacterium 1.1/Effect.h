#pragma once
#include "stdafx.h"

#define pEffect Effect::GetInstance()

class Effect
{
	friend class Option;
public:	
	~Effect(void);

	static Effect * GetInstance(void);
	       void     Release(void);
private:
	Effect(void);

	static Effect *m_pInstance;

	HEFFECT   sndBackGround;///∑Ω±„ π”√
	HCHANNEL  channel;
	int       vol;

	HGE      *hge;
};

