#include "Snake.h"

Snake::Snake()
{

}

void Snake::CreateBlock()
{
	BlockPos stTempPos;
	m_strHead = "¡ã";
	m_strTail = "¡Þ";
	m_eDirection = SNAKE_DIRECTION_STOP;
	m_eLastDirection = m_eDirection;
	//Init Position Set
	stTempPos.iX = MAP_WIDTH / 2;
	stTempPos.iY = MAP_HEIGHT / 2;
	m_vecBlockPos.push_back(stTempPos);
}

void Snake::DrawBlock()
{
	for (int i = 0; i < m_vecBlockPos.size(); i++)
	{
		if (i == 0)
			m_blockDrawManager.DrawObject(m_strHead, m_vecBlockPos[i].iX, m_vecBlockPos[i].iY);
		else
			m_blockDrawManager.DrawObject(m_strTail, m_vecBlockPos[i].iX,m_vecBlockPos[i].iY);
	}
}

void Snake::SetSnakeDirection(int keyboard_input)
{
	SNAKE_DIRECTION eTempDirection;
	eTempDirection = (SNAKE_DIRECTION)keyboard_input;
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
}

void Snake::MoveSnake()
{
	if (m_bMoveState == true)
	{
		auto iter = m_vecBlockPos.begin();
		auto iterEnd = m_vecBlockPos.rbegin();
		m_blockDrawManager.EraseObject(iterEnd->iX, iterEnd->iY);
		//Temp Var for Data Moving
		int iTempX1, iTempY1;
		int iTempX2, iTempY2;
		iTempX1 = iter->iX;
		iTempY1 = iter->iY;
		//Move Head
		switch (m_eDirection)
		{
		case SNAKE_DIRECTION_UP:
			if (iter->iY > 0)
			{
				m_strHead = "¡ã";
				iter->iY--;
			}
			break;
		case SNAKE_DIRECTION_DOWN:
			if (iter->iY < MOVE_MAX_Y)
			{
				m_strHead = "¡å";
				iter->iY++;
			}
			break;
		case SNAKE_DIRECTION_LEFT:
			if (iter->iX > 0)
			{
				m_strHead = "¢¸";
				iter->iX--;
			}
			break;
		case SNAKE_DIRECTION_RIGHT:
			if (iter->iX < MOVE_MAX_X)
			{
				m_strHead = "¢º";
				iter->iX++;
			}
			break;
		default:
			break;
		}
		//Move Body & Tail
		iter++;
		for (iter; iter != m_vecBlockPos.end(); iter++)
		{
			iTempX2 = iter->iX;
			iTempY2 = iter->iY;
			iter->iX = iTempX1;
			iter->iY = iTempY1;
			iTempX1 = iTempX2;
			iTempY1 = iTempY2;
		}
		m_eLastDirection = m_eDirection;

	}
	else
		return;
}

void Snake::UpdateSnake()
{
	SNAKE_DIRECTION eTempTailDirection;
	auto iter = m_vecBlockPos.rbegin();
	auto lastIter = iter++;
	//Decide tail direction
	if (m_vecBlockPos.size() == 1)
		eTempTailDirection = m_eDirection;
	else
	{
		lastIter->iX;
		lastIter->iY;
		if ((lastIter->iX - iter->iX) == 1 && (lastIter->iY - iter->iY) == 0)
			eTempTailDirection = SNAKE_DIRECTION_LEFT;
		else if ((lastIter->iX - iter->iX) == -1 && (lastIter->iY - iter->iY) == 0)
			eTempTailDirection = SNAKE_DIRECTION_RIGHT;
		else if ((lastIter->iX - iter->iX) == 0 && (lastIter->iY - iter->iY) == 1)
			eTempTailDirection = SNAKE_DIRECTION_UP;
		else if ((lastIter->iX - iter->iX) == 0 && (lastIter->iY - iter->iY) == -1)
			eTempTailDirection = SNAKE_DIRECTION_DOWN;
		else
			eTempTailDirection = SNAKE_DIRECTION_STOP;
	}
	BlockPos stTempTailPos;
	switch (eTempTailDirection)
	{
	case SNAKE_DIRECTION_STOP:
		break;
	case SNAKE_DIRECTION_UP:
		stTempTailPos.iX = lastIter->iX;
		stTempTailPos.iY = lastIter->iY + 1;
		break;
	case SNAKE_DIRECTION_DOWN:
		stTempTailPos.iX = lastIter->iX;
		stTempTailPos.iY = lastIter->iY - 1;
		break;
	case SNAKE_DIRECTION_LEFT:
		stTempTailPos.iX = lastIter->iX + 1;
		stTempTailPos.iY = lastIter->iY;
		break;
	case SNAKE_DIRECTION_RIGHT:
		stTempTailPos.iX = lastIter->iX - 1;
		stTempTailPos.iY = lastIter->iY;
		break;
	default:
		break;
	}
	m_vecBlockPos.push_back(stTempTailPos);
	m_blockDrawManager.DrawObject(m_strTail, stTempTailPos.iX, stTempTailPos.iY);
}