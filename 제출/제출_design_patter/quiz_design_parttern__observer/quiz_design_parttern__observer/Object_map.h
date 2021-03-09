#pragma once
#include "Playlib.h"
#include "DrawManager.h"

class Object_map
{
protected:
	int m_iStage;
	string m_strObject;

	DrawManager m_objDrawManager;
public:
	virtual void SetObj(int stage) = 0;
	virtual void DrawObject(int stage) = 0;
	virtual Pos GetObjectPos(int index = 0) = 0;
	virtual BUTTON_STATE GetButtonState(int index = 0) = 0;
};