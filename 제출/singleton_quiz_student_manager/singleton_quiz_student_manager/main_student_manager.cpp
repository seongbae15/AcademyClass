#include "student_manager.h"
#include <Windows.h>

void main()
{
	student_manager std_Manager;
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
		case 2:
		case 3:
		case 4:
		case 5:
		case 0:
			return;
		default:cout << "�߸� �Է� " << endl;

		}
		system("pause"); system("cls");
	}
}