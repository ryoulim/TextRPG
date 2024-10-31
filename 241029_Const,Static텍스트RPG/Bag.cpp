#include "pch.h"
#include "Bag.h"
#include "Define.h"

Bag::~Bag()
{
	Release();
}

void Bag::Release()
{
	SAFE_DELETE_ARRAY(m_pItem);
}

void Bag::Gold_Minus(int _iMinus)
{
	m_iGold -= _iMinus;
	if (m_iGold < 0)
		m_iGold = 0;
}

void Bag::Update(const int _iNum, const int _iCount)
{
	for (int i = 0; i < m_iKind; ++i)
	{
		if (m_pItem[i].Get_Num() == _iNum)
		{
			if (m_pItem[i].Count_Cal(_iCount))
			{
				for (int j = i; j < m_iKind - 1; ++j)
					m_pItem[j].Copy(&m_pItem[j + 1]);
				New_Array(false);
			}
			return;
		}
	}
	New_Array(true);
	m_pItem[m_iKind - 1].Initalize(_iNum, _iCount);
}

void Bag::New_Array(bool _bMode) // true-> �迭 ����, false-> �迭 ����
{
	if (_bMode)
	{
		m_iKind++;
		Item* pCopyItem = new Item[m_iKind]; // �迭�� ���� ��������ڰ� ������ �ȵǴµ�?
		for (int i = 0; i < m_iKind - 1; ++i)
			pCopyItem[i].Copy(&m_pItem[i]);
		SAFE_DELETE_ARRAY(m_pItem);
		m_pItem = pCopyItem;
		pCopyItem = nullptr;
	}
	else
	{
		m_iKind--;
		if (m_iKind == 0)
		{
			SAFE_DELETE_ARRAY(m_pItem);
			return;
		}
		Item* pCopyItem = new Item[m_iKind];
		for (int i = 0; i < m_iKind; ++i)
			pCopyItem[i].Copy(&m_pItem[i]);
		SAFE_DELETE_ARRAY(m_pItem);
		m_pItem = pCopyItem;
		pCopyItem = nullptr;
	}
}

void Bag::Info_Render()
{
	cout << "==============================" << endl;
	cout << "������ : " << m_iGold << endl;
	cout << "   �̸�\t\t\t\t����" << endl;
	for (int i = 0; i < m_iKind; ++i)
		cout << i+1 << " : " << m_pItem[i].Get_ItemInfo()->szName << "(" << m_pItem[i].Get_ItemInfo()->iCount << ")" << "\t" << m_pItem[i].Get_ItemInfo()->szInfo << endl;
}

void Bag::Gold_Render() const
{
	cout << "==============================" << endl;
	cout << "������ : " << m_iGold << endl;
}

void Bag::Delete_Null(int _iCount)
{
	for (int i = _iCount; i < m_iKind-1; ++i)
		m_pItem[i].Copy(&m_pItem[i + 1]);
	New_Array(false);
}

