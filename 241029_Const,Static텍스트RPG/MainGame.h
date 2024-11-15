#pragma once
#include "Object.h"
#include "Village.h"
#include "Field.h"

class MainGame
{
public:
	MainGame() : m_pPlayer(nullptr), m_pVillage(nullptr), m_pField(nullptr) {}
	~MainGame();

	void Initialize(); // ������
	void Update();
	void Release();

private:
	Object* m_pPlayer;
	Village* m_pVillage;
	Field* m_pField;
};

