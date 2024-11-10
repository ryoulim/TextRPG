#pragma once
#include "Item.h"
#include "Object.h"

class Useable_Item : public Item
{
public:
	virtual const char* Get_Name(const int _iItemNum) const;
	virtual const char* Get_Info(const int _iItemNum) const;
	virtual int Get_Cost(const int _iItemNum) const;
	virtual bool Use_Item(Object* _pObject) const;

	enum ITEMNAME { POTION1 = 1, POTION2, END };
};
