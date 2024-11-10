#pragma once
#include "Object.h"

class Monster : public Object
{
public:
	static Object* Create_Monster(const int _iFloor);

	void Info_Render() const override;
	void Info_Render_Detail() const override;

	//enum MONSTER_LIST {};

private:

};

