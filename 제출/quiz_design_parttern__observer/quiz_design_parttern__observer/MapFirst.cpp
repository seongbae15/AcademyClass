#include "MapFirst.h"

void MapFirst::InitMap()
{
	m_strDoor = "¢Ã";
	m_stMapPos.iX = MAP_WIDTH / 2;
	m_stMapPos.iY = 1 + MAP_HEIGHT+5;
}

void MapFirst::DrawMap()
{
	m_mapDrawManager.DrawBaseMap(MAP_WIDTH, MAP_HEIGHT, 0, MAP_HEIGHT + 5);
	BLUE
	m_mapDrawManager.DrawObject(m_strDoor, m_stMapPos.iX, m_stMapPos.iY);
	ORIGINAL
	//Àå¾Ö¹° ´õ ±×¸®±â(1Ãþ 2Ãþ)
}