#pragma once
#include "Useable_Item.h"

class Potion_Item : public Useable_Item
{
public:
	~Potion_Item() {}
	static Item* Create_Item(const int _iItemNum);

	void Use_Item(Objecct* _pPlayer) override {};
	Item* Copy() override;

	enum POTION_LIST {POTION1=1,POTION2};
private:
	bool m_bType;// 상숫값 false 퍼센트 true
	int m_iForce;

	Potion_Item(const char* _szName, const char* _szInfo, int _iCost, int _iForce, bool _bType) : Useable_Item(_szName, _szInfo, _iCost, Useable_Item::POTION_ITEM),
		m_iForce(_iForce), m_bType(_bType) {}
};