#pragma once
#include "Lib.h"
#include "DrawManager.h"
#include "Text.h"

enum ITEM_LIST
{
	ITEM_LIST_START = 1,
	ITEM_LIST_SPEED_UP = 1,
	ITEM_LIST_SPEED_DOWN,
	ITEM_LIST_PAUSE,
	ITEM_LIST_CLEAR,
	ITEM_LIST_HIDE = 5,
	ITEM_LIST_END = 5,
};

class Word:public Text
{
private:
	bool m_bVisionState;
	int m_iItemNumber;
public:
	void DrawTexts(bool hide_state = false);
	void EraseText();
	void SetItem(int item_number=0);
	inline bool GetVisionState()
	{
		return m_bVisionState;
	}
	inline int GetItemNumber()
	{
		return m_iItemNumber;
	}
};

