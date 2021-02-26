#include "GameFM.h"

void LobyView::Initialize(int type)
{
	DrawView();
}

void LobyView::DrawView()
{
	m_lobyDraw.DrawBaseMap(MAP_WIDTH, MAP_HEIGHT);
	m_lobyDraw.DispText("�� �� �� Sanke Game �� �� ��", MAP_WIDTH, MAP_HEIGHT * 0.2f);
	m_lobyDraw.DispText("1. ���� ����", MAP_WIDTH, MAP_HEIGHT * 0.3f);
	m_lobyDraw.DispText("2. ���� ����", MAP_WIDTH, MAP_HEIGHT * 0.4f);
	m_lobyDraw.DispText("���� : ", MAP_WIDTH, MAP_HEIGHT * 0.5f);
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
	//���� �ʱ�ȭ
	//��ġ �ʱ�ȭ �� ����
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