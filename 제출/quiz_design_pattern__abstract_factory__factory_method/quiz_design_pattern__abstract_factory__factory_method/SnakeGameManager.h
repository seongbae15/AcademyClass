#pragma once

#include <iostream>
#include <Windows.h>
#include <time.h>
#include "DrawManager.h"
#include "PlayLib.h"

#include "ViewFactoryMethod.h"
#include "LobyView.h"
#include "PlayView.h"
#include "GameOverView.h"

#include "Block.h"
#include "Stone.h"
#include "Snake.h"
#include "Food.h"

#define MOVE_TIME_DEFAULT 400
#define MOVE_TIME_MIN 80
#define MOVE_TIME_SPEED_UP 20
#define SPACE_BAR 32

using namespace std;

class SnakeGameManager
{
private:
	int m_iMapWidth;
	int m_iMapHeight;
	int m_iScore;
	int m_iMoveTime;
	DrawManager m_gmDrawManager;

	ViewFactoryMethod* m_gmLobyView;
	ViewFactoryMethod* m_gmPlayView;
	ViewFactoryMethod* m_gmGameOverView;
	Block* m_gmBlockStone;
	Block* m_gmBlockSnake;
	Block* m_gmBlockFood;

public:
	SnakeGameManager();
	void SetConsoleWindow();
	void GameRun();
	void GameInit();
	void GameStart();
	void KeyboardInput();
	bool CheckPositionCollision(BlockPos stPos1,BlockPos stPos2);
	bool CheckEatFood();
	void UpdateGameInfo();
	bool CheckGameOver();
	bool CheckFoodPos();
	void GameClear();
	void Release();
	inline int getMapWidth()
	{
		return MAP_WIDTH;
	}
	inline int getMapHeight()
	{
		return MAP_HEIGHT;
	}
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
};

