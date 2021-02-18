#pragma once
#include <iostream>
#include <string>
#include "DrawManager.h"

enum ITEM_LIST
{
	ITEM_LIST_NONE = 0,
	ITEM_LIST_START = 1,
	ITEM_LIST_SPEED_UP = 1,
	ITEM_LIST_SPEED_DOWN,
	ITEM_LIST_PAUSE,
	ITEM_LIST_CLEAR,
	ITEM_LIST_HIDE = 5,
	ITEM_LIST_END = 5,
};

using namespace std;
class Word
{
private:
	string m_strWord;
	int m_iX;
	int m_iY;
	bool m_bVisionState;
	int m_iItemNumber;
	DrawManager m_wordDrawManager;
public:
	void SetWord(string str);
	void SetWordPos(int posX, int posY);
	void UpadatePosY();
	void DrawWord(bool hide_state =false);
	void EraseWord();
	void SetItem(int item_number=0);
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
	inline int GetItemNumber()
	{
		return m_iItemNumber;
	}
};

