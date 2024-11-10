#include "pch.h"
#include "Cure_Skill.h"

//enum CURE_SKILL_LIST { DIA, AMRITADROP };
//enum BUFF_SKILL_LIST { TARUKAJA = AMRITADROP + 1, RAKUKAJA, SUKUKAJA };


Skill* Cure_Skill::Create_Skill(const int _iSkillNum)
{
	Skill* pSkill = nullptr;
	bool* pStatusBuff = new bool[MAX_STATUS];
	memset(pStatusBuff, false, sizeof(bool) * MAX_STATUS);

	switch (_iSkillNum)
	{
	case DIA:
		pSkill = new Cure_Skill("디아", "HP 30% 회복,마나 3 소모", 30, 3, Object::HEAL, pStatusBuff, NONE);
		break;
	case AMRITADROP:
		pSkill = new Cure_Skill("암리타드롭", "모든 상태이상 해제,마나 8 소모", 30, 3, Object::NORMAL, pStatusBuff, CURE);
		break;
	case TARUKAJA:
		pStatusBuff[Object::ATK] = true;
		pSkill = new Cure_Skill("타루카쟈", "3턴간 아군의 공격력 증가, 마나 6 소모", 0, 6, Object::NORMAL, pStatusBuff, NONE);
		break;
	case RAKUKAJA:
		pStatusBuff[Object::DEF] = true;
		pSkill = new Cure_Skill("라쿠카쟈", "3턴간 아군의 방어력 증가, 마나 6 소모", 0, 6, Object::NORMAL, pStatusBuff, NONE);
		break;
	case SUKUKAJA:
		pStatusBuff[Object::LUK] = true;
		pStatusBuff[Object::SPD] = true;
		pSkill = new Cure_Skill("스쿠카쟈", "3턴간 아군의 운,스피드 증가, 마나 6 소모", 0, 6, Object::NORMAL, pStatusBuff, NONE);
		break;
	default:
		break;
	}
	// 수정해야할것
	// 1. 상태이상 어떤걸 치료할지 세분화
	// 2. 큐어스킬에 과연 타입이 필요한가?

	return pSkill;
}

bool Cure_Skill::Use_Skill(Object* _pCaster, Object* _pTarget)
{
	if (m_iForce != 0)
		_pCaster->Heal(m_iForce, true);

	for (int i = 2; i < MAX_STATUS; ++i)
	{
		if (m_pStatusBuff[i])
		{
			if (_pCaster->Get_Status()->iBuff == 0)
			{
				_pCaster->Set_iBuff(i, 3);
				cout << _pCaster->Get_Status()->szName << "의" << Status_Name_Render((Object::STATUSNUM)i) << "이(가) 증가했다." << endl;;
			}
			else if (_pCaster->Get_Status()->iBuff < 0)
			{
				_pCaster->Set_iBuff(i, 0);
				cout << _pCaster->Get_Status()->szName << "의" << Status_Name_Render((Object::STATUSNUM)i) << "이(가) 원래대로 돌아왔다. " << endl;;
			}
			else
			{
				_pCaster->Set_iBuff(i, 3);
				cout << _pCaster->Get_Status()->szName << "의" << Status_Name_Render((Object::STATUSNUM)i) << "증가의 지속시간이 증가했다." << endl;;
			}
			DELAY(50);
		}
	}

	if (m_Effect_Type == CURE)
	{
		if (_pCaster->Get_Status()->iEffect != 0)
			cout << _pCaster->Get_Status()->szName << "의 " << Effect_Name_Render(EFFECT_TYPE(_pCaster->Get_Status()->iEffect / 10)) << "이(가) 회복되었다." << endl;
		else
			cout << _pCaster->Get_Status()->szName << "은 건강한 상태이다." << endl;
		DELAY(50);
	}

	return false;
}
