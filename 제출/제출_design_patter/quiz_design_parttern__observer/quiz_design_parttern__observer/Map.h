#pragma once
#include "Playlib.h"
#include "DrawManager.h"
#include "Object_map.h"
#include "Door.h"
#include "Button.h"
#include "Wall.h"

class Map
{
protected:
	string m_strDoor;
	DrawManager m_mapDrawManager;
	Pos m_stMapPos;
	Object_map* m_mapDoor;
	Object_map* m_mapButton;
	Object_map* m_mapWall;
	string m_strGoal;
	Pos m_stGoalPos;

public:
	virtual void InitMap() = 0;
	virtual void DrawMap() = 0;
	virtual Pos GetGoalPos() = 0;

	Object_map* GetDoorPointer()
	{
		return m_mapDoor;
	}
	Object_map* GetButtonPointer()
	{
		return m_mapButton;
	}
	Object_map* GetWallPointer()
	{
		return m_mapWall;
	}
};