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
void Play::DispLoby(int Mode)
{
	BG_GRAY_TEXT_PURPLE
	if (Mode == TEXT_MODE_DRAW)
	{
		m_pDrawManager.BoxDraw(0, 0, MAP_WIDTH, MAP_HEIGHT);
		m_pDrawManager.DrawMidText("�� �� �� �� ġ �� �� ��", MAP_WIDTH, MAP_HEIGHT * 0.2f);
		m_pDrawManager.DrawMidText("1. Game Start", MAP_WIDTH, MAP_HEIGHT * 0.4f);
		m_pDrawManager.DrawMidText("2. Rank", MAP_WIDTH, MAP_HEIGHT * 0.4f + LOBY_ADD_COL);
		m_pDrawManager.DrawMidText("3. Exit", MAP_WIDTH, MAP_HEIGHT * 0.4f + 2 * LOBY_ADD_COL);
	}
	else if (Mode == TEXT_MODE_ERASE)
	{
		m_pDrawManager.EraseMidText("�� �� �� �� ġ �� �� ��", MAP_WIDTH, MAP_HEIGHT * 0.2f);
		m_pDrawManager.EraseMidText("1. Game Start", MAP_WIDTH, MAP_HEIGHT * 0.4f);
		m_pDrawManager.EraseMidText("2. Rank", MAP_WIDTH, MAP_HEIGHT * 0.4f + LOBY_ADD_COL);
		m_pDrawManager.EraseMidText("3. Exit", MAP_WIDTH, MAP_HEIGHT * 0.4f + 2 * LOBY_ADD_COL);
	}
	ORIGINAL
}

void Play::DispPlayerInfo()
{
	BG_GRAY_TEXT_RED
	m_pDrawManager.TextDraw("Life : ", 1, MAP_HEIGHT + 1);
	for (int i = 0;i < m_iLife;i++)
		cout << "��";
	for (int j = m_iLife;j < INIT_LIFE;j++)
		cout << "  ";
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

void Play::ScrollText(int posX, int posY)
{
	//Erase
	DispLineText(posX, posY, TEXT_LINE_COUNT, TEXT_MODE_ERASE);
	//Pop first line Text
	m_listStoryText.pop_front();
	//Draw
	DispLineText(posX, posY, TEXT_LINE_COUNT);
}

//Template ���?? : StoryText Class�߰�???
void Play::TextScroll(string str, int posX, int posY)
{
	//Erase
	
	//Draw or Delete

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
		m_vStoryText.push_back(strStory);
	}
	fStoryLoad.close();

	int StroyTextFirstLine = 8;
	int iLineCount = 0;
	int iLineCount1 = 0;
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
				DispLineText(MAP_WIDTH, StroyTextFirstLine, TEXT_LINE_COUNT, TEXT_MODE_ERASE);
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
				//m_pDrawManager.DrawMidText(m_vStoryText[iLineCount], MAP_WIDTH, StroyTextFirstLine + iLineCount);
				iLineCount++;
			}
			else
			{
				//Scroll text
				ScrollText(MAP_WIDTH, StroyTextFirstLine);
				//Escape
				if (m_listStoryText.size() == TEXT_LINE_COUNT)
				{
					Sleep(1000);
					//Erase all text line
					DispLineText(MAP_WIDTH, StroyTextFirstLine, TEXT_LINE_COUNT, TEXT_MODE_ERASE);
					break;
				}
			}
			iOldTextTime = iCurTextTime;
		}
	}
}

