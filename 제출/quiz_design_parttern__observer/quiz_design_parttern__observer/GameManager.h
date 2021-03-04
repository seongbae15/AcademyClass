#pragma once
#include "Playlib.h"

#include "Map.h"
#include "MapFirst.h"
#include "MapSecond.h"

#include "Character.h"
#include "Player.h"
#include "Monster.h"


class GameManager
{
private:
	Map* m_gmMapFirst;
	Map* m_gmMapSecond;
	Character* m_gmP1;
	Character* m_gmP2;
	Character* m_gmArrPlayer[2];
	Character* m_gmM1;
	Character* m_gmM2;
	DrawManager m_gmDraw;
public:
	GameManager();
	void StartGame();
	void SetConsoleWin();
	void InitGame();
	void DrawTowerMap();
	void MovePlayer();
	void CheckStageUp();
	void CheckButton();

};

