#include "pch.h"
#include "Equip_Item.h"

Equip_Item* Equip_Item::Create_Equip_Item(const int _iItemNum)
{
	Equip_Item* pReturn = nullptr;

	switch (_iItemNum)
	{
	case SWORD1 :
		pReturn = new Equip_Item("�ʱ� ��", 203, 30, SWORD);
		break;
	case SWORD2:
		pReturn = new Equip_Item("�߱� ��", 206, 60, SWORD);
		break;
	case SWORD3:
		pReturn = new Equip_Item("��� ��", 209, 90, SWORD);
		break;
	case STAFF1:
		pReturn = new Equip_Item("�ʱ� ������", 203, 30, STAFF);
		break;
	case STAFF2:
		pReturn = new Equip_Item("�߱� ������", 206, 60, STAFF);
		break;
	case STAFF3:
		pReturn = new Equip_Item("��� ������", 209, 90, STAFF);
		break;
	case DAGGER1:
		pReturn = new Equip_Item("�ʱ� �ܰ�", 203, 30, DAGGER);
		break;
	case DAGGER2:
		pReturn = new Equip_Item("�߱� �ܰ�", 206, 60, DAGGER);
		break;
	case DAGGER3:
		pReturn = new Equip_Item("��� �ܰ�", 209, 90, DAGGER);
		break;
	case HAT1:
		pReturn = new Equip_Item("�ʱ� ����", 103, 30, HAT);
		break;
	case HAT2:
		pReturn = new Equip_Item("�߱� ����", 106, 60, HAT);
		break;
	case HAT3:
		pReturn = new Equip_Item("��� ����", 109, 90, HAT);
		break;
	case CLOTHES1:
		pReturn = new Equip_Item("�ʱ� ��", 303, 30, CLOTHES);
		break;
	case CLOTHES2:
		pReturn = new Equip_Item("�߱� ��", 306, 60, CLOTHES);
		break;
	case CLOTHES3:
		pReturn = new Equip_Item("��� ��", 309, 90, CLOTHES);
		break;
	case SHOES1:
		pReturn = new Equip_Item("�ʱ� �Ź�", 403, 30, SHOES);
		break;
	case SHOES2:
		pReturn = new Equip_Item("�߱� �Ź�", 406, 60, SHOES);
		break;
	case SHOES3:
		pReturn = new Equip_Item("��� �Ź�", 409, 90, SHOES);
		break;
	default:
		break;
	}
	return pReturn;
}

void Equip_Item::Info_Render() const
{
	cout << Status_Name_Render() << " " << m_iUpStatus % 100 << " ���";
}

const char* Equip_Item::Status_Name_Render() const
{
	switch (m_iUpStatus / 100)
	{
	case 1:
		return "ü��";
	case 2:
		return "���ݷ�";
	case 3:
		return "����";
	case 4:
		return "���ǵ�";
	default:
		return "";
	}
}
