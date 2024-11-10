#include "pch.h"
#include "Skill.h"

const char* Skill::Status_Name_Render(Object::STATUSNUM _StatusNum) const
{
	switch (_StatusNum)
	{
	case Object::ATK:
		return "���ݷ�";
	case Object::M_ATK:
		return "���� ���ݷ�";
	case Object::DEF:
		return "����";
	case Object::SPD:
		return "���ǵ�";
	case Object::LUK:
		return "��";
	default:
		return "";
	}
}

const char* Skill::Effect_Name_Render(EFFECT_TYPE _EffectType) const
{
	switch (_EffectType)
	{
	case BURN:
		return "ȭ��";
	case FRIZE:
		return "����";
	case PARALYZE:
		return "����";
	case INSTANT_DEATH:
		return "���";
	default:
		return "";
	}
}
