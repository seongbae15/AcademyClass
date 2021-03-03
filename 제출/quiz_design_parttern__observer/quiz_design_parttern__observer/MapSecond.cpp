#include "MapSecond.h"

void MapSecond::InitMap()
{
	m_mapDoor = new Door;
	m_mapDoor->SetObj(2);
	m_mapButton = new Button;
	m_mapWall = new Wall;
}


void MapSecond::DrawMap()
{
	m_mapDrawManager.DrawBaseMap(MAP_WIDTH, MAP_HEIGHT, 0, 0);
	m_mapDoor->DrawObject(2);
}