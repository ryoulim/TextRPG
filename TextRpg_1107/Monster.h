#pragma once
#include "Object.h"

class Monster : public Object
{
public:
	static Object* Create_Monster(const int _iFloor);

	void Info_Render() const override;
	void Info_Render_Detail() const override;
	void Set_Skill(Skill* _pSKill, const int _iIndex) override { m_pSkill[_iIndex] = _pSKill; m_iActionCount++; }
	const int Get_DropItemNum() { return m_iDropItemNum; }
	const int Get_DropGold() { return m_iDropGold; }


	//enum MONSTER_LIST {};
	bool Monster_Ai(Object* _pPlayer);
	virtual void LvUp() override {}

private:
	int m_iActionCount;
	const int m_iDropItemNum;
	const int m_iDropGold;

	Monster(char _szName[], int _iHp, int _iMp, int _iAtk, int _iM_Atk, int _iDef, int _iSpeed, const char* _pClass, int* _pType, const int _iDropItemNum, const int _iDropGold)
		: Object(_szName, _iHp, _iMp, _iAtk, _iM_Atk, _iDef, _iSpeed, _pClass, _pType), m_iActionCount(2), m_iDropItemNum(_iDropItemNum), m_iDropGold(_iDropGold) {}
};

