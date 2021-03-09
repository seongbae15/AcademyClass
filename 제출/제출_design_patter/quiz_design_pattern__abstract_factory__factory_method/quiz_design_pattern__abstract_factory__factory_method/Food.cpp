#include "Food.h"

Food::Food()
{
	m_strBlock = "¢½";
}

void Food::CreateBlock()
{
	bool bCheck_pos = true;
	int iRandomX = rand() % (MAP_WIDTH - 2) + 1;
	int iRandomY = rand() % (MAP_HEIGHT - 2) + 1;
	if (m_vecBlockPos.empty());
	else
	{
		for (int j = 0; j < m_vecBlockPos.size(); j++)
		{
			if (iRandomX == m_vecBlockPos[j].iX && iRandomY == m_vecBlockPos[j].iY)
			{
				bCheck_pos = false;
				break;
			}
		}
	}
	if (bCheck_pos == true)
	{
		BlockPos stTempPos;
		stTempPos.iX = iRandomX;
		stTempPos.iY = iRandomY;
		m_vecBlockPos.push_back(stTempPos);
	}
}

void Food::DrawBlock()
{
	auto iterEnd = m_vecBlockPos.rbegin();
	m_blockDrawManager.DrawObject(m_strBlock, (*iterEnd).iX, (*iterEnd).iY);
}

void Food::EraseBlock(int i)
{
	m_vecBlockPos.erase(m_vecBlockPos.begin() + i);
}