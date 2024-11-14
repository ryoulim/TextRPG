#pragma once
#include <string>

class Equip_Item
{
public:
	Equip_Item(const char* _szName, int _iUpStatus, int _iCost, const int _Type) : m_strName(_szName), m_iUpStatus(_iUpStatus), m_iCost(_iCost), m_Type(_Type){}
	~Equip_Item() {}

	enum Equip_Item_List 
	{
		SWORD1,SWORD2,SWORD3,
		STAFF1,STAFF2,STAFF3,
		DAGGER1,DAGGER2,DAGGER3,
		HAT1,HAT2,HAT3,
		CLOTHES1,CLOTHES2,CLOTHES3,
		SHOES1,SHOES2,SHOES3
	};
	enum Equip_Item_Type {SWORD,STAFF,DAGGER,HAT,CLOTHES,SHOES};

	static Equip_Item* Create_Equip_Item(const int _iItemNum);

	void Info_Render() const;
	const char* Get_Name() const { return m_strName.c_str(); }
	const char* Status_Name_Render() const;

	int Get_Type() { return m_Type; }
	int Get_Cost() { return m_iCost; }
	int Get_Status_Id() { return m_iUpStatus/100 - 1; }
	int Get_Stuats_Val() { return m_iUpStatus % 100;  }

private:
	const int m_Type;
	string m_strName;
	int m_iUpStatus; // 100의자리는 능력치번호, 나머지는 값
	int m_iCost;
};

