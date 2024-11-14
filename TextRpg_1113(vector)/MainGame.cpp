#include "pch.h"
#include "MainGame.h"

void MainGame::Initialize()
{
	cout << "�̸��� �Է����ּ���. : ";
	string strName;
	cin >> strName;

	int iClass(0);
	while (true)
	{
		system("cls");
		cout << "Ŭ������ �������ּ���. (1.���� 2.������ 3.����) : ";
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
