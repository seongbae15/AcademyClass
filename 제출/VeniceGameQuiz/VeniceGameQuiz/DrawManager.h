#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include "Lib.h"

#define UP 'w'
#define UP_CAP 'W'
#define DOWN 's'
#define DOWN_CAP 'S'
#define ENTER 13

using namespace std;
class DrawManager
{
public:
	void BoxDraw(int Start_x, int Start_y, int Width, int Height);
	void BoxErase(int Width, int Height);
	void DrawPoint(string str, int x, int y);
	void DrawMidText(string str, int x, int y);
	void EraseMidText(string str, int x, int y);
	void TextDraw(string str, int x, int y);
	void ErasePoint(int x, int y);
	void TextErase(string str, int x, int y);
	int MenuSelectCursor(int MenuLen, int AddCol, int x, int y);
	DrawManager();
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
	~DrawManager();
};

