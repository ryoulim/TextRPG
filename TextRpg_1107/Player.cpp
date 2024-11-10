#include "pch.h"
#include "Player.h"
#include "Define.h"

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
