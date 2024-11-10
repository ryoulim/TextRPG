#pragma once
#include "Item.h"
#include "Object.h"
#include "Define.h"

class Equip_Item : public Item
{
public:
	~Equip_Item() { Release(); };

	static Item* Create_Item(const int _iItemNum);

	enum EQUIP_ITEM_LIST
	{ SWORD1 = 1 , SWORD2, 
		STAFF1, STAFF2, 
		DAGGER1, DAGGER2 , 
		HAT1, HAT2, HAT3, 
		CLOTHES1, CLOTHES2, CLOTHES3, 
		SHOES1, SHOES2, SHOES3 };

	enum EQUIP_ITEM_TYPE { WEAPON,HAT,CLOTHES,SHOES };

	void Use_Item(Objecct* _pPlayer) override {}; // Àåºñ¸¦ Âø¿ë
	Item* Copy() override;
	void Release() { SAFE_DELETE_ARRAY(m_pEquipStatus); }

private:
	EQUIP_ITEM_TYPE m_EquipType;
	int* m_pEquipStatus;

	Equip_Item(const char* _szName, const char* _szInfo, int _iCost, EQUIP_ITEM_TYPE _EquipType, int* _pEquipStatus) :Item(_szName, _szInfo, _iCost, Item::EQUIP),
		m_EquipType(_EquipType), m_pEquipStatus(_pEquipStatus) {}
};

