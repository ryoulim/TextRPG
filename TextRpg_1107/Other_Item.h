#pragma once
#include "Item.h"

class Other_Item : public Item
{
public:
	Other_Item(const char* _szName, const char* _szInfo, int _iCost) : Item(_szName, _szInfo, _iCost, Item::OTHER) {}
	~Other_Item() {}

	void Use_Item(Object* _pPlayer) override {};
	Item* Copy() override;


private:
};