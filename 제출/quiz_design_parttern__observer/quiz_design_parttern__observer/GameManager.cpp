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
	//콘솔창 설정
	SetConsoleWin();
	//베이스 맵 그리기
	m_gmMap.DrawMap();
	//플레이어 위치 표시
	
	//
}