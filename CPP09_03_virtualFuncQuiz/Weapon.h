#pragma once
#include "Lib.h"
#include "MapDraw.h"

enum WEAPON_TYPE
{
	WEAPON_TYPE_START=0,
	WEAPON_TYPE_DAGGER=1,
	WEAPON_TYPE_GUN,
	WEAPON_TYPE_SWORD,
	WEAPON_TYPE_WAND,
	WEAPON_TYPE_BOW,
	WEAPON_TYPE_HAMMER,
	WEAPON_TYPE_END,
};

typedef struct WEAPON
{
	string m_strWType;
	string m_strWName;
	int m_iWCost;
	int m_iWAttack;
}WEAPON;

class Weapon
{
private:
	MapDraw m_wMapDraw;
protected:
	WEAPON m_stWInfo;
public:
	void LoadWeapon(WEAPON wInfo);
	void ShowWeapon(int posX, int posY);
	inline string GetWeaponType()
	{
		return m_stWInfo.m_strWType;
	}
	inline WEAPON getWeaponInfo()
	{
		return m_stWInfo;
	}
};

