#include "Student.h"
Student::Student()
{
	m_iNum = 0;
}
void Student::SetStudent(int number)
{
	cout << "�̸��� �Է� �Ͻÿ� : ";
	cin >> m_strName;
	cout << "3������ ������ �Է��Ͻÿ�" << endl;
	cout << "���� : ";
	cin >> m_iKor;
	cout << "���� : ";
	cin >> m_iEng;
	cout << "���� : ";
	cin >> m_iMath;
	m_iSum = m_iKor + m_iEng + m_iMath;
	m_fAvg = (float)m_iSum / 3;
	m_iNum = number;
	if (m_fAvg >= 90)
		m_chGrade = 'A';
	else if (m_fAvg >= 80)
		m_chGrade = 'B';
	else if (m_fAvg >= 70)
		m_chGrade = 'C';
	else if (m_fAvg >= 60)
		m_chGrade = 'D';
	else
		m_chGrade = 'F';
	return;
}
void Student::ShowStudent()
{
	cout << "-------------------------" << endl;
	cout << m_iNum << " �� �л�" << endl;
	cout << "�̸� : " << m_strName << endl;
	cout << "���� ���� : " << m_iKor << endl;
	cout << "���� ���� : " << m_iEng << endl;
	cout << "���� ���� : " << m_iMath << endl;
	cout << "�հ� ���� : " << m_iSum << "\t ��� ���� : " << m_fAvg << endl;
	cout << "��� : [" << m_chGrade << "]" << endl << endl;
	return;
}