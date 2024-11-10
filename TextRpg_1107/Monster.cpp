#include "pch.h"
#include "Monster.h"
#include "Define.h"

#include "Slime.h"
#include "Pixie.h"
#include "Demon.h"

Object* Monster::Create_Monster(const int _iFloor)
{
	Object* pObject = nullptr;
	int iMonNum = rand() % 3 + 1;
	// ���� ���� 3����
	switch ((_iFloor-1)*3 + iMonNum)
	{
	case 1:
		pObject = new Slime;
		break;
	case 2:
	case 3:

	case 4:
	case 5:
	case 6:

	case 7:
	case 8:
	case 9:

	case 10:
	case 11:
	case 12:

	case 13:
		pObject = new BossMonster;
	}
	return nullptr;
}

void Monster::Info_Render() const
{
	LINE_UI;
	cout << "�̸� : " << m_Status.szName << endl;
	cout << "ü�� : " << m_Status.iHp << " / " << m_Status.iMaxHp << "���� : " << m_Status.iLv << endl;
	LINE_UI;

}

void Monster::Info_Render_Detail() const
{
}
