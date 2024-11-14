#include "pch.h"
#include "Buff_Item.h"

Item* Buff_Item::Copy()
{
    Buff_Item* pReturn = new Buff_Item(*this);
    pReturn->m_pBuffStatus = new int[MAX_STATUS];
    memcpy_s(pReturn->m_pBuffStatus, sizeof(int) * MAX_STATUS, m_pBuffStatus, sizeof(int) * MAX_STATUS);
    return static_cast<Item*>(pReturn);
}
