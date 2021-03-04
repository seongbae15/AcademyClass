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
	m_gmArrPlayer[0];
	//���� �ʱ�ȭ, ǥ��
	m_gmM1->InitCharacter(1);
	m_gmM1->DrawCharacter();
	m_gmM2->InitCharacter(2);
	m_gmM2->DrawCharacter();

	//�˶� �ʱ�ȭ
	m_gmP1->SetAlarm(m_gmM1);
	m_gmP2->SetAlarm(m_gmM1);
}

void GameManager::MovePlayer()
{
	char chKeyIn = getch();
	{
		bool bCheck_wallPos = false;
		//Player1 Move
		switch ((MOVE)chKeyIn)
		{
		case MOVE_UP_1:
		case MOVE_DOWN_1:
		case MOVE_LEFT_1:
		case MOVE_RIGHT_1:
			m_gmP1->EraseCharacter();
			m_gmP1->MoveCharacter(chKeyIn);
			for (int i = 0; i < MAX_WALL_COUNT; i++)
			{
				if (m_gmP1->GetPlayerStage() == 1)
				{
					if (m_gmP1->GetCharacterPos().iX == m_gmMapFirst->GetWallPointer()->GetObjectPos(i).iX
						&& m_gmP1->GetCharacterPos().iY == m_gmMapFirst->GetWallPointer()->GetObjectPos(i).iY)
					{
						bCheck_wallPos = true;
						break;
					}

				}
				else if (m_gmP1->GetPlayerStage() == 2)
				{
					if (m_gmP1->GetCharacterPos().iX == m_gmMapSecond->GetWallPointer()->GetObjectPos(i).iX
						&& m_gmP1->GetCharacterPos().iY == m_gmMapSecond->GetWallPointer()->GetObjectPos(i).iY)
					{
						bCheck_wallPos = true;
						break;
					}
				}
			}
			if (!bCheck_wallPos)
				m_gmP1->DrawCharacter();
			else
			{
				m_gmP1->BackCharacter(chKeyIn);
				m_gmP1->DrawCharacter();
			}
			break;
		case MOVE_UP_2:
		case MOVE_DOWN_2:
		case MOVE_LEFT_2:
		case MOVE_RIGHT_2:
			m_gmP2->EraseCharacter();
			m_gmP2->MoveCharacter(chKeyIn);
			for (int i = 0; i < MAX_WALL_COUNT; i++)
			{
				if (m_gmP2->GetPlayerStage() == 1)
				{
					if (m_gmP2->GetCharacterPos().iX == m_gmMapFirst->GetWallPointer()->GetObjectPos(i).iX
						&& m_gmP2->GetCharacterPos().iY == m_gmMapFirst->GetWallPointer()->GetObjectPos(i).iY)
					{
						bCheck_wallPos = true;
						break;
					}

				}
				else if (m_gmP2->GetPlayerStage() == 2)
				{
					if (m_gmP2->GetCharacterPos().iX == m_gmMapSecond->GetWallPointer()->GetObjectPos(i).iX
						&& m_gmP2->GetCharacterPos().iY == m_gmMapSecond->GetWallPointer()->GetObjectPos(i).iY)
					{
						bCheck_wallPos = true;
						break;
					}
				}
			}
			if (!bCheck_wallPos)
				m_gmP2->DrawCharacter();
			else
			{
				m_gmP2->BackCharacter(chKeyIn);
				m_gmP2->DrawCharacter();
			}
			break;
		default:
			break;
		}
		//Recovery �����
	}
}

void GameManager::CheckStageUp()
{
	Pos stTmpPlayerPos1 = m_gmP1->GetCharacterPos();
	Pos stTmpPlayerPos2 = m_gmP2->GetCharacterPos();
	//1�� üũ
	Pos stTmpDoor1 = m_gmMapFirst->GetDoorPointer()->GetObjectPos();
	Pos stTmpDoor2 = m_gmMapSecond->GetDoorPointer()->GetObjectPos();
	//Player 1 üũ
	if (m_gmP1->GetPlayerStage() == 1
		&& stTmpPlayerPos1.iX == stTmpDoor1.iX && stTmpPlayerPos1.iY == stTmpDoor1.iY)
	{
		m_gmP1->StageUpCharacter(stTmpDoor2);
		m_gmP1->SetAlarm(m_gmM2);
	}
	//Player 2 üũ
	else if (m_gmP2->GetPlayerStage() == 1
		&& stTmpPlayerPos2.iX == stTmpDoor1.iX && stTmpPlayerPos2.iY == stTmpDoor1.iY)
	{
		m_gmP2->StageUpCharacter(stTmpDoor2);
		m_gmP2->SetAlarm(m_gmM2);
	}
}

