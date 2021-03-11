#pragma once
#include "Lib.h"
#include "DrawManager.h"
#include "Text.h"

class Story :public Text
{
private:
public:
	void DrawTexts(bool hide_state = false);
	void EraseText();
};

