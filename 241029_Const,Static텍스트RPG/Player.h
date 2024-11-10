#pragma once
#include "Define.h"
#include "Bag.h"
#include "Object.h"


class Player : public Object
{
public:
	Player() : m_pBag_Equip(nullptr),m_pBag_Useable(nullptr), m_pBag_Other(nullptr) {}
	~Player();

	void Initialize(const int _iNum);
	void Info_Render() const;
	Bag* Get_Bag_Equip() const { return m_pBag_Equip; }
	Bag* Get_Bag_Useable() const  { return m_pBag_Useable; }
	Bag* Get_Bag_Other() const  { return m_pBag_Other; }

	void Exp_Cal(int _iTmp);

	void LvUp(); // ·¹º§¾÷
	void Release();

	void Set_Skill(const int _iIndex, const int _iValue) { m_pStatus->iSkill[_iIndex] = _iValue; }

	enum CLASSNUM {WARRIOR,MAGE,THIEF,END};

private:
	Bag* m_pBag_Equip;
	Bag* m_pBag_Useable;
	Bag* m_pBag_Other;
};

