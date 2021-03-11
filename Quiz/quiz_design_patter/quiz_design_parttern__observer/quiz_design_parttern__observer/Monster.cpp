#include "Monster.h"

void Monster::InitMonster(int num)
{
	m_strMonsterName = "MONSTER" + to_string(num);
	//Stage
	m_iMonsterStage = num;
	//��ġ
	m_strMonster = "��";
	m_strMonsterAround = "��";
	m_stMonsterPos.iX = MAP_WIDTH / 2;
	m_stMonsterPos.iY = 2;
	//����
	m_eM_state = MONSTER_STATE_SLEEP;
}

void Monster::DrawMonster()
{
	RED
	if (m_iMonsterStage == 1)
		m_monDrawManager.DrawObject(m_strMonster, m_stMonsterPos.iX, m_stMonsterPos.iY + (MAP_HEIGHT + 5));
	else if(m_iMonsterStage == 2)
		m_monDrawManager.DrawObject(m_strMonster, m_stMonsterPos.iX, m_stMonsterPos.iY);
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
		strNoti = m_strMonsterName + ": Awake";
		break;
	case MONSTER_STATE_SLEEP:
		strNoti = m_strMonsterName + ": Sleep";
		break;
	case MONSTER_STATE_ATTACK:
		strNoti = m_strMonsterName + ": Attack";
		break;
	default:
		break;
	}
	auto iterBegin = m_vecPlayerList.begin();
	auto iterEnd = m_vecPlayerList.end();
	while (iterBegin != iterEnd)
	{
		(*iterBegin)->Notified(strNoti, m_iMonsterStage);
		iterBegin++;
	}
}

void Monster::AttackPlayer(Character* player)
{
	player->ChangePlayerState();
}

void Monster::DrawMonsterAround()
{
	RED
		if (m_iMonsterStage == 1)
		{
			m_monDrawManager.DrawObject(m_strMonsterAround, m_stMonsterPos.iX - 1, m_stMonsterPos.iY - 1 + (MAP_HEIGHT + 5));
			m_monDrawManager.DrawObject(m_strMonsterAround, m_stMonsterPos.iX - 1, m_stMonsterPos.iY + (MAP_HEIGHT + 5));
			m_monDrawManager.DrawObject(m_strMonsterAround, m_stMonsterPos.iX - 1, m_stMonsterPos.iY + 1 + (MAP_HEIGHT + 5));
			m_monDrawManager.DrawObject(m_strMonsterAround, m_stMonsterPos.iX, m_stMonsterPos.iY + 1 + (MAP_HEIGHT + 5));
			m_monDrawManager.DrawObject(m_strMonsterAround, m_stMonsterPos.iX + 1, m_stMonsterPos.iY + 1 + (MAP_HEIGHT + 5));
			m_monDrawManager.DrawObject(m_strMonsterAround, m_stMonsterPos.iX + 1, m_stMonsterPos.iY + (MAP_HEIGHT + 5));
			m_monDrawManager.DrawObject(m_strMonsterAround, m_stMonsterPos.iX + 1, m_stMonsterPos.iY - 1 + (MAP_HEIGHT + 5));
		}
		else if (m_iMonsterStage == 2)
		{
			m_monDrawManager.DrawObject(m_strMonsterAround, m_stMonsterPos.iX - 1, m_stMonsterPos.iY - 1);
			m_monDrawManager.DrawObject(m_strMonsterAround, m_stMonsterPos.iX - 1, m_stMonsterPos.iY);
			m_monDrawManager.DrawObject(m_strMonsterAround, m_stMonsterPos.iX - 1, m_stMonsterPos.iY + 1);
			m_monDrawManager.DrawObject(m_strMonsterAround, m_stMonsterPos.iX, m_stMonsterPos.iY + 1);
			m_monDrawManager.DrawObject(m_strMonsterAround, m_stMonsterPos.iX + 1, m_stMonsterPos.iY + 1);
			m_monDrawManager.DrawObject(m_strMonsterAround, m_stMonsterPos.iX + 1, m_stMonsterPos.iY);
			m_monDrawManager.DrawObject(m_strMonsterAround, m_stMonsterPos.iX + 1, m_stMonsterPos.iY - 1);
		}
	ORIGINAL
	
}

void Monster::EraseMonsterAround()
{
	if (m_iMonsterStage == 1)
	{
		m_monDrawManager.DrawObject("  ", m_stMonsterPos.iX - 1, m_stMonsterPos.iY - 1 + (MAP_HEIGHT + 5));
		m_monDrawManager.DrawObject("  ", m_stMonsterPos.iX - 1, m_stMonsterPos.iY + (MAP_HEIGHT + 5));
		m_monDrawManager.DrawObject("  ", m_stMonsterPos.iX - 1, m_stMonsterPos.iY + 1 + (MAP_HEIGHT + 5));
		m_monDrawManager.DrawObject("  ", m_stMonsterPos.iX, m_stMonsterPos.iY + 1 + (MAP_HEIGHT + 5));
		m_monDrawManager.DrawObject("  ", m_stMonsterPos.iX + 1, m_stMonsterPos.iY + 1 + (MAP_HEIGHT + 5));
		m_monDrawManager.DrawObject("  ", m_stMonsterPos.iX + 1, m_stMonsterPos.iY + (MAP_HEIGHT + 5));
		m_monDrawManager.DrawObject("  ", m_stMonsterPos.iX + 1, m_stMonsterPos.iY - 1 + (MAP_HEIGHT + 5));
	}
	else if (m_iMonsterStage == 2)
	{
		m_monDrawManager.DrawObject("  ", m_stMonsterPos.iX - 1, m_stMonsterPos.iY - 1);
		m_monDrawManager.DrawObject("  ", m_stMonsterPos.iX - 1, m_stMonsterPos.iY);
		m_monDrawManager.DrawObject("  ", m_stMonsterPos.iX - 1, m_stMonsterPos.iY + 1);
		m_monDrawManager.DrawObject("  ", m_stMonsterPos.iX, m_stMonsterPos.iY + 1);
		m_monDrawManager.DrawObject("  ", m_stMonsterPos.iX + 1, m_stMonsterPos.iY + 1);
		m_monDrawManager.DrawObject("  ", m_stMonsterPos.iX + 1, m_stMonsterPos.iY);
		m_monDrawManager.DrawObject("  ", m_stMonsterPos.iX + 1, m_stMonsterPos.iY - 1);
	}
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
			DrawMonsterAround();
			//�˸�
			Notify();
		}
		else if (m_eM_state == MONSTER_STATE_AWAKE)
		{
			m_eM_state = MONSTER_STATE_ATTACK;
			//�˸�
			Notify();
			AttackPlayer(player);
		}
		break;
	case BUTTON_STATE_SLEEP_OR_WAKE:
		if (m_eM_state == MONSTER_STATE_AWAKE)
		{
			m_eM_state = MONSTER_STATE_SLEEP;
			EraseMonsterAround();
			//�˸�
			Notify();
		}
		else if (m_eM_state == MONSTER_STATE_ATTACK)
		{
			m_eM_state = MONSTER_STATE_AWAKE;
			
			//�˸�
			Notify();
		}
		else if (m_eM_state == MONSTER_STATE_SLEEP)
		{
			m_eM_state = MONSTER_STATE_AWAKE;
			DrawMonsterAround();
			//�˸�
			Notify();
		}
		break;
	default:
		break;
	}
}
