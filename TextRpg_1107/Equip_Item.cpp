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
		pItem = new Equip_Item("�ʱ� ��", "���ݷ� 5 ����", 30, WEAPON, pEquipStatus);
		break;
	case SWORD2:
		PEQUIPSTATUS(0, 0, 5, 0, 0, 0, 0);
		pItem = new Equip_Item("�߱� ��", "���ݷ� 10 ����", 60, WEAPON, pEquipStatus);
		break;
	case STAFF1:
		PEQUIPSTATUS(0, 0, 0, 10, 0, 0, 0);
		pItem = new Equip_Item("�ʱ� ������", "�������ݷ� 5 ����", 30, WEAPON, pEquipStatus);
		break;
	case STAFF2:
		PEQUIPSTATUS(0, 0, 0, 10, 0, 0, 0);
		pItem = new Equip_Item("�߱� ������", "�������ݷ� 10 ����", 60, WEAPON, pEquipStatus);
		break;
	case DAGGER1:
		PEQUIPSTATUS(0, 0, 3, 3, 0, 0, 0);
		pItem = new Equip_Item("�ʱ� �ܰ�", "���ݷ� 3, �������ݷ� 3 ����", 30, WEAPON, pEquipStatus);
		break;
	case DAGGER2:
		PEQUIPSTATUS(0, 0, 6, 6, 0, 0, 0);
		pItem = new Equip_Item("�߱� �ܰ�", "���ݷ� 6, �������ݷ� 6 ����", 60, WEAPON, pEquipStatus);
		break;
	case HAT1:
		PEQUIPSTATUS(5, 0, 0, 0, 0, 0, 0);
		pItem = new Equip_Item("�ʱ� ����", "ü�� 5 ����", 30, HAT, pEquipStatus);
		break;
	case HAT2:
		PEQUIPSTATUS(10, 0, 0, 0, 0, 0, 0);
		pItem = new Equip_Item("�߱� ����", "ü�� 10 ����", 60, HAT, pEquipStatus);
		break;
	case HAT3:
		PEQUIPSTATUS(15, 0, 0, 0, 0, 0, 0);
		pItem = new Equip_Item("��� ����", "ü�� 15 ����", 90, HAT, pEquipStatus);
		break;
	case CLOTHES1:
		PEQUIPSTATUS(0, 0, 0, 0, 5, 0, 0);
		pItem = new Equip_Item("�ʱ� ����", "���� 5 ����", 30, CLOTHES, pEquipStatus);
		break;
	case CLOTHES2:
		PEQUIPSTATUS(0, 0, 0, 0, 10, 0, 0);
		pItem = new Equip_Item("�߱� ����", "���� 10 ����", 60, CLOTHES, pEquipStatus);
		break;
	case CLOTHES3:
		PEQUIPSTATUS(0, 0, 0, 0, 15, 0, 0);
		pItem = new Equip_Item("��� ����", "���� 15 ����", 90, CLOTHES, pEquipStatus);
		break;
	case SHOES1:
		PEQUIPSTATUS(0, 0, 0, 0, 0, 5, 0);
		pItem = new Equip_Item("�ʱ� �Ź�", "���ǵ� 5 ����", 30, SHOES, pEquipStatus);
		break;
	case SHOES2:
		PEQUIPSTATUS(0, 0, 0, 0, 0, 10, 0);
		pItem = new Equip_Item("�߱� �Ź�", "���ǵ� 10 ����", 60, SHOES, pEquipStatus);
		break;
	case SHOES3:
		PEQUIPSTATUS(0, 0, 0, 0, 0, 15, 0);
		pItem = new Equip_Item("��� �Ź�", "���ǵ� 15 ����", 90, SHOES, pEquipStatus);
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
// ����� �ɷ�ġ �ö󰡴°� ��� ����?