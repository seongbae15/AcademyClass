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
	bool m_bVisionState;
	DrawManager m_wordDrawManager;
public:
	void SetWord(string str);
	void SetWordPos(int posX, int posY);
	void UpadatePosY();
	void DrawWord();
	void EraseWord();
	inline string GetWord()
	{
		return m_strWord;
	}
	inline int GetWordPosY()
	{
		return m_iY;
	}
	inline int GetWordPosX()
	{
		return m_iX;
	}
	inline bool GetVisionState()
	{
		return m_bVisionState;
	}
};

