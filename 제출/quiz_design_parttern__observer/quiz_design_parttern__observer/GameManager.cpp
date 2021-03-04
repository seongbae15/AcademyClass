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
	//베이스 맵 그리기
	DrawTowerMap();
	//플레이어 초기화, 표시
	m_gmArrPlayer[PLAYER1]->InitCharacter(1);
	m_gmArrPlayer[PLAYER2]->InitCharacter(2);
	m_gmArrPlayer[PLAYER1]->DrawCharacter();
	m_gmArrPlayer[PLAYER2]->DrawCharacter();

	//m_gmP1->InitCharacter(1);
	//m_gmP1->DrawCharacter();
	//m_gmP2->InitCharacter(2);
	//m_gmP2->DrawCharacter();

	//몬스터 초기화, 표시
	m_gmArrMonster[MONSTER_FIRST]->InitMonster(1);
	m_gmArrMonster[MONSTER_FIRST]->DrawMonster();
	m_gmArrMonster[MONSTER_SECOND]->InitMonster(2);
	m_gmArrMonster[MONSTER_SECOND]->DrawMonster();
	//m_gmM1->InitCharacter(1);
	//m_gmM1->DrawCharacter();
	//m_gmM2->InitCharacter(2);
	//m_gmM2->DrawCharacter();

	//알람 초기화
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
	//1층 체크
	Pos stTmpDoor1 = m_gmMapArr[FIRST_FLOOR]->GetDoorPointer()->GetObjectPos();

	Pos stTmpDoor2 = m_gmMapArr[SECOND_FLOOR]->GetDoorPointer()->GetObjectPos();
	//Player 1 체크
	if (m_gmArrPlayer[player_number]->GetPlayerStage() == 1
		&& stTmpPlayerPos.iX == stTmpDoor1.iX && stTmpPlayerPos.iY == stTmpDoor1.iY)
	{
		m_gmArrPlayer[player_number]->StageUpCharacter(stTmpDoor2);
		m_gmArrPlayer[player_number]->SetAlarm(m_gmArrMonster[MONSTER_SECOND]);
	}
	////Player 2 체크
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
		//맵 배열로 작성//***
		Pos stTmpButton = m_gmMapArr[iStage%2]->GetButtonPointer()->GetObjectPos(i);
		if (stTmpPlayerPos.iX == stTmpButton.iX && stTmpPlayerPos.iY == stTmpButton.iY)
		{
			switch (m_gmMapArr[iStage % 2]->GetButtonPointer()->GetButtonState(i))
			{
			case BUTTON_STATE_PASS:
				//아무일 일어나지 않음.
				break;
			case BUTTON_STATE_WAKE:
				//해당 층 몬스터 깨우기
				//해당 층 플레이어에게 알림
				m_gmArrMonster[iStage % 2]->ChangeMonsterState(BUTTON_STATE_WAKE, m_gmArrPlayer[player_number]);
				//m_gmM1->ChangeMonsterState(BUTTON_STATE_WAKE, m_gmArrPlayer[player_number]);
				break;
			case BUTTON_STATE_SLEEP:
				//해당 층 몬스터 재우기
				//해당 층 플레이어에게 알림
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
	//				//아무일 일어나지 않음.
	//				break;
	//			case BUTTON_STATE_WAKE:
	//				//해당 층 몬스터 깨우기
	//				//해당 층 플레이어에게 알림
	//				m_gmArrMonster[iStage%2]->ChangeMonsterState(BUTTON_STATE_WAKE, m_gmArrPlayer[player_number]);
	//				break;
	//			case BUTTON_STATE_SLEEP:
	//				//해당 층 몬스터 재우기
	//				//해당 층 플레이어에게 알림
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
	//				//아무일 일어나지 않음.
	//				break;
	//			case BUTTON_STATE_WAKE:
	//				//해당 층 몬스터 깨우기
	//				//해당 층 플레이어에게 알림
	//				m_gmM1->ChangeMonsterState(BUTTON_STATE_WAKE, m_gmP2);
	//				break;
	//			case BUTTON_STATE_SLEEP:
	//				//해당 층 몬스터 재우기
	//				//해당 층 플레이어에게 알림
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
	//				//아무일 일어나지 않음.
	//				break;
	//			case BUTTON_STATE_WAKE:
	//				//해당 층 몬스터 깨우기
	//				//해당 층 플레이어에게 알림
	//				m_gmM2->ChangeMonsterState(BUTTON_STATE_WAKE, m_gmP2);
	//				break;
	//			case BUTTON_STATE_SLEEP:
	//				//해당 층 몬스터 재우기
	//				//해당 층 플레이어에게 알림
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
	//콘솔창 설정
	SetConsoleWin();
	//게임초기화
	InitGame();
	//Game Start
	while (1)
	{
		//이동
		int iMovePlayer;
		iMovePlayer = MovePlayer();
		//Text 지우기
		m_gmDraw.EraseText(0, MAP_HEIGHT);
		//버튼 기능 확인
		CheckButton(iMovePlayer);
		//도어 이동(1층->2층) : 이동 체크
		//플레이어, 맵 층 배열로 구성 -> 코드 단순화
		CheckStageUp(iMovePlayer);
		//GameOver 체크
		if (m_gmArrPlayer[PLAYER1]->GetPlayerState() == PLAYER_STATE_DEAD && m_gmArrPlayer[PLAYER2]->GetPlayerState() == PLAYER_STATE_DEAD)
		{
			m_gmDraw.DispText("!!! Game Over !!!", 0, 0);
			
			break;
		}
		//Game 완료 조건 체크
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
		//그림 복구 : 플레이어, 벽, 몬스터, 버튼 그림 위치 다시 그리기
		//다시 그리기(버튼, 몬스터, 플레이어)
		m_gmMapArr[FIRST_FLOOR]->GetButtonPointer()->DrawObject(1);
		m_gmMapArr[SECOND_FLOOR]->GetButtonPointer()->DrawObject(2);
		m_gmMapArr[FIRST_FLOOR]->GetDoorPointer()->DrawObject(1);
		m_gmMapArr[SECOND_FLOOR]->GetDoorPointer()->DrawObject(2);
		//m_gmP1->DrawCharacter();
		//m_gmP2->DrawCharacter();
	}

}