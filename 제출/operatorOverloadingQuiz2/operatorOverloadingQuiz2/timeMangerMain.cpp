#include <Windows.h>
#include "Time.h"

void Register()
{
	int iTmpHour;
	int iTmpMin;
	cout << "시간 : ";
	cin >> iTmpHour;
	cout << "분 : ";
	cin >> iTmpMin;
	Time tmp(iTmpHour, iTmpMin);
}

void main()
{
	Time StudyTime;
	int iSelection;
	int iDay = 1;

	while (1)
	{
		system("cls");
		StudyTime.ShowTime();
		cout << "=====공부 시간 관리 프로그램<"<<iDay <<"Day>=====";
		cout << "\t\t 1. 시간 등록" << endl;
		cout << "\t\t 2. 종료" << endl;
		cout << "입력 : ";
		cin >> iSelection;
		switch (iSelection)
		{
		case 1:
			Register();
			break;
		case 2:
			return;
		default:
			break;
		}
	}
}