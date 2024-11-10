#pragma once
#include "Define.h"

class Object;

class Item
{
public:

	virtual const char* Get_Name(const int _iItemNum) const = 0;
	virtual const char* Get_Info(const int _iItemNum) const = 0;
	virtual int Get_Cost(const int _iItemNum) const = 0;
	virtual bool Use_Item(Object* _pObject) const = 0; // ���� �Ҹ�������� ����� �� �߰��ȴٸ�? ��Ŭ������ ���� �Լ��� ����� �� �Լ������� ���� �Լ��� �������ִ� ����
	// static, const ���û�� �Ұ�, ����ƽ���� ��¥�� �������(�Լ�)�� ������ ���ϴϱ� ���̴°� �ǹ� ���µ�?
};