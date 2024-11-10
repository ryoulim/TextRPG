#include "pch.h"
#include "Other_Item.h"
#include "Define.h"

//enum OTHER_ITEM_LIST { SLIMEITEM, PIXIEITEM, DEMONITEM };

Item* Other_Item::Create_Item(const int _iItemNum)
{
	Item* pItem = nullptr;

	switch (_iItemNum)
	{
	case SLIMEITEM:
		pItem = new Other_Item("슬라임의 점액", "끈적인다.", 10);
		break;
	case PIXIEITEM:
		pItem = new Other_Item("요정가루", "반짝인다.", 10);
		break;
	case DEMONITEM:
		pItem = new Other_Item("악마의 날개", "펄럭인다.", 10);
		break;
	default:
		break;
	}
	return pItem;
}

Item* Other_Item::Copy()
{
	Other_Item* pReturn = new Other_Item(*this);
	return static_cast<Item*>(pReturn);
}
