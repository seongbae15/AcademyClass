#include "DrawManager.h"

void DrawManager::DrawBaseMap(int width, int height, int start_x, int start_y)
{
	for (int y = 0; y < height; y++)
	{
		gotoxy(start_x, start_y + y);
		if (y == 0 || y == height - 1)
		{
			for (int x = 0; x < width; x++)
				cout << "¢Ë";
		}
		else
		{
			cout << "¢Ë";
			gotoxy(2 * (start_x + width - 1), start_y + y);
			cout << "¢Ë";
		}
	}
}

void DrawManager::DispText(string str, int posX, int posY)
{

	gotoxy(posX, posY);
	cout << str;
}

void DrawManager::EraseText(int posX, int posY)
{
	gotoxy(posX, posY);
	cout << "                  ";
	gotoxy(posX, posY+1);
	cout << "                  ";
	gotoxy(posX, posY+2);
	cout << "                  ";
	gotoxy(posX, posY+3);
	cout << "                  ";

}

void DrawManager::DrawObject(string str, int posX, int posY)
{
	gotoxy(2 * posX, posY);
	cout << str;
}

void DrawManager::EraseObject(int posX, int posY)
{
	gotoxy(2 * posX, posY);
	cout << "  ";
}



