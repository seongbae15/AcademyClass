#include "Word.h"

void Word::SetItem(int item_number)
{
	m_iItemNumber = item_number;
}

void Word::DrawTexts(bool hide_state)
{
	if (hide_state == true)
		BLACK
	else
	{
		////Test ¿ë
		//switch ((ITEM_LIST)m_iItemNumber)
		//{
		//case ITEM_LIST_SPEED_UP:
		//	RED
		//	break;
		//case ITEM_LIST_SPEED_DOWN:
		//	GREEN
		//	break;
		//case ITEM_LIST_PAUSE:
		//	BLUE
		//	break;
		//case ITEM_LIST_CLEAR:
		//	YELLOW
		//	break;
		//case ITEM_LIST_HIDE:
		//	ORIGINAL
		//	break;
		//default:
		//	BG_GRAY_TEXT_PURPLE
		//	break;
		//}
		switch ((ITEM_LIST)m_iItemNumber)
		{
		case ITEM_LIST_SPEED_UP:
		case ITEM_LIST_SPEED_DOWN:
		case ITEM_LIST_PAUSE:
		case ITEM_LIST_CLEAR:
		case ITEM_LIST_HIDE:
			RED
			break;
		default:
			BG_GRAY_TEXT_PURPLE
			break;
		}
	}
	m_textDrawManager.TextDraw(m_strText, m_iX, m_iY);
	BG_GRAY_TEXT_PURPLE
}
void Word::EraseText()
{
	BG_GRAY_TEXT_PURPLE
	m_textDrawManager.TextErase(m_strText,m_iX,m_iY);
}