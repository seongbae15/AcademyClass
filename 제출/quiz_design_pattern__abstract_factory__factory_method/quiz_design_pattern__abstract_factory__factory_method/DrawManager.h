#pragma once
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class DrawManager
{
public:
	void DrawBaseMap(int width, int height);
	void DispText(string str, int posX, int posY);
	void DrawObject(string str, int posX, int posY);
	void EraseObject(int posX, int posY);
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
};

