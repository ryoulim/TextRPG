#pragma once
#include "Player.h"
#include "Monster.h"

class Field
{
public:
	Field() : m_pMonster(nullptr), m_pPlayer(nullptr), m_iFloor(1)
	{
	}
	~Field();

	void Initialize(Object* _pPlayer);
	void Update();
	void Release();

private:
	Object* m_pPlayer;
	Object* m_pMonster;
	int m_iFloor;

	void Render_Walk() const;

	void Item_Drop();

	void Battle(const int _iMonNum);
	bool Spd_Cmp(const int _iPlayerSpd, const int _iMonsterSpd);
	int Skill_Select();
	int Monster_Ai();

	void Victory();
	void Lose();

	void Next_Floor();
	void Text_Render();

	void New_Skill();
};