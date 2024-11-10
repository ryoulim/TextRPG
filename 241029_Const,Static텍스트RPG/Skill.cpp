#include "pch.h"
#include "Skill.h"

//enum SkillName { NORMALATTACK = 0, POWERHIT, FIRESHOT, WATERSHOT, GRASSSHOT };
//enum Type { NORMAL = 0, FIRE, WATER, GRASS };

void Skill::Initialize() // 2��
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
	cout << m_pCaster->Get_Status()->szName << "�� ����" << endl;
	DELAY;
	int iDamage = m_pCaster->Get_Status()->iAtk;
	return Hit(NORMAL, &iDamage);
}

bool Skill::PowerHit()
{
	cout << m_pCaster->Get_Status()->szName << "��(��) " << Get_Name(POWERHIT) << "�� �����ߴ�." << endl;
	DELAY;
	int iDamage = m_pCaster->Get_Status()->iAtk * 2;
	return Hit(NORMAL, &iDamage);
}

bool Skill::FireShot()
{
	cout << m_pCaster->Get_Status()->szName << "��(��) " << Get_Name(POWERHIT) << "�� �����ߴ�." << endl;
	DELAY;
	int iDamage = m_pCaster->Get_Status()->iAtk * 2;
	bool bKillCheck = Hit(FIRE, &iDamage);
	Effect(BURN);
	return bKillCheck;
}

bool Skill::WaterShot()
{
	cout << m_pCaster->Get_Status()->szName << "��(��) " << Get_Name(POWERHIT) << "�� �����ߴ�." << endl;
	DELAY;
	int iDamage = m_pCaster->Get_Status()->iAtk * 2;
	bool bKillCheck = Hit(WATER, &iDamage);
	Effect(FRIZE);
	return bKillCheck;
}

bool Skill::GrassShot()
{
	cout << m_pCaster->Get_Status()->szName << "��(��) " << Get_Name(POWERHIT) << "�� �����ߴ�." << endl;
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
			cout << m_pTarget->Get_Status()->szName << "�� ���� ���� �پ���." << endl;
			m_pTarget->Get_Status()->iEffect = BURN * 10 + 3;
			DELAY;
			return true;
		case FRIZE:
			cout << m_pTarget->Get_Status()->szName << "��(��) ���پ���." << endl;
			m_pTarget->Get_Status()->iEffect = BURN * 10 + 3;
			DELAY;
			return true;
		default:
			cout << "���ܹ߻� bool Skill::Effect(const int _iEffectNum)" << endl;
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
		return "��ų ����";
	case POWERHIT:
		return "���� ġ��";
	case FIRESHOT:
		return "���̾� ��";
	case WATERSHOT:
		return "���� ��";
	case GRASSSHOT:
		return "�׷��� ��";
	default :
		return "";
	}
}

const char* Skill::Get_Info(const int _iSkillNum)
{
	switch (_iSkillNum)
	{
	case POWERHIT:
		return " : �� �ϳ����� �� �Ӽ� 200% ������";
	case FIRESHOT:
		return " : �� �ϳ����� �� �Ӽ� 200% ������, ����Ȯ���� ȭ�� �ο�";
	case WATERSHOT:
		return " : �� �ϳ����� �� �Ӽ� 200% ������, ����Ȯ���� ���� �ο�";
	case GRASSSHOT:
		return " : �� �ϳ����� Ǯ �Ӽ� 200% ������";
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
