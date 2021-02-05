#include "Time.h"

Time::Time()
{
	m_iHour = 0;
	m_iMin = 0;
}
Time::Time(int Hour, int Min)
{
	m_iHour = Hour;
	m_iMin = Min;
}
void Time::ShowTime()
{
	cout << "ÃÑ °øºÎ ½Ã°£ : " << m_iHour << " : " <<m_iMin << endl;
}

Time Time::operator+(Time calTime)
{
	this->m_iMin += calTime.m_iMin;
	if (this->m_iMin >= MINUTE)
	{
		int tmp = this->m_iMin / MINUTE;

		this->m_iMin %= MINUTE;
		this->m_iHour += tmp;
	}
	this->m_iHour += calTime.m_iHour;
	return *this;
}

Time::~Time()
{

}