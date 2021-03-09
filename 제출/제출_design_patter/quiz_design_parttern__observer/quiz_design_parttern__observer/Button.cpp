#include "Button.h"

void Button::SetObj(int stage)
{
	m_iStage = stage;
	m_strObject = "¡Ú";
	ButtonInfo stTmpB;
	Pos stTmpButtonPos;
	int iRandStatte;
	for (int i = 0; i < MAX_BUTTON_COUNT;i++)
	{
		if (i < (MAX_BUTTON_COUNT/2))
		{
			stTmpB.m_stButtonPos.iX = MAP_WIDTH / 2 - 2;
			stTmpB.m_stButtonPos.iY = 1 + i;
		}
		else
		{
			stTmpB.m_stButtonPos.iX = MAP_WIDTH / 2 + 2;
			stTmpB.m_stButtonPos.iY = 1 + i%(MAX_BUTTON_COUNT / 2);
		}
		while (1)
		{
			bool bCheck_collsion = false;
			iRandStatte = rand() % 3;
			if (m_vecButtonInfo.empty())
				break;
			else
			{
				if (m_vecButtonInfo.size() < (MAX_BUTTON_COUNT/2))
				{
					for (int j = 0; j < m_vecButtonInfo.size(); j++)
					{
						if (m_vecButtonInfo[j].eButton_state == (BUTTON_STATE)iRandStatte)
						{
							bCheck_collsion = true;
							break;
						}
					}
				}
				else if (m_vecButtonInfo.size() == (MAX_BUTTON_COUNT / 2))
					break;
				else
				{
					for (int j = (MAX_BUTTON_COUNT / 2); j < m_vecButtonInfo.size(); j++)
					{
						if (m_vecButtonInfo[j].eButton_state == (BUTTON_STATE)iRandStatte)
						{
							bCheck_collsion = true;
							break;
						}
					}
				}
				if (!bCheck_collsion)
					break;
			}
		}
		stTmpB.eButton_state = (BUTTON_STATE)iRandStatte;
		m_vecButtonInfo.push_back(stTmpB);
	}
}

void Button::DrawObject(int stage)
{
	SKY_BLUE
	for (int i = 0; i < MAX_BUTTON_COUNT; i++)
	{
		if (m_iStage == 1)
			m_objDrawManager.DrawObject(m_strObject, m_vecButtonInfo[i].m_stButtonPos.iX, m_vecButtonInfo[i].m_stButtonPos.iY + (MAP_HEIGHT + 5));
		else if (m_iStage == 2)
			m_objDrawManager.DrawObject(m_strObject, m_vecButtonInfo[i].m_stButtonPos.iX, m_vecButtonInfo[i].m_stButtonPos.iY);
	}
	ORIGINAL
}