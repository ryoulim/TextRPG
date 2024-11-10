#include "pch.h"
#include "Equip_Item.h"
#include "Define.h"
//enum STATUSNUM { HP, MP, ATK, M_ATK, DEF, SPD, END };

#define PEQUIPSTATUS(_HP,_MP,_ATK,_M_ATK,_DEF,_SPD,_LUK) \
pEquipStatus[Object::HP] = (_HP); \
pEquipStatus[Object::MP] = (_MP);\
pEquipStatus[Object::ATK] = (_ATK); \
pEquipStatus[Object::M_ATK] = (_M_ATK); \
pEquipStatus[Object::DEF] = (_DEF); \
pEquipStatus[Object::SPD] = (_SPD); \
pEquipStatus[Object::LUK] = (_LUK)


//enum EQUIP_ITEM_LIST
//{
//	SWORD1 = 1, SWORD2,
//	STAFF1, STAFF2,
//	DAGGER1, DAGGER2,
//	HAT1, HAT2, HAT3,
//	CLOTHES1, CLOTHES2, CLOTHES3,
//	SHOES1, SHOES2, SHOES3
//};

Item* Equip_Item::Create_Item(const int _iItemNum)
{
	Item* pItem = nullptr;
	int* pEquipStatus = new int[MAX_STATUS];

	switch (_iItemNum)
	{
	case SWORD1:
		PEQUIPSTATUS(0, 0, 5, 0, 0, 0, 0);
		pItem = new Equip_Item("초급 검", "공격력 5 증가", 30, WEAPON, pEquipStatus);
		break;
	case SWORD2:
		PEQUIPSTATUS(0, 0, 5, 0, 0, 0, 0);
		pItem = new Equip_Item("중급 검", "공격력 10 증가", 60, WEAPON, pEquipStatus);
		break;
	case STAFF1:
		PEQUIPSTATUS(0, 0, 0, 10, 0, 0, 0);
		pItem = new Equip_Item("초급 스태프", "마법공격력 5 증가", 30, WEAPON, pEquipStatus);
		break;
	case STAFF2:
		PEQUIPSTATUS(0, 0, 0, 10, 0, 0, 0);
		pItem = new Equip_Item("중급 스태프", "마법공격력 10 증가", 60, WEAPON, pEquipStatus);
		break;
	case DAGGER1:
		PEQUIPSTATUS(0, 0, 3, 3, 0, 0, 0);
		pItem = new Equip_Item("초급 단검", "공격력 3, 마법공격력 3 증가", 30, WEAPON, pEquipStatus);
		break;
	case DAGGER2:
		PEQUIPSTATUS(0, 0, 6, 6, 0, 0, 0);
		pItem = new Equip_Item("중급 단검", "공격력 6, 마법공격력 6 증가", 60, WEAPON, pEquipStatus);
		break;
	case HAT1:
		PEQUIPSTATUS(5, 0, 0, 0, 0, 0, 0);
		pItem = new Equip_Item("초급 모자", "체력 5 증가", 30, HAT, pEquipStatus);
		break;
	case HAT2:
		PEQUIPSTATUS(10, 0, 0, 0, 0, 0, 0);
		pItem = new Equip_Item("중급 모자", "체력 10 증가", 60, HAT, pEquipStatus);
		break;
	case HAT3:
		PEQUIPSTATUS(15, 0, 0, 0, 0, 0, 0);
		pItem = new Equip_Item("고급 모자", "체력 15 증가", 90, HAT, pEquipStatus);
		break;
	case CLOTHES1:
		PEQUIPSTATUS(0, 0, 0, 0, 5, 0, 0);
		pItem = new Equip_Item("초급 갑옷", "방어력 5 증가", 30, CLOTHES, pEquipStatus);
		break;
	case CLOTHES2:
		PEQUIPSTATUS(0, 0, 0, 0, 10, 0, 0);
		pItem = new Equip_Item("중급 갑옷", "방어력 10 증가", 60, CLOTHES, pEquipStatus);
		break;
	case CLOTHES3:
		PEQUIPSTATUS(0, 0, 0, 0, 15, 0, 0);
		pItem = new Equip_Item("고급 갑옷", "방어력 15 증가", 90, CLOTHES, pEquipStatus);
		break;
	case SHOES1:
		PEQUIPSTATUS(0, 0, 0, 0, 0, 5, 0);
		pItem = new Equip_Item("초급 신발", "스피드 5 증가", 30, SHOES, pEquipStatus);
		break;
	case SHOES2:
		PEQUIPSTATUS(0, 0, 0, 0, 0, 10, 0);
		pItem = new Equip_Item("중급 신발", "스피드 10 증가", 60, SHOES, pEquipStatus);
		break;
	case SHOES3:
		PEQUIPSTATUS(0, 0, 0, 0, 0, 15, 0);
		pItem = new Equip_Item("고급 신발", "스피드 15 증가", 90, SHOES, pEquipStatus);
		break;
	default:
		break;
	}

	return pItem;
}
Item* Equip_Item::Copy()
{
	Equip_Item* pReturn = new Equip_Item(*this);
	pReturn->m_pEquipStatus = new int[MAX_STATUS];
	memcpy_s(pReturn->m_pEquipStatus, sizeof(int) * MAX_STATUS, m_pEquipStatus, sizeof(int) * MAX_STATUS);
	return static_cast<Item*>(pReturn);
}
// 장비템 능력치 올라가는것 어떻게 구현?