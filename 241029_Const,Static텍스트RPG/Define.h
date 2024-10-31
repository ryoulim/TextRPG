#pragma once

#define SAFE_DELETE(X) if ( X != nullptr ) { delete X ; X = nullptr; }
#define SAFE_DELETE_ARRAY(X) if ( X != nullptr ) { delete[] X ; X = nullptr; }
#define CLEAN system("cls")
#define DELAY _Thrd_sleep_for(50)
#define PAUSE system("pause")

typedef struct tagStatus
{
	char szName[24];
	int iLv, iExp;
	int iMaxHp, iHp;
	int iAtk;
	int iSpeed;
} Status ;

typedef struct tagItemInfo
{
	char szName[24];
	int iNumber; // 아이템 고유 번호
	char szInfo[32];
	int iCost;
	int iCount; // 몇개있는지
} ItemInfo;