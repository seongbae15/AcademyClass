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
	Map* m_gmMapArr[2];
	//Character* m_gmArrPlayer;
	//Monster* m_gmArrMonster;
	Character* m_gmArrPlayer[2];
	Monster* m_gmArrMonster[2];
	DrawManager m_gmDraw;
	bool m_bGameOverState;
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
	bool CheckGameOver(int player_number);
	void CheckPlayerDeadAlive(int player_number);
};