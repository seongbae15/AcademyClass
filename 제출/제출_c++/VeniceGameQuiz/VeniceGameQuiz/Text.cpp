#include "Text.h"
void Text::SetText(string str, int posX, int posY)
{
	m_strText = str;
	m_iX = posX;
	m_iY = posY;
}

void Text::SetTextPos(int posX, int posY)
{
	m_iX = posX;
	m_iY = posY;
}
void Text::UpadatePosY(int dirY)
{
	if (dirY == Y_DOWN)
		m_iY++;
	else if (dirY == Y_UP)
		m_iY--;
}