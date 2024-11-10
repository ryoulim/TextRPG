#include "pch.h"
#include "MainGame.h"
#include "Define.h"
#include "Common.h"

MainGame::~MainGame()
{
	Release();
}

void MainGame::Initialize()
{
	m_pPlayer = new Player;
	int iSelect(0);
	while (true)
	{
		CLEAN;
		cout << "������ �������ּ��� ( 1.���� 2. ������ 3. ���� ) : ";
		iSelect = Common::Get_Int() - 1;
		if (0 <= iSelect && Player::END > iSelect)
		{
			m_pPlayer->Initialize(iSelect);
			return;
		}
		else
			continue;
	}
}

void MainGame::Update()
{
	bool bLocation(true);
	while (true)
	{
		if (bLocation)
		{
			m_pVillage = new Village;
			m_pVillage->Initialize(m_pPlayer);
			if (m_pVillage->Update())
				return;
			bLocation = false;
		}
		else
		{
			m_pField = new Field;
			m_pField->Initialize(m_pPlayer);
			m_pField->Update();
			bLocation = true;
		}
	}
}

void MainGame::Release()
{
	SAFE_DELETE(m_pPlayer);
	SAFE_DELETE(m_pVillage);
	SAFE_DELETE(m_pField);
}
