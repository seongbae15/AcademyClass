#include "MapFirst.h"

void MapFirst::InitMap()
{
	m_mapDoor = new Door;
	m_mapDoor->SetObj(1);
	m_mapButton = new Button;
	m_mapButton->SetObj(1);
	m_mapWall = new Wall;
	m_mapWall->SetObj(1);
}

void MapFirst::DrawMap()
{
	ORIGINAL
	m_mapDrawManager.DrawBaseMap(MAP_WIDTH, MAP_HEIGHT, 0, MAP_HEIGHT + 5);

	m_mapDoor->DrawObject(1);
	m_mapButton->DrawObject(1);
	m_mapWall->DrawObject(1);
}