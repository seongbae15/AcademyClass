#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <list>
#include <time.h>

#include "Lib.h"
#include "DrawManager.h"

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

#define MAX_NAME_LEN 10

using namespace std;

class Play
{
private:
	int m_iLife;
	int m_iScore;
	string m_strName;
	vector<string> m_vStory;
	list<string> m_listStoryText;
	DrawManager m_pDrawManager;
public:
	Play();
	void GameOn();
	void SetConsoleWindow(int width, int height);
	void DispLoby();
	void DispPlayerInfo();
	void StartGame();
	void DispStory();
	void DispLineText(int posX, int posY, int TextLine, int Mode = TEXT_MODE_DRAW);
	void EraseAllLineText(int posX, int posY, int TextLine);
	void ScrollText(int posX, int posY);
	void InputName();
};

