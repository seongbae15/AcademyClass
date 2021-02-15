#include "Word.h"

void Word::SetWord(string str)
{
	m_strWord = str;
	m_bVisionState = true;
}

void Word::SetWordPos(int posX, int posY)
{
	m_iX = posX;
	m_iY = posY;
}

void Word::DrawWord()
{
	m_wordDrawManager.TextDraw(m_strWord, m_iX, m_iY);
}
void Word::EraseWord()
{
	m_wordDrawManager.TextErase(m_strWord,m_iX,m_iY);
}
void Word::UpadatePosY()
{
	m_iY++;
}