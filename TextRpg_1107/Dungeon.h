#pragma once
#include "Object.h"

class Dungeon
{
public:
	Dungeon() : m_pPlayer(nullptr), m_iFloor(1) {}
	Dungeon(Object* _pPlayer) :m_pPlayer(_pPlayer), m_iFloor(1) {}
	~Dungeon() {}

	void Update();

private:
	Object* m_pPlayer;
	int m_iFloor;

	void Enter() const;
	void Item_Drop();
	void Next_Floor();
	void Text_Render();

	void New_Skill();
};

