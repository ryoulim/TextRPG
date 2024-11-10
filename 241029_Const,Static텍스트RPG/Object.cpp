#include "pch.h"
#include "Object.h"

Object::~Object()
{
	Release();
}

void Object::Heal(int _iForce)
{
	m_pStatus->iHp += _iForce;
	if (m_pStatus->iHp >= m_pStatus->iMaxHp)
	{
		_iForce -= m_pStatus->iHp - m_pStatus->iMaxHp;
		m_pStatus->iHp = m_pStatus->iMaxHp;

	}
	cout << m_pStatus->szName << "의 체력이 " << _iForce << "회복되었다." << endl;
	DELAY;
}

bool Object::Damaged(int _iDamage)
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

void Object::Release()
{
	SAFE_DELETE(m_pStatus);
}
