#pragma once

class Object;

class Item
{
public:
	virtual ~Item() {}

	bool operator ==(Item& rhs) { return !strcmp(m_szName, rhs.m_szName); }

	static Item* Create_Item(const int _iItemNum);

	enum ITEM_TYPE { EQUIP, USEABLE, OTHER };
	enum EQUIP_ITEM_LIST
	{
		SWORD1, SWORD2,
		STAFF1, STAFF2,
		DAGGER1, DAGGER2,
		HAT1, HAT2, HAT3,
		CLOTHES1, CLOTHES2, CLOTHES3,
		SHOES1, SHOES2, SHOES3
	};
	enum OTHER_ITEM_LIST { SLIMEITEM = SHOES3+1, PIXIEITEM, DEMONITEM };
	enum BUFF_ITEM_LIST { ATKUP = DEMONITEM+1, DEFUP };
	enum POTION_LIST { POTION1 = DEFUP+1, POTION2 };
	enum ATTACK_ITEM_LIST { BOMB = POTION2+1};



	virtual void Use_Item(Object* _pPlayer) = 0;
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

