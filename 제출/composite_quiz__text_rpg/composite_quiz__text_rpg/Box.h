#pragma once
#include "Shop.h"
#include <vector>
class Box :public Shop
{
	vector<Shop*> m_vecShopList;
public:
	void AddShop(Shop* shop);
};

