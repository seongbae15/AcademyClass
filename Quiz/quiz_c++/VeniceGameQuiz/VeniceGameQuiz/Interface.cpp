#include "Interface.h"

void Interface::DispLobyScreen(int Mode)
{
		if (Mode == TEXT_MODE_DRAW)
		{
			BG_GRAY_TEXT_BLUE_GREEN
				m_ifDrawManager.BoxDraw(0, 0, MAP_WIDTH, MAP_HEIGHT);
			BG_GRAY_TEXT_PURPLE
			m_ifDrawManager.DrawMidText("☆ ★ 베 네 치 아 ★ ☆", MAP_WIDTH, MAP_HEIGHT * 0.2f);
			m_ifDrawManager.DrawMidText("1. Game Start", MAP_WIDTH, MAP_HEIGHT * 0.4f);
			m_ifDrawManager.DrawMidText("2. Rank", MAP_WIDTH, MAP_HEIGHT * 0.4f + LOBY_ADD_COL);
			m_ifDrawManager.DrawMidText("3. Exit", MAP_WIDTH, MAP_HEIGHT * 0.4f + 2 * LOBY_ADD_COL);
		}
		else if (Mode == TEXT_MODE_ERASE)
		{
			BG_GRAY_TEXT_PURPLE
			m_ifDrawManager.EraseMidText("☆ ★ 베 네 치 아 ★ ☆", MAP_WIDTH, MAP_HEIGHT * 0.2f);
			m_ifDrawManager.EraseMidText("1. Game Start", MAP_WIDTH, MAP_HEIGHT * 0.4f);
			m_ifDrawManager.EraseMidText("2. Rank", MAP_WIDTH, MAP_HEIGHT * 0.4f + LOBY_ADD_COL);
			m_ifDrawManager.EraseMidText("3. Exit", MAP_WIDTH, MAP_HEIGHT * 0.4f + 2 * LOBY_ADD_COL);
		}
	ORIGINAL
}
void Interface::DispStoryScreen()
{
	BG_GRAY_TEXT_PURPLE
		m_ifDrawManager.BoxDraw(MAP_WIDTH, MAP_HEIGHT * 0.8f - 4, SMALL_BOX_WIDTH, SMALL_BOX_HEIGHT);
	m_ifDrawManager.DrawMidText("Skip : S", MAP_WIDTH, MAP_HEIGHT * 0.8f - 2);
}
void Interface::DispNameInputScreen(int Mode)
{
	if (Mode == TEXT_MODE_DRAW)
	{
		m_ifDrawManager.DrawMidText("이름 입력", MAP_WIDTH, MAP_HEIGHT * 0.4f + 2);
		m_ifDrawManager.EraseMidText("Skip : S", MAP_WIDTH, MAP_HEIGHT * 0.8f - 2);
	}
	else if (Mode == TEXT_MODE_ERASE)
	{
		string strTmp;
		for (int i = 0; i < MAX_NAME_LEN; i++)
			strTmp += " ";
		m_ifDrawManager.EraseMidText("이름 입력", MAP_WIDTH, MAP_HEIGHT * 0.4f + 2);
		m_ifDrawManager.EraseMidText(strTmp, MAP_WIDTH, MAP_HEIGHT * 0.8f - 2);
	}
}
void Interface::DispStageNumber(int stage_number)
{
	//Erase text in box
	m_ifDrawManager.BoxErase(MAP_WIDTH, MAP_HEIGHT);
	//Display stage
	BG_GRAY_TEXT_ORIGINAL
	string strStage = "★ " + to_string(stage_number) + " Stage ★";
	m_ifDrawManager.DrawMidText(strStage, MAP_WIDTH, MAP_HEIGHT * 0.5f);
	Sleep(1000);
	m_ifDrawManager.EraseMidText(strStage, MAP_WIDTH, MAP_HEIGHT * 0.5f);
	Sleep(1000);
}
void Interface::DispPlayBox()
{
	m_ifDrawManager.BoxDraw(MAP_WIDTH, MAP_HEIGHT * 0.8f - 4, SMALL_BOX_WIDTH, SMALL_BOX_HEIGHT);
}
void Interface::DispGameOverScreen()
{
	BG_GRAY_TEXT_RED
	m_ifDrawManager.DrawMidText("♨ Game Over ♨", MAP_WIDTH, MAP_HEIGHT * 0.5f);
}
void Interface::DispRankScreen()
{
	string strTemp;
	for (int i = 0; i < 2 * (MAP_WIDTH - 2); i++)
		strTemp += "=";
	BG_GRAY_TEXT_PURPLE
		system("cls");
	BG_GRAY_TEXT_BLUE_GREEN
	m_ifDrawManager.BoxDraw(0, 0, MAP_WIDTH, MAP_HEIGHT);
	m_ifDrawManager.DrawMidText(strTemp, MAP_WIDTH, MAP_HEIGHT * 0.2f + 1);
	m_ifDrawManager.BoxDraw(MAP_WIDTH, MAP_HEIGHT * 0.2f - 4, SMALL_BOX_WIDTH, SMALL_BOX_HEIGHT);
	m_ifDrawManager.DrawMidText("Ranking", MAP_WIDTH, MAP_HEIGHT * 0.2f - 2);
}


		