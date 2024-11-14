#include "pch.h"
#include "Skill.h"

#include "Hit_Skill.h"
#include "Cure_Skill.h"


Skill* Skill::Create_Skill(SKILL_LIST _SkillList)
{
	Skill* pSkill = nullptr;
	bool* pStatusBuff = new bool[MAX_STATUS];
	memset(pStatusBuff, false, sizeof(bool) * MAX_STATUS);

	switch (_SkillList)
	{
	case ATTACK:
		pSkill = new Hit_Skill("공격", "100%의 무 속성 물리데미지, 마나 0 소모", 100, 0, Object::NORMAL, pStatusBuff, NONE, false);
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
	return pSkill;
}

const char* Skill::Status_Name_Render(Object::STATUSNUM _StatusNum) const
{
	switch (_StatusNum)
	{
	case Object::ATK:
		return "공격력";
	case Object::M_ATK:
		return "마법 공격력";
	case Object::DEF:
		return "방어력";
	case Object::SPD:
		return "스피드";
	case Object::LUK:
		return "운";
	default:
		return "";
	}
}

const char* Skill::Effect_Name_Render(EFFECT_TYPE _EffectType) const
{
	switch (_EffectType)
	{
	case BURN:
		return "화상";
	case FRIZE:
		return "빙결";
	case PARALYZE:
		return "마비";
	case INSTANT_DEATH:
		return "즉사";
	default:
		return "";
	}
}
