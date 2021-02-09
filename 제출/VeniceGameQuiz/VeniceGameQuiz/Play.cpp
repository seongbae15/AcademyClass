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

	BG_GRAY_TEXT_PURPLE
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

void Play::DispStory()
{
	//File Load
	ifstream fStoryLoad;
	fStoryLoad.open("베네치아_스토리.txt");
	string strStory;
	while (!fStoryLoad.eof())
	{
		getline(fStoryLoad,strStory);
		m_vStory.push_back(strStory);
		m_listStoryText.push_back(strStory);
	}
	fStoryLoad.close();

	int iTextLineLimit = 10;
	int StroyTextFirstLine = 8;
	while (1)
	{
		int iCol = 0;
		//First, Disp each text line.
		for (auto iter = m_listStoryText.begin();iter != m_listStoryText.end();iter++)
		{
			m_pDrawManager.DrawMidText(*iter, MAP_WIDTH, StroyTextFirstLine + iCol++);
			if (iCol == iTextLineLimit)
				break;
			Sleep(1000);
		}
		//Scroll 
		if (iCol == iTextLineLimit)
		{
			auto iter = m_listStoryText.begin();
			m_pDrawManager.EraseMidText(*iter, MAP_WIDTH, StroyTextFirstLine);
			m_listStoryText.pop_front();
		}
		if (m_listStoryText.size() == iTextLineLimit)
			break;
	}





	//Disp Story & Scroll Text
	//10줄표시, 1sec당 한줄 표시
	
	//for (int i = 0;i < m_vStory.size();)
	//{
	//	if (i < iTextLineLimit)
	//	{
	//		m_pDrawManager.DrawMidText(m_vStory[i], MAP_WIDTH, 8 + i);
	//		i++;
	//	}
	//	else
	//	{
	//		m_pDrawManager.EraseMidText(m_vStory[0], MAP_WIDTH, 8);
	//		
	//		for (int j = 0;j < iTextLineLimit;j++)
	//		{
	//			m_pDrawManager.DrawMidText(m_vStory[j], MAP_WIDTH, 8 + j);
	//		}
	//	}
	//	Sleep(1000);
	//}
	
}

void Play::StartGame()
{
	BG_GRAY_TEXT_PURPLE
	m_pDrawManager.BoxErase(MAP_WIDTH, MAP_HEIGHT);
	m_pDrawManager.BoxDraw(MAP_WIDTH, 24, 19, 5);
	m_pDrawManager.DrawMidText("Skip : S", MAP_WIDTH, 26);
	//Display Stroy
	DispStory();
	//Skip

	//Input name


	ORIGINAL
	getch();
}

void Play::GameOn()
{
	int iSelector;
	SetConsoleWindow(MAP_WIDTH,MAP_HEIGHT);
	while (1)
	{
		DispLoby();
		DispPlayerInfo();
		BG_GRAY_TEXT_RED
		iSelector = m_pDrawManager.MenuSelectCursor(LOBY_MENU_CNT, LOBY_ADD_COL, MAP_WIDTH/2 - 5, MAP_HEIGHT * 0.4f);
		ORIGINAL
		switch (iSelector)
		{
		case 1:
			//Start Game
			StartGame();
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
