#include "student_manager.h"
#include <Windows.h>

void main()
{
	int iSelection;
	while (1)
	{
		cout << "=========================" << endl;
		cout << "   1.�л� ���" << endl;
		cout << "   2.��ü �л����� ���" << endl;
		cout << "   3.�л� ��ȣ �˻�" << endl;
		cout << "   4.�л� �̸� �˻�" << endl;
		cout << "   5.��޺� ���" << endl;
		cout << "   0.����" << endl;
		cout << "=========================" << endl;
		cin >> iSelection;
		switch (iSelection)
		{
		case 1:
			student_manager::GetInstance()->RegisterStudent();
			break;
		case 2:
			student_manager::GetInstance()->ShowStInfo();
			break;
		case 3:
			student_manager::GetInstance()->FindNum();
			break;
		case 4:
			student_manager::GetInstance()->FindName();
			break;
		case 5:
			student_manager::GetInstance()->FindGrade();
			break;
		case 0:
			student_manager::GetInstance()->ReleaseInstance();
			return;
		default:
			cout << "�߸� �Է� " << endl;
			break;
		}
		system("pause");
		system("cls");
	}
}