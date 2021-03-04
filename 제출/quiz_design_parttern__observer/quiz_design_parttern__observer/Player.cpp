#include "Player.h"

void Player::InitCharacter(int num)
{
	m_strName = "PLAYER" + to_string(num);
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

void Player::EraseCharacter()
{
	if (m_iStage == 1)
		m_chDrawManager.DrawObject("  ", m_stPos.iX, m_stPos.iY + (MAP_HEIGHT + 5));
	else if (m_iStage == 2)
		m_chDrawManager.DrawObject("  ", m_stPos.iX, m_stPos.iY);
}

void Player::MoveCharacter(char keyIn)
{
	switch ((MOVE)keyIn)
	{
	case MOVE_UP_1:
	case MOVE_UP_2:
		if (m_stPos.iY > 1)
			m_stPos.iY--;
		break;
	case MOVE_DOWN_1:
	case MOVE_DOWN_2:
		if (m_stPos.iY < MAP_HEIGHT - 2)
			m_stPos.iY++;
		break;
	case MOVE_LEFT_1:
	case MOVE_LEFT_2:
		if (m_stPos.iX > 1)
			m_stPos.iX--;
		break;
	case MOVE_RIGHT_1:
	case MOVE_RIGHT_2:
		if (m_stPos.iX < MAP_WIDTH-2)
			m_stPos.iX++;
		break;
	default:
		break;
	}
}

void Player::BackCharacter(char keyIn)
{
	switch ((MOVE)keyIn)
	{
	case MOVE_UP_1:
	case MOVE_UP_2:
			m_stPos.iY++;
		break;
	case MOVE_DOWN_1:
	case MOVE_DOWN_2:
			m_stPos.iY--;
		break;
	case MOVE_LEFT_1:
	case MOVE_LEFT_2:
			m_stPos.iX++;
		break;
	case MOVE_RIGHT_1:
	case MOVE_RIGHT_2:
			m_stPos.iX--;
		break;
	default:
		break;
	}
}

void Player::StageUpCharacter(Pos next_pos)
{
	EraseCharacter();
	//Update state
	m_iStage = 2;
	m_stPos.iX = next_pos.iX;
	m_stPos.iY = next_pos.iY;
	DrawCharacter();
}

void Player::SetAlarm(Monster* monster, bool alarm)
{
	if (m_iStage == 1)
	{
		m_playerMonsterAlarm = monster;
		m_bAlarm_state1 = alarm;
		m_bAlarm_state2 = false;
		m_playerMonsterAlarm->AddAlarmPlayer(this);
	}
	else if (m_iStage == 2)
	{
		m_playerMonsterAlarm = monster;
		m_bAlarm_state1 = false;
		m_bAlarm_state2 = alarm;
		m_playerMonsterAlarm->AddAlarmPlayer(this);
	}
}

void Player::Notified(string notification, int stage)
{
	if (m_iStage == stage)
	{
		if (stage == 1 && m_bAlarm_state1 == true)
		{
			if (m_iNum == 1)
			{
				m_chDrawManager.DispText("<" + m_strName + "에게 알림>", 0, MAP_HEIGHT);
				m_chDrawManager.DispText(notification, 0, MAP_HEIGHT + 1);
			}
			else if (m_iNum == 2)
			{
				m_chDrawManager.DispText("<" + m_strName + "에게 알림>", 0, MAP_HEIGHT+2);
				m_chDrawManager.DispText(notification, 0, MAP_HEIGHT + 3);
			}
		}
		else if (stage == 2 && m_bAlarm_state2 == true)
		{
			if (m_iNum == 1)
			{
				m_chDrawManager.DispText("<" + m_strName + "에게 알림>", 0, MAP_HEIGHT);
				m_chDrawManager.DispText(notification, 0, MAP_HEIGHT + 1);
			}
			else if (m_iNum == 2)
			{
				m_chDrawManager.DispText("<" + m_strName + "에게 알림>", 0, MAP_HEIGHT + 2);
				m_chDrawManager.DispText(notification, 0, MAP_HEIGHT + 3);
			}
		}
	}
}

void Player::ChangePlayerState()
{
	m_bAlarm_state1 = false;
	m_bAlarm_state2 = false;
	m_eP_state = PLAYER_STATE_DEAD;
	EraseCharacter();
}