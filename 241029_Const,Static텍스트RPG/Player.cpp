#include "pch.h"
#include "Player.h"

Player::Player()
{
	m_pStatus = nullptr;
	m_pBag = nullptr;
}

Player::~Player()
{
	Release();
}

void Player::Initialize(const int _iClassNum)
{
	m_pStatus = new Status;
	switch (_iClassNum-1)
	{
	case WARRIOR:
		memcpy_s(m_pStatus->szName, sizeof(m_pStatus->szName), &"����", sizeof("����"));
		m_pStatus->iMaxHp = 100;
		m_pStatus->iHp = 100;
		m_pStatus->iAtk = 10;
		m_pStatus->iLv = 1;
		m_pStatus->iExp = 0;
		m_pStatus->iSpeed = 10;
		break;
	case MAGE:
		memcpy_s(m_pStatus->szName, sizeof(m_pStatus->szName), &"������", sizeof("������"));
		m_pStatus->iMaxHp = 100;
		m_pStatus->iHp = 100;
		m_pStatus->iAtk = 10;
		m_pStatus->iLv = 1;
		m_pStatus->iExp = 0;
		m_pStatus->iSpeed = 10;
		break;
	case THIEF:
		memcpy_s(m_pStatus->szName, sizeof(m_pStatus->szName), &"����", sizeof("����"));
		m_pStatus->iMaxHp = 100;
		m_pStatus->iHp = 100;
		m_pStatus->iAtk = 10;
		m_pStatus->iLv = 1;
		m_pStatus->iExp = 0;
		m_pStatus->iSpeed = 10;
		break;
	default:
		cout << "���ܹ߻� void Player::Initialize(const int _iClassNum)" << endl;
		return;
	}

	m_pBag = new Bag;
}

void Player::Info_Render()
{
	cout << "========================================" << endl;
	cout << "�̸� : " << m_pStatus->szName << '\t' << "���� : " << m_pStatus->iLv << endl;
	cout << "ü�� : " << m_pStatus->iHp << " / " << m_pStatus->iMaxHp << '\t' << "���ݷ� : " << m_pStatus->iAtk << endl;
	cout << "����ġ : " << m_pStatus->iExp << " / 100" << endl;
}

bool Player::Damaged(int _iDamage)
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


void Player::Exp_Minus(int _iMinus)
{
	m_pStatus->iExp -= _iMinus;
	if (0 > m_pStatus->iExp)
		m_pStatus->iExp = 0;
}

void Player::Heal(int _iForce)
{
	m_pStatus->iHp += _iForce;
	if (m_pStatus->iHp >= m_pStatus->iMaxHp)
	{
		_iForce -= m_pStatus->iHp - m_pStatus->iMaxHp;
		m_pStatus->iHp = m_pStatus->iMaxHp;

	}
	cout << m_pStatus->szName << "�� ü���� " << _iForce << "ȸ���Ǿ���." << endl;
}

void Player::LvUp()
{
	m_pStatus->iLv++;
	m_pStatus->iExp -= 100;
	cout << "���� ��!" << endl;
	DELAY;

	m_pStatus->iMaxHp++;
	m_pStatus->iHp = m_pStatus->iMaxHp;
	m_pStatus->iAtk++;
	m_pStatus->iSpeed++;
}

void Player::Release()
{
	SAFE_DELETE(m_pStatus);
	SAFE_DELETE(m_pBag)
}
