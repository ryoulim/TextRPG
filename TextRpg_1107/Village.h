#pragma once
#include "Object.h"

class Village
{
public:
	Village() {}
	Village(Object* _pPlayer) :m_pPlayer(_pPlayer) {}
	~Village() {}

	int Update();

private:
	Object* m_pPlayer;
};