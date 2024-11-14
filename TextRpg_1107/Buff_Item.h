#pragma once
#include "Useable_Item.h"

class Buff_Item : public Useable_Item
{
public:
	Buff_Item(const char* _szName, const char* _szInfo, int _iCost, int* _pBuffStatus) : Useable_Item(_szName, _szInfo, _iCost, Useable_Item::BUFF_ITEM),
		m_pBuffStatus(_pBuffStatus) {}
	~Buff_Item() {}
	void Use_Item(Object* _pPlayer) override {};
	Item* Copy() override;

private:
	int* m_pBuffStatus; // ��������ͽ��� ����, �ø����� ��������

};
