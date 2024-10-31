#include "pch.h"
#include "Village.h"
#include "Define.h"
#include "Common.h"

#define RESET system("cls"); m_pPlayer->Info_Render()

Village::~Village()
{
	Release();
}

void Village::Initialize(Player* _pPlayer)
{
	m_pPlayer = _pPlayer;
}

bool Village::Update()
{
	RESET;
	while (true)
	{
		system("cls");
		m_pPlayer->Info_Render();
		cout << "1. ����� 2. ���� 3. ���� : ";
		switch (Common::Get_Int())
		{
		case 1:
			return false;
		case 2:
			Store();
			continue;
		case 3:
			return true;
		default:
			continue;
		}
	}
}

void Village::Store()
{
	while (true)
	{
		system("cls");
		m_pPlayer->Get_Bag()->Gold_Render();
		cout << "1. ���� 2. �Ǹ� 3. ���ư���" << endl;
		switch (Common::Get_Int())
		{
		case 1:
			Store_Buy();
			continue;
		case 2:
			Store_Sell();
			continue;
		case 3:
			return;
		default:
			continue;
		}
	}
}

void Village::Store_Buy()
{
	int iSelect(0);
	while (true)
	{
		system("cls");
		cout << "������ �����Ͻðڽ��ϱ�?" << endl;
		m_pPlayer->Get_Bag()->Gold_Render();
		cout << "1. �Ϲ� ���� (ü�� 30 ȸ��) , 30 G" << endl;
		cout << "2. ��� ���� (ü�� 60 ȸ��) , 50 G" << endl;
		cout << "3. ���ư���" << endl;
		iSelect = Common::Get_Int();
		switch (iSelect)
		{
		case 1:
			if (30 > m_pPlayer->Get_Bag()->Get_Gold())
				cout << "��尡 �����մϴ�." << endl;
			else
			{
				m_pPlayer->Get_Bag()->Update(Item::POTION1, 1);
				m_pPlayer->Get_Bag()->Gold_Minus(30);
				cout << "�Ϲ� ���� ���ſϷ�" << endl;	
			}
			PAUSE;
			continue;
		case 2:
			if (50 > m_pPlayer->Get_Bag()->Get_Gold())
				cout << "��尡 �����մϴ�." << endl;
			else
			{
				m_pPlayer->Get_Bag()->Update(Item::POTION2, 1);
				m_pPlayer->Get_Bag()->Gold_Minus(50);
				cout << "��� ���� ���ſϷ�" << endl;
			}
			PAUSE;
			continue;
		case 3:
			return;
		default:
			continue;
		}
	}
}

void Village::Store_Sell()
{
	int iSelect(0), iKind(0);
	while (true)
	{
		iKind = m_pPlayer->Get_Bag()->Get_iKind();
		system("cls");
		cout << "������ �Ǹ��Ͻðڽ��ϱ�?" << endl;
		m_pPlayer->Get_Bag()->Info_Render();
		cout << iKind + 1 << " : ���ư���" << endl;
		iSelect = Common::Get_Int();

		if (1 > iSelect || iKind + 1 < iSelect)
			continue;
		else if (iKind + 1 == iSelect)
			return;

		m_pPlayer->Get_Bag()->Gold_Plus(m_pPlayer->Get_Bag()->Get_Item()[iSelect - 1].Get_ItemInfo()->iCost / 2);
		if (m_pPlayer->Get_Bag()->Get_Item()[iSelect-1].Count_Cal(-1))
			m_pPlayer->Get_Bag()->Delete_Null(iSelect-1);
	}
}

void Village::Release()
{
	m_pPlayer = nullptr;
}
