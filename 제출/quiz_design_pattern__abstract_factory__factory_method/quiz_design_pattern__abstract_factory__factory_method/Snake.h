#pragma once
#include "Block.h"

#define MOVE_MAX_X MAP_WIDTH-1
#define MOVE_MAX_Y MAP_HEIGHT-1

enum SNAKE_DIRECTION
{
	SNAKE_DIRECTION_STOP = 0,
	SNAKE_DIRECTION_UP = 119,
	SNAKE_DIRECTION_DOWN = 115,
	SNAKE_DIRECTION_LEFT = 97,
	SNAKE_DIRECTION_RIGHT = 100,
};

class Snake : public Block
{
	string m_strHead;
	string m_strTail;
	SNAKE_DIRECTION m_eDirection;
	SNAKE_DIRECTION m_eLastDirection;
	bool m_bMoveState;
public:
	Snake();
	void CreateBlock();
	void EraseBlock(int i) {};
	void DrawBlock();

	void SetSnakeDirection(int keyboard_input);
	void MoveSnake();
	void UpdateSnake();
};

