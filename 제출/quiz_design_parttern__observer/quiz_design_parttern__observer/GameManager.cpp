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
	//���̽� �� �׸���
	DrawTowerMap();
	//�÷��̾� �ʱ�ȭ, ǥ��
	m_gmP1->InitCharacter(1);
	m_gmP1->DrawCharacter();
	m_gmP2->InitCharacter(2);
	m_gmP2->DrawCharacter();
	//���� �ʱ�ȭ, ǥ��
	m_gmM1->InitCharacter(1);
	m_gmM1->DrawCharacter();
	m_gmM2->InitCharacter(2);
	m_gmM2->DrawCharacter();
}

void GameManager::MovePlayer()
{
	char chKeyIn = getch();
	{
		//Player1 Move
		switch ((MOVE)chKeyIn)
		{
		case MOVE_UP_1:
		case MOVE_DOWN_1:
		case MOVE_LEFT_1:
		case MOVE_RIGHT_1:
			m_gmP1->MoveCharacter(chKeyIn);
			break;
		case MOVE_UP_2:
		case MOVE_DOWN_2:
		case MOVE_LEFT_2:
		case MOVE_RIGHT_2:
			m_gmP2->MoveCharacter(chKeyIn);
			break;
		default:
			break;
		}
		//Recovery �����
	}
}

void GameManager::StartGame()
{
	//�ܼ�â ����
	SetConsoleWin();
	//�����ʱ�ȭ
	InitGame();
	//Game Start
	while (1)
	{
		if (kbhit())
			MovePlayer();

		//���� �̵�(1��->2��) : �̵� üũ

		//��ư Ȱ��ȭ
		//�˸�


	}


	getch();
	//
}