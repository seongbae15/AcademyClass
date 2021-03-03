#pragma once
#include "Character.h"

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
public:
	void InitCharacter(int num);
	void DrawCharacter();
	void MoveCharacter(char keyIn);
	void EraseCharacter();
};

