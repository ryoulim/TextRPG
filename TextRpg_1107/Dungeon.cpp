#include "pch.h"
#include "Dungeon.h"
#include "Define.h"
#include "Store.h"

void Dungeon::Update()
{
	Enter();
	while (true)
	{
		CLEAR;
		m_pPlayer->Info_Render();
		cout << "1. 앞으로 나아간다 2. 탐색을 종료한다." << endl;

		int iSelect(0);
		cin >> iSelect;
		switch (iSelect)
		{
		case 1:
			if (PERCENT(30))
				Battle();
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
