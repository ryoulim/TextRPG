#pragma once
#include "Equip_Item.h"
#include "Useable_Item.h"
#include "Other_Item.h"

class Bag
{
public:
	Bag() : m_iKind(0), m_pItem(nullptr), m_pItemCount(nullptr), m_pItemClass(nullptr) { m_iGold = 0; }
	~Bag();

	void Release();

	int Get_iKind() const { return m_iKind; }
	int* Get_pItem() const { return m_pItem; }

	void Initialize(const int _iType);
	void Update(const int _iNum, const int _iCount); // 어떤 아이템을 몇개나 증가시키는가?
	bool Gold_Cal(int _iTmp);

	void Info_Render() const;
	void Gold_Render() const;

	void Sell_Item(const int _iIndex);

	enum BagType {EQUIP,USEABLE,OTHER,END};

	static int m_iGold;

private:
	
	int m_iKind; // 현재 지니고있는 아이템의 가짓수
	int* m_pItem; // 동적배열로 만들어서, 아이템 고유 번호 저장
	int* m_pItemCount; // 동적배열로 만들어서 같은 인덱스상의 아이템의 갯수저장.
	Item* m_pItemClass;

	void Minus_Array(int _iNum);
	void Plus_Array();
};