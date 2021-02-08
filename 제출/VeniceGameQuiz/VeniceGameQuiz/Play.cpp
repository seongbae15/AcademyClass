#include "Play.h"
Play::Play()
{
	m_iLife = INIT_LIFE;
	m_iScore = INIT_SCORE;
}
void Play::SetConsoleWindow(int MapWidth, int MapHeight)
{
	char buf[256];
	int width = (MapWidth * 2);
	int height = MapHeight + 4;
	sprintf(buf, "mode con: lines=%d cols=%d", height, width);
	system(buf);
}
void Play::DispLoby()	
{

	BG_GRATY_TEXT_BLUE_GREEN
	m_pDrawManager.BoxDraw(0,0,MAP_WIDTH,MAP_HEIGHT);
	m_pDrawManager.DrawMidText("☆ ★ 베 네 치 아 ★ ☆",MAP_WIDTH,MAP_HEIGHT*0.2f);
	m_pDrawManager.DrawMidText("1. Game Start", MAP_WIDTH, MAP_HEIGHT*0.4f);
	m_pDrawManager.DrawMidText("2. Rank", MAP_WIDTH, MAP_HEIGHT*0.4f + LOBY_ADD_COL);
	m_pDrawManager.DrawMidText("3. Exit", MAP_WIDTH, MAP_HEIGHT * 0.4f + 2 * LOBY_ADD_COL);
	ORIGINAL
}

void Play::DispPlayerInfo()
{
	BG_GRAY_TEXT_RED
	m_pDrawManager.TextDraw("Life : ", 1, MAP_HEIGHT + 1);
	for (int i = 0;i < m_iLife;i++)
		cout << "♥";
	m_pDrawManager.DrawMidText("Score : ", MAP_WIDTH, MAP_HEIGHT + 1);
	cout << m_iScore;
	m_pDrawManager.TextDraw("Name : ? ? ?", 2 * (MAP_WIDTH - 9), MAP_HEIGHT + 1);
	ORIGINAL
}

void Play::GameOn()
{
	int iSelector;
	SetConsoleWindow(MAP_WIDTH,MAP_HEIGHT);
	while (1)
	{
		DispLoby();
		DispPlayerInfo();
		iSelector = m_pDrawManager.MenuSelectCursor(LOBY_MENU_CNT, LOBY_ADD_COL, MAP_WIDTH/2 - 5, MAP_HEIGHT * 0.4f);
		switch (iSelector)
		{
		case 1:
			//Start Game
			break;
		case 2:
			//Display ranking
			break;
		case 3:
			return;
		}
		system("cls");
	}
}
