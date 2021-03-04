#pragma once
#include "Character.h"
#include "Monster.h"

enum PLAYER_STATE
{
	PLAYER_STATE_LIVE = 0,
	PLAYER_STATE_DEAD,
};

enum MOVE
{
	MOVE_UP_1 = 'w',
	MOVE_DOWN_1 = 's',
	MOVE_LEFT_1 = 'a',
	MOVE_RIGHT_1 = 'd',
	MOVE_UP_2 = 'i',
	MOVE_DOWN_2 = 'k',
	MOVE_LEFT_2 = 'j',
	MOVE_RIGHT_2 = 'l',
};

class Player : public Character
{
private:
	PLAYER_STATE m_eP_state;
	int m_iNum;
	Character* m_playerMonsterAlarm;
	bool m_bAlarm_state1;
	bool m_bAlarm_state2;

public:
	void InitCharacter(int num);
	void DrawCharacter();
	void MoveCharacter(char keyIn);
	void EraseCharacter();
	void StageUpCharacter(Pos next_pos);
	void BackCharacter(char keyIn);
	void SetAlarm(Character* monster, bool alarm);
	void AddAlarmPlayer(Character* player) {};
	void ChangeMonsterState(BUTTON_STATE button_state, Character* player) {};
	void ChangePlayerState();
	void Notify() {};
	void Notified(string notification, int stage);
	void AttackPlayer(Character* player) {};
};

