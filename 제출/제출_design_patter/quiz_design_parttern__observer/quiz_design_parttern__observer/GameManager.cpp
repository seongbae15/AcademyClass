#include "GameManager.h"

GameManager::GameManager()
{
	m_bGameOverState = false;
	m_gmMapArr[FIRST_FLOOR] = new MapFirst;
	m_gmMapArr[SECOND_FLOOR] = new MapSecond;
	m_gmArrPlayer[PLAYER1] = new Player;
	m_gmArrPlayer[PLAYER2] = new Player;
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

	//몬스터 초기화, 표시
	m_gmArrMonster[MONSTER_FIRST]->InitMonster(1);
	m_gmArrMonster[MONSTER_FIRST]->DrawMonster();
	m_gmArrMonster[MONSTER_SECOND]->InitMonster(2);
	m_gmArrMonster[MONSTER_SECOND]->DrawMonster();

	//알람 초기화
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
	}
	return bCheck_wallPos;

}

int GameManager::MovePlayer()
{
	while (1)
	{
		char chKeyIn = getch();
		bool bChecker;
		switch ((MOVE)chKeyIn)
		{
		case MOVE_UP_1:
		case MOVE_DOWN_1:
		case MOVE_LEFT_1:
		case MOVE_RIGHT_1:
			if (m_gmArrPlayer[PLAYER1]->GetPlayerState() == PLAYER_STATE_LIVE)
			{
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
			}
			else
				break;
		case MOVE_UP_2:
		case MOVE_DOWN_2:
		case MOVE_LEFT_2:
		case MOVE_RIGHT_2:
			if (m_gmArrPlayer[PLAYER2]->GetPlayerState() == PLAYER_STATE_LIVE)
			{
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
			}
			else
				break;
		default:
			break;
		}

	}
}

void GameManager::CheckStageUp(int player_number)
{
	Pos stTmpPlayerPos = m_gmArrPlayer[player_number]->GetCharacterPos();
	Pos stTmpDoor1 = m_gmMapArr[FIRST_FLOOR]->GetDoorPointer()->GetObjectPos();
	Pos stTmpDoor2 = m_gmMapArr[SECOND_FLOOR]->GetDoorPointer()->GetObjectPos();
	if (m_gmArrPlayer[player_number]->GetPlayerStage() == 1
		&& stTmpPlayerPos.iX == stTmpDoor1.iX && stTmpPlayerPos.iY == stTmpDoor1.iY)
	{
		m_gmArrPlayer[player_number]->StageUpCharacter(stTmpDoor2);
		m_gmArrPlayer[player_number]->SetAlarm(m_gmArrMonster[MONSTER_SECOND]);
	}
}

void GameManager::CheckButton(int player_number)
{
	Pos stTmpPlayerPos = m_gmArrPlayer[player_number]->GetCharacterPos();
	int iStage = m_gmArrPlayer[player_number]->GetPlayerStage();
	for (int i = 0; i < MAX_BUTTON_COUNT; i++)
	{
		Pos stTmpButton = m_gmMapArr[iStage%2]->GetButtonPointer()->GetObjectPos(i);
		if (stTmpPlayerPos.iX == stTmpButton.iX && stTmpPlayerPos.iY == stTmpButton.iY)
		{
			switch (m_gmMapArr[iStage % 2]->GetButtonPointer()->GetButtonState(i))
			{
			case BUTTON_STATE_PASS:
				break;
			case BUTTON_STATE_WAKE:
				//해당 층 몬스터 깨우기
				//해당 층 플레이어에게 알림
				m_gmArrMonster[iStage % 2]->ChangeMonsterState(BUTTON_STATE_WAKE, m_gmArrPlayer[player_number]);
				break;
			case BUTTON_STATE_SLEEP_OR_WAKE:
				//해당 층 몬스터 재우기
				//해당 층 플레이어에게 알림
				m_gmArrMonster[iStage % 2]->ChangeMonsterState(BUTTON_STATE_SLEEP_OR_WAKE, m_gmArrPlayer[player_number]);
				break;
			default:
				break;
			}
			break;
		}
	}
}

