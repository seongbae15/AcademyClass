#include "GameManager.h"

GameManager::GameManager()
{
	//m_gmMapFirst = new MapFirst;
	//m_gmMapSecond = new MapSecond;
	m_gmMapArr[FIRST_FLOOR] = new MapFirst;
	m_gmMapArr[SECOND_FLOOR] = new MapSecond;
	//m_gmP1 = new Player;
	//m_gmP2 = new Player;
	m_gmArrPlayer[PLAYER2] = new Player;
	m_gmArrPlayer[PLAYER1] = new Player;

	//m_gmM1 = new Monster;
	//m_gmM2 = new Monster;
	m_gmArrMonster[MONSTER_FIRST] = new Monster;
	m_gmArrMonster[MONSTER_SECOND] = new Monster;
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
	m_gmMapArr[FIRST_FLOOR]->DrawMap();
	m_gmMapArr[SECOND_FLOOR]->DrawMap();
}

void GameManager::InitGame()
{
	m_gmMapArr[FIRST_FLOOR]->InitMap();
	m_gmMapArr[SECOND_FLOOR]->InitMap();
	//���̽� �� �׸���
	DrawTowerMap();
	//�÷��̾� �ʱ�ȭ, ǥ��
	m_gmArrPlayer[PLAYER1]->InitCharacter(1);
	m_gmArrPlayer[PLAYER2]->InitCharacter(2);
	m_gmArrPlayer[PLAYER1]->DrawCharacter();
	m_gmArrPlayer[PLAYER2]->DrawCharacter();

	//m_gmP1->InitCharacter(1);
	//m_gmP1->DrawCharacter();
	//m_gmP2->InitCharacter(2);
	//m_gmP2->DrawCharacter();

	//���� �ʱ�ȭ, ǥ��
	m_gmArrMonster[MONSTER_FIRST]->InitMonster(1);
	m_gmArrMonster[MONSTER_FIRST]->DrawMonster();
	m_gmArrMonster[MONSTER_SECOND]->InitMonster(2);
	m_gmArrMonster[MONSTER_SECOND]->DrawMonster();
	//m_gmM1->InitCharacter(1);
	//m_gmM1->DrawCharacter();
	//m_gmM2->InitCharacter(2);
	//m_gmM2->DrawCharacter();

	//�˶� �ʱ�ȭ
	//m_gmP1->SetAlarm(m_gmM1);
	//m_gmP2->SetAlarm(m_gmM1);
	m_gmArrPlayer[PLAYER1]->SetAlarm(m_gmArrMonster[MONSTER_FIRST]);
	m_gmArrPlayer[PLAYER2]->SetAlarm(m_gmArrMonster[MONSTER_FIRST]);

}

bool GameManager::CheckPlayerWallPos(int player_number)
{
	bool bCheck_wallPos = false;
	int iTmpStage = m_gmArrPlayer[player_number]->GetPlayerStage();

	for (int i = 0; i < MAX_WALL_COUNT; i++)
	{
		if (m_gmArrPlayer[player_number]->GetCharacterPos().iX == m_gmMapArr[iTmpStage%2]->GetWallPointer()->GetObjectPos(i).iX
			&& m_gmArrPlayer[player_number]->GetCharacterPos().iY == m_gmMapArr[iTmpStage % 2]->GetWallPointer()->GetObjectPos(i).iY)
		{
			bCheck_wallPos = true;
			break;
		}
		//if (m_gmArrPlayer[player_number]->GetPlayerStage() == 1)
		//{
		//	if (m_gmArrPlayer[player_number]->GetCharacterPos().iX == m_gmMapFirst->GetWallPointer()->GetObjectPos(i).iX
		//		&& m_gmArrPlayer[player_number]->GetCharacterPos().iY == m_gmMapFirst->GetWallPointer()->GetObjectPos(i).iY)
		//	{
		//		bCheck_wallPos = true;
		//		break;
		//	}
		//}
		//else if (m_gmArrPlayer[player_number]->GetPlayerStage() == 2)
		//{
		//	if (m_gmArrPlayer[player_number]->GetCharacterPos().iX == m_gmMapSecond->GetWallPointer()->GetObjectPos(i).iX
		//		&& m_gmArrPlayer[player_number]->GetCharacterPos().iY == m_gmMapSecond->GetWallPointer()->GetObjectPos(i).iY)
		//	{
		//		bCheck_wallPos = true;
		//		break;
		//	}
		//}
	}
	return bCheck_wallPos;

}

