#include "pch.h"
#include "Dungeon.h"
#include "Define.h"
#include "Store.h"

#include "Monster.h"

#include "Skill.h"
#include "Battle.h"

void Dungeon::Update()
{
	Enter();
	while (true)
	{
		CLEAR;
		m_pPlayer->Info_Render();
		if (m_iFloor == 5)
		{
			cout << "보스전 개발중" << endl;
			return;
		//	BossBattle;
		}
		cout << "지하 " << m_iFloor << "층" << endl;
		cout << "1. 앞으로 나아간다 2. 탐색을 종료한다." << endl;

		int iSelect(0);
		cin >> iSelect;
		switch (iSelect)
		{
		case 1:
			if (PERCENT(30))
				Battle::Meet_Battle(m_pPlayer,m_iFloor);
			else if (PERCENT(10))
				Item_Drop();
			else if (PERCENT(15))
				Store::Meet_Store(m_pPlayer, m_iFloor);
			else if (PERCENT(20))
				Next_Floor();
			else
				Text_Render();
		case 2:
			return;
		default:
			continue;
		}
	}
}

void Dungeon::Enter() const
{
	CLEAR;
	cout << "던전에 입장합니다";
	for (int i = 0; i < 3; ++i)
	{
		DELAY(400);
		cout << '.';
	}
	DELAY(400);
}

void Dungeon::Item_Drop()
{
	int iTmp = Item::BOMB - Item::POTION1;
	iTmp = Item::BOMB + rand() % iTmp;

	Item* pItem = Item::Create_Item(iTmp);
	cout << pItem->Get_Name() << "을(를) 획득했다." << endl;
	static_cast<Player*>(m_pPlayer)->Get_Inven(Item::USEABLE)->Add_Item(pItem, 1);
	SAFE_DELETE(pItem);
	PAUSE;
}

void Dungeon::Next_Floor()
{
	cout << "계단 발견 1.다음층으로 나아간다. 2. 현재층을 계속 탐색한다." << endl;
	int iSelect(0);
	while (true)
	{
		cin >> iSelect;

		if (iSelect == 2)
			return;
		else if (iSelect == 1)
		{
			m_iFloor++;
			New_Skill();
		}
		else
			cout << "잘못된 입력입니다." << endl;
	}
}

void Dungeon::Text_Render()
{
	cout << m_pPlayer->Get_Status()->szName << "은(는) 앞으로 나아간다" << endl;
	for (int i = 0; i < 3; ++i)
	{
		DELAY(200);
		cout << '.';
	}
	DELAY(200);
}

void Dungeon::New_Skill()
{
	int iSelect(0);

	int iSkillNum[MAX_SKILL_NUM];
	for (int i = 0; i < MAX_SKILL_NUM; ++i)
		iSkillNum[i] = i + 1;
	for (int i = 0; i < 100; ++i)
		swap(iSkillNum[rand() % MAX_SKILL_NUM], iSkillNum[rand() % MAX_SKILL_NUM]);

	Skill* pSkill[3];
	for (int i = 0; i < 3; ++i)
	{
		pSkill[i] = Skill::Create_Skill((Skill::SKILL_LIST)iSkillNum[i]);
	}

	while (true)
	{
		CLEAR;
		cout << "새로운 스킬 개방" << endl;
		DELAY(200);
		cout << "배울 스킬을 선택해주세요" << endl;
		
		for (int i = 0; i < 3; ++i)
		{
			cout << i+1 << ". " << pSkill[i]->Get_Name() << " : " << pSkill[i]->Get_Info();
		}
		cin >> iSelect; 
		if (iSelect < 1 || iSelect > 3)
			continue;
		else
		{
			for (int i = 1; i < MAX_SKILL_ABLE; ++i)
			{
				if (m_pPlayer->Get_Skill(i) == nullptr)
				{
					m_pPlayer->Set_Skill(pSkill[iSelect], i);
					break;
				}
			}
		}
		
	}
}
