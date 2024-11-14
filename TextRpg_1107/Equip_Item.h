#pragma once
#include "Item.h"
#include "Define.h"

class Equip_Item : public Item
{
public:
	enum EQUIP_ITEM_TYPE { WEAPON, HAT, CLOTHES, SHOES };

	Equip_Item(const char* _szName, const char* _szInfo, int _iCost, EQUIP_ITEM_TYPE _EquipType, int* _pEquipStatus) :Item(_szName, _szInfo, _iCost, Item::EQUIP),
		m_EquipType(_EquipType), m_pEquipStatus(_pEquipStatus) {}
	~Equip_Item() { Release(); };

	void Use_Item(Object* _pPlayer) override {}; // Àåºñ¸¦ Âø¿ë
	Item* Copy() override;
	void Release() { SAFE_DELETE_ARRAY(m_pEquipStatus); }

private:
	EQUIP_ITEM_TYPE m_EquipType;
	int* m_pEquipStatus;

};

