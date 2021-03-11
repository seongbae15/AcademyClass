#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::ShowInfo(int Col)
{
	int iPosX1 = WIDTH - 15;
	int iPosX2 = WIDTH + 5;
	string strTemp = "======" + m_stChInfo.m_strName + "<" + to_string(m_stChInfo.m_iLevel) + ">======";
	YELLOW
	m_ChMapDraw.DrawMidText(strTemp, WIDTH, HEIGHT * 0.1f + Col);
	m_ChMapDraw.TextDraw("���ݷ� = ", iPosX1, HEIGHT * 0.1f + 1 + Col);
	cout << m_stChInfo.m_iAttack;
	m_ChMapDraw.TextDraw("����� = ", iPosX2, HEIGHT * 0.1f + 1 + Col);
	cout << m_stChInfo.m_iCurVital << "/" << m_stChInfo.m_iVital << " ";
	m_ChMapDraw.TextDraw("����ġ = ", iPosX1, HEIGHT * 0.1f + 2 + Col);
	cout << m_stChInfo.m_iCurExp << "/" << m_stChInfo.m_iExp << " ";
	m_ChMapDraw.TextDraw("GetEXP = ", iPosX2, HEIGHT * 0.1f + 2 + Col);
	cout << m_stChInfo.m_iGetExp;
	m_ChMapDraw.TextDraw("Gold = ", iPosX1, HEIGHT * 0.1f + 3 + Col);
	cout << m_stChInfo.m_iGold;
	//Weapon Infoǥ��
	if (m_bWeaponState == true)
	{
		m_ChMapDraw.DrawMidText("����Ÿ�� : " + m_stPlayerWeapon.m_strWType + " �����̸� : " + m_stPlayerWeapon.m_strWName + " ���ݷ� : " + to_string(m_stPlayerWeapon.m_iWAttack),WIDTH, HEIGHT * 0.1f + 4 + Col);
	}
	ORIGINAL
}

void Player::InstallWeapon()
{
	m_bWeaponState = false;
	m_iWeaponAttack = 0;
	m_iTotalAttack = m_iWeaponAttack + m_stChInfo.m_iAttack;
}

void Player::InstallWeapon(WEAPON WeaponInfo)
{
	m_bWeaponState = true;
	m_stPlayerWeapon = WeaponInfo;
	m_iWeaponAttack = WeaponInfo.m_iWAttack;
	m_iTotalAttack = m_iWeaponAttack + m_stChInfo.m_iAttack;
}

void Player::Damage(int attack)
{
	if (m_bWeaponState == true)
	{
		int iCriRate = rand() % 100 + 1;
		m_stPlayerWeapon.m_strWType;
		if (m_stPlayerWeapon.m_strWType == "Dagger" && iCriRate <= 60)
		{
			attack *= 2;
			m_ChMapDraw.DrawMidText("Critical Shot!! <Damage :" + to_string(attack) + ">", WIDTH, HEIGHT * 0.4f + 2);
		}
		else if ((m_stPlayerWeapon.m_strWType == "Gun" || m_stPlayerWeapon.m_strWType == "Bow")&& iCriRate <= 50)
		{
			attack *= 2;
			m_ChMapDraw.DrawMidText("Head Shot!! <Damage :" + to_string(attack) + ">", WIDTH, HEIGHT * 0.4f + 2);
		}
		else if (m_stPlayerWeapon.m_strWType == "Sword" && iCriRate <= 30)
		{
			attack *= 2;
			m_ChMapDraw.DrawMidText("�˱�!! <Damage :" + to_string(attack) + ">", WIDTH, HEIGHT * 0.4f + 2);
		}
	}
	m_stChInfo.m_iCurVital -= attack;
	if (m_stChInfo.m_iCurVital <= 0)
		m_stChInfo.m_iCurVital = 0;
}

void Player::BuyWeapon(WEAPON WeaponInfo)
{
	if (WeaponInfo.m_iWCost < m_stPlayerWeapon.m_iWCost)
	{
		m_ChMapDraw.BoxErase(WIDTH, HEIGHT);
		m_ChMapDraw.DrawMidText("Gold �� �����մϴ�.",WIDTH, HEIGHT*0.5f);
	}
	else
	{
		m_stChInfo.m_iGold -= WeaponInfo.m_iWCost;
		InstallWeapon(WeaponInfo);
	}

}

void Player::LoadCharacterInfo(CharacterInfo stCharacter, int iMode)
{
	m_stChInfo = stCharacter;
	switch (iMode)
	{
	case NEW:
		m_stChInfo.m_iCurExp = 0;
		m_stChInfo.m_iCurVital = m_stChInfo.m_iVital;
		m_iWeaponAttack = 0;
		m_iTotalAttack = m_iWeaponAttack + m_stChInfo.m_iAttack;
		m_bWeaponState = false;
		break;
	case LOAD:
		break;
	}
}