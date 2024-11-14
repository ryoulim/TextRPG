#pragma once
#include "Inventory.h"
#include "Define.h"
#include <algorithm>

class Store
{
public:
	Store(Inventory* _pInven) : m_pInven(_pInven) {}
	~Store() { Release(); }

	void Initialize(const int _iStoreNum);
	void Update();
	void Release();

	enum Store_List {Store1,Store2,Store3};

private:
	vector<Equip_Item*> m_vecItemList;
	Inventory* m_pInven;

	void Buy();
	void Sell();
};

