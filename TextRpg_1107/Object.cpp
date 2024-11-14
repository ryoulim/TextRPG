#include "pch.h"
#include "Object.h"
#include "Define.h"

bool Object::Damaged(const int _iDamage)
{
	m_Status.iHp -= _iDamage;
	cout << m_Status.szName << "��(��) " << _iDamage << " �������� �Ծ���." << endl;
	DELAY(50);

	if (m_Status.iHp <= 0)
	{
		cout << m_Status.szName << "��(��) ��������." << endl;
		DELAY(50);
		return true;
	}
	return false;
}

void Object::Heal(int _iForce, const bool _bMode)
{
	if (_bMode == false) // �������
		m_Status.iHp += _iForce;
	else // �ۼ�Ʈ����
		m_Status.iHp += m_Status.iMaxHp * _iForce / 100;

	if (m_Status.iMaxHp < m_Status.iHp)
	{
		_iForce -= m_Status.iHp - m_Status.iMaxHp;
		m_Status.iHp = m_Status.iMaxHp;
	}

	cout << m_Status.szName << "�� ü���� " << _iForce << " ȸ���Ǿ���." << endl;
}

void Object::Release()
{
	SAFE_DELETE_ARRAY(m_Status.pType);
	for(int i = 0; i < MAX_SKILL_ABLE + 1; ++i)
		SAFE_DELETE(m_pSkill[i]);
}
