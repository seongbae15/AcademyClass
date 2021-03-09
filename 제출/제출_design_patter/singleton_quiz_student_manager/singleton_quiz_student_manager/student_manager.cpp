#include "student_manager.h"

student_manager* student_manager::m_pThis = NULL;

student_manager::student_manager()
{
	for (int i = 0; i < MAX; i++)
	{
		m_vectorStList.push_back(new Student);
	}
}
student_manager::~student_manager()
{
	m_vectorStList.clear();
	//for (int i = 0; i < MAX; i++)
	//	delete m_vectorStList[i];
}

void student_manager::RegisterStudent()
{
	for (int i = 0; i < MAX; i++)
	{
		if (m_vectorStList[i]->GetNum() == 0)
		{
			m_vectorStList[i]->SetStudent(i + 1);
			return;
		}
	}
	cout << "�л��� ���� ��� �Ǿ����ϴ�." << endl;
}

void student_manager::ShowStInfo()
{
	for (int i = 0; i < MAX; i++)
	{
		if (m_vectorStList[i]->GetNum() != 0)
		{
			m_vectorStList[i]->ShowStudent();
		}
		else
			return;
	}
}

void student_manager::FindNum()
{
	int iFind;
	cout << "ã�� �л��ǹ�ȣ�� �Է� �Ͻÿ� : ";
	cin >> iFind;
	for (int i = 0; i < MAX; i++)
	{
		if (m_vectorStList[i]->GetNum() == iFind)
		{
			m_vectorStList[i]->ShowStudent();
			return;
		}
	}
	cout << endl << "�ش� ��ȣ�� �л��� �����ϴ�." << endl;
}

void student_manager::FindName()
{
	string strFind;
	int iFindCount=0;
	cout << "ã�� �л����̸��� �Է� �Ͻÿ� : ";
	cin >> strFind;
	for (int i = 0; i < MAX; i++)
	{
		if (m_vectorStList[i]->GetName() == strFind)
		{
			m_vectorStList[i]->ShowStudent();
			iFindCount++;
		}
	}
	if(iFindCount == 0)
		cout << "�ش� �̸��� �л��� �����ϴ�." << endl;
}
void student_manager::FindGrade()
{
	int iFindCount = 0;
	cout << "========= [ A ] =========" << endl;
	for (int i = 0; i < MAX; i++)
	{
		if (m_vectorStList[i]->GetGrade() == 'A')
		{
			m_vectorStList[i]->ShowStudent();
			iFindCount++;
		}
	}
	cout << "�� " << iFindCount << "��" << endl;
	cout << "=========================" << endl << endl << endl;
	iFindCount = 0;
	cout << "========= [ B ] =========" << endl;
	for (int i = 0; i < MAX; i++)
	{
		if (m_vectorStList[i]->GetGrade() == 'B')
		{
			m_vectorStList[i]->ShowStudent();
			iFindCount++;
		}
	}
	cout << "�� " << iFindCount << "��" << endl;
	cout << "=========================" << endl << endl << endl;
	iFindCount = 0;
	cout << "========= [ C ] =========" << endl;
	for (int i = 0; i < MAX; i++)
	{
		if (m_vectorStList[i]->GetGrade() == 'C')
		{
			m_vectorStList[i]->ShowStudent();
			iFindCount++;
		}
	}
	cout << "�� " << iFindCount << "��" << endl;
	cout << "=========================" << endl << endl << endl;
	iFindCount = 0;
	cout << "========= [ D ] =========" << endl;
	for (int i = 0; i < MAX; i++)
	{
		if (m_vectorStList[i]->GetGrade() == 'D')
		{
			m_vectorStList[i]->ShowStudent();
			iFindCount++;
		}
	}
	cout << "�� " << iFindCount << "��" << endl;
	cout << "=========================" << endl << endl << endl;
	iFindCount = 0;
	cout << "========= [ F ] =========" << endl;
	for (int i = 0; i < MAX; i++)
	{
		if (m_vectorStList[i]->GetGrade() == 'D')
		{
			m_vectorStList[i]->ShowStudent();
			iFindCount++;
		}
	}
	cout << "�� " << iFindCount << "��" << endl;
	cout << "=========================" << endl << endl << endl;
}