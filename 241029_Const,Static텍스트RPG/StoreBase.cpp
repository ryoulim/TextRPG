#include "pch.h"
#include "StoreBase.h"
#include "Common.h"

#include "Object.h"
#include "Store1.h"
#include "Store2.h"
#include "Store3.h"
#include "Player.h"


void StoreBase::Store(Object* _pPlayer, const int _iStoreNum)
{
	StoreBase* pStore;
	switch (_iStoreNum)
	{
	case 1:
		pStore = new Store1;
		break;
	case 2:
		pStore = new Store2;
		break;
	case 3:
		pStore = new Store3;
		break;
	default:
		return;
	}

	pStore->Initialize(_pPlayer);
	pStore->Update();
}

StoreBase::~StoreBase()
{
	Release();
}

void StoreBase::Update()
{
	while (true)
	{
		cout << "���ʿ� ������ �ִ�. (1.���� 2. ����ģ��)" << endl;
		int iSelect = Common::Get_Int();
		if (1 > iSelect || 2 < iSelect)
			continue;
		else if (1 == iSelect)
			break;
		else if (2 == iSelect)
		{
			cout << "========================================" << endl;
			cout << "������ ����Ĩ�ϴ�." << endl;
			PAUSE;
			return;
		}
	}

	while (true)
	{
		system("cls");
		dynamic_cast<Player*>(m_pPlayer)->Get_Bag_Equip()->Gold_Render();
		cout << "1. ���� 2. �Ǹ� 3. ������" << endl;
		switch (Common::Get_Int())
		{
		case 1:
			Store_Buy();
			continue;
		case 2:
			Store_Sell();
			continue;
		case 3:
			return;
		default:
			continue;
		}
	}
}

void StoreBase::Store_Sell()
{
	Bag* pBag = dynamic_cast<Player*>(m_pPlayer)->Get_Bag_Equip();
	int iKind(0);
	char cSelect(0);
	while (true)
	{
		iKind = pBag->Get_iKind();
		system("cls");
		cout << "������ �Ǹ��Ͻðڽ��ϱ�?" << endl;
		pBag->Info_Render();
		cout << iKind + 1 << " : ���ư���" << endl;
		cout << "(����ɼ� : Q=��������, W=�Ҹ������, E=��Ÿ������) ";
		cSelect = getchar();
		
		if ('0' < cSelect && (char)iKind + '1' > cSelect)
		{
			cSelect -= '0';
			pBag->Sell_Item((int)cSelect);
		}
		else if ((char)iKind + '1' == cSelect)
			return;
		else
		{
			switch (cSelect)
			{
			case 'q':
			case 'Q':
				pBag = dynamic_cast<Player*>(m_pPlayer)->Get_Bag_Equip();
				continue;
			case 'w':
			case 'W':
				pBag = dynamic_cast<Player*>(m_pPlayer)->Get_Bag_Useable();
				continue;
			case 'e':
			case 'E':
				pBag = dynamic_cast<Player*>(m_pPlayer)->Get_Bag_Other();
				continue;
			default:
				continue;
			}
		}
	}
}