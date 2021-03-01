#pragma once
#include "PlayLib.h"
#include "DrawManager.h"
#include <vector>

typedef struct BlockPos
{
	int iX;
	int iY;
};

class Block
{
protected:
	string m_strBlock;
	vector<BlockPos> m_vecBlockPos;
	DrawManager m_blockDrawManager;
public:
	virtual void CreateBlock()=0;
	virtual void DrawBlock() = 0;
	virtual void EraseBlock(int i=0) = 0;
	void ClearBlock();

	virtual void SetSnakeDirection(int keyboard_input) = 0;
	virtual void MoveSnake() = 0;
	virtual void UpdateSnake() = 0;
	
	BlockPos getPosition(int i)
	{
		return m_vecBlockPos[i];
	}
	BlockPos getLastPostion()
	{
		auto iter = m_vecBlockPos.rbegin();
		return (*iter);
	}
	int getSizeVector()
	{
		return m_vecBlockPos.size();
	}

};

