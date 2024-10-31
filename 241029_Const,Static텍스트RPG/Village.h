#pragma once
#include "Player.h"

class Village
{
public:
	Village() : m_pPlayer(nullptr) {}
	~Village();

	void Initialize(Player* _pPlayer);
	bool Update();
	void Release();

private:
	void Store();
	void Store_Buy();
	void Store_Sell();
	Player* m_pPlayer;
};

