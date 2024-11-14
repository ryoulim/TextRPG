#pragma once
#include "Useable_Item.h"

class Potion_Item : public Useable_Item
{
public:
	Potion_Item(const char* _szName, const char* _szInfo, int _iCost, int _iForce, bool _bType) : Useable_Item(_szName, _szInfo, _iCost, Useable_Item::POTION_ITEM),
		m_iForce(_iForce), m_bType(_bType) {}
	~Potion_Item() {}

	void Use_Item(Object* _pPlayer) override {};
	Item* Copy() override;

private:
	bool m_bType;// 상숫값 false 퍼센트 true
	int m_iForce;

};