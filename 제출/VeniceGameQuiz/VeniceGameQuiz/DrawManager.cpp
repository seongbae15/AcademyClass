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
void DrawManager::TextDraw(string str, int x, int y)
{
	gotoxy(x, y);
	cout << str;
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
			//gotoxy(2*(Start_x+Width-1), Start_y + y);
			cout << "¦¢";
		}
	}
	return;
}

int DrawManager::MenuSelectCursor(int MenuLen, int AddCol, int x, int y)
{
	int Select = 1;
	BG_GRAY_TEXT_RED
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
			return Select;
		}
		BG_GRAY_TEXT_RED
		DrawPoint("¢¹", x, y);
		ORIGINAL
	}
	
}
DrawManager::~DrawManager()
{
}
