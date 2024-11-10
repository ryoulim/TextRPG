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
		cout << "���� " << m_iFloor << "��" << endl;
		cout << "1. ������ ���ư���. 2. ���ư���. : ";
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
		// ��Ʋ (30%)
		// ������ ȹ�� (10%)
		// ���� ���� (10%)
		// �޽�ó ���� (10%)
		// ���� �� ���� (10%)
		// ��� �ɸ��� ������ �Ϲ� �ؽ�Ʈ ���
		// 
		// ���� ������ �̵��� �ÿ� ���ο� ��ų�� ȹ�� (3���� �ϳ� ������ �ϱ�)
	}
}

void Field::Release()
{
	m_pMonster = nullptr;
}

void Field::Render_Walk() const
{
	cout << "========================================" << endl;
	cout << m_pPlayer->Get_Status()->szName << "��(��) ������ ���ư���";
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
	cout << "�������� �������ִ�." << endl;
	_Thrd_sleep_for(500); 

	Item* pItem = new Useable_Item;

	int iItemNum = rand() % 2 + Useable_Item::POTION1;
	cout << pItem->Get_Name(iItemNum) << "�� �����." << endl;
	dynamic_cast<Player*>(m_pPlayer)->Get_Bag_Useable()->Update(iItemNum,1);
	PAUSE;
	delete pItem;
}

void Field::Battle(const int _iMonNum)
{
	m_pMonster = new Monster;
	m_pMonster->Initialize(_iMonNum);
	cout << m_pMonster->Get_Status()->szName << "�� ����" << endl;
	PAUSE;
	Item* pItem;

	int iSelect(0), iSkillNum(0);
	while (true)
	{
		RESET;
		cout << "========================================" << endl;
		cout << "1. ���� 2.��ų 3. ������ 4.���� : ";
		iSelect = Common::Get_Int();
		cout << "========================================" << endl;
		switch (iSelect)
		{
		case 1:
			if (Spd_Cmp(m_pPlayer->Get_Status()->iSpeed, m_pMonster->Get_Status()->iSpeed)) // �÷��̾ �� �������
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
			if (Spd_Cmp(m_pPlayer->Get_Status()->iSpeed, m_pMonster->Get_Status()->iSpeed)) // �÷��̾ �� �������
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
			if (pItem->Use_Item(m_pPlayer)) // ���ư��� ���ý� true return
				continue;
			cout << m_pMonster->Get_Status()->szName << "�� ����" << endl;
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
		cout << "��ų�� �������ּ���." << endl;
		for (int i = 0; i < iTmp; ++i)
			cout << i + 1 << ". " << Skill::Get_Name(m_pPlayer->Get_Status()->iSkill[i]) << Skill::Get_Info(m_pPlayer->Get_Status()->iSkill[i]) << endl;
		cout << iTmp + 1 << ". ���ư���" << endl;
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
	cout << "�¸�" << endl;
	DELAY;
	dynamic_cast<Player*>(m_pPlayer)->Get_Bag_Other()->Gold_Cal(m_pMonster->Get_Gold());
	cout << m_pMonster->Get_Gold() << "��带 �����." << endl;
	DELAY;
	m_pPlayer->Exp_Cal(m_pMonster->Get_Status()->iExp);
	cout << m_pMonster->Get_Status()->iExp << "����ġ�� �����." << endl;
	DELAY;
	dynamic_cast<Player*>(m_pPlayer)->Get_Bag_Other()->Update(m_pMonster->Get_iDropItem(), 1);
	Item* pItem = new Other_Item;
	cout << pItem->Get_Name(m_pMonster->Get_iDropItem()) << "�� �����." << endl;
	delete pItem;
	DELAY;

	if (100 <= m_pPlayer->Get_Status()->iExp)
		m_pPlayer->LvUp();
	PAUSE;
}

void Field::Lose()
{
	cout << "�й�" << endl;
	DELAY;
	dynamic_cast<Player*>(m_pPlayer)->Get_Bag_Other()->Gold_Cal(-m_pMonster->Get_Gold());
	cout << m_pMonster->Get_Gold() << "��带 �Ҿ���." << endl;
	DELAY;
	m_pPlayer->Exp_Cal(-m_pMonster->Get_Status()->iExp);
	cout << m_pMonster->Get_Status()->iExp << "����ġ�� �Ҿ���." << endl;
	m_pPlayer->Heal(100);
	PAUSE;
}

void Field::Next_Floor()
{
	while (true)
	{
		system("cls");
		m_pPlayer->Info_Render();

		cout << "���������� ���� ����̴�." << endl;
		cout << "1. ���� ������ �̵� 2. ���� ���� �� Ž���Ѵ�." << endl;
		int iSelect = Common::Get_Int();
		cout << "========================================" << endl;
		switch (iSelect)
		{
		case 1:
			cout << m_pPlayer->Get_Status()->szName << "��(��) ���������� �̵��Ѵ�..." << endl;
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
		cout << "�ؽ�Ʈ �׽�Ʈ" << endl;
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
		cout << "���ο� ��ų ����!" << endl;
		cout << "ȹ���� ��ų�� �������ּ���" << endl;
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
			cout << Skill::Get_Name(pSkill[iSelect]) << "��(��) �����." << endl;
			SAFE_DELETE_ARRAY(pSkill);
			PAUSE;
			return;
		default:
			continue;
		}
	}
}