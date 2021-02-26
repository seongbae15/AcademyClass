#pragma once
#include <conio.h>
#include <list>

#include "DrawManager.h"

enum SNAKE_DIRECTION
{
	SNAKE_DIRECTION_STOP = 0,
	SNAKE_DIRECTION_UP = 119,
	SNAKE_DIRECTION_DOWN = 115,
	SNAKE_DIRECTION_LEFT = 97,
	SNAKE_DIRECTION_RIGHT = 100,
};

typedef struct SnakePos
{
	int m_iX;
	int m_iY;
}SnakePos;

class Snake
{
private:
	SnakePos m_stSnake;
	list<SnakePos> m_listSnake;
	int m_iMinX, m_iMinY;
	int m_iMaxX, m_iMaxY;
	string m_strSnakeHead;
	string m_strSnakeTail;
	bool m_bMoveState;

	SNAKE_DIRECTION m_eDirection;
	SNAKE_DIRECTION m_eLastDirection;

	DrawManager snakeDrawManager;
public:
	void SetSnakeMoveArrange(int Width, int Height);
	void InitSnake(int Width, int Height);
	void DrawSnake();
	void SetDirection(int keyInput);
	void MoveSnake();
	void CreateTail();
	inline SnakePos GetHeadPos()
	{
		auto iter = m_listSnake.begin();
		return *iter;
	}
	inline list<SnakePos> GetSnakePos()
	{
		return m_listSnake;
	}
};

