#pragma once
#include "Item.h"

typedef struct tagElement
{
	int iCount;
	Item* pItem;
	tagElement* pLink;
} Element;

class Inventory
{
public:
	Inventory() : m_iListLength(0) { memset(&m_HeadNode, 0, sizeof(Element)); }
	~Inventory() { Release(); }

	void Add_Item(Item* _pItem, const int _iCount);
	void Add_Item(const int _iIndex, const int iCount);
	void Remove_Item(Item* _pItem, const int _iCount);
	void Remove_Item(const int _iIndex, const int iCount);

	Item* Get_Item(const int _iIndex);
	void Render();
	int Get_Length() { return m_iListLength; }
	static int m_iPlayerGold;
private:
	int	m_iListLength;
	Element m_HeadNode;

	void Release(); // deletelist의 역할 수행
};

