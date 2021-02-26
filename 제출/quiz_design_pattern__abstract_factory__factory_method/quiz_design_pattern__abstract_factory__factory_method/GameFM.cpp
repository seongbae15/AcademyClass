#include "GameFM.h"

void LobyView::Initialize(int type)
{
	DrawView();
}

void LobyView::DrawView()
{
	m_lobyDraw.DrawBaseMap(MAP_WIDTH, MAP_HEIGHT);
	m_lobyDraw.DispText("★ ☆ ★ Sanke Game ★ ☆ ★", MAP_WIDTH, MAP_HEIGHT * 0.2f);
	m_lobyDraw.DispText("1. 게임 시작", MAP_WIDTH, MAP_HEIGHT * 0.3f);
	m_lobyDraw.DispText("2. 게임 종료", MAP_WIDTH, MAP_HEIGHT * 0.4f);
	m_lobyDraw.DispText("선택 : ", MAP_WIDTH, MAP_HEIGHT * 0.5f);
}

void PlayInfo::Initialize(int type)
{
	m_iPlay_time = MOVE_TIME_DEFAULT;
	m_iPlay_score = 0;
	m_piDraw.DispText("Score : ", MAP_WIDTH, MAP_HEIGHT + 2);
	cout << m_iPlay_score;

}

void PlayInfo::Update()
{
	m_piDraw.DispText("Score : ", MAP_WIDTH, MAP_HEIGHT + 2);
	cout << m_iPlay_score;
}

void BlockFactory::Initialize(int type)
{
	m_BlockFactory = CreateBlock(type);
	//갯수 초기화
	//위치 초기화 등 설정
}

Block* BlockFactory::CreateBlock(int type)
{
	switch (type)
	{
	case STONE:
		return new Stone;
		break;
	case FOOD:
		return new Food;
		break;
	default:
		break;
	}
}

void BlockFactory::Update()
{
	m_BlockFactory->DrawBlock();
}