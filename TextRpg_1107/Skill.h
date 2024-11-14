#pragma once
#include "Object.h"
#include "Define.h"

#define MAX_SKILL_NUM 15

class Object;

//typedef struct tagInfo
//{
//
//} Info;

class Skill
{
public:
	~Skill() { Release(); }

	virtual bool Use_Skill(Object* _pCaster, Object* _pTarget = nullptr) = 0;
	enum EFFECT_TYPE {NONE, BURN, FRIZE, PARALYZE, INSTANT_DEATH, CURE};

	enum SKILL_LIST
	{
		ATTACK = 0, SLASH, AGI, BUFU, ZIO, GARU, KOUHA, EIHA,
		TARUNDA, RAKUNDA, SUKUNDA,
		DIA, AMRITADROP,
		TARUKAJA, RAKUKAJA, SUKUKAJA
	};

	static Skill* Create_Skill(SKILL_LIST _SkillList);

	const char* Get_Name() { return m_szName; }
	const char* Get_Info() { return m_szInfo; }

protected:
//	Info m_Info;
	EFFECT_TYPE m_Effect_Type;
	char m_szName[16];
	char m_szInfo[100];
	int m_iForce;
	int m_iCost;
	int m_iType;
	bool* m_pStatusBuff;

	Skill(const char* _szName, const char* _szInfo, int _iForce, int _iCost, int _iType, bool* _bStatusBuff, EFFECT_TYPE _Effect_type)
	{
		strcpy_s(m_szName, sizeof(m_szName), _szName);
		strcpy_s(m_szInfo, sizeof(m_szInfo), _szInfo);
		m_iForce = _iForce;
		m_iCost = _iCost;
		m_iType = _iType;
		m_pStatusBuff = _bStatusBuff;
		m_Effect_Type = _Effect_type;
	}
	
	const char* Status_Name_Render(Object::STATUSNUM _StatusNum) const;
	const char* Effect_Name_Render(EFFECT_TYPE _EffectType) const;

	void Release() { SAFE_DELETE_ARRAY(m_pStatusBuff); }
};

