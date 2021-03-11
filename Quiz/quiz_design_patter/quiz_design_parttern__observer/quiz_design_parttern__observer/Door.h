#pragma once
#include "Object_map.h"
class Door : public Object_map
{
private:
	Pos m_stObjPos;
public:
	void SetObj(int stage);
	void DrawObject(int stage);
	Pos GetObjectPos(int index)
	{
		return m_stObjPos;
	}
	BUTTON_STATE GetButtonState(int index = 0)
	{
		return BUTTON_STATE_PASS;
	}
};