#pragma once
#include "Dungeon.h"
#include "Object.h"
#include "Skill.h"

class Battle
{
public:
	static void Meet_Battle(Object* _pPlayer, const int _iFloor);

private:
	Object* m_pPlayer;
	Object* m_pMonster;

	Battle(Object* _pPlaeyr, Object* _pMonster) : m_pPlayer(_pPlaeyr), m_pMonster(_pMonster) {}
	~Battle() { Release(); }

	void Release() { SAFE_DELETE(m_pMonster); }

	void Update();
	bool SpdCmp();
	void Victory();
	void Lose();
};

