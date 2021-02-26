#pragma once
#include "LibGame.h"
#include "DrawManager.h"
#include <vector>


typedef struct BlockPosition
{
	int m_iX;
	int m_iY;
}BlockPosition;

class Block
{
protected:
	string m_strBlock;
	vector<BlockPosition> m_vecPosList;
	DrawManager m_blockDrawManager;
public:
	virtual void DrawBlock() = 0;
	inline int GetCount()
	{
		return m_vecPosList.size();
	}
};

class Stone : public Block
{
public:
	Stone();
	void DrawBlock();
private:
};

class Food : public Block
{
public:
	Food();
	void DrawBlock();
private:

};

