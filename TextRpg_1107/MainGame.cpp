#include "pch.h"
#include "MainGame.h"
#include "Player.h"

void MainGame::Initialize()
{
	cout << "이름을 입력해주세요(최대 15자)" << endl;
	char szName[32];
	cin >> szName;

	int iClass;
	while (true)
	{
		CLEAR;
		cout << "클래스를 선택해주세요(1.전사, 2.마법사 3.도적) : ";
		cin >> iClass;

		if (1 > iClass || 3 < iClass)
			continue;
		else
			break;
	}
	m_pPlayer = Player::Create_Player(iClass, szName);
}

void MainGame::Update()
{
	int iLocation(1); // 1 = 마을, 2 = 던전

	while (iLocation)
	{
		switch (iLocation)
		{
		case VILLAGE:
			m_pVillage = new Village(m_pPlayer);
			iLocation = m_pVillage->Update() + 1;
			SAFE_DELETE(m_pVillage);
		case DUNGEON:
			m_pDungeon = new Dungeon(m_pPlayer);
			m_pDungeon->Update();
			iLocation = VILLAGE;
			SAFE_DELETE(m_pDungeon);
		default:
			continue;
		}
	}
}

void MainGame::Release()
{
	SAFE_DELETE(m_pPlayer);
	SAFE_DELETE(m_pVillage);
	SAFE_DELETE(m_pDungeon);
}
