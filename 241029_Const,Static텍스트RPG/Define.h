#pragma once

#define SAFE_DELETE(X) if ( X != nullptr ) { delete X ; X = nullptr; }
#define SAFE_DELETE_ARRAY(X) if ( X != nullptr ) { delete[] X ; X = nullptr; }
#define CLEAN system("cls")
#define DELAY _Thrd_sleep_for(50)
#define PAUSE system("pause")
#define Percent(X) 0 < (X) - rand()%100
#define MAX_SKILL_ABLE 4

typedef struct tagStatus
{
	char szName[24];
	int iLv, iExp;
	int iType;
	int iMaxHp, iHp;
	int iMaxMp, iMp;
	int iAtk;
	int iSpeed;

	int iSkill[MAX_SKILL_ABLE] = {};
	int iEffect; // 10자릿수는 고유번호 1의자릿수는 타이머
} Status;