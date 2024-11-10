#include "pch.h"
#include "Attack_Item.h"

Item* Attack_Item::Create_Item(const int _iItemNum)
{
	Item* pItem = nullptr;

	switch (_iItemNum)
	{
	case BOMB:
		pItem = new Attack_Item("폭탄", "노말타입의 30데미지", 15, 30, Object::NORMAL, NONE);
		break;
	default:
		break;
	}
	return pItem;
}

Item* Attack_Item::Copy()
{
	Attack_Item* pReturn = new Attack_Item(*this);
	return static_cast<Item*>(pReturn);
}
