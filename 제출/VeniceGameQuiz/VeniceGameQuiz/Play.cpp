#include "Play.h"
Play::Play()
{

}

void Play:: PlayerInit()
{
	m_stP.iLife = INIT_LIFE;
	m_stP.iScore = INIT_SCORE;
	m_stP.strName = "? ? ?";
	m_stP.iStage = 1;
	m_iWordMoveRate = TIME_WORD_MOVING;
	m_iWordCreateRate = TIME_WORD_CREATE;
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
		m_pDrawManager.DrawMidText("☆ ★ 베 네 치 아 ★ ☆", MAP_WIDTH, MAP_HEIGHT * 0.2f);
		m_pDrawManager.DrawMidText("1. Game Start", MAP_WIDTH, MAP_HEIGHT * 0.4f);
		m_pDrawManager.DrawMidText("2. Rank", MAP_WIDTH, MAP_HEIGHT * 0.4f + LOBY_ADD_COL);
		m_pDrawManager.DrawMidText("3. Exit", MAP_WIDTH, MAP_HEIGHT * 0.4f + 2 * LOBY_ADD_COL);
	}
	else if (Mode == TEXT_MODE_ERASE)
	{
		m_pDrawManager.EraseMidText("☆ ★ 베 네 치 아 ★ ☆", MAP_WIDTH, MAP_HEIGHT * 0.2f);
		m_pDrawManager.EraseMidText("1. Game Start", MAP_WIDTH, MAP_HEIGHT * 0.4f);
		m_pDrawManager.EraseMidText("2. Rank", MAP_WIDTH, MAP_HEIGHT * 0.4f + LOBY_ADD_COL);
		m_pDrawManager.EraseMidText("3. Exit", MAP_WIDTH, MAP_HEIGHT * 0.4f + 2 * LOBY_ADD_COL);
	}
	ORIGINAL
}

