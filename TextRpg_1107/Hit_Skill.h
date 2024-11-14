#pragma once
#include "Skill.h"

class Hit_Skill : public Skill
{
public:
	Hit_Skill(const char* _szName, const char* _szInfo, int _iForce, int _iCost, int _iType, bool* _bStatusBuff, EFFECT_TYPE _Effect_type, bool _bMagicAtk) :
		Skill(_szName, _szInfo, _iForce, _iCost, _iType, _bStatusBuff, _Effect_type), m_bMagicAtk(_bMagicAtk) {}

	bool Use_Skill(Object* _pCaster, Object* _pTarget = nullptr) override;

private:
	bool m_bMagicAtk;
};