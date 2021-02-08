#pragma once
#include <iostream>
#include <string>
#include "Lib.h"
#include "DrawManager.h"

#define LOBY_MENU_CNT 3
#define LOBY_ADD_COL 3
#define INIT_SCORE 0
#define INIT_LIFE 9
using namespace std;

class Play
{
private:
	int m_iLife;
	int m_iScore;
	string m_strName;
	DrawManager m_pDrawManager;
public:
	Play();
	void GameOn();
	void SetConsoleWindow(int width, int height);
	void DispLoby();
	void DispPlayerInfo();
};

