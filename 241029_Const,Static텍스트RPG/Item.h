#pragma once
#include "Define.h"

class Object;

class Item
{
public:

	virtual const char* Get_Name(const int _iItemNum) const = 0;
	virtual const char* Get_Info(const int _iItemNum) const = 0;
	virtual int Get_Cost(const int _iItemNum) const = 0;
	virtual bool Use_Item(Object* _pObject) const = 0; // 만약 소모아이템의 기능이 더 추가된다면? 이클래스에 하위 함수를 만들고 이 함수에서는 각각 함수로 연결해주는 역할
	// static, const 동시사용 불가, 스태틱에서 어짜피 멤버변수(함수)에 접근을 못하니까 붙이는게 의미 없는듯?
};