#pragma once
#include "Equip_Item.h"
#include "Useable_Item.h"
#include "Other_Item.h"

class Bag
{
public:
	Bag() : m_iKind(0), m_pItem(nullptr), m_pItemCount(nullptr), m_pItemClass(nullptr) { m_iGold = 0; }
	~Bag();

	void Release();

	int Get_iKind() const { return m_iKind; }
	int* Get_pItem() const { return m_pItem; }

	void Initialize(const int _iType);
	void Update(const int _iNum, const int _iCount); // � �������� ��� ������Ű�°�?
	bool Gold_Cal(int _iTmp);

	void Info_Render() const;
	void Gold_Render() const;

	void Sell_Item(const int _iIndex);

	enum BagType {EQUIP,USEABLE,OTHER,END};

	static int m_iGold;

private:
	
	int m_iKind; // ���� ���ϰ��ִ� �������� ������
	int* m_pItem; // �����迭�� ����, ������ ���� ��ȣ ����
	int* m_pItemCount; // �����迭�� ���� ���� �ε������� �������� ��������.
	Item* m_pItemClass;

	void Minus_Array(int _iNum);
	void Plus_Array();
};