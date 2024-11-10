#include "pch.h"
#include "Field.h"
#include "Define.h"
#include "Common.h"
#include "Skill.h"
#include "StoreBase.h"
#include "Player.h"

#define RESET system("cls"); m_pPlayer->Info_Render(); m_pMonster->Info_Render()

Field::~Field()
{
	Release();
}

void Field::Initialize(Object* _pPlayer)
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

		//if (m_iFloor == 5)
			//BossBattle();
		cout << "========================================" << endl;
		cout << "지하 " << m_iFloor << "층" << endl;
		cout << "1. 앞으로 나아간다. 2. 돌아간다. : ";
		iSelect = Common::Get_Int();

		switch (iSelect)
		{
		case 1:
			Render_Walk();
			if (Percent(0))
				Battle(m_iFloor);
			else if (Percent(0))
				Item_Drop();
			else if (Percent(100))
				StoreBase::Store(m_pPlayer,m_iFloor);
			else if(Percent(10))
				Next_Floor();
			else
				Text_Render();
			continue;
		case 2:
			return;
		}
		// 배틀 (30%)
		// 아이템 획득 (10%)
		// 상점 등장 (10%)
		// 휴식처 등장 (10%)
		// 다음 층 등장 (10%)
		// 모두 걸리지 않으면 일반 텍스트 출력
		// 
		// 다음 층으로 이동할 시에 새로운 스킬을 획득 (3개중 하나 고르도록 하기)
	}
}

void Field::Release()
{
	m_pMonster = nullptr;
}

void Field::Render_Walk() const
{
	cout << "========================================" << endl;
	cout << m_pPlayer->Get_Status()->szName << "은(는) 앞으로 나아간다";
	for (int i = 0; i < 3; ++i)
	{
		_Thrd_sleep_for(200);
		cout << ".";
	}
	_Thrd_sleep_for(200);
	cout << endl;
}

void Field::Item_Drop()
{
	cout << "아이템이 떨어져있다." << endl;
	_Thrd_sleep_for(500); 

	Item* pItem = new Useable_Item;

	int iItemNum = rand() % 2 + Useable_Item::POTION1;
	cout << pItem->Get_Name(iItemNum) << "을 얻었다." << endl;
	dynamic_cast<Player*>(m_pPlayer)->Get_Bag_Useable()->Update(iItemNum,1);
	PAUSE;
	delete pItem;
}

