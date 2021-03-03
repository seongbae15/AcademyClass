#include "GameManager.h"

GameManager::GameManager()
{
	m_gmMapFirst = new MapFirst;
	m_gmMapSecond = new MapSecond;
	m_gmP1 = new Player;
	m_gmP2 = new Player;
	m_gmM1 = new Monster;
	m_gmM2 = new Monster;
}

void GameManager::SetConsoleWin()
{
	char buf[256];
	int width = (WINDOW_WIDTH * 2);
	int height = WINDOW_HEIGHT;
	sprintf(buf, "mode con: lines=%d cols=%d", height, width);
	system(buf);
}

void GameManager::DrawTowerMap()
{
	m_gmMapFirst->DrawMap();
	m_gmMapSecond->DrawMap();
}

void GameManager::InitGame()
{
	m_gmMapFirst->InitMap();
	m_gmMapSecond->InitMap();
	//베이스 맵 그리기
	DrawTowerMap();
	//플레이어 초기화, 표시
	m_gmP1->InitCharacter(1);
	m_gmP1->DrawCharacter();
	m_gmP2->InitCharacter(2);
	m_gmP2->DrawCharacter();
	//몬스터 초기화, 표시
	m_gmM1->InitCharacter(1);
	m_gmM1->DrawCharacter();
	m_gmM2->InitCharacter(2);
	m_gmM2->DrawCharacter();
	
}

void GameManager::StartGame()
{
	//콘솔창 설정
	SetConsoleWin();
	//게임초기화
	InitGame();


	getch();
	//
}