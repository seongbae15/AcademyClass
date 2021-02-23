#pragma once
#include <iostream>
#include <string>
#include "Box.h"
//#include <iomanip>
//#include <vector>

using namespace std;
class Shop
{
	Shop* m_pParent;

	string m_strWeapon_type;
	string m_strWepaon_name;
	int m_iWeapon_cost;
	int m_iWeapon_attack;

public:
	virtual void AddShop(Shop* shop)=0;
};




