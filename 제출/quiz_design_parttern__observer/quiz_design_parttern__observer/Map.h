#pragma once
#include "Playlib.h"
#include "DrawManager.h"

class Map
{
protected:
	string m_strDoor;
	DrawManager m_mapDrawManager;
	Pos m_stMapPos;
public:
	virtual void InitMap() = 0;
	virtual void DrawMap() = 0;
};

