#pragma once
#include "Object.h"

class Village
{
public:
	Village() : m_pPlayer(nullptr) {}
	~Village();

	void Initialize(Object* _pPlayer);
	bool Update();
	void Release();

private:
	Object* m_pPlayer;
};

