#include "pch.h"
#include "Potion_Item.h"


Item* Potion_Item::Copy()
{
	Potion_Item* pReturn = new Potion_Item(*this);
	return static_cast<Item*>(pReturn);
}
