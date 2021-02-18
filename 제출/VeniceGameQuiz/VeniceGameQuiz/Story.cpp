#include "Story.h"

void Story::DrawWord(bool hide_state)
{
	m_stroyDrawManager.DrawMidText(m_strStoryLine, m_iX, m_iY);
}
void Story::EraseWord()
{
	m_stroyDrawManager.EraseMidText(m_strStoryLine, m_iX, m_iY);
}

void Story::SetWord(string str, int AddCol)
{
	m_strStoryLine = str;
	m_iX = MAP_WIDTH;
	m_iY = MAP_HEIGHT*0.2f+1+ AddCol;
}
void Story::UpadatePosY()
{
	m_iY--;
}
