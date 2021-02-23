#pragma once
#include <iostream>
#include <string>
#include <vector>
//#include <iomanip>


using namespace std;
class Shop
{
private:
	Shop* m_pParent;
	const string m_strWeapon_type;


public:
	Shop(string type);
	~Shop();
	void SetParent(Shop* Parent);
	virtual void AddShop(Shop* shop)=0;
};


class Box : public Shop
{
private:
	vector<Shop*> m_vecShopList;
public:
	Box(string type);
	~Box() {};
	void AddShop(Shop* shop);
};


class Item : public Shop
{
private:
	string m_strWeapon_type;
	string m_strWepaon_name;
	int m_iWeapon_cost;
	int m_iWeapon_attack;
public:
	Item(string type, string name, int cos, int attack);
	~Item() {};
	void AddShop(Shop* shop) {};
};




