#pragma once
#include <iostream>
#include <string>
#include "DrawManager.h"
using namespace std;
class Story
{
private:
	string m_strStoryLine;
	int m_iX;
	int m_iY;
	DrawManager m_stroyDrawManager;
public:
	void DrawWord(bool hide_state = false);
	void EraseWord();
	void SetWord(string str, int AddCol=0);
	void UpadatePosY();
	inline string GetWord()
	{
		return m_strStoryLine;
	}
	inline int GetWordPosY()
	{
		return m_iY;
	}
	inline int GetWordPosX()
	{
		return m_iX;
	}
};

