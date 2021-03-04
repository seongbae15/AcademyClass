#pragma once
#include "Playlib.h"
#include "Character.h"
#include <vector>

class Character;

enum MONSTER_STATE
{
	MONSTER_STATE_AWAKE =0,
	MONSTER_STATE_SLEEP,
	MONSTER_STATE_ATTACK,
};

class Monster
{
private:
	MONSTER_STATE m_eM_state;
	vector<Character*> m_vecPlayerList;
	DrawManager m_monDrawManager;
	string m_strMonster;
	int m_iMonsterStage;
	Pos m_stMonsterPos;
	string m_strMonsterName;
public:
	void InitMonster(int num);
	void DrawMonster();
	//void EraseMonster() {};
	//void MoveMonster(char keyIn) {};
	//void StageUpMonster(Pos next_pos) {};
	//void BackMonster(char keyIn) {};
	//void SetAlarm(Monster* monster, bool alarm) {};
	void AddAlarmPlayer(Character* player);
	void ChangeMonsterState(BUTTON_STATE button_state, Character* player);
	//void ChangePlayerState() {};
	void Notify();
	//void Notified(string notification, int stage) {};
	void AttackPlayer(Character* player);
	//PLAYER_STATE GetPlayerState()
	//{
	//	return PLAYER_STATE_LIVE;
	//}
};

