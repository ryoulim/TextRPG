#include "pch.h"
#include "Useable_Item.h"
#include "Common.h"
#include "Player.h"


const char* Useable_Item::Get_Name(const int _iItemNum) const
{
	switch (_iItemNum)
	{
	case POTION1:
		return "일반 포션";
	case POTION2:
		return "고급 포션";
	default:
		return "";
	}
}

const char* Useable_Item::Get_Info(const int _iItemNum) const
{
	switch (_iItemNum)
	{
	case POTION1:
		return "체력 30 회복";
	case POTION2:
		return "체력 60 회복";
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
		cout << iKind + 1 << " : 돌아가기 " << endl;
		iSelect = Common::Get_Int();
		if (1 > iSelect || iKind + 1 < iSelect)
			continue;
		else if (iSelect == iKind + 1)
			return true;
		switch (dynamic_cast<Player*>(_pObject)->Get_Bag_Useable()->Get_pItem()[iSelect - 1])
		{
		case POTION1:
			iEffect = 30;
			cout << _pObject->Get_Status()->szName << "은(는) " << Get_Name(POTION1) << "을 사용했다." << endl;
			DELAY;
			_pObject->Heal(30);
			dynamic_cast<Player*>(_pObject)->Get_Bag_Useable()->Update(POTION1, -1);
			return false;
		case POTION2:
			cout << _pObject->Get_Status()->szName << "은(는) " << Get_Name(POTION2) << "을 사용했다." << endl;
			DELAY;
			_pObject->Heal(50);
			dynamic_cast<Player*>(_pObject)->Get_Bag_Useable()->Update(POTION2, -1);
			return false;
		default:
			cout << "사용할 수 없는 아이템입니다." << endl;
			PAUSE;
			continue;
		}
	}
}