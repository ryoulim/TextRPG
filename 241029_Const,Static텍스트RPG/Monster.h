#pragma once
#include "Define.h"
#include "Object.h"

class Monster : public Object
{
public:
	Monster() : m_iGold(0), m_iDropItem(0) {}
	~Monster();

	void Initialize(const int _iNum);
	void Info_Render() const;
	int Get_Gold() const { return m_iGold; }
	int Get_iDropItem() const { return m_iDropItem; }
	void Release();

	enum MONNUM {MONSTER1 = 1,MONSTER2,MONSTER3,END};

private:
	int m_iGold;
	int m_iDropItem;
};

