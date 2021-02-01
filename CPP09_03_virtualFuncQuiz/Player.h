#pragma once
#include "Character.h"

class Player:public Character
{
private:
	int m_iWeaponAttack;
	int m_iTotalAttack;
public:
	Player();
	~Player();
	//void LoadInfo(string str, int index);
	void ShowInfo(int Col);
	void SetInfo(string str, int index);
	inline int GetAttack()
	{
		return m_iTotalAttack;
	}


};

