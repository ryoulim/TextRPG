#pragma once
#include <string>

#include "Inventory.h"

#define MAX_CLASS 3
#define MAX_STATUS 4

class Object
{
public:
	enum STATUS_LIST {HP,ATK,DEF,SPD};

	static Object* Create_Player(string* _pstrName, const int _iClassNum);
	static Object* Create_Monster(const int _iMonNum);

	Object(string* _pstrName, int _iMAXHp, int _iAtk, int _iDef, int _iSpd) : m_iStatus{ _iMAXHp, _iAtk, _iDef, _iSpd }, m_strName(*_pstrName), m_iHp(_iMAXHp){}
	virtual ~Object() {}

	virtual void Info_Render() = 0;

	void Set_Status(const int _iIndex, const int _iValue) { m_iStatus[_iIndex] += _iValue; }

protected:
	string m_strName;
	int m_iStatus[MAX_STATUS];
	int m_iHp;
};

