#pragma once
#include "Define.h"
#include "Object.h"
#include "Village.h"
#include "Dungeon.h"

class MainGame
{
public:
	MainGame() : m_pPlayer(nullptr), m_pVillage(nullptr), m_pDungeon(nullptr) {}
	~MainGame() { Release(); }

	void Initialize();
	void Update();
	void Release();
	
	enum LOCATION {VILLAGE = 1,DUNGEON,END};

private:
	Object* m_pPlayer;
	Village* m_pVillage;
	Dungeon* m_pDungeon;
};

