#include "pch.h"
#include "Buff_Item.h"

#define PBUFFSTATUS(_HP,_MP,_ATK,_M_ATK,_DEF,_SPD,_LUK) \
pBuffStatus[Object::HP] = (_HP); \
pBuffStatus[Object::MP] = (_MP);\
pBuffStatus[Object::ATK] = (_ATK); \
pBuffStatus[Object::M_ATK] = (_M_ATK); \
pBuffStatus[Object::DEF] = (_DEF); \
pBuffStatus[Object::SPD] = (_SPD); \
pBuffStatus[Object::LUK] = (_LUK)

Item* Buff_Item::Create_Item(const int _iItemNum)
{
    Item* pItem = nullptr;
    int* pBuffStatus = new int[MAX_STATUS];

    switch (_iItemNum)
    {
    case ATKUP:
        PBUFFSTATUS(0, 0, 3, 0, 0, 0, 0);
        pItem = new Buff_Item("어택 업", "3턴간 공격력 증가", 15, pBuffStatus);
        break;
    case DEFUP:
        PBUFFSTATUS(0, 0, 0, 3, 0, 0, 0);
        pItem = new Buff_Item("디펜스 업", "3턴간 방어력 증가", 15, pBuffStatus);
        break;
    default:
        break;
    }
    return pItem;
}

Item* Buff_Item::Copy()
{
    Buff_Item* pReturn = new Buff_Item(*this);
    pReturn->m_pBuffStatus = new int[MAX_STATUS];
    memcpy_s(pReturn->m_pBuffStatus, sizeof(int) * MAX_STATUS, m_pBuffStatus, sizeof(int) * MAX_STATUS);
    return static_cast<Item*>(pReturn);
}
