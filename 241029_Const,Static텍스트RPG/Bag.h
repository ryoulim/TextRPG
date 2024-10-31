#pragma once
#include "Item.h"

class Bag
{
public:
	Bag() : m_iGold(0), m_iKind(0), m_pItem(nullptr) {}
	~Bag();

	void Release();

	int Get_Gold() { return m_iGold; }
	void Gold_Plus(int _iAdd) { m_iGold += _iAdd; }
	void Gold_Minus(int _iMinus);
	int Get_iKind() { return m_iKind; }

	void Update(const int _iNum, const int _iCount); // 어떤 아이템을 몇개나 증가시키는가?
	//void Use_Item
	void Info_Render();
	void Gold_Render() const;
	void Delete_Null(int _iCount);

	Item* Get_Item() { return m_pItem; }
	
private:
	int m_iGold;
	int m_iKind; // 현재 지니고있는 아이템의 가짓수
	Item* m_pItem;

	void New_Array(bool _bMode);
};

