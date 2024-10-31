#pragma once
#include "Define.h"

class Item
{
public:
	Item() : m_pItemInfo(nullptr) {}
	~Item() { Release(); }

	void Initalize(const int _iNum, const int _iCount);
	bool Count_Cal(const int _iCount); // 0이되면 bag에서 이 아이템의 배열을 삭제하기 위해 true 반환
	int Get_Num() { return m_pItemInfo->iNumber; }
	void Release();

	static const char* Name_Render(const int _iItemNum);
	ItemInfo* Get_ItemInfo() { return m_pItemInfo; }
	void Copy(Item* _pItem);

	enum ITEMNAME { ITEM1 = 1, ITEM2, ITEM3, POTION1, POTION2, End };
private:
	ItemInfo* m_pItemInfo;
};