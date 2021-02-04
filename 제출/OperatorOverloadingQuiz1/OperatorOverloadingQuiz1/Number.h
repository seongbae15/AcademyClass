#pragma once
#include <iostream>
using namespace std;
class Number
{
private:
	int m_iX, m_iY;
public:
	Number();
	Number(int num1, int num2);
	Number operator / (Number N);
	void ShowNum();
	inline int GetX()
	{
		return m_iX;
	}
	inline int GetY()
	{
		return m_iY;
	}

};

