#pragma once
#include "Define.h"
#include "Bag.h"

class Object;

class StoreBase
{
public:
	static void Store(Object* _pPlayer,const int _iStoreNum);

protected:
	StoreBase() : m_pPlayer(nullptr) {}
	virtual ~StoreBase();
	
	void Initialize(Object* _pPlayer) { m_pPlayer = _pPlayer; }
	void Release() { m_pPlayer = nullptr; }

	Object* m_pPlayer;

	void Update();
	virtual void Store_Buy() = 0;
	void Store_Sell();
};

