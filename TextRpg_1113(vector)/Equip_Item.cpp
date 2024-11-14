#include "pch.h"
#include "Equip_Item.h"

Equip_Item* Equip_Item::Create_Equip_Item(const int _iItemNum)
{
	Equip_Item* pReturn = nullptr;

	switch (_iItemNum)
	{
	case SWORD1 :
		pReturn = new Equip_Item("초급 검", 203, 30, SWORD);
		break;
	case SWORD2:
		pReturn = new Equip_Item("중급 검", 206, 60, SWORD);
		break;
	case SWORD3:
		pReturn = new Equip_Item("고급 검", 209, 90, SWORD);
		break;
	case STAFF1:
		pReturn = new Equip_Item("초급 스태프", 203, 30, STAFF);
		break;
	case STAFF2:
		pReturn = new Equip_Item("중급 스태프", 206, 60, STAFF);
		break;
	case STAFF3:
		pReturn = new Equip_Item("고급 스태프", 209, 90, STAFF);
		break;
	case DAGGER1:
		pReturn = new Equip_Item("초급 단검", 203, 30, DAGGER);
		break;
	case DAGGER2:
		pReturn = new Equip_Item("중급 단검", 206, 60, DAGGER);
		break;
	case DAGGER3:
		pReturn = new Equip_Item("고급 단검", 209, 90, DAGGER);
		break;
	case HAT1:
		pReturn = new Equip_Item("초급 모자", 103, 30, HAT);
		break;
	case HAT2:
		pReturn = new Equip_Item("중급 모자", 106, 60, HAT);
		break;
	case HAT3:
		pReturn = new Equip_Item("고급 모자", 109, 90, HAT);
		break;
	case CLOTHES1:
		pReturn = new Equip_Item("초급 방어구", 303, 30, CLOTHES);
		break;
	case CLOTHES2:
		pReturn = new Equip_Item("중급 방어구", 306, 60, CLOTHES);
		break;
	case CLOTHES3:
		pReturn = new Equip_Item("고급 방어구", 309, 90, CLOTHES);
		break;
	case SHOES1:
		pReturn = new Equip_Item("초급 신발", 403, 30, SHOES);
		break;
	case SHOES2:
		pReturn = new Equip_Item("중급 신발", 406, 60, SHOES);
		break;
	case SHOES3:
		pReturn = new Equip_Item("고급 신발", 409, 90, SHOES);
		break;
	default:
		break;
	}
	return pReturn;
}

void Equip_Item::Info_Render() const
{
	cout << Status_Name_Render() << " " << m_iUpStatus % 100 << " 상승";
}

const char* Equip_Item::Status_Name_Render() const
{
	switch (m_iUpStatus / 100)
	{
	case 1:
		return "체력";
	case 2:
		return "공격력";
	case 3:
		return "방어력";
	case 4:
		return "스피드";
	default:
		return "";
	}
}
