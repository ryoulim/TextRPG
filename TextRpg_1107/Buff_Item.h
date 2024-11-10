#pragma once
#include "Useable_Item.h"

class Buff_Item : public Useable_Item
{
public:
	static Item* Create_Item(const int _iItemNum);

	~Buff_Item() {}
	void Use_Item(Objecct* _pPlayer) override {};
	Item* Copy() override;

	enum BUFF_ITEM_LIST {ATKUP=1,DEFUP};
private:
	int* m_pBuffStatus; // ��������ͽ��� ����, �ø����� ��������

	Buff_Item(const char* _szName, const char* _szInfo, int _iCost, int* _pBuffStatus) : Useable_Item(_szName,_szInfo,_iCost,Useable_Item::BUFF_ITEM),
		m_pBuffStatus(_pBuffStatus) {}
};
