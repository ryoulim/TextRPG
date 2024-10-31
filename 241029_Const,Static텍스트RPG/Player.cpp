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
		memcpy_s(m_pStatus->szName, sizeof(m_pStatus->szName), &"전사", sizeof("전사"));
		m_pStatus->iMaxHp = 100;
		m_pStatus->iHp = 100;
		m_pStatus->iAtk = 10;
		m_pStatus->iLv = 1;
		m_pStatus->iExp = 0;
		m_pStatus->iSpeed = 10;
		break;
	case MAGE:
		memcpy_s(m_pStatus->szName, sizeof(m_pStatus->szName), &"마법사", sizeof("마법사"));
		m_pStatus->iMaxHp = 100;
		m_pStatus->iHp = 100;
		m_pStatus->iAtk = 10;
		m_pStatus->iLv = 1;
		m_pStatus->iExp = 0;
		m_pStatus->iSpeed = 10;
		break;
	case THIEF:
		memcpy_s(m_pStatus->szName, sizeof(m_pStatus->szName), &"도적", sizeof("도적"));
		m_pStatus->iMaxHp = 100;
		m_pStatus->iHp = 100;
		m_pStatus->iAtk = 10;
		m_pStatus->iLv = 1;
		m_pStatus->iExp = 0;
		m_pStatus->iSpeed = 10;
		break;
	default:
		cout << "예외발생 void Player::Initialize(const int _iClassNum)" << endl;
		return;
	}

	m_pBag = new Bag;
}

void Player::Info_Render()
{
	cout << "========================================" << endl;
	cout << "이름 : " << m_pStatus->szName << '\t' << "레벨 : " << m_pStatus->iLv << endl;
	cout << "체력 : " << m_pStatus->iHp << " / " << m_pStatus->iMaxHp << '\t' << "공격력 : " << m_pStatus->iAtk << endl;
	cout << "경험치 : " << m_pStatus->iExp << " / 100" << endl;
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
	cout << m_pStatus->szName << "은(는)" << _iDamage << "의 피해를 입었다." << endl;
	DELAY;
	if (bKillCheck)
	{
		cout << m_pStatus->szName << "은(는) 쓰러졌다." << endl;
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
	cout << m_pStatus->szName << "의 체력이 " << _iForce << "회복되었다." << endl;
}

void Player::LvUp()
{
	m_pStatus->iLv++;
	m_pStatus->iExp -= 100;
	cout << "레벨 업!" << endl;
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
