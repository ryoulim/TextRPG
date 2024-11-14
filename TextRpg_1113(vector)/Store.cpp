#include "pch.h"
#include "Store.h"

#define STORE_ITEM(X) 	m_vecItemList.push_back(Equip_Item::Create_Equip_Item(Equip_Item:: X ));

void Store::Initialize(const int _iStoreNum)
{
	m_vecItemList.reserve(6);

	switch (_iStoreNum)
	{
	case Store1:
		STORE_ITEM(SWORD1);
		STORE_ITEM(STAFF1);
		STORE_ITEM(DAGGER1);
		STORE_ITEM(HAT1);
		STORE_ITEM(CLOTHES1);
		STORE_ITEM(SHOES1);
		break;
	case Store2:
		STORE_ITEM(SWORD2);
		STORE_ITEM(STAFF2);
		STORE_ITEM(DAGGER2);
		STORE_ITEM(HAT2);
		STORE_ITEM(CLOTHES2);
		STORE_ITEM(SHOES2);
		break;
	case Store3:
		STORE_ITEM(SWORD3);
		STORE_ITEM(STAFF3);
		STORE_ITEM(DAGGER3);
		STORE_ITEM(HAT3);
		STORE_ITEM(CLOTHES3);
		STORE_ITEM(SHOES3);
		break;
	}
}

void Store::Update()
{
	int iSelect(0);
	while (true)
	{
		system("cls");
		cout << "1.구매 2.판매 3.나가기" << endl;
		cin >> iSelect;
		switch (iSelect)
		{
		case 1:
			Buy();
			break;
		case 2:
			Sell();
		case 3:
			return;
		default:
			continue;
		}
	}
}

void Store::Release()
{
	for_each(m_vecItemList.begin(), m_vecItemList.end(), Safe_Delete<Equip_Item*>);
}

void Store::Buy()
{
	int iSelect(0);
	while (true)
	{
		system("cls");
		cout << "구매하실 물건을 골라주세요. (0. 돌아가기)" << endl;
		for (int i = 0; i < m_vecItemList.size(); ++i)
		{
			cout << i + 1 << ". " << m_vecItemList[i]->Get_Name() << " : ";
			m_vecItemList[i]->Info_Render();
			cout << endl;
		}
		cout << "소지금 : " << m_pInven->Get_Gold() << endl;

		cin >> iSelect;

		if (iSelect == 0)
			return;
		else if (iSelect < 0 || iSelect > m_vecItemList.size())
			continue;
		else
		{
			iSelect--;
			if (m_pInven->Get_Gold() < m_vecItemList[iSelect]->Get_Cost())
			{
				cout << "골드가 부족합니다." << endl;
			}
			else
			{
				m_pInven->Add_Item(m_vecItemList[iSelect]);
				m_pInven->Set_Gold(m_pInven->Get_Gold() - m_vecItemList[iSelect]->Get_Cost());
				cout << "구매완료" << endl;
			}
			system("pause");
		}
	}
}

void Store::Sell()
{
	int iSelect(0);
	while (true)
	{
		system("cls");
		cout << "판매하실 물건을 골라주세요. (0. 돌아가기)" << endl;
		cout << "소지금 : " << m_pInven->Get_Gold() << endl;

		for (int i = 0; i < m_pInven->Get_Size(); ++i)
			m_pInven->Item_Render(i);

		cin >> iSelect;
		if (iSelect == 0)
			return;
		else if (iSelect >= 1 && iSelect <= m_pInven->Get_Size())
		{
			m_pInven->Sell_Item_Gold(iSelect - 1);
			m_pInven->Delete_Item(iSelect - 1);
			cout << "판매완료" << endl;
			system("pause");
		}
		else
			continue;
	}
}
