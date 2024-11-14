#include "pch.h"
#include "MainGame.h"

void MainGame::Initialize()
{
	cout << "이름을 입력해주세요. : ";
	string strName;
	cin >> strName;

	int iClass(0);
	while (true)
	{
		system("cls");
		cout << "클래스를 선택해주세요. (1.전사 2.마법사 3.도적) : ";
		cin >> iClass;

		if (iClass > 0 || iClass < 4)
			break;
	}

	m_pPlayer = Object::Create_Player(&strName, iClass-1);
}

void MainGame::Update()
{
	Village vVillage(m_pPlayer);
	vVillage.Update();
}
