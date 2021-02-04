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