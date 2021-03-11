#pragma once
#include "Playlib.h"
#include <Windows.h>

class DrawManager
{
public:
	void DrawBaseMap(int width, int height,int start_x, int start_y);
	void DispText(string str, int posX, int posY);
	void EraseText(int posX, int posY);
	void DrawObject(string str, int posX, int posY);
	void EraseObject(int posX, int posY);
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
};