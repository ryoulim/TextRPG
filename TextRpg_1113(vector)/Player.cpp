#include "pch.h"
#include "Player.h"

void Player::View_Status()
{
	int iSelect(0);
	while (true)
	{
		system("cls");
		Info_Render();
		cout << "===================================" << endl;
		cout << "착용중인 장비" << endl;
		m_pInventory->Equip_Render();
		cout << "===================================" << endl;
		cout << "1. 장비바꾸기 2.돌아가기" << endl;

		cin >> iSelect;
		switch (iSelect)
		{
		case 1:
			Equip_Change();
			break;
		case 2:
			return;
		default:
			continue;
		}
	}
}

void Player::Equip_Change()
{
	cout << "===================================" << endl;
	cout << "착용할 장비 번호를 입력해주세요. (9: 장비해제, 0: 취소)" << endl;
	for (int i = 0; i < m_pInventory->Get_Size(); ++i)
		m_pInventory->Item_Render(i);

	while (true)
	{
		int iSelect(0);
		cin >> iSelect;
		if (iSelect == 0)
			return;
		else if ((iSelect != 9) && (iSelect < 0 || iSelect > m_pInventory->Get_Size()))
		{
			cout << "잘못된 입력입니다." << endl;
			continue;
		}
		else
		{
			m_pInventory->Equip_Itemp(iSelect - 1, this);
			return;
		}
	}
}

void Player::Info_Render()
{
	cout << "===================================" << endl;
	cout << "이름 : " << m_strName << "\t\t" << "클래스 : " << Class_Name_Render() << endl;
	cout << "체력 : " << m_iHp << " / " << m_iStatus[HP] << "\t" << "공격력 : " << m_iStatus[ATK] << endl;
	cout << "방어력 : " << m_iStatus[DEF] << "\t\t" << "스피드 : "  << m_iStatus[SPD] << endl;
}

const char* Player::Class_Name_Render() const
{
	switch (m_Class)
	{
	case WARRIOR:
		return "전사";
	case MAGE:
		return "마법사";
	case THIEF:
		return "도적";
	default:
		return "";
	}
}
