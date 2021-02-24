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

Shop* Shop::GetParent()
{
	return m_pParent;
}

int Shop::GetLevel()
{
	int level = 0;
	Shop* tmpShop = GetParent();
	while (tmpShop != NULL)
	{
		level++;
		tmpShop = tmpShop->GetParent();
	}
	return level;
}

int Shop::GetSize()
{
	return m_strWeapon_type.size() + GetLevel() * 2;
}

void Box::AddShop(Shop* shop)
{
	shop->SetParent(this);
	m_vecShopList.push_back(shop);
}

void Box::Show()
{
	cout << setiosflags(ios::right) << setw(GetSize());
	cout << setfill(' ') << GetType().c_str() << "-Box" << endl;

	auto iterBegin = m_vecShopList.begin();
	auto iterEnd = m_vecShopList.end();

	while (iterBegin != iterEnd)
	{
		(*iterBegin)->Show();
		iterBegin++;
	}
}

void Box::ShowList(int posX, int posY)
{
	auto iterBegin = m_vecShopList.begin();
	auto iterEnd = m_vecShopList.end();
	int iAdd_cols = 0;
	while (iterBegin != iterEnd)
	{
		if ((*iterBegin)->GetLevel() == 1)
		{
			m_shopDrawMG.TextDraw((*iterBegin)->GetType(), posX,posY + iAdd_cols);
			iAdd_cols += 2;
		}
		iterBegin++;
	}
}

void Box::ShowWeaponInfo(string w_type)
{
	auto iterBegin = m_vecShopList.begin();
	auto iterEnd = m_vecShopList.end();
	int iAdd_cols = 0;
	while (iterBegin != iterEnd)
	{
		if ((*iterBegin)->GetType()== w_type)
		{
			//
			//Level Down
			(*iterBegin)->ShowList(WIDTH, HEIGHT * 0.2f + 3* iAdd_cols);
			iAdd_cols += 3;
			//
		}
		iterBegin++;
	}
}

Item::Item(string type, string name, int cost, int attack) : Shop(type)
{
	m_strWepaon_name = name;
	m_iWeapon_cost = cost;
	m_iWeapon_attack = attack;
}

string Shop::GetType()
{
	return m_strWeapon_type;
}

void Item::Show()
{
	cout << setiosflags(ios::right) << setw(GetSize());
	cout << setfill(' ') << GetType().c_str() << "-Item" << endl;
}

void Item::ShowList(int posX, int posY)
{
	YELLOW
	m_shopDrawMG.TextDraw("가격 : " + to_string(this->m_iWeapon_cost), posX - 16, posY);
	m_shopDrawMG.TextDraw("무기 타입 : " + this->m_strWeapon_type, posX, posY);
	m_shopDrawMG.TextDraw("무기 이름 : " + this->m_strWepaon_name, posX - 18, posY + 1);
	m_shopDrawMG.TextDraw("공격력 : " + to_string(this->m_iWeapon_attack), posX + 8, posY + 1);
	ORIGINAL

}