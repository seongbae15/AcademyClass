#include "LobyView.h"

void LobyView::DrawView()
{
	m_viewDrawManager.DrawBaseMap(MAP_WIDTH, MAP_HEIGHT);
	m_viewDrawManager.DispText("★ ☆ ★ Sanke Game ★ ☆ ★", MAP_WIDTH, MAP_HEIGHT * 0.2f);
	m_viewDrawManager.DispText("1. 게임 시작", MAP_WIDTH, MAP_HEIGHT * 0.3f);
	m_viewDrawManager.DispText("2. 게임 종료", MAP_WIDTH, MAP_HEIGHT * 0.4f);
	m_viewDrawManager.DispText("선택 : ", MAP_WIDTH, MAP_HEIGHT * 0.5f);
}