void Field::Battle(const int _iMonNum)
{
	m_pMonster = new Monster;
	m_pMonster->Initialize(_iMonNum);
	cout << m_pMonster->Get_Status()->szName << "의 등장" << endl;
	PAUSE;
	Item* pItem;

	int iSelect(0), iSkillNum(0);
	while (true)
	{
		RESET;
		cout << "========================================" << endl;
		cout << "1. 공격 2.스킬 3. 아이템 4.도망 : ";
		iSelect = Common::Get_Int();
		cout << "========================================" << endl;
		switch (iSelect)
		{
		case 1:
			if (Spd_Cmp(m_pPlayer->Get_Status()->iSpeed, m_pMonster->Get_Status()->iSpeed)) // 플레이어가 더 빠를경우
			{
				if (Skill::Use_Skill(m_pPlayer,m_pMonster,Skill::NORMALATTACK))
				{
					Victory();
					return;
				}
				if (Skill::Use_Skill(m_pMonster, m_pPlayer, Monster_Ai()))
				{
					Lose();
					return;
				}
			}
			else
			{
				if (Skill::Use_Skill(m_pMonster, m_pPlayer, Monster_Ai()))
				{
					Lose();
					return;
				}
				if (Skill::Use_Skill(m_pPlayer,m_pMonster,Skill::NORMALATTACK))
				{
					Victory();
					return;
				}
			}
			PAUSE;
			break;
		case 2:
			iSkillNum = Skill_Select();
			if (0 == iSkillNum)
				continue;
			if (Spd_Cmp(m_pPlayer->Get_Status()->iSpeed, m_pMonster->Get_Status()->iSpeed)) // 플레이어가 더 빠를경우
			{
				if (Skill::Use_Skill(m_pPlayer, m_pMonster, iSkillNum))
				{
					Victory();
					return;
				}
				if (Skill::Use_Skill(m_pMonster, m_pPlayer, Monster_Ai()))
				{
					Lose();
					return;
				}
			}
			else
			{
				if (Skill::Use_Skill(m_pMonster, m_pPlayer, Monster_Ai()))
				{
					Lose();
					return;
				}
				if (Skill::Use_Skill(m_pPlayer, m_pMonster, iSkillNum))
				{
					Victory();
					return;
				}
			}
			PAUSE;
			break;

			break;
		case 3:
			pItem = new Useable_Item;
			if (pItem->Use_Item(m_pPlayer)) // 돌아가기 선택시 true return
				continue;
			cout << m_pMonster->Get_Status()->szName << "의 공격" << endl;
			DELAY;
			if (m_pPlayer->Damaged(m_pMonster->Get_Status()->iAtk))
			{
				Lose();
				return;
			}
			delete pItem;
			PAUSE;
			break;
		case 4:
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

int Field::Skill_Select()
{
	int iTmp(0);
	int iSelect(0);
	for (iTmp = 0; iTmp < MAX_SKILL_ABLE; ++iTmp)
		if (0 == m_pMonster->Get_Status()->iSkill[iTmp])
			break;
	iTmp--;
	while (true)
	{
		RESET;
		cout << "========================================" << endl;
		cout << "스킬을 선택해주세요." << endl;
		for (int i = 0; i < iTmp; ++i)
			cout << i + 1 << ". " << Skill::Get_Name(m_pPlayer->Get_Status()->iSkill[i]) << Skill::Get_Info(m_pPlayer->Get_Status()->iSkill[i]) << endl;
		cout << iTmp + 1 << ". 돌아가기" << endl;
		iSelect = Common::Get_Int();
		if (1 > iSelect || iTmp + 1 < iSelect)
			continue;
		else if (iTmp + 1 == iSelect)
			return 0;
		else
			return iSelect;
	}
}

int Field::Monster_Ai()
{
	int iTmp = 0;
	for (iTmp = 0; iTmp < MAX_SKILL_ABLE; ++iTmp)
		if (0 == m_pMonster->Get_Status()->iSkill[iTmp])
			break;
	iTmp = rand() % (iTmp);
	if (0 == iTmp)
		return 0;
	else
		return m_pMonster->Get_Status()->iSkill[iTmp-1];
}

void Field::Victory()
{
	cout << "승리" << endl;
	DELAY;
	dynamic_cast<Player*>(m_pPlayer)->Get_Bag_Other()->Gold_Cal(m_pMonster->Get_Gold());
	cout << m_pMonster->Get_Gold() << "골드를 얻었다." << endl;
	DELAY;
	m_pPlayer->Exp_Cal(m_pMonster->Get_Status()->iExp);
	cout << m_pMonster->Get_Status()->iExp << "경험치를 얻었다." << endl;
	DELAY;
	dynamic_cast<Player*>(m_pPlayer)->Get_Bag_Other()->Update(m_pMonster->Get_iDropItem(), 1);
	Item* pItem = new Other_Item;
	cout << pItem->Get_Name(m_pMonster->Get_iDropItem()) << "을 얻었다." << endl;
	delete pItem;
	DELAY;

	if (100 <= m_pPlayer->Get_Status()->iExp)
		m_pPlayer->LvUp();
	PAUSE;
}

void Field::Lose()
{
	cout << "패배" << endl;
	DELAY;
	dynamic_cast<Player*>(m_pPlayer)->Get_Bag_Other()->Gold_Cal(-m_pMonster->Get_Gold());
	cout << m_pMonster->Get_Gold() << "골드를 잃었다." << endl;
	DELAY;
	m_pPlayer->Exp_Cal(-m_pMonster->Get_Status()->iExp);
	cout << m_pMonster->Get_Status()->iExp << "경험치를 잃었다." << endl;
	m_pPlayer->Heal(100);
	PAUSE;
}

void Field::Next_Floor()
{
	while (true)
	{
		system("cls");
		m_pPlayer->Info_Render();

		cout << "다음층으로 가는 계단이다." << endl;
		cout << "1. 다음 층으로 이동 2. 현재 층을 더 탐색한다." << endl;
		int iSelect = Common::Get_Int();
		cout << "========================================" << endl;
		switch (iSelect)
		{
		case 1:
			cout << m_pPlayer->Get_Status()->szName << "은(는) 다음층으로 이동한다..." << endl;
			PAUSE;
			cout << "========================================" << endl;
			New_Skill();
			m_iFloor++;
			break;
		case 2:
			return;
		default:
			continue;
		}
	}
}

void Field::Text_Render()
{
	int iSelect = rand() % 5;

	switch (iSelect)
	{
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	default:
		cout << "텍스트 테스트" << endl;
 	}
	PAUSE;
}

void Field::New_Skill()
{
	int iSkill[MAX_SKILL] = {};
	int iCount(0);
	for (int i = 0; i < MAX_SKILL; ++i)
		iSkill[i] = i + 1;
	for (int i = 0; i < MAX_SKILL_ABLE; ++i)
	{
		if (0 != m_pPlayer->Get_Status()->iSkill[i])
		{
			iSkill[m_pPlayer->Get_Status()->iSkill[i] - 1] = 0;
			iCount++;
			for (int j = m_pPlayer->Get_Status()->iSkill[i] - 1; j < MAX_SKILL - 1; ++j)
				iSkill[j] = iSkill[j + 1];
		}
	}

	int* pSkill = new int[MAX_SKILL-1 - iCount];

	for (int i = 0; i < MAX_SKILL-1 - iCount; ++i)
		pSkill[i] = iSkill[i];

	for (int i = 0; i < 100; ++i)
		swap(pSkill[rand() % (MAX_SKILL-1 - iCount)], pSkill[rand() % (MAX_SKILL-1 - iCount)]);

	int iSelect;
	while (true)
	{
		CLEAN;
		cout << "새로운 스킬 개방!" << endl;
		cout << "획득할 스킬을 선택해주세요" << endl;
		cout << "========================================" << endl;
		for (int i = 0; i < 3; ++i)
			cout << i + 1 << ". " << Skill::Get_Name(pSkill[i]) << Skill::Get_Info(pSkill[i]) << endl;
		iSelect = Common::Get_Int();
		switch (iSelect)
		{
		case 1:
		case 2:
		case 3:
			m_pPlayer->Set_Skill(iCount, pSkill[iSelect]);
			cout << Skill::Get_Name(pSkill[iSelect]) << "을(를) 배웠다." << endl;
			SAFE_DELETE_ARRAY(pSkill);
			PAUSE;
			return;
		default:
			continue;
		}
	}
}