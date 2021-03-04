#pragma once
#include "Character.h"
#include <vector>

enum MONSTER_STATE
{
	MONSTER_STATE_AWAKE =0,
	MONSTER_STATE_SLEEP,
	MONSTER_STATE_ATTACK,
};

class Monster : public Character
{
private:
	MONSTER_STATE m_eM_state;
	vector<Character*> m_vecPlayerList;
public:
	void InitCharacter(int num);
	void DrawCharacter();
	void EraseCharacter() {};
	void MoveCharacter(char keyIn) {};
	void StageUpCharacter(Pos next_pos) {};
	void BackCharacter(char keyIn) {};
	void SetAlarm(Character* monster, bool alarm) {};
	void AddAlarmPlayer(Character* player);
	void ChangeMonsterState(BUTTON_STATE button_state, Character* player);
	void ChangePlayerState() {};
	void Notify();
	void Notified(string notification, int stage) {};
	void AttackPlayer(Character* player);
};

