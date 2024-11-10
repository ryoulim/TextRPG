#include "pch.h"
#include "Equip_Item.h"

// enum ITEMNAME { WEAPON1=1, WEAPON2, WEAPON3, HAT1, HAT2, HAT3, CLOTHES1, CLOTHES2, CLOTHES3, SHOES1, SHOES2, SHOES3 };

const char* Equip_Item::Get_Name(const int _iItemNum) const
{
	switch (_iItemNum)
	{
	case WEAPON1 :
		return "초급 무기";
	case WEAPON2:
		return "중급 무기";
	case WEAPON3 :
		return "고급 무기";
	case HAT1:
		return "초급 투구";
	case HAT2:
		return "중급 투구";
	case HAT3:
		return "고급 투구";
	case CLOTHES1:
		return "초급 방어구";
	case CLOTHES2:
		return "중급 방어구";
	case CLOTHES3:
		return "고급 방어구";
	case SHOES1:
		return "초급 신발";
	case SHOES2:
		return "중급 신발";
	case SHOES3:
		return "고급 신발";
	default:
		return "";
	}
}

const char* Equip_Item::Get_Info(const int _iItemNum) const
{
	switch (_iItemNum)
	{
	case WEAPON1:
		return "공격력 +5";
	case WEAPON2:
		return "공격력 +10";
	case WEAPON3:
		return "공격력 +15";
	case HAT1:
		return "체력 +5";
	case HAT2:
		return "체력 +10";
	case HAT3:
		return "체력 +15";
	case CLOTHES1:
		return "방어력 +5";
	case CLOTHES2:
		return "방어력 +10";
	case CLOTHES3:
		return "방어력 +15";
	case SHOES1:
		return "스피드 +5";
	case SHOES2:
		return "스피드 +10";
	case SHOES3:
		return "스피드 +15";
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
	//아이템을 착용할수 있도록
	return false;
}
