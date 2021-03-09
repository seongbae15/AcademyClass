#include <Windows.h>
#include "Time.h"

Time Register()
{
	int iTmpHour;
	int iTmpMin;
	while (1)
	{
		cout << "시간 : ";
		cin >> iTmpHour;
		if (iTmpHour >= 0)
			break;
		else
			cout << "0보다 큰 수로 다시 입력하세요." << endl;
	}
	while (1)
	{
		cout << "분 : ";
		cin >> iTmpMin;
		if (iTmpMin >= 0)
			break;
		else
			cout << "0보다 큰 수로 다시 입력하세요." << endl;
	}
	Time tmp(iTmpHour, iTmpMin);
	return tmp;
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
		cout << "=====공부 시간 관리 프로그램<" << iDay << "Day>=====" << endl;
		cout << "\t1. 시간 등록" << endl;
		cout << "\t2. 종료" << endl;
		cout << "\t입력 : ";
		cin >> iSelection;
		switch (iSelection)
		{
		case 1:
			StudyTime + Register();
			iDay++;
			break;
		case 2:
			system("cls");
			StudyTime.ShowTime();
			system("pause");
			return;
		default:
			break;
		}
	}
}