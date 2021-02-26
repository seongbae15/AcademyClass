#include "Snake.h"

void Snake::SetSnakeMoveArrange(int Width, int Height)
{
	m_iMinX = 0;
	m_iMinY = 0;
	m_iMaxX = Width - 1;
	m_iMaxY = Height - 1;
}

void Snake::InitSnake(int Width, int Height)
{
	SetSnakeMoveArrange(Width, Height);
	if (!m_listSnake.empty())
		m_listSnake.clear();
	m_stSnake.m_iX = Width / 2;
	m_stSnake.m_iY = Height / 2;
	m_listSnake.push_back(m_stSnake);
	//m_stSnake.m_iY = START_Y + 1;
	//m_listSnake.push_back(m_stSnake);
	//m_stSnake.m_iY = START_Y + 2;
	//m_listSnake.push_back(m_stSnake);
	//m_stSnake.m_iY = START_Y + 3;
	//m_listSnake.push_back(m_stSnake);
	//m_stSnake.m_iY = START_Y + 4;
	//m_listSnake.push_back(m_stSnake);
	m_bMoveState = false;
	m_strSnakeHead = "▲";
	m_strSnakeTail = "◇";
	m_eDirection = SNAKE_DIRECTION_STOP;
	m_eLastDirection = m_eDirection;
}

void Snake::DrawSnake()
{
	for (auto iter = m_listSnake.begin(); iter != m_listSnake.end(); iter++)
	{
		if (iter == m_listSnake.begin())
			snakeDrawManager.DrawObject(m_strSnakeHead, iter->m_iX, iter->m_iY);
		else
			snakeDrawManager.DrawObject(m_strSnakeTail, iter->m_iX, iter->m_iY);
	}
}

void Snake::SetDirection(int keyInput)
{
	//enum 사용 재확인
	SNAKE_DIRECTION eTempDirection;
	eTempDirection = (SNAKE_DIRECTION)keyInput;
	switch (eTempDirection)
	{
	case SNAKE_DIRECTION_UP:
		if (m_eLastDirection == SNAKE_DIRECTION_DOWN)
			m_eDirection = m_eLastDirection;
		else
			m_eDirection = eTempDirection;
		m_bMoveState = true;
		break;
	case SNAKE_DIRECTION_DOWN:
		if (m_eLastDirection == SNAKE_DIRECTION_UP)
			m_eDirection = m_eLastDirection;
		else
			m_eDirection = eTempDirection;
		m_bMoveState = true;
		break;
	case SNAKE_DIRECTION_LEFT:
		if (m_eLastDirection == SNAKE_DIRECTION_RIGHT)
			m_eDirection = m_eLastDirection;
		else
			m_eDirection = eTempDirection;
		m_bMoveState = true;
		break;
	case SNAKE_DIRECTION_RIGHT:
		if (m_eLastDirection == SNAKE_DIRECTION_LEFT)
			m_eDirection = m_eLastDirection;
		else
			m_eDirection = eTempDirection;
		m_bMoveState = true;
		break;
	default:
		break;
	}
	//m_eDirection = (SNAKE_DIRECTION)keyInput;
	//switch (m_eDirection)
	//{
	//case SNAKE_DIRECTION_UP:
	//	if (m_eLastDirection == SNAKE_DIRECTION_DOWN)
	//		m_eDirection = m_eLastDirection;
	//	else
	//		m_strSnakeHead = "▲";
	//	m_bMoveState = true;
	//	break;
	//case SNAKE_DIRECTION_DOWN:
	//	if (m_eLastDirection == SNAKE_DIRECTION_UP)
	//		m_eDirection = m_eLastDirection;
	//	else
	//		m_strSnakeHead = "▼";
	//	m_bMoveState = true;
	//	break;
	//case SNAKE_DIRECTION_LEFT:
	//	if (m_eLastDirection == SNAKE_DIRECTION_RIGHT)
	//		m_eDirection = m_eLastDirection;
	//	else
	//		m_strSnakeHead = "◀";
	//	m_bMoveState = true;
	//	break;
	//case SNAKE_DIRECTION_RIGHT:
	//	if (m_eLastDirection == SNAKE_DIRECTION_LEFT)
	//		m_eDirection = m_eLastDirection;
	//	else
	//		m_strSnakeHead = "▶";
	//	m_bMoveState = true;
	//	break;
	//default:
	//	break;
	//}
}

