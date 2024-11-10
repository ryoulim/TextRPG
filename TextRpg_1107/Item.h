#pragma once

class Objecct;

class Item
{
public:
	virtual ~Item() {}

	bool operator ==(Item& rhs) { return !strcmp(m_szName, rhs.m_szName); }

	enum ITEM_TYPE { EQUIP, USEABLE, OTHER };

	virtual void Use_Item(Objecct* _pPlayer) = 0;
	virtual Item* Copy() = 0;

	const char* Get_Name() { return m_szName; }
	const char* Get_Info() { return m_szInfo; }
	ITEM_TYPE Get_Type() { return m_Type; }
	
protected:
	char m_szName[32];
	char m_szInfo[48];
	int m_iCost; // 구매가격
	ITEM_TYPE m_Type;

	Item(const char* _szName, const char* _szInfo, int _iCost, ITEM_TYPE _Type) : m_iCost(_iCost), m_Type(_Type)
	{
		strcpy_s(m_szName, sizeof(m_szName), _szName);
		strcpy_s(m_szInfo, sizeof(m_szInfo), _szInfo);
	}
};

