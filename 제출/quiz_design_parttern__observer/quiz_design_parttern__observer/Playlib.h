#pragma once
#include <iostream>
#include <string>
#include <time.h>
#include "conio.h"

#define UP_1P 'w'
#define DOWN_1P 's'
#define LEFT_1P 'a'
#define RIGHT_1P 'd'

#define UP_2P 'i'
#define DOWN_2P 'k'
#define LEFT_2P 'j'
#define RIGHT_2P 'l'

#define MAP_WIDTH 11
#define MAP_HEIGHT 11
#define WINDOW_WIDTH MAP_WIDTH
#define WINDOW_HEIGHT 2*MAP_HEIGHT +7

using namespace std;

typedef struct Pos
{
	int iX;
	int iY;
}Pos;

enum BUTTON_STATE
{
	BUTTON_STATE_PASS = 0,
	BUTTON_STATE_WAKE,
	BUTTON_STATE_SLEEP,
};

enum PLAYER_STATE
{
	PLAYER_STATE_LIVE = 0,
	PLAYER_STATE_DEAD,
};

///////////////////////////////////////////////////////////////////////
#define col GetStdHandle(STD_OUTPUT_HANDLE) 
#define BLACK SetConsoleTextAttribute( col,0x0000 );
#define DARK_BLUE SetConsoleTextAttribute( col,0x0001 );
#define GREEN SetConsoleTextAttribute( col,0x0002 );
#define BLUE_GREEN SetConsoleTextAttribute( col,0x0003 );
#define BLOOD SetConsoleTextAttribute( col,0x0004 );
#define PUPPLE SetConsoleTextAttribute( col,0x0005 );
#define GOLD SetConsoleTextAttribute( col,0x0006 );			//���� ����
#define ORIGINAL SetConsoleTextAttribute( col,0x0007 );
#define GRAY SetConsoleTextAttribute( col,0x0008 );
#define BLUE SetConsoleTextAttribute( col,0x0009 );
#define HIGH_GREEN SetConsoleTextAttribute( col,0x000a );
#define SKY_BLUE SetConsoleTextAttribute( col,0x000b );
#define RED SetConsoleTextAttribute( col,0x000c );
#define PLUM SetConsoleTextAttribute( col,0x000d );
#define YELLOW SetConsoleTextAttribute( col,0x000e );
///////////////////////////////////////////////////////////////////////


