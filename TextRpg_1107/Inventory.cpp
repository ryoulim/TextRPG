#include "pch.h"
#include "Inventory.h"
#include "Define.h"

int Inventory::m_iPlayerGold = 0;

void Inventory::Add_Item(Item* _pItem, const int _iCount)
{
	Element* pPreNode = &m_HeadNode; // 더미 헤드노트
	for (int i = 0; i < m_iListLength; ++i)
	{
		pPreNode = pPreNode->pLink;
		if (*_pItem == *pPreNode->pItem) // 아이템에서 연산자 오버로딩 할것
		{
			pPreNode->iCount++;
			return;
		}
	}
	Element* pNewNode = new Element;
	pPreNode->pLink = pNewNode;
	pNewNode->iCount = _iCount;

	pNewNode->pItem = _pItem->Copy();
	m_iListLength++;

	pNewNode->pLink = nullptr;
}

void Inventory::Add_Item(const int _iIndex, const int iCount)
{
	if (0 > _iIndex || m_iListLength < _iIndex)
		return; // 오류

	Element* pNode = &m_HeadNode;
	for (int i = 0; i <= _iIndex; ++i) //인덱스의 위치까지 이동
		pNode = pNode->pLink;
	pNode->iCount++;
}

void Inventory::Remove_Item(Item* _pItem, const int _iCount)
{
	Element* pPreNode = &m_HeadNode; // 더미 헤드노트
	Element* pPrePreNode = nullptr;
	for (int i = 0; i < m_iListLength; ++i)
	{
		pPrePreNode = pPreNode;
		pPreNode = pPrePreNode->pLink;
		if (*_pItem == *pPreNode->pItem) // 아이템
		{
			pPreNode->iCount--;
			if (0 == pPreNode->iCount)
			{
				m_iListLength--;
				pPrePreNode->pLink = pPreNode->pLink;
				SAFE_DELETE(pPreNode->pItem);
				SAFE_DELETE(pPreNode);
			}
			break;
		}
	}
}

void Inventory::Remove_Item(const int _iIndex, const int iCount)
{
	Element* pPreNode = &m_HeadNode; // 더미 헤드노트
	Element* pPrePreNode = nullptr;
	for (int i = 0; i <= _iIndex; ++i)
	{
		pPrePreNode = pPreNode;
		pPreNode = pPrePreNode->pLink;
		pPreNode->iCount--;
		if (0 == pPreNode->iCount)
		{
			m_iListLength--;
			pPrePreNode->pLink = pPreNode->pLink;
			SAFE_DELETE(pPreNode->pItem);
			SAFE_DELETE(pPreNode);
		}
		break;
	}
}

Item* Inventory::Get_Item(const int _iIndex)
{
	Element* pNode = &m_HeadNode;
	for (int i = 0; i <= _iIndex; ++i)
		pNode = pNode->pLink;
	return pNode->pItem;
}

void Inventory::Render()
{
	Element* pNode = &m_HeadNode;
	for (int i = 0; i < m_iListLength; ++i)
	{
		pNode = pNode->pLink;
		cout << i + 1 << ". " << pNode->pItem->Get_Name() << " : " << pNode->pItem->Get_Info() << endl;
	}
}

void Inventory::Release()
{
	Element* pNode = &m_HeadNode;
	Element* pPreNode = nullptr;
	for (int i = 1; i <= m_iListLength; ++i)
	{
		pPreNode = pNode;
		pNode = pNode->pLink;
		delete pPreNode->pItem;
		delete pPreNode;
	}
}
