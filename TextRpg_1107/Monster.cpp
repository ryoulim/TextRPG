#include "pch.h"
#include "Monster.h"
#include "Define.h"

#include "Slime.h"
#include "Pixie.h"
#include "Demon.h"

#include "Skill.h"

Object* Monster::Create_Monster(const int _iFloor)
{
	Object* pObject = nullptr;
	int iMonNum = rand() % 3 + 1;
	// 층당 종류 3개씩
	switch ((_iFloor-1)*3 + iMonNum)
	{
	case 1:
		pObject = new Slime;
		break;
	case 2:
	case 3:

	case 4:
	case 5:
	case 6:

	case 7:
	case 8:
	case 9:

	case 10:
	case 11:
	case 12:

	case 13:
//		pObject = new BossMonster;
	}
	return nullptr;
}

void Monster::Info_Render() const
{
	LINE_UI;
	cout << "이름 : " << m_Status.szName << endl;
	cout << "체력 : " << m_Status.iHp << " / " << m_Status.iMaxHp << "레벨 : " << m_Status.iLv << endl;
	LINE_UI;

}

void Monster::Info_Render_Detail() const
{
}

bool Monster::Monster_Ai(Object* _pPlayer)
{
	int iMonsterAction = rand() % m_iActionCount;

	if (iMonsterAction == 0)
	{
		return m_pSkill[0]->Use_Skill(this, _pPlayer);
	}
	else if (iMonsterAction == m_iActionCount-1)
	{
		m_bGaurd = true;
		cout << m_Status.szName << "은(는) 방어태세를 갖췄다.";
		return false;
	}
	else
	{
		return m_pSkill[iMonsterAction-1]->Use_Skill(this, _pPlayer);
	}
}
