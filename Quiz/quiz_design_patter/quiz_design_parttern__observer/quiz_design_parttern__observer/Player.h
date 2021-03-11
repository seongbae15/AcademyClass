#pragma once
#include "Character.h"

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
	Monster* m_playerMonsterAlarm;
	bool m_bAlarm_state1;
	bool m_bAlarm_state2;

public:
	void InitCharacter(int num);
	void DrawCharacter();
	void MoveCharacter(char keyIn);
	void EraseCharacter();
	void StageUpCharacter(Pos next_pos);
	void BackCharacter(char keyIn);
	void SetAlarm(Monster* monster, bool alarm);
	void ChangePlayerState();
	void Notified(string notification, int stage);
	PLAYER_STATE GetPlayerState()
	{
		return m_eP_state;
	}
};