#include "DrawManager.h"

DrawManager::DrawManager()
{

}

void DrawManager::ErasePoint(int x, int y)
{
	gotoxy(x * 2, y);
	cout << "  ";
	gotoxy(-1, -1);
	return;
}
void DrawManager::DrawPoint(string str, int x, int y)
{
	gotoxy(x * 2, y);
	cout << str;
	gotoxy(-1, -1);
	return;
}

void DrawManager::DrawMidText(string str, int x, int y)
{
	if (x > str.size() / 2)
		x -= str.size() / 2;
	gotoxy(x, y);
	cout << str;
	return;
}
void DrawManager::EraseMidText(string str, int x, int y)
{
	string strErase;
	for (int i = 0;i<str.size();i++)
	{
		strErase += " ";
	}
	if (x > str.size() / 2)
		x -= str.size() / 2;
	gotoxy(x, y);
	cout << strErase;
	return;
}
void DrawManager::TextDraw(string str, int x, int y)
{
	gotoxy(x, y);
	cout << str;
}

void DrawManager::TextErase(string str, int x, int y)
{
	string strBlank;
	for (int i = 0;i < str.size();i++)
		strBlank += " ";
	gotoxy(x, y);
	cout << strBlank;
}



void DrawManager::BoxErase(int Width, int Height)
{
	for (int y = 1; y < Height - 1; y++)
	{
		gotoxy(2, y);
		for (int x = 1; x < Width - 1; x++)
			cout << "  ";
	}
}

void DrawManager::BoxDraw(int Start_x, int Start_y, int Width, int Height)
{
	if (Start_x > Width)
		Start_x -= Width;
	for (int y = 0; y < Height; y++)
	{
		gotoxy(Start_x, Start_y + y);
		if (y == 0)
		{
			cout << "¦£";
			for (int x = 1; x < Width - 1; x++)
				cout << "¦¡";
			cout << "¦¤";
		}
		else if (y == Height - 1)
		{
			cout << "¦¦";
			for (int x = 1; x < Width - 1; x++)
				cout << "¦¡";
			cout << "¦¥";
		}
		else
		{

			cout << "¦¢";
			for (int x = 1; x < Width - 1; x++)
			cout << "  ";
			cout << "¦¢";
		}
	}
	return;
}

int DrawManager::MenuSelectCursor(int MenuLen, int AddCol, int x, int y)
{
	BG_GRAY_TEXT_RED
	int Select = 1;
	DrawPoint("¢¹", x, y);
	while (1)
	{
		switch (getch())
		{
		case UP:
			if (Select - 1 >= 1)
			{
				ErasePoint(x, y);
				y -= AddCol;
				Select--;
			}
			break;
		case DOWN:
			if (Select + 1 <= MenuLen)
			{
				ErasePoint(x, y);
				y += AddCol;
				Select++;
			}
			break;
		case ENTER:
			ErasePoint(x, y);
			ORIGINAL
			return Select;
		}
		DrawPoint("¢¹", x, y);
	}
	ORIGINAL
}
DrawManager::~DrawManager()
{
}
