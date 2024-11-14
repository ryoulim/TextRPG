#pragma once
#include "Object.h"

class Village
{
public:
	Village() : m_pPlayer(nullptr) {}
	Village(Object* _pPlayer) : m_pPlayer(_pPlayer) {}
	~Village() {}

	void Update();
private:
	Object* m_pPlayer;

	void Go_Dungeon();
	void Go_Store();
};

