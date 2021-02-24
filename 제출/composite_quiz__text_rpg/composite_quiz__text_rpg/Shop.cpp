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

void Box::ShowWeaponInfo(string w_type, int posX, int posY, int page)
{
	auto iterBegin = m_vecShopList.begin();
	auto iterEnd = m_vecShopList.end();
	int iCount=0;
	int iDispCount=0;
	int iAdd_cols = 0;
	if ((*iterBegin)->GetLevel() == 2)
	{
		if (m_vecShopList.size() >= 5)
		{
			if (page == 0)
				iDispCount = 5;
			else if (page == 1)
				iDispCount = m_vecShopList.size() - 5 * page;
		}
		else
			iDispCount = m_vecShopList.size();
	}
	while (iterBegin != iterEnd)
	{
		if ((*iterBegin)->GetType()== w_type)
		{
			if ((*iterBegin)->GetLevel() == 1)
			{
				(*iterBegin)->ShowWeaponInfo(w_type, posX, posY + iAdd_cols, page);
			}
			else if ((*iterBegin)->GetLevel() == 2)
			{
				(*(iterBegin + page * 5))->ShowWeaponInfo(w_type, posX, posY + iAdd_cols, page);
				iAdd_cols += 3;
				iCount++;
				if (iCount >= iDispCount)
					break;
			}
		}
		iterBegin++;
	}
}

int Box::GetSizeLevel(int level, string w_type)
{
	auto iterBegin = m_vecShopList.begin();
	auto iterEnd = m_vecShopList.end();
	while (1)
	{
		if ((*iterBegin)->GetType() == w_type)
		{
			if ((*iterBegin)->GetLevel() == level)
				return m_vecShopList.size();
			else
				return (*iterBegin)->GetSizeLevel(level, w_type);
		}
		else
			iterBegin++;
	}
}

WEAPON Box::GetBuyWeaponInfo(string w_type, int number)
{
	auto iterBegin = m_vecShopList.begin();
	while (1)
	{
		if ((*iterBegin)->GetType() == w_type)
		{
			if ((*iterBegin)->GetLevel() == 2)
			{
				return (*(iterBegin+number))->GetBuyWeaponInfo(w_type, number);
			}
			else
				return (*iterBegin)->GetBuyWeaponInfo(w_type, number);
		}
		else
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

void Item::ShowWeaponInfo(string w_type, int posX, int posY, int page)
{
	YELLOW
	m_shopDrawMG.TextDraw("가격 : " + to_string(m_iWeapon_cost), posX - 16, posY);
	m_shopDrawMG.TextDraw("무기 타입 : " + w_type, posX, posY);
	m_shopDrawMG.TextDraw("무기 이름 : " + m_strWepaon_name, posX - 18, posY + 1);
	m_shopDrawMG.TextDraw("공격력 : " + to_string(m_iWeapon_attack), posX + 8, posY + 1);
	ORIGINAL
}

WEAPON Item::GetBuyWeaponInfo(string w_type, int number)
{
	WEAPON stTmpInfo;
	stTmpInfo.m_strWType = w_type;
	stTmpInfo.m_strWName = this->GetName();
	stTmpInfo.m_iWCost = this->GetCost();
	stTmpInfo.m_iWAttack = this->GetAttack();
	return stTmpInfo;
}

string Item::GetName()
{
	return m_strWepaon_name;
}

int Item::GetCost()
{
	return m_iWeapon_cost;
}

int Item::GetAttack()
{
	return m_iWeapon_attack;
}