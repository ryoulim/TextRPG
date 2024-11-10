#include "pch.h"
#include "Useable_Item.h"
#include "Common.h"
#include "Player.h"


const char* Useable_Item::Get_Name(const int _iItemNum) const
{
	switch (_iItemNum)
	{
	case POTION1:
		return "�Ϲ� ����";
	case POTION2:
		return "��� ����";
	default:
		return "";
	}
}

const char* Useable_Item::Get_Info(const int _iItemNum) const
{
	switch (_iItemNum)
	{
	case POTION1:
		return "ü�� 30 ȸ��";
	case POTION2:
		return "ü�� 60 ȸ��";
	default:
		return "";
	}
}

int Useable_Item::Get_Cost(const int _iItemNum) const
{
	switch (_iItemNum)
	{
	case POTION1:
		return 30;
	case POTION2:
		return 50;
	default:
		return 0;
	}
}

bool Useable_Item::Use_Item(Object* _pObject) const
{
	int iSelect(0);
	int iKind = dynamic_cast<Player*>(_pObject)->Get_Bag_Useable()->Get_iKind();
	int iEffect;
	while (true)
	{
		system("cls");
		dynamic_cast<Player*>(_pObject)->Get_Bag_Useable()->Info_Render();
		cout << iKind + 1 << " : ���ư��� " << endl;
		iSelect = Common::Get_Int();
		if (1 > iSelect || iKind + 1 < iSelect)
			continue;
		else if (iSelect == iKind + 1)
			return true;
		switch (dynamic_cast<Player*>(_pObject)->Get_Bag_Useable()->Get_pItem()[iSelect - 1])
		{
		case POTION1:
			iEffect = 30;
			cout << _pObject->Get_Status()->szName << "��(��) " << Get_Name(POTION1) << "�� ����ߴ�." << endl;
			DELAY;
			_pObject->Heal(30);
			dynamic_cast<Player*>(_pObject)->Get_Bag_Useable()->Update(POTION1, -1);
			return false;
		case POTION2:
			cout << _pObject->Get_Status()->szName << "��(��) " << Get_Name(POTION2) << "�� ����ߴ�." << endl;
			DELAY;
			_pObject->Heal(50);
			dynamic_cast<Player*>(_pObject)->Get_Bag_Useable()->Update(POTION2, -1);
			return false;
		default:
			cout << "����� �� ���� �������Դϴ�." << endl;
			PAUSE;
			continue;
		}
	}
}