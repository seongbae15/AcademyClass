#include "LobyView.h"

void LobyView::DrawView()
{
	m_viewDrawManager.DrawBaseMap(MAP_WIDTH, MAP_HEIGHT);
	m_viewDrawManager.DispText("�� �� �� Sanke Game �� �� ��", MAP_WIDTH, MAP_HEIGHT * 0.2f);
	m_viewDrawManager.DispText("1. ���� ����", MAP_WIDTH, MAP_HEIGHT * 0.3f);
	m_viewDrawManager.DispText("2. ���� ����", MAP_WIDTH, MAP_HEIGHT * 0.4f);
	m_viewDrawManager.DispText("���� : ", MAP_WIDTH, MAP_HEIGHT * 0.5f);
}