#include "Block.h"

Stone::Stone()
{
	m_strBlock = "▣";
	int iStartX = MAP_WIDTH / 2, iStartY = MAP_HEIGHT / 2;
	if (!m_vecPosList.empty())
		m_vecPosList.clear();
	while (1)
	{
		for (int i = 0;i < MAX_STONE;)
		{
			int iRand_posX = rand() % (MAP_WIDTH - 2) + 1;
			int iRand_posY = rand() % (MAP_HEIGHT - 2) + 1;
			//함수화
			bool bCheck_rand_pos = true;
			if (iRand_posX == iStartX && iRand_posY == iStartY)
				bCheck_rand_pos = false;
			else if (m_vecPosList.empty());
			else
			{

				for (int j = 0;j < m_vecPosList.size();j++)
				{
					if (iRand_posX == m_vecPosList[j].m_iX && iRand_posY == m_vecPosList[j].m_iY)
					{
						bCheck_rand_pos = false;
						break;
					}
				}
			}
			if (bCheck_rand_pos == true)
			{
				BlockPosition stTmpPos;
				stTmpPos.m_iX = iRand_posX;
				stTmpPos.m_iY = iRand_posY;
				m_vecPosList.push_back(stTmpPos);
				i++;
			}
		}
		break;
	}
}

void Stone::DrawBlock()
{
	for(int i=0;i<MAX_STONE;i++)
		m_blockDrawManager.DrawObject(m_strBlock, m_vecPosList[i].m_iX, m_vecPosList[i].m_iY);
}

Food::Food()
{
	m_strBlock = "♥";
	if (!m_vecPosList.empty())
		m_vecPosList.clear();
}

void Food::DrawBlock()
{
	bool bCheck_head, bCheck_tail, bCheck_stone;
	while (1)
	{
		BlockPosition stTempPos;
		bCheck_head = true;
		bCheck_tail = true;
		bCheck_stone = true;

		//함수화
		bool bCheck_rand_pos = true;
		int iTempX = rand() % (MAP_WIDTH - 2) + 1;		//1~48
		int iTempY = rand() % (MAP_HEIGHT - 2) + 1;		//1~28
		if (m_vecPosList.empty())
			break;
		else
		{
			for (int i = 0;i < m_vecPosList.size();i++)
			{
				if (iTempX == m_vecPosList[i].m_iX && iTempY == m_vecPosList[i].m_iY)
				{
					bCheck_rand_pos = false;
					break;
				}
			}
			if (bCheck_rand_pos == true)
				break;
		}

	}
}