#include "pch.h"
#include "Store.h"
#include "Inventory.h"

void Store::Meet_Store(Object* _pPlayer, const int _iFloor)
{
	Store sStore(_pPlayer);
	int iSelect(0);
	while (true)
	{
		CLEAR;
		cout << "앞쪽에 상점이 있다. (1. 들어간다 2. 지나친다)" << endl;
		cin >> iSelect;
		switch (iSelect)
		{
		case 1:
			sStore.Initialize(Store::STORE1);
			break;
		case 2:
			return;
		default:
			continue;
		}

		sStore.Update();
		return;
	}
}

void Store::Update()
{
	int iSelect(0);
	while (true)
	{
		CLEAR;
		LINE_UI;
		cout << "소지금 : " << Inventory::m_iPlayerGold << endl;
		cout << "1.구매 2. 판매 3.나가기" << endl;
		LINE_UI;

		cin >> iSelect;
		switch (iSelect)
		{
		case 1:
			Buy();
			continue;
		case 2:
			Sell();
			continue;
		case 3:
			return;
		default:
			continue;
		}
	}
}

void Store::Initialize(STORETYPE _StoreType)
{
	switch (_StoreType)
	{
	case STORE1:
		m_iItem_Count = 7;
		m_ppItem = new Item * [m_iItem_Count];
		m_ppItem[0] = Equip_Item::Create_Item(Equip_Item::SWORD1);
		m_ppItem[1] = Equip_Item::Create_Item(Equip_Item::STAFF1);
		m_ppItem[2] = Equip_Item::Create_Item(Equip_Item::DAGGER1);
		m_ppItem[3] = Equip_Item::Create_Item(Equip_Item::HAT1);
		m_ppItem[4] = Equip_Item::Create_Item(Equip_Item::CLOTHES1);
		m_ppItem[5] = Equip_Item::Create_Item(Equip_Item::SHOES1);
		m_ppItem[6] = Potion_Item::Create_Item(Potion_Item::POTION1);
		break;
	case STORE2:
		m_iItem_Count = 7;
		m_ppItem = new Item * [m_iItem_Count];
		m_ppItem[0] = Equip_Item::Create_Item(Equip_Item::SWORD2);
		m_ppItem[1] = Equip_Item::Create_Item(Equip_Item::STAFF2);
		m_ppItem[2] = Equip_Item::Create_Item(Equip_Item::DAGGER2);
		m_ppItem[3] = Equip_Item::Create_Item(Equip_Item::HAT2);
		m_ppItem[4] = Equip_Item::Create_Item(Equip_Item::CLOTHES2);
		m_ppItem[5] = Equip_Item::Create_Item(Equip_Item::SHOES2);
		m_ppItem[6] = Potion_Item::Create_Item(Potion_Item::POTION1);
		break;
	case STORE3:
		m_iItem_Count = 7;
		m_ppItem = new Item * [m_iItem_Count];
		m_ppItem[0] = Equip_Item::Create_Item(Equip_Item::HAT3);
		m_ppItem[1] = Equip_Item::Create_Item(Equip_Item::CLOTHES3);
		m_ppItem[2] = Equip_Item::Create_Item(Equip_Item::SHOES3);
		m_ppItem[3] = Potion_Item::Create_Item(Potion_Item::POTION2);
		m_ppItem[4] = Attack_Item::Create_Item(Attack_Item::BOMB);
		m_ppItem[5] = Buff_Item::Create_Item(Buff_Item::ATKUP);
		m_ppItem[6] = Buff_Item::Create_Item(Buff_Item::DEFUP);
		break;
	default:
		break;
	}
}

void Store::Release()
{
	for (int i = 0; i < m_iItem_Count; ++i)
		SAFE_DELETE(m_ppItem[i]);
	SAFE_DELETE_ARRAY(m_ppItem);
}

void Store::Buy()
{
	Inventory* pInven = nullptr;
	int iSelect(0);
	while (true)
	{
		CLEAR;
		LINE_UI;
		cout << "구매하실 물픔을 선택해주세요" << endl;
		cout << "소지금 : " << Inventory::m_iPlayerGold << endl;
		LINE_UI;
		for (int i = 0; i < m_iItem_Count; ++i)
			cout << i + 1 << " . " << m_ppItem[i]->Get_Name() << "\t:\t" << m_ppItem[i]->Get_Info() << endl;
		cout << m_iItem_Count + 1 << " . 돌아가기" << endl;

		cin >> iSelect;
		if (1 > iSelect || m_iItem_Count+1 < iSelect)
			continue;
		else if (m_iItem_Count + 1 == iSelect)
			return;
		else
		{
			iSelect--;
			pInven = dynamic_cast<Player*>(m_pPlayer)->Get_Inven(m_ppItem[iSelect]->Get_Type());
			pInven->Add_Item(m_ppItem[iSelect], 1);
			cout << m_ppItem[iSelect]->Get_Name() << " 구매 완료" << endl;
			PAUSE;
		}
	}
}

void Store::Sell()
{
	Inventory* pInven = dynamic_cast<Player*>(m_pPlayer)->Get_Inven(Item::EQUIP);
	int iSelect(0),iLength(0);
	while (true)
	{
		CLEAR;
		LINE_UI;
		cout << "구매하실 물픔을 선택해주세요" << endl;
		cout << "(인벤토리 변경 옵션 - 장비아이템(88), 소비아이템(99), 기타아이템(00)" << endl;
		cout << "소지금 : " << Inventory::m_iPlayerGold << endl;
		LINE_UI;
		pInven->Render();
		iLength = pInven->Get_Length();
		cout << iLength + 1 << ". 돌아가기" << endl;

		cin >> iSelect;
		if (88 == iSelect)
		{
			pInven = dynamic_cast<Player*>(m_pPlayer)->Get_Inven(Item::EQUIP);
			continue;
		}
		else if (99 == iSelect)
		{
			pInven = dynamic_cast<Player*>(m_pPlayer)->Get_Inven(Item::USEABLE);
			continue;
		}
		else if (00 == iSelect)
		{
			pInven = dynamic_cast<Player*>(m_pPlayer)->Get_Inven(Item::OTHER);
			continue;
		}
		else if (1 > iSelect || iLength + 1 < iSelect)
			continue;
		else if (iLength + 1 == iSelect)
			return;
		else
		{
			cout << pInven->Get_Item(iSelect - 1)->Get_Name() << "판매 완료" << endl;
			pInven->Remove_Item(iSelect - 1, 1);
			PAUSE;
		}
	}
}
