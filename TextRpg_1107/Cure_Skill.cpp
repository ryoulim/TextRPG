#include "pch.h"
#include "Cure_Skill.h"

//enum CURE_SKILL_LIST { DIA, AMRITADROP };
//enum BUFF_SKILL_LIST { TARUKAJA = AMRITADROP + 1, RAKUKAJA, SUKUKAJA };

	// �����ؾ��Ұ�
	// 1. �����̻� ��� ġ������ ����ȭ
	// 2. ť�ų�� ���� Ÿ���� �ʿ��Ѱ�?


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
				cout << _pCaster->Get_Status()->szName << "��" << Status_Name_Render((Object::STATUSNUM)i) << "��(��) �����ߴ�." << endl;;
			}
			else if (_pCaster->Get_Status()->iBuff < 0)
			{
				_pCaster->Set_iBuff(i, 0);
				cout << _pCaster->Get_Status()->szName << "��" << Status_Name_Render((Object::STATUSNUM)i) << "��(��) ������� ���ƿԴ�. " << endl;;
			}
			else
			{
				_pCaster->Set_iBuff(i, 3);
				cout << _pCaster->Get_Status()->szName << "��" << Status_Name_Render((Object::STATUSNUM)i) << "������ ���ӽð��� �����ߴ�." << endl;;
			}
			DELAY(50);
		}
	}

	if (m_Effect_Type == CURE)
	{
		if (_pCaster->Get_Status()->iEffect != 0)
			cout << _pCaster->Get_Status()->szName << "�� " << Effect_Name_Render(EFFECT_TYPE(_pCaster->Get_Status()->iEffect / 10)) << "��(��) ȸ���Ǿ���." << endl;
		else
			cout << _pCaster->Get_Status()->szName << "�� �ǰ��� �����̴�." << endl;
		DELAY(50);
	}

	return false;
}
