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
		pItem = new Equip_Item("�ʱ� ��", "���ݷ� 5 ����", 30, Equip_Item::Equip_Item::WEAPON, pStatus);
		break;
	case SWORD2:
		pStatus = new int[MAX_STATUS];
		PSTATUS(0, 0, 5, 0, 0, 0, 0);
		pItem = new Equip_Item("�߱� ��", "���ݷ� 10 ����", 60, Equip_Item::WEAPON, pStatus);
		break;
	case STAFF1:
		pStatus = new int[MAX_STATUS];
		PSTATUS(0, 0, 0, 10, 0, 0, 0);
		pItem = new Equip_Item("�ʱ� ������", "�������ݷ� 5 ����", 30, Equip_Item::WEAPON, pStatus);
		break;
	case STAFF2:
		pStatus = new int[MAX_STATUS];
		PSTATUS(0, 0, 0, 10, 0, 0, 0);
		pItem = new Equip_Item("�߱� ������", "�������ݷ� 10 ����", 60, Equip_Item::WEAPON, pStatus);
		break;
	case DAGGER1:
		pStatus = new int[MAX_STATUS];
		PSTATUS(0, 0, 3, 3, 0, 0, 0);
		pItem = new Equip_Item("�ʱ� �ܰ�", "���ݷ� 3, �������ݷ� 3 ����", 30, Equip_Item::WEAPON, pStatus);
		break;
	case DAGGER2:
		pStatus = new int[MAX_STATUS];
		PSTATUS(0, 0, 6, 6, 0, 0, 0);
		pItem = new Equip_Item("�߱� �ܰ�", "���ݷ� 6, �������ݷ� 6 ����", 60, Equip_Item::WEAPON, pStatus);
		break;
	case HAT1:
		PSTATUS(5, 0, 0, 0, 0, 0, 0);
		pStatus = new int[MAX_STATUS];
		pItem = new Equip_Item("�ʱ� ����", "ü�� 5 ����", 30, Equip_Item::Equip_Item::HAT, pStatus);
		break;
	case HAT2:
		PSTATUS(10, 0, 0, 0, 0, 0, 0);
		pStatus = new int[MAX_STATUS];
		pItem = new Equip_Item("�߱� ����", "ü�� 10 ����", 60, Equip_Item::Equip_Item::HAT, pStatus);
		break;
	case HAT3:
		pStatus = new int[MAX_STATUS];
		PSTATUS(15, 0, 0, 0, 0, 0, 0);
		pItem = new Equip_Item("��� ����", "ü�� 15 ����", 90, Equip_Item::Equip_Item::HAT, pStatus);
		break;
	case CLOTHES1:
		pStatus = new int[MAX_STATUS];
		PSTATUS(0, 0, 0, 0, 5, 0, 0);
		pItem = new Equip_Item("�ʱ� ����", "���� 5 ����", 30, Equip_Item::CLOTHES, pStatus);
		break;
	case CLOTHES2:
		pStatus = new int[MAX_STATUS];
		PSTATUS(0, 0, 0, 0, 10, 0, 0);
		pItem = new Equip_Item("�߱� ����", "���� 10 ����", 60, Equip_Item::CLOTHES, pStatus);
		break;
	case CLOTHES3:
		pStatus = new int[MAX_STATUS];
		PSTATUS(0, 0, 0, 0, 15, 0, 0);
		pItem = new Equip_Item("��� ����", "���� 15 ����", 90, Equip_Item::CLOTHES, pStatus);
		break;
	case SHOES1:
		pStatus = new int[MAX_STATUS];
		PSTATUS(0, 0, 0, 0, 0, 5, 0);
		pItem = new Equip_Item("�ʱ� �Ź�", "���ǵ� 5 ����", 30, Equip_Item::SHOES, pStatus);
		break;
	case SHOES2:
		pStatus = new int[MAX_STATUS];
		PSTATUS(0, 0, 0, 0, 0, 10, 0);
		pItem = new Equip_Item("�߱� �Ź�", "���ǵ� 10 ����", 60, Equip_Item::SHOES, pStatus);
		break;
	case SHOES3:
		pStatus = new int[MAX_STATUS];
		PSTATUS(0, 0, 0, 0, 0, 15, 0);
		pItem = new Equip_Item("��� �Ź�", "���ǵ� 15 ����", 90, Equip_Item::SHOES, pStatus);
		break;
	case SLIMEITEM:
		pItem = new Other_Item("�������� ����", "�����δ�.", 10);
		break;
	case PIXIEITEM:
		pItem = new Other_Item("��������", "��¦�δ�.", 10);
		break;
	case DEMONITEM:
		pItem = new Other_Item("�Ǹ��� ����", "�޷��δ�.", 10);
		break;
	case ATKUP:
		pStatus = new int[MAX_STATUS];
		PSTATUS(0, 0, 3, 0, 0, 0, 0);
		pItem = new Buff_Item("���� ��", "3�ϰ� ���ݷ� ����", 15, pStatus);
		break;
	case DEFUP:
		pStatus = new int[MAX_STATUS];
		PSTATUS(0, 0, 0, 3, 0, 0, 0);
		pItem = new Buff_Item("���潺 ��", "3�ϰ� ���� ����", 15, pStatus);
		break;
	case BOMB:
		pItem = new Attack_Item("��ź", "�븻Ÿ���� 30������", 15, 30, Object::NORMAL, Skill::NONE);
		break;
	case POTION1:
		pItem = new Potion_Item("�Ϲ� ����", "ü�� 30 ȸ��", 30, 30, false);
		break;
	case POTION2:
		pItem = new Potion_Item("��� ����", "ü�� 50% ȸ��", 50, 50, true);
		break;
	default:
		break;
	}
    return pItem;
}
