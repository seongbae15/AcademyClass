#pragma once
#include "Playlib.h"
#include "DrawManager.h"

class Character
{
protected:
	DrawManager m_chDrawManager;
	string m_strCharacter;
	int m_iStage;
	Pos m_stPos;
	string m_strName;

public:
	virtual void InitCharacter(int num) = 0;
	virtual void DrawCharacter()=0;
	virtual void EraseCharacter() = 0;
	virtual void MoveCharacter(char keyIn)=0;
	virtual void StageUpCharacter(Pos next_pos)=0;
	virtual void BackCharacter(char keyIn) = 0;
	virtual void SetAlarm(Character* monster, bool alarm = true)=0;
	virtual void AddAlarmPlayer(Character* player)=0;
	virtual void ChangeMonsterState(BUTTON_STATE button_state, Character* player)=0;
	virtual void ChangePlayerState() = 0;
	virtual void Notify() = 0;
	virtual void Notified(string notification, int stage) = 0;
	virtual void AttackPlayer(Character* player) = 0;
	Pos GetCharacterPos()
	{
		return m_stPos;
	}
	int GetPlayerStage()
	{
		return m_iStage;
	}
};