void Play::DispPlayerInfo()
{
	BG_GRAY_TEXT_RED
	string strTemp;
	m_pDrawManager.TextDraw("Life : ", 1, MAP_HEIGHT + 1);
	for (int i = 0;i < m_stP.iLife;i++)
		cout << "♥";
	for (int j = m_stP.iLife;j < INIT_LIFE;j++)
		cout << "  ";
	m_pDrawManager.DrawMidText("     Score : " + to_string(m_stP.iScore) + "     ", MAP_WIDTH, MAP_HEIGHT + 1);
	m_pDrawManager.TextDraw("Name : ", 2 * (MAP_WIDTH - 9), MAP_HEIGHT + 1);
	for (int i = m_stP.strName.size(); i < MAX_NAME_LEN; i++)
		strTemp += " ";
	cout << m_stP.strName + strTemp;
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

//Template 사용?? : StoryText Class추가???
void Play::TextScroll(vector<Story>* vectorClass,int max_size)
{
	for (int i = 0; i < max_size; i++)
	{
		bool bCheckWordPos1 = CheckWordBoxPos((*vectorClass)[i].GetWord(), (*vectorClass)[i].GetWordPosX(), (*vectorClass)[i].GetWordPosY());
		if (bCheckWordPos1 == true);
		else
			(*vectorClass)[i].EraseWord();
	}
	//Move & Draw
	for (int i = 0; i < (*vectorClass).size();)
	{
		(*vectorClass)[i].UpadatePosY();
		if (i < max_size)
		{
			bool bCheckWordPos2 = CheckWordBoxPos((*vectorClass)[i].GetWord(), (*vectorClass)[i].GetWordPosX(), (*vectorClass)[i].GetWordPosY());
			if (bCheckWordPos2 == true)
				i++;
			else
			{
				int iCurPosY = (*vectorClass)[i].GetWordPosY();
				int iCurPosX = (*vectorClass)[i].GetWordPosX();
				string strCurWord = (*vectorClass)[i].GetWord();
				if (iCurPosY == MAP_HEIGHT * 0.2f)
				{
					(*vectorClass).erase((*vectorClass).begin() + i);
				}
				else
				{
					(*vectorClass)[i].DrawWord();
					i++;
				}
			}
		}
		else
			i++;
	}
}
void Play::LoadStory()
{
	string strStory;
	Story tmpStoryClass;
	string strTmpStory;
	ifstream fStoryLoad;
	fStoryLoad.open("베네치아_스토리.txt");
	
	int iStoryLine;
	int iColCount = 0;;
	fStoryLoad >> iStoryLine;
	while (fStoryLoad.is_open() && !fStoryLoad.eof())
	{
		//getline(fStoryLoad, strStory);
		//m_listStoryText.push_back(strStory);
		
		getline(fStoryLoad, strTmpStory);
		tmpStoryClass.SetWord(strTmpStory, iColCount);
		m_vStoryClass.push_back(tmpStoryClass);
		iColCount++;
	}
	fStoryLoad.close();
}
void Play::DispStory()
{
	//File Load
	LoadStory();
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
				//auto iter = m_listStoryText.begin();
				//for (int i = 0; i < iLineCount; i++)
				//	iter++;
				//m_pDrawManager.DrawMidText(*iter, MAP_WIDTH, StroyTextFirstLine + iLineCount);				
				//iLineCount++;
				m_vStoryClass[iLineCount].DrawWord();
				iLineCount++;
			}
			else
			{
				//
				TextScroll(&m_vStoryClass, TEXT_LINE_COUNT);
				//
				////Scroll text
				//ScrollText(MAP_WIDTH, StroyTextFirstLine);
				////Escape
				//if (m_listStoryText.size() == TEXT_LINE_COUNT)
				//{
				//	Sleep(1000);
				//	//Erase all text line
				//	DispLineText(MAP_WIDTH, StroyTextFirstLine, TEXT_LINE_COUNT, TEXT_MODE_ERASE);
				//	break;
				//}
				//Escape
				if (m_vStoryClass.size() == TEXT_LINE_COUNT)
				{
					Sleep(1000);
					//Erase all text line
					for (int i = 0;i < m_vStoryClass.size();i++)
					{
						m_vStoryClass[i].EraseWord();
					}
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
		m_pDrawManager.DrawMidText(to_string(maxLen) + "글자 초과!!", MAP_WIDTH, MAP_HEIGHT * 0.4f + 3);
		m_pDrawManager.DrawMidText(*str, MAP_WIDTH, MAP_HEIGHT * 0.8f - 2);
	}
	else
	{
		m_pDrawManager.EraseMidText(to_string(maxLen) + "글자 초과!!", MAP_WIDTH, MAP_HEIGHT * 0.4f + 3);
		m_pDrawManager.DrawMidText(*str, MAP_WIDTH, MAP_HEIGHT * 0.8f - 2);
	}
	return false;
}
void Play::InputName(int Mode)
{
	if (Mode == TEXT_MODE_DRAW)
	{
		m_pDrawManager.DrawMidText("이름 입력", MAP_WIDTH, MAP_HEIGHT * 0.4f + 2);
		//이름 조건
		m_pDrawManager.EraseMidText("Skip : S", MAP_WIDTH, MAP_HEIGHT * 0.8f - 2);
		string strTempName;
		while (1)
		{
			bool bKeyEnter = KeyboardInput(&strTempName, MAX_NAME_LEN);
			if (bKeyEnter == true)
			{
				m_stP.strName = strTempName;
				break;
			}
		}

	}
	else if (Mode == TEXT_MODE_ERASE)
	{
		m_pDrawManager.EraseMidText("이름 입력", MAP_WIDTH, MAP_HEIGHT * 0.4f + 2);
		m_pDrawManager.EraseMidText(m_stP.strName, MAP_WIDTH, MAP_HEIGHT * 0.8f - 2);
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
	//Erase text in box
	m_pDrawManager.BoxErase(MAP_WIDTH, MAP_HEIGHT);
	//Display stage
	string strStage = "★ " + to_string(m_stP.iStage) + " Stage ★";
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
				if (m_stP.iLife > 0)
					m_stP.iLife--;
				else
					m_stP.iLife = 0;
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

bool Play::CheckWordBoxPos(string str, int posX, int posY)
{
	if ((posY >= MAP_HEIGHT * 0.8f - 4 && posY <= MAP_HEIGHT * 0.8f)
		&& ((posX >= MAP_WIDTH - KEY_IN_BOX_WIDTH && posX <= MAP_WIDTH + KEY_IN_BOX_WIDTH)
			|| (posX + str.size() >= MAP_WIDTH - KEY_IN_BOX_WIDTH
				&& posX + str.size() <= MAP_WIDTH + KEY_IN_BOX_WIDTH)))
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
			if(!CheckWordBoxPos(i))
				m_vPlayingWordClass[i].EraseWord();
			m_vPlayingWordClass.erase(m_vPlayingWordClass.begin() + i);
			return true;
		}
	}
	return false;
}

void Play::StageUp()
{
	BG_GRAY_TEXT_ORIGINAL
	m_stP.iStage++;
	m_stP.iScore = 0;
	//Clear word info
	m_vPlayingWordClass.clear();
	//Speed up
	m_iWordMoveRate -= 100;
	//increase to create word rate
	m_iWordCreateRate -= 20;
	DispStage();
}

void Play::SaveRank()
{
	ofstream fSaveRank;
	fSaveRank.open("Rank.txt",ios::app);
	if (fSaveRank.is_open())
	{
		fSaveRank << m_stP.strName + " ";
		fSaveRank << to_string(m_stP.iStage) + " ";
		fSaveRank << to_string(m_stP.iScore) << endl;;
		fSaveRank.close();
	}
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
	bool bGameOverState = true;
	while (bGameOverState)
	{
		BG_GRAY_TEXT_PURPLE
		//Manage Word
		int iCurCreatTime = clock();
		int iCurMoveTime = clock();
		//Create word
		if (iCurCreatTime - iOldCreatTime >= m_iWordCreateRate)
		{
			CreateWord();
			iOldCreatTime = iCurCreatTime;
		}
		//Move word
		if (iCurMoveTime - iOldMoveTime >= m_iWordMoveRate)
		{
			MoveWord();
			iOldMoveTime = iCurMoveTime;
		}
		//tpying word
		if (kbhit())
		{
			m_pDrawManager.EraseMidText("Failed Compare!!", MAP_WIDTH, MAP_HEIGHT * 0.8f - 2);
			bool bKeyEnter = KeyboardInput(&strTempKeyIn, MAX_WORD_LEN);
			if (bKeyEnter == true)
			{
				m_pDrawManager.EraseMidText(strTempKeyIn, MAP_WIDTH, MAP_HEIGHT * 0.8f - 2);
				//Word 맞추기
				if (CheckWordFailed(strTempKeyIn))
					m_stP.iScore += strTempKeyIn.size()* SCORE_RATE;
				else
				{
					BG_GRAY_TEXT_RED
					m_pDrawManager.DrawMidText("Failed Compare!!", MAP_WIDTH, MAP_HEIGHT * 0.8f - 2);
				}
				//Init typin word
				strTempKeyIn = "\0";
			}
		}
		DispPlayerInfo();
		//Check Stage Up
		if (m_stP.iScore >= 1000* m_stP.iStage)
		{
			StageUp();
			BG_GRAY_TEXT_PURPLE
			m_pDrawManager.BoxDraw(MAP_WIDTH, MAP_HEIGHT * 0.8f - 4, iNameBoxWidth, NameBoxHeight);
		}
		//Check game over
		if (m_stP.iLife <= 0)
		{
			bGameOverState = false;
			BG_GRAY_TEXT_RED
			m_pDrawManager.DrawMidText("♨ Game Over ♨", MAP_WIDTH, MAP_HEIGHT * 0.5f);
			m_vPlayingWordClass.clear();
			//Save player info
			SaveRank();
			getch();
		}
	}
}

void Play::StartGame()
{
	BG_GRAY_TEXT_PURPLE
	m_pDrawManager.BoxDraw(MAP_WIDTH, MAP_HEIGHT*0.8f-4, SMALL_BOX_WIDTH, SMALL_BOX_HEIGHT);
	m_pDrawManager.DrawMidText("Skip : S", MAP_WIDTH, MAP_HEIGHT * 0.8f - 2);
	//Display stroy
	DispStory();
	//Input name
	InputName();
	InputName(TEXT_MODE_ERASE);
	//Word 불러오기
	LoadWord();
	//In game
	InGame();
	ORIGINAL
}
void Play::LoadRank()
{
	ifstream fLoadRank;
	fLoadRank.open("Rank.txt");
	if (fLoadRank.is_open())
	{
		PlayerInfo stPlayerInfo;
		while (!fLoadRank.eof())
		{
			string strTmp;
			fLoadRank >> strTmp;
			if (strTmp == "\0")
				break;
			else
			{
				stPlayerInfo.strName = strTmp;;
				fLoadRank >> stPlayerInfo.iStage;
				fLoadRank >> stPlayerInfo.iScore;
				m_vPList.push_back(stPlayerInfo);
			}
		}
		fLoadRank.close();
	}
	else
		m_pDrawManager.DrawMidText("저장된 정보가 없습니다", MAP_WIDTH, MAP_HEIGHT * .5f);
}
bool RankSort(PlayerInfo A, PlayerInfo B)
{
	if (A.iStage == B.iStage)
		return A.iScore > B.iScore;
	else
		return A.iStage > B.iStage;
}
void Play::DispRankScreen()
{
	BG_GRAY_TEXT_PURPLE
	system("cls");
	string strTemp;
	vector<PlayerInfo> vTempList;
	//Load rank info
	LoadRank();
	sort(m_vPList.begin(), m_vPList.end(), RankSort);
	for (int i = 0; i < m_vPList.size(); i++)
	{
		if (i >= NUMBER_RANK_MAX)
			break;
		else
			vTempList.push_back(m_vPList[i]);
	}

	BG_GRAY_TEXT_BLUE_GREEN
	m_pDrawManager.BoxDraw(0, 0, MAP_WIDTH, MAP_HEIGHT);
	BG_GRAY_TEXT_PURPLE
	m_pDrawManager.BoxDraw(MAP_WIDTH, MAP_HEIGHT * 0.2f - 4, SMALL_BOX_WIDTH, SMALL_BOX_HEIGHT);
	m_pDrawManager.DrawMidText("Ranking", MAP_WIDTH, MAP_HEIGHT * 0.2f - 2);
	for (int i = 0;i < 2*(MAP_WIDTH - 2);i++)
		strTemp += "=";
	BG_GRAY_TEXT_BLUE_GREEN
	m_pDrawManager.DrawMidText(strTemp, MAP_WIDTH, MAP_HEIGHT * 0.2f+1);
	BG_GRAY_TEXT_PURPLE
	gotoxy(MAP_WIDTH - 20, MAP_HEIGHT * 0.2f + 3);
	cout << "Name\t\tStage\t\tScore";
	for (int i = 0; i < vTempList.size(); i++)
	{
		gotoxy(MAP_WIDTH - 20, MAP_HEIGHT * 0.2f + 4+2*i);
		cout << vTempList[i].strName;
		cout << "\t\t" << vTempList[i].iStage;
		cout << "\t\t" << vTempList[i].iScore;
	}
	m_vPList.clear();
	vTempList.clear();
	getch();
}
void Play::GameOn()
{
	SetConsoleWindow(MAP_WIDTH, MAP_HEIGHT);
	int iSelector;
	srand(time(NULL));
	while (1)
	{
		BG_GRAY_TEXT_PURPLE
			system("cls");
		BG_GRAY_TEXT_BLUE_GREEN
			m_pDrawManager.BoxDraw(0, 0, MAP_WIDTH, MAP_HEIGHT);
		//Init player info
		PlayerInit();
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
			DispRankScreen();
			break;
		case 3:
			return;
		}
		
	}
}