int GameManager::MovePlayer()
{
	while (1)
	{
		char chKeyIn = getch();
		bool bChecker;
		//Player1 Move
		switch ((MOVE)chKeyIn)
		{
		case MOVE_UP_1:
		case MOVE_DOWN_1:
		case MOVE_LEFT_1:
		case MOVE_RIGHT_1:
			m_gmArrPlayer[PLAYER1]->EraseCharacter();
			m_gmArrPlayer[PLAYER1]->MoveCharacter(chKeyIn);
			bChecker = CheckPlayerWallPos(PLAYER1);
			if (!bChecker)
				m_gmArrPlayer[PLAYER1]->DrawCharacter();
			else
			{
				m_gmArrPlayer[PLAYER1]->BackCharacter(chKeyIn);
				m_gmArrPlayer[PLAYER1]->DrawCharacter();
			}
			return PLAYER1;
		case MOVE_UP_2:
		case MOVE_DOWN_2:
		case MOVE_LEFT_2:
		case MOVE_RIGHT_2:
			m_gmArrPlayer[PLAYER2]->EraseCharacter();
			m_gmArrPlayer[PLAYER2]->MoveCharacter(chKeyIn);
			bChecker = CheckPlayerWallPos(PLAYER2);
			if (!bChecker)
				m_gmArrPlayer[PLAYER2]->DrawCharacter();
			else
			{
				m_gmArrPlayer[PLAYER2]->BackCharacter(chKeyIn);
				m_gmArrPlayer[PLAYER2]->DrawCharacter();
			}
			return PLAYER2;
			//m_gmP2->EraseCharacter();
			//m_gmP2->MoveCharacter(chKeyIn);
			//for (int i = 0; i < MAX_WALL_COUNT; i++)
			//{
			//	if (m_gmP2->GetPlayerStage() == 1)
			//	{
			//		if (m_gmP2->GetCharacterPos().iX == m_gmMapFirst->GetWallPointer()->GetObjectPos(i).iX
			//			&& m_gmP2->GetCharacterPos().iY == m_gmMapFirst->GetWallPointer()->GetObjectPos(i).iY)
			//		{
			//			bCheck_wallPos = true;
			//			break;
			//		}

			//	}
			//	else if (m_gmP2->GetPlayerStage() == 2)
			//	{
			//		if (m_gmP2->GetCharacterPos().iX == m_gmMapSecond->GetWallPointer()->GetObjectPos(i).iX
			//			&& m_gmP2->GetCharacterPos().iY == m_gmMapSecond->GetWallPointer()->GetObjectPos(i).iY)
			//		{
			//			bCheck_wallPos = true;
			//			break;
			//		}
			//	}
			//}
			//if (!bCheck_wallPos)
			//	m_gmP2->DrawCharacter();
			//else
			//{
			//	m_gmP2->BackCharacter(chKeyIn);
			//	m_gmP2->DrawCharacter();
			//}
			//break;
		default:
			break;
		}

	}
}

void GameManager::CheckStageUp(int player_number)
{
	Pos stTmpPlayerPos = m_gmArrPlayer[player_number]->GetCharacterPos();
	//Pos stTmpPlayerPos1 = m_gmP1->GetCharacterPos();
	//Pos stTmpPlayerPos2 = m_gmP2->GetCharacterPos();
	//1�� üũ
	Pos stTmpDoor1 = m_gmMapArr[FIRST_FLOOR]->GetDoorPointer()->GetObjectPos();

	Pos stTmpDoor2 = m_gmMapArr[SECOND_FLOOR]->GetDoorPointer()->GetObjectPos();
	//Player 1 üũ
	if (m_gmArrPlayer[player_number]->GetPlayerStage() == 1
		&& stTmpPlayerPos.iX == stTmpDoor1.iX && stTmpPlayerPos.iY == stTmpDoor1.iY)
	{
		m_gmArrPlayer[player_number]->StageUpCharacter(stTmpDoor2);
		m_gmArrPlayer[player_number]->SetAlarm(m_gmArrMonster[MONSTER_SECOND]);
	}
	////Player 2 üũ
	//else if (m_gmP2->GetPlayerStage() == 1
	//	&& stTmpPlayerPos2.iX == stTmpDoor1.iX && stTmpPlayerPos2.iY == stTmpDoor1.iY)
	//{
	//	m_gmP2->StageUpCharacter(stTmpDoor2);
	//	m_gmP2->SetAlarm(m_gmM2);
	//}
}

