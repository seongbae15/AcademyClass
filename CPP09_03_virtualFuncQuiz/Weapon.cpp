#include "Weapon.h"

void Weapon::LoadWeapon(WEAPON wInfo)
{
	m_stWInfo = wInfo;
}

void Weapon::ShowWeapon(int posX, int posY)
{
	YELLOW
	m_wMapDraw.TextDraw("���� : " + to_string(m_stWInfo.m_iWCost),posX-16, posY);
	m_wMapDraw.TextDraw("���� Ÿ�� : " + m_stWInfo.m_strWType, posX, posY);
	m_wMapDraw.TextDraw("���� �̸� : " + m_stWInfo.m_strWName, posX - 16, posY + 1);
	m_wMapDraw.TextDraw("���ݷ� : " + to_string(m_stWInfo.m_iWAttack), posX + 8, posY + 1);
	ORIGINAL
}