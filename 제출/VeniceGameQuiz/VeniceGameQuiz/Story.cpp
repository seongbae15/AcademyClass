#include "Story.h"

void Story::DrawTexts(bool hide_state)
{
	m_textDrawManager.DrawMidText(m_strText, m_iX, m_iY);
}
void Story::EraseText()
{
	m_textDrawManager.EraseMidText(m_strText, m_iX, m_iY);
}
