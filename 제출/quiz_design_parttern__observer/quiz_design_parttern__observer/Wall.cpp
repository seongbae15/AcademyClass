#include "Wall.h"

void Wall::SetObj(int stage)
{
	m_iStage = stage;
	m_strObject = "¢Ç";
	Pos stTempWall;
	for (int i = 0; i < MAX_WALL_COUNT;i++)
	{
		stTempWall.iX = MAP_WIDTH/2-2+i;
		stTempWall.iY = 4;
		m_vecWallPos.push_back(stTempWall);
	}
}

void Wall::DrawObject(int stage)
{
	DARK_BLUE
	for (int i = 0; i < MAX_WALL_COUNT; i++)
	{
		if (m_iStage == 1)
			m_objDrawManager.DrawObject(m_strObject, m_vecWallPos[i].iX, m_vecWallPos[i].iY + (MAP_HEIGHT + 5));
		else if (m_iStage == 2)
			m_objDrawManager.DrawObject(m_strObject, m_vecWallPos[i].iX, m_vecWallPos[i].iY);
	}
	ORIGINAL
}