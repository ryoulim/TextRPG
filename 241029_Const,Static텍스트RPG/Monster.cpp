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
		memcpy_s(m_pStatus->szName, sizeof(m_pStatus->szName), &"�ʱ�", sizeof("�ʱ�"));
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
		memcpy_s(m_pStatus->szName, sizeof(m_pStatus->szName), &"�߱�", sizeof("�߱�"));
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
		memcpy_s(m_pStatus->szName, sizeof(m_pStatus->szName), &"���", sizeof("���"));
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
		cout << "���ܹ߻� void Monster::Initialize(const int _iMonNum)" << endl;
		return;
	}
}

void Monster::Info_Render()
{
	
	cout << "========================================" << endl;
	cout << "�̸� : " << m_pStatus->szName << '\t' << "���� : " << m_pStatus->iLv << endl;
	cout << "ü�� : " << m_pStatus->iHp << " / " << m_pStatus->iMaxHp << '\t' << "���ݷ� : " << m_pStatus->iAtk << endl;
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
	cout << m_pStatus->szName << "��(��)" << _iDamage << "�� ���ظ� �Ծ���." << endl;
	DELAY;
	if (bKillCheck)
	{
		cout << m_pStatus->szName << "��(��) ��������." << endl;
		DELAY;
	}
	return bKillCheck;
}

void Monster::Release()
{
	SAFE_DELETE(m_pStatus);
}