bool Play::KeyboardInput(string* str, int maxLen)
{
	gotoxy(MAP_WIDTH, MAP_HEIGHT * 0.8f - 2);
	char chTemp = getch();
	if ((*str).size() < maxLen
		&& (chTemp >= 'a' && chTemp <= 'z') || (chTemp >= 'A' && chTemp <= 'Z'))
		*str += chTemp;
	else if (chTemp == KEY_BS && (*str).size() > 0)
	{
		m_pDrawManager.EraseMidText(*str, MAP_WIDTH, MAP_HEIGHT * 0.8f - 2);
		(*str).pop_back();
	}
	else if (chTemp == KEY_ENTER)
	{
		if(str->size()>0)
			return true;
	}
	//Display Text
	if ((*str).size() >= maxLen)
	{
		m_pDrawManager.DrawMidText(to_string(maxLen) + "���� �ʰ�!!", MAP_WIDTH, MAP_HEIGHT * 0.4f + 3);
		m_pDrawManager.DrawMidText(*str, MAP_WIDTH, MAP_HEIGHT * 0.8f - 2);
	}
	else
	{
		m_pDrawManager.EraseMidText(to_string(maxLen) + "���� �ʰ�!!", MAP_WIDTH, MAP_HEIGHT * 0.4f + 3);
		m_pDrawManager.DrawMidText(*str, MAP_WIDTH, MAP_HEIGHT * 0.8f - 2);
	}
	return false;
}
void Play::InputName(int Mode)
{
	if (Mode == TEXT_MODE_DRAW)
	{
		m_pDrawManager.DrawMidText("�̸� �Է�", MAP_WIDTH, MAP_HEIGHT * 0.4f + 2);
		//�̸� ����
		m_pDrawManager.EraseMidText("Skip : S", MAP_WIDTH, MAP_HEIGHT * 0.8f - 2);
		string strTempName;
		while (1)
		{
			bool bKeyEnter = KeyboardInput(&strTempName, MAX_NAME_LEN);
			if (bKeyEnter == true)
			{
				for (int i = strTempName.size(); i < MAX_NAME_LEN; i++)
					strTempName += " ";
				m_strName = strTempName;
				break;
			}
		}
	}
	else if (Mode == TEXT_MODE_ERASE)
	{
		m_pDrawManager.EraseMidText("�̸� �Է�", MAP_WIDTH, MAP_HEIGHT * 0.4f + 2);
		m_pDrawManager.EraseMidText(m_strName, MAP_WIDTH, MAP_HEIGHT * 0.8f - 2);
	}
}

void Play::LoadWord()
{
	ifstream fLoadWord;
	Word tmpWordClass;
	string strTmpWord;
	fLoadWord.open("Word.txt");
	fLoadWord >> m_iWordCount;
	while (fLoadWord.is_open()&&!fLoadWord.eof())
	{
		fLoadWord >> strTmpWord;
		tmpWordClass.SetWord(strTmpWord);
		m_vWordClass.push_back(tmpWordClass);
	}
	fLoadWord.close();
}
void Play::DispStage()
{
	//Display stage
	string strStage = "�� " + to_string(m_iStage) + " Stage ��";
	m_pDrawManager.DrawMidText(strStage, MAP_WIDTH, MAP_HEIGHT * 0.5f);
	Sleep(1000);
	m_pDrawManager.EraseMidText(strStage, MAP_WIDTH, MAP_HEIGHT * 0.5f);
	Sleep(1000);
}

void Play::CreateWord()
{
	//Random word index
	int iRindex = rand() % m_iWordCount;	//0~74
	//Random position X	//
	int iRposX = rand() % (MAP_WIDTH * 2 - (m_vWordClass[iRindex].GetWord().size()+3)) + 2;
	m_vWordClass[iRindex].SetWordPos(iRposX, 1);
	m_vPlayingWordClass.push_back(m_vWordClass[iRindex]);
	//Draw
	m_vPlayingWordClass.back().DrawWord();
}
void Play::MoveWord()
{
	//Erase
	for (int i = 0; i < m_vPlayingWordClass.size(); i++)
	{
		bool bCheckWordPos1 = CheckWordBoxPos(i);
		if (bCheckWordPos1 == true);
		else
			m_vPlayingWordClass[i].EraseWord();
	}
	//Move & Draw
	for (int i = 0; i < m_vPlayingWordClass.size();)
	{
		m_vPlayingWordClass[i].UpadatePosY();
		bool bCheckWordPos2 = CheckWordBoxPos(i);
		if (bCheckWordPos2 == true)
			i++;
		else
		{
			int iCurPosY = m_vPlayingWordClass[i].GetWordPosY();
			int iCurPosX = m_vPlayingWordClass[i].GetWordPosX();
			string strCurWord = m_vPlayingWordClass[i].GetWord();
			if (iCurPosY == MAP_HEIGHT - 1)
			{
				m_vPlayingWordClass.erase(m_vPlayingWordClass.begin() + i);
				//Life Down
				if (m_iLife > 0)
					m_iLife--;
				else
					m_iLife = 0;
			}
			else
			{
				m_vPlayingWordClass[i].DrawWord();
				i++;
			}
		}
	}
}
bool Play::CheckWordBoxPos(int index)
{
	int iPosY = m_vPlayingWordClass[index].GetWordPosY();
	int iPosX = m_vPlayingWordClass[index].GetWordPosX();
	string strWord = m_vPlayingWordClass[index].GetWord();
	if ((iPosY >= MAP_HEIGHT * 0.8f - 4 && iPosY <= MAP_HEIGHT * 0.8f)
		&& ((iPosX >= MAP_WIDTH - KEY_IN_BOX_WIDTH && iPosX <= MAP_WIDTH + KEY_IN_BOX_WIDTH)
			|| (iPosX + strWord.size() >= MAP_WIDTH - KEY_IN_BOX_WIDTH
				&& iPosX + strWord.size() <= MAP_WIDTH + KEY_IN_BOX_WIDTH)))
		return true;
	else
		return false;
}
bool Play::CheckWordFailed(string str)
{
	for (int i = 0;i < m_vPlayingWordClass.size();i++)
	{
		if (str == m_vPlayingWordClass[i].GetWord())
		{
			m_vPlayingWordClass[i].EraseWord();
			m_vPlayingWordClass.erase(m_vPlayingWordClass.begin() + i);
			return true;
		}
	}
	return false;
}

