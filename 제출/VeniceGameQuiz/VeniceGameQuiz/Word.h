#pragma once
#include <iostream>
#include <string>
#include "DrawManager.h"

using namespace std;
class Word
{
private:
	string m_strWord;
	int m_iX;
	int m_iY;
public:
	void SetWord(string str);
	void DrawWord(int posX, int posY);
	void EraseWord(int posX, int posY);

};

