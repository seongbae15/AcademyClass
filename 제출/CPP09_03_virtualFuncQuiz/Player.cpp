#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::SetInfo(string str, int index)
{
	if (index == 0)
		m_stChInfo.m_strName = str;
	else
	{
		int iTemp = stoi(str);
		switch ((INFO_LIST)index)
		{
		case INFO_LIST_ATTACK:
			m_stChInfo.m_iAttack = iTemp;
			break;
		case INFO_LIST_VITAL:
			m_stChInfo.m_iVital = iTemp;
			break;
		case INFO_LIST_EXP:
			m_stChInfo.m_iExp = iTemp;
			break;
		case INFO_LIST_GETEXP:
			m_stChInfo.m_iGetExp = iTemp;
			break;
		case INFO_LIST_LEVEL:
			m_stChInfo.m_iLevel = iTemp;
			break;
		case INFO_LIST_GOLD:
			m_stChInfo.m_iGold = iTemp;
			break;
		}
	}
	m_stChInfo.m_iCurExp = 0;
	m_stChInfo.m_iCurVital = m_stChInfo.m_iVital;
	m_iWeaponAttack = 0;
	m_iTotalAttack = m_iWeaponAttack + m_stChInfo.m_iAttack;
	m_bWeaponState = false;
}

void Player::ShowInfo(int Col)
{
	int iPosX1 = WIDTH - 15;
	int iPosX2 = WIDTH + 5;
	string strTemp = "======" + m_stChInfo.m_strName + "<" + to_string(m_stChInfo.m_iLevel) + ">======";
	YELLOW
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
	//Weapon Info표시
	if (m_bWeaponState == true)
	{
		m_ChMapDraw.DrawMidText("무기타입 : " + m_stPlayerWeapon.m_strWType + " 무기이름 : " + m_stPlayerWeapon.m_strWName + " 공격력 : " + to_string(m_stPlayerWeapon.m_iWAttack),WIDTH, HEIGHT * 0.1f + 4 + Col);
	}
	ORIGINAL
}

void Player::BuyWeapon(WEAPON WeaponInfo)
{
	if (WeaponInfo.m_iWCost < m_stPlayerWeapon.m_iWCost)
	{
		m_ChMapDraw.BoxErase(WIDTH, HEIGHT);
		m_ChMapDraw.DrawMidText("Gold 가 부족합니다.",WIDTH, HEIGHT*0.5f);
	}
	else
	{
		m_stChInfo.m_iGold -= WeaponInfo.m_iWCost;
		m_stPlayerWeapon = WeaponInfo;
		m_bWeaponState = true;
		m_iWeaponAttack = WeaponInfo.m_iWAttack;
		m_iTotalAttack = m_iWeaponAttack + m_stChInfo.m_iAttack;
	}

}