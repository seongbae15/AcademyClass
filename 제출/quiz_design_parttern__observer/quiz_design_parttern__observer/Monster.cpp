#include "Monster.h"

void Monster::InitCharacter(int num)
{
	//Stage

	m_iStage = num;
	//위치
	if (num == 1)
		m_strCharacter = "▲";
	else if (num == 2)
		m_strCharacter = "♨";
	m_stPos.iX = MAP_WIDTH / 2;
	m_stPos.iY = 2;
	//상태
	m_eM_state = MONSTER_STATE_SLEEP;
}

void Monster::DrawCharacter()
{
	RED
	if (m_iStage == 1)
		m_chDrawManager.DrawObject(m_strCharacter, m_stPos.iX, m_stPos.iY + (MAP_HEIGHT + 5));
	else if(m_iStage == 2)
		m_chDrawManager.DrawObject(m_strCharacter, m_stPos.iX, m_stPos.iY);
	ORIGINAL
	
}
