#pragma once
#include "Map.h"
class MapFirst : public Map
{
public:
	void InitMap();
	void DrawMap();
	Pos GetGoalPos()
	{
		return m_stGoalPos;
	}
};