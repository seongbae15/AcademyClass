#include "Weapon.h"

void Weapon::LoadWeapon(WEAPON wInfo)
{
	m_stWInfo = wInfo;
}

void Weapon::ShowWeapon(int posX, int posY)
{
	YELLOW
		m_wMapDraw.TextDraw("가격 : " + to_string(m_stWInfo.m_iWCost), posX - 16, posY);
	m_wMapDraw.TextDraw("무기 타입 : " + m_stWInfo.m_strWType, posX, posY);
	m_wMapDraw.TextDraw("무기 이름 : " + m_stWInfo.m_strWName, posX - 18, posY + 1);
	m_wMapDraw.TextDraw("공격력 : " + to_string(m_stWInfo.m_iWAttack), posX + 8, posY + 1);
	ORIGINAL
}