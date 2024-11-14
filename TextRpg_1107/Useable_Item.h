#pragma once
#include "Item.h"
#include "Object.h"

class Useable_Item : public Item
{
public:
	enum USEABLE_ITEM_TYPE { ATTACK_ITEM, BUFF_ITEM, POTION_ITEM };

	Useable_Item(const char* _szName, const char* _szInfo, int _iCost, USEABLE_ITEM_TYPE _Type) :Item(_szName, _szInfo, _iCost, Item::USEABLE),
		m_Type(_Type) {}
	~Useable_Item() {}
	virtual void Use_Item(Object* _pPlayer) = 0;

	Item* Copy() = 0;

protected:
	USEABLE_ITEM_TYPE m_Type;
};

