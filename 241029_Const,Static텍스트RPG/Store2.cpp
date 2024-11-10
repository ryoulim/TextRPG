#include "pch.h"
#include "Store2.h"
#include "Common.h"
#include "Object.h"
#include "Player.h"

void Store2::Store_Buy()
{
	int iSelect(0);
	Item* pItem;
	Bag* pBag = dynamic_cast<Player*>(m_pPlayer)->Get_Bag_Equip();
	while (true)
	{
		pItem = new Equip_Item;
		system("cls");
		cout << "무엇을 구매하시겠습니까?" << endl;
		dynamic_cast<Player*>(m_pPlayer)->Get_Bag_Useable()->Gold_Render();
		cout << "1." << pItem->Get_Name(Equip_Item::WEAPON2) << '\t' << pItem->Get_Info(Equip_Item::WEAPON2) << " , " << pItem->Get_Cost(Equip_Item::WEAPON2) << endl;
		cout << "2." << pItem->Get_Name(Equip_Item::HAT2) << '\t' << pItem->Get_Info(Equip_Item::HAT2) << " , " << pItem->Get_Cost(Equip_Item::HAT2) << endl;
		cout << "3." << pItem->Get_Name(Equip_Item::CLOTHES2) << '\t' << pItem->Get_Info(Equip_Item::CLOTHES2) << " , " << pItem->Get_Cost(Equip_Item::CLOTHES2) << endl;
		cout << "4." << pItem->Get_Name(Equip_Item::SHOES2) << '\t' << pItem->Get_Info(Equip_Item::SHOES2) << " , " << pItem->Get_Cost(Equip_Item::SHOES2) << endl;
		delete pItem;
		pItem = new Useable_Item;
		cout << "5." << pItem->Get_Name(Useable_Item::POTION1) << '\t' << pItem->Get_Info(Useable_Item::POTION1) << " , " << pItem->Get_Cost(Useable_Item::POTION1) << endl;
		cout << "6." << pItem->Get_Name(Useable_Item::POTION2) << '\t' << pItem->Get_Info(Useable_Item::POTION2) << " , " << pItem->Get_Cost(Useable_Item::POTION2) << endl;
		cout << "0. 돌아가기" << endl;
		iSelect = Common::Get_Int();
		switch (iSelect)
		{
		case 1:
			iSelect = Equip_Item::WEAPON2;
			delete pItem;
			pItem = new Equip_Item;
			break;
		case 2:
			iSelect = Equip_Item::HAT2;
			delete pItem;
			pItem = new Equip_Item;
			break;
		case 3:
			iSelect = Equip_Item::CLOTHES2;
			delete pItem;
			pItem = new Equip_Item;
			break;
		case 4:
			iSelect = Equip_Item::SHOES2;
			delete pItem;
			pItem = new Equip_Item;
			break;
		case 5:
			iSelect = Useable_Item::POTION1;
			pBag = dynamic_cast<Player*>(m_pPlayer)->Get_Bag_Useable();
			break;
		case 6:
			iSelect = Useable_Item::POTION2;
			pBag = dynamic_cast<Player*>(m_pPlayer)->Get_Bag_Useable();
			break;

		case 0:
			return;
		default:
			continue;
		}

		if (dynamic_cast<Player*>(m_pPlayer)->Get_Bag_Equip()->Gold_Cal(-pItem->Get_Cost(iSelect)) == false) // 돈이 충분하면 계산되고, 없으면 false 반환
			cout << "골드가 부족합니다." << endl;
		else
		{
			pBag->Update(iSelect, 1);
			cout << pItem->Get_Name(iSelect) << " 구매완료" << endl;
		}
		delete pItem;
		PAUSE;
		continue;
	}
}
