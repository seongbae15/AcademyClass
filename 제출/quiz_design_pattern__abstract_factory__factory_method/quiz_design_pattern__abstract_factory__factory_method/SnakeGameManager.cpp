#include "SnakeGameManager.h"
SnakeGameManager::SnakeGameManager()
{
	m_iMapWidth = MAP_WIDTH;
	m_iMapHeight = MAP_HEIGHT;
	m_iScore = 0;
	m_iMoveTime = MOVE_TIME_DEFAULT;
	SetConsoleWindow();
	m_gmLobyView = new LobyView;
	m_gmPlayInfo = new PlayInfo;
}

void SnakeGameManager::SetConsoleWindow()
{
	char buf[256];
	int width = (m_iMapWidth * 2) + 1;
	int height = m_iMapHeight + 3;
	sprintf(buf, "mode con: lines=%d cols=%d", height, width);
	system(buf);
}

void SnakeGameManager::DispMainLoby()
{
	m_gmDrawManager.DrawBaseMap(m_iMapWidth, m_iMapHeight);
	m_gmDrawManager.DispText("Score : ", m_iMapWidth, m_iMapHeight + 2);
	cout << m_iScore;
	m_gmDrawManager.DispText("★ ☆ ★ Sanke Game ★ ☆ ★", m_iMapWidth, m_iMapHeight * 0.2f);
	m_gmDrawManager.DispText("1. 게임 시작", m_iMapWidth, m_iMapHeight * 0.3f);
	m_gmDrawManager.DispText("2. 게임 종료", m_iMapWidth, m_iMapHeight * 0.4f);
	m_gmDrawManager.DispText("선택 : ", m_iMapWidth, m_iMapHeight * 0.5f);
}

//void SnakeGameManager::KeyboardInput()
//{
//	if (kbhit())
//	{
//		int iKey = getch();
//		m_gmSnake.SetDirection(iKey);
//	}
//}

//bool SnakeGameManager::CheckStonePos(int posX, int posY)
//{
//	//Check Stone Position
//	for (int i = 0; i < MAX_STONE_COUNT; i++)
//	{
//		if (m_gmStone.getStonePosX(i) == posX && m_gmStone.getStonePosY(i) == posY)
//		{
//			return false;
//		}
//	}
//	return true;
//}

//bool SnakeGameManager::CheckEat(int posX, int posY)
//{
//	FoodPosition stTempFoodPos;
//	int iFoodCount = m_gmFood.getFoodCount();
//	for (int i = 0; i < iFoodCount; i++)
//	{
//		stTempFoodPos = m_gmFood.getPosition(i);
//		if (stTempFoodPos.m_iX == posX && stTempFoodPos.m_iY == posY)
//		{
//			//Delete Food
//			m_gmFood.DeleteFoodPos(i);
//			return true;
//		}
//	}
//	return false;
//
//}

//void SnakeGameManager::CreateFood()
//{
//	bool bFoodHeadCheck, bFoodStoneCheck, bFoodTailCheck;
//
//	while (1)
//	{
//		FoodPosition stTempFoodLastPos;
//		bFoodStoneCheck = true;
//		bFoodHeadCheck = true;
//		bFoodTailCheck = true;
//		m_gmFood.MakeFoodPos(m_iMapWidth, m_iMapHeight);
//		stTempFoodLastPos = m_gmFood.getLastPos();
//		//Check Food - Stone Position
//		bFoodStoneCheck = CheckStonePos(stTempFoodLastPos.m_iX, stTempFoodLastPos.m_iY);
//		//Check Food - Snake Position
//		bFoodHeadCheck = CheckHeadPos(stTempFoodLastPos.m_iX, stTempFoodLastPos.m_iY);
//		bFoodTailCheck = CheckTailPos(stTempFoodLastPos.m_iX, stTempFoodLastPos.m_iY);
//
//		if (bFoodStoneCheck && bFoodHeadCheck && bFoodTailCheck)
//		{
//			m_gmFood.DrawFood();
//			return;
//		}
//		else
//			m_gmFood.DeleteFoodPos();
//	}
//}

