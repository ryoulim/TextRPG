#include "pch.h"
#include "Field.h"
#include "Define.h"
#include "Common.h"

#define RESET system("cls"); m_pPlayer->Info_Render(); m_pMonster->Info_Render()

Field::~Field()
{
	Release();
}

void Field::Initialize(Player* _pPlayer)
{
	m_pPlayer = _pPlayer;
}

void Field::Update()
{
	int iSelect(0);
	while (true)
	{
		system("cls");
		m_pPlayer->Info_Render();
		cout << "1.초급 2.중급 3.고급 4. 돌아가기 : ";
		iSelect = Common::Get_Int();
		switch (iSelect)
		{
		case Monster::MONSTER1:
		case Monster::MONSTER2:
		case Monster::MONSTER3:
			Battle(iSelect);
			SAFE_DELETE(m_pMonster);
			continue;
		case 4:
			return;
		default:
			continue;
		}
	}
}

void Field::Release()
{
	m_pMonster = nullptr;
}

void Field::Battle(const int _iMonNum)
{
	m_pMonster = new Monster;
	m_pMonster->Initialize(_iMonNum);

	while (true)
	{
		RESET;
		cout << "1. 공격 2. 아이템 3.도망 : ";
		switch (Common::Get_Int())
		{
		case 1:
			if (Spd_Cmp(m_pPlayer->Get_Status()->iSpeed, m_pMonster->Get_Status()->iSpeed)) // 플레이어가 더 빠를경우
			{
				cout << m_pPlayer->Get_Status()->szName << "의 공격" << endl;
				DELAY;
				if (m_pMonster->Damaged(m_pPlayer->Get_Status()->iAtk))
				{
					Victory();
					return;
				}
				cout << m_pMonster->Get_Status()->szName << "의 공격" << endl;
				DELAY;
				if (m_pPlayer->Damaged(m_pMonster->Get_Status()->iAtk))
				{
					Lose();
					return;
				}
			}
			else
			{
				cout << m_pMonster->Get_Status()->szName << "의 공격" << endl;
				DELAY;
				if (m_pPlayer->Damaged(m_pMonster->Get_Status()->iAtk))
				{
					Lose();
					return;
				}
				cout << m_pPlayer->Get_Status()->szName << "의 공격" << endl;
				DELAY;
				if (m_pMonster->Damaged(m_pPlayer->Get_Status()->iAtk))
				{
					Victory();
					return;
				}
			}
			PAUSE;
			break;
		case 2:
			Use_Item();
			break;
		case 3:
			return;
		default:
			continue;
		}
	}
}


bool Field::Spd_Cmp(const int _iPlayerSpd, const int _iMonsterSpd)
{
	if (_iPlayerSpd > _iMonsterSpd)
		return true;
	else if (_iPlayerSpd == _iMonsterSpd)
		return rand() % 2;
	else
		return false;
}

void Field::Victory()
{
	char szName[32] = {};

	cout << "승리" << endl;
	DELAY;
	m_pPlayer->Get_Bag()->Gold_Plus(m_pMonster->Get_Gold());
	cout << m_pMonster->Get_Gold() << "골드를 얻었다." << endl;
	DELAY;
	m_pPlayer->Exp_Plus(m_pMonster->Get_Status()->iExp);
	cout << m_pMonster->Get_Status()->iExp << "경험치를 얻었다." << endl;
	DELAY;
	m_pPlayer->Get_Bag()->Update(m_pMonster->Get_iDropItem(), 1);
	cout << Item::Name_Render(m_pMonster->Get_iDropItem()) << "을 얻었다." << endl;
	DELAY;

	if (100 <= m_pPlayer->Get_Status()->iExp)
		m_pPlayer->LvUp();
	PAUSE;
}

void Field::Lose()
{
	cout << "패배" << endl;
	DELAY;
	m_pPlayer->Get_Bag()->Gold_Minus(m_pMonster->Get_Gold());
	cout << m_pMonster->Get_Gold() << "골드를 잃었다." << endl;
	DELAY;
	m_pPlayer->Exp_Minus(m_pMonster->Get_Status()->iExp);
	cout << m_pMonster->Get_Status()->iExp << "경험치를 잃었다." << endl;
	m_pPlayer->Heal(100);
	PAUSE;
}

void Field::Use_Item()
{
	int iSelect(0);
	int iKind = m_pPlayer->Get_Bag()->Get_iKind();
	while (true)
	{
		system("cls");
		m_pPlayer->Info_Render();
		m_pMonster->Info_Render();
		m_pPlayer->Get_Bag()->Info_Render();
		cout << iKind + 1 << " : 돌아가기 " << endl;
		iSelect = Common::Get_Int();
		if (1 > iSelect || iKind + 1 < iSelect)
			continue;
		else if (iSelect == iKind + 1)
			return;
		if (m_pPlayer->Get_Bag()->Get_Item()[iSelect - 1].Get_ItemInfo()->iNumber == Item::POTION1)
		{
			m_pPlayer->Heal(30);
			if (m_pPlayer->Get_Bag()->Get_Item()[iSelect - 1].Count_Cal(-1))
				m_pPlayer->Get_Bag()->Delete_Null(iSelect - 1);
		}
		else if (m_pPlayer->Get_Bag()->Get_Item()[iSelect - 1].Get_ItemInfo()->iNumber == Item::POTION2)
		{
			m_pPlayer->Heal(50);
			if (m_pPlayer->Get_Bag()->Get_Item()[iSelect - 1].Count_Cal(-1))
				m_pPlayer->Get_Bag()->Delete_Null(iSelect - 1);
		}
		else
		{
			cout << "사용할 수 없는 아이템입니다." << endl;
			continue;
		}
		PAUSE;
		return;
	}
}
