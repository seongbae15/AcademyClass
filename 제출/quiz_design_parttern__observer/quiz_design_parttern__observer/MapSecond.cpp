#include "MapSecond.h"

void MapSecond::InitMap()
{
	m_strDoor = "¢Ã";
	m_stMapPos.iX = MAP_WIDTH / 2;
	m_stMapPos.iY = MAP_HEIGHT-2;
}

void MapSecond::DrawMap()
{
	m_mapDrawManager.DrawBaseMap(MAP_WIDTH, MAP_HEIGHT, 0, 0);
	BLUE
	m_mapDrawManager.DrawObject(m_strDoor, m_stMapPos.iX, m_stMapPos.iY);
	ORIGINAL
}