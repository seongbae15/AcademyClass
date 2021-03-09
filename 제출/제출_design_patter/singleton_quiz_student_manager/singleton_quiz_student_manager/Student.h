#pragma once
#include <iostream>
#include <string>
using namespace std;
class Student
{
private:
	string m_strName;
	int m_iKor, m_iMath, m_iEng, m_iSum;
	float m_fAvg;
	int m_iNum;
	char m_chGrade;
public:
	Student();
	~Student()
	{
	}
	void SetStudent(int num);
	void ShowStudent();
	inline int GetNum()
	{
		return m_iNum;
	}
	inline string GetName()
	{
		return m_strName;
	}
	inline char GetGrade()
	{
		return m_chGrade;
	}
};

