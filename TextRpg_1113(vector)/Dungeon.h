#pragma once
#include "Object.h"

class Dungeon
{
public:
	Dungeon(Object* _pPlayer): m_pPlayer(_pPlayer) {}
	~Dungeon() {}

	void Update() {};

private:
	Object* m_pPlayer; 
};

