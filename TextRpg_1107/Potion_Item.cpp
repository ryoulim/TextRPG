#include "pch.h"
#include "Potion_Item.h"

Item* Potion_Item::Create_Item(const int _iItemNum)
{
	Item* pItem = nullptr;

	switch (_iItemNum)
	{
	case POTION1:
		pItem = new Potion_Item("�Ϲ� ����", "ü�� 30 ȸ��", 30, 30, false);
		break;
	case POTION2:
		pItem = new Potion_Item("��� ����", "ü�� 50% ȸ��", 50, 50, true);
		break;
	}

	return pItem;
}

Item* Potion_Item::Copy()
{
	Potion_Item* pReturn = new Potion_Item(*this);
	return static_cast<Item*>(pReturn);
}