//bool SnakeGameManager::CheckHeadPos(int posX, int posY)
//{
//	list<SnakePos> listTempSnakePos;
//	listTempSnakePos = m_gmSnake.GetSnakePos();
//	auto iter = listTempSnakePos.begin();
//	if (posX == iter->m_iX && posY == iter->m_iY)
//		return false;
//	else
//		return true;
//}
//
//bool SnakeGameManager::CheckTailPos(int posX, int posY)
//{
//	list<SnakePos> listTempSnakePos;
//	listTempSnakePos = m_gmSnake.GetSnakePos();
//	auto iter = listTempSnakePos.begin();
//	for (++iter; iter != listTempSnakePos.end(); iter++)
//	{
//		if (posX == iter->m_iX && posY == iter->m_iY)
//			return false;
//	}
//	return true;
//}
//bool SnakeGameManager::CheckWallPos(int posX, int posY)
//{
//	if (posX == 0 || posX == m_iMapWidth - 1)
//		return false;
//	else if (posY == 0 || posY == m_iMapHeight - 1)
//		return false;
//	else
//		return true;
//}
//
//bool SnakeGameManager::CheckGameOver(int posX, int posY)
//{
//	bool bStoneCheck;
//	bool bTailCheck;
//	bool bWallCheck;
//	bStoneCheck = CheckStonePos(posX, posY);
//	bTailCheck = CheckTailPos(posX, posY);
//	bWallCheck = CheckWallPos(posX, posY);
//	if (!bStoneCheck || !bTailCheck || !bWallCheck)
//		return true;
//	else
//		return false;
//}
//
//void SnakeGameManager::UpdateGameInfo()
//{
//	//Speed Up
//	if (m_iMoveTime <= MOVE_TIME_MIN)
//		m_iMoveTime = MOVE_TIME_MIN;
//	else
//		m_iMoveTime -= MOVE_TIME_SPEED_UP;
//	//Get Score
//	m_iScore++;
//	//m_gmDrawManager.DispText("Score : ", m_iMapWidth, m_iMapHeight + 2);
//	gotoxy(m_iMapWidth + 4, m_iMapHeight + 2);
//	cout << m_iScore;
//}
//
//void SnakeGameManager::DispGameOver()
//{
//	system("cls");
//	char chKeySpace;
//	m_gmDrawManager.DrawBaseMap(m_iMapWidth, m_iMapHeight);
//	m_gmDrawManager.DispText("★ ☆ ★ Game Over ★ ☆ ★", m_iMapWidth, m_iMapHeight * 0.5f);
//	m_gmDrawManager.DispText("Continu : Space Bar", m_iMapWidth, m_iMapHeight * 0.6f);
//	while (1)
//	{
//		chKeySpace = getch();
//		switch (chKeySpace)
//		{
//		case SPACE_BAR:
//			return;
//		default:
//			break;
//		}
//	}
//}
//
//
//void SnakeGameManager::GameStart()
//{
//	int iOldMoveClock, iCurMoveClock;
//	int iOldFoodClock, iCurFoodClock;
//	bool bGameOverState = false;
//	bool bEatState;
//	//Draw Map & Text
//	m_gmDrawManager.DrawBaseMap(m_iMapWidth, m_iMapHeight);
//	m_gmDrawManager.DispText("Score : ", m_iMapWidth, m_iMapHeight + 2);
//	cout << m_iScore;
//	//Display Stone
//	m_gmStone.DrawStone();
//	//Display Snake
//	m_gmSnake.DrawSnake();
//	iOldMoveClock = clock();
//	iOldFoodClock = clock();
//	srand((unsigned)time(NULL));
//	while (!bGameOverState)
//	{
//		//Draw Food
//		iCurFoodClock = clock();
//		if (iCurFoodClock - iOldFoodClock >= 1000)
//		{
//			if (m_gmFood.getFoodCount() < MAX_FOOD_COUNT)
//				CreateFood();
//			iOldFoodClock = iCurFoodClock;
//		}
//		//Input Keyboard & Start Move & Change direction
//		KeyboardInput();
//		iCurMoveClock = clock();
//		if (iCurMoveClock - iOldMoveClock >= m_iMoveTime)
//		{
//			//Move Snake
//			m_gmSnake.MoveSnake();
//			//Check Eating
//			SnakePos stTempHeadPos = m_gmSnake.GetHeadPos();
//			bEatState = CheckEat(stTempHeadPos.m_iX, stTempHeadPos.m_iY);
//			//Check Game Over
//			bGameOverState = CheckGameOver(stTempHeadPos.m_iX, stTempHeadPos.m_iY);
//			if (!bGameOverState)
//			{
//				if (bEatState == true)
//				{
//					//Create Tail
//					m_gmSnake.CreateTail();
//					//Update Info(Score)
//					UpdateGameInfo();
//				}
//				//Update Snake
//				m_gmSnake.DrawSnake();
//			}
//			else
//			{
//				DispGameOver();
//				return;
//			}
//			iOldMoveClock = iCurMoveClock;
//		}
//	}
//}
//
//void SnakeGameManager::GameInit()
//{
//	//Init Stone Position
//	m_gmStone.InitStonePosition(m_iMapWidth, m_iMapHeight);
//	//Init Snake Position
//	m_gmSnake.InitSnake(m_iMapWidth, m_iMapHeight);
//	//Init Food Position
//	m_gmFood.InitFood();
//	//Init Score
//	m_iScore = 0;
//	m_iMoveTime = MOVE_TIME_DEFAULT;
//}

void SnakeGameManager::GameRun()
{
	while (1)
	{
		m_gmBlock_stone = new BlockFactory;
		m_gmBlock_food = new BlockFactory;

		m_gmLobyView->Initialize();
		m_gmPlayInfo->Initialize();
		int iSelect;
		cin >> iSelect;
		//Init Game Info
		//GameInit();
		//Display Main loby screen
		//DispMainLoby();
		cin >> iSelect;
		switch (iSelect)
		{
		case 1:
			//Start Game
			system("cls");
			//GameStart();
			break;
		case 2:
			return;
		default:
			break;
		}

	}
}

