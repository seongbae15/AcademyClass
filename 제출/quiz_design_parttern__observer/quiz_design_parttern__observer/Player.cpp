#include "Player.h"

void Player::InitCharacter(int num)
{
	m_strCharacter = "♠";
	m_iNum = num;
	//Stage
	m_iStage = 1;
	//위치
	if (num == 1)
	{
		m_stPos.iX = 1;
		m_stPos.iY = MAP_HEIGHT - 2;
	}
	else if (num == 2)
	{
		m_stPos.iX = MAP_WIDTH-2;
		m_stPos.iY = MAP_HEIGHT - 2;
	}
	//상태
	m_eP_state = PLAYER_STATE_LIVE;
}

void Player::DrawCharacter()
{
	if(m_iNum == 1)
		YELLOW
	else if(m_iNum == 2)
		GREEN
	if(m_iStage == 1)
		m_chDrawManager.DrawObject(m_strCharacter, m_stPos.iX, m_stPos.iY + (MAP_HEIGHT + 5));
	else if (m_iStage == 2)
		m_chDrawManager.DrawObject(m_strCharacter, m_stPos.iX, m_stPos.iY);
	ORIGINAL
}