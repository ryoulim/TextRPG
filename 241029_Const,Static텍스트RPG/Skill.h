#pragma once
#include "Object.h"

#define MAX_SKILL 5
#define MAX_TYPE 4


class Skill
{
public:
	static const char* Get_Name(const int _iSkillNum);
	static const char* Get_Info(const int _iSkillNum);
	static int Get_Cost(const int _iSkillNum);

	static bool Use_Skill(Object* _pCaster, Object* pTarget, const int _iSkillNum);

	enum SKILLNAME { NORMALATTACK = 0, POWERHIT, FIRESHOT, WATERSHOT, GRASSSHOT }; // 기본공격도 스킬로 취급하기
	enum TYPE { NORMAL = 0, FIRE, WATER, GRASS };
	enum EFFECT { NONE,BURN,FRIZE };

private:
	Skill(Object* _pCaster, Object* _pTarget) : m_pCaster(_pCaster), m_pTarget(_pTarget), m_iTypeCal() {}
	~Skill() { Release(); }

	void Initialize();
	void Release();

	// 여기 함수들 매개변수 상속 이후에 재지정
	Object* m_pCaster;
	Object* m_pTarget;
	int m_iTypeCal[MAX_TYPE][MAX_TYPE]; // 첫번째 Index는 공격타입, 두번째 Index는 방어타입

	bool NormalAttack();
	bool PowerHit();
	bool FireShot();
	bool WaterShot();
	bool GrassShot();

	bool Hit(const int _iType,int* _iDamage);
	bool Effect(const int _iEffectNum);
};