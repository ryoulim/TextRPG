#pragma once
#include "Object.h"
#include "Equip_Item.h"
#include "Define.h"

class Player : public Object
{
public:
	enum CLASS_LIST { WARRIOR, MAGE, THIEF };

	Player(string* _pstrName, int _iHp, int _iAtk, int _iDef, int _iSpd, CLASS_LIST _Class)
		: Object(_pstrName, _iHp, _iAtk, _iDef, _iSpd), m_pInventory(nullptr),
		m_Class(_Class) {}
	~Player() { Release(); }
	Inventory* Get_Inven() { return m_pInventory; }

	void View_Status();
	void Equip_Change();

	void Info_Render() override;

	void Initalize() { m_pInventory = new Inventory(); }
	void Release() { Safe_Delete<Inventory*>(m_pInventory); }
	int Get_Class() { return m_Class; }


private:
	CLASS_LIST m_Class;
	Inventory* m_pInventory;

	const char* Class_Name_Render() const;
};

