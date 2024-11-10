#include "pch.h"
#include "Skill.h"

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
