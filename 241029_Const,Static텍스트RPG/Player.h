#pragma once
#include "Define.h"
#include "Bag.h"

class Player
{
public:
	Player();
	~Player();

	void Initialize(const int _iClassNum);
	void Info_Render();
	Status* Get_Status() { return m_pStatus; }
	Bag* Get_Bag() { return m_pBag; }
	bool Damaged(int _iDamage);
	void Exp_Plus(int _iAdd) { m_pStatus->iExp += _iAdd; }
	void Exp_Minus(int _iMinus);
	void Heal(int _iForce);
	void LvUp(); // ·¹º§¾÷
	void Release();

	enum CLASSNUM {WARRIOR,MAGE,THIEF,END};

private:
	Status* m_pStatus;
	Bag* m_pBag;
};

