#include "Character.h"

Character::Character()
{
}
Character::~Character()
{
}

void Character::ThrowRPS(int selection, int type)
{
	string strTmpRPS;
	switch ((RPS)selection)
	{
	case RPS_SCISSORS:
		strTmpRPS = "가위";
		break;
	case RPS_ROCK:
		strTmpRPS = "바위";
		break;
	case RPS_PAPER:
		strTmpRPS = "보";
		break;
	}
	//Disp Selection
	m_ChMapDraw.DrawMidText(strTmpRPS, WIDTH, HEIGHT * 0.4f + type);
}

void Character::Damage(int attack)
{
	m_stChInfo.m_iCurVital -= attack;
	if (m_stChInfo.m_iCurVital <= 0)
	{
		m_stChInfo.m_iCurVital = 0;
	}
}

void Character::Respawn()
{
	m_stChInfo.m_iCurVital = m_stChInfo.m_iVital;
}

void Character::GetReward(int RGetExp, int RGold)
{
	//Exp
	m_stChInfo.m_iCurExp += RGetExp;
	//Gold
	m_stChInfo.m_iGold += RGold;
}

void Character::LevelUp(int AddAttack, int AddVital, int AddExp)
{
	if (m_stChInfo.m_iCurExp >= m_stChInfo.m_iExp)
	{
		m_stChInfo.m_iLevel++;
		m_stChInfo.m_iCurExp = 0;
		m_stChInfo.m_iExp += AddExp;
		m_stChInfo.m_iAttack += AddAttack;
		m_stChInfo.m_iVital += AddVital;
		m_stChInfo.m_iCurVital = m_stChInfo.m_iVital;
	}

}