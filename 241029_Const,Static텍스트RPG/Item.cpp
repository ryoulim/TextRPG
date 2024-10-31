#include "pch.h"
#include "Item.h"

void Item::Initalize(const int _iNum, const int _iCount)
{
	m_pItemInfo = new ItemInfo;
	switch (_iNum)
	{
	case ITEM1:
		memcpy_s(m_pItemInfo->szName, sizeof(m_pItemInfo->szName), &"�ʱ� ���� ������", sizeof("�ʱ� ���� ������"));
		m_pItemInfo->iNumber = 1;
		memcpy_s(m_pItemInfo->szInfo, sizeof(m_pItemInfo->szInfo), &"�ʱ� ���� �������̴�.", sizeof("�ʱ� ���� �������̴�."));
		m_pItemInfo->iCost = 10;
		m_pItemInfo->iCount = _iCount;
		break;
	case ITEM2:
		memcpy_s(m_pItemInfo->szName, sizeof(m_pItemInfo->szName), &"�߱� ���� ������", sizeof("�߱� ���� ������"));
		m_pItemInfo->iNumber = 2;
		memcpy_s(m_pItemInfo->szInfo, sizeof(m_pItemInfo->szInfo), &"�߱� ���� �������̴�.", sizeof("�߱� ���� �������̴�."));
		m_pItemInfo->iCost = 20;
		m_pItemInfo->iCount = _iCount;
		break;
	case ITEM3:
		memcpy_s(m_pItemInfo->szName, sizeof(m_pItemInfo->szName), &"��� ���� ������", sizeof("��� ���� ������"));
		m_pItemInfo->iNumber = 3;
		memcpy_s(m_pItemInfo->szInfo, sizeof(m_pItemInfo->szInfo), &"��� ���� �������̴�.", sizeof("��� ���� �������̴�."));
		m_pItemInfo->iCost = 30;
		m_pItemInfo->iCount = _iCount;
		break;
	case POTION1:
		memcpy_s(m_pItemInfo->szName, sizeof(m_pItemInfo->szName), &"�Ϲ� ����", sizeof("�Ϲ� ����"));
		m_pItemInfo->iNumber = 4;
		memcpy_s(m_pItemInfo->szInfo, sizeof(m_pItemInfo->szInfo), &"ü�� 30 ȸ��", sizeof("ü�� 30 ȸ��"));
		m_pItemInfo->iCost = 30;
		m_pItemInfo->iCount = _iCount;
		break;
	case POTION2:
		memcpy_s(m_pItemInfo->szName, sizeof(m_pItemInfo->szName), &"��� ����", sizeof("��� ����"));
		m_pItemInfo->iNumber = 5;
		memcpy_s(m_pItemInfo->szInfo, sizeof(m_pItemInfo->szInfo), &"ü�� 60 ȸ��", sizeof("ü�� 60 ȸ��"));
		m_pItemInfo->iCost = 50;
		m_pItemInfo->iCount = _iCount;
		break;
	default:
		cout << "���ܹ߻� void Item::Initalize(const int _iNum)" << endl;
		break;
	}
}

bool Item::Count_Cal(const int _iCount)
{
	m_pItemInfo->iCount += _iCount;
	if (0 == m_pItemInfo->iCount)
		return true;
	else
		return false;
}

void Item::Release()
{
	SAFE_DELETE(m_pItemInfo);
}

const char* Item::Name_Render(const int _iItemNum)
{
	switch (_iItemNum)
	{
	case ITEM1:
		return "�ʱ� ���� ������";
	case ITEM2:
		return "�߱� ���� ������";
	case ITEM3:
		return "��� ���� ������";
	case POTION1:
		return "�Ϲ� ����";
	case POTION2:
		return "��� ����";
	}
}

void Item::Copy(Item* _pItem)
{
	SAFE_DELETE(m_pItemInfo);
	m_pItemInfo = new ItemInfo;
	*m_pItemInfo = *_pItem->Get_ItemInfo();
}
