#include "Monster.h"

Monster::Monster()
{
}
Monster::~Monster()
{
}

void Monster::SetInfo(string str, int index)
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