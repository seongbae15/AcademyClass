#pragma once
#include "Block.h"

#define MAX_FOOD_COUNT 10

class Food : public Block
{
public:
	Food();
	void CreateBlock();
	void EraseBlock(int i);
	void DrawBlock();

	void SetSnakeDirection(int keyboard_input) {};
	void MoveSnake() {};
	void UpdateSnake() {};
};

