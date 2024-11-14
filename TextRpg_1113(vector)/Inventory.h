#pragma once
#include "Equip_Item.h"
#include <vector>

#define MAX_INVEN_ITEM 5
#define MAX_EQUIPABLE_ITEM_NUM 4

class Object;

class Inventory
{
public:
	Inventory() : m_iGold(3000) {}
	~Inventory() {}

	void Initialize();

	bool Add_Item(const int _iItemNum);
	bool Add_Item(Equip_Item* _pItem);
	bool Delete_Item(const int _iIndex);
	bool Equip_Itemp(const int _iIndex, Object* _pPlayer);

	int Get_Gold() { return m_iGold; }
	void Set_Gold(int _iGold) { m_iGold = _iGold; }
	void Sell_Item_Gold(const int _iindex) { m_iGold += m_vecInven_ItemP[_iindex]->Get_Cost() / 2; }
	int Get_Size() { return (int)m_vecInven_ItemP.size(); }

	void Item_Render(const int _iIndex) const;
	void Equip_Render() const;

private:
	int m_iGold;
	vector<Equip_Item*> m_vecInven_ItemP;
	vector<Equip_Item*> m_vecEquip_ItemP;
};