void GameManager::CheckButton(int player_number)
{
	//Pos stTmpPlayerPos1 = m_gmArrPlayer[PLAYER1]->GetCharacterPos();
	Pos stTmpPlayerPos = m_gmArrPlayer[player_number]->GetCharacterPos();
	int iStage = m_gmArrPlayer[player_number]->GetPlayerStage();
	
	//int iStage1 = m_gmArrPlayer[PLAYER1]->GetPlayerStage();
	//int iStage2 = m_gmArrPlayer[PLAYER2]->GetPlayerStage();
	for (int i = 0; i < MAX_BUTTON_COUNT; i++)
	{
		//�� �迭�� �ۼ�//***
		Pos stTmpButton = m_gmMapArr[iStage%2]->GetButtonPointer()->GetObjectPos(i);
		if (stTmpPlayerPos.iX == stTmpButton.iX && stTmpPlayerPos.iY == stTmpButton.iY)
		{
			switch (m_gmMapArr[iStage % 2]->GetButtonPointer()->GetButtonState(i))
			{
			case BUTTON_STATE_PASS:
				//�ƹ��� �Ͼ�� ����.
				break;
			case BUTTON_STATE_WAKE:
				//�ش� �� ���� �����
				//�ش� �� �÷��̾�� �˸�
				m_gmArrMonster[iStage % 2]->ChangeMonsterState(BUTTON_STATE_WAKE, m_gmArrPlayer[player_number]);
				//m_gmM1->ChangeMonsterState(BUTTON_STATE_WAKE, m_gmArrPlayer[player_number]);
				break;
			case BUTTON_STATE_SLEEP:
				//�ش� �� ���� ����
				//�ش� �� �÷��̾�� �˸�
				m_gmArrMonster[iStage % 2]->ChangeMonsterState(BUTTON_STATE_SLEEP, m_gmArrPlayer[player_number]);
				break;
			default:
				break;
			}
			break;
		}
	}
	
	//else if (iStage == 2)
	//{
	//	for (int i = 0; i < MAX_BUTTON_COUNT; i++)
	//	{
	//		
	//		Pos stTmpButton2 = m_gmMapSecond->GetButtonPointer()->GetObjectPos(i);
	//		if (stTmpPlayerPos.iX == stTmpButton2.iX && stTmpPlayerPos.iY == stTmpButton2.iY)
	//		{
	//			switch (m_gmMapSecond->GetButtonPointer()->GetButtonState(i))
	//			{
	//			case BUTTON_STATE_PASS:
	//				//�ƹ��� �Ͼ�� ����.
	//				break;
	//			case BUTTON_STATE_WAKE:
	//				//�ش� �� ���� �����
	//				//�ش� �� �÷��̾�� �˸�
	//				m_gmArrMonster[iStage%2]->ChangeMonsterState(BUTTON_STATE_WAKE, m_gmArrPlayer[player_number]);
	//				break;
	//			case BUTTON_STATE_SLEEP:
	//				//�ش� �� ���� ����
	//				//�ش� �� �÷��̾�� �˸�
	//				m_gmArrMonster[iStage % 2]->ChangeMonsterState(BUTTON_STATE_SLEEP, m_gmArrPlayer[player_number]);
	//				break;
	//			default:
	//				break;
	//			}
	//			break;
	//		}
	//	}
	//}
	//Pos stTmpPlayerPos2 = m_gmP2->GetCharacterPos();
	//if (iStage2 == 1)
	//{
 //		for (int i = 0; i < MAX_BUTTON_COUNT; i++)
	//	{
	//		Pos stTmpButton1 = m_gmMapFirst->GetButtonPointer()->GetObjectPos(i);
	//		if (stTmpPlayerPos2.iX == stTmpButton1.iX && stTmpPlayerPos2.iY == stTmpButton1.iY)
	//		{
	//			switch (m_gmMapFirst->GetButtonPointer()->GetButtonState(i))
	//			{
	//			case BUTTON_STATE_PASS:
	//				//�ƹ��� �Ͼ�� ����.
	//				break;
	//			case BUTTON_STATE_WAKE:
	//				//�ش� �� ���� �����
	//				//�ش� �� �÷��̾�� �˸�
	//				m_gmM1->ChangeMonsterState(BUTTON_STATE_WAKE, m_gmP2);
	//				break;
	//			case BUTTON_STATE_SLEEP:
	//				//�ش� �� ���� ����
	//				//�ش� �� �÷��̾�� �˸�
	//				m_gmM1->ChangeMonsterState(BUTTON_STATE_SLEEP, m_gmP2);
	//				break;
	//			default:
	//				break;
	//			}
	//			break;
	//		}
	//	}
	//}
	//else if (iStage2 == 2)
	//{
	//	for (int i = 0; i < MAX_BUTTON_COUNT; i++)
	//	{
	//		Pos stTmpButton2 = m_gmMapSecond->GetButtonPointer()->GetObjectPos(i);
	//		if (stTmpPlayerPos2.iX == stTmpButton2.iX && stTmpPlayerPos2.iY == stTmpButton2.iY)
	//		{
	//			switch (m_gmMapFirst->GetButtonPointer()->GetButtonState(i))
	//			{
	//			case BUTTON_STATE_PASS:
	//				//�ƹ��� �Ͼ�� ����.
	//				break;
	//			case BUTTON_STATE_WAKE:
	//				//�ش� �� ���� �����
	//				//�ش� �� �÷��̾�� �˸�
	//				m_gmM2->ChangeMonsterState(BUTTON_STATE_WAKE, m_gmP2);
	//				break;
	//			case BUTTON_STATE_SLEEP:
	//				//�ش� �� ���� ����
	//				//�ش� �� �÷��̾�� �˸�
	//				m_gmM2->ChangeMonsterState(BUTTON_STATE_SLEEP, m_gmP2);
	//				break;
	//			default:
	//				break;
	//			}
	//			break;
	//		}
	//	}
	//}
}

