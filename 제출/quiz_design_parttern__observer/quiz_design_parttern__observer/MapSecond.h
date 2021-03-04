#pragma once
#include "Map.h"
class MapSecond : public Map
{
private:

public:
	void InitMap();
	void DrawMap();
	Pos GetGoalPos()
	{
		return m_stGoalPos;
	}
};

