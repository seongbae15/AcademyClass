#pragma once
#include "Student.h"
#include "singleton.h"
#include <vector>
#define MAX 5

class student_manager:public singleton<student_manager>
{
	vector<Student*> m_vectorStList;
public:
	student_manager();
	void RegisterStudent();
	void ShowStInfo();
	void FindNum();
	void FindName();
	void FindGrade();
	~student_manager();
};