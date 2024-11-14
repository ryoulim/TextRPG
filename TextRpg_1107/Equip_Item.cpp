#include "pch.h"
#include "Equip_Item.h"
#include "Define.h"

#include "Object.h"

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

Item* Equip_Item::Copy()
{
	Equip_Item* pReturn = new Equip_Item(*this);
	pReturn->m_pEquipStatus = new int[MAX_STATUS];
	memcpy_s(pReturn->m_pEquipStatus, sizeof(int) * MAX_STATUS, m_pEquipStatus, sizeof(int) * MAX_STATUS);
	return static_cast<Item*>(pReturn);
}
// 장비템 능력치 올라가는것 어떻게 구현?