#include "SnakeGameManager.h"
SnakeGameManager::SnakeGameManager()
{
	m_iMapWidth = MAP_WIDTH;
	m_iMapHeight = MAP_HEIGHT;
	m_gmLobyView = new LobyView;
	m_gmPlayView = new PlayView;
	m_gmGameOverView = new GameOverView;
	m_gmBlockStone = new Stone;
	m_gmBlockSnake = new Snake;
	m_gmBlockFood = new Food;
	SetConsoleWindow();
}

void SnakeGameManager::SetConsoleWindow()
{
	char buf[256];
	int width = (m_iMapWidth * 2) + 1;
	int height = m_iMapHeight + 3;
	sprintf(buf, "mode con: lines=%d cols=%d", height, width);
	system(buf);
}

void SnakeGameManager::KeyboardInput()
{
	if (kbhit())
	{
		int iKey = getch();
		m_gmBlockSnake->SetSnakeDirection(iKey);
	}
}

void SnakeGameManager::UpdateGameInfo()
{
	//Speed Up
	if (m_iMoveTime <= MOVE_TIME_MIN)
		m_iMoveTime = MOVE_TIME_MIN;
	else
		m_iMoveTime -= MOVE_TIME_SPEED_UP;
	//Get Score
	m_iScore++;
	gotoxy(m_iMapWidth + 4, m_iMapHeight + 2);
	cout << m_iScore;
}

bool SnakeGameManager::CheckPositionCollision(BlockPos stPos1, BlockPos stPos2)
{
	if (stPos1.iX == stPos2.iX && stPos1.iY == stPos2.iY)
		return true;
	else
		return false;
}

bool SnakeGameManager::CheckFoodPos()
{
	bool bCheck_food_stone = false;
	bool bCheck_food_snake = false;
	for (int i = 0; i < MAX_STONE_COUNT; i++)
	{
		bCheck_food_stone = CheckPositionCollision(m_gmBlockFood->getLastPostion(), m_gmBlockStone->getPosition(i));
		if (bCheck_food_stone == true)
			return true;
	}
	//Check Food - Snake Collision
	for (int i = 0; i < m_gmBlockSnake->getSizeVector(); i++)
	{
		bCheck_food_snake = CheckPositionCollision(m_gmBlockFood->getLastPostion(), m_gmBlockSnake->getPosition(i));
		if (bCheck_food_snake == true)
			return true;
	}
	return false;
}

bool SnakeGameManager::CheckEatFood()
{
	bool bCheck_snake_food = false;
	for (int i = 0; i < m_gmBlockFood->getSizeVector(); i++)
	{
		bCheck_snake_food = CheckPositionCollision(m_gmBlockSnake->getPosition(0), m_gmBlockFood->getPosition(i));
		if (bCheck_snake_food == true)
		{
			//冈捞 昏力
			m_gmBlockFood->EraseBlock(i);
			return true;
		}
	}
	return false;
}

bool SnakeGameManager::CheckGameOver()
{
	bool bCheck_head_tail = false;
	bool bCheck_head_stone = false;
	for (int i = 1; i < m_gmBlockSnake->getSizeVector(); i++)
	{
		bCheck_head_tail = CheckPositionCollision(m_gmBlockSnake->getPosition(0), m_gmBlockSnake->getPosition(i));
		if (bCheck_head_tail == true)
			return true;
	}
	for (int i = 0; i < m_gmBlockStone->getSizeVector(); i++)
	{
		bCheck_head_stone = CheckPositionCollision(m_gmBlockSnake->getPosition(0), m_gmBlockStone->getPosition(i));
		if (bCheck_head_stone == true)
			return true;
	}
	if (m_gmBlockSnake->getPosition(0).iX == 0 || m_gmBlockSnake->getPosition(0).iX == MAP_WIDTH - 1)
		return true;
	else if (m_gmBlockSnake->getPosition(0).iY == 0 || m_gmBlockSnake->getPosition(0).iY == MAP_HEIGHT - 1)
		return true;
	else
		return false;
}

void SnakeGameManager::GameStart()
{
	int iOldMoveClock, iCurMoveClock;
	int iOldFoodClock, iCurFoodClock;
	bool bGameOverState = false;
	bool bEatState = false;
	//Draw Map & Text
	m_gmPlayView->DrawView();
	m_gmDrawManager.DispText("Score : ", m_iMapWidth, m_iMapHeight + 2);
	cout << m_iScore;
	//Display Stone;
	m_gmBlockStone->DrawBlock();
	////Display Snake
	m_gmBlockSnake->DrawBlock();
	iOldMoveClock = clock();
	iOldFoodClock = clock();
	while (!bGameOverState)
	{
		//Draw Food
		iCurFoodClock = clock();
		if (iCurFoodClock - iOldFoodClock >= 1000)
		{
			if (m_gmBlockFood->getSizeVector() < MAX_FOOD_COUNT)
			{
				bool bCheck_food_pos = true;

				while (bCheck_food_pos)
				{
					m_gmBlockFood->CreateBlock();
					//Check Food - Stone Collision
					bCheck_food_pos = CheckFoodPos();
					if (bCheck_food_pos == false)
						m_gmBlockFood->DrawBlock();
					else
						m_gmBlockFood->EraseBlock();
				}
			}
			iOldFoodClock = iCurFoodClock;
		}
		//Input Keyboard & Start Move & Change direction
		KeyboardInput();
		iCurMoveClock = clock();
		if (iCurMoveClock - iOldMoveClock >= m_iMoveTime)
		{
			//Move Snake
			m_gmBlockSnake->MoveSnake();
			//Check Eating
			bEatState = CheckEatFood();
			if (bEatState == true)
			{
				//部府 积己
				m_gmBlockSnake->UpdateSnake();
				//痢荐 up
				UpdateGameInfo();
			}
			//Check Game Over
			bGameOverState = CheckGameOver();
			//Update Snake
			if (!bGameOverState)
				m_gmBlockSnake->DrawBlock();
			else
			{
				m_gmGameOverView->DrawView();
				char chKeySpace;
				while (1)
				{
					chKeySpace = getch();
					switch (chKeySpace)
					{
					case SPACE_BAR:
						return;
					default:
						break;
					}
				}
				return;
			}
			iOldMoveClock = iCurMoveClock;
		}
	}
}
void SnakeGameManager::GameInit()
{
	//Init Stone Position
	m_gmBlockStone->CreateBlock();
	//Init Snake Position
	m_gmBlockSnake->CreateBlock();
	//Init Score
	m_iScore = 0;
	m_iMoveTime = MOVE_TIME_DEFAULT;
}
void SnakeGameManager::GameClear()
{
	m_gmBlockStone->ClearBlock();
	m_gmBlockSnake->ClearBlock();
	m_gmBlockFood->ClearBlock();
}

void SnakeGameManager::Release()
{
	delete m_gmBlockFood;
	delete m_gmBlockSnake;
	delete m_gmBlockStone;
	delete m_gmGameOverView;
	delete m_gmPlayView;
	delete m_gmLobyView;
}
void SnakeGameManager::GameRun()
{
	srand((unsigned)time(NULL));
	while (1)
	{
		system("cls");
		int iSelect;
		//Display Main loby screen
		m_gmLobyView->DrawView();
		//Init Game Info
		GameInit();
		cin >> iSelect;
		switch (iSelect)
		{
		case 1:
			//Start Game
			system("cls");
			GameStart();
			GameClear();
			break;
		case 2:
			Release();
			return;
		default:
			break;
		}
	}
}