#include "pch.h"
#include "Object.h"

#include "Player.h"

Object* Object::Create_Player(string* _pstrName, const int _iClassNum)
{
	Object* pPlayer = nullptr;
	switch (_iClassNum)
	{
	case Player::WARRIOR:
		pPlayer = new Player(_pstrName, 1000, 100, 10, 10, Player::WARRIOR);
		break;
	case Player::MAGE:
		pPlayer = new Player(_pstrName, 1000, 100, 10, 10, Player::MAGE);
		break;
	case Player::THIEF:
		pPlayer = new Player(_pstrName, 1000, 100, 10, 10, Player::THIEF);
		break;
	default:
		break;
	}
	
	static_cast<Player*>(pPlayer)->Initalize();
	static_cast<Player*>(pPlayer)->Get_Inven()->Initialize();

	return pPlayer;
}

Object* Object::Create_Monster(const int _iMonNum)
{
	Object* pPlayer = nullptr;
	switch (_iMonNum)
	{
		case 
	}
	return nullptr;
}
