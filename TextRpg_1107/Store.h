#pragma once
#include "Player.h" 
#include "Define.h"

#include "Equip_Item.h"
#include "Potion_Item.h"
#include "Attack_Item.h"
#include "Buff_Item.h"

class Store
{
public:
	static void Meet_Store(Object* _pPlayer,const int _iFloor);
	//판매아이템 번호가 있어야함.. 아이템을 생성해주는데 
	~Store() { Release(); };

	void Update();

	enum STORETYPE {STORE1,STORE2,STORE3};

private:
	Object* m_pPlayer;
	Item** m_ppItem;
	int m_iItem_Count;

	Store(Object* _pPlayer) : m_pPlayer(_pPlayer), m_ppItem(nullptr), m_iItem_Count(0) {}

	void Initialize(STORETYPE _StoreType);
	void Release();

	void Buy();
	void Sell();
};

