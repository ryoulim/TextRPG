#pragma once
#include "Item.h"
#include "Object.h"

class Equip_Item : public Item
{
public:
	const char* Get_Name(const int _iItemNum) const;
	const char* Get_Info(const int _iItemNum) const;
	int Get_Cost(const int _iItemNum) const;

	virtual bool Use_Item(Object* _pObject) const;

	enum ITEMNAME { WEAPON1=1, WEAPON2, WEAPON3, HAT1, HAT2, HAT3, CLOTHES1, CLOTHES2, CLOTHES3, SHOES1, SHOES2, SHOES3 };
};

