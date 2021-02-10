#include "Play.h"
Play::Play()
{
	m_iLife = INIT_LIFE;
	m_iScore = INIT_SCORE;
	m_strName = "? ? ?";
	m_iStage = 1;
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
	m_pDrawManager.DrawMidText("�� �� �� �� ġ �� �� ��",MAP_WIDTH,MAP_HEIGHT*0.2f);
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
		cout << "��";
	m_pDrawManager.DrawMidText("Score : ", MAP_WIDTH, MAP_HEIGHT + 1);
	cout << m_iScore;
	m_pDrawManager.TextDraw("Name : ", 2 * (MAP_WIDTH - 9), MAP_HEIGHT + 1);
	cout << m_strName;
	ORIGINAL
}
void Play::DispLineText(int posX, int posY, int TextLine, int Mode)
{
	int iCol = 0;
	for (auto iter = m_listStoryText.begin(); iCol < TextLine; iter++, iCol++)
	{
		if(Mode == TEXT_MODE_DRAW)
			m_pDrawManager.DrawMidText(*iter, posX, posY + iCol);
		else if(Mode == TEXT_MODE_ERASE)
			m_pDrawManager.EraseMidText(*iter, posX, posY + iCol);
	}
	
}

void Play::EraseAllLineText(int posX, int posY, int TextLine)
{
	int iCol = 0;
	for (auto iter = m_listStoryText.begin(); iCol < TextLine; iter++, iCol++)
	{
		m_pDrawManager.EraseMidText(*iter, posX, posY + iCol);
	}
}

void Play::ScrollText(int posX, int posY)
{
	//Erase
	DispLineText(posX, posY, TEXT_LINE_COUNT, TEXT_MODE_ERASE);
	//Pop first line Text
	m_listStoryText.pop_front();
	//Draw
	DispLineText(posX, posY, TEXT_LINE_COUNT);
}

void Play::DispStory()
{
	//File Load
	ifstream fStoryLoad;
	fStoryLoad.open("����ġ��_���丮.txt");
	string strStory;
	int iStoryLine;
	fStoryLoad >> iStoryLine;
	while (!fStoryLoad.eof())
	{
		getline(fStoryLoad,strStory);
		m_listStoryText.push_back(strStory);
	}
	fStoryLoad.close();

	int StroyTextFirstLine = 8;
	int iLineCount = 0;
	int iOldTextTime = clock();
	while (1)
	{
		int iCurTextTime = clock();
		if (kbhit())
		{
			char chKeyIn = getch();
			if (chKeyIn == KEY_SKIP_s || chKeyIn == KEY_SKIP_S)
			{
				//Erase all text line
				EraseAllLineText(MAP_WIDTH, StroyTextFirstLine, TEXT_LINE_COUNT);
				break;
			}
		}
		if (iCurTextTime - iOldTextTime >= TEXT_DELAY)
		{
			if (iLineCount < TEXT_LINE_COUNT)
			{
				auto iter = m_listStoryText.begin();
				for (int i = 0; i < iLineCount; i++)
					iter++;
				m_pDrawManager.DrawMidText(*iter, MAP_WIDTH, StroyTextFirstLine + iLineCount);
				iLineCount++;
			}
			else
			{
				//Scroll text
				ScrollText(MAP_WIDTH, StroyTextFirstLine);
				//Escape
				if (m_listStoryText.size() == TEXT_LINE_COUNT)
				{
					//Erase all text line
					EraseAllLineText(MAP_WIDTH, StroyTextFirstLine, TEXT_LINE_COUNT);
					break;
				}
			}
			iOldTextTime = iCurTextTime;
		}
	}
}
void Play::InputName()
{
	m_pDrawManager.DrawMidText("�̸� �Է�",MAP_WIDTH, MAP_HEIGHT*0.4f+2);
	//�̸� ����
	m_pDrawManager.EraseMidText("Skip : S", MAP_WIDTH, MAP_HEIGHT * 0.8f - 2);
	string strTempName;
	while (1)
	{
		m_pDrawManager.gotoxy(MAP_WIDTH, MAP_HEIGHT * 0.8f - 2);

		char chTemp = getch();
		if (strTempName.size() <= MAX_NAME_LEN
		&&(chTemp >= 'a' && chTemp <= 'z')|| (chTemp >= 'A' && chTemp <= 'Z'))
			strTempName += chTemp;
		else if (chTemp == KEY_BS && strTempName.size() > 0)
		{
			m_pDrawManager.EraseMidText(strTempName, MAP_WIDTH, MAP_HEIGHT * 0.8f - 2);
			strTempName.pop_back();
		}
		else if (chTemp == KEY_ENTER)
		{
			for (int i = strTempName.size();i < MAX_NAME_LEN;i++)
				strTempName += " ";
			m_strName = strTempName;
			break;
		}
		//Display Text
		if (strTempName.size() >= MAX_NAME_LEN)
		{
			m_pDrawManager.DrawMidText("10���� �ʰ�!!", MAP_WIDTH, MAP_HEIGHT * 0.4f + 3);
			m_pDrawManager.DrawMidText(strTempName, MAP_WIDTH, MAP_HEIGHT * 0.8f - 2);
		}
		else
		{
			m_pDrawManager.EraseMidText("10���� �ʰ�!!", MAP_WIDTH, MAP_HEIGHT * 0.4f + 3);
			m_pDrawManager.DrawMidText(strTempName, MAP_WIDTH, MAP_HEIGHT * 0.8f - 2);
		}
	}
}

