#pragma once
#include "Block.h"

#define MAX_STONE_COUNT 40

class Stone : public Block
{
public:
	Stone();
	void CreateBlock();
	void EraseBlock(int i) {};
	void DrawBlock();

	void SetSnakeDirection(int keyboard_input) {};
	void MoveSnake() {};
	void UpdateSnake() {};

};