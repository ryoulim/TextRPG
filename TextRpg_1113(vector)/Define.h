#pragma once

template<typename T>
void Safe_Delete(T temp)
{
	if (temp != nullptr)
	{
		delete temp;
		temp = nullptr;
	}
}

template<typename T>
void Safe_Delete_Array(T temp)
{
	if (temp != nullptr)
	{
		delete[] temp;
		temp = nullptr;
	}
}