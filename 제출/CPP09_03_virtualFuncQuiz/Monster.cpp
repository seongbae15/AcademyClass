#include "Monster.h"

Monster::Monster()
{
}
Monster::~Monster()
{
}

void Monster::ShowInfo(int Col)
{
	int iPosX1 = WIDTH - 15;
	int iPosX2 = WIDTH + 5;
	string strTemp = "======" + m_stChInfo.m_strName + "<" + to_string(m_stChInfo.m_iLevel) + ">======";
	m_ChMapDraw.DrawMidText(strTemp, WIDTH, HEIGHT * 0.1f + Col);
	m_ChMapDraw.TextDraw("공격력 = ", iPosX1, HEIGHT * 0.1f + 1 + Col);
	cout << m_stChInfo.m_iAttack;
	m_ChMapDraw.TextDraw("생명력 = ", iPosX2, HEIGHT * 0.1f + 1 + Col);
	cout << m_stChInfo.m_iCurVital << "/" << m_stChInfo.m_iVital << " ";
	m_ChMapDraw.TextDraw("경험치 = ", iPosX1, HEIGHT * 0.1f + 2 + Col);
	cout << m_stChInfo.m_iCurExp << "/" << m_stChInfo.m_iExp << " ";
	m_ChMapDraw.TextDraw("GetEXP = ", iPosX2, HEIGHT * 0.1f + 2 + Col);
	cout << m_stChInfo.m_iGetExp;
	m_ChMapDraw.TextDraw("Gold = ", iPosX1, HEIGHT * 0.1f + 3 + Col);
	cout << m_stChInfo.m_iGold;
}

void Monster::BuyWeapon(WEAPON WeaponInfo)
{

}
void Monster::InstallWeapon()
{

}

void Monster::InstallWeapon(WEAPON WeaponInfo)
{

}

void Monster::LoadCharacterInfo(CharacterInfo stCharacter, int iMode)
{
	m_stChInfo = stCharacter;
	m_stChInfo.m_iCurExp = 0;
	m_stChInfo.m_iCurVital = m_stChInfo.m_iVital;
}

