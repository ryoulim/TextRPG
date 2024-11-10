#pragma once
#include "Skill.h"

class Cure_Skill : public Skill
{
public:

	static Skill* Create_Skill(const int _iSkillNum);
	bool Use_Skill(Object* _pCaster, Object* _pTarget = nullptr) override;

private:
	Cure_Skill(const char* _szName, const char* _szInfo, int _iForce, int _iCost, int _iType, bool* _bStatusBuff, EFFECT_TYPE _Effect_type) :
		Skill(_szName, _szInfo,_iForce, _iCost, _iType, _bStatusBuff, _Effect_type) {}

};