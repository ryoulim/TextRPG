#include "pch.h"
#include "Battle.h"

#include "Player.h"
#include "Monster.h"
#include "Define.h"


void Battle::Meet_Battle(Object* _pPlayer, const int _iFloor)
{
	Object* pMonster = Monster::Create_Monster(_iFloor);
	Battle bBattle(_pPlayer, pMonster);
	bBattle.Update();
}

void Battle::Update()
{
	int iSelect(0);
	int iPlayerAction(0), iMonsterAction(0);

	while (true)
	{
		CLEAR;
		m_pPlayer->Info_Render();
		m_pMonster->Info_Render();
		cout << "1.°ø°Ý 2.½ºÅ³ 3.¾ÆÀÌÅÛ 4.°¡µå 5.µµ¸Á°£´Ù. :";
		cin >> iSelect;
		switch (iSelect)
		{
		case 1:
		case 2:
			if (iSelect != 1)
				iPlayerAction = static_cast<Player*>(m_pPlayer)->Skill_Select();
			if (iPlayerAction == 0)
				continue;
			if (SpdCmp())
			{
				if (m_pPlayer->Get_Skill(iPlayerAction)->Use_Skill(m_pPlayer, m_pMonster))
				{
					Victory();
					return;
				}
				if (static_cast<Monster*>(m_pMonster)->Monster_Ai(m_pPlayer))
				{
					Lose();
					return;
				}
			}
			else
			{
				if (static_cast<Monster*>(m_pMonster)->Monster_Ai(m_pPlayer))
				{
					Lose();
					return;
				}
				if (m_pPlayer->Get_Skill(iPlayerAction)->Use_Skill(m_pPlayer, m_pMonster))
				{
					Victory();
					return;
				}
			}
			break;
		case 3:
			iPlayerAction = static_cast<Player*>(m_pPlayer)->Item_Select();
			if (iPlayerAction == 0)
				continue;
			else
				iPlayerAction--;
			static_cast<Player*>(m_pPlayer)->Get_Inven(Item::USEABLE)->Get_Item(iPlayerAction)->Use_Item(m_pPlayer);
			if (m_pMonster->Get_Status()->iHp < 0)
			{
				Victory();
				return;
			}
			if (static_cast<Monster*>(m_pMonster)->Monster_Ai(m_pPlayer))
			{
				Lose();
				return;
			}
			break;
		case 4:
			m_pPlayer->Set_Gaurd(true);
			if (static_cast<Monster*>(m_pMonster)->Monster_Ai(m_pPlayer))
			{
				Lose();
				return;
			}
			break;
		case 5:
			return;
		default:
			continue;
		}
	}

	// °¡µå ÇØÁ¦
	m_pPlayer->Set_Gaurd(false);
	m_pMonster->Set_Gaurd(false);
	// ÀÌÆåÆ® °è»ê
	
	// ½ºÅ×ÀÌÅÍ½º °è»ê
}

bool Battle::SpdCmp()
{
	bool bReturn(false);
	if (m_pPlayer->Get_Status()->iSpeed > m_pMonster->Get_Status()->iSpeed)
		bReturn = true;
	else if (m_pPlayer->Get_Status()->iSpeed == m_pMonster->Get_Status()->iSpeed)
		bReturn = rand() % 2;
	else
		bReturn = false;

	return bReturn;
}

void Battle::Victory()
{
	cout << "½Â¸®" << endl;
	DELAY(100);

	static_cast<Player*>(m_pPlayer)->Exp_Update(m_pMonster->Get_Status()->iExp);
	cout << m_pMonster->Get_Status()->iExp << " °æÇèÄ¡ È¹µæ" << endl;
	DELAY(50);

	static_cast<Player*>(m_pPlayer)->Get_Inven(Item::OTHER)->m_iPlayerGold += static_cast<Monster*>(m_pMonster)->Get_DropGold();
	cout << static_cast<Monster*>(m_pMonster)->Get_DropGold() << " °ñµå È¹µæ" << endl;
	DELAY(50);

	if (PERCENT(50))
	{
		static_cast<Player*>(m_pPlayer)->Get_Inven(Item::OTHER)->Add_Item(static_cast<Monster*>(m_pMonster)->Get_DropItemNum(), 1);
		cout << static_cast<Monster*>(m_pMonster)->Get_DropItemNum() << " È¹µæ" << endl;
		DELAY(50);
	}

	if (m_pPlayer->Get_Status()->iExp >= 100)
		m_pPlayer->LvUp();
}

void Battle::Lose()
{
	cout << "ÆÐ¹è" << endl;
	DELAY(100);

	static_cast<Player*>(m_pPlayer)->Exp_Update(-m_pMonster->Get_Status()->iExp);
	cout << m_pMonster->Get_Status()->iExp << " °æÇèÄ¡¸¦ ÀÒ¾ú´Ù." << endl;
	DELAY(50);

	static_cast<Player*>(m_pPlayer)->Get_Inven(Item::OTHER)->m_iPlayerGold -= static_cast<Monster*>(m_pMonster)->Get_DropGold();
	if (static_cast<Player*>(m_pPlayer)->Get_Inven(Item::OTHER)->m_iPlayerGold < 0)
		static_cast<Player*>(m_pPlayer)->Get_Inven(Item::OTHER)->m_iPlayerGold == 0;
	cout << static_cast<Monster*>(m_pMonster)->Get_DropGold() << " °ñµå¸¦ ÀÒ¾ú´Ù." << endl;
	DELAY(50);
}
