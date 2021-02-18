#include "Story.h"

void Story::DrawWord(bool hide_state)
{
	m_stroyDrawManager.DrawMidText(m_strStoryLine, m_iX, m_iY);
}
void Story::EraseWord()
{
	m_stroyDrawManager.EraseMidText(m_strStoryLine, m_iX, m_iY);
}

void Story::SetWord(string str, int posX, int posY)
{
	m_strStoryLine = str;
	m_iX = posX;
	m_iY = posY;
	//m_iX = MAP_WIDTH;
	//m_iY = MAP_HEIGHT*0.2f+1+ AddCol;
}
//void Story::SetWordPos(int posX, int posY)
//{
//	m_iX = posX;
//	m_iY = posY;
//}
void Story::UpadatePosY()
{
	m_iY--;
}
