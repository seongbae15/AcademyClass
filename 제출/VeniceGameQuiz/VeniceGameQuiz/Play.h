#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <list>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include "Lib.h"
#include "DrawManager.h"
#include "Word.h"
#include "Story.h"

#define LOBY_MENU_CNT 3
#define LOBY_ADD_COL 3
#define INIT_SCORE 0
#define INIT_LIFE 9
#define SMALL_BOX_WIDTH 19
#define SMALL_BOX_HEIGHT 5

#define TEXT_LINE_COUNT 10
#define TEXT_DELAY 1000
#define TEXT_MODE_DRAW 0
#define TEXT_MODE_ERASE 1
#define KEY_SKIP_s 115
#define KEY_SKIP_S 83
#define KEY_BS 8
#define KEY_ENTER 13
#define MAX_NAME_LEN 10

#define SCROLL_MODE_STORY 0
#define SCROLL_MODE_WORD 1


#define KEY_IN_BOX_WIDTH 19
#define KEY_IN_BOX_HEIGHT 5

#define TIME_WORD_CREATE 1500
#define TIME_WORD_MOVING 500
#define MAX_WORD_LEN 20
#define SCORE_RATE 30

#define NUMBER_RANK_MAX 10

using namespace std;

typedef struct PlayerInfo
{
	string strName;
	int iStage;
	int iScore;
	int iLife;
}PlayerInfo;

class Play
{
private:
	bool m_bGameState;
	bool m_bLifeState;
	int m_iWordMoveRate;
	int m_iWordCreateRate;
	PlayerInfo m_stP;
	DrawManager m_pDrawManager;

	list<string> m_listStoryText;

	vector<Story> m_vStoryClass;

	vector<Word> m_vWordClass;
	vector<Word> m_vPlayingWordClass;

	vector<PlayerInfo> m_vPList;
	int m_iWordCount;

public:
	Play();
	void PlayerInit();
	void GameOn();
	void SetConsoleWindow(int width, int height);
	void DispLoby(int Mode = TEXT_MODE_DRAW);
	void DispPlayerInfo();
	void StartGame();
	void DispStory();
	void LoadStory();
	void DispLineText(int posX, int posY, int TextLine, int Mode = TEXT_MODE_DRAW);
	void ScrollText(int posX, int posY);

	//Template 적용<Story><Word> 모두 사용하도록
	template <typename t>
	void TextScroll(vector<t>* vectorClass, int max_size,int limit_y,int Mode);

	void InputName(int Mode = TEXT_MODE_DRAW);
	bool KeyboardInput(string* str, int maxLen);
	void InGame();
	void DispStage();
	void LoadWord();
	void CreateWord();
	void MoveWord();
	bool CheckWordBoxPos(int index);
	bool CheckWordBoxPos(string str, int posX, int posY);
	bool CheckWordFailed(string str);
	void StageUp();
	void SaveRank();

	//Ok
	void DispRankScreen();
	void LoadRank();
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
};

