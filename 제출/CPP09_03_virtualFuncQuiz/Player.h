#pragma once
#include "Character.h"


class Player:public Character
{
private:
	int m_iWeaponAttack;
	int m_iTotalAttack;
	//WEAPON m_stPlayerWeapon;
	//bool m_bWeaponState;
public:
	Player();
	~Player();
	//void LoadInfo(string str, int index);
	void ShowInfo(int Col);
	void SetInfo(string str, int index);
	void BuyWeapon(WEAPON WeaponInfo);
	void InstallWeapon();
	void InstallWeapon(WEAPON WeaponInfo);
	void LoadCharacterInfo(CharacterInfo stCharacter);
	inline int GetAttack()
	{
		return m_iTotalAttack;
	}


};

