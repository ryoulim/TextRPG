#include "pch.h"
#include "Item.h"

void Item::Initalize(const int _iNum, const int _iCount)
{
	m_pItemInfo = new ItemInfo;
	switch (_iNum)
	{
	case ITEM1:
		memcpy_s(m_pItemInfo->szName, sizeof(m_pItemInfo->szName), &"초급 몬스터 아이템", sizeof("초급 몬스터 아이템"));
		m_pItemInfo->iNumber = 1;
		memcpy_s(m_pItemInfo->szInfo, sizeof(m_pItemInfo->szInfo), &"초급 몬스터 아이템이다.", sizeof("초급 몬스터 아이템이다."));
		m_pItemInfo->iCost = 10;
		m_pItemInfo->iCount = _iCount;
		break;
	case ITEM2:
		memcpy_s(m_pItemInfo->szName, sizeof(m_pItemInfo->szName), &"중급 몬스터 아이템", sizeof("중급 몬스터 아이템"));
		m_pItemInfo->iNumber = 2;
		memcpy_s(m_pItemInfo->szInfo, sizeof(m_pItemInfo->szInfo), &"중급 몬스터 아이템이다.", sizeof("중급 몬스터 아이템이다."));
		m_pItemInfo->iCost = 20;
		m_pItemInfo->iCount = _iCount;
		break;
	case ITEM3:
		memcpy_s(m_pItemInfo->szName, sizeof(m_pItemInfo->szName), &"고급 몬스터 아이템", sizeof("고급 몬스터 아이템"));
		m_pItemInfo->iNumber = 3;
		memcpy_s(m_pItemInfo->szInfo, sizeof(m_pItemInfo->szInfo), &"고급 몬스터 아이템이다.", sizeof("고급 몬스터 아이템이다."));
		m_pItemInfo->iCost = 30;
		m_pItemInfo->iCount = _iCount;
		break;
	case POTION1:
		memcpy_s(m_pItemInfo->szName, sizeof(m_pItemInfo->szName), &"일반 포션", sizeof("일반 포션"));
		m_pItemInfo->iNumber = 4;
		memcpy_s(m_pItemInfo->szInfo, sizeof(m_pItemInfo->szInfo), &"체력 30 회복", sizeof("체력 30 회복"));
		m_pItemInfo->iCost = 30;
		m_pItemInfo->iCount = _iCount;
		break;
	case POTION2:
		memcpy_s(m_pItemInfo->szName, sizeof(m_pItemInfo->szName), &"고급 포션", sizeof("고급 포션"));
		m_pItemInfo->iNumber = 5;
		memcpy_s(m_pItemInfo->szInfo, sizeof(m_pItemInfo->szInfo), &"체력 60 회복", sizeof("체력 60 회복"));
		m_pItemInfo->iCost = 50;
		m_pItemInfo->iCount = _iCount;
		break;
	default:
		cout << "예외발생 void Item::Initalize(const int _iNum)" << endl;
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
		return "초급 몬스터 아이템";
	case ITEM2:
		return "중급 몬스터 아이템";
	case ITEM3:
		return "고급 몬스터 아이템";
	case POTION1:
		return "일반 포션";
	case POTION2:
		return "고급 포션";
	}
}

void Item::Copy(Item* _pItem)
{
	SAFE_DELETE(m_pItemInfo);
	m_pItemInfo = new ItemInfo;
	*m_pItemInfo = *_pItem->Get_ItemInfo();
}