void Play::InGame()
{
	int iNameBoxWidth = 19;
	int NameBoxHeight = 5;
	//Display PlayerInfo
	DispPlayerInfo();
	BG_GRAY_TEXT_PURPLE
	//Display stage
	DispStage();
	m_pDrawManager.BoxDraw(MAP_WIDTH, MAP_HEIGHT * 0.8f - 4, iNameBoxWidth, NameBoxHeight);
	int iOldCreatTime = clock();
	int iOldMoveTime = clock();
	string strTempKeyIn;
	while (1)
	{
		BG_GRAY_TEXT_PURPLE
		//Manage Word
		int iCurCreatTime = clock();
		int iCurMoveTime = clock();
		//Create word
		if (iCurCreatTime - iOldCreatTime >= TIME_WORD_CREATE)
		{
			CreateWord();
			iOldCreatTime = iCurCreatTime;
		}
		//Move word
		if (iCurMoveTime - iOldMoveTime >= TIME_WORD_MOVING)
		{
			MoveWord();
			iOldMoveTime = iCurMoveTime;
		}
		//Input word
		if (kbhit())
		{
			m_pDrawManager.EraseMidText("Failed Compare!!", MAP_WIDTH, MAP_HEIGHT * 0.8f - 2);
			bool bKeyEnter = KeyboardInput(&strTempKeyIn, MAX_WORD_LEN);
			if (bKeyEnter == true)
			{
				m_pDrawManager.EraseMidText(strTempKeyIn, MAP_WIDTH, MAP_HEIGHT * 0.8f - 2);
				//Word ���߱�
				if (CheckWordFailed(strTempKeyIn))
					m_iScore += SCORE_PLUS;
				else
					m_pDrawManager.DrawMidText("Failed Compare!!", MAP_WIDTH, MAP_HEIGHT * 0.8f - 2);
				//�Է� ���� �ʱ�ȭ
				strTempKeyIn = "\0";
			}
		}
		DispPlayerInfo();
	}
}

void Play::StartGame()
{
	int iNameBoxWidth = 19;
	int NameBoxHeight = 5;
	BG_GRAY_TEXT_PURPLE
	m_pDrawManager.BoxDraw(MAP_WIDTH, MAP_HEIGHT*0.8f-4, iNameBoxWidth, NameBoxHeight);
	m_pDrawManager.DrawMidText("Skip : S", MAP_WIDTH, MAP_HEIGHT * 0.8f - 2);
	//Display stroy
	DispStory();

	//Input name
	InputName();
	InputName(TEXT_MODE_ERASE);
	//Word �ҷ�����
	LoadWord();
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
		iSelector = m_pDrawManager.MenuSelectCursor(LOBY_MENU_CNT, LOBY_ADD_COL, MAP_WIDTH/2 - 5, MAP_HEIGHT * 0.4f);
		switch (iSelector)
		{
		case 1:
			//Text Erase
			DispLoby(TEXT_MODE_ERASE);
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
