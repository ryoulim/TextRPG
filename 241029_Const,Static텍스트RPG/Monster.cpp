#include "pch.h"
#include "Monster.h"

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
		m_pStatus->iAtk = 3;
		m_pStatus->iLv = 1;
		m_pStatus->iExp = 10;
		m_pStatus->iSpeed = 5;
		m_iGold = 10;
		m_iDropItem = Item::ITEM1;
		break;
	case MONSTER2:
		memcpy_s(m_pStatus->szName, sizeof(m_pStatus->szName), &"중급", sizeof("중급"));
		m_pStatus->iMaxHp = 60;
		m_pStatus->iHp = 60;
		m_pStatus->iAtk = 6;
		m_pStatus->iLv = 2;
		m_pStatus->iExp = 20;
		m_pStatus->iSpeed = 10;
		m_iGold = 20;
		m_iDropItem = Item::ITEM2;
		break;
	case MONSTER3:
		memcpy_s(m_pStatus->szName, sizeof(m_pStatus->szName), &"고급", sizeof("고급"));
		m_pStatus->iMaxHp = 90;
		m_pStatus->iHp = 90;
		m_pStatus->iAtk = 9;
		m_pStatus->iLv = 3;
		m_pStatus->iExp = 30;
		m_pStatus->iSpeed = 15;
		m_iGold = 30;
		m_iDropItem = Item::ITEM3;
		break;
	default:
		cout << "예외발생 void Monster::Initialize(const int _iMonNum)" << endl;
		return;
	}
}

void Monster::Info_Render()
{
	
	cout << "========================================" << endl;
	cout << "이름 : " << m_pStatus->szName << '\t' << "레벨 : " << m_pStatus->iLv << endl;
	cout << "체력 : " << m_pStatus->iHp << " / " << m_pStatus->iMaxHp << '\t' << "공격력 : " << m_pStatus->iAtk << endl;
}

bool Monster::Damaged(int _iDamage)
{
	bool bKillCheck(false);
	m_pStatus->iHp -= _iDamage;
	if (0 >= m_pStatus->iHp)
	{
		_iDamage -= m_pStatus->iHp;
		bKillCheck = true;
	}
	cout << m_pStatus->szName << "은(는)" << _iDamage << "의 피해를 입었다." << endl;
	DELAY;
	if (bKillCheck)
	{
		cout << m_pStatus->szName << "은(는) 쓰러졌다." << endl;
		DELAY;
	}
	return bKillCheck;
}

void Monster::Release()
{
	SAFE_DELETE(m_pStatus);
}
