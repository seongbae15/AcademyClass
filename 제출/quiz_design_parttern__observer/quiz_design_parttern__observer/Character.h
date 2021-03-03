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
public:
	virtual void InitCharacter(int num) = 0;
	virtual void DrawCharacter()=0;
	virtual void MoveCharacter()=0;
};

