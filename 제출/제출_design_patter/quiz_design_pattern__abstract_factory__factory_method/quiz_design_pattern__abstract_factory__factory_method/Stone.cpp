#include "Stone.h"

Stone::Stone()
{
	m_strBlock = "¢Ã";
}

void Stone::CreateBlock()
{
	bool bCheck_pos;
	if (!m_vecBlockPos.empty())
		m_vecBlockPos.clear();
	while (1)
	{
		for (int i = 0; i < MAX_STONE_COUNT;)
		{
			bCheck_pos = true;
			int iRandomX = rand() % (MAP_WIDTH - 2) + 1;
			int iRandomY = rand() % (MAP_HEIGHT - 2) + 1;
			if (m_vecBlockPos.empty());
			else if (iRandomX == MAP_WIDTH / 2 && iRandomY == MAP_HEIGHT / 2)
				bCheck_pos = false;
			else
			{
				for (int j = 0; j < i; j++)
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
				i++;
			}
		}
		break;
	}
}

void Stone::DrawBlock()
{
	for(int i=0;i<MAX_STONE_COUNT;i++)
		m_blockDrawManager.DrawObject(m_strBlock, m_vecBlockPos[i].iX, m_vecBlockPos[i].iY);
}