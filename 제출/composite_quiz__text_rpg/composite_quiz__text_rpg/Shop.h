#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#include "MapDraw.h"


using namespace std;
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
	virtual void ShowList(int posX, int posY) = 0;
	virtual void ShowWeaponInfo(string w_type, int posX, int posY) = 0;
	int GetLevel();
	Shop* GetParent();
	string GetType();
};


class Box : public Shop
{
	vector<Shop*> m_vecShopList;
public:
	Box(string type);
	~Box() {};
	void AddShop(Shop* shop);
	void Show();
	void ShowList(int posX, int posY);
	void ShowWeaponInfo(string w_type, int posX, int posY);

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
	void ShowList(int posX, int posY);
	void ShowWeaponInfo(string w_type, int posX, int posY);

};




