#include "student_manager.h"
#include <Windows.h>

void main()
{
	student_manager std_Manager;
	int iSelection;
	while (1)
	{
		cout << "=========================" << endl;
		cout << "   1.학생 등록" << endl;
		cout << "   2.전체 학생정보 출력" << endl;
		cout << "   3.학생 번호 검색" << endl;
		cout << "   4.학생 이름 검색" << endl;
		cout << "   5.등급별 출력" << endl;
		cout << "   0.종료" << endl;
		cout << "=========================" << endl;
		cin >> iSelection;
		switch (iSelection)
		{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 0:
			return;
		default:cout << "잘못 입력 " << endl;

		}
		system("pause"); system("cls");
	}
}