#include "pch.h"
#include "Player.h"
#include "Common.h"
#include "Skill.h"

Player::~Player()
{
	Release();
}

void Player::Initialize(const int _iClassNum)
{
	m_pStatus = new Status;
	switch (_iClassNum)
	{
	case WARRIOR:
		memcpy_s(m_pStatus->szName, sizeof(m_pStatus->szName), &"전사", sizeof("전사"));
		m_pStatus->iMaxHp = 100;
		m_pStatus->iHp = 100;
		m_pStatus->iMaxMp = 100;
		m_pStatus->iMp = 100;
		m_pStatus->iAtk = 10;
		m_pStatus->iLv = 1;
		m_pStatus->iExp = 0;
		m_pStatus->iType = Skill::NORMAL;
		m_pStatus->iSpeed = 10;
		break;
	case MAGE:
		memcpy_s(m_pStatus->szName, sizeof(m_pStatus->szName), &"마법사", sizeof("마법사"));
		m_pStatus->iMaxHp = 100;
		m_pStatus->iHp = 100;
		m_pStatus->iMaxMp = 100;
		m_pStatus->iMp = 100;
		m_pStatus->iAtk = 10;
		m_pStatus->iLv = 1;
		m_pStatus->iExp = 0;
		m_pStatus->iType = Skill::NORMAL;
		m_pStatus->iSpeed = 10;
		break;
	case THIEF:
		memcpy_s(m_pStatus->szName, sizeof(m_pStatus->szName), &"도적", sizeof("도적"));
		m_pStatus->iMaxHp = 100;
		m_pStatus->iHp = 100;
		m_pStatus->iMaxMp = 100;
		m_pStatus->iMp = 100;
		m_pStatus->iAtk = 10;
		m_pStatus->iLv = 1;
		m_pStatus->iExp = 0;
		m_pStatus->iType = Skill::NORMAL;
		m_pStatus->iSpeed = 10;
		break;
	default:
		cout << "예외발생 void Player::Initialize(const int _iClassNum)" << endl;
		return;
	}

	m_pBag_Equip = new Bag;
	m_pBag_Equip->Initialize(Bag::EQUIP);
	m_pBag_Useable = new Bag;
	m_pBag_Equip->Initialize(Bag::USEABLE);
	m_pBag_Other = new Bag;
	m_pBag_Equip->Initialize(Bag::OTHER);
}

void Player::Info_Render() const
{
	cout << "========================================" << endl;
	cout << "이름 : " << m_pStatus->szName << '\t' << "레벨 : " << m_pStatus->iLv << endl;
	cout << "체력 : " << m_pStatus->iHp << " / " << m_pStatus->iMaxHp << '\t' << "공격력 : " << m_pStatus->iAtk << endl;
	cout << "경험치 : " << m_pStatus->iExp << " / 100" << endl;
}

void Player::Exp_Cal(int _iTmp)
{
	m_pStatus->iExp += _iTmp;
	if (0 > m_pStatus->iExp)
		m_pStatus->iExp = 0;
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
	SAFE_DELETE(m_pBag_Equip);
	SAFE_DELETE(m_pBag_Useable);
	SAFE_DELETE(m_pBag_Other);
}
