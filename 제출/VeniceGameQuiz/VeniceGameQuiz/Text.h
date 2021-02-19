#pragma once
#include "Lib.h"
#include "DrawManager.h"

#define Y_UP -1
#define Y_DOWN 1

class Text
{
protected:
	string m_strText;
	int m_iX;
	int m_iY;
	DrawManager m_textDrawManager;
public:
	void UpadatePosY(int dirY);
	void SetText(string str, int posX = 0, int posY = 0);
	void SetTextPos(int posX, int posY);
	inline string GetText()
	{
		return m_strText;
	}
	inline int GetTextPosY()
	{
		return m_iY;
	}
	inline int GetTextPosX()
	{
		return m_iX;
	}
};

