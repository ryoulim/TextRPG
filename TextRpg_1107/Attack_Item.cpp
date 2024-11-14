#include "pch.h"
#include "Attack_Item.h"

Item* Attack_Item::Copy()
{
	Attack_Item* pReturn = new Attack_Item(*this);
	return static_cast<Item*>(pReturn);
}