bool GameManager::CheckGameOver(int player_number)
{
	if (m_gmArrPlayer[PLAYER1]->GetPlayerState() == PLAYER_STATE_DEAD && m_gmArrPlayer[PLAYER2]->GetPlayerState() == PLAYER_STATE_DEAD)
	{
		m_gmDraw.DispText("!!! Game Over !!!", 0, MAP_HEIGHT + 2);
		getch();
		return true;
	}
	else
	{
		Pos GoalPos = m_gmMapArr[SECOND_FLOOR]->GetGoalPos();
		if (m_gmArrPlayer[player_number]->GetPlayerStage() == 2)
		{
			Pos p1Pos = m_gmArrPlayer[player_number]->GetCharacterPos();
			if (p1Pos.iX == GoalPos.iX && p1Pos.iY == GoalPos.iY)
			{
				m_gmDraw.DispText("!!!! Congraturation !!!!", 0, MAP_HEIGHT + 2);
				getch();
				return true;
			}
		}
	}
	return false;
}
void GameManager::CheckPlayerDeadAlive(int player_number)
{
	bool bPlayerDOA = true;
	//stage 확인
	int iP_stage = m_gmArrPlayer[player_number]->GetPlayerStage();
	//동일 스테이지 몬스터 상태 조건확인
	MONSTER_STATE eM_state = m_gmArrMonster[iP_stage % 2]->GetMonsterState();
	if (eM_state == MONSTER_STATE_AWAKE || eM_state == MONSTER_STATE_ATTACK)
	{
		Pos stPlayerPos = m_gmArrPlayer[player_number]->GetCharacterPos();
		Pos stMonsterPos = m_gmArrMonster[iP_stage % 2]->GetMonsterPos();
		//주변 위치 확인
		if ((stPlayerPos.iX == stMonsterPos.iX && stPlayerPos.iY == stMonsterPos.iY)
			|| (stPlayerPos.iX == stMonsterPos.iX-1 && stPlayerPos.iY == stMonsterPos.iY-1)
			|| (stPlayerPos.iX == stMonsterPos.iX-1 && stPlayerPos.iY == stMonsterPos.iY)
			|| (stPlayerPos.iX == stMonsterPos.iX-1 && stPlayerPos.iY == stMonsterPos.iY+1)
			|| (stPlayerPos.iX == stMonsterPos.iX && stPlayerPos.iY == stMonsterPos.iY)
			|| (stPlayerPos.iX == stMonsterPos.iX+1 && stPlayerPos.iY == stMonsterPos.iY+1)
			|| (stPlayerPos.iX == stMonsterPos.iX+1 && stPlayerPos.iY == stMonsterPos.iY)
			|| (stPlayerPos.iX == stMonsterPos.iX+1 && stPlayerPos.iY == stMonsterPos.iY-1))
			bPlayerDOA = false;
		else
			bPlayerDOA = true;
	}
	//플레이어 상태 변경
	if (bPlayerDOA == false)
	{
		m_gmArrPlayer[player_number]->ChangePlayerState();
		m_gmArrMonster[iP_stage % 2]->DrawMonsterAround();
	}
	
}

void GameManager::StartGame()
{
	srand((unsigned)time(NULL));
	//콘솔창 설정
	SetConsoleWin();
	//게임초기화
	InitGame();
	//Game Start
	while (!m_bGameOverState)
	{
		m_gmMapArr[FIRST_FLOOR]->GetButtonPointer()->DrawObject(1);
		m_gmMapArr[SECOND_FLOOR]->GetButtonPointer()->DrawObject(2);
		m_gmMapArr[FIRST_FLOOR]->GetDoorPointer()->DrawObject(1);
		m_gmMapArr[SECOND_FLOOR]->GetDoorPointer()->DrawObject(2);
		m_gmArrPlayer[PLAYER1]->DrawCharacter();
		m_gmArrPlayer[PLAYER2]->DrawCharacter();
		//이동
		int iMovePlayer;
		iMovePlayer = MovePlayer();
		//Text 지우기
		m_gmDraw.EraseText(0, MAP_HEIGHT);
		//버튼 기능 확인
		CheckButton(iMovePlayer);
		//도어 이동(1층->2층) : 이동 체크
		CheckStageUp(iMovePlayer);
		//PlayerDead or alive 체크(몬스터 주변 움직임 체크)
		CheckPlayerDeadAlive(iMovePlayer);
		//GameOver 체크 & Game 완료 조건 체크
		m_bGameOverState = CheckGameOver(iMovePlayer);
	}
}