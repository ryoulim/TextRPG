#include "pch.h"
#include "Monster.h"
#include "Skill.h"
#include "Other_Item.h"


Monster::~Monster()
{
	Release();
}

void Monster::Initialize(const int _iMonNum)
{
	m_pStatus = new Status;
	switch (_iMonNum)
	{
	case MONSTER1:
		memcpy_s(m_pStatus->szName, sizeof(m_pStatus->szName), &"초급", sizeof("초급"));
		m_pStatus->iMaxHp = 30;
		m_pStatus->iHp = 30;
		m_pStatus->iMaxMp = 30;
		m_pStatus->iMp = 30;
		m_pStatus->iAtk = 3;
		m_pStatus->iLv = 1;
		m_pStatus->iExp = 10;
		m_pStatus->iSpeed = 5;
		m_pStatus->iType = Skill::FIRE;
		m_pStatus->iSkill[0] = Skill::FIRESHOT;
		m_iGold = 10;
		m_iDropItem = Other_Item::MONITEM1;
		break;
	case MONSTER2:
		memcpy_s(m_pStatus->szName, sizeof(m_pStatus->szName), &"중급", sizeof("중급"));
		m_pStatus->iMaxHp = 60;
		m_pStatus->iHp = 60;
		m_pStatus->iMaxMp = 60;
		m_pStatus->iMp = 60;
		m_pStatus->iAtk = 6;
		m_pStatus->iLv = 2;
		m_pStatus->iExp = 20;
		m_pStatus->iSpeed = 10;
		m_pStatus->iType = Skill::WATER;
		m_pStatus->iSkill[0] = Skill::WATERSHOT;
		m_iGold = 20;
		m_iDropItem = Other_Item::MONITEM2;
		break;
	case MONSTER3:
		memcpy_s(m_pStatus->szName, sizeof(m_pStatus->szName), &"고급", sizeof("고급"));
		m_pStatus->iMaxHp = 90;
		m_pStatus->iHp = 90;
		m_pStatus->iMaxMp = 90;
		m_pStatus->iMp = 90;
		m_pStatus->iAtk = 9;
		m_pStatus->iLv = 3;
		m_pStatus->iExp = 30;
		m_pStatus->iSpeed = 15;
		m_pStatus->iType = Skill::GRASS;
		m_pStatus->iSkill[0] = Skill::GRASSSHOT;
		m_iGold = 30;
		m_iDropItem = Other_Item::MONITEM3;
		break;
	default:
		cout << "예외발생 void Monster::Initialize(const int _iMonNum)" << endl;
		return;
	}
}

void Monster::Info_Render() const
{
	
	cout << "========================================" << endl;
	cout << "이름 : " << m_pStatus->szName << '\t' << "레벨 : " << m_pStatus->iLv << endl;
	cout << "체력 : " << m_pStatus->iHp << " / " << m_pStatus->iMaxHp << '\t' << "공격력 : " << m_pStatus->iAtk << endl;
}

void Monster::Release()
{
	SAFE_DELETE(m_pStatus);
}
