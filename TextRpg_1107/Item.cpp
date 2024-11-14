#include "pch.h"
#include "Item.h"
#include "Object.h"

#include "Equip_Item.h"
#include "Other_Item.h"
#include "Attack_Item.h"
#include "Buff_Item.h"
#include "Potion_Item.h"

#include "Skill.h"

#define PSTATUS(_HP,_MP,_ATK,_M_ATK,_DEF,_SPD,_LUK) \
pStatus[Object::HP] = (_HP); \
pStatus[Object::MP] = (_MP);\
pStatus[Object::ATK] = (_ATK); \
pStatus[Object::M_ATK] = (_M_ATK); \
pStatus[Object::DEF] = (_DEF); \
pStatus[Object::SPD] = (_SPD); \
pStatus[Object::LUK] = (_LUK)

Item* Item::Create_Item(const int _iItemNum)
{
	Item* pItem = nullptr;
	int* pStatus = new int[MAX_STATUS];

	switch (_iItemNum)
	{
	case SWORD1:
		pStatus = new int[MAX_STATUS];
		PSTATUS(0, 0, 5, 0, 0, 0, 0);
		pItem = new Equip_Item("초급 검", "공격력 5 증가", 30, Equip_Item::Equip_Item::WEAPON, pStatus);
		break;
	case SWORD2:
		pStatus = new int[MAX_STATUS];
		PSTATUS(0, 0, 5, 0, 0, 0, 0);
		pItem = new Equip_Item("중급 검", "공격력 10 증가", 60, Equip_Item::WEAPON, pStatus);
		break;
	case STAFF1:
		pStatus = new int[MAX_STATUS];
		PSTATUS(0, 0, 0, 10, 0, 0, 0);
		pItem = new Equip_Item("초급 스태프", "마법공격력 5 증가", 30, Equip_Item::WEAPON, pStatus);
		break;
	case STAFF2:
		pStatus = new int[MAX_STATUS];
		PSTATUS(0, 0, 0, 10, 0, 0, 0);
		pItem = new Equip_Item("중급 스태프", "마법공격력 10 증가", 60, Equip_Item::WEAPON, pStatus);
		break;
	case DAGGER1:
		pStatus = new int[MAX_STATUS];
		PSTATUS(0, 0, 3, 3, 0, 0, 0);
		pItem = new Equip_Item("초급 단검", "공격력 3, 마법공격력 3 증가", 30, Equip_Item::WEAPON, pStatus);
		break;
	case DAGGER2:
		pStatus = new int[MAX_STATUS];
		PSTATUS(0, 0, 6, 6, 0, 0, 0);
		pItem = new Equip_Item("중급 단검", "공격력 6, 마법공격력 6 증가", 60, Equip_Item::WEAPON, pStatus);
		break;
	case HAT1:
		PSTATUS(5, 0, 0, 0, 0, 0, 0);
		pStatus = new int[MAX_STATUS];
		pItem = new Equip_Item("초급 모자", "체력 5 증가", 30, Equip_Item::Equip_Item::HAT, pStatus);
		break;
	case HAT2:
		PSTATUS(10, 0, 0, 0, 0, 0, 0);
		pStatus = new int[MAX_STATUS];
		pItem = new Equip_Item("중급 모자", "체력 10 증가", 60, Equip_Item::Equip_Item::HAT, pStatus);
		break;
	case HAT3:
		pStatus = new int[MAX_STATUS];
		PSTATUS(15, 0, 0, 0, 0, 0, 0);
		pItem = new Equip_Item("고급 모자", "체력 15 증가", 90, Equip_Item::Equip_Item::HAT, pStatus);
		break;
	case CLOTHES1:
		pStatus = new int[MAX_STATUS];
		PSTATUS(0, 0, 0, 0, 5, 0, 0);
		pItem = new Equip_Item("초급 갑옷", "방어력 5 증가", 30, Equip_Item::CLOTHES, pStatus);
		break;
	case CLOTHES2:
		pStatus = new int[MAX_STATUS];
		PSTATUS(0, 0, 0, 0, 10, 0, 0);
		pItem = new Equip_Item("중급 갑옷", "방어력 10 증가", 60, Equip_Item::CLOTHES, pStatus);
		break;
	case CLOTHES3:
		pStatus = new int[MAX_STATUS];
		PSTATUS(0, 0, 0, 0, 15, 0, 0);
		pItem = new Equip_Item("고급 갑옷", "방어력 15 증가", 90, Equip_Item::CLOTHES, pStatus);
		break;
	case SHOES1:
		pStatus = new int[MAX_STATUS];
		PSTATUS(0, 0, 0, 0, 0, 5, 0);
		pItem = new Equip_Item("초급 신발", "스피드 5 증가", 30, Equip_Item::SHOES, pStatus);
		break;
	case SHOES2:
		pStatus = new int[MAX_STATUS];
		PSTATUS(0, 0, 0, 0, 0, 10, 0);
		pItem = new Equip_Item("중급 신발", "스피드 10 증가", 60, Equip_Item::SHOES, pStatus);
		break;
	case SHOES3:
		pStatus = new int[MAX_STATUS];
		PSTATUS(0, 0, 0, 0, 0, 15, 0);
		pItem = new Equip_Item("고급 신발", "스피드 15 증가", 90, Equip_Item::SHOES, pStatus);
		break;
	case SLIMEITEM:
		pItem = new Other_Item("슬라임의 점액", "끈적인다.", 10);
		break;
	case PIXIEITEM:
		pItem = new Other_Item("요정가루", "반짝인다.", 10);
		break;
	case DEMONITEM:
		pItem = new Other_Item("악마의 날개", "펄럭인다.", 10);
		break;
	case ATKUP:
		pStatus = new int[MAX_STATUS];
		PSTATUS(0, 0, 3, 0, 0, 0, 0);
		pItem = new Buff_Item("어택 업", "3턴간 공격력 증가", 15, pStatus);
		break;
	case DEFUP:
		pStatus = new int[MAX_STATUS];
		PSTATUS(0, 0, 0, 3, 0, 0, 0);
		pItem = new Buff_Item("디펜스 업", "3턴간 방어력 증가", 15, pStatus);
		break;
	case BOMB:
		pItem = new Attack_Item("폭탄", "노말타입의 30데미지", 15, 30, Object::NORMAL, Skill::NONE);
		break;
	case POTION1:
		pItem = new Potion_Item("일반 포션", "체력 30 회복", 30, 30, false);
		break;
	case POTION2:
		pItem = new Potion_Item("고급 포션", "체력 50% 회복", 50, 50, true);
		break;
	default:
		break;
	}
    return pItem;
}
