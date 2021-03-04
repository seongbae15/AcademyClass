#pragma once
#include "Playlib.h"

#include "Map.h"
#include "MapFirst.h"
#include "MapSecond.h"

#include "Character.h"
#include "Player.h"
#include "Monster.h"

#define PLAYER1 1
#define PLAYER2 0
#define MONSTER_FIRST 1
#define MONSTER_SECOND 0
#define FIRST_FLOOR 1
#define SECOND_FLOOR 0
class GameManager
{
private:
	//Map* m_gmMapFirst;
	//Map* m_gmMapSecond;

	Map* m_gmMapArr[2];
	//Character* m_gmP1;
	//Character* m_gmP2;
	Character* m_gmArrPlayer[2];

	//Character* m_gmM1;
	//Character* m_gmM2;

	Monster* m_gmArrMonster[2];

	DrawManager m_gmDraw;
public:
	GameManager();
	void StartGame();
	void SetConsoleWin();
	void InitGame();
	void DrawTowerMap();
	int MovePlayer();
	bool CheckPlayerWallPos(int player_number);
	void CheckStageUp(int player_number);
	void CheckButton(int player_number);
	void Releas();

};

