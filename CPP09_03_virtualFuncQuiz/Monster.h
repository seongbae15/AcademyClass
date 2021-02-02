#pragma once
#include "Character.h"
class Monster:public Character
{
public:
	Monster();
	~Monster();
	//void LoadInfo(string str, int index);
	void ShowInfo(int Col);
	void SetInfo(string str, int index);
	void BuyWeapon(WEAPON WeaponInfo);
	inline int GetAttack()
	{
		return m_stChInfo.m_iAttack;
	}
	//void ThrowRPS(int selection);

};

