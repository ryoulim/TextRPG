#include "pch.h"
#include "Other_Item.h"
#include "Define.h"

//enum OTHER_ITEM_LIST { SLIMEITEM, PIXIEITEM, DEMONITEM };

Item* Other_Item::Copy()
{
	Other_Item* pReturn = new Other_Item(*this);
	return static_cast<Item*>(pReturn);
}
