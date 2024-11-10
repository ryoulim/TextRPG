#pragma once
#include "Useable_Item.h"


class Attack_Item : public Useable_Item
{
public:
	~Attack_Item() {}

	static Item* Create_Item(const int _iItemNum);

	void Use_Item(Objecct* _pPlayer) override {};
	Item* Copy() override;
	
	enum ATTACK_ITEM_LIST {BOMB = 1};
	enum EFFECT {NONE=0,BURN,FRIZE};

private:
	int m_iForce;
	int m_iType;
	int m_iEffect;

	Attack_Item(const char* _szName, const char* _szInfo, int _iCost, int _iForce, int _iType, int _iEffect) : Useable_Item(_szName,_szInfo,_iCost, Useable_Item::ATTACK_ITEM),
		m_iForce(0), m_iType(0), m_iEffect(0) {}
};