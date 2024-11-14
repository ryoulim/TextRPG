#pragma once
#include "Object.h"

class Monster
{
public:
	enum MONSTER_LIST {MONSTER1, MONSTER2, MONSTER3, MON_END};
	
	Monster(string* _pstrName, int _iMAXHp, int _iAtk, int _iDef, int _iSpd)
	: Object{}
	~Monster() {}
private:
	int m_iDropGold;
};