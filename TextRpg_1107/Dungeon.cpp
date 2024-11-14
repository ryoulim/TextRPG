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
			cout << "������ ������" << endl;
			return;
		//	BossBattle;
		}
		cout << "���� " << m_iFloor << "��" << endl;
		cout << "1. ������ ���ư��� 2. Ž���� �����Ѵ�." << endl;

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
	cout << "������ �����մϴ�";
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
	cout << pItem->Get_Name() << "��(��) ȹ���ߴ�." << endl;
	static_cast<Player*>(m_pPlayer)->Get_Inven(Item::USEABLE)->Add_Item(pItem, 1);
	SAFE_DELETE(pItem);
	PAUSE;
}

void Dungeon::Next_Floor()
{
	cout << "��� �߰� 1.���������� ���ư���. 2. �������� ��� Ž���Ѵ�." << endl;
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
			cout << "�߸��� �Է��Դϴ�." << endl;
	}
}

void Dungeon::Text_Render()
{
	cout << m_pPlayer->Get_Status()->szName << "��(��) ������ ���ư���" << endl;
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
		cout << "���ο� ��ų ����" << endl;
		DELAY(200);
		cout << "��� ��ų�� �������ּ���" << endl;
		
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
