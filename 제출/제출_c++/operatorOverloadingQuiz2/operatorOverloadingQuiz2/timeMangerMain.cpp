#include <Windows.h>
#include "Time.h"

Time Register()
{
	int iTmpHour;
	int iTmpMin;
	while (1)
	{
		cout << "�ð� : ";
		cin >> iTmpHour;
		if (iTmpHour >= 0)
			break;
		else
			cout << "0���� ū ���� �ٽ� �Է��ϼ���." << endl;
	}
	while (1)
	{
		cout << "�� : ";
		cin >> iTmpMin;
		if (iTmpMin >= 0)
			break;
		else
			cout << "0���� ū ���� �ٽ� �Է��ϼ���." << endl;
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
		cout << "=====���� �ð� ���� ���α׷�<" << iDay << "Day>=====" << endl;
		cout << "\t1. �ð� ���" << endl;
		cout << "\t2. ����" << endl;
		cout << "\t�Է� : ";
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