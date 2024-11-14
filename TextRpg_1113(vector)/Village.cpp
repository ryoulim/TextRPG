#include "pch.h"
#include "Village.h"
#include "Define.h"

#include "Dungeon.h"
#include "Store.h"

#include "Player.h"

void Village::Update()
{
	int iSelect(0);
	while (true)
	{
		system("cls");
		m_pPlayer->Info_Render();
		cout << "1.던전 2.상점 3.스테이터스 4.게임종료";
		cin >> iSelect;
		switch (iSelect)
		{
		case 1:
			Go_Dungeon();
			break;
		case 2:
			Go_Store();
			break;
		case 3:
			static_cast<Player*>(m_pPlayer)->View_Status();
			break;
		case 4:
			return;
		default:
			continue;
		}
	}
}

void Village::Go_Dungeon()
{
	Dungeon dDungeon(m_pPlayer);
	dDungeon.Update();
}

void Village::Go_Store()
{
	Store sStore(static_cast<Player*>(m_pPlayer)->Get_Inven());
	sStore.Initialize(rand() % 3);
	sStore.Update();
}



