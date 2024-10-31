#pragma once
#include "Player.h"
#include "Monster.h"
class Field
{
public:
	Field() : m_pMonster(nullptr), m_pPlayer(nullptr)
	{
	}
	~Field();

	void Initialize(Player* _pPlayer);
	void Update();
	void Release();

private:
	Player* m_pPlayer;
	Monster* m_pMonster;

	void Battle(const int _iMonNum);
	bool Spd_Cmp(const int _iPlayerSpd, const int _iMonsterSpd);
	void Victory();
	void Lose();

	void Use_Item();
};