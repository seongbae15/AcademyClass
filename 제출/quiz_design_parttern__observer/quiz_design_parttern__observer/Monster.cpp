#include "Monster.h"

void Monster::InitCharacter(int num)
{
	m_strName = "MONSTER" + to_string(num);
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

void Monster::AddAlarmPlayer(Character* player)
{
	m_vecPlayerList.push_back(player);
}

void Monster::Notify()
{
	string strNoti;
	switch (m_eM_state)
	{
	case MONSTER_STATE_AWAKE:
		strNoti = m_strName + ": Awake";
		break;
	case MONSTER_STATE_SLEEP:
		strNoti = m_strName + ": Sleep";
		break;
	case MONSTER_STATE_ATTACK:
		strNoti = m_strName + ": Attack";
		break;
	default:
		break;
	}
	auto iterBegin = m_vecPlayerList.begin();
	auto iterEnd = m_vecPlayerList.end();
	while (iterBegin != iterEnd)
	{
		(*iterBegin)->Notified(strNoti,m_iStage);
		iterBegin++;
	}
}

void Monster::AttackPlayer(Character* player)
{
	player->ChangePlayerState();
}

void Monster::ChangeMonsterState(BUTTON_STATE button_state, Character* player)
{
	switch (button_state)
	{
	case BUTTON_STATE_PASS:
		break;
	case BUTTON_STATE_WAKE:
		if (m_eM_state == MONSTER_STATE_SLEEP)
		{
			m_eM_state = MONSTER_STATE_AWAKE;
			//알림
			Notify();
		}
		else if (m_eM_state == MONSTER_STATE_AWAKE)
		{
			m_eM_state = MONSTER_STATE_ATTACK;
			//플레이어 공격 알림
			Notify();
			AttackPlayer(player);
		}
		break;
	case BUTTON_STATE_SLEEP:
		//Awake 상태이면 알림 발생
		if (m_eM_state == MONSTER_STATE_AWAKE)
		{
			m_eM_state = MONSTER_STATE_SLEEP;
			//알림
			Notify();
		}
		else if (m_eM_state == MONSTER_STATE_ATTACK)
		{
			m_eM_state = MONSTER_STATE_AWAKE;
			//알림
			Notify();
		}
		break;
	default:
		break;
	}
}
