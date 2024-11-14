#include "pch.h"
#include "Object.h"
#include "Define.h"

bool Object::Damaged(const int _iDamage)
{
	m_Status.iHp -= _iDamage;
	cout << m_Status.szName << "은(는) " << _iDamage << " 데미지를 입었다." << endl;
	DELAY(50);

	if (m_Status.iHp <= 0)
	{
		cout << m_Status.szName << "은(는) 쓰러졌다." << endl;
		DELAY(50);
		return true;
	}
	return false;
}

void Object::Heal(int _iForce, const bool _bMode)
{
	if (_bMode == false) // 상수연산
		m_Status.iHp += _iForce;
	else // 퍼센트연산
		m_Status.iHp += m_Status.iMaxHp * _iForce / 100;

	if (m_Status.iMaxHp < m_Status.iHp)
	{
		_iForce -= m_Status.iHp - m_Status.iMaxHp;
		m_Status.iHp = m_Status.iMaxHp;
	}

	cout << m_Status.szName << "의 체력이 " << _iForce << " 회복되었다." << endl;
}

void Object::Release()
{
	SAFE_DELETE_ARRAY(m_Status.pType);
	for(int i = 0; i < MAX_SKILL_ABLE + 1; ++i)
		SAFE_DELETE(m_pSkill[i]);
}
