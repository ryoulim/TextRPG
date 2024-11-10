#include "pch.h"
#include "Other_Item.h"

const char* Other_Item::Get_Name(const int _iItemNum) const
{
	switch (_iItemNum)
	{
	case MONITEM1:
		return "�ʱ� ���� ������";
	case MONITEM2:
		return "�߱� ���� ������";
	case MONITEM3:
		return "��� ���� ������";
	default:
		return "";
	}
}

const char* Other_Item::Get_Info(const int _iItemNum) const
{
	switch (_iItemNum)
	{
	case MONITEM1:
		return "�ʱ� ���� �������̴�.";
	case MONITEM2:
		return "�߱� ���� �������̴�.";
	case MONITEM3:
		return "��� ���� �������̴�.";
	default:
		return "";
	}
}

int Other_Item::Get_Cost(const int _iItemNum) const
{
	switch (_iItemNum)
	{
	case MONITEM1:
		return 10;
	case MONITEM2:
		return 20;
	case MONITEM3:
		return 30;
	default:
		return 0;
	}
}
