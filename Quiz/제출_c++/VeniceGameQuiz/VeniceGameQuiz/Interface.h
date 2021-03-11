#pragma once
#include "DrawManager.h"
#include "Lib.h"

#define TEXT_MODE_DRAW 0
#define TEXT_MODE_ERASE 1
#define LOBY_MENU_CNT 3
#define LOBY_ADD_COL 3
#define SMALL_BOX_WIDTH 19
#define SMALL_BOX_HEIGHT 5

class Interface
{
private:
	DrawManager m_ifDrawManager;
public:
	void DispLobyScreen(int Mode = TEXT_MODE_DRAW);
	void DispStoryScreen();
	void DispNameInputScreen(int Mode = TEXT_MODE_DRAW);
	void DispStageNumber(int stage_number);
	void DispPlayBox();
	void DispGameOverScreen();
	void DispRankScreen();
};

