#pragma once

#define MAX_STATUS 7
#define MAX_SKILL_ABLE 4
#define MAX_TYPE 8

class Skill;

typedef struct tagStatus
{
	char szName[32];
	char szClass[12];
	int iLv, iExp;
	int iMaxHp, iHp;
	int iMaxMp, iMp;
	int iAtk, iM_Atk, iDef, iSpeed;
	int iEffect;
	int* pType;
	int iBuff[MAX_STATUS];
} Status;

class Object
{
public:
	virtual ~Object() { Release(); }

	virtual void Info_Render() const = 0;
	virtual void Info_Render_Detail() const = 0;

	enum STATUSNUM { HP, MP, ATK, M_ATK, DEF, SPD, LUK };
	enum TYPE { NORMAL, FIRE, ICE, THUNDER, WIND, LIGHT, DARKNESS, HEAL};

	Status* Get_Status() { return &m_Status; }
	bool Damaged(const int _iDamage);
	void Heal(int _iForce, const bool _bMode);
	void Set_iBuff(const int _iIndex, const int _iValue) { m_Status.iBuff[_iIndex] = _iValue; }
	void Set_iEffect(const int _iType) { m_Status.iEffect = _iType * 10 + 3; }

protected:
	Status m_Status;
	Skill* m_pSkill;

	void Release();

	Object(char _szName[], int _iHp, int _iMp, int _iAtk, int _iM_Atk, int _iDef, int _iSpeed, const char* _pClass, int* _pType) : m_pSkill(nullptr)
	{
		strcpy_s(m_Status.szName, sizeof(m_Status.szName), _szName);
		strcpy_s(m_Status.szClass, sizeof(m_Status.szClass), _pClass);
		memset(m_Status.iBuff, 0, sizeof(int) * MAX_STATUS);
		m_Status.iLv = 1;
		m_Status.iExp = 0;
		m_Status.iMaxHp = m_Status.iHp = _iHp;
		m_Status.iMaxMp = m_Status.iMp = _iMp;
		m_Status.iAtk = _iAtk;
		m_Status.iM_Atk = _iM_Atk;
		m_Status.iDef = _iDef;
		m_Status.iSpeed = _iSpeed;
		m_Status.pType = _pType;
		m_Status.iEffect = 0;
	}

	const char* Type_Render();
	const char* Effect_Render();
};

