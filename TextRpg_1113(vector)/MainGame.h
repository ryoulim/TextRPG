#pragma once
#include "Object.h"
#include "Village.h"
#include "Define.h"

class MainGame
{
public:
	MainGame() : m_pPlayer(nullptr) {}
	~MainGame() { Release(); }

	void Initialize();
	void Update();
	void Release() { Safe_Delete<Object*>(m_pPlayer); }
private:
	Object* m_pPlayer;
};

