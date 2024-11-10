#include "pch.h"
#include "Skill.h"

//enum SkillName { NORMALATTACK = 0, POWERHIT, FIRESHOT, WATERSHOT, GRASSSHOT };
//enum Type { NORMAL = 0, FIRE, WATER, GRASS };

void Skill::Initialize() // 2배
{
	m_iTypeCal[NORMAL][NORMAL] = 2;
	m_iTypeCal[NORMAL][FIRE] = 2;
	m_iTypeCal[NORMAL][WATER] = 2;
	m_iTypeCal[NORMAL][GRASS] = 2;

	m_iTypeCal[FIRE][NORMAL] = 2;
	m_iTypeCal[FIRE][FIRE] = 2;
	m_iTypeCal[FIRE][WATER] = 1;
	m_iTypeCal[FIRE][GRASS] = 4;

	m_iTypeCal[WATER][NORMAL] = 2;
	m_iTypeCal[WATER][FIRE] = 4;
	m_iTypeCal[WATER][WATER] = 2;
	m_iTypeCal[WATER][GRASS] = 1;

	m_iTypeCal[GRASS][NORMAL] = 2;
	m_iTypeCal[GRASS][FIRE] = 1;
	m_iTypeCal[GRASS][WATER] = 4;
	m_iTypeCal[GRASS][GRASS] = 2;
}

void Skill::Release()
{
}

bool Skill::NormalAttack()
{
	cout << m_pCaster->Get_Status()->szName << "의 공격" << endl;
	DELAY;
	int iDamage = m_pCaster->Get_Status()->iAtk;
	return Hit(NORMAL, &iDamage);
}

bool Skill::PowerHit()
{
	cout << m_pCaster->Get_Status()->szName << "은(는) " << Get_Name(POWERHIT) << "를 시전했다." << endl;
	DELAY;
	int iDamage = m_pCaster->Get_Status()->iAtk * 2;
	return Hit(NORMAL, &iDamage);
}

bool Skill::FireShot()
{
	cout << m_pCaster->Get_Status()->szName << "은(는) " << Get_Name(POWERHIT) << "을 시전했다." << endl;
	DELAY;
	int iDamage = m_pCaster->Get_Status()->iAtk * 2;
	bool bKillCheck = Hit(FIRE, &iDamage);
	Effect(BURN);
	return bKillCheck;
}

bool Skill::WaterShot()
{
	cout << m_pCaster->Get_Status()->szName << "은(는) " << Get_Name(POWERHIT) << "을 시전했다." << endl;
	DELAY;
	int iDamage = m_pCaster->Get_Status()->iAtk * 2;
	bool bKillCheck = Hit(WATER, &iDamage);
	Effect(FRIZE);
	return bKillCheck;
}

bool Skill::GrassShot()
{
	cout << m_pCaster->Get_Status()->szName << "은(는) " << Get_Name(POWERHIT) << "을 시전했다." << endl;
	DELAY;
	int iDamage = m_pCaster->Get_Status()->iAtk * 2;
	return Hit(GRASS, &iDamage);
}

bool Skill::Hit(const int _iType, int* _iDamage)
{
	*_iDamage *= m_iTypeCal[_iType][m_pTarget->Get_Status()->iType] / 2;
	switch (m_iTypeCal[_iType][m_pTarget->Get_Status()->iType])
	{
	case 0:
		cout << "Immunity!" << endl;
		DELAY;
		return false;
	case 1:
		cout << "Block!" << endl;
		DELAY;
		break;
	case 4:
		cout << "Weak!" << endl;
		DELAY;
		break;
	default:
		break;
	}

	if (Percent(10))
	{
		*_iDamage *= 3 / 2;
		cout << "Critical!" << endl;
		DELAY;
	}

	return m_pTarget->Damaged(*_iDamage);
}

bool Skill::Effect(const int _iEffectNum)
{
	if (0 == m_pTarget->Get_Status()->iEffect && Percent(10))
	{
		switch (_iEffectNum)
		{
		case BURN:
			cout << m_pTarget->Get_Status()->szName << "의 몸에 불이 붙었다." << endl;
			m_pTarget->Get_Status()->iEffect = BURN * 10 + 3;
			DELAY;
			return true;
		case FRIZE:
			cout << m_pTarget->Get_Status()->szName << "은(는) 얼어붙었다." << endl;
			m_pTarget->Get_Status()->iEffect = BURN * 10 + 3;
			DELAY;
			return true;
		default:
			cout << "예외발생 bool Skill::Effect(const int _iEffectNum)" << endl;
			break;
		}
	}
	return false;
}

const char* Skill::Get_Name(const int _iSkillNum)
{
	switch (_iSkillNum)
	{
	case NORMALATTACK :
		return "스킬 없음";
	case POWERHIT:
		return "세게 치기";
	case FIRESHOT:
		return "파이어 샷";
	case WATERSHOT:
		return "워터 샷";
	case GRASSSHOT:
		return "그레스 샷";
	default :
		return "";
	}
}

const char* Skill::Get_Info(const int _iSkillNum)
{
	switch (_iSkillNum)
	{
	case POWERHIT:
		return " : 적 하나에게 무 속성 200% 데미지";
	case FIRESHOT:
		return " : 적 하나에게 불 속성 200% 데미지, 일정확률로 화상 부여";
	case WATERSHOT:
		return " : 적 하나에게 물 속성 200% 데미지, 일정확률로 빙결 부여";
	case GRASSSHOT:
		return " : 적 하나에게 풀 속성 200% 데미지";
	default:
		return "";
	}
}

int Skill::Get_Cost(const int _iSkillNum)
{
	switch (_iSkillNum)
	{
	case POWERHIT:
		return 3;
	case FIRESHOT:
		return 4;
	case WATERSHOT:
		return 4;
	case GRASSSHOT:
		return 3;
	default:
		return 0;
	}
}

bool Skill::Use_Skill(Object* _pCaster, Object* pTarget, const int _iSkillNum)
{
	Skill sSkill(_pCaster, pTarget);
	sSkill.Initialize();

	switch (_iSkillNum)
	{
	case NORMALATTACK:
		return sSkill.NormalAttack();
	case POWERHIT:
		return sSkill.PowerHit();
	case FIRESHOT:
		return sSkill.FireShot();
	case WATERSHOT:
		return sSkill.WaterShot();
	case GRASSSHOT:
		return sSkill.GrassShot();
	default:
		return false;
	}
}
