#include "GameManager.h"

void GameManager::SetConsoleWin()
{
	char buf[256];
	int width = (WINDOW_WIDTH * 2);
	int height = WINDOW_HEIGHT;
	sprintf(buf, "mode con: lines=%d cols=%d", height, width);
	system(buf);
}

void GameManager::StartGame()
{
	//�ܼ�â ����
	SetConsoleWin();
	//���̽� �� �׸���
	m_gmMap.DrawMap();
	//�÷��̾� ��ġ ǥ��
	
	//
}