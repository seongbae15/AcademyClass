#include "MapFirst.h"

void MapFirst::InitMap()
{
	m_mapDoor = new Door;
	m_mapDoor->SetObj(1);
	m_mapButton = new Button;
	m_mapWall = new Wall;
}

void MapFirst::DrawMap()
{
	m_mapDrawManager.DrawBaseMap(MAP_WIDTH, MAP_HEIGHT, 0, MAP_HEIGHT + 5);

	m_mapDoor->DrawObject(1);

}