#include "GameOverView.h"
void GameOverView::DrawView()
{
	m_viewDrawManager.DrawBaseMap(MAP_WIDTH, MAP_HEIGHT);
	m_viewDrawManager.DispText("�� �� �� Game Over �� �� ��", MAP_WIDTH, MAP_HEIGHT * 0.5f);
	m_viewDrawManager.DispText("Continu : Space Bar", MAP_WIDTH, MAP_HEIGHT * 0.6f);
}