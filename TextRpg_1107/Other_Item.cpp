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
		pItem = new Other_Item("�������� ����", "�����δ�.", 10);
		break;
	case PIXIEITEM:
		pItem = new Other_Item("��������", "��¦�δ�.", 10);
		break;
	case DEMONITEM:
		pItem = new Other_Item("�Ǹ��� ����", "�޷��δ�.", 10);
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
