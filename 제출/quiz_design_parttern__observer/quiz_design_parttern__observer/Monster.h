#pragma once
#include "Character.h"

enum MONSTER_STATE
{
	MONSTER_STATE_AWAKE =0,
	MONSTER_STATE_SLEEP,
};

class Monster : public Character
{
private:
	MONSTER_STATE m_eM_state;
public:
	void InitCharacter(int num);
	void DrawCharacter();
	void MoveCharacter() {};
};

