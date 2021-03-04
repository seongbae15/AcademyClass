#pragma once
#include "Object_map.h"
#include <vector>

#define MAX_WALL_COUNT 5
class Wall : public Object_map
{
private:
	vector<Pos> m_vecWallPos;
public:
	void SetObj(int stage);
	void DrawObject(int stage);
	Pos GetObjectPos(int index)
	{
		return m_vecWallPos[index];
	}
	BUTTON_STATE GetButtonState(int index = 0)
	{
		return BUTTON_STATE_PASS;
	};
};

