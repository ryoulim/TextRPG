#include "pch.h"
#include "Hit_Skill.h"

//enum HIT_SKILL_LIST { ATTACK = 0, SLASH, AGI, BUFU, ZIO, GARU, KOUHA, EIHA };
//enum DEBUFF_SKILL_LIST { TARUNDA = EIHA + 1, RAKUNDA, SUKUNDA };

//Hit_Skill(const char* _szName, const char* _szInfo, int _iForce, int _iType, bool* _bStatusBuff, EFFECT_TYPE _Effect_type) :

Skill* Hit_Skill::Create_Skill(const int _iSkillNum)
{
	Skill* pSkill = nullptr;
	bool* pStatusBuff = new bool[MAX_STATUS];
	memset(pStatusBuff, false, sizeof(bool) * MAX_STATUS);
	
	switch (_iSkillNum)
	{
	case ATTACK : 
		pSkill = new Hit_Skill("공격", "100%의 무 속성 물리데미지, 마나 0 소모", 100, 0 , Object::NORMAL, pStatusBuff, NONE, false);
		break;
	case SLASH:
		pSkill = new Hit_Skill("슬래쉬", "150%의 무 속성 물리데미지, 마나 3 소모", 150, 3, Object::NORMAL, pStatusBuff, NONE, false);
		break;
	case AGI:
		pSkill = new Hit_Skill("아기", "150%의 화염 속성 마법데미지, 마나 3 소모, 10%확률로 화상 부여", 150, 3, Object::FIRE, pStatusBuff, BURN, true);
		break;
	case BUFU:
		pSkill = new Hit_Skill("부흐", "150%의 얼음 속성 마법데미지, 마나 4 소모, 10%확률로 빙결 부여", 150, 4, Object::ICE, pStatusBuff, FRIZE, true);
		break;
	case ZIO:
		pSkill = new Hit_Skill("지오", "150%의 전격 속성 마법데미지, 마나 4 소모, 10%확률로 마비 부여", 150, 4, Object::THUNDER, pStatusBuff, PARALYZE, true);
		break;
	case GARU:
		pSkill = new Hit_Skill("갈", "150%의 질풍 속성 마법데미지, 마나 3 소모", 150, 3, Object::WIND, pStatusBuff, NONE, true);
		break;
	case KOUHA:
		pSkill = new Hit_Skill("코우하", "170%의 빛 속성 마법데미지, 마나 4 소모", 170, 4, Object::LIGHT, pStatusBuff, NONE, true);
		break;
	case EIHA:
		pSkill = new Hit_Skill("에이하", "150%의 어둠 속성 마법데미지, 마나 4 소모, 10%확률로 즉사 부여", 150, 4, Object::DARKNESS, pStatusBuff, INSTANT_DEATH, true);
		break;
	case TARUNDA:
		pStatusBuff[Object::ATK] = true;
		pSkill = new Hit_Skill("타룬다", "3턴간 적의 공격력 감소, 마나 6 소모", 0, 6, Object::NORMAL, pStatusBuff, NONE, false);
		break;
	case RAKUNDA:
		pStatusBuff[Object::DEF] = true;
		pSkill = new Hit_Skill("라쿤다", "3턴간 적의 방어력 감소, 마나 6 소모", 0, 6, Object::NORMAL, pStatusBuff, NONE, false);
		break;
	case SUKUNDA:
		pStatusBuff[Object::LUK] = true;
		pStatusBuff[Object::SPD] = true;
		pSkill = new Hit_Skill("스쿤다", "3턴간 적의 운,스피드 감소, 마나 7 소모", 0, 7, Object::NORMAL, pStatusBuff, NONE, false);
		break;
	default:
		break;
	}
	return pSkill;
}

bool Hit_Skill::Use_Skill(Object* _pCaster, Object* _pTarget)
{
	int iDamage(0), iType(0);
	bool bKillCheck(false);

	cout << _pCaster->Get_Status()->szName << "의 " << m_szName << "!" << endl;
	DELAY(50);

	if (m_iForce != 0)
	{
		if (m_bMagicAtk == false) // 물리공격, 마법공격 비교해 기본데미지 연산
			iDamage = _pCaster->Get_Status()->iAtk;
		else
			iDamage = _pCaster->Get_Status()->iM_Atk;
		iDamage *= m_iForce / 100;

		if (PERCENT(10)) // 크리티컬연산
		{
			cout << "Critical!" << endl;
			DELAY(100);
			iDamage *= 150 / 100;
		}
		else
			iDamage -= _pTarget->Get_Status()->iDef;
		
		if (_pTarget->Get_Status()->pType[m_iType] == 0)
		{
			cout << "Immunity!" << endl;
			DELAY(100);
		}
		else if (_pTarget->Get_Status()->pType[m_iType] == 1)
		{
			cout << "Block!" << endl;
			DELAY(100);
		}
		else if (_pTarget->Get_Status()->pType[m_iType] == 4)
		{
			cout << "Weak!" << endl;
			DELAY(100);
		}
		iDamage *= _pTarget->Get_Status()->pType[m_iType] / 2; // 타입연산

		bKillCheck = _pTarget->Damaged(iDamage);
	}

	for (int i = 2; i < MAX_STATUS; ++i)
	{
		if (m_pStatusBuff[i])
		{
			if (_pTarget->Get_Status()->iBuff == 0)
			{
				_pTarget->Set_iBuff(i, -3);
				cout << _pTarget->Get_Status()->szName << "의" << Status_Name_Render((Object::STATUSNUM)i) << "이(가) 하락했다." << endl;;
			}
			else if (_pTarget->Get_Status()->iBuff < 0)
			{
				_pTarget->Set_iBuff(i, -3);
				cout << _pTarget->Get_Status()->szName << "의" << Status_Name_Render((Object::STATUSNUM)i) << "하락의 지속시간이 증가했다." << endl;;
			}
			else
			{
				_pTarget->Set_iBuff(i, 0);
				cout << _pTarget->Get_Status()->szName << "의" << Status_Name_Render((Object::STATUSNUM)i) << "이(가) 원래대로 돌아왔다. " << endl;;

			}
			DELAY(50);
		}
	}

	if (NONE < m_Effect_Type && m_Effect_Type < CURE && _pTarget->Get_Status()->iEffect == 0)
	{
		if (PERCENT(10))
		{
			_pTarget->Set_iEffect(m_Effect_Type);
			cout << _pTarget->Get_Status()->szName << "은(는)" << Effect_Name_Render(m_Effect_Type) << " 상태가 되었다." << endl;

			if (m_Effect_Type == INSTANT_DEATH)
				bKillCheck = _pTarget->Damaged(9999);
		}
	}

	return bKillCheck;
}
