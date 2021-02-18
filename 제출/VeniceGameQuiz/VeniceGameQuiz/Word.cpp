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

void Word::SetItem(int item_number)
{
	m_iItemNumber = item_number;

}


void Word::DrawWord(bool hide_state)
{
	if (hide_state == true)
		BLACK
	else
	{
		//Test ¿ë
		switch ((ITEM_LIST)m_iItemNumber)
		{
		case ITEM_LIST_NONE:
			BG_GRAY_TEXT_PURPLE
			break;
		case ITEM_LIST_SPEED_UP:
			RED
			break;
		case ITEM_LIST_SPEED_DOWN:
			GREEN
			break;
		case ITEM_LIST_PAUSE:
			BLUE
			break;
		case ITEM_LIST_CLEAR:
			YELLOW
			break;
		case ITEM_LIST_HIDE:
			ORIGINAL
			break;
		default:
			BG_GRAY_TEXT_PURPLE
			break;
		}
		//if (m_iItemNumber != 0)
		//	RED
		//else
		//	BG_GRAY_TEXT_PURPLE
	}
	m_wordDrawManager.TextDraw(m_strWord, m_iX, m_iY);
	BG_GRAY_TEXT_PURPLE
}
void Word::EraseWord()
{
	BG_GRAY_TEXT_PURPLE
	m_wordDrawManager.TextErase(m_strWord,m_iX,m_iY);
}
void Word::UpadatePosY()
{
	m_iY++;
}