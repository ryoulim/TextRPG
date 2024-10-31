#pragma once
#include "Define.h"
#include "Item.h"

class Monster
{
public:
	Monster() : m_pStatus(nullptr), m_iGold(0), m_iDropItem(0) {}
	~Monster();

	void Initialize(const int _iMonNum);
	void Info_Render();
	Status* Get_Status() { return m_pStatus; }
	int Get_Gold() { return m_iGold; }
	int Get_iDropItem() { return m_iDropItem; }
	bool Damaged(int _iDamage);
	void Release();

	enum MONNUM {MONSTER1 = 1,MONSTER2,MONSTER3,END};

private:
	Status* m_pStatus;
	int m_iGold;
	int m_iDropItem;
};