void GameManager::Releas()
{
	delete m_gmMapArr;
	delete m_gmArrPlayer;
	delete m_gmArrMonste;
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
		//�̵�
		int iMovePlayer;
		iMovePlayer = MovePlayer();
		//Text �����
		m_gmDraw.EraseText(0, MAP_HEIGHT);
		//��ư ��� Ȯ��
		CheckButton(iMovePlayer);
		//���� �̵�(1��->2��) : �̵� üũ
		//�÷��̾�, �� �� �迭�� ���� -> �ڵ� �ܼ�ȭ
		CheckStageUp(iMovePlayer);
		//GameOver üũ
		if (m_gmArrPlayer[PLAYER1]->GetPlayerState() == PLAYER_STATE_DEAD && m_gmArrPlayer[PLAYER2]->GetPlayerState() == PLAYER_STATE_DEAD)
		{
			m_gmDraw.DispText("!!! Game Over !!!", 0, 0);
			
			break;
		}
		//Game �Ϸ� ���� üũ
		Pos GoalPos = m_gmMapArr[SECOND_FLOOR]->GetGoalPos();
		if (m_gmArrPlayer[PLAYER1]->GetPlayerStage() == 2)
		{
			Pos p1Pos = m_gmArrPlayer[PLAYER1]->GetCharacterPos();
			if (p1Pos.iX == GoalPos.iX && p1Pos.iY == GoalPos.iY)
			{
				m_gmDraw.DispText("!!!! Congraturation !!!!", 0, 0);
				break;
			}
				
		}
		if (m_gmArrPlayer[PLAYER2]->GetPlayerStage() == 2)
		{
			Pos p2Pos = m_gmArrPlayer[PLAYER2]->GetCharacterPos();
			if (p2Pos.iX == GoalPos.iX && p2Pos.iY == GoalPos.iY)
			{
				m_gmDraw.DispText("!!!! Congraturation !!!!", 0, 0);
				return;
			}
		}
		//�׸� ���� : �÷��̾�, ��, ����, ��ư �׸� ��ġ �ٽ� �׸���
		//�ٽ� �׸���(��ư, ����, �÷��̾�)
		m_gmMapArr[FIRST_FLOOR]->GetButtonPointer()->DrawObject(1);
		m_gmMapArr[SECOND_FLOOR]->GetButtonPointer()->DrawObject(2);
		m_gmMapArr[FIRST_FLOOR]->GetDoorPointer()->DrawObject(1);
		m_gmMapArr[SECOND_FLOOR]->GetDoorPointer()->DrawObject(2);
		//m_gmP1->DrawCharacter();
		//m_gmP2->DrawCharacter();
	}

}