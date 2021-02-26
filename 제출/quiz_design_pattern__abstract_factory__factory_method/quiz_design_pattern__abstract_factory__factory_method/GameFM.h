#pragma once
#include "DrawManager.h"
#include "LibGame.h"
#include "Block.h"

#define STONE 1
#define FOOD 2

class GameFM
{
	//LobyView* m_viwer;
public:
	virtual void Initialize(int type = 0)=0;
	virtual void Update() =0;
	//void Finish();
};

class LobyView : public GameFM
{
	DrawManager m_lobyDraw;
public:
	void Initialize(int type = 0);
	void Update() {};
	void DrawView();
};

class PlayInfo : public GameFM
{
private:
	int m_iPlay_score;
	int m_iPlay_time;
	DrawManager m_piDraw;
public:
	void Initialize(int type = 0);
	void Update();
	//void Finish()
};

class BlockFactory :public GameFM
{
	Block* m_BlockFactory;
public:
	void Initialize(int type=0);
	void Update();
	Block* CreateBlock(int type);
	inline Block* getBlockFactory()
	{
		return m_BlockFactory;
	}
};