void Snake::MoveSnake()
{
	if (m_bMoveState == true)
	{
		auto iter = m_listSnake.begin();
		auto iterEnd = m_listSnake.rbegin();
		snakeDrawManager.EraseObject(iterEnd->m_iX, iterEnd->m_iY);
		//Temp Var for Data Moving
		int iTempX1, iTempY1;
		int iTempX2, iTempY2;
		iTempX1 = iter->m_iX;
		iTempY1 = iter->m_iY;
		//Move Head
		switch (m_eDirection)
		{
		case SNAKE_DIRECTION_UP:
			if (iter->m_iY > m_iMinY)
			{
				m_strSnakeHead = "▲";
				iter->m_iY--;
			}
			break;
		case SNAKE_DIRECTION_DOWN:
			if (iter->m_iY < m_iMaxY)
			{
				m_strSnakeHead = "▼";
				iter->m_iY++;
			}
			break;
		case SNAKE_DIRECTION_LEFT:
			if (iter->m_iX > m_iMinX)
			{
				m_strSnakeHead = "◀";
				iter->m_iX--;
			}
			break;
		case SNAKE_DIRECTION_RIGHT:
			if (iter->m_iX < m_iMaxX)
			{
				m_strSnakeHead = "▶";
				iter->m_iX++;
			}
			break;
		default:
			break;
		}
		//Move Body & Tail
		iter++;
		for (iter; iter != m_listSnake.end(); iter++)
		{
			iTempX2 = iter->m_iX;
			iTempY2 = iter->m_iY;
			iter->m_iX = iTempX1;
			iter->m_iY = iTempY1;
			iTempX1 = iTempX2;
			iTempY1 = iTempY2;
		}
		m_eLastDirection = m_eDirection;

	}
	else
		return;
}

void Snake::CreateTail()
{
	SNAKE_DIRECTION eTempTailDirection;
	auto iter = m_listSnake.rbegin();
	auto lastIter = iter++;
	//Decide tail direction
	if (m_listSnake.size() == 1)
		eTempTailDirection = m_eDirection;
	else
	{
		lastIter->m_iX;
		lastIter->m_iY;
		if ((lastIter->m_iX - iter->m_iX) == 1 && (lastIter->m_iY - iter->m_iY) == 0)
			eTempTailDirection = SNAKE_DIRECTION_LEFT;
		else if ((lastIter->m_iX - iter->m_iX) == -1 && (lastIter->m_iY - iter->m_iY) == 0)
			eTempTailDirection = SNAKE_DIRECTION_RIGHT;
		else if ((lastIter->m_iX - iter->m_iX) == 0 && (lastIter->m_iY - iter->m_iY) == 1)
			eTempTailDirection = SNAKE_DIRECTION_UP;
		else if ((lastIter->m_iX - iter->m_iX) == 0 && (lastIter->m_iY - iter->m_iY) == -1)
			eTempTailDirection = SNAKE_DIRECTION_DOWN;
		else
			eTempTailDirection = SNAKE_DIRECTION_STOP;
	}
	switch (eTempTailDirection)
	{
	case SNAKE_DIRECTION_STOP:
		break;
	case SNAKE_DIRECTION_UP:
		m_stSnake.m_iX = lastIter->m_iX;
		m_stSnake.m_iY = lastIter->m_iY + 1;
		break;
	case SNAKE_DIRECTION_DOWN:
		m_stSnake.m_iX = lastIter->m_iX;
		m_stSnake.m_iY = lastIter->m_iY - 1;
		break;
	case SNAKE_DIRECTION_LEFT:
		m_stSnake.m_iX = lastIter->m_iX + 1;
		m_stSnake.m_iY = lastIter->m_iY;
		break;
	case SNAKE_DIRECTION_RIGHT:
		m_stSnake.m_iX = lastIter->m_iX - 1;
		m_stSnake.m_iY = lastIter->m_iY;
		break;
	default:
		break;
	}
	m_listSnake.push_back(m_stSnake);
	snakeDrawManager.DrawObject(m_strSnakeTail, m_stSnake.m_iX, m_stSnake.m_iY);
}