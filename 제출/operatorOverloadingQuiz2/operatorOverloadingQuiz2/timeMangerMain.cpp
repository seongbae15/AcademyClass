#include <Windows.h>
#include "Time.h"

void Register()
{
	int iTmpHour;
	int iTmpMin;
	cout << "�ð� : ";
	cin >> iTmpHour;
	cout << "�� : ";
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
		cout << "=====���� �ð� ���� ���α׷�<"<<iDay <<"Day>=====";
		cout << "\t\t 1. �ð� ���" << endl;
		cout << "\t\t 2. ����" << endl;
		cout << "�Է� : ";
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