void Play::LoadWord()
{
	ifstream fLoadWord;
	Word tmpWordClass;
	string strTmpWord;
	fLoadWord.open("Word.txt");
	fLoadWord >> m_iWordCount;
	while (!fLoadWord.eof())
	{
		fLoadWord >> strTmpWord;
		tmpWordClass.SetWord(strTmpWord);
		m_vWordClass.push_back(tmpWordClass);
	}
	fLoadWord.close();
}

void Play::InGame()
{
	//Word �ҷ�����
	LoadWord();

	int iNameBoxWidth = 19;
	int NameBoxHeight = 5;

	m_pDrawManager.BoxErase(MAP_WIDTH, MAP_HEIGHT);
	DispPlayerInfo();
	BG_GRAY_TEXT_PURPLE
	//Display stage
	string strStage = "�� " + to_string(m_iStage) + " Stage ��";
	m_pDrawManager.DrawMidText(strStage, MAP_WIDTH, MAP_HEIGHT * 0.5f);
	Sleep(2000);
	m_pDrawManager.EraseMidText(strStage, MAP_WIDTH, MAP_HEIGHT * 0.5f);
	
	m_pDrawManager.BoxDraw(MAP_WIDTH, MAP_HEIGHT * 0.8f - 4, iNameBoxWidth, NameBoxHeight);
	int iOldCreatTime = clock();
	int iOldMoveTime = clock();
	while (1)
	{
		int iCurCreatTime = clock();
		int iCurMoveTime = clock();

	}
	getch();
}

void Play::StartGame()
{
	BG_GRAY_TEXT_PURPLE
	int iNameBoxWidth = 19;
	int NameBoxHeight = 5;
	m_pDrawManager.BoxErase(MAP_WIDTH, MAP_HEIGHT);
	m_pDrawManager.BoxDraw(MAP_WIDTH, MAP_HEIGHT*0.8f-4, iNameBoxWidth, NameBoxHeight);
	m_pDrawManager.DrawMidText("Skip : S", MAP_WIDTH, MAP_HEIGHT * 0.8f - 2);
	//Display stroy
	DispStory();
	//Input name
	InputName();
	//In game
	InGame();
	ORIGINAL

}

void Play::GameOn()
{
	int iSelector;
	SetConsoleWindow(MAP_WIDTH,MAP_HEIGHT);
	srand(time(NULL));
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
