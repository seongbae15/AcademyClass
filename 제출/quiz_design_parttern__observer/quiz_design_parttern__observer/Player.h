#pragma once
#include "Character.h"

enum PLAYER_STATE
{
	PLAYER_STATE_LIVE = 0,
	PLAYER_STATE_DEAD,
};


class Player : public Character
{
private:
	PLAYER_STATE m_eP_state;
	int m_iNum;
public:
	void InitCharacter(int num);
	void DrawCharacter();
	void MoveCharacter() {};
};

