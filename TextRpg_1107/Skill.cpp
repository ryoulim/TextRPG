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
		pSkill = new Hit_Skill("����", "100%�� �� �Ӽ� ����������, ���� 0 �Ҹ�", 100, 0, Object::NORMAL, pStatusBuff, NONE, false);
		break;
	case SLASH:
		pSkill = new Hit_Skill("������", "150%�� �� �Ӽ� ����������, ���� 3 �Ҹ�", 150, 3, Object::NORMAL, pStatusBuff, NONE, false);
		break;
	case AGI:
		pSkill = new Hit_Skill("�Ʊ�", "150%�� ȭ�� �Ӽ� ����������, ���� 3 �Ҹ�, 10%Ȯ���� ȭ�� �ο�", 150, 3, Object::FIRE, pStatusBuff, BURN, true);
		break;
	case BUFU:
		pSkill = new Hit_Skill("����", "150%�� ���� �Ӽ� ����������, ���� 4 �Ҹ�, 10%Ȯ���� ���� �ο�", 150, 4, Object::ICE, pStatusBuff, FRIZE, true);
		break;
	case ZIO:
		pSkill = new Hit_Skill("����", "150%�� ���� �Ӽ� ����������, ���� 4 �Ҹ�, 10%Ȯ���� ���� �ο�", 150, 4, Object::THUNDER, pStatusBuff, PARALYZE, true);
		break;
	case GARU:
		pSkill = new Hit_Skill("��", "150%�� ��ǳ �Ӽ� ����������, ���� 3 �Ҹ�", 150, 3, Object::WIND, pStatusBuff, NONE, true);
		break;
	case KOUHA:
		pSkill = new Hit_Skill("�ڿ���", "170%�� �� �Ӽ� ����������, ���� 4 �Ҹ�", 170, 4, Object::LIGHT, pStatusBuff, NONE, true);
		break;
	case EIHA:
		pSkill = new Hit_Skill("������", "150%�� ��� �Ӽ� ����������, ���� 4 �Ҹ�, 10%Ȯ���� ��� �ο�", 150, 4, Object::DARKNESS, pStatusBuff, INSTANT_DEATH, true);
		break;
	case TARUNDA:
		pStatusBuff[Object::ATK] = true;
		pSkill = new Hit_Skill("Ÿ���", "3�ϰ� ���� ���ݷ� ����, ���� 6 �Ҹ�", 0, 6, Object::NORMAL, pStatusBuff, NONE, false);
		break;
	case RAKUNDA:
		pStatusBuff[Object::DEF] = true;
		pSkill = new Hit_Skill("�����", "3�ϰ� ���� ���� ����, ���� 6 �Ҹ�", 0, 6, Object::NORMAL, pStatusBuff, NONE, false);
		break;
	case SUKUNDA:
		pStatusBuff[Object::LUK] = true;
		pStatusBuff[Object::SPD] = true;
		pSkill = new Hit_Skill("�����", "3�ϰ� ���� ��,���ǵ� ����, ���� 7 �Ҹ�", 0, 7, Object::NORMAL, pStatusBuff, NONE, false);
		break;
	case DIA:
		pSkill = new Cure_Skill("���", "HP 30% ȸ��,���� 3 �Ҹ�", 30, 3, Object::HEAL, pStatusBuff, NONE);
		break;
	case AMRITADROP:
		pSkill = new Cure_Skill("�ϸ�Ÿ���", "��� �����̻� ����,���� 8 �Ҹ�", 30, 3, Object::NORMAL, pStatusBuff, CURE);
		break;
	case TARUKAJA:
		pStatusBuff[Object::ATK] = true;
		pSkill = new Cure_Skill("Ÿ��ī��", "3�ϰ� �Ʊ��� ���ݷ� ����, ���� 6 �Ҹ�", 0, 6, Object::NORMAL, pStatusBuff, NONE);
		break;
	case RAKUKAJA:
		pStatusBuff[Object::DEF] = true;
		pSkill = new Cure_Skill("����ī��", "3�ϰ� �Ʊ��� ���� ����, ���� 6 �Ҹ�", 0, 6, Object::NORMAL, pStatusBuff, NONE);
		break;
	case SUKUKAJA:
		pStatusBuff[Object::LUK] = true;
		pStatusBuff[Object::SPD] = true;
		pSkill = new Cure_Skill("����ī��", "3�ϰ� �Ʊ��� ��,���ǵ� ����, ���� 6 �Ҹ�", 0, 6, Object::NORMAL, pStatusBuff, NONE);
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
