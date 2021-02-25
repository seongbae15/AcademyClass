#pragma once
#include "Character.h"

class Player :public Character
{
private:
	int m_iWeaponAttack;
	int m_iTotalAttack;
public:
	Player();
	~Player();
	void ShowInfo(int Col);
	void Damage(int attack);
	void BuyWeapon(WEAPON WeaponInfo);
	void InstallWeapon();
	void InstallWeapon(WEAPON WeaponInfo);
	void LoadCharacterInfo(CharacterInfo stCharacter, int iMode);
	inline int GetAttack()
	{
		return m_iTotalAttack;
	}
};

