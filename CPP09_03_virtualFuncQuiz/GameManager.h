#pragma once
#include "Lib.h"
#include "MapDraw.h"
#include "Character.h"
#include "Player.h"
#include "Monster.h"
#include "Weapon.h"
#include <vector>

#define NUMBER_INFO 7
#define MAX_CHARACTER 7
#define MAX_MONSTER MAX_CHARACTER-1
#define NUMBER_WEAPON_TYPE 6
#define NUMBER_SAVE_SLOT 10
#define NUMBER_WEAPON 30

#define PLAYER 0
#define MONSTER 6

#define WIN 1
#define LOSE 3

#define ADD_EXP 3

enum LOBY_MENU
{
	LOBY_MENU_NEW=1,
	LOBY_MENU_LOAD,
	LOBY_MENU_EXIT,
	LOBY_MENU_END=3,
};

enum PLAY_MENU
{
	PLAY_MENU_DUNGEON=1,
	PLAY_MENU_PLAYER_INFO,
	PLAY_MENU_MONSTER_INFO,
	PLAY_MENU_WEAPONG_SHOP,
	PLAY_MENU_SAVE,
	PLAY_MENU_EXIT,
	PALY_MENU_END=7,
};

enum WINDRAWLOSE
{
	WLD_WIN = 1,
	WLD_DRAW = 2,
	WLD_LOSE =3,
};

enum GAME_STATE
{
	STATE_WIN = 1,
	STATE_ING = 2,
	STATE_OVER =3,
};

class GameManager
{
private:
	MapDraw m_gmMapDraw;
	Character* m_gmCharacter[MAX_CHARACTER] = { NULL };
	vector<Weapon> m_vWeaponList;
	GAME_STATE m_eSTATE;
	int m_iMonsterCount;
	int m_iAddAttack;
	int m_iAddVital;

public:
	void RunGame();
	void LoadWeapon();
	void DispLoby();
	void NewGameSet();
	void StartGame();
	void DispPlayMenu();
	void EnterDungeon();
	void DispEntrance();
	void DispInfo(int selection);
	void StartBattle(int MonsterSelection);
	int WinLoseDraw(int player, int monster);
	void CheckGameEnd(int MonsterNumber);
	void DispResult(int result, int WinNumber, int LoseNumber);
	void DispLevelUp();
	void DispShop();
	void DispWeaponList(int weaponSelection);
	void DispDetailList(string str);
	void DispSave();
};

