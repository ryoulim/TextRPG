#include "pch.h"
#include "Bag.h"
#include "Define.h"

int Bag::m_iGold = 0;

Bag::~Bag()
{
	Release();
}

void Bag::Release()
{
	SAFE_DELETE_ARRAY(m_pItem);
	SAFE_DELETE_ARRAY(m_pItemCount);
}

void Bag::Initialize(const int _iType)
{
	switch (_iType)
	{
	case EQUIP:
		m_pItemClass = new Equip_Item;
		break;
	case USEABLE:
		m_pItemClass = new Useable_Item;
		break;
	case OTHER:
		m_pItemClass = new Other_Item;
		break;
	default:
		cout << "예외발생 void Bag::Initialize(const int _iType)" << endl;
		break;
	}
}

void Bag::Update(const int _iNum, const int _iCount)
{

	for (int i = 0; i < m_iKind; ++i)
	{
		if (m_pItem[i]== _iNum)
		{
			m_pItemCount[i] += _iCount;
			if (0 >= m_pItemCount[i])
				Minus_Array(i);
			return;
		}
	} // 가방안에 같은 아이템이 있을경우

	Plus_Array();
	m_pItem[m_iKind - 1] = _iNum;
	m_pItemCount[m_iKind - 1] = _iCount;
	//가방에 같은 아이템이 없는경우
}

void Bag::Minus_Array(int _iNum)
{
	m_iKind--;
	if (m_iKind == 0)
	{
		SAFE_DELETE_ARRAY(m_pItem);
		SAFE_DELETE_ARRAY(m_pItemCount);
	}
	else
	{
		int* pCopyItem = new int[m_iKind];
		int* p_CopyItemCount = new int[m_iKind];
		for (int j = 0; j < _iNum; j++)
		{
			pCopyItem[j] = m_pItem[j];
			p_CopyItemCount[j] = m_pItemCount[j];
		}
		for (int j = _iNum; j < m_iKind; ++j)
		{
			pCopyItem[j] = m_pItem[j + 1];
			p_CopyItemCount[j] = m_pItemCount[j];
		}
		SAFE_DELETE_ARRAY(m_pItem);
		SAFE_DELETE_ARRAY(m_pItemCount);
		m_pItem = pCopyItem;
		m_pItemCount = p_CopyItemCount;
	}
}

void Bag::Plus_Array()
{
	m_iKind++;
	int* pCopyItem = new int[m_iKind];
	int* p_CopyItemCount = new int[m_iKind];

	for (int i = 0; i < m_iKind - 1; ++i)
	{
		pCopyItem[i] = m_pItem[i];
		p_CopyItemCount[i] = m_pItemCount[i];
	}
	SAFE_DELETE_ARRAY(m_pItem);
	SAFE_DELETE_ARRAY(m_pItemCount);
	m_pItem = pCopyItem;
	m_pItemCount = p_CopyItemCount;
}

bool Bag::Gold_Cal(int _iTmp)
{
	if (0 > m_iGold + _iTmp)
		return false;
	else
	{
		m_iGold += _iTmp;
		return true;
	}
}

void Bag::Info_Render() const
{
	cout << "==============================" << endl;
	cout << "소유금 : " << m_iGold << endl;
	cout << "   이름\t\t\t\t설명" << endl;
	for (int i = 0; i < m_iKind; ++i)
		cout << i+1 << " : " << m_pItemClass->Get_Name(m_pItem[i]) << "(" << m_pItemCount[i] << ")" << "\t" << m_pItemClass->Get_Info(m_pItem[i]) << endl;
}

void Bag::Gold_Render() const
{
	cout << "==============================" << endl;
	cout << "소유금 : " << m_iGold << endl;
}

void Bag::Sell_Item(const int _iIndex)
{
	m_iGold += m_pItemClass->Get_Cost(m_pItem[_iIndex]) / 2;
	m_pItemCount[_iIndex]--;
	if (0 >= m_pItemCount[_iIndex])
		Minus_Array(_iIndex);
}
