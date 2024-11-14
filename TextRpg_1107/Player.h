#pragma once
#include "Object.h"
#include "Inventory.h"

class Player : public Object
{
public:
	~Player() {}

	static Object* Create_Player(const int _iClassNum, char _szName[]);
	void Info_Render() const override;
	void Info_Render_Detail() const override;

	int Skill_Select();
	int Item_Select();

	void Exp_Update(const int _Exp);

	virtual void LvUp() override;

	Inventory* Get_Inven(Item::ITEM_TYPE _Type) { return &m_Inven[_Type]; }

	enum CLASS_LIST { WARRIOR = 1, MAGE, THIEF, END };
private:
	bool bEquip[MAX_STATUS]; // true - Âø¿ëÁß, false - ¹ÌÂø¿ë
	Inventory m_Inven[3];

	Player(char _szName[], int _iHp, int _iMp, int _iAtk, int _iM_Atk, int _iDef, int _iSpeed, const char* _pClass, int* _pType)
	: Object(_szName,_iHp,_iMp,_iAtk,_iM_Atk,_iDef, _iSpeed,_pClass,_pType),
		bEquip(){}
};

