#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <list>
#include <time.h>
#include <stdlib.h>

#include "Lib.h"
#include "DrawManager.h"
#include "Word.h"

#define LOBY_MENU_CNT 3
#define LOBY_ADD_COL 3
#define INIT_SCORE 0
#define INIT_LIFE 9

#define TEXT_LINE_COUNT 10
#define TEXT_DELAY 1000
#define TEXT_MODE_DRAW 0
#define TEXT_MODE_ERASE 1
#define KEY_SKIP_s 115
#define KEY_SKIP_S 83
#define KEY_BS 8
#define KEY_ENTER 13
#define MAX_NAME_LEN 10

#define KEY_IN_BOX_WIDTH 19
#define KEY_IN_BOX_HEIGHT 5

#define TIME_WORD_CREATE 1500
#define TIME_WORD_MOVING 500
#define MAX_WORD_LEN 20
#define SCORE_PLUS 100

using namespace std;

class Play
{
private:
	bool m_bGameState;
	int m_iLife;
	int m_iScore;
	int m_iStage;
	string m_strName;
	list<string> m_listStoryText;
	vector<string> m_vStoryText;
	DrawManager m_pDrawManager;
	vector<Word> m_vWordClass;
	vector<Word> m_vPlayingWordClass;
	int m_iWordCount;

public:
	Play();
	void GameOn();
	void SetConsoleWindow(int width, int height);
	void DispLoby(int Mode = TEXT_MODE_DRAW);
	void DispPlayerInfo();
	void StartGame();
	void DispStory();
	void DispLineText(int posX, int posY, int TextLine, int Mode = TEXT_MODE_DRAW);
	void ScrollText(int posX, int posY);

	void TextScroll(string str, int posX, int posY);

	void InputName(int Mode = TEXT_MODE_DRAW);
	bool KeyboardInput(string* str, int maxLen);
	void InGame();
	void DispStage();
	void LoadWord();
	void CreateWord();
	void MoveWord();
	bool CheckWordBoxPos(int index);
	bool CheckWordFailed(string str);
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
};

