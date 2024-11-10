#include "pch.h"
#include "Village.h"
#include "Define.h"
#include "Common.h"

#define RESET system("cls"); m_pPlayer->Info_Render()

Village::~Village()
{
	Release();
}

void Village::Initialize(Object* _pPlayer)
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
		cout << "1.사냥터 2.종료 : ";
		switch (Common::Get_Int())
		{
		case 1:
			return false;
		case 2:
			return true;
		default:
			continue;
		}
	}
}

void Village::Release()
{
	m_pPlayer = nullptr;
}
