#pragma once
#include <iostream>
#define MINUTE 60
using namespace std;
class Time
{
private:
	int m_iHour;
	int m_iMin;
public:
	void ShowTime();
	Time operator + (Time time);
	Time();
	Time(int Hour, int Min);
	~Time();

};

