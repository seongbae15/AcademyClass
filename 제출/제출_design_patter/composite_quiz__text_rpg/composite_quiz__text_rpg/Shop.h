#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "MapDraw.h"

using namespace std;

enum WEAPON_TYPE
{
	WEAPON_TYPE_START = 0,
	WEAPON_TYPE_DAGGER = 1,
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

class Shop
{
	Shop* m_pParent;
	const string m_strWeapon_type;
protected:
	MapDraw m_shopDrawMG;
	int GetSize();
public:
	Shop(string type);
	~Shop();
	void SetParent(Shop* Parent);
	virtual void AddShop(Shop* shop)=0;
	virtual void Show() = 0;
	virtual void ShowWeaponInfo(string w_type, int posX, int posY,int page) = 0;
	int GetLevel();
	virtual int GetSizeLevel(int level, string w_type) = 0;
	virtual WEAPON GetBuyWeaponInfo(string w_type, int number) = 0;
	Shop* GetParent();
	string GetType();
	virtual string GetName() = 0;
	virtual int GetCost() = 0;
	virtual int GetAttack() = 0;
};

class Box : public Shop
{
	vector<Shop*> m_vecShopList;
public:
	Box(string type);
	~Box() {};
	void AddShop(Shop* shop);
	void Show();
	void ShowWeaponInfo(string w_type, int posX, int posY, int page);
	int GetSizeLevel(int level, string w_type);
	WEAPON GetBuyWeaponInfo(string w_type, int number);
	string GetName()
	{
		return "";
	};
	int GetCost()
	{
		return -1;
	};
	int GetAttack()
	{
		return -1;
	};
};

class Item : public Shop
{
	//string m_strWeapon_type;
	string m_strWepaon_name;
	int m_iWeapon_cost;
	int m_iWeapon_attack;
public:
	Item(string type, string name, int cos, int attack);
	~Item() {};
	void AddShop(Shop* shop) {};
	void Show();
	void ShowWeaponInfo(string w_type, int posX, int posY, int page);
	WEAPON GetBuyWeaponInfo(string w_type, int number);
	int GetSizeLevel(int level, string w_type)
	{
		return -1;
	};
	string GetName();
	int GetCost();
	int GetAttack();
};




