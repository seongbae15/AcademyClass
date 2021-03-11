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
	DrawManager m_monDrawManager;
	string m_strMonster;
	string m_strMonsterAround;
	int m_iMonsterStage;
	Pos m_stMonsterPos;
	string m_strMonsterName;
	vector<Character*> m_vecPlayerList;
public:
	void InitMonster(int num);
	void DrawMonster();
	void AddAlarmPlayer(Character* player);
	void ChangeMonsterState(BUTTON_STATE button_state, Character* player);
	void Notify();
	void AttackPlayer(Character* player);
	void DrawMonsterAround();
	void EraseMonsterAround();
	MONSTER_STATE GetMonsterState()
	{
		return m_eM_state;
	}
	Pos GetMonsterPos()
	{
		return m_stMonsterPos;
	}
};