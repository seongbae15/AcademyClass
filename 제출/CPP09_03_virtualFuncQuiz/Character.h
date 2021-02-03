#pragma once
#include "Lib.h"
#include "MapDraw.h"
#include "Weapon.h"

enum INFO_LIST
{
	INFO_LIST_NAME=0,
	INFO_LIST_ATTACK,
	INFO_LIST_VITAL,
	INFO_LIST_EXP,
	INFO_LIST_GETEXP,
	INFO_LIST_LEVEL,
	INFO_LIST_GOLD
};

enum RPS
{
	RPS_SCISSORS = 49,
	RPS_ROCK,
	RPS_PAPER,
};

typedef struct CharacterInfo
{
	string m_strName;
	int m_iCurExp;
	int m_iCurVital;
	int m_iLevel;
	int m_iAttack;
	int m_iVital;
	int m_iExp;
	int m_iGetExp;
	int m_iGold;
}CharacterInfo;

class Character
{
protected:
	CharacterInfo m_stChInfo;
	MapDraw m_ChMapDraw;
	WEAPON m_stPlayerWeapon;
	bool m_bWeaponState;
public:
	Character();
	virtual void SetInfo(string str, int index) = 0;
	//virtual void LoadInfo(string str, int index) = 0;
	virtual void ShowInfo(int Col = 9) = 0;
	virtual inline int GetAttack() = 0;
	void ThrowRPS(int selection, int type = 0);
	void Damage(int attack);
	void Respawn();
	void GetReward(int RGetExp, int RGold);
	void LevelUp(int AddAttack, int AddVital, int AddExp);
	virtual void BuyWeapon(WEAPON WeaponInfo) = 0;
	virtual void InstallWeapon() = 0;
	virtual void InstallWeapon(WEAPON WeaponInfo) = 0;
	virtual void LoadCharacterInfo(CharacterInfo stCharacter, int iMode) = 0;
	inline string GetName()
	{
		return m_stChInfo.m_strName;
	}
	inline int GetCurVital()
	{
		return m_stChInfo.m_iCurVital;
	}
	inline int GetGetExp()
	{
		return m_stChInfo.m_iGetExp;
	}
	inline int GetGold()
	{
		return m_stChInfo.m_iGold;
	}
	inline int GetCurExp()
	{
		return m_stChInfo.m_iCurExp;
	}
	inline int GetExp()
	{
		return m_stChInfo.m_iExp;
	}
	inline int GetVital()
	{
		return m_stChInfo.m_iVital;
	}
	inline int GetLevel()
	{
		return m_stChInfo.m_iLevel;
	}
	inline bool GetWeaponState()
	{
		return m_bWeaponState;
	}
	inline WEAPON GetWeapon()
	{
		return m_stPlayerWeapon;
	}

	virtual ~Character();

};

