#include "pch.h"
#include "Player.h"
#include "Define.h"
#include "Skill.h"

#define PTYPE(_NORMAL,_FIRE,_ICE,_THUNDER,_WIND,_LIGHT,_DARKNESS) \
pType[NORMAL] = (_NORMAL);\
pType[FIRE] = (_FIRE);\
pType[ICE] = (_ICE);\
pType[THUNDER] = (_THUNDER);\
pType[WIND] = (_WIND);\
pType[LIGHT] = (_LIGHT);\
pType[DARKNESS] = (_DARKNESS)

//typedef struct tagStatus
//{
//	char szName[32];
//	char szClass[12];
//	int iLv, iExp;
//	int iMaxHp, iHp;
//	int iMaxMp, iMp;
//	int iAtk, iM_Atk, iDef, iSpeed;
//	int iEffect;
//	int* pType;
//} Status;

Object* Player::Create_Player(const int _iClassNum, char _szName[])
{
	Object* pPlayer = nullptr;
	int* pType = new int[MAX_TYPE];

	switch (_iClassNum)
	{
	case WARRIOR:
		PTYPE(1, 2, 2, 2, 2, 2, 4);
		pPlayer = new Player(_szName, 200, 50, 150, 50, 50, 50, "����", pType);
		break;
	case MAGE:
		PTYPE(4, 1, 1, 1, 1, 2, 2);
		pPlayer = new Player(_szName, 50, 200, 50, 150, 50, 50, "������", pType);
		break;
	case THIEF:
		PTYPE(2, 2, 2, 2, 2, 4, 1);
		pPlayer = new Player(_szName, 100, 100, 100, 100, 50, 50, "����", pType);
		break;
	default:
		break;
	}

	pPlayer->Set_Skill(Skill::Create_Skill(Skill::ATTACK), 0);

	return pPlayer;
}

void Player::Info_Render() const
{
	LINE_UI;
	cout << "�̸� : " << m_Status.szName << "\t\t" << "Ŭ���� : " << m_Status.szClass << endl;
	cout << "ü�� : " << m_Status.iHp << " / " << m_Status.iMaxHp << "\t\t\t" << "���� : " << m_Status.iMp << " / " << m_Status.iMaxMp << endl;
	cout << "���� : " << m_Status.iLv << "\t\t" << "����ġ : " << m_Status.iExp << endl;
	LINE_UI;
}

void Player::Info_Render_Detail() const
{
	LINE_UI;
	cout << "�̸� : " << m_Status.szName << "\t\t" << "Ŭ���� : " << m_Status.szClass << endl;
	cout << "ü�� : " << m_Status.iHp << " / " << m_Status.iMaxHp << "\t\t\t" << "���� : " << m_Status.iMp << " / " << m_Status.iMaxMp << endl;
	cout << "���� : " << m_Status.iLv << "\t\t" << "����ġ : " << m_Status.iExp << endl;
	cout << "���ݷ� : " << m_Status.iAtk << " �������ݷ� : " << m_Status.iM_Atk << '\t' << "���� : " << m_Status.iDef << '\t' << "���ǵ� : " << m_Status.iSpeed << endl;
	LINE_UI;
}


int Player::Skill_Select()
{
	cout << "����� ��ų�� ����ּ���" << endl;
	int i(1);
	for (; i <= MAX_SKILL_ABLE; ++i)
	{
		if (m_pSkill[i] == nullptr)
			break;
		cout << i << ". " << m_pSkill[i]->Get_Name() << " : " << m_pSkill[i]->Get_Info() << endl;
	}
	cout << "0. ���ư���" << endl;
	--i;

	int iSelect(0);
	while (true)
	{
		cin >> iSelect;
		if (iSelect == 0)
			return 0;
		if (iSelect < 0 || iSelect > i)
		{
			cout << "�߸��� �Է��Դϴ�." << endl;
			continue;
		}
		else
			break;
	}
	return iSelect;
}

int Player::Item_Select()
{
	cout << "����� �������� ����ּ���" << endl;
	int i(0);
	for (; i < m_Inven[Item::USEABLE].Get_Length(); ++i)
	{
		cout << i+1 << ". " << m_Inven[Item::USEABLE].Get_Item(i)->Get_Name() << " : " << m_Inven[Item::USEABLE].Get_Item(i)->Get_Info() << endl;
	}
	cout << "0. ���ư���" << endl;

	int iSelect(0);
	while (true)
	{
		cin >> iSelect;
		if (iSelect == 0)
			return 0;
		if (iSelect < 0 || iSelect > i)
		{
			cout << "�߸��� �Է��Դϴ�." << endl;
			continue;
		}
		else
			break;
	}
	return iSelect;
}

void Player::Exp_Update(const int _Exp)
{
	m_Status.iExp += _Exp;
	if (m_Status.iExp < 0)
		m_Status.iExp = 0;
}

void Player::LvUp()
{
	cout << "���� ��!" << endl;
	DELAY(100);
	m_Status.iExp -= 100;
	m_Status.iLv++;

	m_Status.iMaxHp++;
	m_Status.iHp = m_Status.iMaxHp;
	m_Status.iMaxMp++;
	m_Status.iMp = m_Status.iMaxMp;
	m_Status.iAtk++;
	m_Status.iM_Atk++;
	m_Status.iDef++;
	m_Status.iSpeed++;
	cout << m_Status.szName << "�� �ɷ�ġ�� ����ߴ�." << endl;
}
