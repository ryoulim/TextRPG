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
		pSkill = new Hit_Skill("����", "100%�� �� �Ӽ� ����������, ���� 0 �Ҹ�", 100, 0 , Object::NORMAL, pStatusBuff, NONE, false);
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
	default:
		break;
	}
	return pSkill;
}

bool Hit_Skill::Use_Skill(Object* _pCaster, Object* _pTarget)
{
	int iDamage(0), iType(0);
	bool bKillCheck(false);

	cout << _pCaster->Get_Status()->szName << "�� " << m_szName << "!" << endl;
	DELAY(50);

	if (m_iForce != 0)
	{
		if (m_bMagicAtk == false) // ��������, �������� ���� �⺻������ ����
			iDamage = _pCaster->Get_Status()->iAtk;
		else
			iDamage = _pCaster->Get_Status()->iM_Atk;
		iDamage *= m_iForce / 100;

		if (PERCENT(10)) // ũ��Ƽ�ÿ���
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
		iDamage *= _pTarget->Get_Status()->pType[m_iType] / 2; // Ÿ�Կ���

		bKillCheck = _pTarget->Damaged(iDamage);
	}

	for (int i = 2; i < MAX_STATUS; ++i)
	{
		if (m_pStatusBuff[i])
		{
			if (_pTarget->Get_Status()->iBuff == 0)
			{
				_pTarget->Set_iBuff(i, -3);
				cout << _pTarget->Get_Status()->szName << "��" << Status_Name_Render((Object::STATUSNUM)i) << "��(��) �϶��ߴ�." << endl;;
			}
			else if (_pTarget->Get_Status()->iBuff < 0)
			{
				_pTarget->Set_iBuff(i, -3);
				cout << _pTarget->Get_Status()->szName << "��" << Status_Name_Render((Object::STATUSNUM)i) << "�϶��� ���ӽð��� �����ߴ�." << endl;;
			}
			else
			{
				_pTarget->Set_iBuff(i, 0);
				cout << _pTarget->Get_Status()->szName << "��" << Status_Name_Render((Object::STATUSNUM)i) << "��(��) ������� ���ƿԴ�. " << endl;;

			}
			DELAY(50);
		}
	}

	if (NONE < m_Effect_Type && m_Effect_Type < CURE && _pTarget->Get_Status()->iEffect == 0)
	{
		if (PERCENT(10))
		{
			_pTarget->Set_iEffect(m_Effect_Type);
			cout << _pTarget->Get_Status()->szName << "��(��)" << Effect_Name_Render(m_Effect_Type) << " ���°� �Ǿ���." << endl;

			if (m_Effect_Type == INSTANT_DEATH)
				bKillCheck = _pTarget->Damaged(9999);
		}
	}

	return bKillCheck;
}