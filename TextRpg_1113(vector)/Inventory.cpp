#include "pch.h"
#include "Inventory.h"
#include "Define.h"

#include "Player.h"

void Inventory::Initialize()
{
	m_vecInven_ItemP.reserve(5);
	m_vecEquip_ItemP.reserve(4);

	for (int i = 0; i < m_vecEquip_ItemP.capacity(); ++i)
	{
		m_vecEquip_ItemP.push_back(nullptr);
	}
}

bool Inventory::Add_Item(const int _iItemNum)
{
	if (m_vecInven_ItemP.size() == MAX_INVEN_ITEM)
	{
		cout << "�κ��丮�� ����á���ϴ�." << endl;
		return false;
	}
	else
	{
		m_vecInven_ItemP.push_back(Equip_Item::Create_Equip_Item(_iItemNum));
		return true;
	}
}

bool Inventory::Add_Item(Equip_Item* _pItem)
{
	if (m_vecInven_ItemP.size() == MAX_INVEN_ITEM)
	{
		cout << "�κ��丮�� ����á���ϴ�." << endl;
		return false;
	}
	else
	{
		m_vecInven_ItemP.push_back(new Equip_Item(*_pItem));
		return true;
	}
}

bool Inventory::Delete_Item(const int _iIndex)
{
	if (m_vecEquip_ItemP.size() == 0)
	{
		cout << "�κ��丮�� ����ֽ��ϴ�." << endl;
		return false;
	}
	else
	{
		vector<Equip_Item*>::iterator Iter = m_vecInven_ItemP.begin() + _iIndex;
		Safe_Delete<Equip_Item*>(*Iter);
		Iter = m_vecInven_ItemP.erase(Iter);
		return true;
	}
}

bool Inventory::Equip_Itemp(const int _iIndex, Object* _pPlayer)
{	
	if (_iIndex == 8) // �������
	{
		cout << "==========================" << endl;
		cout << "������ ��� �������ּ���" << endl;
		cout << "(1. ����, 2.����, 3.��, 4.�Ź�)" << endl;
		int iSelect(0);
		while (true)
		{
			cin >> iSelect;
			if (iSelect < 1 || iSelect > 4 || m_vecEquip_ItemP[iSelect-1] == nullptr)
				cout << "�߸��� �Է��Դϴ�." << endl;
			else
			{
				if (m_vecInven_ItemP.size() == MAX_INVEN_ITEM)
				{
					cout << "�κ��丮�� ����á���ϴ�." << endl;
					return false;
				}
				else
				{
					m_vecInven_ItemP.push_back(m_vecEquip_ItemP[iSelect - 1]);
					_pPlayer->Set_Status(m_vecEquip_ItemP[iSelect - 1]->Get_Status_Id(), - m_vecEquip_ItemP[iSelect - 1]->Get_Stuats_Val());
					m_vecEquip_ItemP[iSelect - 1] = nullptr;
					cout << "�����Ϸ�" << endl;
					system("pause");
					return true;
				}
			}
		}
	}

	int iType = m_vecInven_ItemP[_iIndex]->Get_Type();
	int iEquipIndex(0);
	int iClass = static_cast<Player*>(_pPlayer)->Get_Class();

	if ((iType == Equip_Item::SWORD && iClass != Player::WARRIOR) ||
		(iType == Equip_Item::STAFF && iClass != Player::MAGE) ||
		(iType == Equip_Item::DAGGER && iClass != Player::THIEF))
	{
		cout << "Ŭ������ ������ ���Ⱑ �ƴմϴ�." << endl;
		system("pause");
		return false;
	}
	else
	{
		switch (iType)
		{
		case Equip_Item::SWORD:
		case Equip_Item::STAFF:
		case Equip_Item::DAGGER:
			iEquipIndex = 0;
			break;
		case Equip_Item::HAT:
		case Equip_Item::CLOTHES:
		case Equip_Item::SHOES:
			iEquipIndex = iType - 2;
			break;
		}

		if (m_vecEquip_ItemP[iEquipIndex] == nullptr) // �������...�������ͽ��� ���ϱ⸸�Ѵ�.
		{
			_pPlayer->Set_Status(m_vecInven_ItemP[_iIndex]->Get_Status_Id(), m_vecInven_ItemP[_iIndex]->Get_Stuats_Val());
			m_vecEquip_ItemP[iEquipIndex] = m_vecInven_ItemP[_iIndex];
			vector<Equip_Item*>::iterator Iter = m_vecInven_ItemP.begin() + _iIndex;
			m_vecInven_ItemP.erase(Iter);
		}
		else // �̹� �������� ���Ⱑ ������.. �������ͽ� ���� ���ϰ�
		{
			_pPlayer->Set_Status(m_vecEquip_ItemP[iEquipIndex]->Get_Status_Id(), -m_vecEquip_ItemP[iEquipIndex]->Get_Stuats_Val());
			_pPlayer->Set_Status(m_vecInven_ItemP[_iIndex]->Get_Status_Id(), m_vecInven_ItemP[_iIndex]->Get_Stuats_Val());
			swap(m_vecEquip_ItemP[iEquipIndex], m_vecInven_ItemP[_iIndex]);
		}
		cout << "��������Ϸ�" << endl;
		return true;
	}
}

void Inventory::Item_Render(const int _iIndex) const
{
	if (_iIndex < 0 || _iIndex > m_vecInven_ItemP.size() - 1)
		return;
	else
	{
		cout << _iIndex + 1 << ". ";
		cout << m_vecInven_ItemP[_iIndex]->Get_Name() << " : ";
		m_vecInven_ItemP[_iIndex]->Info_Render();
		cout << endl;
	}
}

void Inventory::Equip_Render() const
{

	for (int i = 0; i < m_vecEquip_ItemP.size(); ++i)
	{
		if (m_vecEquip_ItemP[i] == nullptr)
		{
			cout << "������" << endl;
			continue;
		}
		cout << i + 1 << ". ";
		cout << m_vecEquip_ItemP[i]->Get_Name() << " : ";
		m_vecEquip_ItemP[i]->Info_Render();
		cout << endl;
	}
}
