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
	void SetWord(string str, int posX, int posY);

	//void SetWordPos(int posX, int posY);
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

