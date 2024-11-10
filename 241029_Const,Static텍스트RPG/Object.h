#pragma once
#include "Define.h"
#include "Bag.h"

class Object
{
public:
	Object() : m_pStatus(nullptr) {}
	virtual ~Object();

	bool Damaged(int _iDamage);
	void Heal(int _iForce);
	void Set_Mp(int _iMp) { m_pStatus->iMp = _iMp; }

	Status* Get_Status() const { return m_pStatus; }

	virtual void Initialize(const int _iNum) {}
	virtual void Info_Render() const {}
	virtual void Release();

	//virtual Bag* Get_Bag_Equip() { return 0; }
	//virtual Bag* Get_Bag_Useable() { return 0; }
	//virtual Bag* Get_Bag_Other() { return 0; }

	virtual void Exp_Cal(int _iTmp) {}
	virtual void LvUp() {}
	virtual void Set_Skill(const int _iIndex, const int _iValue) {}

	virtual int Get_Gold() const { return 0; }
	virtual int Get_iDropItem() const { return 0; }

protected:
	Status* m_pStatus;
};
