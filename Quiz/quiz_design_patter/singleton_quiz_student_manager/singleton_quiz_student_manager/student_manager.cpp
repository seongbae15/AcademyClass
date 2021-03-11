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
	cout << "학생이 전원 등록 되었습니다." << endl;
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
	cout << "찾을 학생의번호를 입력 하시오 : ";
	cin >> iFind;
	for (int i = 0; i < MAX; i++)
	{
		if (m_vectorStList[i]->GetNum() == iFind)
		{
			m_vectorStList[i]->ShowStudent();
			return;
		}
	}
	cout << endl << "해당 번호의 학생이 없습니다." << endl;
}

void student_manager::FindName()
{
	string strFind;
	int iFindCount=0;
	cout << "찾을 학생의이름을 입력 하시오 : ";
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
		cout << "해당 이름의 학생이 없습니다." << endl;
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
	cout << "총 " << iFindCount << "명" << endl;
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
	cout << "총 " << iFindCount << "명" << endl;
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
	cout << "총 " << iFindCount << "명" << endl;
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
	cout << "총 " << iFindCount << "명" << endl;
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
	cout << "총 " << iFindCount << "명" << endl;
	cout << "=========================" << endl << endl << endl;
}