void GameManager::CheckButton()
{
	Pos stTmpPlayerPos1 = m_gmP1->GetCharacterPos();
	
	int iStage1 = m_gmP1->GetPlayerStage();
	int iStage2 = m_gmP2->GetPlayerStage();
	if (iStage1 == 1)
	{
		for (int i = 0; i < MAX_BUTTON_COUNT; i++)
		{
			Pos stTmpButton1 = m_gmMapFirst->GetButtonPointer()->GetObjectPos(i);
			if (stTmpPlayerPos1.iX == stTmpButton1.iX && stTmpPlayerPos1.iY == stTmpButton1.iY)
			{
				switch (m_gmMapFirst->GetButtonPointer()->GetButtonState(i))
				{
				case BUTTON_STATE_PASS:
					//�ƹ��� �Ͼ�� ����.
					break;
				case BUTTON_STATE_WAKE:
					//�ش� �� ���� �����
					//�ش� �� �÷��̾�� �˸�
					m_gmM1->ChangeMonsterState(BUTTON_STATE_WAKE, m_gmP1);
					break;
				case BUTTON_STATE_SLEEP:
					//�ش� �� ���� ����
					//�ش� �� �÷��̾�� �˸�
					m_gmM1->ChangeMonsterState(BUTTON_STATE_SLEEP, m_gmP1);
					break;
				default:
					break;
				}
				break;
			}
		}
	}
	else if (iStage1 == 2)
	{
		for (int i = 0; i < MAX_BUTTON_COUNT; i++)
		{
			
			Pos stTmpButton2 = m_gmMapSecond->GetButtonPointer()->GetObjectPos(i);
			if (stTmpPlayerPos1.iX == stTmpButton2.iX && stTmpPlayerPos1.iY == stTmpButton2.iY)
			{
				switch (m_gmMapSecond->GetButtonPointer()->GetButtonState(i))
				{
				case BUTTON_STATE_PASS:
					//�ƹ��� �Ͼ�� ����.
					break;
				case BUTTON_STATE_WAKE:
					//�ش� �� ���� �����
					//�ش� �� �÷��̾�� �˸�
					m_gmM2->ChangeMonsterState(BUTTON_STATE_WAKE, m_gmP1);
					break;
				case BUTTON_STATE_SLEEP:
					//�ش� �� ���� ����
					//�ش� �� �÷��̾�� �˸�
					m_gmM2->ChangeMonsterState(BUTTON_STATE_SLEEP, m_gmP1);
					break;
				default:
					break;
				}
				break;
			}
		}
	}
	Pos stTmpPlayerPos2 = m_gmP2->GetCharacterPos();
	if (iStage2 == 1)
	{
 		for (int i = 0; i < MAX_BUTTON_COUNT; i++)
		{
			Pos stTmpButton1 = m_gmMapFirst->GetButtonPointer()->GetObjectPos(i);
			if (stTmpPlayerPos2.iX == stTmpButton1.iX && stTmpPlayerPos2.iY == stTmpButton1.iY)
			{
				switch (m_gmMapFirst->GetButtonPointer()->GetButtonState(i))
				{
				case BUTTON_STATE_PASS:
					//�ƹ��� �Ͼ�� ����.
					break;
				case BUTTON_STATE_WAKE:
					//�ش� �� ���� �����
					//�ش� �� �÷��̾�� �˸�
					m_gmM1->ChangeMonsterState(BUTTON_STATE_WAKE, m_gmP2);
					break;
				case BUTTON_STATE_SLEEP:
					//�ش� �� ���� ����
					//�ش� �� �÷��̾�� �˸�
					m_gmM1->ChangeMonsterState(BUTTON_STATE_SLEEP, m_gmP2);
					break;
				default:
					break;
				}
				break;
			}
		}
	}
	else if (iStage2 == 2)
	{
		for (int i = 0; i < MAX_BUTTON_COUNT; i++)
		{
			Pos stTmpButton2 = m_gmMapSecond->GetButtonPointer()->GetObjectPos(i);
			if (stTmpPlayerPos2.iX == stTmpButton2.iX && stTmpPlayerPos2.iY == stTmpButton2.iY)
			{
				switch (m_gmMapFirst->GetButtonPointer()->GetButtonState(i))
				{
				case BUTTON_STATE_PASS:
					//�ƹ��� �Ͼ�� ����.
					break;
				case BUTTON_STATE_WAKE:
					//�ش� �� ���� �����
					//�ش� �� �÷��̾�� �˸�
					m_gmM2->ChangeMonsterState(BUTTON_STATE_WAKE, m_gmP2);
					break;
				case BUTTON_STATE_SLEEP:
					//�ش� �� ���� ����
					//�ش� �� �÷��̾�� �˸�
					m_gmM2->ChangeMonsterState(BUTTON_STATE_SLEEP, m_gmP2);
					break;
				default:
					break;
				}
				break;
			}
		}
	}
}

void GameManager::StartGame()
{
	srand((unsigned)time(NULL));
	//�ܼ�â ����
	SetConsoleWin();
	//�����ʱ�ȭ
	InitGame();
	//Game Start
	while (1)
	{
		if (kbhit())
		{
			//�̵�
			//�÷��̾�, �� �� �迭�� ���� -> �ڵ� �ܼ�ȭ
			MovePlayer();
			//��ư ��� Ȯ��
			//�÷��̾�, �� �� �迭�� ���� -> �ڵ� �ܼ�ȭ
			//Text �����
			m_gmDraw.EraseText(0, MAP_HEIGHT);
			CheckButton();
			//���� �̵�(1��->2��) : �̵� üũ
			//�÷��̾�, �� �� �迭�� ���� -> �ڵ� �ܼ�ȭ
			CheckStageUp();
			//�׸� ���� : �÷��̾�, ��, ����, ��ư �׸� ��ġ �ٽ� �׸���
		}
		
	}

}