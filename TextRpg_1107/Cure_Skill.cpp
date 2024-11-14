#include "pch.h"
#include "Cure_Skill.h"

//enum CURE_SKILL_LIST { DIA, AMRITADROP };
//enum BUFF_SKILL_LIST { TARUKAJA = AMRITADROP + 1, RAKUKAJA, SUKUKAJA };

	// 수정해야할것
	// 1. 상태이상 어떤걸 치료할지 세분화
	// 2. 큐어스킬에 과연 타입이 필요한가?


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
