#include "Student.h"
Student::Student()
{
	m_iNum = 0;
}
void Student::SetStudent(int number)
{
	cout << "이름을 입력 하시오 : ";
	cin >> m_strName;
	cout << "3과목의 점수를 입력하시오" << endl;
	cout << "국어 : ";
	cin >> m_iKor;
	cout << "영어 : ";
	cin >> m_iEng;
	cout << "수학 : ";
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
	cout << m_iNum << " 번 학생" << endl;
	cout << "이름 : " << m_strName << endl;
	cout << "국어 점수 : " << m_iKor << endl;
	cout << "영어 점수 : " << m_iEng << endl;
	cout << "수학 점수 : " << m_iMath << endl;
	cout << "합계 점수 : " << m_iSum << "\t 평균 점수 : " << m_fAvg << endl;
	cout << "등급 : [" << m_chGrade << "]" << endl << endl;
	return;
}