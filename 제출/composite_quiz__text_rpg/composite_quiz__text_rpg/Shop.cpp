#include "Shop.h"

Shop::Shop(string type) : m_strWeapon_type(type)
{
	m_pParent = NULL;
}
Shop::~Shop()
{

}

Box::Box(string type) : Shop(type)
{

}

void Shop::SetParent(Shop* Parent)
{
	m_pParent = Parent;
}

void Box::AddShop(Shop* shop)
{
	shop->SetParent(this);
	m_vecShopList.push_back(shop);
}

Item::Item(string type, string name, int cost, int attack) : Shop(type)
{
	m_strWepaon_name = name;
	m_iWeapon_cost = cost;
	m_iWeapon_attack = attack;
}
