#pragma once
#include "Object_map.h"
#include <vector>

#define MAX_BUTTON_COUNT 6

typedef struct ButtonInfo
{
	Pos m_stButtonPos;
	BUTTON_STATE eButton_state;
}ButtonInfo;

class Button : public Object_map
{
private:
	vector<Pos> m_vecButtonPos;
	vector< ButtonInfo> m_vecButtonInfo;
public:
	void SetObj(int stage);
	void DrawObject(int stage);
	Pos GetObjectPos(int index)
	{
		return m_vecButtonInfo[index].m_stButtonPos;
	}
	BUTTON_STATE GetButtonState(int index)
	{
		return m_vecButtonInfo[index].eButton_state;
	}
};