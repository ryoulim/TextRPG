#include "pch.h"
#include "Equip_Item.h"

// enum ITEMNAME { WEAPON1=1, WEAPON2, WEAPON3, HAT1, HAT2, HAT3, CLOTHES1, CLOTHES2, CLOTHES3, SHOES1, SHOES2, SHOES3 };

const char* Equip_Item::Get_Name(const int _iItemNum) const
{
	switch (_iItemNum)
	{
	case WEAPON1 :
		return "�ʱ� ����";
	case WEAPON2:
		return "�߱� ����";
	case WEAPON3 :
		return "��� ����";
	case HAT1:
		return "�ʱ� ����";
	case HAT2:
		return "�߱� ����";
	case HAT3:
		return "��� ����";
	case CLOTHES1:
		return "�ʱ� ��";
	case CLOTHES2:
		return "�߱� ��";
	case CLOTHES3:
		return "��� ��";
	case SHOES1:
		return "�ʱ� �Ź�";
	case SHOES2:
		return "�߱� �Ź�";
	case SHOES3:
		return "��� �Ź�";
	default:
		return "";
	}
}

const char* Equip_Item::Get_Info(const int _iItemNum) const
{
	switch (_iItemNum)
	{
	case WEAPON1:
		return "���ݷ� +5";
	case WEAPON2:
		return "���ݷ� +10";
	case WEAPON3:
		return "���ݷ� +15";
	case HAT1:
		return "ü�� +5";
	case HAT2:
		return "ü�� +10";
	case HAT3:
		return "ü�� +15";
	case CLOTHES1:
		return "���� +5";
	case CLOTHES2:
		return "���� +10";
	case CLOTHES3:
		return "���� +15";
	case SHOES1:
		return "���ǵ� +5";
	case SHOES2:
		return "���ǵ� +10";
	case SHOES3:
		return "���ǵ� +15";
	default:
		return "";
	}
}

int Equip_Item::Get_Cost(const int _iItemNum) const
{
	switch (_iItemNum)
	{
	case WEAPON1:
		return 40;
	case WEAPON2:
		return 80;
	case WEAPON3:
		return 120;
	case HAT1:
		return 40;
	case HAT2:
		return 80;
	case HAT3:
		return 120;
	case CLOTHES1:
		return 40;
	case CLOTHES2:
		return 80;
	case CLOTHES3:
		return 120;
	case SHOES1:
		return 40;
	case SHOES2:
		return 80;
	case SHOES3:
		return 120;
	default:
		return 0;
	}

}

bool Equip_Item::Use_Item(Object* _pObject) const
{
	//�������� �����Ҽ� �ֵ���
	return false;
}
