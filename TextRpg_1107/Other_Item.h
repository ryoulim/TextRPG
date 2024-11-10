#pragma once
#include "Item.h"

class Other_Item : public Item
{
public:
	~Other_Item() {}
	static Item* Create_Item(const int _iItemNum);

	void Use_Item(Objecct* _pPlayer) override {};
	Item* Copy() override;

	enum OTHER_ITEM_LIST { SLIMEITEM = 1, PIXIEITEM, DEMONITEM };

private:
	Other_Item(const char* _szName, const char* _szInfo, int _iCost) : Item(_szName, _szInfo, _iCost,Item::OTHER) {}
};