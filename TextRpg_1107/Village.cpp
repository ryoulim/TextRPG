#include "pch.h"
#include "Village.h"
#include "Define.h"

int Village::Update()
{
	while (true)
	{
		CLEAR;
		m_pPlayer->Info_Render();
		cout << "1.�������� 2.���� : ";
		int iSelect(0);
		cin >> iSelect;

		switch (iSelect)
		{
		case 1:
			return true;
		case 2:
			return false;
		default:
			continue;
		}
	}
}
