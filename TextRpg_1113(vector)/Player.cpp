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
		cout << "�������� ���" << endl;
		m_pInventory->Equip_Render();
		cout << "===================================" << endl;
		cout << "1. ���ٲٱ� 2.���ư���" << endl;

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
	cout << "������ ��� ��ȣ�� �Է����ּ���. (9: �������, 0: ���)" << endl;
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
			cout << "�߸��� �Է��Դϴ�." << endl;
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
	cout << "�̸� : " << m_strName << "\t\t" << "Ŭ���� : " << Class_Name_Render() << endl;
	cout << "ü�� : " << m_iHp << " / " << m_iStatus[HP] << "\t" << "���ݷ� : " << m_iStatus[ATK] << endl;
	cout << "���� : " << m_iStatus[DEF] << "\t\t" << "���ǵ� : "  << m_iStatus[SPD] << endl;
}

const char* Player::Class_Name_Render() const
{
	switch (m_Class)
	{
	case WARRIOR:
		return "����";
	case MAGE:
		return "������";
	case THIEF:
		return "����";
	default:
		return "";
	}
}
