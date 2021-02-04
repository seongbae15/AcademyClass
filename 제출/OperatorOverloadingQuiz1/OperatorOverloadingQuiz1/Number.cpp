#include "Number.h"
Number::Number()
{

}
Number::Number(int num1, int num2)
{
	m_iX = num1;
	m_iY = num2;
}

Number Number::operator/(Number N)
{
	Number tmp;
	if (this->m_iX >= N.m_iX)
		tmp.m_iX = this->m_iX / N.m_iX;
	else
		tmp.m_iX = N.m_iX / this->m_iX;
	if (this->m_iY >= N.m_iY)
		tmp.m_iY = this->m_iY / N.m_iY;
	else
		tmp.m_iY = N.m_iY / this->m_iY;
	return tmp;
}
void Number:: ShowNum()
{
	cout << "x = " << m_iX << ", y = " << m_iY << endl;
}